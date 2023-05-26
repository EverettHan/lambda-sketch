#ifndef CATTopBlend_h
#define CATTopBlend_h

// COPYRIGHT DASSAULT SYSTEMES  2000

/**
* @level Protected
* @usage U1
*/ 

#include "FrFTopologicalOpe.h"
#include "CATTopOperator.h"
#include "CATListOfCATGeometries.h"
#include "CATBlendValue.h"
#include "CATIACGMLevel.h"
#include "CATTopBlendCouplingMode.h"
#include "CATTopBlendBehaviour_Mode.h"

class CATLaw;
class CATFrFSweepChecker;
class CATMathPoint;
/**
  * Class defining the topological operator that connects two wires with a skin.
  * <br> Continuity criteria can be precised: G0, G1 or G2 if the supporting surfaces of the wires
  * are given, G0 otherwise.
  * <br>The CATTopBlend operator creates the resulting blend
  * separately from the inputs: the topology of the input bodies is not used to define the topology
  * of the resulting body.  
  *<ul>
  * <li>A CATTopBlend operator is created with the <tt>CATCreateTopBlend</tt> global method;
  * it must be directly <tt>delete</tt>d after use. It is is not streamable. 
  *<li>Options can be precised with the <tt>SetXxx</tt> methods, before
  * asking for the computation with the <tt>Run</tt> method. 
  * <li>The resulting body is retrieved with the <tt>GetResult</tt> method.
  *</ul>
  */

class ExportedByFrFTopologicalOpe CATTopBlend :public CATTopOperator

{
  CATCGMVirtualDeclareClass(CATTopBlend);
  public: 
          virtual ~CATTopBlend              ();
/**
  * Constructor. Cannot be called. Use the <tt>CATCreateTopBlend</tt> global function
  * to create a CATTopBlend operator.
*/
                   CATTopBlend              (     CATGeoFactory           *  iFactory                  ,
                                                  CATTopData              *  iTopData                  );


/**
  * Defines the continuity criteria to take into account for a given wire (<tt>ADVANCED mode</tt>).
  * @param iWhichWire
  * The first (1) or the second (2) input wire.
  * @param iTransitionContinuity
  * The continuity criteria.
  * <br><b>Legal values</b>: <tt>0</tt> for G0 continuity, <tt>1</tt> for G1 continuity, 
  * <tt>2</tt> for G2 continuity.
  */
  virtual void     SetTransitionContinuity(       int                        iWhichWire                ,
                                                  int                        iTransitionContinuity     )        = 0; // 0- G1 1-G1 2-G2
  
/**
  * Defines the orientation of the wire to be used by <tt>this</tt> operator(<tt>ADVANCED mode</tt>).
  * @param iWhichWire
  * The first (1) or the second (2) input wire.
  * @param iWireOrientation
  * The orientation.
  * <br><b>Legal values</b>: <tt>1</tt> the natural orientation of the <tt>iWhichWire</tt> wire is used,
  * <tt>-1</tt> for the opposite orientation.
  */ 
  virtual void     SetWireOrientation       (     int                        iWhichWire                ,
                                                  int                        iWireOrientation          )        = 0;

/**
  * Returns the orientation of the wire used by <tt>this</tt> operator.
  * @param iWhichWire
  * The first (1) or the second (2) input wire.
  * @return 
  * The orientation.
  * <br><b>Legal values</b>: <tt>1</tt> the natural orientation of the <tt>iWhichWire</tt> wire is used,
  * <tt>-1</tt> for the opposite orientation.
  */ 
  virtual int      GetWireOrientation       (     int                        iWhichWire                )        = 0;

/**
  * Retrieves the default WireOrientation defined by <tt>this</tt> operator.
  * <br>The operator does an analysis of the inputs, in order to avoid twisted surfaces for examples.
  * This method returns the orientation found after this analysis.
  * @param iWhichWire
  * The first (1) or the second (2) input wire.
  * @return
  * The default wire orientation.
  * <br><b>Legal values</b>: <tt>1</tt> the natural orientation of the <tt>iWhichWire</tt> wire is used,
  * <tt>-1</tt> for the opposite orientation.
  */
  virtual int      GetDefaultWireOrientation(     int                        iWhichWire                )        = 0;
  
/**
  * Set the TransitionOrientation used by <tt>this</tt> operator.
  * Let <tt>T</tt> be the tangent to the wire, 
  * and <tt>N</tt> be the normal to the skin body.
  * The transition orientation defines how the blend goes from the initial wires: it takes the 
  * direction of <tt>oTransitionOrientationSide*(T^N)</tt>, where <tt>^</tt> is the vectorial product.
  * @param iWhichWire
  * The first (1) or the second (2) input wire.
  * @param TransitionOrientation
  * The transition orientation.
  * <br><b>Legal values</b>: <tt>1</tt> the direction of <tt>oTransitionOrientationSide*(T^N)</tt> 
  * <tt>iWhichWire</tt> wire is used,
  * <tt>-1</tt> for the opposite orientation.
  */ 
  virtual void     SetTransitionOrientation(      int                        iWhichWire                ,
                                                  int                        TransitionOrientation     )        = 0;
  
/**
  * Get the TransitionOrientation used by <tt>this</tt> operator.
  * @param iWhichWire
  * The first (1) or the second (2) input wire.
  * @return
  * The transition orientation.
  * <br><b>Legal values</b>: <tt>1</tt> the direction of <tt>oTransitionOrientationSide*(T^N)</tt> 
  * <tt>iWhichWire</tt> wire is used,
  * <tt>-1</tt> for the opposite orientation.
  */ 
  virtual int      GetTransitionOrientation      (int                        iWhichWire                )        = 0;
  
  
/**
  * Retrieves the default TransitionOrientation defined by <tt>this</tt> operator.
  * <br>The operator does an analysis of the inputs, in order to avoid twisted surfaces for examples.
  * This method returns the orientation found after this analysis.
  * @param iWhichWire
  * The first (1) or the second (2) input wire.
  * @return
  * The default transition orientation.
  * <br><b>Legal values</b>: <tt>1</tt> the direction of <tt>oTransitionOrientationSide*(T^N)</tt> 
  * <tt>iWhichWire</tt> wire is used,
  * <tt>-1</tt> for the opposite orientation.
  */

