/* -*-C++-*- */
#ifndef CATPrPattern1D_H
#define CATPrPattern1D_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrPattern1D
// one-dimension Table of CATPrRep, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATPrPattern.h"
#include "CATCGMVirtual.h"
#include "CATCGMNewArray.h"
#include "CATMathTransformation.h"
#include "AdvOpeInfra.h"

class CATPrPattern1DLinear;
class CATPrPattern1DCircular;

class ExportedByAdvOpeInfra CATPrPattern1D : public CATPrPattern
{
public:
  //------------------------------------------------------------------------------
  // Recognizer Constructor
  //------------------------------------------------------------------------------
  CATPrPattern1D(CATPrContext& iContext);

  //------------------------------------------------------------------------------
  // Actual Pattern Constructor 
  //------------------------------------------------------------------------------
  CATPrPattern1D(CATPrContext& iContext, const CATMathTransformation& iStep);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrPattern1D();

  //------------------------------------------------------------------------------
  // Allow to Grow
  //------------------------------------------------------------------------------
  virtual CATBoolean CanGrow();

  //------------------------------------------------------------------------------
  // Absorb all possible instances
  //------------------------------------------------------------------------------
  void GrowNetwork(CATPrSet& iSet, CATListOfInt& iOrderedRepIndexes);
  
  //------------------------------------------------------------------------------
  // Return Row & Column numbers
  //------------------------------------------------------------------------------
  int GetRowCount() const; 
  int GetColumnCount() const;

  //------------------------------------------------------------------------------
  // Return inside Row Transformation & inside ColumnTransformation
  //------------------------------------------------------------------------------
  const CATMathTransformation& GetRowTransformation() const;
  void GetColumnTransformation(const int iColumn, CATMathTransformation& oTransfo) const;

  //------------------------------------------------------------------------------
  // Safe Cast
  //------------------------------------------------------------------------------
  CATPrPattern1D* GetAsPattern1D();
  virtual CATPrPattern1DLinear* GetAsPattern1DLinear();
  virtual CATPrPattern1DCircular* GetAsPattern1DCircular();

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  void Dump(CATCGMOutput& ioOS);

  //------------------------------------------------------------------------------
  // Check
  //------------------------------------------------------------------------------
  void Check();

  //------------------------------------------------------------------------------
  // Private section
  //------------------------------------------------------------------------------
private:
  //------------------------------------------------------------------------------
  // Smooth the Transformation in order to better fit current instances
  //------------------------------------------------------------------------------
  CATBoolean FixSpecWithCurrentResult();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  CATMathTransformation   _Step;

};

#endif
