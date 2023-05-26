#ifndef CATPrism_H
#define CATPrism_H

// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
// 2010-08-19 DLP Declare ComputeExtrapolatedLimits().
// 2010-09-30 DLP Declare new methods called by ComputeExtrapolatedLimits().
// 2010-11-04 DLP ProfileExtrapoleBasic -> ProfileExtrapoleBasicStiffener
// 2011-10-26 THM Add CalculateExtremityTangents & ProfileClosePrismGeneral methods
// 2012-11-07 G5S New method GetExtrusionLimits, which is useful for the Remove First Volume project.
//=============================================================================

#include "CATMathDef.h"
#include "CATSweep.h"
#include "CATMathDirection.h"
#include "CATMathInline.h"
#include "BO0SWEEP.h"
class CATGeoFactory;
class CATBody;
class CATMathPoint;
class CATTopData;

//--------------------------------------------------------------------------
class ExportedByBO0SWEEP   CATPrism : public CATSweep
{
public :
//
/**	@nodoc @nocgmitf */
  const  CATString  *GetOperatorId();
// Donnees membres
//----------------
protected:
//
  CATMathDirection _Direction;
  CATLength _Value[2];
  CATBoolean _StiffenerMode;
  CATBoolean _StiffenerMatterSide;
  CATBoolean _DirectionHasBeenInverted;
//
CATBody * SweepCnt(CATGeoFactory * iGeoFactory);
//
// methodes pour extrapoler le center contour
  void CenterExtrapole ();
// methodes pour extrapoler le profile
  void ProjectPointOnSurface ( CATGeoFactory            *  iGeoFactory            , 
                               CATSoftwareConfiguration *  iSoftwareConfiguration ,
                               const CATMathPoint       &  iPointToProject        ,
                               const CATSurface         *  iSurface               ,
                               CATSurParam              &  oCurrentSurParam       ,
                               CATError                 *& oError                 );
  CATBody * ProfileClose (CATBody * iBody);
  CATBody * ProfileCloseStiffener (CATBody * iBody);
  CATBody * ProfileExtrapoleBasicStiffener
                                  (CATBody * iBody,
                                   double iRadius, CATMathPoint & iMiddlePoint,
                                   CATBoolean & oFermeture);
  CATBody * ComplementBody (CATBody * iBody);

   int GetRefPlaneOri ( CATMathPoint         &  ioOrigin,
                        CATMathDirection     &  iNormal );

  //  Methods involved in extrapolating limiting faces.
  void ComputeExtrapolatedLimits (
    CATSurface   * iSurface,
    CATSurLimits & iFacesLimits,
    CATSurLimits & oNewSurLimits );
  void ComputeExtrapolatedLimitsFromLines(
    CATSurface   * iSurface      ,
    CATSurLimits & iFacesLimits  ,
    CATMathLine ProfBoxExtrudedLine[],
    CATSurLimits & oNewSurLimits );
  void ComputeExtrudedLines(
    CATMathLine    ProfBoxExtrudedLine[] );

  /**	@nodoc @nocgmitf */ 
	static const  CATString  *GetDefaultOperatorId();
	
	/**	@nodoc @nocgmitf */
	static  CATString  _OperatorId;

//
//
// nettoyage de l'environnement
  void Clear ();
//
//
private:
   void CalculateExtremityTangents(CATVertex** iExtVertices, 
                                   CATEdge** iExtEdges, 
                                   const CATSide iExtSide[2],  
                                   CATMathVector* oTangentVector, 
                                   CATMathPoint& oMPoint0, 
                                   CATMathPoint& oMPoint1);
   CATBody* ProfileClosePrismGeneral( CATBody * iBody );


public:
// Constructeur d'un prisme a partir d'un Body
  CATPrism(CATGeoFactory * iGeoFactory,
           CATTopData * iData,
           CATBody * iProfBody,
           const CATMathDirection& iDir,
           CATLength iStartOffset,
           CATLength iEndOffset);

// Constructeur d'un prisme a partir d'un Body
  CATPrism(CATGeoFactory * iGeoFactory,
           CATBody * iProfBody,
           const CATMathDirection& iDir,
           CATLength iStartOffset,
           CATLength iEndOffset,
           CATCGMJournalList * iReport=NULL);

  CATPrism(const CATPrism & iInitialPrism);
//
// Destructeur
  ~CATPrism();

  // If one of the two limits is an offset, create a copy of the prism or the inverse of the prism.
  CATPrism * CreateCopyPrism(CATBoolean iCreateInverse);

// Get limits of extrusion.
  void GetExtrusionLimits (CATLength (& oLimits)[2]);
//
// lecture de la direction
  INLINE CATMathDirection & GetDirection ();
//
// fonction membre de verification des inputs
  void  SetVerifCenter();
//
// demande de fermeture du profile em mode Stiffener
  void  SetStiffenerMode (CATBoolean iStiffenerMode,
                          CATBoolean iMatterSide);
  CATBoolean GetStiffenerMode (CATBoolean &oMatterSide);
  void SetMatterSide(CATSide iMatterSide);

  // Set the option to convert the dimension limit to an until limit.
  void SetConvertDimLimitToUntil (CATBoolean iConvertDimLimitToUntil);

  // Whether to convert the dimension limit to an until limit.
  virtual CATBoolean              ShouldConvertDimLimitToUntil();

  // The transformation of the profile required for the dimension limit. 
  virtual CATMathTransformation * GetProfileOffsetTransformation (CATLength iOffset);
};

// lecture de la direction
INLINE CATMathDirection & CATPrism::GetDirection ()
{ return _Direction; }
#endif
