// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATFrFMovingFrame:
// Interface class of the FrF Moving Frame
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// Nov.  97 CPL Creation
// 12/02/99 CPL Modification
// 22/06/99 PRG new Project Method is added
// 27/09/99 CPL Evaluators
// 22/12/99 CPL IsATypeOf
// 21/02/01 MNA GetMovingFrameType
// 26/11/02 NDN GetSoftwareConfiguration
// 23/05/03 NLD GetMapping(), GetTotalLength() ne sont plus const
// 20/11/03 NLD GetSpinePlane()
// 28 06 04 JSX Archi (herite de FrFObjectVirtual)
//              +
// 13/12/05 NLD Ajout SetFrFTopologyCallBacks()
// 16/12/05 NLD Documentation des valeurs possibles de SetSmoothOption()
// 13/03/06 NLD Ajout _SpecialCaseMultipleViewingDirRestrictedUse
// 27/03/06 NLD Ajout de GetLocalViewingDirection()
// 27/02/07 NLD Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 10/03/07 NLD Ajout du constructeur avec CATFrFObject
// 09/12/09 NLD Definition de nomenclature pour les #define partages:
//              CouplingAbs devient CATFrFMovingFrame_CouplingAbs
// 02/04/12 NLD Colonnage général
// 31/05/12 NLD Le destructeur est mis en protected pour privilégier Remove()
// 05/04/13 NLD SetINumDom() devient SetNumDominantGuide()
// 14/12/17 NLD Ajout GetCoupling()
// 15/12/17 NLD Ajout SetShape()
// 19/12/17 NLD Ajout argument iShapeToDelete à SetShape()
//==========================================================================
#define CATFrFMovingFrame_CouplingAbs
//
#ifndef CATFrFMovingFrame_H
#define CATFrFMovingFrame_H
//
#include <FrFAdvancedObjects.h>
//
//
#include <CATListOfInt.h>

class CATMathInterval;
class CATMathDirection;
class CATMathPoint;
class CATMathPlane;
class CATMathTransformation;
class CATMathAxis;
class CATSoftwareConfiguration;

class CATGeoFactory;
class CATCurve;

#include <CATFrFObject.h>
class CATFrFCompositeCurve;
class CATFrFCompositeCurveMapping;
class CATFrFCCvParam;
class CATFrFSweepShape;
class CATFrFGeneralBlextShape;
class CATFrFTopologyCallBacks;

