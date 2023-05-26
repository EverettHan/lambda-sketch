// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATISAXAttributes_h
#define CATISAXAttributes_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXAttributes;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXAttributes ;
#endif // LOCAL_DEFINITION_FOR_IID


/**
 * Interface for a list of XML attributes.
 * 
 * <p>This interface allows access to a list of attributes in three different ways:</p>
 * <ol>
 * <li>by attribute index;</li>
 * <li>by Namespace-qualified name; or</li>
 * <li>by qualified (prefixed) name.</li>
 * </ol>
 * 
 * <p>The list will not contain attributes that were declared
 * <tt>#IMPLIED</tt> but not specified in the start tag.  It will also not
 * contain attributes used as Namespace declarations (xmlns*) unless
 * the <tt>http://xml.org/sax/features/namespace-prefixes</tt> 
 * feature is set to <tt>TRUE</tt> (it is <tt>FALSE</tt> by 
 * default).</p>
 * 
 * <p>If the namespace-prefixes feature (see above) is <tt>FALSE</tt>, 
 * access by qualified name may not be available; if the 
 * <tt>http://xml.org/sax/features/namespaces</tt>
 * feature is <tt>FALSE</tt>, access by Namespace-qualified names 
 * may not be available.</p>
 * 
 * <p>The order of attributes in the list is unspecified, and will
 * vary from implementation to implementation.</p>
 *
 * @see CATISAXXMLReader#SetFeature 
 */

