/* -*-C++-*- */
#ifndef CATPrSet_H
#define CATPrSet_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrSet
// Set of CATPrRep, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATCGMVirtual.h"
#include "CATCGMNewArray.h"
#include "CATMathInline.h"
#include "CATPrRep.h"
#include "CATListOfInt.h"
#include "ListPOfCATPrRep.h"
#include "ListPOfCATPrSet.h"
#include "ListPOfCATPrPattern.h"
#include "ListPOfCATPrSetRepList.h"
#include "ListPOfCATFace.h"
#include "AdvOpeInfra.h"
#include "CATSafe.h"
CATSafeDefine(CATPrSet);       
class CATMathTransformation;
class CATPrContext;
class CATTextStampCGM;
class CATUnicodeString;
class CATCGMOutput;

class ExportedByAdvOpeInfra CATPrSet : public CATCGMVirtual
{
public:
  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  CATPrSet(CATPrContext& iContext, CATPrRep* &ioRep1, CATPrRep* &ioRep2);
  CATPrSet(CATPrContext& iContext, CATPrRep* &ioRep1);
  CATPrSet(CATPrContext& iContext);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATPrSet();

  //------------------------------------------------------------------------------
  // Build the PrSet (Reps may be absorbed)
  //------------------------------------------------------------------------------
  static void CreateSets(CATPrContext& iContext, CATLISTP(CATPrRep) &ioReps, const ListPOfCATFace* iSelected, CATLISTP(CATPrSet) &oSets);

  //------------------------------------------------------------------------------
  // Recognize All BRep Copies from Sets
  //------------------------------------------------------------------------------
  static void RecognizeAllCopies(CATPrContext& iContext, ListPOfCATPrSet& iSets, ListPOfCATPrSet& oBRepCopies);

  //------------------------------------------------------------------------------
  // Recognize only BRepCopies of
  //------------------------------------------------------------------------------
  static void RecognizeOnlyCopiesOf(CATPrContext& iContext, ListPOfCATPrSet& iSets, CATLISTP(CATFace)& iSelectedCopyOf, ListPOfCATPrSet& oBRepCopies);

  //------------------------------------------------------------------------------
  // Catalyze (identify basic patterns)
  //------------------------------------------------------------------------------
  void RecognizePattern(CATPrPattern& iCatalyzer, ListPOfCATPrPattern& ioFoundPatterns);

  //------------------------------------------------------------------------------
  // Returns Rep[i] 1<=i<=GetRepCount
  //------------------------------------------------------------------------------
  INLINE CATPrRep*& operator [] (const int iRepIndex) { return _Reps[iRepIndex]; };
  INLINE int Size() const { return _Reps.Size(); };

  //------------------------------------------------------------------------------
  // GetContext
  //------------------------------------------------------------------------------
  INLINE CATPrContext& GetContext() const { return _Context; };

  //------------------------------------------------------------------------------
  // Check whether this is empty
  //------------------------------------------------------------------------------
  CATBoolean IsEmpty() const;

  //------------------------------------------------------------------------------
  // Grow with ioReps if they are isometric
  //------------------------------------------------------------------------------
 virtual CATBoolean Grow(CATLISTP(CATPrRep) &ioReps, const int iStartIndex);

  //------------------------------------------------------------------------------
  // Export to (empty) iSet this' Reps
  //------------------------------------------------------------------------------
  void ExportTo(CATPrSet& iSet, ListPOfCATPrRep& ioNewReps);

  //------------------------------------------------------------------------------
  // Get the Translation between Rep1 & Rep2 if it exists else returned transformation is an isometry
  //------------------------------------------------------------------------------
  CATBoolean GetTranslation(const int iRepIndex1, const int iRepIndex2, CATMathTransformation &oTransfoFrom1To2);

  //------------------------------------------------------------------------------
  // Get the Relation between Rep1 & Rep2
  //------------------------------------------------------------------------------
  virtual void GetIsometry(const int iRepIndex1, const int iRepIndex2, CATMathTransformation &oTransfoFrom1To2);

  //==============================================================================
  // Debug
  //==============================================================================
  virtual void Display(const CATBoolean iClearCreatedObjectsAtDelete = TRUE);
  void GetObjectsToSave(CATLISTP(CATGeometry)& ioObjectsToSave);

  //------------------------------------------------------------------------------
  // Create a Line or a sphere for Debug purpose
  //------------------------------------------------------------------------------
  CATGeometry* CreateLine  (const CATMathPoint& iP1, const CATMathPoint& iP2, const int iR, const int iG, const int iB, CATTextStampCGM* iTextStamp=NULL); 
  CATGeometry* CreateSphere(const CATMathPoint& iC, const CATPositiveLength iRadius, const int iR, const int iG, const int iB, CATTextStampCGM* iTextStamp=NULL); 

