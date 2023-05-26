// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATFrFImplicitSpine:
// Interface class of Guide Object for the Generalized Sweep Operator.
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// March 99 DHN Creation
// 21/02/01 NLD SetVersion(), _Version
// 18/01/02 NLD,
//          CCK SetSoftwareConfiguration (migration ulterieure de SetVersion
//              vers SetSoftwareConfiguration)
// 21/05/02 CCK SetFirstProfilPlaneNormal
// 04/04/06 JSX Derivation de CATFrFObjectVirtual; Resultat sous forme d'une CCV
// 19 01 07 JSX Suppression de SetSoftware (le create a un topdata)
//              SetVersion() reste pour le cas==3
// 25 01 07 JSX Ajout de SetForceMinCurvaturSpine
// 13 04 07 JSX Constructeur avec CATFrFObject
// 03/01/14 NLD le constructeur par defaut devient prive
// 05/02/14 NLD SetFirstProfilPlaneNormal() est renommee SetFirstProfilePlaneNormal()
//==========================================================================
//
#ifndef CATFrFImplicitSpine_H
#define CATFrFImplicitSpine_H
//
#include "FrFAdvancedObjects.h"

#include "CreateImplicitSpine.h"
//#include "CATCGMVirtual.h"
//#include "CATFrFObjectVirtual.h"
#include "CATFrFObject.h"
#include "CATListOfInt.h"
class CATMathPoint;
class CATMathPlane;
class CATFrFCompositeCurve;
class CATCurve;
class CATSoftwareConfiguration;

/**
 * The relimitations on the extremity profiles.
 * @param Relimitation_Off
 * The sweep is not relimited on the extremity profiles.
 * @param Relimitation_OnLimitProfiles
 * The sweep is not relimited on the extremity profiles
 * @param Relimitation_OnFirstProfile
 * The sweep is relimited only on the first input profile 
 * @param Relimitation_OnLastProfile
 * The sweep is relimited only on the last input profile 
 */
typedef enum { Relimitation_Off            = 0,
               Relimitation_OnLimitProfiles,
               Relimitation_OnFirstProfile ,
               Relimitation_OnLastProfile  }
               CATImplicitSpineRelimitation_Type ;


//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFImplicitSpine : public CATFrFObject //Virtual
{
 private:
                    CATFrFImplicitSpine            ();
 public :

                    CATFrFImplicitSpine            (const CATFrFObject& iFrFObject);

   virtual         ~CATFrFImplicitSpine            ();

   //
   // Add a reference curve (for exemple a guide or a limit curve)
   // This curve will change the form of the implicit spine if method
   // "UseReferenceCurvesForSpineShape" is called.
   //
  virtual void      AddReferenceCurves             (      CATFrFCompositeCurve            **  iCCVs               ,
                                                          CATLONG32                           iNbOfReferenceCurves)    = 0;

  virtual void      UseReferenceCurvesForSpineShape()                                                                  = 0;

/**
 * Sets the software version to use
 * @param iVersion
 * 0 : default
 * 1 : with tangency control by pair at extremities
 */
  virtual void      SetVersion                     (      int                                 iVersion            = 0) = 0;
  // On va remplacer le SetVersion par le SetSoftwareConfiguration()
  // (qui lui meme disparait a cause des constructeurs avec CATFrFObject)
  //JSX  virtual void SetSoftwareConfiguration(CATSoftwareConfiguration* iSoftwareConfig)=0;

//-------------------
// Impose tangency
//-------------------
// (iCase == 0) => Tangency on First & Last  Profile
// (iCase == 1) => Tangency on only    First Profile
// (iCase == 2) => Tangency on only    Last  Profile
//
// When iTangent == NULL, Profile have to be a "Wire Pose Sur"
  virtual void      SetTangency                    (      CATLONG32                            iCase               = 0,
                                                    const CATMathPlane                      *  iTangent            = 0)= 0;

/**
 * Sets the relimitation mode by the extremity profiles.
 * @param iRelimitationMode
 * The relimitation mode.
 */
  virtual void      SetRelimitationMode            (      CATImplicitSpineRelimitation_Type    iRelimitationMode   = Relimitation_OnLimitProfiles ) = 0 ;

//------------------------------------------------------------------------------
// Impose a point the spine exactly passes through 
// The InitPointRank specifies which entry this point is related to
// This rank must be one of the orders given for the composite curves
// or the planes (see the function CreateImpliciteSpine), its value
// must be between 1 and the number of entries (planes and composite curves)
//------------------------------------------------------------------------------
  virtual void      ImposeInitPoint                (      CATMathPoint                      *  iInitPoint          ,
                                                          CATLONG32                            iInitPointRank      )  = 0;

//
// Set Mode For Extrapol Operator
//
  virtual void      SetSpineForExtrapol            ()                                                                 = 0;

//
// Set the normal of the first plane when all profils are planes
// iNormalOrn = 0 (default value): default mode (optimized computation, not ever the better)
// iNormalOrn = 1 : Geometric normal orientation
// iNormalOrn = -1 :  - Geometric normal orientation
//
  virtual void      SetFirstProfilePlaneNormal      (      CATLONG32                            iFirstNormalOrn    )    = 0;

  //
  //
  //
  virtual void      SetForceMinCurvatureSpine      (      CATLONG32                            iForceMinCurvature = 1) = 0;


  //-------------------
  // Compute the Spine
  //-------------------
  virtual void      Run                            ()                                                                  = 0;

  //
  // Get the result spine
  //
  virtual CATCurve* GetImplicitSpine               ()                                                                  = 0;

  //                                                                                           iContinuityAtVertex : one value for each plane or ccv
  //                                                                                           (see derivated class for constructor with planes) NLD030114
  virtual void      SetKeepCompositeSpine          (      const CATListOfInt                 & iContinuityAtVertex)    = 0;

  // Get CCV result : ExtrapolMode : Result Before Clean
  //
  virtual CATFrFCompositeCurve * GetImplicitSpineCCV()                                                                 = 0;


};
#endif




