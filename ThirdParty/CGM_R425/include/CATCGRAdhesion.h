// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATCGRAdhesion.h
// Header definition of CATCGRAdhesion
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2003  Creation: Code generated by the CAA wizard  jut
//===================================================================
#ifndef CATCGRAdhesion_H
#define CATCGRAdhesion_H

#include "CATCGRAdhesionUtils.h"
#include "CATListOfCATUnicodeString.h"

// Visu FW
class CATRep;
class CATCGRContainer;
class CATCGRSetting;

// The following macros declares an empty class in order
// to be able to call code outside the visualization FW
// for the CGR adhesion, without any prereqs.
//
// In order to do that, you must implement CATICGRContainer
// on one of these class (contact SVQ for more informations)
//
// These macros also handle the activation switches for the
// adhesion, stored in a repository.
//
// Let's take the class V4_Model_CommentPage as an example.
// For this class, the following things are generated by the
// macros :
// 
// -  A class deriving from CATBaseUnknown : V4_Model_CommentPage
//    and implementing CATICreateInstance.
//    It is on this class that you must implement CATICGRContainer
//    if you want to be called back during the save of the CGR.
//
// -  The following methods in order to access and set the activation
//    switch in the repository
//
//    int  CATGetCGR_V4_Model_CommentPage();
//    void CATSetCGR_V4_Model_CommentPage(const int iOn);

CATVizDeclareCGRAdhesion(V4_Model_CommentPage);
CATVizDeclareCGRAdhesion(V4_Model_LnF);
CATVizDeclareCGRAdhesion(V5_SPA);
CATVizDeclareCGRAdhesion(V4V5_FDT);
CATVizDeclareCGRAdhesion(Voxels);

/**@nodoc
 * Global actions to the CATSetting file "CGRFormat".
 */
extern ExportedBySGInfra HRESULT CATSaveCGRRepository();
extern ExportedBySGInfra HRESULT CATCommitCGRRepository();
extern ExportedBySGInfra HRESULT CATRollbackCGRRepository();
extern ExportedBySGInfra HRESULT CATInitCGRRepository();

/**@nodoc
 * Generic setters and getters on parameters in the CATSetting file "CGRFormat".
 */
extern ExportedBySGInfra int     CATGetCGRRepositoryValue(const char *iSettingName);
extern ExportedBySGInfra HRESULT CATSetCGRRepositoryValue(const char *iSettingName, int iValue);
extern ExportedBySGInfra char    CATGetCGRRepositoryLock(const char *iSettingName);
extern ExportedBySGInfra HRESULT CATSetCGRRepositoryLock(const char *iSettingName, int iLockMode);


/* @nodoc
 * This function fetch the applicative containers of the current scenegraph.
 */
extern ExportedBySGInfra HRESULT CATFetchApplicativeContainers(CATRep *iRep, CATCGRContainer * attachTo);

/* @nodoc
 * This function loads the applicative containers of the current scenegraph.
 */
extern ExportedBySGInfra HRESULT CATLoadApplicativeContainers(CATRep *iRep, CATBaseUnknown * iModel, CATCGRContainer * attachedFrom, CATListOfCATUnicodeString * containerList = 0);

/* @nodoc
 * This function returns the number of adhesion.
 */
extern ExportedBySGInfra int CATGetCGRAdhesionCount();

/* @nodoc
 * This function returns the adhesion name.
 */
extern ExportedBySGInfra const char * CATGetCGRAdhesionName(int index);

/* @nodoc
 * This function returns the number of adhesion that are currently
 * requested by the user (the corresponding settings are ON).
 */
extern ExportedBySGInfra int CATGetCGRAdhesionCurrentlyRequested();

/* @nodoc
 * This function activates or desactivates the save of applicative.
 * containers.
 */
extern ExportedBySGInfra void CATSetCGRAdhesionActivated(int iActivate);

/* @nodoc
 * This function returns the state of the save of applicative.
 * containers.
 */
extern ExportedBySGInfra int  CATGetCGRAdhesionActivated();

/* @nodoc
 * This function activates or desactivates the light scene graph.
 */
extern ExportedBySGInfra void CATSetLightSceneGraph(int iOnOff);

/* @nodoc
 * This function returns the state of the light scene graph activation.
 */
extern ExportedBySGInfra int  CATGetLightSceneGraph();

/* @nodoc
 * This function locks or unlocks the light scene graph setting.
 */
extern ExportedBySGInfra HRESULT CATSetLockLightSceneGraph(int LockMode);

/* @nodoc
 * This function returns the lock state of the light scene graph setting.
 */
extern ExportedBySGInfra char CATGetLockLightSceneGraph();

/* @nodoc
 * This function returns the state of the smart loading activation.
 */
extern ExportedBySGInfra int  CATGetSmartLoading();

/* @nodoc
 * This function defines the state of the smart loading unload mechanism.
 */
extern ExportedBySGInfra void CATSetSmartLoadingUnload(CATBoolean iOnOff, unsigned int iMaxSizeInBytes);

/* @nodoc
 * This function returns the state of the smart loading unload mechanism.
 */
extern ExportedBySGInfra void CATGetSmartLoadingUnload(CATBoolean & oOnOff, unsigned int & oMaxSizeInBytes);

/* @nodoc
 * This function sets the voxel accuracy used for CGR voxels generation (in mm).
 */
extern ExportedBySGInfra void CATSetVoxelsAccuracy(int iAccuracy);

/* @nodoc
 * This function returns the voxel accuracy used for CGR voxels generation (in mm).
 */
extern ExportedBySGInfra int  CATGetVoxelsAccuracy();

/* @nodoc
 * This function fetch the applicative containers of the current scenegraph.
 */
extern ExportedBySGInfra HRESULT CATApplicativeContainersCGRSettingsOverride(CATRep *iRep, CATCGRSetting *ioCGRSettings);

#endif