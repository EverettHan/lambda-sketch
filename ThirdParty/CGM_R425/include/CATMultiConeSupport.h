// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=================================================================================
// CATMultiConeSupport:
// Cone supports interfaces for additive manufacturing 
// From TopZone and a list of cones parameters (grid of points, radius ,...), build the cone supports between Bottomzone and Topzone
// Anchors can be defined at top and bottom of the cones
//=================================================================================
// 25 04 2020 AOV Creation 

#ifndef CATMultiConeSupport_H
#define CATMultiConeSupport_H

#include "AdvTopoOpeItf.h"
#include "CATTopMultiResult.h"

// Math
#include "CATMathPoint.h"
#include "CATMathVector.h"

// Topo
#include "CATCGMOutput.h"

class CATIPolyMesh;

/**
* Class defining an operator that computes the conical supports between tray and zone to support
* Support zone is a CATIPolyMesh.
* This operator is a <tt>CATICGMTopMultiResult</tt> operator and its results are polyhedral CATBody.
* Use CATCreateMultiConeSupport to create it.
*/

class ExportedByAdvTopoOpeItf CATMultiConeSupport : public CATTopMultiResult {
  CATCGMVirtualDeclareClass(CATMultiConeSupport);
public:
  
  virtual ~CATMultiConeSupport();

  /** @brief Define a list of cone supports parameters.
  * @param iNbOfPoints Total of supports. Defines the size of all the other arguments
  * @param iListOfTopCenter top point of cone on top zone (Ct)
  * @param iListOfBottomCenter bottom point of cone on tray (Cb)
  * @param iListOfInnerAngle Inner angle of the cone. 0 < iListOfInnerAngle <= CATPIBY2. If equal to CATPIBY2, the support is a Cylinder. (alpha)
  * @param iConeRadii List of the radii of each cone taken orthogonal to cone axis around TopCenter point (Rt).
  * 
  *                            /         \
  *                           /)          \
                   alpha-----/->)       Rt \                  
    ----------------------- /----)  o  <--->\ -------------- TOP ZONE
                           /        ^        \      
                          /         |         \                       
                         /         Ct          \                        
                        /                       \                               
                       /                         \                              
    --------------------------------o------------------------ BOTTOM ZONE
                                    ^
                                    |
                                   Cb
  */
  virtual void SetConesParam(const int iNbOfPoints, const CATMathPoint* iListOfTopCenter, const CATMathPoint* iListOfBottomCenter, const CATAngle* iListOfInnerAngle, const double* iTopConeRadii) = 0;


  /** @brief Define the SAG of the output mesh
  * @param iSAG value of the SAG 
  * by default take the min sag of top and bottom zone
  */
  virtual void SetConeSAG(const double iSAG) = 0;

  /** @brief Define a thickness for the cones.
  * @param iThickness value of the thickness >0 
  * A paralel cone will be removed inside leaving the given thickness. 
  */
  virtual void SetConeThickness(const double iThickness) = 0;

  /** @brief Define offset at top of the cones.
  * Creates a void between the support cone and the top zone. 
  * Negative value allowed - the cone will penetrate the part at top by the offset amount
  * WARNING: if offset defined at top no relimitation by the topzone
  */
  virtual void SetTopOffset(const double iTopOffset) = 0;

  /** @brief Define offset at bottom of the cones.
  * Creates a void between the support cone and the bottom zone.
  * Negative value allowed - the cone will penetrate the tray by the offset amount
  * WARNING: if offset defined at bottom no relimitation by the bottomzone
  */
  virtual void SetBottomOffset(const double iBottomOffset) = 0;

  /** @brief Define top zone for relimitation of the cones at top
  * @param iTopZone the mesh representing the top zone with normal oriented from top to bottom and normal at vertices defined
  */
  virtual void SetTopZone(CATIPolyMesh* iTopZone) = 0;
  
  /** @brief Define bottom zone for relimitation of the cones at bottom
  * @param iBottomZone the mesh representing the top zone with normal oriented from bottom to top and normal at vertices defined
  */
  virtual void SetBottomZone(CATIPolyMesh* iBottomZone) = 0;

  /** @brief Anchors
  * @param iPenetrationLength : the top zone (i1)
  * @param iShrinkingRate : rate of middle radius of the anchor (i2)
  * @param iShrinkingRatePosition : rate position of middle radius of the anchor (i3)
  * @param iAnchorHeight : height of the anchor (i4)
  * @param iNormalAnchor : if TRUE, anchor will be generated following the part surface's normal direction (not available for the moment), 
  *                        else, anchor will be generated vertically
  * @param iOnBuildTray : if TRUE, anchor will be also build at bottom
  *                       else only on top
  * 
  * 
  * ^           *---------*          ^
  * A           *         *          | i1
  * N  ---------***********----------^------ TOP ZONE
  * C             *     *            |
  * H               * *         ^    i4
  * O             *     *       |i3  |
  * R           ***********     ^    ^
  * ^          /           \
  * C         / |<->|       \
  * O        /  | i2|        \
  * N       /                 \
  * E      /                   \
  *   -------------------------------------- TRAY
  */
  virtual void SetAnchorsParameters(double iPenetrationLength, double iShrinkingRate, double iShrinkingRatePosition, double iAnchorHeight, CATBoolean iNormalAnchor=FALSE, CATBoolean iOnBuildTray=FALSE) = 0;

  /** @brief Returns the pointer to the current result body.
  */
  virtual CATBody* GetResult() const = 0;

  /**
 * @nodoc
 * Virtual constructor of a CATMultiConeSupport.<br>
 * Cannot be called. Use the <tt>CATCreateXxx</tt> global function
 * to create the Xxx operator.
 */
  CATMultiConeSupport(CATGeoFactory* iFactory, CATTopData& iTopData);

};

ExportedByAdvTopoOpeItf CATMultiConeSupport* CATCreateMultiConeSupport(CATGeoFactory* iFactory, CATTopData& iTopData);


#endif
