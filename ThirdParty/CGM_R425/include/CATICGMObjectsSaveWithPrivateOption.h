//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//=============================================================================
//
// DESCRIPTION  : Specific stream interface with stream option (internal use)
//                
//=============================================================================
// Creation YL3 Feb 2023
//=============================================================================

#ifndef CATICGMObjectsSaveWithPrivateOption_h
#define CATICGMObjectsSaveWithPrivateOption_h

#include "CATICGMObjectsPersistency.h"
#include "ExportedByGeometricObjects.h"
#include "CATDataType.h"
#include "CATCGMStreamPrivateOption.h"

/**
  Save a set of geometrical objects belonging to the same CATGeoFactory
  This is a specific save tool with private option
*/
class ExportedByGeometricObjects CATICGMObjectsSaveWithPrivateOption : public CATICGMObjectsSave
{
#if defined (CATIACGMR426CAA)
    CATDeclareClass;
#endif
public:
  /**
  * Constructor.
  */
  CATICGMObjectsSaveWithPrivateOption(CATCGMStream& ioStreamArea);
  /**
  * Destructor
  */
  ~CATICGMObjectsSaveWithPrivateOption();


#ifdef DEFINE_IN_PARENT_CLASS_CATICGMObjectsSave
  // To be used only as part of specific BackSave process
  void SetTargetVersion(CATCGMStreamVersion& iTargetVersion);

  // Get Short enumeration of some usefull failures occuring during save attempt
  CATICGMObjectsSaveDiagnosis GetDiagnosis();
 
  /**
 * Run Save.
 * @param iFullFederatorObjects
 *   Set of objects to Save.
 *   Each Object must be a non null value and all objects must be contained in the same CATGeoFactory.
 * @param iLightSubsetObjects
 *   Light subset of objects that may be loaded partially afterwards.
 *   List may be empty.
 *   Each Object must be a non null value and all objects must be contained in the same CATGeoFactory.
 *   Each Object must be equals or contained in previous list of <tt>iFullFederatorObjects</tt>.
 * @return
 * The result of the operation.
 * <br><b>Legal values</b>:
 * <dl>
 * <dt><tt>S_OK</tt>   <dd> if operation succeed.
 * <dt><tt>E_FAIL</tt> <dd> if operation fails.
 *</dl>
 */
  HRESULT   Save(const CATLISTP(CATICGMObject)& iFullFederatorObjects,
    const CATLISTP(CATICGMObject)* iLightSubsetObjects = NULL);
#endif

  /**
  * @nodoc
  * SetCGMStreamPrivateOption
  */
  void SetCGMStreamPrivateOption(const CATCGMStreamPrivateOption& iStreamOption);

  /**
   * @nodoc
  * GetCGMStreamPrivateOption
  */
  CATCGMStreamPrivateOption GetCGMStreamPrivateOption() const;


private:

  CATCGMStreamPrivateOption _PrivateStreamOption;
  //------------------------------------------------------------------------
  // Forbidden (Declared, Not Defined) : Constructor by copy  et   operator =
  //------------------------------------------------------------------------
  CATICGMObjectsSaveWithPrivateOption(const CATICGMObjectsSaveWithPrivateOption& iCopy);
  CATICGMObjectsSaveWithPrivateOption& operator=(const CATICGMObjectsSaveWithPrivateOption& iCopy);
};

#endif
