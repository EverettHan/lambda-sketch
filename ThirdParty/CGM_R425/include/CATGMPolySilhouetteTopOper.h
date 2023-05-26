/* -*-C++-*-*/
#ifndef CATGMPolySilhouetteTopOper_H
#define CATGMPolySilhouetteTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2019
//
// CATGMPolySilhouetteTopOper
//
// DESCRIPTION :
// Compute the silhouette of a given list of polyhedral bodies on a planar screen.
// Polyhedral delegation of CATTopSilhouette operator for a subset of options only
//
//=============================================================================
//
// History
//
// August 2019 DPS Creation without implementation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyProject.h"            // ExportedBy

#include "CATTopSilhouetteType.h"

#include "CATDataType.h"              // HRESULT
#include "CATTopDefine.h"             // CATSide
#include "CATMathInline.h"            // inline Methods

#include "ListPOfCATBody.h"

#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATDomain;
class CATWire;
class CATGMPolySilhouetteTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyProject CATGMPolySilhouetteTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolySilhouetteTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolySilhouetteTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolySilhouetteTopOper() method to create an instance
  static CATGMPolySilhouetteTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolySilhouetteTopExt & iExtension);


  //=============================================================================
  // Settings from public & CAA APIs available through CATICGMTopSilhouette
  //=============================================================================

  /**
  * Sets the operator to project shadows on a planar screen whose the normal is the projection direction.
  * @param iScreenBody
  *   The infinite planar screen to project the shadows.
  * @param iLightSourceInFront
  *   The side from which the light comes : 
  *   This side influences the location of points on the boundary of the shadow.
  *   <li> <tt>TRUE</tt> if the planar normal direction shows the light source.
  *   <li> <tt>FALSE</tt> if the light source is behind the screen.
  * @return
  */
  void SetProjectionScreenForShadows(CATBody *iScreenBody, CATBoolean iLightSourceInFront);

  /**
  * Sets the operator to project shadows on a planar screen whose the normal is the projection direction.
  * @param iScreenPlane
  *   The infinite planar screen to project the shadows.
  * @param iLightSourceInFront
  *   The side from which the light comes : 
  *   This side influences the location of points on the boundary of the shadow.
  *     <li> <tt>TRUE</tt> if the planar normal direction shows the light source.
  *     <li> <tt>FALSE</tt> if the light source is behind the screen.
  * @return
  */
  void SetProjectionScreenForShadows(const CATMathPlane &iScreenPlane, CATBoolean iLightSourceInFront);


  //=============================================================================
  // Settings from protected & CAA APIs available through CATIPGMTopSilhouette
  //=============================================================================

  // ----------------------------------------------------------------------------
  // 1. View definition 
  // -> The caller has to choose exclusively between perspective and parallel view
  // -> In PHM, both parallel & conical view modes are available, but only if a planar screen has been defined


  // PERSPECTIVE VIEW (conical view)
  // ----------------
  //
  // This call defines EXPLICITLY the conical view by the point of view from which the observer can see the 3D scene.
  // In this case, the 3D scene has to be totally contained by one half of the full 3D space around the view point.
  //
  void SetViewPoint(const CATMathPoint &iPt);


  // PARALLEL VIEW (cylindrical view)
  // -------------
  //
  // This call defines EXPLICITLY the cylindrical view by the direction used to observe the 3D scene.
  // This set is NOT MANDATORY : another way to define IMPLICITLY the cylindrical view consists in 
  // calling SetShadowScreen() method, setting the "iViewSide" option to +1 or -1. 
  //
  void SetViewDirection(const CATMathDirection &iDir);


  // Disable the reflect line computation
  // -------------
  //
  // If the Input model is already disconnected by the silhouette (with the partingline algorithm)
  // it's not neccessary to compute the reflectline and to disonnect the model again.
  // This option is an expert option because if the model is not disconnect before calling the TopSilhouette operator
  // the result will be wrong.
  //
  /* Not available in PHM
  void DisableReflectLineComputation();
  */

  // ----------------------------------------------------------------------------
  // 2. Screen definition [ OPTION FOR PARALLEL VIEW ONLY ]
  // -> Without any screen definition, the result will contain 3D edges (no projection)
  // SetShadowScreen() method definition 
  // ---------------
  // 
  // iScreenBody has to contain a single infinite planar face
  // All 3D silhouettes will be projected on this ScreenBody
  //
  // iOutputDim has to be set to 1 (the result will be a set of silhouette edges) 
  //                          or 2 (the result will be a set of faces bounded by silhouettes)
  //
  // iViewSide allows to define IMPLICITLY the cylindrical view,
  // if "iViewSide" variable is set to +1 or -1. 
  // In this case, the view direction will be logicaly orthogonal to the planar Body 
  // and its orientation will depend on the "iViewSide" value.
  // iViewSide will be ignored in case of conflictual call with SetViewDirection() method
  //
  /** @nodoc 
  */
  void SetShadowScreen(CATBody *iScreenBody, int iOutputDim, int iViewSide = 0);

  // ----------------------------------------------------------------------------
  // 3. Silhouette filter specification [ OPTION FOR BOTH PERSPECTIVE AND PARALLEL VIEW MODES]
  // CATInnerSilhType is not available in PHM
  // -> The default behavior consists in building the most complete result as possible, 
  //    containing 2 types of silhouette : CATExternalSilhType + CATInternalSilhType
  // Possibility to specify the types of silhouette to keep in the final result
  // -> SetSilhouetteSelectionMode(CATExternalSilhType + CATInternalSilhType)
  //    leads to elimate all silhouettes inner to the shadow faces
  // -> SetSilhouetteSelectionMode(CATExternalSilhType) leads to fill all shadows,
  //    removing both inner silhouettes and internal loops of shadow faces
  //
  /** @nodoc 
  */
  void SetSilhouetteSelectionMode(int iSilhTypes);

    

  //=============================================================================
  // Other settings
  //=============================================================================
  
  /**
  * Sets the operator to return wires instead of faces : 
  * those wires are equivalent to the loops bounding the shadow faces
  * and will contain all the external silhouettes, plus the internal silhouettes if the option FillHoles is disabled
  * @return
  */  
  void EnableWireMode();

  // Option considering the infinite planar surface as reference for generated geometries : 
  // -> leads to generate CATGeoPolyCurveOnPlane objects instead of CATGeoPolyCurve objects associated to the projected edges
  void EnablePlanarModeling();

  // Activate the generation of "LyingOn" links between the projected result body and the input screen
  // this mode is disabled by default if not specified by the caller
  // This option can not be enabled if no infinite planar body has been specified as screen before the computation :
  // -> Please call also SetShadowScreen(CATBody *iScreenBody,...) or SetProjectionScreenForShadows(CATBody *iScreenBody,...)
  void SetLyingOnMode(CATBoolean iLyingOnMode);


  //=============================================================================
  // Get (from protected APIs available through CATIPGMTopSilhouette)
  //=============================================================================

  // ----------------------------------------------------------------------------
  // Service to call after the CATIPGMTopSilhouette computation
  // Get the type of silhouette ('CATExternalSilhType' Or 'CATInternalSilhType' Or 'CATInnerSilhType') 
  // for an output Wire (owned by the result Body returned by GetResult())
  //
  // Returns 'CATUnknownSilhType' enum in case of failure
  //
  /** @nodoc 
  */
  void GetOutputDomainType(CATWire *iOutputWire, int &oSilhDomainType);


  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();
  /** @nodoc
   * @nocgmitf
  */

protected:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolySilhouetteTopOper() method to create an instance
  CATGMPolySilhouetteTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolySilhouetteTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolySilhouetteTopOper();
  CATGMPolySilhouetteTopOper(const CATGMPolySilhouetteTopOper& iOneOf); 
  CATGMPolySilhouetteTopOper& operator =(const CATGMPolySilhouetteTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolySilhouetteTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBody
 * The pointer to the body whose sihouette needs to be computed.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyProject CATGMPolySilhouetteTopOper * CATCreatePolySilhouetteTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iInputBody);


/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolySilhouetteTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iInputBodies
 * The list of bodies whose sihouette needs to be computed.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyProject CATGMPolySilhouetteTopOper * CATCreatePolySilhouetteTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, ListPOfCATBody & iInputBodies);


#endif
