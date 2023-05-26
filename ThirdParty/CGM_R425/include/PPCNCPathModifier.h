#ifndef PPCNCPathModifier_H_
#define PPCNCPathModifier_H_

#include "CATPolyRefCounted.h"
#include "CATCGMSharedPtr.h"
#include <vector>
#include <unordered_map>
#include <map>

#include "CATPolyPPPath.h"

#include "CATPolyPPRobotChecker.h"
#include "ExportedByPPRobot.h"
/*
* Prototype
*/
class ExportedByPPRobot PPCNCPathModifier
{
  public:
  PPCNCPathModifier(CATPolyPPRobotChecker::SPtr & iChecker);

  /**
   * Define how a segment of the path will be decompose (if possible ) in action allowing only some dof at each time
  */
  void SetDecompositionDofGroup(std::vector<std::vector<std::vector<int>>> & iDecomposition);

  /**
   * Try to modify the path to have a more CNC like path ( not all axis in the same time )
   * @param[in] ioPath
  */
  HRESULT Decompose( CATPolyPPPath & ioPath );

  HRESULT AdaptLocalSegment(CATPolyPPPosition::SPtr & A, CATPolyPPPosition::SPtr & B, std::vector<CATPolyPPPosition::SPtr > & oResu);
  
  //Helper
  // create the group to separate Translation, and Rotation 
  static std::vector<std::vector<int>> TranslationThenRotate(PPRobot & IRobotModel, bool iAllTranslateInSameTime = true, bool AllRotateInSameTime = true);
  static std::vector<std::vector<std::vector<int>>>  GetPermutations(std::vector<std::vector<int>> &Original);

  HRESULT RemoveUseLessDofMovement(CATPolyPPPath & ioPath ,unsigned int iDof);
  
  /**
   * try to replace rotation that make more than 180 deg in a direction by the rotation in other direction which will be less than 180 deg
  */
  HRESULT MinimizeRotationAngles(CATPolyPPPath & ioPath );

  protected:
  std::vector<std::vector<std::vector<int>>> _DecompositionPriority;
  CATPolyPPRobotChecker::SPtr _Checker;
};

#endif
