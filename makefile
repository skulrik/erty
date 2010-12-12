PROJECT_NAME=CPP_APP_TEMPLATE

PREFIX=/usr/local/bin

CXX=g++
CXXFLAGS=-pedantic -Wall -Wextra -Werror -std=c++0x -D_FORTIFY_SOURCE=2 -DHAVE_CXA_DEMANGLE

CXXINCLUDES=-I. -I$(SRC_MAIN_DIR)
CXXLIBS=-lboost_program_options -lboost_regex

ifdef OPTIMIZE
    CXXFLAGS+= -s -O3
endif

ifdef DEBUG
  CXXFLAGS+= -g -rdynamic -DDEBUG
endif

ifdef PROFILE
  CXXFLAGS+= -fprofile-arcs -ftest-coverage -pg
  CXXLIBS+= -lgcov
endif

SRC_DIR=src
SRC_MAIN_DIR=${SRC_DIR}/main
SRC_TEST_DIR=${SRC_DIR}/test

BUILD_DIR=build
BUILD_MAIN_DIR=${BUILD_DIR}/main
BUILD_TEST_DIR=${BUILD_DIR}/test

RESOURCES_DIR=resources
REPORT_TOOLS_DIR=$(RESOURCES_DIR)/report-tools
LOCALES_DIR=$(RESOURCES_DIR)/LC_MESSAGES

TEST_OUTPUT_DIR=test-output

REPORT_DIR=report

BIN_DIR=bin

TAGS_FILE=tags
CSCOPE_FILES=cscope.*

SRC_FILES=$(shell find $(SRC_DIR) -name *.cpp)
SRC_FILES+=$(shell find $(SRC_DIR) -name *.h)
MAIN_OBJECTS=$(shell find $(SRC_MAIN_DIR) -name *.cpp |sed 's/.cpp/.o/' |sed 's/$(SRC_DIR)/$(BUILD_DIR)/')
TEST_OBJECTS=$(shell find $(SRC_DIR) -name *.cpp |grep -v 'main.cpp' |sed 's/.cpp/.o/' |sed 's/$(SRC_DIR)/$(BUILD_DIR)/')

MAIN_EXEC_APP=$(BUILD_MAIN_DIR)/$(PROJECT_NAME)
TEST_EXEC_APP=$(BUILD_TEST_DIR)/$(PROJECT_NAME)

default: prod

all:	clean init ctags cscope report

report: clean init
	cp -f $(REPORT_TOOLS_DIR)/index.html $(REPORT_DIR)/
	sed -i 's/@PROJECT_NAME@/$(PROJECT_NAME)/' $(REPORT_DIR)/index.html
	make "DEBUG=1" "PROFILE=1" lcov
	make ctags
	make doxygen
	make clean.build
	make test
	make clean.build
	make "DEBUG=1" valgrind
	make cccc
	make ccm

clean:	clean.build
	rm -rf $(TEST_OUTPUT_DIR) $(REPORT_DIR) $(TAGS_FILE) $(CSCOPE_FILES) $(LOCALES_DIR)/mo *.log

