/* -*-C++-*- */

#ifndef CATRibInit_H
#define CATRibInit_H

// COPYRIGHT DASSAULT SYSTEMES 1998

//------------------------------------------------------------------------------
//
// CATRibInit
// Definition of a topological blend
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// March. 98    Creation                         J-M.Guillard
//------------------------------------------------------------------------------

#include "RibbonLight.h"
#include "CATTopRibObject.h"
#include "ListPOfCATTopRibs.h"
#include "CATCellHashTable.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATTopRibNuplets.h"
#include "ListPOfCATRibInit.h"
#include "CATMathDef.h"
#include "CATTopRibDef.h"
#include "CATListOfKeepEdges.h"
#include "CATBody.h"
#include "CATMathInline.h"



class CATShell;
class CATTopRib;
class CATEdgeRibbon;
class CATEdge;
class CATSupContact;
class CATCrvParam;
class CATPCurve;
class CATTopRibNuplet;
class CATCGMJournalList;
class CATSoftwareConfiguration;
class CATTopRibMacroTool;
class CATRibTopOp;
class CATParting;
class CATBlendParams;
class CATSoftwareConfiguration;

typedef struct CATFilletPaquage {
  int first;
  int last;
  int firstIn;
  int lastIn;
  int firstConfused;
  int lastConfused;
  int ok;
} CATFilletPaquage;

#include "CATSafe.h"
CATSafeDefine(CATRibInit);

class ExportedByRibbonLight CATRibInit : public CATTopRibObject
{
  public:

    //------------------------------------------------------------------------------
    // Constructor
    //------------------------------------------------------------------------------
    CATRibInit(CATCGMJournalList * iJournal, CATBody * iCreationBody, CATSoftwareConfiguration * iSoftwareConfiguration=NULL);

    //------------------------------------------------------------------------------
    // Destructor
    //------------------------------------------------------------------------------
    virtual ~CATRibInit();

    INLINE  CATGeoFactory      *GetFactory      () const;
    //------------------------------------------------------------------------------
    // Specify the topological operator
    //------------------------------------------------------------------------------
    INLINE void          SetRibTopOp(CATRibTopOp *iOperateur);
    INLINE CATRibTopOp * GetRibTopOp();

    //------------------------------------------------------------------------------
    // Read the results of run
    //------------------------------------------------------------------------------
    virtual CATTopRib          * GetRib(int i=1);
    virtual CATTopRib          * GetNextRib();
    virtual CATTopRib          * GetNewInitialRibbon(int iNuInit);
    int                          LocateRib (CATTopRib *iRib);
    void                         RemoveRib (CATTopRib *iRib);


    //------------------------------------------------------------------------------
    // Spec skin
    //------------------------------------------------------------------------------
    //void SetSkinMode(CATTopRibPropagation iMode=PropagStandard);
    virtual void SetSkinOptions (CATBlendParams& iparams);
    virtual CATBlendParams * GetSkinOptions ();
    INLINE CATBoolean GetSkinMode ();

    //------------------------------------------------------------------------------
    // Read SoftwareConfiguration
    //------------------------------------------------------------------------------
    CATSoftwareConfiguration* GetSoftwareConfiguration();

    //------------------------------------------------------------------------------
    // Run method
    //------------------------------------------------------------------------------
    virtual CATBoolean   Run ();
    CATBoolean           Done();
    void                 SetDone(CATBoolean iDone=TRUE);
    //------------------------------------------------------------------------------
    // Init method
    //------------------------------------------------------------------------------
    virtual CATBoolean Init () = 0;

    //------------------------------------------------------------------------------
    // Cleans shells before body is completed
    //------------------------------------------------------------------------------
    virtual void CleanUp();

    virtual void RestoreSpecificContent(CATCGMJournalList * iEdgesJournal=NULL);

    //------------------------------------------------------------------------------
    // Mise a jour apres passage d'un ruban anterieur
    //------------------------------------------------------------------------------
    virtual void Update(CATBody * iNewInitialBody,
                        CATDomain* iNewInitialDomain,
                        CATCGMJournalList * iJournal,
                        CATCellHashTable * iEdges=NULL,
                        CATCGMJournalList * iJournalOfficiel = NULL);

    virtual void Update(CATCGMJournalList * iJournal);


