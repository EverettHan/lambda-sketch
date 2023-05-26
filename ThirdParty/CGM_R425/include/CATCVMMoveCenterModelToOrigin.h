/* -*-C++-*- */

#ifndef CATCVMMoveCenterModelToOrigin_H
#define CATCVMMoveCenterModelToOrigin_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMMoveCenterModelToOrigin
//
// class pour recentrer les modele
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Dec. 2007    Creation                         Delphine Jennequin
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "ListPOfCATCVMBody.h"
#include "ListPOfCATCVMObject.h"
#include "CATMathBox.h"
#include "CATMathTransformation.h"

class CATCGMOutput;
class CATCVMContainer;

class ExportedByCATCVMGeoOperators CATCVMMoveCenterModelToOrigin : public CATCVMGeoOperator
{
   //------------------------------------------------------------------------------
  // Create a Transfo operator
  //------------------------------------------------------------------------------
public:
  static CATCVMMoveCenterModelToOrigin* Create(CATCVMGeoContainer *iCVMGeoContainer, CATTopData *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
protected:
  CATCVMMoveCenterModelToOrigin(CATCVMGeoContainer *iContainer, CATTopData *iTopData,CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
public:
  virtual ~CATCVMMoveCenterModelToOrigin();
  
  //------------------------------------------------------------------------------
  // Set
  //------------------------------------------------------------------------------
  public:
  virtual void SetBodies(ListPOfCATCVMBody & iBodies);

  public:
  virtual void GetTransformation(CATMathTransformation& ioTransfo);

  //public:
  //static const CATString *GetDefaultOperatorId();

};
#endif
