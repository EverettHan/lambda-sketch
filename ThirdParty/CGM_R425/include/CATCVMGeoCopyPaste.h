#ifndef CATCVMGeoCopyPaste_h 
#define CATCVMGeoCopyPaste_h
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATCVMGeoCopyPaste :
// Classe générique permettant la gestion du Copy Paste
//
//=============================================================================
// Mars    2007  Création                    Etienne Bartholomot
//=============================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"

class CATCVMGeoContainer;
class CATTopData;
class CATCVMGeoExtractData;
class CATCVMComponent;
class CATCVMObject;
class CATCVMSystem;
class CATMathTransformation;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoCopyPaste : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a Copy operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoCopyPaste *Create(CATCVMGeoContainer *iCVMGeoContainer,
                                    CATTopData         *iTopData);
  static CATCVMGeoCopyPaste *Create(CATCVMInstancePath *iCVMInstancePath,
                                    CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoCopyPaste(CATCVMGeoContainer   *iCVMGeoContainer,
                     CATTopData           *iTopData,
                     CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoCopyPaste(CATTopData           *iTopData,
                     CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoCopyPaste();

  //------------------------------------------------------------------------------
  // Extract Data
  //------------------------------------------------------------------------------
  public:
  virtual void SetExtractData(CATCVMGeoExtractData * iExtractData);

  //------------------------------------------------------------------------------
  // resulting CVMObjects
  //------------------------------------------------------------------------------
  public:
  virtual void GetObjectList(ListPOfCATCVMObject & oObjectList);
  
  //------------------------------------------------------------------------------
  // The Merge Option
  //------------------------------------------------------------------------------
  public:
  virtual void MergeGeometry();

  //------------------------------------------------------------------------------
  // Set the host component (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetHostComponent(CATCVMComponent *iComponent);

  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
	//virtual int RunOperator();
  
  public:
  static const CATString *GetDefaultOperatorId();
  
};
#endif

