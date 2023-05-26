//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyHealingWithOverlayOptions.h
//
//===================================================================
//  May 2018 : F1Z : Creation
//  Dec 2022 : F1Z : Review options: no more volumic/surfacic option necessary,
//                   a single option to handle all the cases.
//===================================================================
#pragma once

#include "CATPolyBodyOverlayOptions.h"
#include "PolyBodyBoolean.h"
#include "Poly/Vector.h"
#include "CATPolyBody.h"
#include "CATPolyOverlayFillHoleOptions.h"

namespace Poly
{
  namespace HWO
  {
    class IPatchInfo;
  }
};

/**
 * Main hwo options. Abstract.
 */
class ExportedByPolyBodyBoolean CATPolyBodyHealingWithOverlayOptions : public CATPolyBodyOverlayOptions
{
public:
  CATPolyBodyHealingWithOverlayOptions();
  CATPolyBodyHealingWithOverlayOptions(const CATPolyBodyHealingWithOverlayOptions & iToCopy);
  virtual ~CATPolyBodyHealingWithOverlayOptions() {};
  CATPolyBodyHealingWithOverlayOptions& operator=(const CATPolyBodyHealingWithOverlayOptions & iToCopy);
  CATPolyBodyHealingWithOverlayOptions(const CATPolyBodyOverlayOptions & iToCopy);

public:
  // ======================================================================================== //
  // ======================================   STATUS   ====================================== //
  // ======================================================================================== //
  // Can provide information to the operator to skip check or improve them
  enum Status
  {
    eIsIntersectionFree = 0x001,
    eIsClosed = 0x002,
    eIsOriented = 0x004
  };

  /**
   * Set a status of the input poly body to avoid some computation
   * If the provided information are not valid, the operator might fail to perform the computation
   */
  inline void SetStatus(int iPolyBodyStatus) { _polyBodyStatus = iPolyBodyStatus; };
  inline int  GetStatus() { return _polyBodyStatus; };
  inline bool IsIntersectionFree() { return (_polyBodyStatus & eIsIntersectionFree) != 0; };
  inline bool IsClosed() { return (_polyBodyStatus & eIsClosed) != 0; };
  inline bool IsOriented() { return (_polyBodyStatus & eIsOriented) != 0; };

  // ========================================================================================= //
  // ======================================   CONTACT   ====================================== //
  // ========================================================================================= //
  // The method to compute the contacts
  enum class ContactMode : unsigned int
  {
    eBasic, // Non tolerant mode with one iteration. Efficient but doesn't guarantee there is no intersection anymore due to the numerical noise.
    eIterativeConvergence, // Tolerant mode. Efficient at the resolution. Performance troubles & quality issue with dense meshes, but overall improvement of the quality. Bad behavior for high tolerance.
    eIterativeWithOffsetFilter, // Tolerant mode. Avoid most of the CPU problem with iterative mode + improve the quality of result. Can be use at higher tolerance than the resolution.
    eTolerantHoleFilling // under dev. It removes the confused area and use the fill hole to create a new surface (instead of displacement of original mesh).
  };

  void SetContactMode(ContactMode iContactMode);
  inline ContactMode GetContactMode() const { return _contactMode; };

  // ============================================================================================= //
  // ======================================   ORIENTATION   ====================================== //
  // ============================================================================================= //
  /**
  * Any external closed surface will define a volume.
  * Necessary when you expect a volume based on an unoriented poly body or without multiplicity/volume information.
  */
  inline void SetBuildExternalHullVolumes(bool iBuildExternalHullVolumes = true) { _buildExternalHullVolumes = iBuildExternalHullVolumes; };
  inline bool DoBuildExternalHullVolumes() const { return _buildExternalHullVolumes; };

  /**
  * All the space partition will define volumes.
  * It can be useful if you want to filter the volume to keep after the healing run.
  */
  inline void SetAllSpacePartitionAsVolume(bool allSpacePartitionAsVolume = true) { _allSpacePartitionAsVolume = allSpacePartitionAsVolume; };
  inline bool DoAllSpacePartitionAsVolume() { return _allSpacePartitionAsVolume; };

  // ============================================================================================= //
  // ======================================   HOLE FILLING  ====================================== //
  // ============================================================================================= //
  inline void SetFillTheHoles(bool doFillTheHoles=true) { _doFillTheHoles = doFillTheHoles; };
  inline bool DoFillTheHoles() const { return _doFillTheHoles; };

  using FillHoleOptions = CATPolyOverlayFillHoleOptions;

