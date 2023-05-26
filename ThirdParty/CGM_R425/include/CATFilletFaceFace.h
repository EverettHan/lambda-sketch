/* -*-C++-*- */

#ifndef CATFilletFaceFace_H
#define CATFilletFaceFace_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//------------------------------------------------------------------------------
//
// CATFilletFaceFace 
// Definition of a FilletFaceFace operation class 
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Dec. 97    Creation                         J-M.Guillard
//------------------------------------------------------------------------------

#include "Fillet.h"
#include "CATRibAdvInit.h"
#include "CATBody.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATDomain.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATTopRibNupletsNew.h"

struct CATFaceFaceInit;

class CATBody;
class CATShell;
class CATBlendRlm;
class CATRlmMacroTool;
class CATBlendRib;
class CATArrayOfNupletsLists;


class ExportedByFillet CATFilletFaceFace : public CATRibAdvInit
{
 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATFilletFaceFace(double                       iRadius,
		                CATBody                    * iCreationBody,
                    CATSoftwareConfiguration   * iConfig,
		                CATBody                    * iLeftSupport,
		                CATDomain                  * iLeftDom,
		                ListPOfCATFace             * iLeftFaces,
		                CATBody                    * iRightSupport,
		                CATDomain                  * iRightDom,
		                ListPOfCATFace             * iRightFaces,
		                CATCGMJournalList          * iJournal=NULL,
		                CATListOfInt               * iOrientation=NULL,
                    CATBody::CATPropagationTypePr3 iPropagation=CATBody::CATEdgePropagAuto);

  CATCGMNewClassArrayDeclare; // Pool allocation
 
  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------

  virtual ~CATFilletFaceFace ();

  //------------------------------------------------------------------------------
  // Specific Init
  //------------------------------------------------------------------------------
  CATBoolean Init ();

  //------------------------------------------------------------------------------
  // Update (mode multi-ruban or with parting)
  //------------------------------------------------------------------------------
  virtual void Update(CATBody           * iNewInitialBody, 
                      CATDomain* iNewInitialDomain,
                      CATCGMJournalList * iJournal, 
                      CATCellHashTable  * iEdges=NULL,
                      CATCGMJournalList * iJournalOfficiel = NULL);

  //------------------------------------------------------------------------------
  // Update the supports after smart duplication.
  //------------------------------------------------------------------------------
  virtual void UpdateSupports(ListPOfCATBody    * iBodiesBeforeDuplic ,
                              CATBody           * iBodyAfterDuplic    , 
                              ListPOfCATDomain  * iDomainsBeforeDuplic,
		                          ListPOfCATDomain  * iDomainsAfterDuplic );

  //------------------------------------------------------------------------------
  // Specific Run Functions
  //------------------------------------------------------------------------------

  //void ComputeBlendRibbon();
  void CleanInits(int i, CATFaceFaceInit * iListToClean, int iNbElem);
  virtual void CleanAllInits();

  //------------------------------------------------------------------------------
  // Boolean queries 
  //------------------------------------------------------------------------------
  // IsMatching decides if a nuplet matches the specification of the face/facefillet
  virtual CATBoolean IsMatching(CATTopRibNuplet * nuplet,CATEdge ** oEdge=NULL,
                                CATBoolean *iIsotopoSpecOnSupport=NULL);
  CATBoolean IsMatching(CATTopRibNuplet * nuplet,CATTopRibSign iDir);

  //------------------------------------------------------------------------------
  // Liste des faces (ou edges) qui on ete vu dans la recherche d'initialisation.
  // 
  //------------------------------------------------------------------------------
  virtual void GetListOfInitCells (ListPOfCATCell& InitCells);
    //------------------------------------------------------------------------------
  // Get Initial Shell 
  //------------------------------------------------------------------------------
  virtual CATShell * GetInitialShell ();
    
  //------------------------------------------------------------------------------
  // Get Initial Body 
  //------------------------------------------------------------------------------
  virtual CATBody  * GetInitialBody ();

   
  //------------------------------------------------------------------------------
  // recherche de tous les body initiaux
  //------------------------------------------------------------------------------
  virtual void GetAllInitialBodies (ListPOfCATBody &Liste);

  //------------------------------------------------------------------------------
  // Creation des wires correspondant aux traces geometriques en cas d'erreur
  //------------------------------------------------------------------------------
  virtual void CreateWires (ListPOfCATDomain &oCreatedWires);

