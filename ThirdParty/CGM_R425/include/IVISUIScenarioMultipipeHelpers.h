//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVISUIScenarioMultipipeHelpers_H
#define IVISUIScenarioMultipipeHelpers_H

#include "IVInterfaces.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATUnicodeString.h"

class CATMathTransformation;
class IVISUIScenarioMultipipe;
class IVISUIScenarioMultipipe_var;
class CAT3DViewpoint;

/**
 * IVCameraType
 */
typedef enum
{
  IVCameraType_Fly
  , IVCameraType_Standing
  , IVCameraType_Free
} IVCameraType;

struct ExportedByIVInterfaces POIData {
  POIData() : m_display(false) {}
  POIData(bool iDisplay, CATMathPoint iPos, int iRadius, bool iUseFading, double iFadingValue) : m_display(iDisplay), m_pos(iPos), m_radius(iRadius), m_useFading(iUseFading), m_fadingValue(iFadingValue) {}

  bool m_display;
  CATMathPoint m_pos;
  int m_radius;
  bool m_useFading;
  double m_fadingValue;
};

/**
 * IVCameraData
 */
struct ExportedByIVInterfaces IVCameraData
{
  IVCameraData() {}
  IVCameraData(IVCameraType iType, CATUnicodeString iName, CATMathPoint iPosition, CATMathVector iSight, CATMathVector iUp) : m_Type(iType), m_Name(iName), m_Position(iPosition), m_Sight(iSight), m_Up(iUp), m_POIData(POIData()) {}

  IVCameraType m_Type;
  CATUnicodeString m_Name;
  CATMathPoint m_Position;
  CATMathVector m_Sight;
  CATMathVector m_Up;
  POIData m_POIData;

  bool operator == (const IVCameraData& cameraData) const {
    return m_Name == cameraData.m_Name ? true : false;
  }

  bool operator != (const IVCameraData& cameraData) const {
    return !(*this == cameraData);
  }

};



//=============================================================================
/**
 * IVISUIScenarioMultipipeHelpers
 */
namespace IVISUIScenarioMultipipeHelpers
{
  /**
   * Update the interaction context of the given multipipe scenario so that
   * the "adjusted" current physical HMD pose (*) is mapped to the given V6
   * pose.
   *
   * (*) The "adjusted" physical HMD pose is the current physical pose of the
   * HMD modified so that its "up" matches the vertical.
   *
   * @param iScenario The multipipe scenario. Must already be started.
   *
   * @param iTargetPose The target pose in the absolute V6 referential. This
   * pose is interpreted according to the V6 conventions (X right, Y forward,
   * Z up). iTargetPose must be an isometry.
   *
   */
  ExportedByIVInterfaces void ResetInteractionContext(IVISUIScenarioMultipipe* iScenario, CATMathTransformation const& iTargetPose);


  /**
   * Update the interaction context of the given multipipe scenario so that
   * the "adjusted" current physical HMD pose (*) is mapped to the given V6
   * pose.
   *
   * (*) The "adjusted" physical HMD pose is the current physical pose of the
   * HMD modified so that its "up" matches the vertical.
   *
   * @param i_Main3DViewpoint The desktop main 3D viewpoint. Used to determine the ground for IVCameraType_Standing type.
   *
   * @param i_Scenario The multipipe scenario. Must already be started.
   *
   * @param i_Camera The target pose in the absolute V6 referential.
   *
   */
  ExportedByIVInterfaces void ApplyCameraToInteractionContext(CAT3DViewpoint& i_Main3DViewpoint, IVISUIScenarioMultipipe_var& i_hScenario, IVCameraData& i_Camera);
};

#endif
