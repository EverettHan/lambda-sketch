// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMCharacterData_h
#define CATIDOMCharacterData_h

// System framework
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"


#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMCharacterData;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMCharacterData ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface extending <tt>CATIDOMNode</tt> with a set of 
 * methods for accessing character data in the DOM.
 *
 * For clarity this set is defined here rather than on each class that uses 
 * these methods. No DOM objects correspond directly to 
 * @href CATIDOMCharacterData, though @href CATIDOMText and others do inherit 
 * the interface from it. All <code>offset</code>s in this interface start 
 * from 0, and index in terms of Unicode 16 bit storage units.
 * @see CATIDOMText
 */
class ExportedByCatXmlItfExt CATIDOMCharacterData: public CATIDOMNode {
	CATDeclareInterface;

	public:

		/**
		 * Retrieves the character data of the node that implements this interface. 
		 *
		 * The DOM implementation may not put arbitrary limits on the amount of data that 
		 * may be stored in a @href CATIDOMCharacterData node. However, 
		 * implementation limits may mean that the entirety of a node's data may 
		 * not fit into a single call to <tt>GetData</tt>. In such cases, the user 
		 * may call @href #SubstringData to retrieve the data in 
		 * appropriately sized pieces.
		 * @param oData
		 * the character data of the node that implements this interface
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2202</td>
		 *        <td class="errtd">DOMSTRING_SIZE_ERR: Raised when it would return more characters than supported by the underlying implementation.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT GetData(
			CATUnicodeString& oData) = 0;

		/**
		 * Sets the character data of the node that implements this interface. 
		 *
		 * The DOM implementation may not put arbitrary limits on the amount of data that 
		 * may be stored in a @href CATIDOMCharacterData node. However, 
		 * implementation limits may mean that the entirety of a node's data may 
		 * not fit into a single call to <tt>GetData</tt>. In such cases, the user 
		 * may call @href #SubstringData to retrieve the data in 
		 * appropriately sized pieces.
		 *
		 * @param iData
		 * The @href CATUnicodeString to set.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2202</td>
		 *        <td class="errtd">DOMSTRING_SIZE_ERR: Raised when it would return more characters than supported by the underlying implementation.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT SetData(
			const CATUnicodeString& iData) = 0;

		/**
		 * Retrieves the number of characters that are available through <code>data</code> and 
		 * the <code>SubstringData</code> method below. 
		 *
		 * This may have the value zero, i.e., <code>CharacterData</code> nodes may be empty.
		 *
		 * @param oLength
		 * The retrieved number of characters that are available through <code>data</code>.
		 *
		 * @see #SubstringData
		 */
		virtual HRESULT GetLength(
			unsigned int& oLength)  = 0;

		/**
		 * Extracts a range of data from the node.
		 *
		 * @param iOffset
		 * Start offset of substring to extract.
		 * @param iCount
		 * The number of characters to extract.
		 * @param oSubstringData
		 * The specified substring. If the sum of <code>iOffset</code> and 
		 *   <code>iCount</code> exceeds the value returned by @href #GetLength, then all 
		 *   characters to the end of the data are returned.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2201</td>
		 *        <td class="errtd">INDEX_SIZE_ERR: Raised if the specified <tt>iOffset</tt> is greater 
		 *   than the number of characters in <code>data</code>.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2202</td>
		 *        <td class="errtd">DOMSTRING_SIZE_ERR: Raised when it would return more characters than supported by the underlying implementation.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see #GetLength
		 */
		virtual HRESULT SubstringData(
			unsigned int iOffSet, 
			unsigned int iCount,
			CATUnicodeString& oSubstringData)  = 0;

		/**
		 * Appends the string to the end of the character data of the node.
		 *
		 * Upon success, @href #GetData provides access to the concatenation of 
		 * <code>data</code> and the @href CATUnicodeString specified.
		 *
		 * @param iAppendedData
		 * The @href CATUnicodeString to append.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT AppendData(
			const CATUnicodeString& iAppendedData) = 0;

		/**
		 * Inserts a string at the specified character offset.
		 *
		 * @param iOffSet
		 * The character offset at which to insert.
		 * @param iInsertedData
		 * The @href CATUnicodeString to insert.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2201</td>
		 *        <td class="errtd">INDEX_SIZE_ERR: Raised if the specified <tt>iOffset</tt> is greater 
		 *   than the number of characters in <code>data</code>.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT InsertData(
			unsigned int iOffSet, 
			const CATUnicodeString& iInsertedData) = 0;

		/**
		 * Removes a range of characters from the node. 
		 *
		 * Upon success, the returned values of @href #GetData and 
		 * @href #GetLength reflect the change.
		 *
		 * @param iOffSet
		 * The offset from which to remove characters.
		 * @param iCount
		 * The number of characters to delete. If the sum of 
		 *   <code>iOffset</code> and <code>iCount</code> exceeds the value returned by @href #GetLength
		 *   then all characters from <code>iOffset</code> to the end of the data 
		 *   are deleted.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2201</td>
		 *        <td class="errtd">INDEX_SIZE_ERR: Raised if the specified <tt>iOffset</tt> is greater 
		 *   than the number of characters in <code>data</code>.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT DeleteData(
			unsigned int iOffSet, 
			unsigned int iCount) = 0;

		/**
		 * Replaces the characters starting at the specified character offset with 
		 * the specified string.
		 *
		 * @param iOffSet
		 * The offset from which to start replacing.
		 * @param iCount
		 * The number of characters to replace. If the sum of 
		 *   <code>iOffSet</code> and <code>iCount</code> exceeds the value returned by @href #GetLength,
		 *   then all characters to the end of the data are replaced (i.e., the 
		 *   effect is the same as a @href #DeleteData method call with the same 
		 *   range, followed by an @href #AppendData method invocation).
		 * @param iArg
		 * The @href CATUnicodeString with which the range must be replaced.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2201</td>
		 *        <td class="errtd">INDEX_SIZE_ERR: Raised if the specified <tt>iOffset</tt> is greater 
		 *   than the number of characters in <code>data</code>.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT ReplaceData(
			unsigned int iOffSet, 
			unsigned int iCount, 
			const CATUnicodeString& iArg) = 0;


};
CATDeclareHandler(CATIDOMCharacterData, CATIDOMNode);

#endif // CATIDOMCharacterData_h

