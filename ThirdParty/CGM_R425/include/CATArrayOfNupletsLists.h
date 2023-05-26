/* -*-C++-*- */

#ifndef CATArrayOfNupletsLists_H
#define CATArrayOfNupletsLists_H


// COPYRIGHT DASSAULT SYSTEMES 2003

//===================================================================
//===================================================================
//
// CATArrayOfNupletsLists
//
// Array of n lists of CATTopRibNuplet pointers
//
//===================================================================

//===================================================================
// Nov 2003     Creation                         ASE
//===================================================================
//===================================================================
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibObject.h"

#include "ListPOfCATTopRibNupletsNew.h"
#include "CATCGMNewArray.h"


class ExportedByRIBLight CATArrayOfNupletsLists : public CATTopRibObject
{
  public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATArrayOfNupletsLists();

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATArrayOfNupletsLists();

  //------------------------------------------------------------------------------
  // Clean up array
  //
  // Please note: iCheck is optional and checks whether all lists, except for
  //              the one located at iIndexOfListToKeep, are empty.
  //              If they aren't the method fails.
  //------------------------------------------------------------------------------
  void Clean(CATBoolean iCheck             = FALSE,
             int        iIndexOfListToKeep = 0);

  //------------------------------------------------------------------------------
  // Clean up N-uplets
  //
  // Please note: 1) The optional argument iIndexOfListToKeep identifies the index
  //                 of a list of N-uplets that mustn't be destroyed (a valid index
  //                 >= 1 and <= _NbLists)
  //              2) if iDownsize == TRUE, _NbLists is set to 0 (but the array
  //                 allocation remains active (this works only if iIndexOfListToKeep is 0)
  //------------------------------------------------------------------------------
  void CleanNuplets(int        iIndexOfListToKeep = 0,
                    CATBoolean iDownsize          = FALSE);

  //------------------------------------------------------------------------------
  // Allocate memory for additional lists
  //------------------------------------------------------------------------------
  void AppendSize(int iNbAdditionalLists);

  //------------------------------------------------------------------------------
  // Add next (empty) list to the used lists, i.e. increment the list size by 1
  //------------------------------------------------------------------------------
  void AddNextList();

  //------------------------------------------------------------------------------
  // Get the last list of N-uplets
  //------------------------------------------------------------------------------
  ListPOfCATTopRibNupletsNew *GetLastListPtr();

  //------------------------------------------------------------------------------
  // Get a list of N-uplets (Index >= 1 && Index <= _NbLists <= _ArraySize)
  //------------------------------------------------------------------------------
  ListPOfCATTopRibNupletsNew *GetListPtr(int iIndex);

  //------------------------------------------------------------------------------
  // Get the last list of N-uplets
  //------------------------------------------------------------------------------
  ListPOfCATTopRibNupletsNew &GetLastList();

  //------------------------------------------------------------------------------
  // Get a list of N-uplets (Index >= 1 && Index <= _NbLists <= _ArraySize)
  //------------------------------------------------------------------------------
  ListPOfCATTopRibNupletsNew &GetList(int iIndex);

  //------------------------------------------------------------------------------
  // Get the number of lists that are used
  //------------------------------------------------------------------------------
  int GetNbLists();

  //------------------------------------------------------------------------------
  // Append N-uplets lists from another array
  //------------------------------------------------------------------------------
  void AppendNupletsLists(CATArrayOfNupletsLists &iNupletsListsArray,
                          int                     iIndexFirstListToAppend,
                          int                     iNbListsToAppend,
                          CATBoolean              iEmptyLists = FALSE);

  //------------------------------------------------------------------------------
  // Replace N-uplets lists with all the lists from another array, starting
  // at a given index in the current array
  //
  // Please note: The method does NOT check whether any N-uplets are lost in
  //              the operation, i.e. the caller is responsible for any N-uplets
  //              that were taken out of the lists
  //------------------------------------------------------------------------------
  void ReplaceNupletsLists(int                     iIndexFirstListToReplace,
                           CATArrayOfNupletsLists &iNupletsListsArray);

  //------------------------------------------------------------------------------
  // Check if array is empty
  //------------------------------------------------------------------------------
  CATBoolean IsEmpty();

  //------------------------------------------------------------------------------
  // Take the data from another array and leave it empty
  //
  // USE WITH EXTREME CAUTION!!!!
  //------------------------------------------------------------------------------
  void StealData(CATArrayOfNupletsLists &iNupletsListsArray);

  //------------------------------------------------------------------------------
  // Checks whether the current array allocation is identical with another
  //------------------------------------------------------------------------------
  CATBoolean IsArrayAllocationIdentical(CATArrayOfNupletsLists &iNupletsListsArray);

  //------------------------------------------------------------------------------
  // Checks whether the current array allocation is free
  //------------------------------------------------------------------------------
  CATBoolean IsFree();

  //------------------------------------------------------------------------------
  // Get the size of a specific list of N-uplets
  //------------------------------------------------------------------------------
  int GetNbNupletsInList(int iIndex);

  //------------------------------------------------------------------------------
  // Get the N-uplet located in a given list at a given location
  //------------------------------------------------------------------------------
  CATTopRibNuplet *GetNupletInList(int iListIndex,
                                   int iNupletIndex);

  //------------------------------------------------------------------------------
  // Replace one N-uplets lists with another one
  //------------------------------------------------------------------------------
  void ReplaceNupletsLists(int                         iIndexListToReplace,
                           ListPOfCATTopRibNupletsNew &iNupletsLists);

  //------------------------------------------------------------------------------
  // Downsize the array, i.e. set the number of lists to iNbLists
  //
  // Please note: 1) _NbLists is set to 0 (but the array allocation
  //                 remains active)
  //              2) If there are any lists beyond iNbLists that aren't
  //                 empty, the method will fail
  //------------------------------------------------------------------------------
  void Downsize(int iNbLists);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  int                         _NbLists;
  int                         _ArraySize;
  ListPOfCATTopRibNupletsNew *_NupletLists;
};
#endif

