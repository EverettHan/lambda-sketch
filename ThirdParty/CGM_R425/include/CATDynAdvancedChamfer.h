#ifndef CATDynAdvancedChamfer_H
#define CATDynAdvancedChamfer_H

// COPYRIGHT DASSAULT SYSTEMES  2003

#include "CATDynChamfer.h"
#include "AdvancedFillet.h"
#include "CATFreeFormDef.h"

class CATGeoFactory;
class CATBody;
class CATTopData;
class CATDynSolidChamferCGM;
class CATRibbonsReorderTracker;

/**
 * Class defining the operator to chamfer edges of a 3D body or a skin body.
 * This operator offers more capabilities that <tt>CATDynChamfer</tt> and 
 * generates a result in cases where <tt>CATDynChamfer</tt> fails.
 * <br>Several chamfering operations (called ribbons, <tt>CATDynChamferRibbon</tt>) 
 * can be defined in the same operator. 
 * By default, a ribbon is automatically propagated by following the tangential
 * continuity of its support, but this propagation can be switched off.
 *<br>
 * The <tt>CATDynAdvancedChamfer</tt> operator follows the global frame of the topological 
 * operators and satisfies the smart mechanism: 
 * the input bodies are not modified. A new resulting body is created, 
 * possibly sharing data with the input bodies.
 *<ul>
 * <li>A <tt>CATDynAdvancedChamfer</tt> operator is created with the <tt>CATCreateDynAdvancedChamfer</tt> global function:
 * It must be directly deleted with the usual C++ <tt>delete</tt> operator after use. It is not streamable. 
 *<li>Options can be precised (such as the faces or edges to chamfer) with the appropriate methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory.
 *</ul>
 */

class ExportedByAdvancedFillet CATDynAdvancedChamfer : public CATDynChamfer
{
  CATCGMVirtualDeclareClass(CATDynAdvancedChamfer);
public:

 /**
  * @nodoc
	* Virtual constructor of a CATDynAdvancedChamfer operator.<br>
	* Cannot be called. Use the <tt>CATCreateDynAdvancedChamfer</tt> global function
	* to create a CATDynAdvancedChamfer operator.
	*/
  CATDynAdvancedChamfer(CATGeoFactory*     iContainer,
                        CATTopData*        iData,
                        CATDynSolidChamferCGM* iImplementation);

  virtual ~CATDynAdvancedChamfer();

  /**
   * Sets internal continuity level of chamfer ribbon
   * @param iContinuityLevel
   * Continuity level requested. Use either CATFrFPointCont or CATFrFTangentCont. Default is CATFrFPointCont.
   * @param iTolerance
   * Maximum deformation allowed to achieve the continuity. Not used as of now.
   */

  void SetContinuityLevel(const CATFrFContinuity  iContinuityLevel, // CATFrFPointCont or CATFrFTangentCont
                          const CATPositiveLength iTolerance = 0.); // Default = approximation not allowed

  /**
   * Activates "cap" shape of chamfer corners
   */
  void SetCornerCap();

  /** @nodoc */
  void SetCollisionCheckMode(CATBoolean iCollisionCheckMode);

  /** @nodoc */
  void SetFilletLongPropagation ();

  /**
   * Turns on the mode for the treatment of bad shapes, if encountered. 
   * It is recommended that you always call this method after creating this chamfer operator.
   */
  void SetBadShapeTreatmentOn();

  /**
  * To keep features that are entirely engulfed by the result of a chamfer operation the method SetKeepFeature should be used.
  * @param iKeepFeature
  * Keep feature option: CATTrue – feature kept; CATFalse – feature not kept. 
  * By default a chamfer operation does not keep any feature that isn’t interfering with the boundary of the chamfer. 
  */
  void SetKeepFeature( CATBoolean iKeepFeature );

  /**
  * Sets the approx mode - The chamfer distances will not be respected.
  * Useful to avoid twists and bad shapes.
  * Only D1D2 type chamfer supported currently.
  */
  void SetApproxChamferMode();

    /**
  * @nodoc
  * INTERNAL USE. DEDICATED TO LIVECHAMFER<br>
  * Assign a Ribbons Reorder Tracker.
  */
  void SetRibbonsReorderTracker(CATRibbonsReorderTracker* iTracker); 

  /**
  * @nodoc
  * Useful only for Approximate Chamfer
  * Retrieve the original Input distances D1 & D2 and reference faces using Chamfered and Un-Chamfered Body
  */
  CATBoolean GetOriginalInputSpecsForApproximateChamfer(CATBody * iChamferedBody,
                                                        CATBody * iUnChamferedBody,
                                                        CATEdge * iEdgeToChamfer,
                                                        CATLISTP(CATFace) & iChamferFaces,
                                                        CATFace * iOriginalInputRefFace,
                                                        CATListOfDouble  & iStoredDistancesd1d2,
                                                        CATListOfDouble  & ioOriginalInputsD1D2);

  /**
   * @nodoc @nocgmitf
   */
   CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent, CATCGMOutput& os);


private:
  int GetCGMApproximateChamferMode();
};


/**
 * Creates a CATDynAdvancedChamfer operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iPart
 * The pointer to the body to chamfer.
 * @return [out, delete]
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */

ExportedByAdvancedFillet CATDynAdvancedChamfer* CATCreateDynAdvancedChamfer(CATGeoFactory* iContainer,
                                                                    CATTopData*    iData,
                                                                    CATBody*       iPart);


#endif
