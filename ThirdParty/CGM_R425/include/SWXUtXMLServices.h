//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2011/09/19
//===================================================================
// SWXUtXMLServices.cpp
// Header definition of class SWXUtXMLServices
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/09/19 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtXMLServices_H
#define SWXUtXMLServices_H

#include "SWXUtGeneral.h"

#include "CATListOfCATUnicodeString.h"
#include "CATMathDirection.h"
#include "CATMathPointf.h"
#include "CATMathVectorf.h"
#include "CATUnicodeString.h"

class CATIDOMDocument_var;
class CATIDOMElement_var;
class CATIDOMNode_var;
class CATListValCATBaseUnknown_var;
class CATISAXInputSource_var;

class ExportedBySWXUtGeneral SWXUtXMLServices
{
public:

	static HRESULT GetDocumentFromPath(const CATUnicodeString& iXMLPath, CATIDOMDocument_var &oXmlDoc);
	static HRESULT GetOneDOMElement(const CATIDOMDocument_var &iXmlDoc, const CATUnicodeString &iTagName, CATIDOMElement_var &oElement);
	static bool GetAttributeIfExists(const CATIDOMElement_var &ispNode, const CATUnicodeString &iAttributeName, CATUnicodeString &ioAttributeVal);
	static CATMathPointf GetPointFromNodeAttr(const CATIDOMElement_var &ispNode, const CATUnicodeString &iAttrName);
	static CATMathVectorf GetVecFromNodeAttr(const CATIDOMElement_var &ispNode, const CATUnicodeString &iAttrName);
	static CATMathDirection GetDirFromNodeAttr(const CATIDOMElement_var &ispNode, const CATUnicodeString &iAttrName, 
		const CATMathDirection &iDefaultDir = CATMathDirection(0, 0, 0));
	static float GetFloatFromNodeAttr(const CATIDOMElement_var &ispNode, const CATUnicodeString &iAttrName, float iDefaultVal = 0.f);
	static int GetIntFromNodeAttr(const CATIDOMElement_var &ispNode, const CATUnicodeString &iAttrName, int iDefaultVal);
	static bool GetBoolFromNodeAttr(const CATIDOMElement_var &ispNode, const CATUnicodeString &iAttrName, bool iDefaultVal = false);
	static CATUnicodeString GetStringFromNodeAttr(const CATIDOMElement_var &ispNode, const CATUnicodeString &iAttrName, const CATUnicodeString &iDefaultVal=CATUnicodeString(""));
	static void ClearXMLDocumentCache();
	static HRESULT GetCachedDocumentFromPath(const CATUnicodeString& iXMLPath, CATIDOMDocument_var &oXmlDoc);
	static bool GetNodeText(const CATIDOMNode_var &ispNode, CATUnicodeString &oNodeText);
	static bool GetChildNode(const CATIDOMNode_var &ispParentNode, const CATUnicodeString &iChildNodeName, CATIDOMNode_var &oChildNode);
	static bool GetChildNode(const CATIDOMNode_var &ispParentNode, const CATUnicodeString &iChildNodeName, const CATUnicodeString &iAttributeName, const CATUnicodeString &iAttributeValue, CATIDOMNode_var &oChildNode);
	static bool GetChildNodes(const CATIDOMNode_var &ispParentNode, const CATUnicodeString &iChildNodeName, const CATUnicodeString &iAttributeName, const CATUnicodeString &iAttributeValue, CATListValCATBaseUnknown_var &oChildNodes);
	static bool GetChildNodeValue(const CATIDOMNode_var &ispParentNode, const CATUnicodeString &iChildNodeName, CATUnicodeString &oNodeValue);
	static bool GetFirstChildElement(const CATIDOMNode_var &ispParentNode, CATIDOMNode_var &oChildNode);
	static bool CreateXMLDocumentFromString(const CATUnicodeString &iInputXML, CATIDOMDocument_var &oXmlDoc);
	static CATUnicodeString UnscrambleXmlData(const CATUnicodeString & iPath);
	static HRESULT CreateInputSourceFromScrambledXML(const CATUnicodeString& iFilePath, CATISAXInputSource_var& oXmlSource);
	// Utilities
	static CATUnicodeString BuildTemplateXML(CATUnicodeString iDataString, CATUnicodeString iPropName);
	static CATUnicodeString RetrieveXMLData(CATUnicodeString iXmlDataString, CATUnicodeString iPropName, bool *oFound = NULL);
	static void RetrieveXMLData(CATListOfCATUnicodeString iXmlDataList, CATUnicodeString iPropName, CATListOfCATUnicodeString &oDataStringList);
	static HRESULT ReadTemplate(CATUnicodeString iFileName, CATListOfCATUnicodeString& oWholeContent);
	static void EraseFilesFromCache(const CATUnicodeString & iSearchStr);	

private:
	// Copy constructor and equal operator
	// -----------------------------------
	SWXUtXMLServices (SWXUtXMLServices &);
	SWXUtXMLServices& operator=(SWXUtXMLServices&);

};

//-----------------------------------------------------------------------

#endif