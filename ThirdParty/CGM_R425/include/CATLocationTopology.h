
/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
// CATLocationTopolgy:
//=============================================================================
// WARNING: DO NOT USE
//=============================================================================
// HISTORIC
// Jul.  99 LMH Creation                                                L. Mahe
// 20/03/00 ALM Gestion des wires avec edges degenerees dans les wires, quand 
//              cela est demande par l'appelant
// 09/11/15 NLD Suppression du vieux constructeur sans TopData
//=============================================================================

//============================================================================= 
// ALGO OPTIONS
//============================================================================= 

//============================================================================= 
// DEFINES
#ifndef CATLocationTopology_h
#define CATLocationTopology_h

#include "AnalysisToolsLight.h"
#include "CATTopDef.h"
#include "CATHybDef.h"
#include "CATListOfCATSurfaces.h"
#include "CATListOfCATCurves.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATDomain.h"
#include "CATTopOperator.h"
//============================================================================= 
// #define CATLocationTopology_CGMReplayBasis "EN COURS NLD091115. NON NECESSAIRE pour CATLocationWireOnShell"

//-----------------------------------------------------------------------------
class ExportedByAnalysisToolsLight CATLocationTopology : public CATTopOperator
{
  public :
    //-------------------------------------------------------------------------
    // Destructor
    //-------------------------------------------------------------------------
    ~CATLocationTopology();
    
    //-------------------------------------------------------------------------
    // Result Access
    //-------------------------------------------------------------------------
    CATVertex * Next     ( CATVertex * iVertex      = NULL ); // Returns Vertex Operande
    void        GetResult( CATCell  ** oCellSupport );        // For LocationVertexOn...


  protected :
    //-------------------------------------------------------------------------
    // Constructor
    //-------------------------------------------------------------------------
    CATLocationTopology(       CATGeoFactory    * iFactory                    ,
                               CATTopData       * iTopData                    ,
                         const CATBody          * iBodyOperande               ,
                               CATDomain        * iOperande                   ,
                         const CATBody          * iBodySupport                ,
                               CATDomain        * iSupport                    ,
                               CATLONG32          iDegeneratedEdgesManagement = 0);

    // Protected Data
    CATGeoFactory          * _Fac;
    CATTopData               _TopData ;
    CATBody                * _BodyOperande;
    CATDomain              * _Operande;
    CATWire                * _Wire;
    CATVertex              * _Vx;
    CATBody                * _BodySupport;
    CATDomain              * _Support;
    CATCell                * _CellSupport;
    CATLISTP(CATSurface)     _ListFonds;
    CATLISTP(CATCurve)       _ListECrvs;
    CATLISTP(CATCell)        _SupportVertices;
    CATLISTP(CATCell)        _SupportEdges;
    CATLISTP(CATCell)        _SupportFaces;
    int                      _rank;
    short                    _done;
    short                    show_trace; // while debugging, set this value to 1 and ...
                                         // you will see .. heaven
    CATLONG32                _DegeneratedEdgesManagement;

    // Internal Methods
    void      Init                     () ;
    void      GetDomainsOfDomain       (CATDomain * iDomain , CATLISTP(CATDomain)  & oList);
    int       IsInSupport              (CATCell   * iCell);
    void      GetSupportGeometries     (CATShell  * iShell  , CATLISTP(CATSurface) * oList);
    void      GetSupportGeometries     (CATDomain * iSupport, CATLISTP(CATCurve)   * oList);
    CATCell * GetSupportFromLyingOnData(CATCell   * iCell);


          // Ajouts pour CGMReplay de CATLocationWireOnShell NLD091115
#ifdef CATLocationTopology_CGMReplayBasis
          CATExtCGMReplay* IsRecordable  (short                  & LevelOfRuntime      ,
                                          short                  & VersionOfStream     );
          void       RequireDefinitionOfInputAndOutputObjects();

          void       WriteInput          (CATCGMStream           & Str                 );
#endif
};
#endif










