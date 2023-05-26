
// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATManageVisuRepository_H
#define CATManageVisuRepository_H

#include "SGInfra.h"
#include "CATSysBoolean.h"

class CATSettingRepository;

//=================================//
// GEOM VISU TESSELLATION SETTINGS //
//=================================//
// Following methods are only to be used for MePref/UI management,
// otherwise if you want to access them (get or set), please use CATGeomVisuTessParamAccess API

// --- BEGIN --- PLEASE USE CATGeomVisuTessParamAccess INSTEAD --- BEGIN --- //

// Accuracy

extern ExportedBySGInfra int  CATGet3DAccuracyMode();
extern ExportedBySGInfra void CATSet3DAccuracyMode(const int);
extern ExportedBySGInfra char CATGetLock3DAccuracyMode();
extern ExportedBySGInfra long CATSetLock3DAccuracyMode(int);

extern ExportedBySGInfra int  CATGet2DAccuracyMode();
extern ExportedBySGInfra void CATSet2DAccuracyMode(const int);
extern ExportedBySGInfra char CATGetLock2DAccuracyMode();
extern ExportedBySGInfra long CATSetLock2DAccuracyMode(int);

extern ExportedBySGInfra float CATGet3DProportionnalAccuracy();
extern ExportedBySGInfra void  CATSet3DProportionnalAccuracy(const float);
extern ExportedBySGInfra char  CATGetLock3DProportionnalAccuracy();
extern ExportedBySGInfra long  CATSetLock3DProportionnalAccuracy(int);

extern ExportedBySGInfra float CATGet2DProportionnalAccuracy();
extern ExportedBySGInfra void  CATSet2DProportionnalAccuracy(const float);
extern ExportedBySGInfra char  CATGetLock2DProportionnalAccuracy();
extern ExportedBySGInfra long  CATSetLock2DProportionnalAccuracy(int);

extern ExportedBySGInfra float CATGet3DFixedAccuracy();
extern ExportedBySGInfra void  CATSet3DFixedAccuracy(const float);
extern ExportedBySGInfra char  CATGetLock3DFixedAccuracy();
extern ExportedBySGInfra long  CATSetLock3DFixedAccuracy(int);

extern ExportedBySGInfra float CATGet2DFixedAccuracy();
extern ExportedBySGInfra void  CATSet2DFixedAccuracy(const float);
extern ExportedBySGInfra char  CATGetLock2DFixedAccuracy();
extern ExportedBySGInfra long  CATSetLock2DFixedAccuracy(int);

extern ExportedBySGInfra float CATGet3DCurveAccuracy();
extern ExportedBySGInfra void  CATSet3DCurveAccuracy(const float);
extern ExportedBySGInfra char  CATGetLock3DCurveAccuracy();
extern ExportedBySGInfra long  CATSetLock3DCurveAccuracy(int);

extern ExportedBySGInfra float CATGetRealV43DCurveAccuracy();

extern ExportedBySGInfra int CATGetTransientAccMode(float&);
extern ExportedBySGInfra void CATUnsetTransientAccMode();
extern ExportedBySGInfra void CATSetTransientAccMode(const float);

// Mesh Quality

// AZX, new option, "Optimize meshes for texturing"
extern ExportedBySGInfra unsigned int CATGetOptimizedMeshMode();
extern ExportedBySGInfra void         CATSetOptimizedMeshMode(const unsigned int);
extern ExportedBySGInfra char         CATGetLockOptimizedMeshMode();
extern ExportedBySGInfra long         CATSetLockOptimizedMeshMode(int);

extern ExportedBySGInfra void CATSetAdaptiveQualityTessellation(const int);
extern ExportedBySGInfra int CATGetAdaptiveQualityTessellation();
extern ExportedBySGInfra char CATGetLockAdaptiveQualityTessellation();
extern ExportedBySGInfra long CATSetLockAdaptiveQualityTessellation(int LockMode);

// Isopars

extern ExportedBySGInfra int  CATGetIsoparGeneration();
extern ExportedBySGInfra void CATSetIsoparGeneration(const int);
extern ExportedBySGInfra char CATGetLockIsoparGeneration();
extern ExportedBySGInfra long CATSetLockIsoparGeneration(int);

extern ExportedBySGInfra int  CATGetInstantIsoparGeneration();
extern ExportedBySGInfra int  CATGetNbIsopars();
extern ExportedBySGInfra void CATSetNbIsopars(const int);

// Smooth Edges Curvature Step Threshold

extern ExportedBySGInfra CATBoolean CATGetEdgeHighCurvatureStepThresholdActivated();
extern ExportedBySGInfra void CATSetEdgeHighCurvatureStepThresholdActivated(const CATBoolean);
extern ExportedBySGInfra char CATGetLockEdgeHighCurvatureStepThresholdActivated();
extern ExportedBySGInfra long CATSetLockEdgeHighCurvatureStepThresholdActivated(int);