    virtual void UpdateWkBody (CATBody *iBody);

    virtual void UpdateWithNewBody (CATBody& iOldBody, CATBody& iNewBody, CATCellHashTable& iNewBodyAllEdges,
                                    CATCGMJournalList * iOldJournal=NULL, CATCGMJournalList * iNewJournal=NULL,
                                    CATCGMJournalList * iEdgesJournal=NULL);
    virtual void UpdateInputBody (CATBody *iBody);

    //------------------------------------------------------------------------------
    // Update the supports after smart duplication. Must be overloaded
    //------------------------------------------------------------------------------
    virtual void UpdateSupports(ListPOfCATBody    * iBodiesBeforeDuplic ,
                                CATBody           * iBodyAfterDuplic    ,
                                ListPOfCATDomain  * iDomainsBeforeDuplic,
                                ListPOfCATDomain  * iDomainsAfterDuplic );

    //------------------------------------------------------------------------------
    // Get/Set the EdgeFilletRibbon
    //------------------------------------------------------------------------------
    virtual CATEdgeRibbon * GetRibbon();
    virtual void    SetRibbon(CATEdgeRibbon * iRib);

    //------------------------------------------------------------------------------
    // Verifie si le nuplet correspond aux spec de l operation.
    //------------------------------------------------------------------------------
    virtual CATBoolean IsMatching (CATTopRibNuplet *iNuplet, CATEdge ** oEdge=NULL,
                                   CATBoolean *iIsotopoSpecOnSupport=NULL);
    virtual CATBoolean IsMatching (CATTopRibNuplet *iNuplet,CATTopRibSign iDir);


    //------------------------------------------------------------------------------
    // Verifie si un ruban dans une direction couvre la spec de l operation. Repond
    // UnknownRibbonType par defaut.
    //
    // Les valeurs de retour possibles sont:
    //
    // - UnknownRibbonType si on ne sait pas si la spec est couverte
    // - EndedType si la spec est couverte dans la direction demandee
    // - NotEndedType si la spec n'est pas couvertes dans la direction demandee
    //------------------------------------------------------------------------------
    virtual CATTopRibType IsCovered(CATTopRibSign   iDirection,
                                    CATTopRib     * iRib      );

    //------------------------------------------------------------------------------
    // Recuperation de la liste des keep edges
    //------------------------------------------------------------------------------
    virtual CATListOfKeepEdges * GetKeepEdges();

    //------------------------------------------------------------------------------
    // Mode "keep edges implicite" ?
    //------------------------------------------------------------------------------
    virtual CATBoolean ImplicitKeepEdgesMode();
    virtual CATBoolean IsImplicitKeepInitialisationDone();
    //------------------------------------------------------------------------------
    // Mode "every keep edge convexity" ?
    //------------------------------------------------------------------------------
    virtual CATBoolean EveryKeepEdgeConvexityMode();

    //------------------------------------------------------------------------------
    // Une cellule fait-elle partie des cellules d'init deja rencontrees du ruban ?
    // return :  1 is an init cell
    //          -1 is not an init cell
    //           0 unknown
    // Cette methode rend toujours 0, seules les derivations peuvent connaitre le resultat
    //------------------------------------------------------------------------------
    virtual int IsInitCell(CATCell * iCell);

    virtual CATBoolean IsCoveredBumper (CATCell * iCell, CATCell * iBumper);
    //------------------------------------------------------------------------------
    // Liste des faces (ou edges) qui on ete vu dans la recherche d'initialisation.
    // Pour fillet edge on y ajoute toutes les faces adjacentes a la superarete.
    // Cette methode rend la liste non modifiee, seules les derivations peuvent connaitre le resultat
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
    // Set Parting Element
    //------------------------------------------------------------------------------
    virtual void SetParting (CATParting * iParting);

    //------------------------------------------------------------------------------
    // Update Parting Element
    //------------------------------------------------------------------------------
    virtual void UpdateParting (CATParting * iParting);
    //------------------------------------------------------------------------------
    // IsEmptyBecauseOfParting
    // -----------------------------------------------------------------------------
    virtual CATBoolean IsEmptyBecauseOfParting();
    //------------------------------------------------------------------------------
    // IsEmptyBecauseOfParting
    // -----------------------------------------------------------------------------
    CATBoolean IsEmpty();