clean.build:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
init:
	mkdir -p $(BUILD_MAIN_DIR)
	mkdir -p $(BUILD_TEST_DIR)
	mkdir -p $(REPORT_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(TEST_OUTPUT_DIR)

ctags:
	ctags -R $(SRC_DIR)

cscope:
	cscope -b -q -R

xgettext:
	xgettext --language C++ --default-domain $(PROJECT_NAME) --sort-output --output-dir $(LOCALES_DIR) --output $(PROJECT_NAME).po --keyword=_ $(SRC_FILES)
	msginit --locale fr_CA.utf8 --output $(LOCALES_DIR)/po/fr.po --input $(LOCALES_DIR)/$(PROJECT_NAME).po

msgfmt:
	mkdir -p $(LOCALES_DIR)/mo/fr
	msgfmt --check --output $(LOCALES_DIR)/mo/fr/$(PROJECT_NAME).mo $(LOCALES_DIR)/po/fr.po

build:	init compile link
	ln -sf ../$(MAIN_EXEC_APP) $(BIN_DIR)/$(PROJECT_NAME)

compile: $(MAIN_OBJECTS)

link:
	$(CXX) $(MAIN_OBJECTS) $(CXXLIBS) -o $(MAIN_EXEC_APP)

run:	build
	$(MAIN_EXEC_APP)

build.test: init compile.test link.test
	ln -sf ../$(TEST_EXEC_APP) $(BIN_DIR)/$(PROJECT_NAME)_TEST

compile.test: $(TEST_OBJECTS)

link.test:
	$(CXX) $(TEST_OBJECTS) $(CXXLIBS) -L/usr/local/lib -lpthread -lgtest -lgmock -o $(TEST_EXEC_APP)

test:	build.test
	mkdir -p $(REPORT_DIR)/test
	$(TEST_EXEC_APP) --gtest_shuffle --gtest_output=xml:$(REPORT_DIR)/test/$(PROJECT_NAME)_TEST.xml
	cp -f $(REPORT_TOOLS_DIR)/gtest.xsl $(REPORT_DIR)/test/
	sed -i 's/<?xml version="1.0" encoding="UTF-8"?>/<?xml version="1.0" encoding="UTF-8"?>\n<?xml-stylesheet type="text\/xsl" href="gtest.xsl"?>/' $(REPORT_DIR)/test/$(PROJECT_NAME)_TEST.xml

run.test:
	$(TEST_EXEC_APP) --gtest_shuffle

prod: clean
	make "OPTIMIZE=1" build
	make msgfmt

install:
	cp -f bin/$(PROJECT_NAME) $(PREFIX)/
	mkdir -p /usr/share/locale-langpack/fr_CA/LC_MESSAGES
	cp -f $(LOCALES_DIR)/mo/fr/$(PROJECT_NAME).mo /usr/share/locale-langpack/fr_CA/LC_MESSAGES/

astyle:
	astyle --options=$(REPORT_TOOLS_DIR)/astyle.cfg $(SRC_FILES)

valgrind: clean.build build build.test
	mkdir -p $(REPORT_DIR)/valgrind
	valgrind --xml=yes -v --leak-check=full --show-reachable=yes --leak-resolution=high --xml-file=$(REPORT_DIR)/valgrind/$(PROJECT_NAME).xml $(MAIN_EXEC_APP)
	valgrind --xml=yes -v --leak-check=full --show-reachable=yes --leak-resolution=high --xml-file=$(REPORT_DIR)/valgrind/$(PROJECT_NAME)_TEST.xml $(TEST_EXEC_APP)
	cp -f $(REPORT_TOOLS_DIR)/valgrind.xsl $(REPORT_DIR)/valgrind/
	sed -i 's/<?xml version="1.0"?>/<?xml version="1.0"?>\n<?xml-stylesheet type="text\/xsl" href="valgrind.xsl"?>/' $(REPORT_DIR)/valgrind/$(PROJECT_NAME).xml
	sed -i 's/<?xml version="1.0"?>/<?xml version="1.0"?>\n<?xml-stylesheet type="text\/xsl" href="valgrind.xsl"?>/' $(REPORT_DIR)/valgrind/$(PROJECT_NAME)_TEST.xml

doxygen:
	mkdir -p $(REPORT_DIR)/doxygen
	doxygen $(REPORT_TOOLS_DIR)/doxyfile

lcov: clean.build build.test
	mkdir -p $(REPORT_DIR)/lcov
	lcov --derive-func-data --directory $(BUILD_DIR) --base-directory . --capture --initial --output-file $(REPORT_DIR)/lcov/$(PROJECT_NAME).capture.before.info
	$(TEST_EXEC_APP)
	lcov --derive-func-data --directory $(BUILD_DIR) --base-directory . --capture --output-file $(REPORT_DIR)/lcov/$(PROJECT_NAME).capture.after.info
	lcov --derive-func-data --add-tracefile $(REPORT_DIR)/lcov/$(PROJECT_NAME).capture.before.info --add-tracefile $(REPORT_DIR)/lcov/$(PROJECT_NAME).capture.after.info --output-file $(REPORT_DIR)/lcov/$(PROJECT_NAME).capture.info
	lcov --derive-func-data --extract $(REPORT_DIR)/lcov/$(PROJECT_NAME).capture.info *$(PROJECT_NAME)* --output-file $(REPORT_DIR)/lcov/$(PROJECT_NAME).extract.info
	genhtml -s -k --legend --demangle-cpp $(REPORT_DIR)/lcov/$(PROJECT_NAME).extract.info -o $(REPORT_DIR)/lcov/

cccc:
	mkdir -p $(REPORT_DIR)/cccc
	cccc --outdir=$(REPORT_DIR)/cccc --lang=c++ $(SRC_FILES)

ccm:
	mkdir -p $(REPORT_DIR)/ccm
	$(REPORT_TOOLS_DIR)/ccm.exe $(REPORT_TOOLS_DIR)/ccm.cfg > $(REPORT_DIR)/ccm/ccm.xml
	cp -f $(REPORT_TOOLS_DIR)/ccm.xsl $(REPORT_DIR)/ccm/
	sed -i '1i<?xml version="1.0"?>\n<?xml-stylesheet type="text\/xsl" href="ccm.xsl"?>' $(REPORT_DIR)/ccm/ccm.xml

.PHONY:	default all report clean clean.build init ctags cscope xgettext msgfmt build compile link run build.test compile.test link.test test prod astyle valgrind doxygen lcov cccc ccm

$(BUILD_MAIN_DIR)/%.o : $(SRC_MAIN_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) -o $@ $<

$(BUILD_TEST_DIR)/%.o : $(SRC_TEST_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) -o $@ $<

