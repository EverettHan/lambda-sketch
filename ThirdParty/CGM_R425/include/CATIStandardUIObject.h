/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2002
#ifndef CATIStandardUIObject_H
#define CATIStandardUIObject_H

#include "CATBaseUnknown.h"

/**
 * Interface to read and modify standard values inside Standard Editor panel
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIStandardUIObject;
#else
extern "C" const IID IID_CATIStandardUIObject;
#endif

#include "CATLISTV_Declare.h"
class CATLISTV(CATBaseUnknown_var);

class CATUnicodeString;
class CATIStandardObject;
class CATIStandardManager;

class ExportedByUIModelInterfaces CATIStandardUIObject : public CATBaseUnknown
{ 
  CATDeclareInterface;

  public:

  /**
  * GetStandardObject
  * @param  oStdObj
  * To retrieve the model object which contains all data informations
  * @return
  * Release to do on oStdObject
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetStandardObject(CATIStandardObject **oStdObject) = 0;

  /**
  * GetStandardManager
  * @param  oStdMng
  * To retrieve the model object witch contains all data informations
  * @return
  * Release to do on oStdMng
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetStandardManager(CATIStandardManager **oStdMng) = 0;

  /**
  * GetName
  * @param  oName
  * To retrieve the NLS name of current object
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetName(CATUnicodeString &oStg) = 0;

  /**
  * IsStructType
  * To manage structure type
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  enum StructType{YES=1, NO=2};

  /**
  * IsStructType
  * To manage structure type
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT IsStructType(CATIStandardUIObject::StructType &oType) = 0;

  /**
  * GetObjRefPosition
  * @param  oPositionInStruct
  * To know which instance of the structure is currently
  * edited (the standard object is the same for all instances)
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetObjRefPosition(int *oPositionInStruct) = 0;

  /**
  * GetAssociatedValues
  * Read all values as temporary literals
  */
  virtual const CATListValCATBaseUnknown_var * GetAssociatedValues() = 0;

  /**
  * IsReadOnly()
  * The editor should be in read-only if the user is not an administrator
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK if ReadOnly, E_FAIL if modification is allowed
  */
  virtual HRESULT IsReadOnly() = 0;

  /**
  * CommitModification()
  * To declare the current standard as dirty and request a save
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT CommitModification() = 0;
};
CATDeclareHandler(CATIStandardUIObject, CATBaseUnknown);

#endif  