  virtual int      GetDefaultTransitionOrientation(int                       iWhichWire                )        = 0;
/**
 * @nodoc
  // iMode: 1-tangent 2-normal 
 */
  virtual void     SetTangencyDirection     (     int                        iMode                     = 1    ) = 0; 

  /**
  * Specifies where the blend boundaries are to be tangent to 
  * the support boundaries.
  * <br>Warning: This 
  * method is inoperative when the wires to be connected are not layed down onto their supports. 
  * To lay down the wires onto their supports, you must use either the CATHybProject or CATLayDownOperator operators.
  * @param iWhichWire
  * The first (1) or the second (2) input wire. 
  * If the coupling mode is set to CATTopBlendCouplingMode_Develop, iWhichWire is the guide number 
  * whose extremity vertex relimits the coupling (the extremity on the other guide is free).
  * @param iStartEnd
  * The start (1) or the end (2) extremity where the border mode is to be applied.
  * @param iMode
  * <dl>
  * <dt>1
  * <dd>tangent mode.
  * <dt>2
  * <dd>normal mode.
  * </dl>
  * If the coupling mode is set to CATTopBlendCouplingMode_Develop:
  * <dl>
  * <dt>0
  * <dd>until extremity vertices on all guides.
  * <dt>1
  * <dd>until extremity vertex of iWhichWire.
  * <dt>2
  * <dd>the best solution.
  * </dl>
  */
  virtual void     SetBorderMode            (     int                        iWhichWire                ,
                                                  int                        iStartEnd                 ,
                                                  int                        iMode                     = 1    ) = 0; 
/**
 * @nodoc
  // OLD Ne Fait plus rien
 */
  virtual void     SetBorderMode            (     int                        iMode                     = 1    ) = 0; 


/**
 * Coupling modes.
 * @param CATTopBlendCouplingMode_DomainG0
 * Standard coupling: by curvilinear length.
 * @param CATTopBlendCouplingMode_DomainG1
 * G1 coupling: in each domain, coupling of the vertices of G0 and
 * not G1 continuity.
 * @param CATTopBlendCouplingMode_DomainG2
 * G1 and then G2 coupling: after a G1 coupling, the
 * G2 coupling is done (vertices of G1 and not G2 continuity) in
 * each domain defined by the G1 coupling.
 * @param CATTopBlendCouplingMode_Edge
 * Vertex coupling: coupling is carried out edge-by-edge. You must 
 * have the same number of vertices on each wire.
 * @param CATTopBlendCouplingMode_Spine
 * Need to use the SetSpine Option 
 * @param CATTopBlendCouplingMode_Develop
 * Points are coupling to minimize Gaussian Curvature of the surface
 * Only with Blend G0G0 continuity
 * @param CATTopBlendCouplingMode_NoTwist
 * NOT TO BE USED.
 */

