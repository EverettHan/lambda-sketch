#ifndef CATTopSilhouette_H
#define CATTopSilhouette_H

#include "CATTopSilhOperator.h"   // derivation
#include "AdvThickness.h"         // exportation
#include "CATTopSilhouetteType.h" // enum

#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATTopSilhouetteImpl;
class CATMathPoint;
class CATMathDirection;
class CATMathPlane;
class CATBody;
class CATDomain;


/**
* Class defining the operator that computes the silhouette for a given body.
*<br>
* It follows the general frame of all operators and satisfies the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>CATTopSilhouette is created with the CATCreateTopSilhouette global function. 
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopSilhouette
*/
class ExportedByAdvThickness CATTopSilhouette : public CATTopSilhOperator
{
  CATCGMVirtualDeclareClass(CATTopSilhouette);

public:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreateTopSilhouette() method to create an instance
  CATTopSilhouette(CATGeoFactory        * iFactory,
                   CATTopData           * iTopData,
                   CATTopSilhouetteImpl * iImpl   );


  // Destructor
  virtual ~CATTopSilhouette();


/** @name Shadows generation Method
  @{ */

  /**
  * Sets the operator to project shadows on a planar screen whose the normal is the projection direction.
  * @param iScreenBody
  *   The infinite or trimmed planar screen to project the shadows.
  * @param iLightSourceInFront
  *   The side from which the light comes : 
  *   This side influences the location of points on the boundary of the shadow.
  *   <li> <tt>TRUE</tt> if the planar normal direction shows the light source.
  *   <li> <tt>FALSE</tt> if the light source is behind the screen.
  * @param iFillHoles
  *   If this optional argument is set to TRUE, the holes inside the shadows will be filled 
  *   and each returned face will be bounded by a single external loop, ignoring the internal silhouettes
  * @return
  */
  virtual void SetProjectionScreenForShadows(CATBody * iScreenBody, CATBoolean iLightSourceInFront, CATBoolean iFillHoles = FALSE);


  /**
  * Sets the operator to project shadows on a planar screen whose the normal is the projection direction.
  * @param iScreenPlane
  *   The infinite planar screen to project the shadows.
  * @param iLightSourceInFront
  *   The side from which the light comes : 
  *   This side influences the location of points on the boundary of the shadow.
  *   <li> <tt>TRUE</tt> if the planar normal direction shows the light source.
  *   <li> <tt>FALSE</tt> if the light source is behind the screen.
  * @param iFillHoles
  *   If this optional argument is set to TRUE, the holes inside the shadows will be filled 
  *   and each returned face will be bounded by a single external loop, ignoring the internal silhouettes
  * @return
  */
  virtual void SetProjectionScreenForShadows(const CATMathPlane &iScreenPlane, CATBoolean iLightSourceInFront, CATBoolean iFillHoles = FALSE);

  /**
  * Sets the operator to return wires instead of faces : 
  * those wires are equivalent to the loops bounding the shadow faces
  * and will contain all the external silhouettes, plus the internal silhouettes if the option FillHoles is disabled
  * @return
  */  
  virtual void EnableWireMode();


/** @} */


  // ----------------------------------------------------------------------------
  // 1. View definition 
  
  // -> The caller has to choose exclusively between perspective and parallel view


  // PERSPECTIVE VIEW (conical view)
  // ----------------
  //
  // This call defines EXPLICITLY the conical view by the point of view from which the observer can see the 3D scene.
  // In this case, the 3D scene has to be totally contained by one half of the full 3D space around the view point.
  //
  /** @nodoc 
  */
  void SetViewPoint(const CATMathPoint &iPt);


  // PARALLEL VIEW (cylindrical view)
  // -------------
  //
  // This call defines EXPLICITLY the cylindrical view by the direction used to observe the 3D scene.
  // This set is NOT MANDATORY : another way to define IMPLICITLY the cylindrical view consists in 
  // calling SetShadowScreen() method, setting the "iViewSide" option to +1 or -1. 
  //
  /** @nodoc 
  */
  void SetViewDirection(const CATMathDirection &iDir);

  
  // Disable the reflect line computation
  // -------------
  //
  // If the Input model is already disconnected by the silhouette (with the partingline algorithm)
  // it's not neccessary to compute the reflectline and to disonnect the model again.
  // This option is an expert option because if the model is not disconnect before calling the TopSilhouette operator
  // the result will be wrong.
  //
  /** @nodoc 
  */
  void DisableReflectLineComputation();

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
  void SetShadowScreen(CATBody * iScreenBody, int iOutputDim, int iViewSide=0);