extern ExportedBySGInfra float CATGetEdgeHighCurvatureStepThreshold();
extern ExportedBySGInfra void CATSetEdgeHighCurvatureStepThreshold(const float);
extern ExportedBySGInfra char CATGetLockEdgeHighCurvatureStepThreshold();
extern ExportedBySGInfra long CATSetLockEdgeHighCurvatureStepThreshold(int);

// Wysiwyg

extern ExportedBySGInfra int  CATGetWysiwygMode();
extern ExportedBySGInfra void CATSetWysiwygMode(const int);

// Sharpness

extern ExportedBySGInfra int  CATGetSharpnessMode();
extern ExportedBySGInfra void CATSetSharpnessMode(const int);

// UV
extern ExportedBySGInfra float CATGetTargetSagForMesh0();
extern ExportedBySGInfra void  CATSetTargetSagForMesh0(const float);

extern ExportedBySGInfra int  CATGetExternalDiscretizationMode();
extern ExportedBySGInfra void CATSetExternalDiscretizationMode(const int);

extern ExportedBySGInfra int  CATGetUVMesh0Mode();
extern ExportedBySGInfra void CATSetUVMesh0Mode(const int);

// Max Angle Tessellation criterion
extern ExportedBySGInfra int  CATGetMaxAngleAccuracyMode();
extern ExportedBySGInfra void CATSetMaxAngleAccuracyMode(const int);

extern ExportedBySGInfra float CATGetMaxAngle();
extern ExportedBySGInfra void  CATSetMaxAngle(const float);

//#define CATWTTModeDefinition
#if defined CATWTTModeDefinition
extern ExportedBySGInfra int  CATGetWTTVisuMode();
extern ExportedBySGInfra void CATSetWTTVisuMode(const int);

extern ExportedBySGInfra int  CATGetRegularizationMode();
extern ExportedBySGInfra void CATSetRegularizationMode(const int);
#endif

// --- END --- PLEASE USE CATGeomVisuTessParamAccess INSTEAD --- END --- //



void SetSpaceDeviceActive(const int active);

extern ExportedBySGInfra float CATGetStaticLOD();
extern ExportedBySGInfra void  CATSetStaticLOD(const float);
extern ExportedBySGInfra char  CATGetLockStaticLOD();
extern ExportedBySGInfra long  CATSetLockStaticLOD( int);

extern ExportedBySGInfra int  CATGetStaticCull();
extern ExportedBySGInfra void CATSetStaticCull(const int);
extern ExportedBySGInfra char CATGetLockStaticCull();
extern ExportedBySGInfra long CATSetLockStaticCull(int);

extern ExportedBySGInfra int  CATGetDynamicCull();
extern ExportedBySGInfra void CATSetDynamicCull(const int);
extern ExportedBySGInfra char CATGetLockDynamicCull();
extern ExportedBySGInfra long CATSetLockDynamicCull(int);

extern ExportedBySGInfra float CATGetDynamicLOD();
extern ExportedBySGInfra void  CATSetDynamicLOD(const float);
extern ExportedBySGInfra char  CATGetLockDynamicLOD();
extern ExportedBySGInfra long  CATSetLockDynamicLOD( int);

extern ExportedBySGInfra int  CATGetGenerateLODsOnSave();
extern ExportedBySGInfra void CATSetGenerateLODsOnSave(const int);
extern ExportedBySGInfra char CATGetLockGenerateLODsOnSave();
extern ExportedBySGInfra long CATSetLockGenerateLODsOnSave(int);

extern ExportedBySGInfra float CATGetCullVanishingRatio();
extern ExportedBySGInfra void CATSetCullVanishingRatio(const float);
extern ExportedBySGInfra char CATGetLockCullVanishingRatio();
extern ExportedBySGInfra long CATSetLockCullVanishingRatio(int);

extern ExportedBySGInfra int  CATGetTransparencyMode();
extern ExportedBySGInfra void CATSetTransparencyMode(const int);
extern ExportedBySGInfra char CATGetLockTransparencyMode();
extern ExportedBySGInfra long CATSetLockTransparencyMode(int);

extern ExportedBySGInfra int  CATGetGraphicsAPI();
extern ExportedBySGInfra void CATSetGraphicsAPI(const int);
extern ExportedBySGInfra char CATGetLockGraphicsAPI();
extern ExportedBySGInfra long CATSetLockGraphicsAPI(int);

extern ExportedBySGInfra int  CATGetOutline();
extern ExportedBySGInfra void CATSetOutline(const int);
extern ExportedBySGInfra char CATGetLockOutline();
extern ExportedBySGInfra long CATSetLockOutline( int);

