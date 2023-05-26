#ifndef CATOmyEditorRegistry_h
#define CATOmyEditorRegistry_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

class CATOmyEditor;
class CATOmyEditorIterator;
class CATOmyEditorHashTable;
class CATIOmyEditorStream;
class CATUnicodeString;

class ExportedByCATOMYBaseSession CATOmyEditorRegistry : public CATBaseUnknown
{
public:
  CATOmyEditorRegistry(int iExpectectedSize=10);
  ~CATOmyEditorRegistry();

  typedef enum 
  {
    UNDEFINED   = 0x0,
	  LOCAL_SAVE  = 0x1,
	  OPEN_NOTIF  = 0x2,
  } RegisteringPurpose;

  /** 
  * Creates a CATOmyEditor. It ensures that the given editor will be correctly
  * registrable inside the given registry (its identifier will be unique)
  *
  * @param iName [in]
  *   A displayable name of this editor.
  * @param iUnmarshallingLateType [in]
  *   The latetype on which the CATIOmyEditorUnstream interface is implemented
  *   for this editor.
  * @param iEditorStream [in]
  *   The CATIOmyEditorStream pointer that will be called to stream the
  *   information relative to the corresponding editor.
  */
  CATOmyEditor * CreateEditor(const CATUnicodeString& iName,
    const CATUnicodeString& iUnmarshallingLateType,
    CATIOmyEditorStream * iEditorStream);

   /** 
  * Creates a CATOmyEditor. It ensures that the given editor will be correctly
  * registrable inside the given registry (its identifier will be unique)
  *
  * @param iName [in]
  *   A displayable name of this editor.
  * @param iEditor [in]
  *   The CATBaseUnknown pointer that will be called to stream the
  *   information relative to the corresponding editor.
  * @param iRegisteringPurpose [in]
  *   The editor's registering purpose (LOCAL_SAVE, OPEN_NOTIF, ....)
  */
  CATOmyEditor * CreateEditor(const CATUnicodeString& iName,
    CATBaseUnknown* iEditor, unsigned int iRegisteringPurpose=LOCAL_SAVE);

	/** 
	* Registers a new CATOmyEditor in the session.
	*
	* @param iOmyEditor [in]
	*   The CATOmyEditor instance that has to be registered
	*
	* @return
	*   S_OK,   if the editor was correctly registered
	*   E_FAIL, if the editor could not be registered, specialy
  *           if its identifier was previously registered.
	*/
  HRESULT Register (const CATOmyEditor*& iOmyEditor);

	/** 
	* Removes a CATOmyEditor from the session. This method should be called when
  * the corresponding editor isn't used anymore
	*
	* @param iIdentifier [in]
	*   The identifier of the editor to be removed
	*
	* @return
	*   S_OK   if the editor was successfully removed from the session,
  *   E_FAIL otherwise.
	*/
  HRESULT RemoveEditor(int& iIdentifier);

	/** 
	* Searches a registered editor according to its identifier.
	*
	* @param iIdentifier [in]
	*   The identifier of the editor
	* @param oOmyEditor [out]
	*   The editor identified by the input identifier
	*
	* @return
	*   S_OK,   a corresponding editor was registered and retrieved,
  *   E_FAIL, otherwise.
	*/
  HRESULT FindEditorByIdentifier(int& iIdentifier, CATOmyEditor*& oOmyEditor);

	/** 
	* Retrieves an editor iterator to access the CATOmyEditors registered in the session.
    *
	* @param oEdtIterator [out]
	*   The current session editor iterator. Its content reflects the registered editors at the time of its creation, therefore 
	*  it should be used right away and deleted after use (it musn't be kept as a data member)
    * @param iRegisteringPurpose [in]
    *   The editor's registering purpose (LOCAL_SAVE, OPEN_NOTIF, ....)
	*
	* @return
	*   S_OK if the editor iterator was successfully retrieved,
  *   E_FAIL otherwise.
	*/
  HRESULT RetrieveEditors(CATOmyEditorIterator *& oEdtIterator, unsigned int iRegisteringPurpose=LOCAL_SAVE);
  
  /**
  * Retrieves the number of editors registered.
  */
  unsigned int GetEditorNumber(const RegisteringPurpose iPurpose = CATOmyEditorRegistry::UNDEFINED);


private:
  HRESULT GetFilteredEditors(const RegisteringPurpose iPurpose, CATListOfInt &oListOfEditors);
  CATOmyEditorHashTable * _editorHT;
  int _currentKey;
};

#endif
