/* -*-C++-*- */

#ifndef CATCVMGeoTransfo_H
#define CATCVMGeoTransfo_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoTransfo
//
//===================================================================


//===================================================================
// Example of use:
// CATCVMGeoTransfo * Transfo = Create(Container, TopData);
// Transfo->SetBodies(Bodies);//To be done only once 
// while (InCommand)
// {
//   Transfo->Run();//At the first call to Run() there is no transformation set: it must be done just to retrieve the DoF
//               //At the next calls to Run(), transformation is applied
//   CATMathTransformation Transformation = ... // Get transformation as UI input, by taking into account the DoF
//   Transfo->SetTransformation(CATMathTransformation &iTransformation);
// }
//===================================================================

//===================================================================
// June 2007    Creation                         KUB
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "ListPOfCATCVMBody.h"

class CATCVMGeoContainer;
class CATCVMGeometry;
class CATMathTransformation;
class CATCVMBody;
class CATCVMDoF;

class ExportedByCATCVMGeoOperators CATCVMGeoTransfo : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a Transfo operator
  //------------------------------------------------------------------------------
public:
  static CATCVMGeoTransfo* Create(CATCVMGeoContainer *iCVMGeoContainer, CATTopData *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
protected:
  CATCVMGeoTransfo(CATCVMGeoContainer *iCVMGeoContainer, CATTopData  *iTopData, CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
public:
  virtual ~CATCVMGeoTransfo();

  //------------------------------------------------------------------------------
  // Specifies iBodies to transform. All these cells are considered as a rigid group in all 
  // calls to GetDoF() and to Run().
  // This method must be called only once, before the first call to GetDoF() or Run(). 
  // If iBoundaryOption is set to TRUE, the Boundary Cells of input cells will be added
  // in the list of the dragged cells
  //------------------------------------------------------------------------------
public:
  virtual void SetBodies(ListPOfCATCVMBody & iBodies);

  public:
  virtual void SetTransformation(CATMathTransformation &iTransformation);

 public:
  static const CATString *GetDefaultOperatorId();

};
#endif