extern ExportedBySGInfra unsigned int CATGetPreselectedElement();
extern ExportedBySGInfra void         CATSetPreselectedElement(const unsigned int);
extern ExportedBySGInfra char         CATGetLockPreselectedElement();
extern ExportedBySGInfra long         CATSetLockPreselectedElement( int);

extern ExportedBySGInfra int  CATGetCompassConfiguration();
extern ExportedBySGInfra void CATSetCompassConfiguration(const int);
extern ExportedBySGInfra char CATGetLockCompassConfiguration();
extern ExportedBySGInfra long CATSetLockCompassConfiguration(int);

extern ExportedBySGInfra int  CATGetHighlightActivation();
extern ExportedBySGInfra void CATSetHighlightActivation(const int);
extern ExportedBySGInfra char CATGetLockHighlightActivation();
extern ExportedBySGInfra long CATSetLockHighlightActivation( int);

// FUN085229 prehighlight of hidden objects ++
extern ExportedBySGInfra int  CATGetHiddenObjectsHighlightActivation();
extern ExportedBySGInfra int  CATGetHiddenObjectsPreHighlightActivation();
extern ExportedBySGInfra void  CATSetHiddenObjectsHighlightActivation(const int);
extern ExportedBySGInfra void  CATSetHiddenObjectsPreHighlightActivation(const int);
// FUN085229 prehighlight of hidden objects --

extern ExportedBySGInfra int  CATGetNoZBufferSelectionMode();
extern ExportedBySGInfra void CATSetNoZBufferSelectionMode(const int);
extern ExportedBySGInfra char CATGetLockNoZBufferSelectionMode();
extern ExportedBySGInfra long CATSetLockNoZBufferSelectionMode( int);

extern ExportedBySGInfra int  CATGetBoundingBoxSelectionMode();
extern ExportedBySGInfra void CATSetBoundingBoxSelectionMode(const int);
extern ExportedBySGInfra char CATGetLockBoundingBoxSelectionMode();
extern ExportedBySGInfra long CATSetLockBoundingBoxSelectionMode(int);

extern ExportedBySGInfra int  CATGetColorBackgroundMode();
extern ExportedBySGInfra void CATSetColorBackgroundMode(const int);
extern ExportedBySGInfra char CATGetLockColorBackgroundMode();
extern ExportedBySGInfra long CATSetLockColorBackgroundMode( int);

extern ExportedBySGInfra void CATGetBackgroundRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetBackgroundRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockBackgroundRGB();
extern ExportedBySGInfra long CATSetLockBackgroundRGB(int);

extern ExportedBySGInfra void CATGetNoShowBackgroundRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetNoShowBackgroundRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockNoShowBackgroundRGB();
extern ExportedBySGInfra long CATSetLockNoShowBackgroundRGB(int);

extern ExportedBySGInfra void CATGetSelectedElementRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetSelectedElementRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockSelectedElementRGB();
extern ExportedBySGInfra long CATSetLockSelectedElementRGB(int);
extern ExportedBySGInfra void CATGetAdvancedSelectedElementRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetAdvancedSelectedElementRGB(const unsigned int, const unsigned int, const unsigned int);

extern ExportedBySGInfra void CATGetPreselectedElementRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetPreselectedElementRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockPreselectedElementRGB();
extern ExportedBySGInfra long CATSetLockPreselectedElementRGB(int);
extern ExportedBySGInfra void CATGetAdvancedPreSelectedElementRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetAdvancedPreSelectedElementRGB(const unsigned int, const unsigned int, const unsigned int);

extern ExportedBySGInfra void CATGetSelectedEdgeRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetSelectedEdgeRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockSelectedEdgeRGB();
extern ExportedBySGInfra long CATSetLockSelectedEdgeRGB(int);

extern ExportedBySGInfra void CATGetUnderIntensifiedRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetUnderIntensifiedRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockUnderIntensifiedRGB();
extern ExportedBySGInfra long CATSetLockUnderIntensifiedRGB(int);

extern ExportedBySGInfra void CATGetHandlesRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetHandlesRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockHandlesRGB();
extern ExportedBySGInfra long CATSetLockHandlesRGB( int);

extern ExportedBySGInfra void CATGetUpdateNeededRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetUpdateNeededRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockUpdateNeededRGB();
extern ExportedBySGInfra long CATSetLockUpdateNeededRGB(int);

extern ExportedBySGInfra unsigned int CATGetHighlightMode();
extern ExportedBySGInfra void CATSetHighlightMode(const unsigned int);
extern ExportedBySGInfra char CATGetLockPreHighlightMode();
extern ExportedBySGInfra long CATSetLockPreHighlightMode(int);