  // ----------------------------------------------------------------------------
  // 3. Silhouette filter specification [ OPTION FOR BOTH PERSPECTIVE AND PARALLEL VIEW MODES]

  // -> The default behavior consists in building the most complete result as possible, 
  //    containing the 3 types of silhouette : 
  //         CATExternalSilhType, 
  //         CATInternalSilhType,
  //         CATInnerSilhType,
  //    excepted for a result with shadows faces (iOutputDim==2) where inner silhouettes are 
  //    automatically removed.

  // Possibility to specify the types of silhouette to keep in the final result
  // -> SetSilhouetteSelectionMode(CATExternalSilhType + CATInternalSilhType)
  //    leads to elimate all silhouettes inner to the shadow faces
  // -> SetSilhouetteSelectionMode(CATExternalSilhType) leads to fill all shadows,
  //    removing both inner silhouettes and internal loops of shadow faces
  //
  // The "iStoreOutputDomainTypes" option enables the knowledge of the silhouette type for each output Domain
  // and allows the call to the "GetOutputDomainType()" function after the CATTopSilhouette computation
  //
  /** @nodoc 
  */
  void SetSilhouetteSelectionMode(int iSilhTypes, int iStoreOutputDomainTypes=0);



  // ----------------------------------------------------------------------------
  // Runs the operator
  /** @nodoc
   * @nocgmitf
  */
  virtual int RunOperator();



  // ----------------------------------------------------------------------------
  // Option to call after the CATTopSilhouette compuation
  // But which requires to be enabled by SetSilhouetteSelectionMode(..., 1) before computation
  //
  // Get the type of silhouette ('CATExternalSilhType' Or 'CATInternalSilhType' Or 'CATInnerSilhType') 
  // for an output Domain (owned by the result Body returned by GetResult())
  //
  // Returns 'CATUnknownSilhType' enum if this option is disabled (default mode)
  //
  /** @nodoc 
  */
  void GetOutputDomainType(CATDomain * iOutputDomain, int &oSilhDomainType);



  // ------------------
  // CGMReplay Methodes
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString *GetDefaultOperatorId();
  /** @nodoc
   * @nocgmitf
  */
  const CATString * GetOperatorId();
  /** @nodoc
   * @nocgmitf
  */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc
   * @nocgmitf
  */
  void WriteInput(CATCGMStream  & Str);
  /** @nodoc
   * @nocgmitf
  */
  void Dump( CATCGMOutput& os ) ;
    /** @nodoc
   * @nocgmitf
  */
  void DumpOutput( CATCGMOutput& os ) ;
  /** @nodoc
   * @nocgmitf
  */
  void RequireDefinitionOfInputAndOutputObjects();


protected:


  /** @nodoc 
  * cannot be called
  */
  // Internal implementation
  CATTopSilhouetteImpl * GetTopSilhouetteImpl();
};

/**
 * Creates a CATTopSilhouette operator.
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
ExportedByAdvThickness
CATTopSilhouette * CATCreateTopSilhouette(CATGeoFactory  * iFactory    ,
                                          CATTopData     * iTopData    ,
                                          CATBody        * iBody       );

/**
 * Creates a CATIPGMTopSilhouette operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iInputBodies
 * The list of bodies to compute silhouettes 
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByAdvThickness 
CATTopSilhouette * CATCreateTopSilhouette(CATGeoFactory           * iFactory    ,
                                          CATTopData              * iTopData    ,
                                          const CATLISTP(CATBody) & iInputBodies);

/**
 * DEPRECATED: Do not use, use CATCGMCreateTopSilhouette with a 'const CATLISTP(CATBody) &' as argument instead
 */
ExportedByAdvThickness
CATTopSilhouette * CATCreateTopSilhouette(CATGeoFactory  * iFactory    ,
                                          CATTopData     * iTopData    ,
                                          ListPOfCATBody * iInputBodies);

#endif

