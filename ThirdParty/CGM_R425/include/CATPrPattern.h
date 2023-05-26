/* -*-C++-*- */
#ifndef CATPrPattern_H
#define CATPrPattern_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrPattern
// Table of CATPrRep, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATPrSet.h"
#include "CATCGMNewArray.h"
#include "CATListOfULONG32.h"
#include "AdvOpeInfra.h"
#include "CATSafe.h"
CATSafeDefine(CATPrPattern);       

class CATPrPattern1D;
class CATPrPattern2D;

class ExportedByAdvOpeInfra CATPrPattern : public CATPrSet
{
  public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATPrPattern(CATPrContext& iContext);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATPrPattern();

  //==============================================================================
  // Mandatory methods to be implemented for a Pattern type
  //==============================================================================
  //------------------------------------------------------------------------------
  // Catalyze (identify basic patterns) around iRepIndex1 in ioSet
  //------------------------------------------------------------------------------
  virtual CATPrPattern* Catalyze(CATPrSet& ioSet, CATListOfInt& iOrderedRepIndexes, const int iRepIndex1) = 0;

  //------------------------------------------------------------------------------
  // Absorb all possible instances
  //------------------------------------------------------------------------------
  virtual void GrowNetwork(CATPrSet& iSet, CATListOfInt& iOrderedRepIndexes) = 0;

  //------------------------------------------------------------------------------
  // Return Row & Column numbers
  //------------------------------------------------------------------------------
  virtual int GetRowCount() const = 0; // returns 1 for 1D Patterns
  virtual int GetColumnCount() const = 0;

  //------------------------------------------------------------------------------
  // Return inside-Row Transformation & inside-Column Transformation
  //------------------------------------------------------------------------------
  virtual const CATMathTransformation& GetRowTransformation() const = 0;
  virtual void GetColumnTransformation(const int iColumn, CATMathTransformation& oTransfo) const = 0;

  //==============================================================================
  // Debug
  //==============================================================================
  void Display(const CATBoolean iClearCreatedObjetcsAtDelete = TRUE);

  //==============================================================================
  // Algorithm implementation
  //==============================================================================
  //------------------------------------------------------------------------------
  // Recognize Patterns from Sets
  //------------------------------------------------------------------------------
  static void Recognize(CATPrContext& iContext, ListPOfCATPrPattern& iRecognizers, ListPOfCATPrSet& iSets, ListPOfCATPrPattern& oPatterns);

  //------------------------------------------------------------------------------
  // Get Rep
  //------------------------------------------------------------------------------
  // CATPrRep* GetRep(const int irow, const int icolumn); 
 
  //------------------------------------------------------------------------------
  // Safe Cast
  //------------------------------------------------------------------------------
  virtual CATPrPattern1D* GetAsPattern1D();
  virtual CATPrPattern2D* GetAsPattern2D();

  //------------------------------------------------------------------------------
  // Get Mapping info between Reps
  //------------------------------------------------------------------------------
  int GetMostCompleteInstance(CATListOfULONG32& oStamps);

  //==============================================================================
  // Protected section
  //==============================================================================
  //------------------------------------------------------------------------------
  // Check
  //------------------------------------------------------------------------------
  void Check();
 
  //==============================================================================
  // Protected section
  //==============================================================================
protected :

  //------------------------------------------------------------------------------
  // Get the Relation between Rep1 & Rep2
  //------------------------------------------------------------------------------
  void GetIsometry(const int iRepIndex1, const int iRepIndex2, CATMathTransformation &oTransfoFrom1To2);

  //==============================================================================
  // Private section
  //==============================================================================
private :

  //------------------------------------------------------------------------------
  // Grow with ioReps if they are isometric: forbidden
  //------------------------------------------------------------------------------
  CATBoolean Grow(CATLISTP(CATPrRep) &ioReps, const int iStartIndex);

  //------------------------------------------------------------------------------
  // Grow Shape 
  //------------------------------------------------------------------------------
  void       GrowShape                  (ListPOfCATPrSet& ioSetsToGrowIn, ListPOfCATPrSet& ioNewSets);
  CATBoolean GrowShapeWithFrozenBoundary(ListPOfCATPrSet& iSets, ListPOfCATPrSetRepList& ioAdjacentReps, ListPOfCATPrSet& oNewSets);

  //------------------------------------------------------------------------------
  // Delete & Remove from list NULL or Empty Patterns
  //------------------------------------------------------------------------------
  void ComputeAdjacentReps(ListPOfCATPrSet& iSets, const int StartIndex, const CATPrRep::Convexity iConvexity, ListPOfCATPrSetRepList& oAdjacentReps);

  //------------------------------------------------------------------------------
  // Delete & Remove from list NULL or Empty Patterns
  //------------------------------------------------------------------------------
  static void DeleteEmpty(ListPOfCATPrPattern& ioPatterns);

  //------------------------------------------------------------------------------
  // Compare 2 instances
  //------------------------------------------------------------------------------
  static int Compare2Patterns(CATPrPattern* iInstance1, CATPrPattern* iInstance2);

};


#endif