extern ExportedBySGInfra unsigned int CATGetPreHighlightMode();
extern ExportedBySGInfra void CATSetPreHighlightMode(const unsigned int);
extern ExportedBySGInfra char CATGetLockPreHighlightMode();
extern ExportedBySGInfra long CATSetLockPreHighlightMode(int);

extern ExportedBySGInfra int  CATGetGravity();
extern ExportedBySGInfra void CATSetGravity(const int);
extern ExportedBySGInfra char CATGetLockGravity();
extern ExportedBySGInfra long CATSetLockGravity( int);

extern ExportedBySGInfra unsigned int CATGetOtherSelectionTimeoutActivity();
extern ExportedBySGInfra void         CATSetOtherSelectionTimeoutActivity(const unsigned int);

extern ExportedBySGInfra char CATGetLockOtherSelectionTimeoutActivity();
extern ExportedBySGInfra long CATSetLockOtherSelectionTimeoutActivity(int);

extern ExportedBySGInfra float CATGetOtherSelectionTimeout();
extern ExportedBySGInfra void  CATSetOtherSelectionTimeout(const float);
extern ExportedBySGInfra char  CATGetLockOtherSelectionTimeout();
extern ExportedBySGInfra long  CATSetLockOtherSelectionTimeout(int);

extern ExportedBySGInfra int  CATGetPreSelectionMode();
extern ExportedBySGInfra void CATSetPreSelectionMode(const int);
extern ExportedBySGInfra char CATGetLockPreSelectionMode();
extern ExportedBySGInfra long CATSetLockPreSelectionMode( int);

extern ExportedBySGInfra int  CATGetPreSelNavigatorStartedByArrowKeys();
extern ExportedBySGInfra void CATSetPreSelNavigatorStartedByArrowKeys(const int);
extern ExportedBySGInfra char CATGetLockPreSelNavigatorStartedByArrowKeys();
extern ExportedBySGInfra long CATSetLockPreSelNavigatorStartedByArrowKeys(int);

extern ExportedBySGInfra int  CATGetAntiAliasingMode();
extern ExportedBySGInfra void CATSetAntiAliasingMode(const int);
extern ExportedBySGInfra char CATGetLockAntiAliasingMode();
extern ExportedBySGInfra long CATSetLockAntiAliasingMode( int);

extern ExportedBySGInfra float CATGetAntiAliasingOffset();
extern ExportedBySGInfra void  CATSetAntiAliasingOffset(const float);

extern ExportedBySGInfra int  CATGetViewpointAnimationMode();
extern ExportedBySGInfra void CATSetViewpointAnimationMode(const int);
extern ExportedBySGInfra char CATGetLockViewpointAnimationMode();
extern ExportedBySGInfra long CATSetLockViewpointAnimationMode( int);

// h55 21Oct2011  Functions related to frame rate options are removed under highlight
//extern ExportedBySGInfra int  CATGetMinimumFPSMode();
//extern ExportedBySGInfra void CATSetMinimumFPSMode(const int);
//extern ExportedBySGInfra char CATGetLockMinimumFPSMode();
//extern ExportedBySGInfra long CATSetLockMinimumFPSMode( int);
//
//extern ExportedBySGInfra int  CATGetNumberOfMinimumFPS();
//extern ExportedBySGInfra void CATSetNumberOfMinimumFPS(const int);
//extern ExportedBySGInfra char CATGetLockNumberOfMinimumFPS();
//extern ExportedBySGInfra long CATSetLockNumberOfMinimumFPS( int);

extern ExportedBySGInfra int  CATGetMaxSelectionMove();
extern ExportedBySGInfra void CATSetMaxSelectionMove(const int);
extern ExportedBySGInfra char CATGetLockMaxSelectionMove();
extern ExportedBySGInfra long CATSetLockMaxSelectionMove( int);

extern ExportedBySGInfra int  CATGetGravityAxis();
extern ExportedBySGInfra void CATSetGravityAxis(const int);
extern ExportedBySGInfra char CATGetLockGravityAxis();
extern ExportedBySGInfra long CATSetLockGravityAxis( int);

extern ExportedBySGInfra int  CATGetAnimationEdgeMode();
extern ExportedBySGInfra void CATSetAnimationEdgeMode(const int);
extern ExportedBySGInfra char CATGetLockAnimationEdgeMode();
extern ExportedBySGInfra long CATSetLockAnimationEdgeMode( int);

extern ExportedBySGInfra int  CATGetOcclusionCullingMode();
extern ExportedBySGInfra void CATSetOcclusionCullingMode(const int);
// r7v 18-FEB-14 Functions related to "Occlusion culling enabled" option are removed under development
/*extern ExportedBySGInfra char CATGetLockOcclusionCullingMode();
extern ExportedBySGInfra long CATSetLockOcclusionCullingMode( int);*/

