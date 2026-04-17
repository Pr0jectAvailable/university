<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <head>
                <title>Аттестация</title>
                <link rel="stylesheet" type="text/css" href="style.css"/>
            </head>
            <body>
                <table>
                    <thead>
                        <tr>
                            <th>№</th>
                            <th>ФИО</th>
                            <th>КЯР</th>
                            <th>ОАиП</th>
                            <th>ОПИ</th>
                            <th>Математика</th>
                        </tr>
                    </thead>
                    <tbody>
                        <xsl:for-each select="attestation/student">
                            <tr>
                                <td><xsl:value-of select="id"/></td>
                                <td><xsl:value-of select="name"/></td>
                                <xsl:for-each select="subject">
                                    <td>
                                        <xsl:attribute name="class">
                                            <xsl:choose>
                                                <xsl:when test="score &lt; 4">low-grade</xsl:when>
                                                <xsl:when test="score &gt; 8">high-grade</xsl:when>
                                            </xsl:choose>
                                        </xsl:attribute>
                                        <xsl:value-of select="score"/>
                                    </td>
                                </xsl:for-each>
                            </tr>
                        </xsl:for-each>
                    </tbody>
                </table>
            </body>
        </html>
    </xsl:template>
    
</xsl:stylesheet>