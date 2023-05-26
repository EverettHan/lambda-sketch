#ifndef CATPrintSetup_H
#define CATPrintSetup_H

// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=================================================================================
// CATPrintSetup:
// Interfaces for Parts orientation optimization, Nesting 2D, 3D and 2.5D 
// TE9
//=================================================================================

#include "ListPOfCATBody.h"
#include "CATListPV.h"
#include "AdvTopoOpeItf.h"
#include "CATGeoOperator.h"
#include "CATLISTV_CATMathTransformation.h"  
#include "CATMathBox.h"
#include "CATPrintSetupOrientationTarget.h"
#include "CATNestingOptimizationCriterion.h"
#include "CATCGMSharedPtr.h"

#include <memory>
#include <optional>

class CATPrintSetupOrientationConstraint;
class CATPrintSetupInteractiveSolution;
class CATPrintSetupCommonCuttingLineOptions;

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATIPolyMesh;
class CATPolyBody;
class CATPrintSetupFuture;
enum class CATNesting3DMethod;
class CATPrintSetupAsyncOptions;

class ExportedByAdvTopoOpeItf CATPrintSetup : public CATGeoOperator
{
  CATCGMVirtualDeclareClass(CATPrintSetup);
public:
  CATPrintSetup(CATGeoFactory* iFactory);
  virtual ~CATPrintSetup() = 0;

  /** @brief Define parts to arrange.
  * @param iBodies As one ‘part’ can be made of several CATBody, specify your part through the list of CATBody
  * @param iNbInstance defines part and corresponding number of instances
  * @param iTarget defines the orientation target position of the part in 3D based see @CATPrintSetupOrientationTarget - if NULL, only nesting is done
  * @param iConstraint allows or not rotation of the part in the nesting see @CATPrintSetupOrientationConstraint - if NULL, free rotation is allowed
  * WARNING: In the case of CATNestingOptimizationTarget = MaximizeNbPart, use NbInstance = -1.
  * AddPart can be called several times
  */
  virtual void AddPart(ListPOfCATBody& iBodies, int iNbInstance,
    CATPrintSetupOrientationTarget const* iTarget,
    CATPrintSetupOrientationConstraint const* iConstraint) = 0;

  /** @brief Define parts to arrange
  * @param iBox define the box to nest
  * @param iNbInstance defines part and corresponding number of instances
  * @param iTarget defines the orientation target position of the part in 3D based see @CATPrintSetupOrientationTarget - if NULL, only nesting is done
  * @param iConstraint allows or not rotation of the part in the nesting see @CATPrintSetupOrientationConstraint - if NULL, free rotation is allowed
  * WARNING: In the case of CATNestingOptimizationTarget = MaximizeNbPart, use NbInstance = -1.
  * AddPart can be called several times
  */
  virtual void AddPart(CATMathBox const& iBox, int iNbInstance, CATPrintSetupOrientationTarget const* ipTarget, CATPrintSetupOrientationConstraint const* ipConstraint) = 0;

  /** @brief Define parts to arrange.
  * @param iPolyMesh define the mesh through CATIPolyMesh
  * @param iNbInstance defines part and corresponding number of instances
  * @param iTarget defines the orientation target position of the part in 3D based see @CATPrintSetupOrientationTarget - if NULL, only nesting is done
  * @param iConstraint allows or not rotation of the part in the nesting see @CATPrintSetupOrientationConstraint - if NULL, free rotation is allowed
  * WARNING: In the case of CATNestingOptimizationTarget = MaximizeNbPart, use NbInstance = -1.
  * AddPart can be called several times.
  */
  virtual void AddPart(CATCGMSharedPtr<CATIPolyMesh> iPolyMesh, int iNbInstance, CATPrintSetupOrientationTarget const* ipTarget, CATPrintSetupOrientationConstraint const* ipConstraint) = 0;

  /** @brief Define parts to arrange.
  * @param iPolyBody define the mesh through CATPolyBody
  * @param iNbInstance defines part and corresponding number of instances
  * @param iTarget defines the orientation target position of the part in 3D based see @CATPrintSetupOrientationTarget - if NULL, only nesting is done
  * @param iConstraint allows or not rotation of the part in the nesting see @CATPrintSetupOrientationConstraint - if NULL, free rotation is allowed
  * WARNING: In the case of CATNestingOptimizationTarget = MaximizeNbPart, use NbInstance = -1.
  * AddPart can be called several times.
  */
  virtual void AddPart(CATCGMSharedPtr<CATPolyBody> iPolyBody, int iNbInstance, CATPrintSetupOrientationTarget const* ipTarget, CATPrintSetupOrientationConstraint const* ipConstraint) = 0;

