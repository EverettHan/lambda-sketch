#ifndef CATListOfKeepEdges_h
#define CATListOfKeepEdges_h

// COPYRIGHT DASSAULT SYSTEMES 2002
#include "RibbonLight.h"
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATMathInline.h"

class CATCGMJournalList;

class ExportedByRibbonLight CATListOfKeepEdges
{
public:
  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  CATListOfKeepEdges();

  CATListOfKeepEdges(CATListOfKeepEdges & iToCopy);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATListOfKeepEdges();
  
  //------------------------------------------------------------------------------
  // Various
  //------------------------------------------------------------------------------
  // Read
  INLINE int GetFirstImplicitKeepEdge () const { return _FirstImplicitKeepEdge; }; 
  INLINE int Size() const { return _KeepEdges.Size(); } ; 
  INLINE int Locate(CATEdge * iEdge) const { return _KeepEdges.Locate(iEdge); };

  CATBoolean Check(); // check integrity of the class
  CATEdge *  Read(int iPos, CATBoolean * IsImplicit=NULL,
                            int        * MacroEdgeNumber=NULL);
  // CATBoolean HasKeepEdge(CATEdge * iEdge, CATBoolean * IsImplicit=NULL, int * MacroEdgeNumber=NULL);

  // Returns a copy of the keep edge list - Do not delete this !
  ListPOfCATEdge * GetCopyOfEdgeList();

  // Adds explicit Keep Edge(s) - returns the position of the last edge added
  int AppendExplicit (CATEdge * iExplicitKeepEdge);
  int AppendExplicit (ListPOfCATEdge * iExplicitKeepEdgeList);

  // Adds Implicit Keep Edge(s) - returns the position of the last edge added
  int AppendImplicit (CATEdge * iImplicitKeepEdge);
  // int AppendImplicit (ListPOfCATEdge * iImplicitKeepEdgeList);

  // Removes all implicit edges
  void RemoveAnyImplicit();

  // Replaces - returns the position of the replaced edge
  int Replace (CATEdge * iInitialEdge, CATEdge * iNewEdge, int * iPos=NULL);

  // Tass
  void RemoveNulls();
  // to remove elements of lists
  void CleanUp();

  // Update with a journal
  //void Update(CATCGMJournalList* iJournal);

  //------------------------------------------------------------------------------
  // Private Data
  //------------------------------------------------------------------------------
  private :

    ListPOfCATEdge _KeepEdges; // liste des keep edges
    int            _FirstImplicitKeepEdge; // numero de la premiere keep edge implicite
    int            _LastMacroEdge; // numero de la derniere macro edge
    CATListOfInt   _MacroEdgeNumbers; // numero de macro edge
    ListPOfCATEdge _CopyOfKeepEdges; // copie de la liste des keep edges
};

#endif