    //------------------------------------------------------------------------------
    // Lecture des edges a suivre
    //------------------------------------------------------------------------------
    virtual void GetAllCellsToWatch (ListPOfCATCell &oCellsToWatch, CATBody *iInitialBodyToUse);

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
    // Request whether the init allows the multiple sollutions
    //------------------------------------------------------------------------------
    virtual CATBoolean MultipleRibbonsAllowed();

    //------------------------------------------------------------------------------
    // List of remove cells.
    //------------------------------------------------------------------------------
    virtual void GetListOfRemoveCells (ListPOfCATCell& RemoveCells);

    virtual CATBoolean CanIgnoreSharpEdge();

    virtual double GetRadius();

    virtual CATBoolean IsSpineCriticalForInit() const {return FALSE;}

    //------------------------------------------------------------------------------
    // Recuperation des bodies initiaux avant updates eventuelles
    //------------------------------------------------------------------------------
    void GetOriginalBodies(ListPOfCATBody &oOriginalBodies);

    //------------------------------------------------------------------------------
    // Indique si on peut tenter le remplacement des frontieres (ComplDrop2)
    //------------------------------------------------------------------------------
    virtual CATBoolean CanReplaceFrontier();


    //------------------------------------------------------------------------------
    //
    //------------------------------------------------------------------------------
    void AddPrerequisite( CATRibInit * iRibInit );
    int GetNbOfPreq() const;
    CATRibInit * GetPrerequisite( const int i ) const;

  protected:
    //------------------------------------------------------------------------------
    // Ordonner la liste des nuplets en paquets correspondant aux solutions possibles
    //------------------------------------------------------------------------------
    virtual CATFilletPaquage * SortListOfNuplets (ListPOfCATTopRibNuplets &iLNuplets, int iStart, int iEnd, int& oNumberOfPaquages,
                                                  int & oNumberOfInPaquages, int& oLastInPaquge);

    void SetOriginalBodies(ListPOfCATBody &iOriginalBodies);
    void AppendOriginalBody(CATBody * iOriginalBody);

    //pfv 22.01.2004
  public:
    virtual void Isolate (CATBoolean iOperationIsOK=FALSE);
    // pfv 25.03.2004
    virtual int GetNumberOfLimitingElements();
    virtual void GetLimitingElement(int iNumber, double iShift, CATBody *& oLimitingElement,
                                    CATOrientation &oOrientation, CATCGMJournalList *ioJournal,
                                    ListPOfCATBody *iLim = NULL, CATListOfInt *iDirs = NULL, double* oGapFillData = NULL);
    //BQJ: 08:11:21
    virtual CATBoolean GetFirstAndLastTwisted();

  protected:

    //------------------------------------------------------------------------------
    // Data
    //------------------------------------------------------------------------------

    CATRibTopOp        * _RibTopOp;
    CATTopRib          * _CurrentRib;
    CATBody            * _CreationBody;
    CATTopRibMacroTool * _MTool;
    CATCGMJournalList  * _Journal;
    CATTopRibPropagation _Mode;
    CATBoolean           _SkinMode;
    CATSoftwareConfiguration * _Config;

    int _NumberOfUsedRibbons;
    ListPOfCATTopRibs    _Rib;

    CATParting         * _Parting;
    CATBoolean           _InitDone;
  private :
    virtual CATBoolean   StillValidInitalSolution(int &NuInit);
  public :
    virtual void UpdateIsoTopoSpecmatchings (CATTopRib * iRib);

  private:
    ListPOfCATBody       _OriginalBodies;

    ListPOfCATRibInit    _Prerequisites;
};


// --------------------------------------------------------------
// INLINE methods
// --------------------------------------------------------------
INLINE CATGeoFactory * CATRibInit::GetFactory()      const { ThrowIfNull(_CreationBody) ; return _CreationBody ? _CreationBody->GetFactory() : NULL ; } ;

INLINE                 CATBoolean CATRibInit::GetSkinMode () { return _SkinMode; };

INLINE void            CATRibInit::SetRibTopOp(CATRibTopOp *iOperateur) { _RibTopOp = iOperateur; };

INLINE CATRibTopOp *   CATRibInit::GetRibTopOp() { return _RibTopOp; };

#endif
