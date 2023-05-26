/* -*-c++-*- */

/**
 * @level Protected
 * @usage U2
 */

/**
 * Adaptor for CATIOmyEditorStream
 */

#ifndef CATOmyEditorStreamAdaptor_h
#define CATOmyEditorStreamAdaptor_h

#include "CATIOmyEditorStream.h"


class ExportedByCATOMYBaseSession CATOmyEditorStreamAdaptor : public CATIOmyEditorStream
{
 public :
    CATOmyEditorStreamAdaptor();
    virtual ~CATOmyEditorStreamAdaptor();

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
	virtual HRESULT StreamEditor(char** oBuffer, CATLONG32& oNbCell);

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

	  virtual HRESULT GetUnstreamLateType(CATUnicodeString& oSTG_EDITOR_LATETYPE_FOR_UNSTEAM);
};

#endif