  inline void SetFillHoleOptions(FillHoleOptions & iFillHoleOptions) { _fillHoleOptions = iFillHoleOptions; };
  inline const FillHoleOptions & GetFillHoleOptions() const { return _fillHoleOptions; };
  inline FillHoleOptions & GetFillHoleOptions() { return _fillHoleOptions; };

  // ================================================================================================ //
  // ======================================   KEEP - VOLUMES   ====================================== //
  // ================================================================================================ //
  /**
  * @ratio
  * The percentage of the volume value to keep, compared to the biggest one.
  * @connex
  *  False means all the volumes are compared with the biggest one.
  *  True if volumes are grouped by connexity. Then the same filter is applied but for each group.
  */
  inline void SetVolumesRatio(double ratio, bool connex=true) { _volumesRatioToRemove = ratio; _volumesConnexityGroup = connex; };
  inline double GetVolumesRatio() const { return _volumesRatioToRemove; };
  inline bool HasVolumesConnexityGroup() const { return _volumesConnexityGroup; };

  /**
  * Remove all the space partition under minVolumeValue
  */
  void SetMinSpacePartitionValue(double minVolumeValue);
  inline double GetMinSpacePartitionValue() const { return _minSpacePartitionValue; };

  /**
  * Remove all the space partition with a thickness under minThicknessValue
  * So far the thickness computation is based on obb.
  */
  void SetMinSpacePartitionThickness(double minThicknessValue);
  inline double GetMinThicknessSpacePartition() const { return _minThicknessValue; };

  inline void SetSpacePartitionNoSolidRemoval(bool noSolidRemoval) { _noSolidRemovalSP = noSolidRemoval; };
  inline bool IsSolidRemovalSpaceParitionAllowed() const { return _noSolidRemovalSP; };

  /**
  * Remove all the space partition internal to a solid with a thickness under minThicknessValue
  * So far the thickness computation is based on obb.
  */
  void SetSolidInternalMinSpacePartitionThickness(double minSolidInternalThicknessValue);
  inline double GetSolidInternalMinThicknessSpacePartition() const { return _minSolidInternalThicknessValue; };

  inline void SetSplitIsolatedVolumeShell(bool splitIsolatedVolumeShell) { _splitIsolatedVolumeShell = splitIsolatedVolumeShell; };
  inline bool DoSplitIsolatedVolumeShell() const { return _splitIsolatedVolumeShell; };


  // ================================================================================================= //
  // ======================================   KEEP - SURFACES   ====================================== //
  // ================================================================================================= //
  inline void SetKeepExternalSurfaces(bool keepExternalSurface = true) { _keepExternalSurfaces = keepExternalSurface; };
  inline bool DoKeepExternalSurfaces() const { return _keepExternalSurfaces; };

  inline void SetMinScalesArea(double minScaleArea) { _minScalesArea = minScaleArea; };
  inline double GetMinScalesArea() const { return _minScalesArea; };

  // ======================================================================================== //
  // ======================================   RESULT   ====================================== //
  // ======================================================================================== //
  /**
   * By default, all the bar are smooth (<=>iAngle=CATPI).
   * If the angle between two triangle is lower than CATPI-iAngle (or above CATPI+iAngle), the bar will participate to the face segmentation.
   * However, a set of bars that do not separate a resulting face will not be concidered as an edge.
   */
  inline void SetSegmentationSharpBar(double iAngle = 0.78539816339) { _sharpAngleLimit = iAngle; };
  inline double GetSegmentationSharpBarLimit() const { return _sharpAngleLimit; };

  /**
  * Set strict filiation face cutting to build the result.
  * By default, we can have a face optimisation to reduce the number of face.
  * A strict face filiation ensure the new face has a filiation identical to each part of this new face.
  */
  inline void SetStrictFiliationCut(bool strict = true) { _strictFiliationCut = strict; };
  inline bool HasStrictFiliationCut() { return _strictFiliationCut; };

  /**
  * Observers for the operator.
  */
  class Observer;
  void RegisterObserver(Observer * iObs);
  void UnregisterObserver(Observer * iObs);
  inline const Poly::Vector<Observer *> & GetObs() { return _obs; };


private:
  void DefaultAttInit();
  void Copy(const CATPolyBodyHealingWithOverlayOptions & toCopy);

  int  _polyBodyStatus;
  bool _NMInnerFaceBarToRemove;
  double _sharpAngleLimit;
  bool _strictFiliationCut;
  ContactMode _contactMode;

  bool _inflateRemainingNonManifoldBar;
  double _volumesRatioToRemove;
  bool _volumesConnexityGroup;
  double _minSpacePartitionValue;
  double _minSolidInternalThicknessValue;
  double _minThicknessValue;
  bool _noSolidRemovalSP;
  bool _splitIsolatedVolumeShell;