  //------------------------------------------------------------------------------
  // Indique si les support doivent etre inverses lors de la couture (selon les specs)
  //------------------------------------------------------------------------------
  virtual CATBoolean ShouldBeInvertedForSewing();

  //------------------------------------------------------------------------------
  //In the case of multiple solution, we will chose the continuous and connex one.
  //If the non connex solution is Out In Out In Out, the connex one is Out In Out.
  //The GetBestInitSelection tests if the first Initial solution is connex and 
  //if not it swaps the first solution with the one which is connex. Thus the first
  //solution is always continuous and connex, if possible. 
  //------------------------------------------------------------------------------
  virtual void GetBestInitSelection ();

  //If the IN nuplet from the Init is 'totally' In on both supports, prefer that as first Init.
  virtual void GetBestInitSelectionCx2 ();

  virtual void SwapInitSelection(int Index);
  CATBoolean IsInitConnex(int iIndex);

  //------------------------------------------------------------------------------
  // Positionne Start et End sur un In non degenere
  //------------------------------------------------------------------------------
  virtual void UpdateStartAndEndOfInit (CATBlendRib *iRib);
  
  //------------------------------------------------------------------------------
  // Specific Run Functions
  //------------------------------------------------------------------------------
  virtual CATBoolean ContinuousRibbonSolution(CATBlendRib *Ribon);
  virtual CATBoolean StillValidInitalSolution(int &NuInit);
  virtual CATTopRib * GetNewInitialRibbon(int iNuInit);

  //------------------------------------------------------------------------------
  // Request whether the init allows the multiple sollutions
  //------------------------------------------------------------------------------
  virtual CATBoolean MultipleRibbonsAllowed();

  virtual double GetRadius();

  //------------------------------------------------------------------------------
  // Indique si on peut tenter le remplacement des frontieres (ComplDrop2)
  //------------------------------------------------------------------------------
  CATBoolean CanReplaceFrontier();

 
 protected :
 
  //------------------------------------------------------------------------------
  // Specific Init Utilities
  //------------------------------------------------------------------------------

 void InitLocals (CATBody *iLeftSupport  , CATDomain *iLeftDom, ListPOfCATFace *iLeftFaces, 
                  CATBody *iRightSupport , CATDomain *iRightDom, ListPOfCATFace *iRightFaces,
		  ListPOfCATBody& iSupportBodies, ListPOfCATDomain& SupportDomains, 
		  CATListOfInt *PtrOri);

 void InitsSelection (CATArrayOfNupletsLists &iInitialNupletsListsArray,
                      CATFaceFaceInit *&InitsOK, int &nInits,
                      CATFaceFaceInit *&ListeInits, int &nGeoInits, CATBoolean *oAreConfused=0);
 
 int RibbonAnalysis(ListPOfCATTopRibNuplets &LNuplets,
                    CATFaceFaceInit*& GoodInits, int &nGoodInits);

 void UpdateInits(int                       iIndex,
                  CATArrayOfNupletsLists   &iInitsArray,
                  CATFaceFaceInit        *  iInitsFound  , int  iNbInits,
                  CATFaceFaceInit        * &ioStoredInits, int &ioNbStoredInits,
                  CATFaceFaceInit        * &ioGeoSol     , int &ioNbGeoSol);

 CATBoolean DegenerateInit(ListPOfCATTopRibNuplets &Liste);

 CATBoolean InitStep2 (CATListPV &iListeSupport,
                       int iMaxLimits=0);

 virtual void UpdateLocation(CATBlendRib &iBlendRib);

 //------------------------------------------------------------------------------
 // Specific Run Functions
 //------------------------------------------------------------------------------
 CATBoolean ContinuousRibbonSolution(int NuInit, CATBlendRib *Ribon);

 //------------------------------------------------------------------------------
 //Analyse de redendance entre les solutions fillet trouvees et la solution propagee
 //------------------------------------------------------------------------------
 CATBoolean RedundantInitSolution (CATListPV *Init, CATListPV *DegeneratedNuplets);
 CATBoolean RedundantInitSolution (CATTopRib * iRib, CATListPV *Init, CATListPV *DegeneratedNuplets);

