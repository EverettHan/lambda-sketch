/* -*-C++-*- */

#ifndef CATMemVertMerger_H
#define CATMemVertMerger_H

// COPYRIGHT DASSAULT SYSTEMES 2001

//=============================================================================
//=============================================================================
//
// CATMemVertMerger : Merger de Vertex a memoire
//
// Classe pour merger des vertex avec verification que l'on ne donne pas en 
// entree de merge un vertex precedemment detruit par un autre merge.
//
//
//=============================================================================

//=============================================================================
//      2000  Creation des methodes ds TopologicalUtilities   P. Rossignol
// Oct  2001  Creation de la classe                           P. Rossignol
//=============================================================================
//=============================================================================

// Pour la def de ExportedByRibbon
#include "RibbonLight.h"


// Includes 
#include "ListPOfCATVertex.h"
#include "CATTopRibDef.h"

// Def 
class CATVertex;
class CATTopologicalOperator;


class ExportedByRibbonLight CATMemVertMerger
{

public :
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATMemVertMerger (CATTopologicalOperator    *iTopOp);
  
  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATMemVertMerger ();
  
  //------------------------------------------------------------------------------
  // Merger de Vertex a memoire
  // Par defaut, on sort en erreur quand on demande de merger un vertex
  // qui a ete efface, mais on peut aussi passer outre et merger avec le
  // vertex qui a remplace le vertex efface (si celui-ci existe, evidemment)
  // Ceci se fait via le iThrow.
  //------------------------------------------------------------------------------
  void Merge(CATVertex               *ioVertex1,
             CATVertex                *iVertex2,
             CATBoolean                iThrow = FALSE,
             int                       iRaz = 0);
  
  //------------------------------------------------------------------------------
  // Get des listes (synchronisees) des vertex old et new
  //------------------------------------------------------------------------------
  ListPOfCATVertex& GetOldVertices();
  ListPOfCATVertex& GetNewVertices();

private:
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  CATTopologicalOperator *_TopOp;
  ListPOfCATVertex        _OldVertices;  // les vertex effaces au cours du merge
  ListPOfCATVertex        _NewVertices;  // leurs remplacants
    
  //------------------------------------------------------------------------------
  // Juste pour eviter que le compilo ne definisse par lui-meme ces operateurs
  //------------------------------------------------------------------------------    
  CATMemVertMerger();
  CATMemVertMerger(CATMemVertMerger& iOperator);
  CATMemVertMerger& operator=(const CATMemVertMerger & iOperator);

};

#endif

