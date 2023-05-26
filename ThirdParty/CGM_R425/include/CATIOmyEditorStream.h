// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATIOmyEditorStream.h
// Define the CATIOmyEditorStream interface
//
//===================================================================
//
// Usage notes:
//   Interface allowing the streaming of editor information in LocalSave context. 
//   The streamed information is sufficient to rebuild the editor with the same properties at image restore
//
//===================================================================
//
//  May 2007  Creation: Code generated by the CAA wizard  hag
//===================================================================
#ifndef CATIOmyEditorStream_H
#define CATIOmyEditorStream_H

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATDataType.h" 

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOMYBaseSession IID IID_CATIOmyEditorStream;
#else
extern "C" const IID IID_CATIOmyEditorStream ;
#endif

/**
* @level Protected
* @usage U4 CATOmyEditorStreamAdaptor
*/

/**
*
* <br><b>Role</b>: This interface should be implemented by VPMNav objects. It allows editors to 
* be streamed in LocalSave directory
* <p>
* This interface should only be called by LocalSave infrastructure (CATPLMIntegration team)
*
*/
class ExportedByCATOMYBaseSession CATIOmyEditorStream: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	  /** 
	  * Streams the informations defining an editor into a buffer. 
	  *
	  * <br><b>Role</b>: Streams the informations defining an editor into a buffer. This buffer will be  
	  * <br> streamed in the LocalSave directory.
	  *
	  * @param oBuffer [out]
	  *   The char array containing the information defining the corresponding editor.
	  * @param oNbCell [out]
	  *   The number of elements of the oBuffer char array.
	  *
	  * @return
	  *   <code>S_OK</code> if the editor was successfully streamed,  <code>E_FAIL</code> otherwise.
	  *
	  */
	  virtual HRESULT StreamEditor(char** oBuffer, CATLONG32& oNbCell)=0;
 
	  /** 
	  * Retrieves editor's corresponding unmarshalling late type. 
	  *
	  * <br><b>Role</b>: Retrieves editor's corresponding unmarshalling late type.
	  *
	  * @param oSTG_EDITOR_LATETYPE_FOR_UNSTEAM [out]
	  *   The late type implementing CATIOmyEditorUnstream interface.
	  *
	  * @return
	  *   <code>S_OK</code> if the editor's unmarshalling late type was defined,  <code>E_FAIL</code> otherwise.
	  *
	  */

	  virtual HRESULT GetUnstreamLateType(CATUnicodeString& oSTG_EDITOR_LATETYPE_FOR_UNSTEAM)=0;


};

//------------------------------------------------------------------

#endif
