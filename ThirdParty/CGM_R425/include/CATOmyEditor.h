/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2007
#ifndef CATOmyEditor_H
#define CATOmyEditor_H

#include "CATOMYBaseSession.h"
#include "CATIOmyEditorStream.h"


#include "CATUnicodeString.h"

#include "CATBoolean.h"

/**
 * @level Protected
 * @usage U1
 */

/**
 * This class is a used to represent an editor for LocalSave operations
 */
class ExportedByCATOMYBaseSession CATOmyEditor
{
  friend class CATOmyEditorRegistryMarshaller;
  friend class CATOmyEditorRegistry;
  friend class OmyTestEditorTable; // For EditorHT test
  friend class PLMBusRestoreLayout; // should disappear
  friend class CATBusLayoutCtrl; // should disappear

public :
  
  /** 
  * 
  *
  * <br><b>Role</b>: Destructor of CATOmyEditor.
  *
  */
  ~CATOmyEditor();
  typedef enum 
  {
	  LOCAL_SAVE  = 0x1,
	  OPEN_NOTIF  = 0x2,
  } RegisteringPurpose;


  /** 
  * Retrieves CATOmyEditor's identifier.
  *
  * <br><b>Role</b>: Retrieve CATOmyEditor's identifier.
  *
  * @param oEditorId [out]
  *   The editor's unique session identifier
  *
  */
  void GetEditorId(int& oEditorId);  
  
  
  /** 
  * Retrieves CATOmyEditor's displayable name.
  *
  * <br><b>Role</b>: Retrieves CATOmyEditor's displayable name.
  *
  * @param oEdtDisplayName [out]
  *   The editor's displayable name
  *
  */
  void GetEditorDisplayName(CATUnicodeString& oEdtDisplayName);   
  

  /** 
  * Retrieves CATOmyEditor's registering purpose.
  *
  * <br><b>Role</b>: Retrieves CATOmyEditor's registering purpose.
  *
  * @param oRegisteringPurpose [out]
  *   The editor's registering purpose (LOCAL_SAVE, OPEN_NOTIF, ....)
  *
  */
  void GetRegisteringPurpose(unsigned int & oRegisteringPurpose);   
  
  /** 
  * Retrieves CATOmyEditor's corresponding unmarshalling late type.
  *
  * <br><b>Role</b>: Retrieves CATOmyEditor'scorresponding unmarshalling late type.
  *
  * @param oUnmarshallingLateType [out]
  *   The late type implementing CATIOmyEditorUnstream interface.
  *
  */
  void GetUnmarshallingLateType(CATUnicodeString& oUnmarshallingLateType);
  
  
  /** 
  * Retrieves pointer used for marshalling the editor.
  *
  * <br><b>Role</b>: Retrieves pointer used for marshalling the editor.
  *
  * @param oMarshallingPrt [out]
  *   The CATIOmyEditorStream pointer that will be used to stream the editor
  *
  */
  void GetMarshallingPointer(CATIOmyEditorStream*& oMarshallingPrt);

/** 
  * Retrieves implementation used for marshalling the editor.
  *
  * <br><b>Role</b>: Retrieves implementation used for marshalling the editor.
  *
  * @param iIID [in]
  *   The interface on which QueryInterface will be made 
  * @param oPPV [out]
  *   The interface implementation pointer that will be used to stream the editor. You need to release 
  *   this pointer at the end of the treatment. 
  *
  */
  HRESULT GetEditorImplementation(const IID &iIID, void **oPPV);
  
  
  /** 
  * Flags the editor so that it will be streamed at the next stream in LocalSave directory.
  *
  * <br><b>Role</b>: Flags the editor so that it will be streamed at the next stream in LocalSave directory.
  * It should be called after each FrmEditor modificationby VPMNav so that this editor is streamed at next 
  * LocalSave operation.
  *
  */
  void HasToBeMarshalled();
  
  
  /** 
  * Allows to know if this editor has to be streamed at the next LocalSave operation.
  *
  * <br><b>Role</b>: Allows to know if this editor has to be streamed at the next LocalSave operation.
  *
  *
  * @return
  *   <code>TRUE</code> :  the editor will be streamed at next Local save operation.
  *   <code>FALSE</code>FALSE : the editor will not be streamed at next Local save Operation
  *
  */
  CATBoolean IsMarshallingNecessary();   

 private :

 /** 
  * Constructor of CATOmyEditor. A CATOmyEditor should be constructed each time a CATFrmEditor is created in the interactive session.
  *
  * <br><b>Role</b>: Constructor of CATOmyEditor. 
  * A CATOmyEditor should be constructed each time a CATFrmEditor is created in the interactive session.
  *
  * @param identifier_as_int [in]
  *   Identifier of the editor. This identifier must be unique in the session. The control of this unicity is done by the caller.
  * @param name [in]
  *   A displayable name of this editor.
  * @param latetype_for_unmarshalling [in]
  *   The latetype on which the CATIOmyEditorUnstream interface is implemented for this editor.
  * @param ptr_to_CATIOmyEditorStream [in]
  *   The CATIOmyEditorStream pointer that will be called to stream the information relative to the corresponding FrmEditor.
   * @param iRegisteringPurpose [in]
  *   Identifier of the editor. This identifier must be unique in the session. The control of this unicity is done by the caller.
  *
  */
 // CATOmyEditor(const int identifier_as_int, const CATUnicodeString& name, const CATUnicodeString& latetype_for_unmarshalling, CATIOmyEditorStream * ptr_to_CATIEditorStream, int );
  CATOmyEditor(const int identifier_as_int, const CATUnicodeString& name, const CATUnicodeString& latetype_for_unmarshalling, CATBaseUnknown * iEditor, unsigned int iRegisteringPurpose=LOCAL_SAVE);
  
  /**
   * internal method which resets _NeedToBeMarshalled at FALSE. This method is called after a LocalSave. 
   */
	 void HasBeenMarshalled();

  CATOmyEditor(const CATOmyEditor &); // not implemented
  CATOmyEditor & operator=(const CATOmyEditor &); // not implemented

   
  
int _UniqueEdtId;  //Unique session id of the editor. The personne responsible for the editors (VPMNav or ApplicationFrame)is responsible for creating this id and match it with the corresponding window.  
unsigned int _RegisteringPurpose;  //Unique session id of the editor. The personne responsible for the editors (VPMNav or ApplicationFrame)is responsible for creating this id and match it with the corresponding window.  

CATUnicodeString _DisplayableName;  //a displayable name for the user  

CATUnicodeString _UnmarshallingLateType;   //lateType on which the editor unmarshalling interface is implemented  

//CATIOmyEditorStream* _ptrEdtMarshallingItf;  //pointer towards an editor marshalling interface  
CATBaseUnknown* _ptrEdtMarshallingItf;  //pointer towards an editor marshalling interface  

CATBoolean _NeedToBeMarshalled;  //to know if the editor has been modified since the last save in the local save directory  


};

#endif
