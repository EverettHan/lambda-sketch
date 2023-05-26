// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATICGRModel.h
// Define the CATICGRModel interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  August 2003  Creation
//===================================================================
#ifndef CATICGRModel_H
#define CATICGRModel_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySGInfra IID IID_CATICGRModel;
#else
extern "C" const IID IID_CATIModel;
#endif

class CATRep;
class CATCGRSetting;

//------------------------------------------------------------------

/**
 * Describe the functionality of your interface here
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedBySGInfra CATICGRModel: public CATBaseUnknown
{
  CATDeclareInterface;

public:
 
 /**@nodoc
  *  Build the alternate CGR Rep.
  * @return
  *    If everything is OK, the function returns a valid pointer to a CAT3DRep,
  *    else, it returns a NULL pointer.
  */
  virtual CATRep *      BuildCGRRep() = 0;
 
 /**@nodoc
  *  Check if a CGRmodel is filtered.
  *  @return
  *   <dl>
  *      <dt>0</dt>
  *        <dd>The current CGRmodel is not filtered in the current CGRcontainer</dd>
  *      <dt>1</dt>
  *        <dd>The current CGRmodel is filtered in the current CGRcontainer</dd>
  *   </dl>
  * @param   iApplicativeFilters
  *    The list of filters of the current CGRcontainer.
  */
  virtual int           IsFiltered(const CATListOfCATUnicodeString * iApplicativeFilters) = 0;

   /**@nodoc
  *  Destroy the alternate CGR Rep.
  * @return
  *    If everything is OK, the function returns S_OK else E_FAIL.
  */
  virtual HRESULT DestroyCGRRep(CATRep *iCGRRep) = 0;
  
 /**@nodoc
  *  Force the setting in the alternate CGR Rep Tree.
  * @return
  *    Forced Settings.
  * @param   iSetting
  *    The actual CGR Settings.Can be read to build the alternate setting.
  */
  virtual CATCGRSetting* GetCGRSetting(const CATCGRSetting* iSetting) = 0;

};

/**  @nodoc  */ 
CATDeclareHandler(CATICGRModel,CATBaseUnknown); 

//------------------------------------------------------------------

#endif