extern ExportedBySGInfra int  CATGetAllZBufferElementMode();
extern ExportedBySGInfra void CATSetAllZBufferElementMode(const int);
extern ExportedBySGInfra char CATGetLockAllZBufferElementMode();
extern ExportedBySGInfra long CATSetLockAllZBufferElementMode( int);

extern ExportedBySGInfra int  CATGetHiddenEdgeMode();
extern ExportedBySGInfra void CATSetHiddenEdgeMode(const int);
extern ExportedBySGInfra char CATGetLockHiddenEdgeMode();
extern ExportedBySGInfra long CATSetLockHiddenEdgeMode( int);

extern ExportedBySGInfra int  CATGetUndoMode();
extern ExportedBySGInfra void CATSetUndoMode(const int);
extern ExportedBySGInfra char CATGetLockUndoMode();
extern ExportedBySGInfra long CATSetLockUndoMode( int);

extern ExportedBySGInfra int  CATGetSWNavigationMode();
extern ExportedBySGInfra void CATSetSWNavigationMode(const int);
extern ExportedBySGInfra char CATGetLockSWNavigationMode();
extern ExportedBySGInfra long CATSetLockSWNavigationMode( int);

extern ExportedBySGInfra int  CATGetFlyCollisionMode();
extern ExportedBySGInfra void CATSetFlyCollisionMode(const int);
extern ExportedBySGInfra char CATGetLockFlyCollisionMode();
extern ExportedBySGInfra long CATSetLockFlyCollisionMode( int);

extern ExportedBySGInfra int  CATGetFlySensitivity();
extern ExportedBySGInfra void CATSetFlySensitivity(const int);
extern ExportedBySGInfra char CATGetLockFlySensitivity();
extern ExportedBySGInfra long CATSetLockFlySensitivity( int);

extern ExportedBySGInfra int  CATGetFlySpeedMode();
extern ExportedBySGInfra void CATSetFlySpeedMode(const int);

extern ExportedBySGInfra int  CATGetFlySpeed();
extern ExportedBySGInfra void CATSetFlySpeed(const int);
extern ExportedBySGInfra char CATGetLockFlySpeedMode();
extern ExportedBySGInfra long CATSetLockFlySpeedMode( int);

extern ExportedBySGInfra int  CATGetBorderEdgesMode();
extern ExportedBySGInfra void CATSetBorderEdgesMode(const int);
extern ExportedBySGInfra int  CATGetBorderEdgesThickness();
extern ExportedBySGInfra void CATSetBorderEdgesThickness(const int);

extern ExportedBySGInfra void CATGetBorderEdgesRGB(unsigned int *, unsigned int *, unsigned int *);
extern ExportedBySGInfra void CATSetBorderEdgesRGB(const unsigned int, const unsigned int, const unsigned int);
extern ExportedBySGInfra char CATGetLockBorderEdgesMode();
extern ExportedBySGInfra long CATSetLockBorderEdgesMode(int);

extern ExportedBySGInfra int  CATGetSharpeSmoothEdgesRatio();
extern ExportedBySGInfra void CATSetSharpeSmoothEdgesRatio(const int);
extern ExportedBySGInfra char CATGetLockSharpeSmoothEdgesMode();
extern ExportedBySGInfra long CATSetLockSharpeSmoothEdgesMode(int LockMode);

extern ExportedBySGInfra int  CATGetTwoSideLightingMode();
extern ExportedBySGInfra void CATSetTwoSideLightingMode(const int);
extern ExportedBySGInfra char CATGetLockTwoSideLightingMode();
extern ExportedBySGInfra long CATSetLockTwoSideLightingMode( int);

extern ExportedBySGInfra int  CATGetBackFaceCullingMode();
extern ExportedBySGInfra void CATSetBackFaceCullingMode(const int);
extern ExportedBySGInfra char CATGetLockBackFaceCullingMode();
extern ExportedBySGInfra long CATSetLockBackFaceCullingMode( int);

extern ExportedBySGInfra int  CATGetLineicCgrMode();
extern ExportedBySGInfra void CATSetLineicCgrMode(const int);
extern ExportedBySGInfra char CATGetLockLineicCgrMode();
extern ExportedBySGInfra long CATSetLockLineicCgrMode( int);

extern ExportedBySGInfra int  CATGetHaloMode();
extern ExportedBySGInfra void CATSetHaloMode(const int);
extern ExportedBySGInfra char CATGetLockHaloMode();
extern ExportedBySGInfra long CATSetLockHaloMode( int);

extern ExportedBySGInfra int  CATGetAccuratePickingMode();
extern ExportedBySGInfra void CATSetAccuratePickingMode(const int);
extern ExportedBySGInfra char CATGetLockAccuratePickingMode();
extern ExportedBySGInfra long CATSetLockAccuratePickingMode( int);

extern ExportedBySGInfra int  CATGetGPUPicking();
extern ExportedBySGInfra void CATSetGPUPicking(const int);

