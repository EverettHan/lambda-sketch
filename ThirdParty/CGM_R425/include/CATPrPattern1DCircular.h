/* -*-C++-*- */
#ifndef CATPrPattern1DCircular_H
#define CATPrPattern1DCircular_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrPattern1DCircular
// one-dimension Circular Table of CATPrRep, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATPrPattern1D.h"
#include "CATCGMVirtual.h"
#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"

class ExportedByAdvOpeInfra CATPrPattern1DCircular : public CATPrPattern1D
{
public:
  //------------------------------------------------------------------------------
  // Recognizer Constructor
  //------------------------------------------------------------------------------
  CATPrPattern1DCircular(CATPrContext& iContext);

  //------------------------------------------------------------------------------
  // Actual Pattern Constructor ( iStep(ioRep1)==ioRep2, iStep(ioRep2)==ioRep3, iStep(ioRep3)==ioRep4 )
  //------------------------------------------------------------------------------
  CATPrPattern1DCircular(CATPrContext& iContext, const CATMathTransformation& iStep, CATPrRep*& ioRep1, CATPrRep*& ioRep2, CATPrRep*& ioRep3, CATPrRep*& ioRep4);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrPattern1DCircular();

  //------------------------------------------------------------------------------
  // Catalyze (identify basic patterns)
  //------------------------------------------------------------------------------
  CATPrPattern* Catalyze(CATPrSet& ioSet, CATListOfInt& iOrderedRepIndexes, const int iRepIndex1);

  //------------------------------------------------------------------------------
  // Stops growing after 2PI
  //------------------------------------------------------------------------------
  CATBoolean CanGrow();

  //------------------------------------------------------------------------------
  // returns class name
  //------------------------------------------------------------------------------
  virtual void GetClassName(CATUnicodeString& oClassName) const;

  //------------------------------------------------------------------------------
  // Check
  //------------------------------------------------------------------------------
  void Check();

  //------------------------------------------------------------------------------
  // Private section
  //------------------------------------------------------------------------------
private:

};

#endif
