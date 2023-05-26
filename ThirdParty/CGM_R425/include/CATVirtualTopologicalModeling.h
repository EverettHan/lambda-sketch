/* -*-C++-*- */

#ifndef CATVirtualTopologicalModeling_H
#define CATVirtualTopologicalModeling_H

// COPYRIGHT DASSAULT SYSTEMES 2000

//===================================================================
//===================================================================
//
// CATVirtualTopologicalModeling
// Classe definissant un shell non encore defini physiquement
// dans le modele
//
//===================================================================

//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June. 00    Creation                         GDR
//===================================================================
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATCGMVirtual.h"

class CATBody;
class CATCGMJournalList;
class CATShell;
class CATFace;
class CATEdge;
class CATVertex;

class ExportedByRIBLight CATVirtualTopologicalModeling : public CATCGMVirtual
{
 
 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATVirtualTopologicalModeling(CATBody           *iCreationBody=0,
                                CATCGMJournalList *iJournal=0); 

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATVirtualTopologicalModeling();

  //------------------------------------------------------------------------------
  // Definition Untwist actif
  //------------------------------------------------------------------------------
  virtual CATBoolean IsUnTwistActive();

  //------------------------------------------------------------------------------
  // Creation de faces supplementaires
  //------------------------------------------------------------------------------
  virtual CATLONG32 CreateFaces(CATFace   *iFace,
                           CATEdge   *iEdge,
                           CATVertex *iVertex);

 protected:
   CATBody           *_CreationBody;     // Container
   CATCGMJournalList *_Journal;          // Report
   CATShell          *_DraftShell;       // Shell cree dans le modele
};
#endif