class ExportedByCatXmlItfBase CATISAXAttributes : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		
		/**
		 * Retrieves the index of an attribute by XML 1&middot;0 qualified name.
		 *
		 * @param iQualifiedName
		 * The qualified (prefixed) name.
		 * @param oIndex
		 * The index of the attribute.
		 * @return
		 * The method returns <tt>E_FAIL</tt> if the attribute is not in the list, <tt>S_OK</tt> otherwise.
		 */
		virtual HRESULT GetIndex(
			const CATUnicodeString& iQualifiedName, 
			unsigned int & oIndex) = 0;

		/**
		 * Retrieves the index of an attribute by Namespace name.
		 *
		 * @param iURI
		 * The Namespace URI, or the empty string if the name has no Namespace URI.
		 * @param iLocalName
		 * The attribute's local name.
		 * @param oIndex
		 * The index of the attribute.
		 * @return
		 * The method returns <tt>E_FAIL</tt> if the attribute is not in the list, <tt>S_OK</tt> otherwise.
		 */
		virtual HRESULT GetIndex(
			const CATUnicodeString& iURI, 
			const CATUnicodeString& iLocalName, 
			unsigned int & oIndex) = 0;

		/**
		 * Retrieves the number of attributes in this list.
		 *
		 * Once you know the number of attributes, you can iterate through the list.
		 *
		 * @param oLength
		 * The number of attributes in the list.  
		 */
		virtual HRESULT GetLength(
			unsigned int & oLength) = 0;

		/**
		 * Retrieves an attribute's XML 1&middot;0 local name by index.
		 *
		 * @param iPosition 
		 * The attribute index (zero-based).
		 * @param oName
		 * The local name, or the empty string if Namespace processing is not being performed.
		 * @return
		 * The method returns <tt>E_FAIL</tt> if the index is out of range, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetLength 
		 */
		virtual HRESULT GetLocalName(
			const unsigned int iPosition, 
			CATUnicodeString & oName) = 0;

		/**
		 * Retrieves an attribute's XML 1&middot;0 qualified name by index.
		 *
		 * @param iPosition 
		 * The attribute index (zero-based).
		 * @param oName
		 * The XML 1&middot;0 qualified name, or the empty string if none is available.
		 * @return
		 * The method returns <tt>E_FAIL</tt> if the index is out of range, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetLength 
		 */
		virtual HRESULT GetQName(
			const unsigned int iPosition, 
			CATUnicodeString & oName) = 0;
		
		/**
		 * Retrieves the type of an attribute (by position).
		 *
		 * The attribute type is one of the strings <tt>"CDATA"</tt>, <tt>"ID"</tt>,
		 * <tt>"IDREF"</tt>, <tt>"IDREFS"</tt>, <tt>"NMTOKEN"</tt>, <tt>"NMTOKENS"</tt>, <tt>"ENTITY"</tt>, <tt>"ENTITIES"</tt>,
		 * or <tt>"NOTATION"</tt> (always in upper case).
		 *
		 * If the parser has not read a declaration for the attribute,
		 * or if the parser does not report attribute types, then it must
		 * return the value <tt>"CDATA"</tt> as stated in the XML 1&middot;0 Recommentation
		 * (clause 3.3.3, "Attribute-Value Normalization").
		 *
		 * For an enumerated attribute that is not a notation, the
		 * parser will report the type as <tt>"NMTOKEN"</tt>.
		 *
		 * @param iPosition
		 * The index of the attribute in the list (starting at 0).
		 * @param oType
		 * The attribute type as a string.
		 * @return
		 * The method returns <tt>E_FAIL</tt> if the index is out of range, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetLength, #GetType
		 */		
		virtual HRESULT GetType(
			const unsigned int iPosition, 
			CATUnicodeString & oType) = 0;
		
		/**
		 * Retrieves the type of an attribute (by XML 1&middot;0 qualified name).
		 *
		 * The return value is the same as the return value for
		 * @href #GetType.
		 *
		 * @param iQualifiedName 
		 * The XML 1&middot;0 qualified name.
		 * @param oType
		 * The attribute type as a string.
 		 * @return
		 * The method returns <tt>E_FAIL</tt> if no such attribute exists, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetType
		 */
		virtual HRESULT GetType(
			const CATUnicodeString & iQualifiedName, 
			CATUnicodeString & oType) = 0;
				

		/**
		 * Retrieves the type of an attribute (by Namespace name).
		 *
		 * The return value is the same as the return value for
		 * @href #GetType.
		 *
		 * @param iURI
		 * The Namespace URI, or the empty string if the name has no Namespace URI.
		 * @param iLocalName
		 * The attribute's local name.
		 * @param oType
		 * The attribute type as a string.
 		 * @return
		 * The method returns <tt>E_FAIL</tt> if no such attribute exists, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetType
		 */
		virtual HRESULT GetType(
			const CATUnicodeString& iURI, 
			const CATUnicodeString& iLocalName, 
			CATUnicodeString & oType) = 0;

		/**
		 * Retrieves an attribute's Namespace URI by index.
		 *
		 * @param iPosition 
		 * The attribute index (zero-based).
		 * @param oURI
		 * The Namespace URI, or the empty string if none is available.
		 * @return
		 * The method returns <tt>E_FAIL</tt> if the index is out of range, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetLength 
		 */
		virtual HRESULT GetURI(
			const unsigned int iPosition, 
			CATUnicodeString & oURI) = 0;

		/**
		 * Retrieves the value of an attribute (by position).
		 *
		 * If the attribute value is a list of tokens (IDREFS,
		 * ENTITIES, or NMTOKENS), the tokens will be concatenated
		 * into a single string separated by whitespace.
		 *
		 * @param iPosition
		 * The index of the attribute in the list (starting at 0).
		 * @param oValue
		 * The attribute value as a string
 		 * @return
		 * The method returns <tt>E_FAIL</tt> if the index is out of range, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetLength, #GetValue
		 */
		virtual HRESULT GetValue(
			const unsigned int iPosition, 
			CATUnicodeString & oValue) = 0;
		
		/**
		 * Retrieves the value of an attribute (by XML 1&middot;0 qualified name).
		 *
		 * The return value is the same as the return value for
		 * @href #GetValue.
		 *
		 * @param iQualifiedName
		 * The XML 1&middot;0 qualified name.
		 * @param oValue
		 * The attribute value as a string, or null if no such attribute exists.
 		 * @return
		 * The method returns <tt>E_FAIL</tt> if no such attribute exists, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetValue
		 */
		virtual HRESULT GetValue(
			const CATUnicodeString & iQualifiedName, 
			CATUnicodeString & oValue) = 0;

		/**
		 * Retrieves the value of an attribute (by Namespace name).
		 *
		 * The return value is the same as the return value for
		 * @href #GetValue.
		 *
		 * @param iURI
		 * The Namespace URI, or the empty string if the name has no Namespace URI.
		 * @param iLocalName
		 * The attribute's local name.
		 * @param oValue
		 * The attribute value as a string, or null if no such attribute exists.
 		 * @return
		 * The method returns <tt>E_FAIL</tt> if no such attribute exists, <tt>S_OK</tt> otherwise.
		 *
		 * @see #GetValue
		 */
		virtual HRESULT GetValue(
			const CATUnicodeString& iURI, 
			const CATUnicodeString& iLocalName, 
			CATUnicodeString & oValue) = 0;
};

CATDeclareHandler(CATISAXAttributes, CATBaseUnknown);

#endif // CATISAXAttributes_h