 CATBoolean RedundantInitSolution (int NuSol, CATListPV *Init, int iNbInit, CATFaceFaceInit *InitsList);
 CATBoolean SameGeoNuplets(CATFaceFaceInit& Inits, CATListPV *Init, CATListOfInt& oNuplets);
 CATBoolean SameSupports(CATFaceFaceInit& Inits, CATListPV *Init, CATListOfInt& oNuplets);
 CATBoolean ExoticIdenticalTracks (CATTopRibNuplet *Nuplet, CATTopRibNuplet *newNuplet);
 void GetCommonSupports (CATTopRibNuplet *Nuplet, CATTopRibNuplet *newNuplet,
                         CATListOfInt& NumsOfSupport, CATListOfInt& NumsOfNewSupport);

  //------------------------------------------------------------------------------
  // Remplissage des supports - Rend leur nombre
  //------------------------------------------------------------------------------
  virtual int GetSupports(CATListPV & ioSupports);

  virtual CATBoolean CanIgnoreSharpEdge();

  //------------------------------------------------------------------------------
  // Select Best Init in case of Multi-Edged Spine.
  //------------------------------------------------------------------------------
  virtual CATBoolean PostProcessInits();
  CATBoolean PostProcessInitsWithSpecifiedInitList(CATFaceFaceInit * ioWorkingInitList, int &ioNbInit);

  // pfv pour derivation dans CATBothSidesDraftInit
  virtual CATBoolean StillValidInitalSolutionWithSpecifiedInitList(int &NuInit, 
    CATFaceFaceInit * ioWorkingInitList, int &ioNbInit);
  virtual void UpdateSecondInitList(CATFaceFaceInit * &ioGeoSol, int &ioNbGeoSol, CATFaceFaceInit * iInitsFound, 
    int iNbInits, CATFaceFaceInit * &ioStoredInits, int &ioNbStoredInits, ListPOfCATTopRibNupletsNew& myInit);
  virtual void UpdateCurrentRib();
  void CreateWiresWithSpecifiedInitList(ListPOfCATDomain &oCreatedWires,
                                        CATFaceFaceInit * ioWorkingInitList, int &ioNbInit);



  //------------------------------------------------------------------------------
  // Lecture des cellules a suivre 
  //------------------------------------------------------------------------------
  virtual void GetAllCellsToWatch (ListPOfCATCell &oCellsToWatch, CATBody *iInitialBodyToUse);

  CATBoolean RedundantBasedOnContactSupportType(CATTopRib * iRib, CATTopRibNuplet * iInitNupletToCheck, CATTopRibNuplet * iNupletFromRib);


  //------------------------------------------------------------------------------
 protected:
 CATFilletPaquage * SortListOfNuplets (ListPOfCATTopRibNuplets &iLNuplets, int iStart, int iEnd, 
                                       int& oNumberOfPaquages, int & oNumberOfInPaquages,
                                       int& oLastInPaquage);

 private :
 CATBoolean     UniqueTwistedSolution (ListPOfCATTopRibNuplets &LNuplets, CATFilletPaquage &Paquage , int &ioNewFirst, int &ioNewLast);

 //------------------------------------------------------------------------------
 // Isolate GeoNuplets of this Ribbon 
 //------------------------------------------------------------------------------
 void IsolateGeoNuplet(CATBlendRib* iRib);

  //------------------------------------------------------------------------------
  // Datas
  //------------------------------------------------------------------------------
  
 protected :
  int             _OrientationTuning;     // Indicates if orientations have 
                                          // to be tuned in init
  double          _Radius;
  CATListOfInt    _ListOri;

  ListPOfCATFace  _LeftFaces;
  ListPOfCATFace  _RightFaces;   

  CATDomain       *_LeftDom;              // Input Domains (shells)
  CATDomain       *_RightDom;
  CATBody         *_LeftBody;             // Input Bodies
  CATBody         *_RightBody;

 //private:
  int _nGeoInits;                         // Number of geometrical solutions
  CATFaceFaceInit *_InitsList;            // lists of nuplets inits : 
					  // geometrical valid solutions
  CATFaceFaceInit  *_Inits;               // logical description of Inits 
  int _nInits;                            // Number of intermediate solutions  

//protected:
  CATBody::CATPropagationTypePr3 _Propagation;

 private :
   int             _MaxLimitsMode;

};
#endif