  double _minScalesArea;

  bool _doFillTheHoles;
  FillHoleOptions _fillHoleOptions;

  bool _buildExternalHullVolumes;
  bool _allSpacePartitionAsVolume;
  bool _allowOpenExternalHull;

  bool _keepExternalSurfaces;

  Poly::Vector<Observer *> _obs;

  public:
    // ======================================================================================== //
    // ====================================   DEPRECATED   ==================================== //
    // ======================================================================================== //
    // This is deprecated because the behavior is hard to guarantee. Still avalaible.
    // If true, the operator will build the external hull even if the model is open.
    // This is useful to clear noise in an almost closed surface.
    inline void SetAllowOpenExternalHull(bool allowOpenExternalHull = true) { _allowOpenExternalHull = allowOpenExternalHull; };
    inline bool DoAllowOpenExternalHull() const { return _allowOpenExternalHull || _inflateRemainingNonManifoldBar;  };

    /**
     * Once correctly oriented, repair the remaining non manifold bars by inflating them at the overlay tolerance.
     * This only works for volumes.
     */
    inline void SetInflateRemainingNMBars(bool iInflate = true) { _inflateRemainingNonManifoldBar = iInflate; };
    inline bool HasInflateRemainingNMBars() const { return _inflateRemainingNonManifoldBar; };

    /**
     * Volumes can touch other volume through non manifold bar or vertex.
     * @deprecated
     * @see SetVolumesRatio
     */
    enum class TouchingVolumesMode
    {
      eKeepBiggest, // Keep the biggest volume among the touching volumes along non manifold bars/vertices
      eKeepAll // Keep all of them.
    };

    /**
     * @deprecated
     * @see SetVolumesRatio
     */
    inline void SetTouchingVolumesMode(TouchingVolumesMode iTVMode) { _volumesRatioToRemove = iTVMode == TouchingVolumesMode::eKeepBiggest ? 100 : 0; _volumesConnexityGroup = true; };
    inline TouchingVolumesMode GetTouchingVolumesMode() const { return _volumesRatioToRemove == 0 ? TouchingVolumesMode::eKeepAll : TouchingVolumesMode::eKeepBiggest; };
};

class ExportedByPolyBodyBoolean CATPolyBodyHealingWithOverlayOptions::Observer
{
public:
  Observer() {};
  virtual ~Observer() {};

  enum class Stage : unsigned int
  {
    eTolerantOffset = 1 << 0,
    eNbStages // to complete
  };

  virtual HRESULT EndBuildTolerantPatch(Stage iStage,
                                        const CATPolyBody & iPolyBody,
                                        const Poly::HWO::IPatchInfo & iPI) {
    return S_FALSE;
  };

  virtual void BeginHoleFilling() {}; // With positions information, we could highlight the border we are filling.
  virtual void EndHoleFilling() {}; // End preview info?
  virtual void ReactToStep(CATIPolyMesh& iMesh) {}; // iMesh is the current mesh of the hole being filled.
};

/**
 * HWO volumic mode
 * and all the options associated.
 * The volumique mode will make sure the model(s) are closed (by filling the hole if any)
 * then will extract the bigest volume if severals are touching taking the intersections into account.
 * So far, it only extract the external hull of the volume.
 */
class ExportedByPolyBodyBoolean CATPolyBodyHealingWithOverlayVolumicOptions : public CATPolyBodyHealingWithOverlayOptions
{
public:
  CATPolyBodyHealingWithOverlayVolumicOptions();
  CATPolyBodyHealingWithOverlayVolumicOptions(const CATPolyBodyOverlayOptions & iToCopy);
  virtual ~CATPolyBodyHealingWithOverlayVolumicOptions(){};

private:
  void BuildDefaultVolumicAtt();
};


/**
* HWO surfacic mode
* and all the options associated.
* The surfacic mode will concretize the contacts.
* Then, according to the options, proceed to various treatment based on given information or heuristic (so far, only area based heuristic exposed)
*/
class ExportedByPolyBodyBoolean CATPolyBodyHealingWithOverlaySurfacicOptions : public CATPolyBodyHealingWithOverlayOptions
{
public:
  CATPolyBodyHealingWithOverlaySurfacicOptions();
  CATPolyBodyHealingWithOverlaySurfacicOptions(const CATPolyBodyOverlayOptions & iToCopy);
  virtual ~CATPolyBodyHealingWithOverlaySurfacicOptions(){};

private:
  void DefaultAttSurfacicInit();
};
