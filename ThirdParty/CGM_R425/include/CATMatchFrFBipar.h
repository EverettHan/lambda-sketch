// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMatchFrFBipar :
// Internal class for the Match operator
//
// To match a FrFBipar to N FrFCombMFs (1 <= N <= 4)
// The FrFBipar and FrFCombMF knot vectors must be the same 
// The FrFCombMFs must be compatible at their common corners
//
//=============================================================================
// Usage notes:
//
//   +---------------------------------->------------------------------------+
//   |            |                                             |            |
//   |            |               FrFCombMF2                    |            | 
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                                             |            |
//   |------------+--------------------->-----------------------+------------|
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                   Side2                     |            |
//   |            |         +--------------------------+        |            |
//   |            |         |                          |        |            |         
//   |            |         |  A V                     |        |            |
//   |            |         |  |                       |        |            |
//   |            |         |  |                       |        |            |
//   |FrFCombMF1  A    Side1|  |      FrFBipar         |Side3   V  FrFCombMF3|
//   |            |         |  |   to be matched       |        |            |
//   |            |         |  |                       |        |            |
//   |            |         |  |                       |        |            |
//   |            |         |  +-----------> U         |        |            |
//   |            |         |                          |        |            |
//   |            |         +--------------------------+        |            |
//   |            |                   Side0                     |            |
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                                             |            |
//   |------------+---------------------<-----------------------+------------|
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                                             |            |
//   |            |                FrFCombMF0                   |            |
//   |            |                                             |            |
//   +----------------------------------<------------------------------------+
//
//=============================================================================
//   Aug 99 TPG Creation
// 08 01 04 CCK Ajout de la _SoftwareConfig
//=============================================================================
#ifndef CATMatchFrFBipar_H
#define CATMatchFrFBipar_H

#include "FrFOpeSur.h"

#include "CATFrFCombMF.h"
#include "CATFrFNurbsBipar.h"
#include "CATFrFNurbsMultiForm.h"
#include "CATFreeFormDef.h"
#include "CATCGMVirtual.h"

class CATGeoFactory;
class CATCurve;
class CATPCurve;
class CATCrvLimits;
class CATSurface;
class CATKnotVector;
class CATMatchSurfaceResult;
class CATSoftwareConfiguration;
 
//-----------------------------------------------------------------------------
class ExportedByFrFOpeSur CATMatchFrFBipar  : public CATCGMVirtual
{
 public:

    //---------------
    //  Constructor !
    //---------------
  CATMatchFrFBipar(CATGeoFactory            * iFactory,
                   CATFrFNurbsBipar         * iBiparToBeMatched,
                   CATFrFCombMF             * iCombMFReference[4],
                   CATSoftwareConfiguration * iConfig=NULL);
   
    //--------------
    //  Destructor !
    //--------------
  virtual ~CATMatchFrFBipar       ();

    //-----------
    //  Methods !
    //-----------
  virtual void Run ();
//
//  Setting the Match parameters
//
//  Transition continuity: the default continuity is CATFrFPointCont.
// 
  void SetTransitionContinuity(CATLONG32 iSideIndex,
                               CATFrFContinuity iContinuity);
//
//  Opposite side continuity: the default continuity is CATFrFPointCont.
//  useful when one side matching
// 
  void SetOppositeSideContinuity(CATLONG32 iSideIndex, 
                                 CATFrFContinuity iContinuity);
//  Diffusion  
//  iDiffusion = 0 : Matching creates only a local deformation (default option).
//  iDiffusion = 1 : Deformation will be diffused along the Bipar To Be Matched.
  void SetDiffusion(CATLONG32 iDiffusion);

//  Optimization  
//  iOptimization = 0 : Local deformation to upgrade the transition quality (OFF).
//  iOptimization = 1 : Local deformation to upgrade the transition quality (ON) (default option).
  void SetOptimization(CATLONG32 iOptimization);

//  Degree  
//  iMode = 0 : Unchange the initial degree.
//  iMode = 1 : Degree can be modified.
  void SetDegreeModification(CATLONG32 iMode);

 protected:
    //-----------
    //  Data    !
    //-----------

// Match input
  CATGeoFactory                   * _Factory;
  CATSoftwareConfiguration        * _SoftwareConfig;
  CATFrFNurbsBipar                * _BiparToBeMatched;
  CATFrFCombMF                    * _CombMFReference[4];

// Match configuration
  CATFrFContinuity                  _TransitionContinuity[4];
  CATFrFContinuity                  _OppositeSideContinuity[4];
  
// Options
  CATLONG32                         _Diffusion;
  CATLONG32                         _Optimization;
  CATLONG32                         _DegreeModification;

// data
  CATLONG32                         _NbReference;
  CATLONG32                         _Reference[4];
  CATFrFCombMF                    * _TargetCombMF[4];
  CATFrFNurbsMultiForm            * _BordsC11[4];
  CATFrFNurbsBipar                * _WorkingBipar;
  CATFrFNurbsBipar                * _WorkingBiparDiff;
  CATFrFNurbsBipar                * _CoonsBipar;
  

// Internal methods
//
// Compute TargetCombMFs
  void ComputeTargetCombMF();

// G1 Compatibility at the corner
  void G1Compatibility();

// G2 Compatibility at the corner
  void G2Compatibility();

// Compute Coons Surface
  void ComputeCoonsSurface();

// Compute matched Surface
  void ComputeMatchedSurface();

// Compute mono matched Surface
  void ComputeBasicMatchedSurface(CATFrFNurbsBipar* ioBipar,
                                  CATLONG32 iSide);

// Diffusion
  void RunDiffusion();

// Optimization
  void RunOptimization(CATLONG32 iCont);

};

#endif