extern ExportedBySGInfra int  CATGetFastGPUPicking();
extern ExportedBySGInfra void CATSetFastGPUPicking(const int);

//extern ExportedBySGInfra int  CATGetLightViewerMode();
//extern ExportedBySGInfra void CATSetLightViewerMode(const int);
//extern ExportedBySGInfra char CATGetLockLightViewerMode();
//extern ExportedBySGInfra long CATSetLockLightViewerMode( int);

extern ExportedBySGInfra int  CATGetMouseSpeedValue();
extern ExportedBySGInfra void CATSetMouseSpeedValue(const int);
extern ExportedBySGInfra char CATGetLockMouseSpeedValue();
extern ExportedBySGInfra long CATSetLockMouseSpeedValue( int);

extern ExportedBySGInfra int  CATGetKeyboardRotationAngleValue();
extern ExportedBySGInfra void CATSetKeyboardRotationAngleValue(const int);
extern ExportedBySGInfra char CATGetLockKeyboardRotationAngleValue();
extern ExportedBySGInfra long CATSetLockKeyboardRotationAngleValue( int);

extern ExportedBySGInfra int  CATGetMouseDoubleClicDelay();
extern ExportedBySGInfra void CATSetMouseDoubleClicDelay(const int);
extern ExportedBySGInfra char CATGetLockMouseDoubleClicDelay();
extern ExportedBySGInfra long CATSetLockMouseDoubleClicDelay( int);

extern ExportedBySGInfra int  CATGetPickingWindowSize();
extern ExportedBySGInfra void CATSetPickingWindowSize(const int);
extern ExportedBySGInfra char CATGetLockPickingWindowSize();
extern ExportedBySGInfra long CATSetLockPickingWindowSize( int);

extern ExportedBySGInfra int  CATGetAccuratePickingWindowSize();
extern ExportedBySGInfra void CATSetAccuratePickingWindowSize(const int);
extern ExportedBySGInfra char CATGetLockAccuratePickingWindowSize();
extern ExportedBySGInfra long CATSetLockAccuratePickingWindowSize( int);

// h55 21Oct2011  Functions related to frame rate options are removed under highlight
//extern ExportedBySGInfra int  CATGetMinimumSpaceFPSMode();
//extern ExportedBySGInfra void CATSetMinimumSpaceFPSMode(const int);
//extern ExportedBySGInfra char CATGetLockMinimumSpaceFPSMode();
//extern ExportedBySGInfra long CATSetLockMinimumSpaceFPSMode(int);
//
//extern ExportedBySGInfra int  CATGetNumberOfMinimumSpaceFPS();
//extern ExportedBySGInfra void CATSetNumberOfMinimumSpaceFPS(const int);
//extern ExportedBySGInfra char CATGetLockNumberOfMinimumSpaceFPS();
//extern ExportedBySGInfra long CATSetLockNumberOfMinimumSpaceFPS(int);

extern ExportedBySGInfra int  CATGetFollowGroundMode();
extern ExportedBySGInfra void CATSetFollowGroundMode(const int);
extern ExportedBySGInfra char CATGetLockFollowGroundMode();
extern ExportedBySGInfra long CATSetLockFollowGroundMode(int);

extern ExportedBySGInfra float CATGetFollowGroundAltitude();
extern ExportedBySGInfra void  CATSetFollowGroundAltitude(const float);
extern ExportedBySGInfra char  CATGetLockFollowGroundAltitutde();
extern ExportedBySGInfra long  CATSetLockFollowGroundAltitude(int);

extern ExportedBySGInfra int  CATGetFlyCollisionType();
extern ExportedBySGInfra void CATSetFlyCollisionType(const int);
extern ExportedBySGInfra char CATGetLockFlyCollisionType();
extern ExportedBySGInfra long CATSetLockFlyCollisionType(int);

extern ExportedBySGInfra float CATGetFlyCollisionShereRadius();
extern ExportedBySGInfra void  CATSetFlyCollisionSphereRadius(const float);
extern ExportedBySGInfra char  CATGetLockFlyCollisionSphereRadius();
extern ExportedBySGInfra long  CATSetLockFlyCollisionSphereRadius(int);

extern ExportedBySGInfra int  CATGetShaderMode();
extern ExportedBySGInfra void CATSetShaderMode(const int);
extern ExportedBySGInfra int  CATGetMouseFreeMode();
extern ExportedBySGInfra void CATSetMouseFreeMode(const int);
extern ExportedBySGInfra char CATGetLockMouseFreeMode();
extern ExportedBySGInfra long CATSetLockMouseFreeMode( int);
extern ExportedBySGInfra int  CATGetNavigIconMode();
extern ExportedBySGInfra void CATSetNavigIconMode(const int);
extern ExportedBySGInfra char CATGetLockNavigIconMode();
extern ExportedBySGInfra long CATSetLockNavigIconMode( int);

