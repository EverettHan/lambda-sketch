
#if defined(__CATPolyConvexHullMT)
#define ExportedByCATPolyConvexHullMT DSYExport
#else
#define ExportedByCATPolyConvexHullMT DSYImport
#endif
#include "DSYExport.h"

class CATPolyVoxelConvexHull;
class CATSoftwareConfiguration;
typedef CATPolyVoxelConvexHull* (*FPCREATEVCH) (char *iTempFilesPrefix, CATSoftwareConfiguration *iConfig);
extern "C" ExportedByCATPolyConvexHullMT CATPolyVoxelConvexHull* CreateVCHImpl( char *iTempFilesPrefix, CATSoftwareConfiguration *iConfig );
