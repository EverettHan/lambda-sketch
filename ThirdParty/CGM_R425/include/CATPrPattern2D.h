/* -*-C++-*- */
#ifndef CATPrPattern2D_H
#define CATPrPattern2D_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrPattern2D
// two-dimension Table of CATPrRep, dedicated to Pattern Recognition
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

class CATPrPattern2DLinear;
class CATPrPattern2DCircular;

class ExportedByAdvOpeInfra CATPrPattern2D : public CATPrPattern
{
public:
  //------------------------------------------------------------------------------
  // Recognizer Constructor
  //------------------------------------------------------------------------------
  CATPrPattern2D(CATPrContext& iContext);

  //------------------------------------------------------------------------------
  // Actual Pattern Constructor 
  //------------------------------------------------------------------------------
  CATPrPattern2D(CATPrContext& iContext, const CATMathTransformation& iStep1, const CATMathTransformation& iStep2, const int iRowSize);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrPattern2D();

  //------------------------------------------------------------------------------
  // Safe Cast
  //------------------------------------------------------------------------------
  CATPrPattern2D* GetAsPattern2D();
  virtual CATPrPattern2DLinear* GetAsPattern2DLinear();
  virtual CATPrPattern2DCircular* GetAsPattern2DCircular();

  //------------------------------------------------------------------------------
  // Absorb all possible instances
  //------------------------------------------------------------------------------
  void GrowNetwork(CATPrSet& iSet, CATListOfInt& iOrderedRepIndexes);

  //------------------------------------------------------------------------------
  // Return Row & Column numbers
  //------------------------------------------------------------------------------
  int GetColumnCount() const;
  int GetRowCount() const; 

  //------------------------------------------------------------------------------
  // Return inside Row Transformation
  //------------------------------------------------------------------------------
  const CATMathTransformation& GetRowTransformation() const;

  //------------------------------------------------------------------------------
  // Rep access
  //------------------------------------------------------------------------------
  CATPrRep* GetRep(const int iRow, const int iColumn);

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

  CATBoolean AddRow(CATPrSet& iSet, CATListOfInt& iOrderedRepIndexes, const int iSide);
  CATBoolean AddColumn(CATPrSet& iSet, CATListOfInt& iOrderedRepIndexes, const int iSide);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
protected: // :-( Todo
  CATMathTransformation _Step[2]; // _Step[0] allow to change instance inside a Row, _Step[1] allow to change instance inside first column (_Step[1] is a translation)

private:
  int                   _RowSize;

};

#endif
