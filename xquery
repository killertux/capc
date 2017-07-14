declare namespace oai = "http://www.openarchives.org/OAI/2.0/"; let $document := doc('temp.xml')//oai:OAI-PMH/oai:Identify return ($document/oai:granularity/string(), $document/oai:earliestDatestamp/string())

