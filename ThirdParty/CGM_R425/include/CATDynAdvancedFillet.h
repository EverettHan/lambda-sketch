// !!! CGMITF !!! #ifndef CATDynAdvancedFillet_H
#define CATDynAdvancedFillet_H

// COPYRIGHT DASSAULT SYSTEMES  2003

#include "CATDynFillet.h"
#include "AdvancedFillet.h"
#include "CATFreeFormDef.h"
#include "CATFilletVariousParameters.h"
#include "CATDynFilletVertexRibbonOrder.h"
#include "CATLISTP_CATMathPoint.h"
#include "CATLISTP_CATMathDirection.h"
#include "ListPOfCATEdge.h"
#include "CATDynEdgeFilletRibbon.h"

class CATGeoFactory;
class CATBody;
class CATTopData;
class CATDynSolidFilletCGM;
class CATFilletCrossPartingLinker;
class CATGeoFactory;
class CATTopData;
class CATFilletVariousParameters;
class CATRibbonsReorderTracker;
class CATMathPoint;

/**
* Class defining an operator to create a fillet.
* This operator offers more capabilities than <tt>CATICGMDynFillet</tt> and 
* might be able to generate a result in cases where <tt>CATICGMDynFillet</tt> could fail.
* <br>
* <br>
* The <tt>CATDynAdvancedFillet</tt> operator follows the global frame of the topological
* operators and satisfies the smart mechanism: 
* the input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>A <tt>CATDynAdvancedFillet</tt> operator is created with the <tt>CATCreateDynAdvancedFillet</tt> global function:
* It must be directly deleted after use. It is not streamable. 
* <li>Options must be precised (such as the faces or edges to fillet) with the appropriate methods, before
* asking for the computation with the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
* </ul>
*/
class ExportedByAdvancedFillet CATDynAdvancedFillet : public CATDynFillet
{
  CATCGMVirtualDeclareClass(CATDynAdvancedFillet);
public:
  
  /**
   * Sets internal continuity level of fillet ribbon
   * @param iContinuityLevel
   * Continuity level requested. Use either CATFrFPointCont or CATFrFTangentCont. Default is CATFrFPointCont.
   * @param iTolerance
   * Maximum deformation allowed to achieve the continuity. Not used as of now.
   */
  void SetContinuityLevel(const CATFrFContinuity  iContinuityLevel, // CATFrFPointCont or CATFrFTangentCont
                          const CATPositiveLength iTolerance = 0.); // Default = approximation not allowed
  
  /**
  * @nodoc
  */
  void SetRadiusLawMode(const CATLONG32 iRadiusLawMode);

  virtual ~CATDynAdvancedFillet();

  /**
  * @nodoc
  */
  void SetFilletVariousParameters(const CATFilletVariousParameters* iFilletParams);


  /**
  * Defines a face or plane to stop the fillet. 
  * @param iBody
  * The body which contains the shell used as a limiting element.
  * @param iSkin
  * The shell to be used as a limiting element.
  * @param iOrientation
  * The orientation of the edge with respect to the limiting element.
  * @param iSmartCrossParting
  * The parting option:
  * <ul>
  * <li> 0: no parting
  * <li> 1: parting is activated
  * </ul>
  */
  /** @nodoc */
  virtual void AddLimitingElement (CATBody* iBody, CATDomain* iSkin , const CATOrientation iOrientation);

  /** @nodoc */
  virtual void AddLimitingElement (CATBody* iBody, CATDomain* iSkin , const CATOrientation iOrientation, 
                                   const int iSmartCrossParting);

  /**
  * @nodoc
  */
  void CreateLimitingBodiesFrom(const CATLISTP(CATMathPoint) &iPoints, const CATLISTP(CATMathDirection) &iDirections, const CATListOfInt * iListOfInfo = NULL);

  /**
  * @nodoc
  */
  void CreateCallBackForG1Tracks();

  /**
  * @nodoc
  */
  HRESULT ConvertSetbacksFromRelativeToAbsolute(const CATLISTP(CATDynEdgeFilletRibbon) & iRibbonsList,
                                                const CATListOfDouble * iRelativeSetbacks,
                                                CATListOfDouble & ioAbsoluteSetbacks,
                                                CATLISTP(CATEdge) & ioEdgesList,
                                                CATListOfDouble & ioRatioList,
                                                CATListOfInt & ioDirectionList,
                                                CATMathPoint * iCommonVtxMathPoint = NULL);
  /**
  * @nodoc
  */
  void SetCollisionCheckMode (CATBoolean iCollisionCheckMode);

  /**
  * @nodoc
  */
  void SetMultiRibbonSafeMode (CATBoolean iMultiRibbonSafeMode);

  /**
  * @nodoc
  */
  void SetCreateZeroSetbackDiabolo (CATBoolean iZeroSetbackDiabolo);

  /**
  * @nodoc
  */
  void SetFilletIntersectionMode();

  /**
   * Set fast fillet preview
   */
  void SetFastPreview();

