/* -*-C++-*- */

#ifndef CATCVMGeoCreateVertex_H
#define CATCVMGeoCreateVertex_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoCreateVertex
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June 2006    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"

class CATCVMGeoContainer;
class CATCVMInstancePath;
class CATCVMGeometry;
class CATCVMBody;
class CATMathPoint;
class CATCVMComponent;
class CATMathDirection;

class ExportedByCATCVMGeoOperators CATCVMGeoCreateVertex : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a CreateVertex operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoCreateVertex* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                       CATTopData         *iTopData);
  static CATCVMGeoCreateVertex* Create(CATCVMInstancePath *iCVMInstancePath,
                                       CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoCreateVertex(CATCVMGeoContainer   *iCVMGeoContainer,
                        CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoCreateVertex(CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoCreateVertex();

  //------------------------------------------------------------------------------
  // Set the CATMathPoint
  //------------------------------------------------------------------------------
  public:
  virtual void SetPoint(CATMathPoint &iMathPoint);

  //------------------------------------------------------------------------------
  // Set the support geometry (optional)
  //
  // Please note: Per default the operator merges the created vertex with the
  //              provided support. If this behavior is not desired, use the
  //              SetSupportMergeMode method
  //------------------------------------------------------------------------------
  public:
  virtual void SetSupportGeometry(CATCVMGeometry *iSupportGeometry);

  //------------------------------------------------------------------------------
  // Set the support projection mode (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetSupportProjectionMode(CATBoolean        iMode,                         // TRUE or FALSE
                                        CATMathDirection *iSupportProjectionDirection);  // used only if iMode == TRUE

  //------------------------------------------------------------------------------
  // Set the support merge mode (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetSupportMergeMode(CATBoolean iMode);

  //------------------------------------------------------------------------------
  // Set the host component (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetHostComponent(CATCVMComponent *iComponent);

  //------------------------------------------------------------------------------
  // Get the created vertex
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMGeometry *GetCreatedVertex();

  //------------------------------------------------------------------------------
  // Get the resulting CVM body
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMBody *GetResultingCVMBody();

  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
	//virtual int RunOperator();
     
  public:
  static const CATString *GetDefaultOperatorId();

  private:
  CATCVMGeoCreateVertex(const CATCVMGeoCreateVertex &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMGeoCreateVertex &);
};
#endif
