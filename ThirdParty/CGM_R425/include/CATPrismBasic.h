#ifndef CATPrismBasic_H
#define CATPrismBasic_H

//------------------------------------------------------------------------------
// CATPrismBasic : basic class for prism to be used by CVM only
// Note : static method are useful for code sharing between Prism and PrismBasic
//------------------------------------------------------------------------------
// 08 12 09 NLD Definition d'une nomenclature pour les classes utilitaires du sweep, la plupart exportees
//              SpecCell  devient CATSweepSpecCell
//              Tableau   devient CATSweepArrayOfSpecCell
//              Spec      devient CATSweepSpec
//              Brep      devient CATSweepBRep
//              BrepCell  devient CATSweepBRepCell
//              Journal   devient CATSweepJournal

#include "CATMathDef.h"
#include "CATSweepBasic.h"
#include "CATMathDirection.h"
#include "BO0SWEEPLight.h"

class CATGeoFactory;
class CATBody;
class CATEdge;
class CATVertex;
class CATTopData;
class CATMathPoint;
class CATSweepJournal;

//--------------------------------------------------------------------------
class ExportedByBO0SWEEPLight   CATPrismBasic : public CATSweepBasic
{

  friend class CATPrism; // for code sharing with static routine

//
//
public:
//-----

  // Constructeur d'un prisme a partir d'un Body 
  CATPrismBasic ( CATGeoFactory          * iGeoFactory,
                  CATTopData             * iData,
                  CATBody                * iProfBody,
                  const CATMathDirection & iDir,
                  CATLength                iStartOffset, 
                  CATLength                iEndOffset );
  //
  // Destructeur 
  ~CATPrismBasic();

//
//
protected :
//---------

  // Data members
  CATMathDirection _Direction;
  CATLength        _Value[2];


  // SweepCnt
  CATBody * SweepCnt(CATGeoFactory * iGeoFactory);

  static void SweepCntStatic ( CATSweepType        iSweepType,
                               CATBoolean          iThinSolidMode,
                               CATSweepJournal  *  iJournal ,
                               CATGeoFactory    *  iGeoFactory , 
                               CATCGMOperator   * iOper,
                               CATMathDirection &  iDirection,
                               double              ioValue[2],
                               CATBody          *& oBody ,
                               CATDomain        *& oDomain,
                               CATEdge          *& oCntEdge,
                               CATVertex        *  oCntVertices[2],
                               CATMathPoint        oPExtremities[2]);

  //
  //
  // nettoyage de l'environnement   
  void Clear ();

};
#endif
