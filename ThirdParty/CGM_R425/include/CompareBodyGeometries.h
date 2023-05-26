#ifndef CompareBodyGeometries_h
#define CompareBodyGeometries_h

/***************************************************************************************************************
 CompareBodyGeometries
--------------------------------------------------------------------------------------------------------------
Utility to compare 2 bodies using BodyMapping + CompareTopology + CompareGeometry

Input parameters:
 iConfig                               : software configuration
 iBodyToHL and iBodyRef                : bodies to compare
 iColor                                : TRUE to change color of cells of iBodyToHL

Output parameters:
 oDifferencesFound                     : TRUE if all cells of BodyToHL are present in BodyRef
 iDump and iLongDump                   : if not NULL, it is filled by comparison information
--------------------------------------------------------------------------------------------------------------
 2011 WEEK 42 LD2 Creation
 2019 WEEK 17 LD2 Now it works also with bodies in different factories
***************************************************************************************************************/

#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByCATCXTopology.h"

class CATGeoFactory;
class CATBody;
class CATSoftwareConfiguration;

#define CompareBody_MPMode                          int
#define CompareBody_MPMode_AllPoints                  0
#define CompareBody_MPMode_PointsUsedByAnyTopo        1
#define CompareBody_MPMode_PointsUsedByBodyToHL       2

#define CompareBody_DifferenceType                  int
#define CompareBody_DifferenceType_NotMapping         0
#define CompareBody_DifferenceType_NotIdentical       1
#define CompareBody_DifferenceType_NotShared          3
#define CompareBody_DifferenceType_NoDifference       4

struct ExportedByCATCXTopology CompareBody_Result
{
  CompareBody_Result();

  CATBoolean IsThereADifference();
  CATBoolean IsBodyMappingKO();

  CompareBody_DifferenceType _MostSevereDifference;
};

ExportedByCATCXTopology HRESULT CompareBodyGeometries(
  CATSoftwareConfiguration * iConfig,
  CATBody * iBodyToHL,
  CATBody * iBodyRef,
  CompareBody_Result & oResult,
  CATBoolean iColor,
  CATListOfCATUnicodeString * iDump,
  CATListOfCATUnicodeString * iLongDump,
  CompareBody_MPMode iMacroPointComparisonMode = CompareBody_MPMode_PointsUsedByAnyTopo,
  CATBoolean iConsiderAsSameIfSupportOfBodyToHLIsSmaller = TRUE,
  CATBoolean iCheckPersistencyOfLyingOnOfFirstTopo = TRUE);

#endif