 typedef enum 
    {
      CATTopBlendCouplingMode_DomainG0 = ::CATTopBlendCouplingMode_DomainG0,
      CATTopBlendCouplingMode_DomainG1 = ::CATTopBlendCouplingMode_DomainG1,
      CATTopBlendCouplingMode_DomainG2 = ::CATTopBlendCouplingMode_DomainG2,
      CATTopBlendCouplingMode_Edge     = ::CATTopBlendCouplingMode_Edge    ,
      CATTopBlendCouplingMode_Spine    = ::CATTopBlendCouplingMode_Spine   ,
      CATTopBlendCouplingMode_Develop  = ::CATTopBlendCouplingMode_Develop ,
      CATTopBlendCouplingMode_NoTwist  = ::CATTopBlendCouplingMode_NoTwist
    } 
  CATTopBlendCouplingMode ;
/**
 * Defines the coupling mode.
 * @param iMode
 * The coupling mode.
 */
  virtual void     SetCouplingMode          (     CATTopBlendCouplingMode    iMode                     )        = 0;
  
/**
 * Defines coupling lines.
 * @param iCouplingLines
 * The list of pointers to the coupling lines (wire bodies).
 */
  virtual void     SetCouplingLines         (     CATLISTP(CATGeometry)   *  iCouplingLines            )        = 0;

/**
 * @nodoc
 */

  virtual void     SetTensionLaw            (     int                        iWhichWire                ,
                                                  CATLaw                  *  iTensionLaw               )        = 0; 
/**
 * @nodoc
 */
  virtual void     SetTensionLawForCurvature(     int                        iSide                     ,
                                                  CATLaw                  *  iTensionLaw               )        = 0;
/**
 * @nodoc
 */

  virtual CATFrFSweepChecker *GetChecker() = 0;

/**
 * @nodoc
  // iConstructionMode 
  // = 0 : Approximated (geo) default
  // = 1 : Analytic ( Can't handle all inputs !)
  // = 2 : Auto
 */
  virtual void     SetConstructionMode    (       int                        iConstructionMode         )        = 0;
/**
 * @nodoc
 */
  virtual void     GetConstructionMode    (       int                      & oAskedMode                 ,
                                                  int                      & oRunMode                  )        = 0; 
/**
 * @nodoc
//   iOnlyOnIso = CATBlendCrossTgCont = Continuity of the normals to teh surfaces. 
//   iOnlyOnIso = CATBlendProportionalTgCont = Continuity only on Iso
 */
  virtual void     SetTransitionContinuityOnIso( CATBlendTgContMode          iOnlyOnIso                 )       = 0;	
/**
 * @nodoc
 */
  virtual void     SetToleranceForSurfaceCreation(double                     iTol                       )       = 0;

/**
 * @nodoc
  // SectionMode = 0 : Mode GSD
  //             = 1 : Mode FSS   
  //             = 2 : Fillet U
  //             = 3 : Fillet Z
 */
  virtual void     SetSectionForm         (      int                         iSectionForm               )       = 0;

/**
 * @nodoc
 */
  virtual void     SetSpine               (      CATGeometry               * iSpine                     )       = 0 ;


