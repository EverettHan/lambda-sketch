/* -*-C++-*- */
#ifndef CATPrPattern1DLinear_H
#define CATPrPattern1DLinear_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrPattern1DLinear
// one-dimension Linear Table of CATPrRep, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATPrPattern1D.h"
#include "CATCGMVirtual.h"
#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"

class ExportedByAdvOpeInfra CATPrPattern1DLinear : public CATPrPattern1D
{
public:
  //------------------------------------------------------------------------------
  // Recognizer Constructor
  //------------------------------------------------------------------------------
  CATPrPattern1DLinear(CATPrContext& iContext);

  //------------------------------------------------------------------------------
  // Actual Pattern Constructor ( iStep(ioRep1)==ioRep2, iStep(ioRep2)==ioRep3 )
  //------------------------------------------------------------------------------
  CATPrPattern1DLinear(CATPrContext& iContext, const CATMathTransformation& iStep, CATPrRep*& ioRep1, CATPrRep*& ioRep2, CATPrRep*& ioRep3);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrPattern1DLinear();

  //------------------------------------------------------------------------------
  // Catalyze (identify basic patterns)
  //------------------------------------------------------------------------------
  CATPrPattern* Catalyze(CATPrSet& ioSet, CATListOfInt& iOrderedRepIndexes, const int iRepIndex1);

  //------------------------------------------------------------------------------
  // returns class name
  //------------------------------------------------------------------------------
  virtual void GetClassName(CATUnicodeString& oClassName) const;

  //------------------------------------------------------------------------------
  // Check
  //------------------------------------------------------------------------------
  void Check();


};

#endif
