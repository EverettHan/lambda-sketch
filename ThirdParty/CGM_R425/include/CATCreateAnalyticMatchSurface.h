// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATCreateAnalyticMatchSurface :
// Declaration of global functions used to create an instance of the Analytic 
// Match Surface operator
//

#ifndef CATCreateAnalyticMatchSurface_H 
#define CATCreateAnalyticMatchSurface_H 

#include "FrFOpeSur.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATPLine;
class CATCurve;
class CATCrvLimits;
class CATLaw;
class CATAnalyticMatchSurface;
class CATSoftwareConfiguration;
class CATPlane;

/**
 * Creates the geometric operator to analytically deform a NURBS surface such that a boundary
 *  of this surface becomes another curve.
 * <br> The parameterization of reference curve or surface (the surface or the curve which 
 * becomes the boundary of the original surface) is kept on the deformed surface.
 * @param iFactory
 * The pointer to the geometry factory.
 * @param iBoundaryToMatch
 * The pointer to the surface boundary to match. The surface must be a NURBS surface.
 * @param iCrvRef
 * The pointer to the curve on which <tt>iCrvMat</tt> is matched.
 * @param iCrvLimRef
 * The limits on <tt>iCrvRef</tt> to take into account.
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator.
 */

ExportedByFrFOpeSur
CATAnalyticMatchSurface * CATCreateAnalyticMatchSurface(CATGeoFactory  *iFactory,
                                                     CATSoftwareConfiguration *iConfig,
                                                     CATPLine *iBoundaryToMatch,
                                                     CATCurve *iCrvRef,
                                                     const CATCrvLimits &iCrvLimRef,
                                                     CATSkillValue iMode=BASIC);


/**
 * Creates the geometric operator to analytically deform a NURBS surface to make a given 
 * angle with a plane.
 * <br> The orthogonal projection on the plane of the initial NURBS surface boundary must
 * not be self-intersecting.
 * @param iFactory
 * The pointer to the geometry factory.
 * @param iBoundaryToMatch
 * The pointer to the surface boundary to match. The surface must be a NURBS surface.
 * @param iPlane
 * The pointer to the plane.
 * @param iAngularLawMirror
 * The law angle between the surface and the plane. If NULL, the surface arrives normally
 * to the plane.
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator.
 */

//////////JSX 040407
//////////Pas de config mais 5 ODTs !
//////////Pourqoui ne pas le migrer en meme temps que les autres 
//////////
//////////CATClassAUI.tst TestCases CATClaFeatureTest003
//////////CATClassAUI.tst TestCases CATClaPlaneMatchingTest001
//////////CATClassAUI.tst TestCases TestWkBInit
//////////CGMSurfacicTests.tst TestCases CGMTest_SurfacicMatchMirror_Task1063_N1
//////////FreeStyleShapeUI.tst TestCases FSSSurfaceMatchingOnPlane
//////////
//////////
//////////

ExportedByFrFOpeSur
CATAnalyticMatchSurface *CreateAnalyticMirrorMatch(CATGeoFactory *iFactory,
                                                      CATSoftwareConfiguration *iConfig,
                                                      CATPLine      *iBoundaryToMatch,
                                                      CATPlane      *iPlane,
                                                      const CATLaw  *iAngularLawMirror,
                                                      CATSkillValue  iMode);

ExportedByFrFOpeSur
CATAnalyticMatchSurface *CreateAnalyticMirrorMatch(CATGeoFactory *iFactory,
                                                      CATPLine      *iBoundaryToMatch,
                                                      CATPlane      *iPlane,
                                                      const CATLaw  *iAngularLawMirror,
                                                      CATSkillValue  iMode);


#endif