  //-----------------------------------------------------------------------
  //--------------- Methods for behaviour mode management ------------------
  //-----------------------------------------------------------------------
/**
* @nodoc
*/
  typedef enum 
    {
      // Reset to defaut
      // ---------------
      CATTopBlendBehaviour_AllDefaultBehaviour                     = ::CATTopBlendBehaviour_AllDefaultBehaviour,

      // SetTransitionOrientation uses Topological Information (outside Shells)
      // ----------------------------------------------------------------------
      CATTopBlendBehaviour_TopologicalDefaultOrientation           = ::CATTopBlendBehaviour_TopologicalDefaultOrientation,

      // SetTransitionOrientation uses Geometrical Information (minimal surface)
      // -----------------------------------------------------------------------
      CATTopBlendBehaviour_GeometricalDefaultOrientation           = ::CATTopBlendBehaviour_GeometricalDefaultOrientation,

      // FSS only : No Journal :    
      // ---------------------
      CATTopBlendBehaviour_AutorizeNonG0ConstraintOnMonoPCurveWire = ::CATTopBlendBehaviour_AutorizeNonG0ConstraintOnMonoPCurveWire

      // Planar surfaces detection
      // -------------------------
      //CATTopBlendBehaviour_PlanarSurfacesDetection               = CATTopBlendBehaviour_PlanarSurfacesDetection,

      // Canonic surfaces detection
      // --------------------------
      //CATTopBlendBehaviour_CanonicSurfacesDetection              = CATTopBlendBehaviour_CanonicSurfacesDetection
    }
  CATTopBlendBehaviour_Mode ;

/**
 * @nodoc
 * Initialization of one behaviour mode.
 */
  virtual void     SetBehaviourMode       (      CATTopBlendBehaviour_Mode   iMode                      )       = 0;

/**
 * @nodoc
 * Possibility to create or not merged curves between the guides and Blend surface
 * Default is TRUE.
 */
  virtual void     SetCreateMergedCurves  (const CATBoolean                  iCreateMergedCurve         = TRUE) = 0;

/**
 * Defines a smooth option for moving frame, coupling and comb extraction.
 * @param iSmoothOption
 * The smoothing option
 * <br><b>Legal values</b>: <tt>0</tt> no smoothing will be done
 * <tt>1</tt> smoothing will be done.
 * (default mode at operator creation),
 */
  virtual void     SetSmoothOption        (      CATLONG32                   iSmoothOption              = 1)    = 0 ;
  
/**
 * Defines the smooth angle threshold. 
 * @param iSmoothAngleThreshold
 * The threshold for smooth (in radian); any angle below this value will be smoothed
 * if smooth option has been activated by SetSmoothOption method.
 */
  virtual void     SetSmoothAngleThreshold(      double                      iAngleThreshold            )       = 0 ;

/**
 * Defines clean guides option, and clean parameter values. Pointers
 * to parameter values are to be given only when corresponding parameter
 * is redefined, otherwise, standard parameter value will be used. Pointers
 * may contain addresses of local variables that will be lost after call: 
 * parameter values will be copied by this method.
 * @param iCleanOption
 * The cleaning option
 * <br><b>Legal values</b>: <tt>0</tt> no cleaning will be done
 * (default mode at operator creation),
 * <tt>1</tt> cleaning will be done.
 * @param iCleanMaxDeformation
 * The pointer to max deformation authorized.
 * @param iCleanSmallCurvesMaxLength
 * The pointer to maximum length of curves to be kept.
 * @param iCleanCurvatureThreshold
 * The pointer to the curvature threshold.
 */
  virtual void     SetCleanGuidesOption   (      CATLONG32                   iCleanOption               = 0,
                                                 double                   *  iCleanMaxDeformation       = NULL,
                                                 double                   *  iCleanSmallCurvesMaxLength = NULL,
                                                 double                   *  iCleanCurvatureThreshold   = NULL) = 0;


/**
 * Asks for topological lay down to be done internally for all guides with support
 * surfaces.
 * @param iLayDownTolerance
 * The pointer to the lay down tolerance (maximum distance between wire to be laid down
 * and its support surface).
 */
 virtual void      SetLayDownRequest      (      double                   *  iLayDownTolerance          = NULL) = 0 ;

 
/**
 * @nodoc
 */
 virtual void      GetMaxGaussianCurvature(      double                    & MaxGaussianCurvature       , 
                                                 CATMathPoint              & MaxPoisition               ) = 0;
 
};

#endif
