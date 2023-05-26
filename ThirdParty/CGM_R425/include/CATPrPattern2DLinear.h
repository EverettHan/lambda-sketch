/* -*-C++-*- */
#ifndef CATPrPattern2DLinear_H
#define CATPrPattern2DLinear_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrPattern2DLinear
// two-dimension Linear Table of CATPrRep, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATPrPattern2D.h"
#include "CATCGMVirtual.h"
#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"

class ExportedByAdvOpeInfra CATPrPattern2DLinear : public CATPrPattern2D
{
public:
  //------------------------------------------------------------------------------
  // Recognizer Constructor
  //------------------------------------------------------------------------------
  CATPrPattern2DLinear(CATPrContext& iContext);

  //------------------------------------------------------------------------------
  // Actual Pattern Constructor ( ioRep2 = iStep1(ioRep1), ioRep3 = iStep2(ioRep1), ioRep4 = iStep2(iStep1((ioRep1)) ) 
  //------------------------------------------------------------------------------
  CATPrPattern2DLinear(CATPrContext& iContext, const CATMathTransformation& iStep1, const CATMathTransformation& iStep2, CATPrRep*& ioRep1, CATPrRep*& ioRep2, CATPrRep*& ioRep3, CATPrRep*& ioRep4);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrPattern2DLinear();

  //------------------------------------------------------------------------------
  // Safe Cast
  //------------------------------------------------------------------------------
  CATPrPattern2DLinear* GetAsPattern2DLinear();

  //------------------------------------------------------------------------------
  // Catalyze (identify basic patterns)
  //------------------------------------------------------------------------------
  CATPrPattern* Catalyze(CATPrSet& ioSet, CATListOfInt& iOrderedRepIndexes, const int iRepIndex1);

  //------------------------------------------------------------------------------
  // returns class name
  //------------------------------------------------------------------------------
  virtual void GetClassName(CATUnicodeString& oClassName) const;

  //------------------------------------------------------------------------------
  // Return inside ColumnTransformation
  //------------------------------------------------------------------------------
  void GetColumnTransformation(const int iColumn, CATMathTransformation& oTransfo) const;

  //------------------------------------------------------------------------------
  // Check
  //------------------------------------------------------------------------------
  void Check();

};

#endif