// h55 29-NOV-12 Functions related to "openGL Shader Enable" option are removed under development
//extern ExportedBySGInfra char CATGetLockShaderMode();
//extern ExportedBySGInfra long CATSetLockShaderMode( int);

extern ExportedBySGInfra int  CATGetAxisSystemLength();
extern ExportedBySGInfra void CATSetAxisSystemLength(const int);
extern ExportedBySGInfra char CATGetLockAxisSystemLength();
extern ExportedBySGInfra long CATSetLockAxisSystemLength( int);

extern ExportedBySGInfra int  CATGetDisplayCurrentScale();
extern ExportedBySGInfra void CATSetDisplayCurrentScale(const int);
extern ExportedBySGInfra char CATGetLockDisplayCurrentScale();
extern ExportedBySGInfra long CATSetLockDisplayCurrentScale( int);

extern ExportedBySGInfra int  CATGetSLIMode();
extern ExportedBySGInfra void CATSetSLIMode(const int);
extern ExportedBySGInfra char CATGetLockSLIMode();
extern ExportedBySGInfra long CATSetLockSLIMode(int);

extern ExportedBySGInfra int  CATGetStaticBatchingMode();
extern ExportedBySGInfra void CATSetStaticBatchingMode(const int);
extern ExportedBySGInfra char CATGetLockStaticBatchingMode();
extern ExportedBySGInfra long CATSetLockStaticBatchingMode( int);

extern ExportedBySGInfra int  CATGetRotationSphereMode();
extern ExportedBySGInfra void CATSetRotationSphereMode(const int);
extern ExportedBySGInfra char CATGetLockRotationSphereMode();
extern ExportedBySGInfra long CATSetLockRotationSphereMode( int);extern ExportedBySGInfra void CATSaveVisualizationRepository();

extern ExportedBySGInfra void CATCommitVisualizationRepository();
extern ExportedBySGInfra void CATInitializeVisualizationRepository(const int force=0, const int onglet=0);
extern ExportedBySGInfra void CATRollbackVisualizationRepository();
extern ExportedBySGInfra CATSettingRepository * CATGetVisualizationRepository();

extern ExportedBySGInfra int  CATGetDisplayDrillList();
extern ExportedBySGInfra void CATSetDisplayDrillList(const int);
extern ExportedBySGInfra char CATGetLockDisplayDrillList();
extern ExportedBySGInfra long CATSetLockDisplayDrillList( int);

extern ExportedBySGInfra int  CATGetAuxiliaryDrillViewer();
extern ExportedBySGInfra void CATSetAuxiliaryDrillViewer(const int);
extern ExportedBySGInfra char CATGetLockAuxiliaryDrillViewer();
extern ExportedBySGInfra long CATSetLockAuxiliaryDrillViewer( int);

extern ExportedBySGInfra int  CATGetFaceHLDrill();
extern ExportedBySGInfra void CATSetFaceHLDrill(const int);
extern ExportedBySGInfra char CATGetLockFaceHLDrill();
extern ExportedBySGInfra long CATSetLockFaceHLDrill( int);

extern ExportedBySGInfra int  CATGetDisplayImmersiveDrillViewer();
extern ExportedBySGInfra void CATSetDisplayImmersiveDrillViewer(const int);
extern ExportedBySGInfra char CATGetLockDisplayImmersiveDrillViewer();
extern ExportedBySGInfra long CATSetLockDisplayImmersiveDrillViewer( int);

extern ExportedBySGInfra int  CATGetDisplayImmersiveDrillViewer();
extern ExportedBySGInfra void CATSetDisplayImmersiveDrillViewer(const int);
extern ExportedBySGInfra char CATGetLockDisplayImmersiveDrillViewer();
extern ExportedBySGInfra long CATSetLockDisplayImmersiveDrillViewer( int);

extern ExportedBySGInfra int  CATGetDisplayImmersiveDrillViewer();
extern ExportedBySGInfra void CATSetDisplayImmersiveDrillViewer(const int);
extern ExportedBySGInfra char CATGetLockDisplayImmersiveDrillViewer();
extern ExportedBySGInfra long CATSetLockDisplayImmersiveDrillViewer( int);

extern ExportedBySGInfra int  CATGetDisplayImmersiveDrillViewer();
extern ExportedBySGInfra void CATSetDisplayImmersiveDrillViewer(const int);
extern ExportedBySGInfra char CATGetLockDisplayImmersiveDrillViewer();
extern ExportedBySGInfra long CATSetLockDisplayImmersiveDrillViewer( int);

