// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMProcessingInstruction_h
#define CATIDOMProcessingInstruction_h

// System framework
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMProcessingInstruction;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMProcessingInstruction ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to represent a "processing 
 * instruction", used in XML as a way to keep processor-specific information 
 * in the text of the document.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Core-20001113'>Document Object Model (DOM) Level 2 Core Specification</a>.
 */

class ExportedByCatXmlItfExt CATIDOMProcessingInstruction: public CATIDOMNode {
	CATDeclareInterface;

	public:
	
		/**
		 * Retrieves the target of this processing instruction. XML defines this as being 
		 * the first token following the markup that begins the processing 
		 * instruction.
		 *
		 * @param oTarget
		 * the target of this processing instruction
		 */
		virtual HRESULT GetTarget(
			CATUnicodeString & oTarget) = 0;

		/**
		 * Retrieves the content of this processing instruction. This is from the first non 
		 * white space character after the target to the character immediately 
		 * preceding the <code>?&gt;</code>.
		 *
		 * @param oData
		 * the content of this processing instruction
		 */
		virtual HRESULT GetData(
			CATUnicodeString & oData) = 0;

		/**
		 * Sets the content of this processing instruction. This is from the first non 
		 * white space character after the target to the character immediately 
		 * preceding the <code>?&gt;</code>.
		 *
		 * @param iData
		 * the content of this processing instruction
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
		virtual HRESULT SetData(
			const CATUnicodeString & iData) = 0;
};
CATDeclareHandler(CATIDOMProcessingInstruction, CATIDOMNode);


#endif // CATIDOMProcessingInstruction_h
