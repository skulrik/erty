<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
    <xsl:apply-templates/> 
  </body>
  </html>
</xsl:template>

<xsl:template match="ccm">

 <h2>Cyclomatic Complexity</h2>

 <table border="1" cellpadding="2" cellspacing="0">
  <tr>
    <th>File</th>
    <th>Unit</th>
    <th>Complexity</th>
    <th>Classification</th>
  </tr>

 <xsl:for-each select="metric">
 
  <xsl:choose>
    <xsl:when test="complexity &gt; 50"> <!-- untestable -->
      <tr bgcolor="#ff0000">
        <td><xsl:value-of select="file"/></td>
        <td><xsl:value-of select="unit"/></td>
        <td><xsl:value-of select="complexity"/></td>
        <td><xsl:value-of select="classification"/></td>
      </tr>
    </xsl:when>
    <xsl:when test="complexity &gt; 30"> <!-- complex -->
      <tr bgcolor="#ff9933">
        <td><xsl:value-of select="file"/></td>
        <td><xsl:value-of select="unit"/></td>
        <td><xsl:value-of select="complexity"/></td>
        <td><xsl:value-of select="classification"/></td>
      </tr>
    </xsl:when>
    <xsl:when test="complexity &gt; 10"> <!-- more complex -->
      <tr bgcolor="#ffff33">
        <td><xsl:value-of select="file"/></td>
        <td><xsl:value-of select="unit"/></td>
        <td><xsl:value-of select="complexity"/></td>
        <td><xsl:value-of select="classification"/></td>
      </tr>
    </xsl:when>
    <xsl:otherwise> <!-- simple -->
      <tr bgcolor="#00ff00">
        <td><xsl:value-of select="file"/></td>
        <td><xsl:value-of select="unit"/></td>
        <td><xsl:value-of select="complexity"/></td>
        <td><xsl:value-of select="classification"/></td>
      </tr>
    </xsl:otherwise>
   </xsl:choose>

 </xsl:for-each>

 </table>

 
</xsl:template>

</xsl:stylesheet>
