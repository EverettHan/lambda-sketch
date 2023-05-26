#ifndef CATIPLM3dxmlIdentification_H
#define CATIPLM3dxmlIdentification_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//
// Usage notes : 3DXML identification Interface
//
//===================================================================
//
//  December 2006 - Creation - pir
//===================================================================


/**
 * @level Protected
 * @usage U3      
 */

/**
 * 
 * <br><b>Role</b>: This interface allows to access 3DXML identification from Identificators of objects and reverse.
 * 
 */
#include "CATBaseUnknown.h"

#include "CATPLMIdentificationAccess.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListPtrCATIAdpPLMIdentificator.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentificationAccess IID IID_CATIPLM3dxmlIdentification;
#else
extern "C" const IID IID_CATIPLM3dxmlIdentification ;
#endif

//------------------------------------------------------------------
#define AuthorizedModule 999
// List of authorized modules
#define CATPLMIdentificationAccess                 AuthorizedModule
#define CATDxp3DXMLIdentification                  AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATIPLM3dxmlIdentification from a non-authorized module
// Fatal error on solaris
@error 
#endif

#undef CATPLMIdentificationAccess
#undef CATDxp3DXMLIdentification

class ExportedByCATPLMIdentificationAccess CATIPLM3dxmlIdentification : public CATBaseUnknown
{
	CATDeclareInterface;

public:

  /**
   * Get 3DXML IDs from Identificators of the objects in session.
   *
   * <br><b>Role</b>: This method is used to get the 3DXML IDs of session objects.
   *
   * @param iListofObjectsIDs
   * the list of objects Identificators in session.
   *
   * @param oListOf3DXMLIDs
   * the returned corresponding list of 3DXMLIDs.
   *
   * @return 
   * <tt>S_OK</tt> if IDs has been successfully retrieved
   * <br><tt>E_FAIL</tt> for failure
   *
   */
  virtual HRESULT Get3DXMLIdsFromIdenfificators(CATLISTP(CATIAdpPLMIdentificator)& iListofObjectsIDs, CATListOfCATUnicodeString& oListOf3DXMLIDs) = 0;
 
  /**
   * Get Identificators of the session objects from 3DXMLIDs.
   *
   * <br><b>Role</b>: This method is used to get the Identificators of 3DXML objects.
   *
   * @param iListOf3DXMLIDs
   * the list of 3DXMLIDs.
   *
   * @param oListofObjectsIDs
   * the returned corresponding list of identificators.
   *
   * @return 
   * <tt>S_OK</tt> if IDs has been successfully retrieved
   * <br><tt>E_FAIL</tt> for failure
   *
   */
  virtual HRESULT GetIdentificatorsFrom3DXMLIds(CATListOfCATUnicodeString& iListOf3DXMLIDs, CATLISTP(CATIAdpPLMIdentificator)& oListofObjectsIDs) = 0;


};


#endif