extern ExportedBySGInfra float CATGetDefaultDiffuseAmbientCoefficient();
extern ExportedBySGInfra void  CATSetDefaultDiffuseAmbientCoefficient(const float);
extern ExportedBySGInfra char  CATGetLockDefaultDiffuseAmbientCoefficient( );
extern ExportedBySGInfra long  CATSetLockDefaultDiffuseAmbientCoefficient( int );

extern ExportedBySGInfra float CATGetDefaultSpecularCoefficient();
extern ExportedBySGInfra void  CATSetDefaultSpecularCoefficient(const float);
extern ExportedBySGInfra char  CATGetLockDefaultSpecularCoefficient(  );
extern ExportedBySGInfra long  CATSetLockDefaultSpecularCoefficient( int );

extern ExportedBySGInfra int   CATGetAmbientActivation();
extern ExportedBySGInfra void  CATSetAmbientActivation(const int);
extern ExportedBySGInfra char  CATGetLockAmbientActivation( );
extern ExportedBySGInfra long  CATSetLockAmbientActivation( int );

extern ExportedBySGInfra float CATGetDefaultShininess();
extern ExportedBySGInfra void  CATSetDefaultShininess(const float );
extern ExportedBySGInfra char  CATGetLockDefaultShininess( );
extern ExportedBySGInfra long  CATSetLockDefaultShininess( int );

extern ExportedBySGInfra unsigned int  CATGetFullSceneAntiAliasingMode();
extern ExportedBySGInfra void CATSetFullSceneAntiAliasingMode(const unsigned int);
extern ExportedBySGInfra char CATGetLockFullSceneAntiAliasingMode();
extern ExportedBySGInfra long CATSetLockFullSceneAntiAliasingMode( int);

extern ExportedBySGInfra unsigned int  CATGetAAOnSSAO();
extern ExportedBySGInfra void CATSetAAOnSSAO(const unsigned int);
extern ExportedBySGInfra char CATGetLockAAOnSSAO();
extern ExportedBySGInfra long CATSetLockAAOnSSAO( int);

extern ExportedBySGInfra unsigned int  CATGetAADynamic();
extern ExportedBySGInfra void CATSetAADynamic(const unsigned int);
extern ExportedBySGInfra char CATGetLockAADynamic();
extern ExportedBySGInfra long CATSetLockAADynamic(int);

extern ExportedBySGInfra unsigned int  CATGetOutlinesDynamic();
extern ExportedBySGInfra void CATSetOutlinesDynamic(const unsigned int);
extern ExportedBySGInfra char CATGetLockOutlinesDynamic();
extern ExportedBySGInfra long CATSetLockOutlinesDynamic(int);

// FUN091486 Tight Reframe All ++
extern ExportedBySGInfra int CATGetTightReframeModeActivation();
extern ExportedBySGInfra void CATSetTightReframeModeActivation(const int);
// FUN091486 Tight Reframe All --

// TSK3948779 Transparency for ghosted parts in Ghosting and in Filter 3dview
extern ExportedBySGInfra int CATGetGhostedTransparencyValue();
extern ExportedBySGInfra void CATSetGhostedTransparencyValue(const int);
//

extern ExportedBySGInfra int   CATGetOpaqueFaces();
extern ExportedBySGInfra void  CATSetOpaqueFaces(const int );
extern ExportedBySGInfra char  CATGetLockOpaqueFaces( );
extern ExportedBySGInfra long  CATSetLockOpaqueFaces( int );

//Video memory management
extern ExportedBySGInfra int   CATGetUnloadMemoryFromGPU();
extern ExportedBySGInfra void  CATSetUnloadMemoryFromGPU(const int);
extern ExportedBySGInfra char  CATGetLockUnloadMemoryFromGPU();
extern ExportedBySGInfra long  CATSetLockUnloadMemoryFromGPU( int);

extern ExportedBySGInfra int   CATGetMeshCompressionNormalEnable();
extern ExportedBySGInfra void  CATSetMeshCompressionNormalEnable(const int);
extern ExportedBySGInfra char  CATGetLockMeshCompressionNormalEnable();
extern ExportedBySGInfra long  CATSetLockMeshCompressionNormalEnable(int);

// LDH
extern ExportedBySGInfra int   CATGetLDHTargetFramerate();
extern ExportedBySGInfra void  CATSetLDHTargetFramerate(const int);
extern ExportedBySGInfra char  CATGetLockLDHTargetFramerate();
extern ExportedBySGInfra long  CATSetLockLDHTargetFramerate(int);
extern ExportedBySGInfra int   CATIsLDHTargetFramerateExplicit();

// View mode Appearances
extern ExportedBySGInfra int   CATGetViewModeUIVersion();
extern ExportedBySGInfra void  CATSetViewModeUIVersion(const int);
extern ExportedBySGInfra char  CATGetLockViewModeUIVersion();
extern ExportedBySGInfra long  CATSetLockViewModeUIVersion(int);

#endif
