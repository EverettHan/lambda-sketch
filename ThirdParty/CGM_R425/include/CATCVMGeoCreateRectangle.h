/* -*-C++-*- */

#ifndef CATCVMGeoCreateRectangle_H
#define CATCVMGeoCreateRectangle_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoCreateRectangle
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
class CATCVMComponent;
class CATMathPoint;
class CATMathVector;

class ExportedByCATCVMGeoOperators CATCVMGeoCreateRectangle : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a CreateEdge operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoCreateRectangle* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                          CATTopData         *iTopData);
  static CATCVMGeoCreateRectangle* Create(CATCVMInstancePath *iCVMInstancePath,
                                          CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoCreateRectangle(CATCVMGeoContainer   *iCVMGeoContainer,
                           CATTopData           *iTopData,
                           CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoCreateRectangle(CATTopData           *iTopData,
                           CATCVMGeoOperatorExt *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoCreateRectangle();

  //------------------------------------------------------------------------------
  // Set the host component (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetHostComponent(CATCVMComponent *iComponent);

  //------------------------------------------------------------------------------
  // Set the start vertex
  //------------------------------------------------------------------------------
  public:
  virtual void SetStartPoint(CATMathPoint &iMathPoint, CATCVMGeometry *iSupportGeometry);

  //------------------------------------------------------------------------------
  // Set the end vertex
  //------------------------------------------------------------------------------
  public:
  virtual void SetEndPoint(CATMathPoint &iMathPoint, CATCVMGeometry *iSupportGeometry);

  //------------------------------------------------------------------------------
  // Set the direction of an edge of the rectangle
  //------------------------------------------------------------------------------
  public:
  virtual void SetVector(CATMathVector &iMathVector);

  //------------------------------------------------------------------------------
  // Set the direction of an edge of the rectangle
  //------------------------------------------------------------------------------
  public:
  virtual void GetVertices(CATCVMGeometry * oVertices[4]);

  private:
  //virtual int RunOperator();
   
  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
