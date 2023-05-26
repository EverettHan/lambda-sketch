// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
//
// ATTENTION : - TOUS LES RANGS COMMENCENT A 1 !
//                  - DEUX COURBES CONSECUTIVES DOIVENT ETRE ADJACENTES.
//                  - ON NE PEUT DEFINIR DEUX DIRECTIONS SUR UN MEME VERTEX.
//==========================================================================
// April 2000  Creation                                                  NDN
// 08/02/01    EvalNormalDerivative                                      CPL
// 07/01/03    Ajout de la methode SetNoCheckOfSensOfDir (CATLONG32 iIndex)   MNA
//             Desactive la verif du sens des direction passee entre la fin 
//             du comb i et le comb i+1. (Cette verif n 'a pas lieu d'etre 
//             si elle est effectuee par l'appelant et surtout dans les cas 
//             de Comb C0 avec un angle > 90.)
// 07/05/04    MNA : Ajout de la methode GetContinuityBetweenComb => Voir MultiComb
// 05 08 05    JSX : Ajout de SetGlobalLaw
// 04/11/05 NLD Ajout de la software configuration en argument du constructeur
// 06/01/06 NLD Ajout de _Config
// 23/02/07 NLD _Fact en public
// 17/09/07 NLD Ajout de GetSoftwareConfiguration()
// 25/11/09 NLD Ajout de _CurvesToDelete
// 01/12/09 NLD Ajout de _SurfacesToDelete
// 02/12/09 JSX Add Direction in Set3DCombCreationOption
// 08/12/09 JSX Heritage de FrFObject et menage
// 14/10/10 JSX Ajout SetG2Law pour imposer la courbure exacte des profils
// 25/04/13 NLD Suppression de l'argument inutile iKind de SetG2Law()
// 30/04/13 NLD Ajout SetFakeConnectionTreatment()
//==========================================================================
#ifndef CATFrFNormalMultiComb_H
#define CATFrFNormalMultiComb_H

#include "CATFrFObject.h"

#include "FrFOpeCrv.h"
#include "CATListOfInt.h"
#include "CATMathDef.h"
#include "CATListOfCATCrvParams.h"
#include "CATListOfDouble.h"
#include "CATCGMVirtual.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATSurfaces.h"

class CATCurve;
class CATSurface;
class CATMathVector;
class CATMathPoint;
class CATCrvParam;
class CATGeoFactory;
class CATMathDirection;
class CATCrvLimits;
class CATFrFMultiComb;
class CATBorderForPocketOffset;
class CATFrFCompositeCurve;
class CATFrFComb;
class CATSoftwareConfiguration;