  /** @brief 
  */
  virtual int GetNbInstances(int iPart) const = 0;
  virtual CATPrintSetupOrientationTarget const* GetOrientationTarget(int iPart) const = 0;
  virtual CATPrintSetupOrientationConstraint const& GetOrientationConstraint(int iPart) const = 0;
  virtual int GetNbParts() const = 0;

  /** @brief Define the tray dimensions.
  * optional in nesting2D if a nesting zone is defined - the tray dimension will be automatically computed from the nesting zone
  */
  virtual void SetTrayDimensions(CATMathBox const& iTrayDimensions) = 0;
  virtual CATMathBox const& GetTrayDimensions() const = 0;

  /** @brief Define the distance expected between parts in the result.
  * The distance is global to all the parts
  */
  virtual void SetMinimalDistanceBetweenParts(CATLength iDistance) = 0;
  virtual CATLength GetMinimalDistanceBetweenParts() const = 0;

  /** @brief Define the distance expected between pair of parts. 
  * the option is only availble for the moment on Nesting2D/2.5D 
  */
  virtual void SetMinimalDistanceBetweenPairOfParts(int iIndexPart1, int iIndexPart2, CATLength iDistance) = 0;
  virtual CATLength GetMinimalDistanceBetweenPairOfParts(int iIndexPart1, int iIndexPart2) const = 0;

  /** @brief Allows interlocking in the solutions of Nesting3D.
  * By default no interlocking occur in the result 
  */
  virtual void SetInterlocking(bool iInterlocking) = 0;
  virtual bool GetInterlocking() const = 0;

  /** @brief Allow nesting 2D of parts in hole of other parts.
  */
  virtual void SetFillHoles(bool iFillHoles) = 0;
  virtual bool GetFillHoles() const = 0;

  virtual void SetNesting3DMethod(CATNesting3DMethod iNesting3DMethod) = 0;
  virtual CATNesting3DMethod GetNesting3DMethod() const = 0;

  /** @brief Define the optimization expected see @CATNestingOptimizationTarget.
  * if not called, only orientation optimization is done
  */
  virtual void SetNestingOptimizationTarget(CATNestingOptimizationTarget iNestingOptimizationTarget) = 0;
  virtual CATNestingOptimizationTarget GetNestingOptimizationTarget() const = 0;

  /** @brief Define nesting2D optimization criteria : see @CATNestingOptimizationCriterion.
  */
  virtual void SetNestingOptimizationCriterion(CATNestingOptimizationCriterion iNestingOptimizationTarget) = 0;
  virtual CATNestingOptimizationCriterion GetNestingOptimizationCriterion() const = 0;

  virtual void SetInteractiveSolution(std::unique_ptr<CATPrintSetupInteractiveSolution> ipInteractiveSolution) = 0;
  
  /** @brief Method to run the opertaor in asynchroneous mode.
  */
  virtual CATPrintSetupFuture RunAsync(CATPrintSetupAsyncOptions const& iOptions) = 0;

  /** @brief Method to interrupt the computation.
  * The result will be the last result computed
  */
  virtual void Interrupt() = 0;
  virtual bool ReadSolution() = 0;
  virtual double GetProgress() const = 0;


  /** @brief Method to clear history of nesting between 2 runs.
  */
  virtual void Clear() = 0;

  /** @brief define a group of n parts ....
  */
  virtual void SetNestingPattern(int iNbPartInPattern) = 0;
  virtual int GetNestingPattern() const = 0;

  /** @brief Define list of exclusion zones.
  * in 2D the exclusion zone is defined by the projection of the CATBody on the tray.
  * in 3D, the exclusion zone is defined by the tesseleted representation of the CATBody in real contour mode 
  * else by the bounding box of the CATBody.
  * For Nesting2.5D, Exclusion Zone and Nesting zone currently work  Nesting2D
  */
  virtual void SetExclusionZone(ListPOfCATBody const& iBodies) = 0;
  virtual ListPOfCATBody GetExclusionZones() const = 0;

  /** @brief Add exclusion zone from previous nested parts for an iterative context.
  * @param iBody the body resulting from a previous nesting
  * @param iDistanceToPart the distance offset defined on the part
  * @param ipPosition the position and orientation of the part
  */
  virtual void AddExclusionZone(CATBody& iBody, double iDistanceToPart, CATMathTransformation const* ipPosition) = 0;

  /** @brief Change nesting zone from box to exact part contour.
  * by default the nesting is computed on the bounding box of the parts.
  * in exact contour, the nesting 2D is comouted on the tesselated contour if the projected CATBody.
  * For Nesting2.5D, Exclusion Zone and Nesting zone currently work  Nesting2D
  */
  virtual void SetContourNesting(bool iContourNesting) = 0;
  virtual bool GetContourNesting() const = 0;

