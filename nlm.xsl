<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet
    version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
    xmlns:oai="http://www.openarchives.org/OAI/2.0/"
    xmlns:nlm="http://dtd.nlm.nih.gov/publishing/2.3"
    xmlns:xlink="http://www.w3.org/1999/xlink"
>
<xsl:output method="xml"/>

<xsl:template match="/">
	<capc-articles>
		<xsl:apply-templates select="//oai:metadata/nlm:article"/>
	</capc-articles>
</xsl:template>

<xsl:template match="//oai:metadata/nlm:article">
  <capc-article>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:title-group/nlm:article-title"/></value>
		<reference>dc.title</reference>
	</field>
	<field>
		<value>article</value>
		<reference>dc.type</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:permissions/nlm:license/nlm:license-p"/></value>
		<reference>dc.rights</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:permissions/nlm:license/@xlink:href"/></value>
		<reference>dc.rights.uri</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:pub-date[@pub-type='epub']/nlm:year"/>-<xsl:value-of select="nlm:front/nlm:article-meta/nlm:pub-date[@pub-type='epub']/nlm:month"/>-<xsl:value-of select="nlm:front/nlm:article-meta/nlm:pub-date[@pub-type='epub']/nlm:day"/></value>
		<reference>dc.date.issued</reference>
	</field>
	<xsl:for-each select="nlm:front/nlm:article-meta/nlm:contrib-group/nlm:contrib[@contrib-type='author']">
		<field>
			<value><xsl:value-of select="nlm:name/nlm:surname"/>, <xsl:value-of select="nlm:name/nlm:given-names"/></value>
			<reference>dc.creator</reference>
		</field>
	</xsl:for-each>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:journal-meta/nlm:journal-title"/></value>
		<reference>dc.relation.ispartof</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:volume"/></value>
		<reference>dc.citation.volume</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:issue"/></value>
		<reference>dc.citation.issue</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:self-uri[not(@content-type)]/@xlink:href"/></value>
		<reference>dc.relation.uri</reference>
	</field>
	<field>
		<value><xsl:choose>
			<xsl:when test="@xml:lang = 'PT'">por</xsl:when>
			<xsl:when test="@xml:lang = 'pt_BR'">por</xsl:when>
			<xsl:when test="@xml:lang = 'pt'">por</xsl:when>
			<xsl:when test="@xml:lang = 'EN'"></xsl:when>
			<xsl:when test="@xml:lang = 'en'">eng</xsl:when>
			<xsl:when test="@xml:lang = 'en_US'">eng</xsl:when>
			<xsl:when test="@xml:lang = 'en_UK'">eng</xsl:when>
			<xsl:when test="@xml:lang = 'es'">spa</xsl:when>
			<xsl:when test="@xml:lang = 'ES'">spa</xsl:when>
			<xsl:when test="@xml:lang = 'es_ES'">spa</xsl:when>
			<xsl:when test="@xml:lang = 'fr'">fra</xsl:when>
			<xsl:when test="@xml:lang = 'FR'">fra</xsl:when>
			<xsl:when test="@xml:lang = 'fr_FR'">fra</xsl:when>
			<xsl:when test="@xml:lang = 'DE'">deu</xsl:when>
			<xsl:when test="@xml:lang = 'de'">deu</xsl:when>
			<xsl:when test="@xml:lang = 'de_DE'">deu</xsl:when>
			<xsl:when test="@xml:lang = 'de_AU'">deu</xsl:when>
			<xsl:when test="@xml:lang = 'it'">ita</xsl:when>
			<xsl:when test="@xml:lang = 'IT'">ita</xsl:when>
			<xsl:when test="@xml:lang = 'it_IT'">ita</xsl:when>
			<xsl:when test="@xml:lang = 'ca'">cat</xsl:when>
			<xsl:when test="@xml:lang = 'CA'">cat</xsl:when>
			<xsl:when test="@xml:lang = 'ca_ES'">cat</xsl:when>
			<xsl:when test="@xml:lang = 'nl'">nld</xsl:when>
			<xsl:when test="@xml:lang = 'NL'">nld</xsl:when>
			<xsl:when test="@xml:lang = 'nl_NL'">nld</xsl:when>
			<xsl:when test="@xml:lang = 'nl_BE'">nld</xsl:when>
			<xsl:otherwise>por</xsl:otherwise>
		</xsl:choose></value>
		<reference>dc.language</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:article-id[@pub-id-type='doi']"/></value>
		<reference>dc.identifier.doi</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:journal-meta/nlm:issn"/></value>
		<reference>dc.identifier.issn</reference>
	</field>
	<xsl:for-each select="nlm:front/nlm:article-meta/nlm:kwd-group/nlm:kwd">
		<field>
			<value><xsl:value-of select="."/></value>
			<reference>dc.subject</reference>
		</field>
	</xsl:for-each>
	<field>
		<value><xsl:choose>
			<xsl:when test="nlm:front/nlm:article-meta/nlm:abstract/@xml:lang = 'PT'"><xsl:value-of select="nlm:front/nlm:article-meta/nlm:abstract"/></xsl:when>
			<xsl:when test="nlm:front/nlm:article-meta/nlm:abstract-trans/@xml:lang = 'PT'"><xsl:value-of select="nlm:front/nlm:article-meta/nlm:abstract-trans"/></xsl:when>
			</xsl:choose>
		</value>
		<reference>dc.description.resumo</reference>
	</field>
	<field>
		<value><xsl:choose>
			<xsl:when test="nlm:front/nlm:article-meta/nlm:abstract/@xml:lang = 'EN'"><xsl:value-of select="nlm:front/nlm:article-meta/nlm:abstract"/></xsl:when>
			<xsl:when test="nlm:front/nlm:article-meta/nlm:abstract-trans/@xml:lang = 'EN'"><xsl:value-of select="nlm:front/nlm:article-meta/nlm:abstract-trans"/></xsl:when>
			</xsl:choose>
		</value>
		<reference>dc.description.abstract</reference>
	</field>
	<field>
		<xsl:for-each select="nlm:front/nlm:article-meta/nlm:contrib-group/nlm:contrib[@contrib-type='author']">
			<value><xsl:value-of select="nlm:aff"/></value>
		</xsl:for-each>
		<reference>affiliation</reference>
	</field>
	<field>
		<value><xsl:value-of select="nlm:front/nlm:article-meta/nlm:self-uri[@content-type]/@xlink:href"/></value>
		<reference>fileLink</reference>
  </field>
  </capc-article>
</xsl:template>
</xsl:stylesheet>