  /**
  *	Setting the FilletLongPropagation option on allows controlling the relimitation of the fillet 
  * in case it encounters a sharp edge on one support and then a smooth edge on the second 
  * support in the relimitation zone. Without this option, the fillet is extrapolated 
  * after the second smooth edge and the relimitation may be sharp but will be shorter. 
  * If the option is activated, the fillet will be able to roll on to the next support after 
  * the smooth edge and thus will offer a smooth relimitation at the cost of its length.
  * This option is de-activated by default.
  */
  void SetFilletLongPropagation();

  /**
  * @nodoc
  */
  void SetFlatEnding();

  /**
  * To keep features that are entirely engulfed by the result of a fillet operation the method SetKeepFeature should be used.
  * @param iKeepFeature
  * Keep feature option: CATTrue – feature kept; CATFalse – feature not kept. 
  * By default a fillet operation does not keep any feature that isn’t interfering with the boundary of the fillet. 
  */
  void SetKeepFeature( CATBoolean iKeepFeature );

    /**
  * @nodoc
  */
  void SetVariableJointEnabled( CATBoolean iSmoothCornerPreferred );

  /**
  * @nodoc
  */
  void SetSmoothCornerPreferred( CATBoolean iSmoothCornerPreferred );

  /**
  * @nodoc
  */
  void SetCrossPartingLinker(CATFilletCrossPartingLinker* iLinker = NULL); 

  /**
  * @nodoc
  */
  void SetVertexRibbonOrderList(CATLISTP(CATDynFilletVertexRibbonOrder) &iVertexRibbonOrderList);

  /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO LIVEFILLET<br>
  * Assign a Ribbons Reorder Tracker.
  */
  void SetRibbonsReorderTracker(CATRibbonsReorderTracker* iTracker); 

  /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO AUTOFILLET<br>
  * Does not simplify the possible fat edges bounding the computed ribbon.
  */
  void DisableFatEdgesSimplification();

   /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO AUTOFILLET.
  */
  void DisableRelimitation(CATBoolean iDisableRelimitation);

  /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO AUTOFILLET.
  */
  void AddSupportJournalInfo(CATBoolean iAddSupportJournalInfo);

   /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO AUTOFILLET.
  */
  void EnableSuperMaxOption(CATBoolean iEnableSuperMaxOption);

   /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO AUTOFILLET.
  */
  void SetBestInInSelectionPoint(CATMathPoint &iBestInInSelectionPoint);

   /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO AUTOFILLET.
  */
  virtual CATBoolean IsUntwistFillFunctionUsed () const;

   /**
  * @nodoc
  * INTERNAL USE. 
  * Activates support curvature control to filter ribbons crossing support skin .
  */ 
  void SetSupportCurvatureCheck();

   /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO AUTOFILLET.
  * Activate new tritangent fillet algorithm.
  */
  void SetDoubleCircleTritangentFilletMode();

  /* Do not use */
  CATDynAdvancedFillet(CATGeoFactory* iContainer, CATTopData* iData, CATDynSolidFilletCGM* iImplementation);

  /**
  * @nodoc
  * When several ribbons are possible in a FaceFace Fillet, 
  * use a Help Point to choose the edge where the ribbon must be computed.
  */
  virtual void SetHelpPoint(CATMathPoint &iHelpPoint);

  /**
  * @nodoc
  * Allow or forbid (default) use of DRep information. 
  */
  virtual void SetLiveBodyAllowed(CATBoolean iLiveBodyAllowed);

  /**
   * If CATDynImplicitKeepEdgeMode has been specified for edge fillet ribbons, use the 
   * specified CATDynKeepEdgeSameConvexityMode also for potential implicit keep edges.
   * @param iUseKeepEdgeSameConvexityMode
   * <ul>
   * <li> FALSE: Turn the mode off
   * <li> TRUE : Turn the mode on
   * </ul>
   */
  void UseKeepEdgeSameConvexityModeForImplicitKeepEdges(CATBoolean iUseKeepEdgeSameConvexityMode);

public:
  // IZE wk. 01 2010 IR 021460 Some checks are too restrictive for SheetMetal configurations
   /**
   * @nodoc
   */
  void SetUnplugChecksForSheetMetal(CATBoolean iUnplugChecksForSheetMetal);

  // IZE Redefinition of ValidateTopOutput method to test the evaluation of the radius
   /**
   * @nodoc
   */
  CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent,CATCGMOutput& os);



};

/**
 * Creates a CATDynAdvancedFillet operator.
 * @param iContainer
 * The factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.  
 * @param iPart
 * The pointer to the body to fillet. 
 * When set to <tt>NULL</tt>, the different ribbons can be defined on several bodies.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByAdvancedFillet CATDynAdvancedFillet* CATCreateDynAdvancedFillet(CATGeoFactory* iContainer,
                                                                          CATTopData*    iData,
                                                                          CATBody*       iPart=NULL);

/** @nodoc */
ExportedByAdvancedFillet CATDynFillet* CATCreateAdvancedDynFillet(CATGeoFactory* iContainer,
                                                                  CATTopData*    iData,
                                                                  CATBody*       iPart,
                                                                  CATBoolean     iMultiRibbSafeMode);
// !!! CGMITF !!! #endif
