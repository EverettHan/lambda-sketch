// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMComment_h
#define CATIDOMComment_h

#include "CatXmlItfExt.h"
#include "CATIDOMCharacterData.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMComment;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMComment ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface representing XML comment nodes in the DOM.
 *
 * <P>This interface inherits from @href CATIDOMCharacterData. The string value contains all of the characters between 
 * the starting '<code>&lt;!--</code>' and ending '<code>--&gt;</code>'.
 * @see CATIDOMCharacterData
 */

class ExportedByCatXmlItfExt CATIDOMComment: public CATIDOMCharacterData {
	CATDeclareInterface;

	public:

};
CATDeclareHandler(CATIDOMComment, CATIDOMCharacterData);


#endif // CATIDOMComment_h

