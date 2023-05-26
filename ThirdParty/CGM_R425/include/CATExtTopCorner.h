// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATExtTopCorner :
// Implementation class(enveloppe-lettre extension) for TopCorner operator.
// All Corner implementation class should derive from this class
//
//=============================================================================
// Usage notes:
// classe prive generique pour tous les corners :
//  cette genericite va nous permettre de retraiter tous les probles de trim, de relimitation
// de relimitation de cercle et tutti quanti
// sample of use :
// to provide :
//    classe virtuelle, il faut en deriver
//
//=============================================================================
// November 07     Creation                          JHN
//=============================================================================
#ifndef CATExtTopCorner_H
#define CATExtTopCorner_H

#include "Parallel.h"
#include "CATExtTopMultiResult.h"
#include "CATTopCorner.h"

class CATTopCorner;


//-----------------------------------------------------------------------------
class CATExtTopCorner : public CATExtTopMultiResult
{
public:
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;
 public:

  //
  //  Constructor 
  //

  CATExtTopCorner (CATTopMultiResult *iOperateur);
  virtual ~CATExtTopCorner ();
  virtual void GetAllResults(CATBody **& oResultBodies, CATCGMJournalList**& oResultReports, CATLONG32 & oNbResults);


};
#endif