//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrFNormalMultiComb : public CATFrFObject
  {
  public:
    //--------------------
    // Constructor
    //--------------------
    //The variable iLevel allows you to precise the method (Or Level) used for the built of the Normal Comb.
    //Its values is by default equal to 0. 
    //        - Level 0 : An intemediate surface is computed to obtain the comb. Please do not use anymore this mode and migrate on following mode.
    //        - Level 1 : No intermediate surfaces are computed: better performance, more reliable.

    CATFrFNormalMultiComb(CATGeoFactory *iFactory, 
                          CATSoftwareConfiguration* iConfig,
                          const CATCurve **iCrv, const CATCrvLimits *iLim,CATLONG32 *iCont,
                          const CATListOfInt *iListOfOrn, CATLONG32 iLevel=0);

    //--------------------
    // Destructor
    //--------------------
    virtual ~CATFrFNormalMultiComb();

    //--------------------
    // Set
    //--------------------
    //iDir is normalized.
    void SetDirection(CATLONG32 iRankOfCurve, const CATCrvParam &iParam, const CATMathVector &iDir);

    //Set3DCombCreation. Default is No/0. If you want to create a comb on 3D Curves.
    void Set3DCombCreationOption(CATBoolean iYeNo, CATMathVector *iPlnaNormal=NULL);
    CATBoolean Get3DCombCreationOption();

    CATFrFMultiComb * GetMultiComb();

    //To remove localization of the deformation.
    void RemoveLocalization();
    CATBoolean GetLocalizationOption();

    //To get a G1 normal comb everywhere the underlying curve is G1.
    void SetSmoothOption();
    void SetSmoothAngleThreshold( double iAngle );

    //To close the set of Curves (i.e. the last and the first Curve are adjacent).
    void SetIsClosed();
    CATBoolean IsClosed();

    void SetNoCheckOfSensOfDir (CATLONG32 iIndex);

    //AngleMax en dessous duquel on corrige automatiquement le peigne en C0 (angle en radian).
    void SetC0AngleThreshold(double iMaxAngleForRepairing);

    //Define connexion where you don't want any C0 correction. Connexion "iIndex" is between iIndex and iIndex+1, iIndex 
    //starting from 0. On closed comb, closure connexion correspond to iIndex=NbElementsInComb. Default is always repair.
    //WARNING : if there is any incompatibility between this option and SetC0AngleThreshold option on a connexion, no
    //C0 repair will be done.
    void SetRemoveC0Correction(CATLONG32 iIndexOfConnexion);

    // Activates continuons direction law over fake connections (C1)
    void SetFakeConnectionTreatment();

    void RemoveNormalModeOption(CATBoolean iNo=0);


    void SetG2Law(CATLONG32 iIndexOfCurve, const CATCrvParam &iParam, /* NLD250413 CATLONG32 iKind,*/ double iNormalG2, const CATMathVector &iCrossG2Dir);

    CATLONG32 GetContinuityBetweenComb(CATLONG32 iRankOfCurve,double iPointContinuity,double iAngleContinuity);

    virtual void SetGlobalLaw(int iGlobalLaw); 
    //--------------------
    // After any set and before any eval methods
    //--------------------
    void UpdateComb();
    CATLONG32 Check();

    //--------------------
    // Eval methods
    //--------------------
    void EvalPoint           (CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathPoint &oPt);
    void EvalNormal          (CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathDirection &oDir);
    void EvalNormalDerivative(CATLONG32 iRankOfCurve, const CATCrvParam &iParam, CATMathDirection &oN, CATMathVector& odN);

    //--------------------
    // To invert the entire comb.
    //--------------------
    //Invert the direction used for G1.
    void InvertCombOrientation();
    //Invert orientation of the list of curve.
    void InvertCurvesOrientation();
    // To set support orientation for each comb. NewOrn=1 or -1.
    void SetCombOrientation(int iRankOfCurve, int NewOrn);

    //--------------------
    // To get maximal angular deformation. The result is expressed in radian.
    //--------------------
    double GetAngularDeviation();

    //--------------------
    // To get the number of comb.
    //--------------------
    CATLONG32 GetNumberOfComb() const;

    //--------------------
    // To get one extremity of the comb according to orientation of the curve.
    // For iSide : Beginning=0 and End=1.
    //--------------------
    void GetOneCombExtremity(CATLONG32 iRankOfCurve, CATLONG32 iSide, CATCrvParam &oParam) const;

    //--------------------
    // Private -> Internal mapping.
    //--------------------
    void FromOriginalToNewParam(CATLONG32 &iIndexOfCurve,const CATCrvParam &iOriginal,
                                CATCrvParam &oNew,double *oDerivMapp=0);

    //--------------------
    // Private -> Get one elementary comb.
    //--------------------
    const CATFrFComb * GetOneComb(CATLONG32 iRankOfCurve) const;

    //--------------------
    // Private -> Get Initial Data.
    //--------------------
    const CATCurve * GetContactCurve(CATLONG32 iRankOfCurve,CATCrvLimits *ioLimOnContact=0);

    //--------------------
    // Dump
    //--------------------
    void Dump();

protected :
    void CreateSmoothComb();
    void CleanSmoothData();

//============================================================================================
//----- DATA ---------
//============================================================================================

  protected:

    CATBorderForPocketOffset **_Wall;
    CATFrFMultiComb           *_Comb;

    CATLONG32 _Level;
    int       _GlobalLaw;
    //Options for Smooth comb
    double                     _AccuPoint;
    double                     _AccuAngle;
    double                     _AccuSecRow; //pour opti cpu/lisibilite = 2*sin(0.5*_AccuAngle)
    double                     _ErrorPoint;
    double                     _ErrorSecRow;
    CATLONG32                  _Smooth;
    double                     _SmoothAngle; 
    CATLONG32                  _NeedSmoothDataUpdate;
    CATFrFCompositeCurve      *_newCCV[2];
    CATLISTP(CATCurve)         _CurvesToDelete;
    CATLISTP(CATSurface)       _SurfacesToDelete;
  };
#endif
