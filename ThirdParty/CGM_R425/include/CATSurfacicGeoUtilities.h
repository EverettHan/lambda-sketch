#ifndef CATSurfacicGeoUtilities_H
#define CATSurfacicGeoUtilities_H

#include "GeoPlate.h"

#include "CATBoolean.h"
#include "CATListOfCATPCurves.h"
#include "CATSurParam.h"
#include "CATCrvLimits.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATSurface;
class CATPlane;
class CATPCurve;
class CATSurLimits;
class CATMathPolynomX;

class CATSurface;

class  ExportedByGeoPlate  CATSurfacicGeoUtilities
{
	public :
	/** nodoc*/
	// Unlock des equation sans levee d'exception
	// return TRUE if OK
	// return FALSE if Unlock is impossible
	static CATBoolean SafeUnlock (CATSurface* iSurf);

	/** nodoc*/
	// iVersion 0 : Methode antique (rapport max/min)
	//          1 : rapport des sommes
	static double ComputeAnisotropie(CATGeoFactory * iFactory,
													 CATSoftwareConfiguration *iConfig,
													 const CATSurface * iSurf, 
													 const CATSurLimits * iSL, 
													 const CATBoolean iPrecAniso = FALSE,
													 const short iVersion = 1);


	/** 
	* Extend a surface
	*
	* <br><b>Role</b>: Extend a surface, where some iso are kept. It is useful to vanish some singular corner.
	*
	* @param iFactory [in]
	*   The factory, used to create new gemetry.
	* @param iConfig [in]
	*   Define the versionning level
	* @param iSurface [in]
	*   The (singular) surface to extend
	* @param iBord [in]
	*   The liste of iso-boundary of the surface.
	* @param oInitPCurves [out]
	*   The liste of pcurve on the result surface / near of the input iso-boundary
	* @param iBord1 [in]
	*   The first boundary to keep.
	* @param iBord2 [in]
	*   The second boundary to keep. (if equal 0, only one boundary is kept).
	* @param iOrder_To_Freeze [in]
	*   Define the derivative order to freeze along the iso-curve to keep.
	*
	* @return
	*   An extended surface with respect of iso-bounary <iBord1> and <iBord2>
	*
	*/
	static CATSurface * ExtendSurf(CATGeoFactory * iFactory,
													 CATSoftwareConfiguration *iConfig,
													 CATSurface *iSurface, 
													 CATLISTP(CATPCurve)& iBord, 
													 CATLISTP(CATPCurve)& oInitPCurves, 
                           int iBord1,  int iBord2, int iOrder_To_Freeze);

	/** 
	* Find the identity number of an iso-boundary 
	*
	* <br><b>Role</b>: Return the identity number of an iso-boundary :
	*																			(Umax, Vmax)
	*              +---------------------------+
  *              |        --------->         |                 Natural orientation attached to the surface:
  *              |         Iso #4            |                                                             
  *              |                           |                    /|\                                           
  *          /|\ |                           | /|\                 |                                          
  *           |  |                           |  |                  | v                                        
  *    Iso #1 |  |                           |  | Iso #3           |                                                 
  *           |  |                           |  |                  |    u                                     
  *           |  |                           |  |                   ---------->                                        
  *              |         Iso #2            |                                                            
  *              |        --------->         |                                                           
  *              +---------------------------+
	*         (Umin, Vmin)
	*
	* @param iBord [in]
	*   The iso-boundary
	* @param iMin [in]
	*   The parameters (Umin, Vmin) on the surface.
	* @param iMax [in]
	*    The parameters (Umax, Vmax) on the surface.
	*
	* @return
	*   
	*
	*/
	static int GetIsoId(CATPCurve * iBord, CATSurParam& iMin, CATSurParam& iMax);


  /** 
  * Convert a surface in Plane
  *
  * <br><b>Role</b>: Explain what this method does.
  *
  * @param iFactory [in]
	*   The factory, used to create new gemetry.
	* @param iConfig [in]
	*   Define the versionning level
  * @param iSurface [in]
  *   The surface to convert
  *   Limitation (No permanent) : Only NURBS Surface
  *
  * @return
  *   A Plane, if there is no result, it is a NULL pointer
  *
  */
  static CATPlane * IsPlaneSurf(CATGeoFactory * iFactory,
													      CATSoftwareConfiguration *iConfig,
													      CATSurface *iSurface); 

  static void ClonePCurve(CATGeoFactory * iFactory,CATSoftwareConfiguration * iSoftwareConfiguration, 
											  CATPCurve * iPCurve , 
											  const CATCrvLimits& iLimits, 
											  CATSurface * iSurf,
											  CATPCurve * &oPCurve , 
											  CATCrvLimits &oLimits);

  
  static CATMathPolynomX* HermiteInterpolate(const double FirstParameter, 
                                             const double LastParameter, 
                                             const CATLONG32 FirstOrder, 
                                             const CATLONG32 LastOrder, 
                                             const double* FirstConstr,
                                             const double* LastConstr);


  /** 
  * Compute the offset max on the whole surface
  *
  * @param iFactory [in]
  *   The factory 
  * @param iConfig [in]
  *   The software configuration
  * @param iSurface [in]
  *   The surface
  * @param oResultOffset1 [out]
  *   The max offest on one side
  * @param oResultOffset2 [out]
  *   The max offest on another side
  *
  * @return
  *   0 : OK
  :   >0 : Erreur
  *
  */
  static int ComputeOffsetMax(CATGeoFactory * iFactory,
                             CATSoftwareConfiguration* iConfig, 
                             CATSurface * iSurface,
                             double& oResultOffset1,
                             double& oResultOffset2);

   /** 
   * Compute isoparametric curve 's length
   *
   * <br><b>Role</b>: Compute the lenght of the both isoparametric curve at one Point on Surface.
   *
   * @param iSurf [in]
   *   The support surface
   * @param iSurParam [in]
   *   The parameter role...
   * @param iFactory [in]
   *   The Factory to use
   * @param iConfig [in]
   *   The Software Configuration to use
   * @param iTol [in]
   *   Tolerance for the length computation
   * @param olgIsoU [out]
  *   The lenghth of the curve Iso-U
   * @param olgIsoV [out]
   *   The lenghth of the curve Iso-V
   * @param iSurLim [in]
   *   The parametric limits of the surface
   *
   * @return
  *   0 : OK
  :   >0 : Erreur
   *
   */
   static int CheckLgIso(CATSurface * iSurf, const CATSurParam & iSurParam, CATGeoFactory * iFactory, 
                        CATSoftwareConfiguration * iConfig, double & iTol, 
                        double & olgIsoU, double & olgIsoV, CATSurLimits *iSurLim=0);
													 
};

#endif

