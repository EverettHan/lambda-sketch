// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIAdpType.h
// Define the CATIAdpType interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Apr 2005  Creation: Code generated by the CAA wizard  PMM
//===================================================================
/**
* @CAA2Level L1
* @CAA2Usage U3  
*/
#ifndef CATIAdpType_H
#define CATIAdpType_H

#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATPLMCoreType.h"

class CATUnicodeString ;
class CATString ;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentificationAccess IID IID_CATIAdpType;
#else
extern "C" const IID IID_CATIAdpType ;
#endif

//------------------------------------------------------------------

/**
* Interface representing PLM Type.
*
* <br><b>Role</b>: Components that implement this interface are PLM Type.
* You retrieves these objects using @href CATAdpDictionaryServices .
*/
class ExportedByCATPLMIdentificationAccess CATIAdpType: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
  * Gets the PLM Class type (name) as NLS name.
  *
  * <br><b>Role</b>: Allows the user to retrieve the PLM class type (name).as NLS name
  *
  * @param oAlias [out]
  *   The modeler name.
  * @return
  * <dt> <code>S_OK</code>     <dd> an Alias was retrieved.
  * <dt> <code>S_FALSE</code>  <dd> No alias retrieve.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  virtual HRESULT GetAlias( CATUnicodeString & oAlias )=0;

  /**
  * Gets the PLM Core Type.
  *
  * <br><b>Role</b>: Allows the user to retrieve the PLM core type.
  *
	* @param oCoreType [out]
  *   The environment Core Type.
  * @return
  * <dt> <code>S_OK</code>     <dd> an Core Type was retrieved.
  * <dt> <code>S_FALSE</code>  <dd> No Core Type retrieve.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  virtual HRESULT GetPLMCoreType(CATPLMCoreType & oCoreType)=0;

   /**
  * Gets the modeler name.
  *
  * <br><b>Role</b>: Allows the user to retrieve the name of the modeler
  *
  * @param oModeler [out]
  *   The modeler.
  * @return
  * <dt> <code>S_OK</code>     <dd> a Modeler was retrieved.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  virtual HRESULT GetPLMModeler( CATUnicodeString & oModeler )=0;


  /**
  * Compares two PLM types.
  *
  * @param iOtherType [in]
  *   The type to compare.
  * @return
  *   TRUE if the types are identical and FALSE otherwise.
  */
  virtual CATBoolean IsEqual (const CATIAdpType *iOtherType) = 0;

  /**
  * Retrieves the PLM Class and modeler information defining the PLM type.
  *
  * @param oModelerName [out]
  *   The modeler associated to the PLM type.
  * @param oModelerPLMClassName [out]
  *   The PLM Modeler Class Name. 
  * @param oCustoPLMModelerClassName [out]
  *   The Name of the Customized PLM Modeler Class. This string is empty if <tt> oModelerPLMClassName </tt> is a concrete PLM type.
  *   If <tt> oCustoPLMModelerClassName </tt> is not empty, the PLM type inherits from <tt> oModelerPLMClassName </tt>.
  * @return
  * <dt> <code>S_OK</code>     <dd> The values are usable.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  virtual HRESULT GetTypeIdentification (CATString &oModelerName, 
                                         CATString &oModelerPLMClassName, 
                                         CATString &oCustoPLMModelerClassName) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler( CATIAdpType, CATBaseUnknown );
//------------------------------------------------------------------

#endif
