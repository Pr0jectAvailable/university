<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
    <html>
        <head>
            <title><xsl:value-of select="shop/name"/></title>
            <link rel="stylesheet" type="text/css" href="style.css"/>
        </head>
        <body>
            <h1 class="name"><xsl:value-of select="shop/name"/></h1>
            <div class="storage">
                <xsl:for-each select="shop/storage/item">
                    <xsl:sort select="price" data-type="number" order="ascending"/>
                    <div class="item">
                        <h2><xsl:value-of select="title"/></h2>
                        <div class="hr"/>
                        <p class="description"><xsl:value-of select="description"/></p>
                        <p class="advantages"><xsl:value-of select="advantages"/></p>
                        <p class="price"><xsl:value-of select="price"/>$</p>
                    </div>
                </xsl:for-each>
            </div>
        </body>
    </html>
</xsl:template>

</xsl:stylesheet>