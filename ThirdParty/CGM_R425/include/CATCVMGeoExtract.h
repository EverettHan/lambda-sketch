#ifndef CATCVMGeoExtract_h 
#define CATCVMGeoExtract_h
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATCVMGeoExtract :
// Classe générique permettant la gestion du CopyPaste
//
//=============================================================================
// mars    2007  Création                    Etienne Bartholomot
//=============================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"

#include "ListPOfCATCVMObject.h"
#include "ListPOfCATCVMInstancePath.h"

class CATCVMGeoContainer;
class CATTopData;
class CATCVMGeoOperatorExt;
class CATCVMGeoExtractData;
class CATCVMComponent;
class CATCVMSystem;
class CATString;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoExtract : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a Extract operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoExtract *Create(CATCVMGeoContainer *iCVMGeoContainer,
                                  CATTopData         *iTopData);
  static CATCVMGeoExtract *Create(CATCVMInstancePath *iCVMInstancePath,
                                  CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoExtract(CATCVMGeoContainer   *iCVMGeoContainer,
                   CATTopData           *iTopData,
                   CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoExtract(CATTopData           *iTopData,
                   CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoExtract();

  //------------------------------------------------------------------------------
  // SetObjectList
  //------------------------------------------------------------------------------
  public:
  void SetObjectList(ListPOfCATCVMObject & iObjectList);

/*
  //------------------------------------------------------------------------------
  // Set the host component (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetHostComponent(CATCVMComponent *iComponent);

*/
/*
  //------------------------------------------------------------------------------
  // Set the incrementation value for the extension of the name for the copy
  //------------------------------------------------------------------------------
  public:
  virtual void SetNameExtensionIncrement(int iExtensionIncrementValue);
*/
  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
	//virtual int RunOperator();
     
/*
  //------------------------------------------------------------------------------
  // Get number of resulting systems
  //------------------------------------------------------------------------------
  public:
  virtual int GetNbResultingSystems();
*/
/*
  //------------------------------------------------------------------------------
  // Get resulting system
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMSystem *GetResultingSystem(int iIndex);
*/
  //------------------------------------------------------------------------------
  // Get copy
  //------------------------------------------------------------------------------
  public:
  CATCVMGeoExtractData * GetExtractData();

  //------------------------------------------------------------------------------
  // No Duplicate Mode
  //------------------------------------------------------------------------------
  public:
  void DoNotDuplicate();
  
  public:
  static const CATString *GetDefaultOperatorId();
};
#endif