class CATMovingFrameStruct;
#include <CreateFrFMovingFrame.h>
#include <CATMovingFrameType.h>

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFMovingFrame : public CATFrFObject
{
                                       CATCGMVirtualDeclareClass(      CATFrFMovingFrame);

 friend ExportedByFrFAdvancedObjects void Remove                (      CATFrFMovingFrame   *& ioMovingFrame     );

 protected:
  virtual                             ~CATFrFMovingFrame        (                                               );

 public:

                                       CATFrFMovingFrame        (      CATFrFMovingFrame   *  icopy             );
                                       CATFrFMovingFrame        (      CATFrFObject         & iFrFObject        );
  // Type
  virtual       CATBoolean             IsATypeOf                (      CATMovingFrameType     iType             ) const = 0;
  virtual       int                    GetMovingFrameType       ()                                                      = 0;

  // Factory (?)
  virtual       void                   SetFactory               (      CATGeoFactory       *  iFactory          )       = 0;

  // Spine
  virtual       void                   SetCcvMasterGuide        (      CATFrFCompositeCurve*  iSpine            )       = 0;
  virtual       CATFrFCompositeCurve * GetCcvMasterGuide        (                                               ) const = 0;

  virtual       void                   SetNumDominantGuide      (      CATLONG32              iNumDominantGuide )       = 0;
  
  // ViewingDirection
  virtual       void                   SetViewingDirection      (const CATMathDirection     & iViewingDirection )       = 0;
  virtual const CATMathDirection     * GetViewingDirection      (                                               )       = 0;
  // (Restricted use)
  virtual       void                   GetLocalViewingDirection (      int                    iNumImposedDomain ,
                                                                       CATMathDirection     & oViewingDirection )       = 0;
  
  // Data
  virtual       CATMovingFrameStruct   GetMFStruct              (                                               ) const = 0;

  // Smooth
  //-------
  // Option 0 : inactive, 1: standard, 2: fixed tangents
  // (ATTENTION: en pas modifier: valeurs utilisees dans le stream de SmoothSpine. NLD131114)
  // (ATTENTION: valeurs non definies dans CATIPGMFrFMovingFrame.h                 NLD220416)
  #define CATFrFMovingFrameSmoothOptionInactive      0
  #define CATFrFMovingFrameSmoothOptionStandard      1
  #define CATFrFMovingFrameSmoothOptionFixedTangents 2

  virtual       void                   SetSmoothOption          (      CATLONG32              iOption           )       = 0;

  virtual       void                   SetSmoothAngleThreshold  (      double                 iAngle            )       = 0;

  virtual       CATLONG32              GetSmoothOption          (                                               ) const = 0;

  virtual       double                 GetSmoothAngleThreshold  (                                               ) const = 0;


  // Domain (s)
  //-----------

  // Gestion de plusieurs domaines:
  // Cela permet de gerer une spine C1(voir C0)
  // en n evaluant que sur des elements C2

  virtual       void                  SetMovingDomain           (      CATMathInterval     *  iDomain           )       = 0;
  virtual const CATMathInterval     * GetMovingDomain           (                                               ) const = 0;
  virtual       CATMathInterval     * GetOneDomain              (      CATLONG32              iIndex            ) const = 0;

  virtual       double                GetTotalLength            (                                               )       = 0;

  virtual       CATLONG32             GetNumberOfDomains        (                                               ) const = 0;
 
  virtual       void                  SetDomains                (      CATMathInterval     *  iDomains          ,
                                                                       CATLONG32              iNbDomains        ,
                                                                       CATLONG32           *  iCrvIndexLow      ,
                                                                       CATLONG32           *  iCrvIndexHigh     )       = 0;
  virtual       void                  SetWorkingDomain          (      CATLONG32              iIndex            )       = 0;
  virtual       CATLONG32             GetWorkingDomain          (                                               ) const = 0;

  // Compute the domain by calculation of min distance
  // between 2 points and the MasterGuide
  virtual       void                  ComputeMovingDomain       (      CATGeoFactory       *  iFactory          ,
                                                                       CATMathPoint         & iStartPt          ,
                                                                       CATMathPoint         & iEndPt            )       = 0;


  // Parametrisation from the MovingFrame to the spine is defined
  // by a Coupling; otherwise by a Mapping.
  virtual       void                  SetCoupling               (      CATFrFCoupling      *  iCoupling         )       = 0;
  virtual       CATFrFCoupling*       GetCoupling               (                                               )       = 0;
  
  // Parametric Coupling
  virtual       void                  IsParametric              (                                               )       = 0;

  // Get spine plane if all spine curves are pcurves on same plane
  virtual       CATBoolean            GetSpinePlane             (      CATMathPlane         & oPlan             )       = 0;

  // Traitement C0
  virtual       void                  SetExtrapolatedConnexions (      CATListOfInt        *  iExtrapolatedConnexions)  = 0;

  // Traitement C1
  virtual       void                  GetMvFC1Param             (      CATListOfInt         & C2Dom             ,
                                                                       CATListOfDouble      & C2Param           ) const = 0;

  // Mapping 
  // Do not use
  virtual CATFrFCompositeCurveMapping*GetMapping                (                                               )       = 0;
  

  //------------------
  //  Pseudo Operators
  //------------------
  // iParam[0 1] in MovingDomain

  // From iParam to spine parametrisation (and invert)
  virtual       void                  EvalOnSpine               (      double                 iParam            ,
                                                                       CATFrFCCvParam       & oParam            )       = 0;
  virtual       void                  InvEvalOnSpine            (const CATFrFCCvParam       & iParam            ,
                                                                       double               & oParam            )       = 0;


  // Get Axis System of the Moving Frame

  virtual       void                  GetAxisSystem             (      double                 iParam            ,
                                                                       CATMathAxis          & oAxis             )       = 0;
  virtual       void                  GetAxisSystem             (const CATFrFCCvParam       & iParam            ,
                                                                       CATMathAxis          & oAxis             )       = 0;

  // iAxis[12], idAxis[12], id2Axis[12]
  virtual       CATBoolean            EvalAxis                  (      double                 iParam            ,
                                                                       double              *  iAxis             ,
                                                                       double              *  idAxis            = NULL,
                                                                       double              *  id2Axis           = NULL) = 0;
  // Do Not use
  virtual       void                  GetAxisSystem             (      double                 iParam            ,
                                                                       CATMathPoint         & oOrigin           ,
                                                                       CATMathDirection     & oXAxis            ,
                                                                       CATMathDirection     & oYAxis            ,
                                                                       CATMathDirection     & oZAxis            )       = 0;


  // Transformation Matrix from Global to Local Axis System
  virtual      CATMathTransformation* TransformGlobalToLocal    (const double                 iParam            )       = 0;
  virtual      CATMathTransformation* TransformLocalToGlobal    (const double                 iParam            )       = 0;

  // Get Section Plane
  virtual       CATMathPlane        * GetSectionPlane           (      double                 iParam            )       = 0;

  // Get Origin
  virtual       CATMathPoint          EvalOrigin                (      double                 iT                )       = 0;

  // Eval Origin and Plane Normal
  // iP[3] & iN[3] mustn't be NULL
  virtual       CATBoolean            EvalNormal                (      double                 iParam            ,
                                                                       double              *  iP                ,
                                                                       double              *  iN                ,
                                                                       double              *  idP               = NULL,
                                                                       double              *  idN               = NULL,
                                                                       double              *  id2P              = NULL,
                                                                       double              *  id2N              = NULL) = 0;


  // Project Point on Spine
  // ----------------------
  // Return the global parameter on the spine which defines
  // a plane including PointOnGuide.
  
  // Return only one solution
  // oParam
  virtual       double                Project                   (      CATGeoFactory       *  iFactory          ,
                                                                 const CATMathPoint         & iPointOnGuide     ,
                                                                       CATLONG32            & oNbSol            )       = 0;
  // Return only one solution 
  // oAxis (is the MovingFrame)
  virtual       void                  Project                   (      CATGeoFactory       *  iFactory          ,
                                                                 const CATMathPoint         & iPointOnGuide     ,
                                                                       CATMathAxis          & oAxis             ,
                                                                       CATLONG32            & oNbSol            )       = 0;

  // Return all solutions
  // odouble
  virtual       void                  Project                   (      CATGeoFactory       *  iFactory          ,
                                                                 const CATMathPoint         & iPointOnGuide     ,
                                                                       CATLONG32            & oNbSol            ,
                                                                       double              *& oSolutionParams   )       = 0;
  // Return all solutions
  // oCCVParam
  virtual       void                  Project                   (      CATGeoFactory       *  iFactory          ,
                                                                 const CATMathPoint         & iPointOnGuide     ,
                                                                       CATLONG32            & oNbSol            ,
                                                                       CATFrFCCvParam      *& oSolutionParams   )       = 0;


  // Return all solutions on one specified curve of the spine
  // projection on one spine's crv
  // we specify merge tolerance with extremities for the project operator
  // to avoid snapping
  virtual       void                  Project                   (      CATGeoFactory       *  iFactory         ,
                                                                 const CATMathPoint         & iPointOnGuide    ,
                                                                       CATLONG32            & oNbSol           ,
                                                                       double              *& oSolutionParams  ,
                                                                       CATLONG32              iGuideIndex      ,
                                                                       double                 iTolerance       )        = 0;


  virtual       void                  SetFrFTopologyCallBacks   (      CATFrFTopologyCallBacks*  iFrFTopologyCallBacks) = 0;

  // Special stream (DO NOT USE OUTSIDE STREAM)
  // --------------

  // Special MvFrExtrapol (pour Stream)
  //  je type ici la shape en CATFrFGeneralBlextShape(CATFrFSweepShape?) et non bien sûr CATFrFGeneralBlextShapeCx2
  virtual       void                  SetShape                  (const CATFrFGeneralBlextShape*  iShape        ,
                                                                       int                       iShapeToDelete= 0)        = 0;
};
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "CATMovingFrameStruct.h"
//-----------------------------------------------------------------------------

#endif