  //------------------------------------------------------------------------------
  // returns class name
  //------------------------------------------------------------------------------
  virtual void GetClassName(CATUnicodeString& oClassName) const;

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  virtual void Dump(CATCGMOutput& ioOS);
  friend CATCGMOutput& operator << (CATCGMOutput& s, const CATPrSet & iSet);

  //------------------------------------------------------------------------------
  // Get Tag (debug only)
  //------------------------------------------------------------------------------
  INLINE int GetTag() const { return _Tag; };
  static void Reset();

  //------------------------------------------------------------------------------
  // Check
  //------------------------------------------------------------------------------
  virtual void Check();

  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  // Protected section
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
protected:

  //------------------------------------------------------------------------------
  // Delete & Remove from list NULL or Empty Sets
  //------------------------------------------------------------------------------
  static void DeleteEmpty(ListPOfCATPrSet& ioSets);

  //------------------------------------------------------------------------------
  // Absorb a Rep at index (ioRep is set to NULL), if Rep already exists, ioRep is inserted
  // Be careful: if this is a CATPrSet, ioRep->_TransfoThisVsRef must be set before absortion
  //------------------------------------------------------------------------------
  CATBoolean AbsorbRep(const int iIndex, CATPrRep*& ioRep);
 
  //------------------------------------------------------------------------------
  // Grow with ioReps 
  //------------------------------------------------------------------------------
  static void AbsorbReps(CATPrContext& iContext, ListPOfCATPrSet& ioSets1, ListPOfCATPrSet& ioSets2, ListPOfCATPrRep &ioReps);

  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  // Private section
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
private:

  //------------------------------------------------------------------------------
  // Sort Reps according to increasing distance with Reference Rep
  //------------------------------------------------------------------------------
  void SortByDistanceToARep(const int iRefRepIndex, CATListOfInt &oOrderedRepIndexes);

  //------------------------------------------------------------------------------
  // Sort Reps according to distance to first Rep
  //------------------------------------------------------------------------------
  void SortByDistanceToFirst();

  //------------------------------------------------------------------------------
  // Sort Reps according to density & distance to origin
  //------------------------------------------------------------------------------
  void SortByDensityAndDistanceToOrigin(CATListOfInt &oOrderedRepIndexes);

  //------------------------------------------------------------------------------
  // Sort Sets 
  //------------------------------------------------------------------------------
  static int CompareSizeAndRepComplexity(CATPrSet* iSet1, CATPrSet* iSet2);

  //------------------------------------------------------------------------------
  // Build the PrSet
  //------------------------------------------------------------------------------
  static CATPrSet* Create(CATPrContext& iContext, CATPrRep* &ioRep1, CATLISTP(CATPrRep) &ioReps, int& ioStartIndex); // Returns StartIndex for Growing

  //------------------------------------------------------------------------------
  // Create a new set containing Reps, one for every SetRepList, absorbed by this Rep (ioBRepCopies are deleted)
  //------------------------------------------------------------------------------
  static CATPrSet* Create(CATPrContext& iContext, ListPOfCATPrSetRepList& ioBRepCopies, ListPOfCATPrRep& ioRejectedReps);

  //------------------------------------------------------------------------------
  // Catalyze this PrSet with other adjacent sets (>=iFirstSetIndex): wherever similar shape exist, grow Rep shape 
  //------------------------------------------------------------------------------
  void Catalyze(ListPOfCATPrSet& iSets, ListPOfCATPrSet& ioBRepCopies);

  //------------------------------------------------------------------------------
  // Catalyze start: 2 Reps are grown
  //------------------------------------------------------------------------------
  CATBoolean GrowShape(CATMathTransformation& iTransfoFromRep1ToRep2, ListPOfCATPrSet& iSets, CATPrSetRepList& ioRep1List, CATPrSetRepList& ioRep2List);

  //------------------------------------------------------------------------------
  // Grow this set: find as much as possible isometric reps
  //------------------------------------------------------------------------------
  void GrowNetwork(ListPOfCATPrSet& iSets, ListPOfCATPrSetRepList& ioBRepCopies);
  int Locate(ListPOfCATPrSetRepList& iBRepCopies, const int iSet, const int iRep);

  //------------------------------------------------------------------------------
  // Move Reps sharing faces with iSelected to the beginning of the ioReps list
  //------------------------------------------------------------------------------
  static int MoveSelectedRepFirst(const ListPOfCATFace& iSelected, CATLISTP(CATPrRep) &ioReps);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
private:
  int                   _Tag;
  int                   _Dumped;        // to index dump files on disk
  int                   _DumpSignature; // To dump file on disk only when set actually changed
  CATPrContext&         _Context;
  CATLISTP(CATPrRep)    _Reps;
  CATLISTP(CATGeometry) _CreatedObjects;

};
//------------------------------------------------------------------------------

#endif
