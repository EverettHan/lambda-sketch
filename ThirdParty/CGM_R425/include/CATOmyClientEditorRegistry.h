/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2007

#ifndef CATOmyClientEditorRegistry_H
#define CATOmyClientEditorRegistry_H

#include "CATOMYBaseSession.h"
#include "CATOmyEditor.h"

#include  "IUnknown.h"

/**
 * @level Protected
 * @usage U1
 */

class CATOmyEditorIterator;
class CATOmyEditorRegistry;

/**
 * This class is a used to register an editor for LocalSave operations
 */
class ExportedByCATOMYBaseSession CATOmyClientEditorRegistry
{

public :

	/** 
	* Constructor.
	*/
	CATOmyClientEditorRegistry();

	/** 
	* Constructor from a CATOmyEditorRegistry.
	*/
	CATOmyClientEditorRegistry(CATOmyEditorRegistry * iRealRegistry);

	/** 
	* Destructor.
	*/
	~CATOmyClientEditorRegistry();
	typedef enum 
	{
		LOCAL_SAVE  = 0x1,
		OPEN_NOTIF  = 0x2,
	} iRegisteringPurpose;

	
	/** 
	* Registers a new CATOmyEditor in the session.
	*
	* @param iOmyEditor [in]
	*   The CATOmyEditor instance that has to be registered
	*
	* @return
	* <ul>
	*   <li><code>S_OK</code> if the editor was correctly registered
	*   <li><code>E_FAIL</code> if the editor could not be registered or if it an editor 
	*   with the same identifier was previously registered.
	* </ul>
	*
	*
	*/
	HRESULT Register (const CATOmyEditor*& iOmyEditor);  
	
	
	/** 
	* Searches a registered editor according to its identifier.
	*
	* @param iIdentifier [in]
	*   The identifier of the editor
	* @param oOmyEditor [out]
	*   The editor identified by the input identifier
	*
	* @return
	*   <code>S_OK</code> a corresponding editor was registered and retrieved, otherwise <code>E_FAIL</code>.
	*
	*/
	HRESULT FindEditorByIdentifier(int& iIdentifier, CATOmyEditor*& oOmyEditor);
	
	
	/** 
	* Removes a CATOmyEditor from the session.
	*
	* <br><b>Role</b>: Removes a CATOmyEditor from the session. This method should be called at editor interactive 
	* closure in order to unregister it from the session as it is no longer necessary to stream its information at the 
	* next LocalSave operation. 
	*
	* @param iIdentifier [in]
	*   The identifier of the editor to be removed
	*
	* @return
	*   <code>S_OK</code> if the editor was successfully removed from the session, <code>E_FAIL</code> otherwise.
	*
	*/
	HRESULT RemoveEditor(int& iIdentifier);

	
	/** 
	* Retrieves an editor iterator to access the CATOmyEditors registered in the session.
  *
	* @param oEdtIterator [out]
	*   The current session editor iterator. Its content reflects the registered editors at the time of its creation, therefore 
	*  it should be used right away and deleted after use (it musn't be kept as a data member)
	* @param iRegisteringPurpose [in]
    *   The editor's registering purpose (LOCAL_SAVE, OPEN_NOTIF, ....), used to filter the editor list
	*
	* @return
	*   <code>S_OK</code> if the editor iterator was successfully retrieved, <code>E_FAIL</code>otherwise.
	*
	*/
	HRESULT RetrieveEditors(CATOmyEditorIterator *& oEdtIterator, unsigned int iRegisteringPurpose=LOCAL_SAVE);  

  /** 
  * Factory for CATOmyEditor. It ensures that the given editor will be correctly
  * reisgtrable inside the given registry (its identifier will be unique)
  * This factory is now deprecated. Please use the following one.
  *
  * @param name [in]
  *   A displayable name of this editor.
  * @param latetype_for_unmarshalling [in]
  *   The latetype on which the CATIOmyEditorUnstream interface is implemented for this editor.
  * @param ptr_to_CATIOmyEditorStream [in]
  *   The CATIOmyEditorStream pointer that will be called to stream the information relative to the corresponding FrmEditor.
  *
  */
  CATOmyEditor * CreateEditor(const CATUnicodeString& name,const CATUnicodeString& latetype_for_unmarshalling, CATIOmyEditorStream * ptr_to_CATIEditorStream);
/** 
  * Factory for CATOmyEditor. It ensures that the given editor will be correctly
  * reisgtrable inside the given registry (its identifier will be unique)
  *
  * @param name [in]
  *   A displayable name of this editor.
  * @param iEditor [in]
  *   The CATBaseUnknown pointer that will be called to stream the
  *   information relative to the corresponding editor.
  * @param iRegisteringPurpose [in]
  *   The editor's registering purpose (LOCAL_SAVE, OPEN_NOTIF, ....)
  *
  */
  CATOmyEditor * CreateEditor(const CATUnicodeString& iName,
    CATBaseUnknown* iEditor, unsigned int iRegisteringPurpose=LOCAL_SAVE);

private :
	
	//CATOmyClientEditorRegistry();
	//~CATOmyClientEditorRegistry();
	CATOmyClientEditorRegistry(const CATOmyClientEditorRegistry &); // not implemented
	CATOmyClientEditorRegistry & operator=(const CATOmyClientEditorRegistry &); // not implemented

  CATOmyEditorRegistry * _RealRegistry;
};

#endif
