#ifndef CATSweepDef_H
#define CATSweepDef_H

// COPYRIGHT DASSAULT SYSTEMES 1999
//===========================================================================
// 09 01 04 NLD Ajout _CntContourDupExt
// 24 03 10 NLD La classe EdgeToBeCut est renommee CATSweepDefEdgeToBeCut
//              et n'est plus exportee
//              Suppression methode statique TransfoCalculation() definie dans l'implementation
// 06 12 10 NLD Argument iExtrapolateReport à ProfileExtrapoleBasic()
// 07/07/11 NLD Ajout _OperatorId, GetOperatorId(), GetDefaultOperatorId()
//===========================================================================
#define CATSweepDef_NewListCntCrvLimitsDeleteAsSingleElement "NLD150911 pour correction coherente mauvaise gestion"

#include "BO0SWEEP.h"

#include "CATString.h"

#include "CATMathDef.h"
#include "CATMathDirection.h"

#include "CATSweep.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "CATListOfCATCrvLimits.h"
#include "CATSetOfCrvParams.h"
class CATGeoFactory;
class CATBody;
class CATExtrudeDef;
class CATPGMExtruder;
class CATFrFSection;
class CATSweepDefEdgeToBeCut;
//
//--------------------------------------------------------------------------
// Liste des elements de graphe
// -----------------------------
//
// clean previous functions requests

#include "CATCGMLISTP_Declare.h"

class CATSweepDefEdgeToBeCut;

CATCGMLISTP_DECLARE(CATSweepDefEdgeToBeCut);

typedef CATLISTP(CATSweepDefEdgeToBeCut) ListPOfCATSweepDefEdgeToBeCut;
typedef CATLISTP(CATCrvLimits) CATSweepDefListPOfCATCrvLimits;
//
//
//
class /* export non necessaire NLD240310 ExportedByBO0SWEEP */ CATSweepDefEdgeToBeCut
{
  protected :
  CATEdge *            _Edge;
  CATSetOfCrvParams *  _SetOfBreaks;
  CATListOfInt      *  _Sharpness;
// 
//
  public :
// constructeur
  CATSweepDefEdgeToBeCut (CATEdge * iEdge, CATSetOfCrvParams * iSetOfBreaks, CATListOfInt * iSharpness = 0);
// destruteur
  ~CATSweepDefEdgeToBeCut();
// methodes 
  CATEdge * GetEdge ();
  CATSetOfCrvParams  * GetSetOfBreaks ();
  CATListOfInt * GetSharpness ();
};
//
//
//--------------------------------------------------------------------------
//
class ExportedByBO0SWEEP   CATSweepDef : public CATSweep
{
 // Donnees membres
 //----------------
 protected:
  ListPOfCATVertex          _ListCntVertexC0;
  ListPOfCATEdge            _ListCntEdge;
  CATSweepDefListPOfCATCrvLimits _ListCntCrvLimits;
  ListPOfCATSweepDefEdgeToBeCut  _ListEdgeToBeCut;
  CATBody* _CntContourDupExt ;// duplication du contour centre extrapole.
  //
  //
  CATBody * ProfileExtrapole (CATBody * iBody);
  CATBody * ProfileExtrapoleBasic (CATBody * iBody, const CATMathTransformation &iTransfo, CATCGMJournalList* iExtrapolateReport);
  void CenterExtrapole (); 
  void SetCenter ();
  //
  //
  // nettoyage de l'environnement
  void Clear ();
  //
  void  GeoExtrudeLate (CATSweepBRepCell * iBrepCell);
  //
  // Gestion de la non-isotopologie
  void NonIsoExtrude ();
  CATBoolean IsCenterVertexC1 (CATVertex * iCntVertex);
  void GetCenterEdgeLimits (CATEdge * iCntEdge, CATCrvLimits & ioCenterEdgeLimits);
 //
 public:

  // Constructeur d'un SweepDef a partir d'un Body
  CATSweepDef (CATGeoFactory * iGeoFactory,
               CATTopData * iData,
               CATBody * iProfBody,
               CATBody * iCntBody,
               CATPGMExtruder * iExtruder);

  //
  // Destructeur
  ~CATSweepDef();
  //
  const CATString* GetOperatorId();
  const CATString* GetDefaultOperatorId();

 private:
  static CATString _OperatorId;

};

#endif

  



















