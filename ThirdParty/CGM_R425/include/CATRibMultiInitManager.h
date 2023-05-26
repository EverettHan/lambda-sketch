/* -*-C++-*- */

#ifndef CATRibMultiInitManager_H
#define CATRibMultiInitManager_H

// COPYRIGHT DASSAULT SYSTEMES 1998

//------------------------------------------------------------------------------
//
// CATRibMultiInitManager
// Definition of a class that permits the management of multiple inits for
// a ribbon
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Sept. 1998    Creation                         A. State
//------------------------------------------------------------------------------

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATMathDef.h"
#include "CATTopRibDef.h"
#include "CATArrayOfNupletsLists.h"

class CATTopRib;

#include "CATListOfInt.h"
#include "ListPOfCATTopRibNuplets.h"
#include "CATCGMVirtual.h"


class ExportedByRIBLight CATRibMultiInitManager  : public CATCGMVirtual
{
  protected :

  CATTopRib              *_OwnerRibbon;
  CATListPV              *_OtherRibbons;
  CATBoolean              _OwnerRibbonChecked;
  CATListOfInt            _OtherRibbonsChecked;
  CATLONG32               _IndexOfUsedList;
  CATListOfInt           *_FirstNupletIn;
  CATListOfInt           *_LastNupletIn;
  CATArrayOfNupletsLists  _InitialNupletsListsArray;
  CATBoolean              _DoNotClean;
  CATBoolean              _CheckOnlyUsefulRibbonPart;

  public:

  //------------------------------------------------------------------------------
  // Constructor with data
  //
  // Please note: iOtherRibbons may be a NULL pointer
  //------------------------------------------------------------------------------

  CATRibMultiInitManager (CATTopRib              *iOwnerRibbon,
                          CATListPV              *iOtherRibbons,
                          CATLONG32               iIndexOfUsedList,
                          CATListOfInt           *iFirstNupletIn,
                          CATListOfInt           *iLastNupletIn,
                          CATArrayOfNupletsLists &iInitialNupletsListsArray);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------

  ~CATRibMultiInitManager ();

  //------------------------------------------------------------------------------
  // Copy constructor. Not implemented
  //------------------------------------------------------------------------------
  private :
  CATRibMultiInitManager(CATRibMultiInitManager &iOperator);

  //------------------------------------------------------------------------------
  // Affectation operator. Not implemented
  //------------------------------------------------------------------------------
  private :
  CATRibMultiInitManager& operator=(const CATRibMultiInitManager &iOperator);

  //D1A: Start: IR-212024 : 17-May-2013
  //-----------------------------------------------------------------------------
  private :
  CATBoolean _UseConfusedNuplets;
  //-----------------------------------------------------------------------------
  //D1A: End: IR-212024 : 17-May-2013


  //------------------------------------------------------------------------------
  // Check that the ribbon contains all the initializing N-uplets and
  // destroy them
  // Returns TRUE if all lists of N-uplets are redundant with the stored Ribbons
  //------------------------------------------------------------------------------
  public:
  CATBoolean CheckAndCleanInits (CATBoolean iDestroyNonRedundantInits = CATBoolean(1),
                                 CATBoolean iDestroyRedundantInits    = CATBoolean(1));

  //D1A: Start: IR-212024 : 17-May-2013
  //------------------------------------------------------------------------------
  // Method to set UseConfusedNuplet for CATDraftReflect case
  //------------------------------------------------------------------------------
  void UseConfusedNuplets (CATBoolean iUseConfusedNuplets = CATBoolean(0));
  //D1A: End: IR-212024 : 17-May-2013


  //------------------------------------------------------------------------------
  // Appends a new rib in OtherRibs
  //------------------------------------------------------------------------------

  void AppendNewRib (CATTopRib * NewRib);

  //------------------------------------------------------------------------------
  //  Set Nuplets to check 
  //------------------------------------------------------------------------------

  void SetNupletsToCheck(CATLONG32               iIndexOfUsedList,
                         CATListOfInt           *iFirstNupletIn,
                         CATListOfInt           *iLastNupletIn,
                         CATArrayOfNupletsLists &iInitialNupletsListsArray);
 
  //------------------------------------------------------------------------------
  // Reset the "Check" status
  //------------------------------------------------------------------------------

  void ResetCheckStatus(CATTopRib *iRib = NULL);

  //------------------------------------------------------------------------------
  // Get / Set _DoNotClean
  //------------------------------------------------------------------------------

  void SetDoNotClean (CATBoolean iDoNotClean);
  CATBoolean GetDoNotClean ();

  //------------------------------------------------------------------------------
  // Gives the index of the first non empty list of Initial Nuplets
  //------------------------------------------------------------------------------

  int GetNextNonRedundantSolution ();

  //------------------------------------------------------------------------------
  // Empties the list of nuplets without distroying the N-uplets
  //------------------------------------------------------------------------------

  void EmptyInitialList (int iNuInit);

  //------------------------------------------------------------------------------
  // Gives the list and the descriptive indexes of the initial solution
  //------------------------------------------------------------------------------

  ListPOfCATTopRibNuplets * GetListOfInits( int iNuInit, int *oFirstIn=NULL, int *oLastIn=NULL);

  //------------------------------------------------------------------------------
  // Set other possible solutions for a given ribbon (in order to allow
  // for propagation on same supports)
  //------------------------------------------------------------------------------

  void SetLastSolNupletOnRibbon(CATTopRib *iRib,
                                int        iNuInitUsedForRib);

  //------------------------------------------------------------------------------
  // Checks redundant ribs only between startofrib and endofrib
  //------------------------------------------------------------------------------
  void SetCheckOnlyUsefulRibbonPart(CATBoolean iCheckOnlyUsefulRibbonPart);

  CATTopRib  * GetOwnerRibbon() { return _OwnerRibbon; }
  void SetOwnerRibbon(CATTopRib  * iOwnerRibbon) { _OwnerRibbon = iOwnerRibbon; }

  protected : 

  //------------------------------------------------------------------------------
  // Destroy redundant inits
  //------------------------------------------------------------------------------

  void DestroyRedundantInits (CATListOfInt           &iRedundantInits,
                              CATArrayOfNupletsLists &iInitialNupletsListsArray);

  //------------------------------------------------------------------------------
  // Clean up
  //------------------------------------------------------------------------------

  void CleanUp ();

};
#endif