  /** @brief Create a new nesting zone inside the global tray.
  * Nested pieces would have to be inside one of the nesting zones if any is defined
  */
  virtual void AddNestingZone(CATBody& iBody, double iDistanceToParts, CATMathTransformation const* ipPosition) = 0;
  virtual ListPOfCATBody GetNestingZones() const = 0;

  /** @brief Internal computation of the nesting is done on discrete representation of the part - define the sag expected.
  */
  virtual void SetSag(double iSag) = 0;
  virtual double GetSag() const = 0;


  /** @brief This method is still under development. it is dedicated to test for cardboard design application.
  * Param iCriterion:    
  *       1 = MinimizeMathBox        :  Minimize the MathBox area.
  *       2 = MinimizeMultiCriterion :  Minimize the delta value of different criterion : GravityCenterOnX + GravityCenterOnY + LengthX + LengthY. 
  *       3 = LowestGravityCenterOnX :  Lowest gravity center on axe X (minimize GravityCenterPoint.GetY()).
  *       4 = LowestGravityCenterOnY :  Lowest gravity center on axe Y (minimize GravityCenterPoint.GetX()).
  * */
  virtual void SetNestingCriterion(short iCriterion) = 0;
  virtual short GetNestingCriterion() const = 0;

  /** @brief Get result as a list of transformations of the total number of instances in the order the parts have been added.
  */
  virtual void GetTransfos(CATLISTV(CATMathTransformation)& oTransfos) const = 0;
  
  /** @brief Get result as a list of transformations of the number of parts in pattern (size of oTransfoWithinPattern == iNbPartInPattern).
  * + the list of the transformations of the number of pattern (size of oPatternTransfos = (total nb of instances)/iNbPartInPattern).
  */
  virtual void GetPatternTransfos(CATLISTV(CATMathTransformation)& oTransfoWithinPattern,
    CATLISTV(CATMathTransformation)& oPatternTransfos) const = 0;
  
  /** @brief Result for orientation optimization (?).
  */
  virtual void GetOptimizedValues(CATListOfDouble& oOptimizedValues) const = 0;

  /** @brief Result for nesting optimization.
  * 0: nesting not requested;
  * 1: nesting succeeded;
  * 2: nesting failed;
  */
  virtual void GetTrayStatus(CATListOfInt& oTrayStatus) const = 0;
  
  /** @brief Get boudning box of nesting result.
  */
  virtual void GetTrayFilledBox(CATMathBox& oFilledBox) const = 0;

  /** @brief Get number of parts in the result.
  */
  virtual int  GetNumberOfPlacedParts() const = 0;

  /** @brief Returns the total area of all nested parts (2D).
  */
  virtual double GetNestedArea() const = 0;

  /** @brief Returns the total area of all exclusion zones (2D).
  */
  virtual double GetExclusionZoneArea() const = 0;

  /** @brief Returns the total volume of all nested parts (3D)
  */
  virtual double GetNestedVolume() const = 0;

  /** @brief Returns the density of all nested parts (nested area / tray area) or (nested volume / container volume)
  */
  virtual double GetNestedDensity() const = 0;

  /** @brief Returns the total heights of all nested parts (3D)
  */
  virtual double GetNestedHeight() const = 0;

  /** @brief Returns the total volume of all exclusion zones (3D)
  */
  virtual double GetExclusionZoneVolume() const = 0;

  /** @brief Enable/disable centering of the solution with respect to the build tray
   */
  virtual void SetCenterSolution(bool iDoCenter) = 0;
  virtual bool GetCenterSolution() const = 0;

  /** @brief DO NOT USE.
   * Test infra only    
   */
  virtual void SetGAS(bool iGAS) = 0;
  virtual bool GetGAS() const = 0;

  /** @brief Enable/disable common cutting line mode
   */
  virtual void SetCommonCuttingLine(std::optional<CATPrintSetupCommonCuttingLineOptions> const& ipOptions) = 0;
  virtual std::optional<CATPrintSetupCommonCuttingLineOptions> const& GetCommonCuttingLine() const = 0;
};

//=============================================================================
ExportedByAdvTopoOpeItf CATPrintSetup* CATCreatePrintSetup(CATGeoFactory* iFactory, CATSoftwareConfiguration* iSoftwareConfiguration);

inline CATPrintSetup::CATPrintSetup(CATGeoFactory* iFactory)
  : CATGeoOperator(iFactory)
{
}

inline CATPrintSetup::~CATPrintSetup()
{
}

#endif
