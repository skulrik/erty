<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
    <xsl:apply-templates/>
  </body>
  </html>
</xsl:template>

<xsl:template match="testsuites">

 <p bgcolor="#ff0000">

 <h2>Summary</h2>

 <table border="1" cellpadding="2" cellspacing="0">
  <tr>
    <th># of tests</th>
    <th>Failures</th>
    <th>Disabled</th>
    <th>Errors</th>
    <th>Time</th>
    <th>Random seed</th>
  </tr>

  <xsl:choose>
    <xsl:when test="@failures &gt; 0">
      <tr bgcolor="#ff0000">
        <td><xsl:value-of select="@tests"/></td>
        <td><xsl:value-of select="@failures"/></td>
        <td><xsl:value-of select="@disabled"/></td>
        <td><xsl:value-of select="@errors"/></td>
        <td><xsl:value-of select="@time"/></td>
        <td><xsl:value-of select="@random_seed"/></td>
      </tr>
    </xsl:when>
    <xsl:otherwise>
      <tr bgcolor="#00ff00">
        <td><xsl:value-of select="@tests"/></td>
        <td><xsl:value-of select="@failures"/></td>
        <td><xsl:value-of select="@disabled"/></td>
        <td><xsl:value-of select="@errors"/></td>
        <td><xsl:value-of select="@time"/></td>
        <td><xsl:value-of select="@random_seed"/></td>
      </tr>
    </xsl:otherwise>
   </xsl:choose>
 </table>

 </p>

 <h2>Details</h2>

 <xsl:for-each select="testsuite">

   <h3><xsl:value-of select="@name"/></h3>

   <table border="1" cellpadding="2" cellspacing="0">
     <tr>
       <th># of tests</th>
       <th>Failures</th>
       <th>Disabled</th>
       <th>Errors</th>
       <th>Time</th>
     </tr>

     <xsl:choose>
       <xsl:when test="@failures &gt; 0">
         <tr bgcolor="#ff0000">
           <td><xsl:value-of select="@tests"/></td>
           <td><xsl:value-of select="@failures"/></td>
           <td><xsl:value-of select="@disabled"/></td>
           <td><xsl:value-of select="@errors"/></td>
           <td><xsl:value-of select="@time"/></td>
         </tr>
       </xsl:when>
       <xsl:otherwise>
         <tr bgcolor="#00ff00">
           <td><xsl:value-of select="@tests"/></td>
           <td><xsl:value-of select="@failures"/></td>
           <td><xsl:value-of select="@disabled"/></td>
           <td><xsl:value-of select="@errors"/></td>
           <td><xsl:value-of select="@time"/></td>
         </tr>
       </xsl:otherwise>
     </xsl:choose>
   </table>

   <table border="1" cellpadding="2" cellspacing="0">
     <tr align="left">
       <th>Name</th>
       <th>Status</th>
       <th>Time</th>
       <th>Class Name</th>
       <th>Message</th>
     </tr>

     <xsl:for-each select="testcase">
       <xsl:choose>
         <xsl:when test="count(failure)>0">
           <tr bgcolor="#ff0000">
             <td><xsl:value-of select="@name"/></td>
             <td><xsl:value-of select="@status"/></td>
             <td><xsl:value-of select="@time"/></td>
             <td><xsl:value-of select="@classname"/></td>
             <td><xsl:value-of select="failure/@message"/></td>
           </tr>
         </xsl:when>
         <xsl:otherwise>
           <tr bgcolor="#00ff00">
             <td><xsl:value-of select="@name"/></td>
             <td><xsl:value-of select="@status"/></td>
             <td><xsl:value-of select="@time"/></td>
             <td><xsl:value-of select="@classname"/></td>
             <td/>
           </tr>
         </xsl:otherwise>
       </xsl:choose>
     </xsl:for-each>
   </table>

 </xsl:for-each>

</xsl:template>

</xsl:stylesheet>
