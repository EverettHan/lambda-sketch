/* -*-c++-*- */
#ifndef ListPOfCATTopRibNupletsNew_h
#define ListPOfCATTopRibNupletsNew_h

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
// Nov 2003     Creation                         JMA/ASE
//===================================================================
//===================================================================
#include "RibbonLight.h"
#include "ListPOfCATTopRibNuplets.h"

// Pool allocation
#include "CATCGMNewArray.h"

typedef ListPOfCATTopRibNuplets ListPOfCATTopRibNupletsNew;

/*
class ExportedByRibbonLight ListPOfCATTopRibNupletsNew : public ListPOfCATTopRibNuplets
{
  public:
  // Constructeurs
  ListPOfCATTopRibNupletsNew(int iInitAlloc = 0);
  ListPOfCATTopRibNupletsNew(const ListPOfCATTopRibNupletsNew &iCopy);
  //rearrange the elements in reverse order
  //void Invert();

  // Destructeur
  ~ListPOfCATTopRibNupletsNew();

  // Pool allocation
  CATCGMNewClassArrayDeclare;
};
*/
#endif
