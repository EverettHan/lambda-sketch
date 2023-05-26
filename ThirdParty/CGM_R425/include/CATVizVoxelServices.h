// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATVizVoxelServices.h
// Header definition of CATVizVoxelServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2003  Creation: Code generated by the CAA wizard  svq
//===================================================================
#ifndef CATVizVoxelServices_H
#define CATVizVoxelServices_H

#include "SGInfra.h"

#include "CATVizPtrList.h"

class CATVizVoxelRep;
class CAT4x4Matrix;
class CATRepPath;
class CATMathPointf;
class CATCgrHeader;
class CATRep;
class CATVizVoxelGP;
class CATILockBytes2;

extern void ExportedBySGInfra ComputeChildPosition(int iPosition, const CATMathPointf & iCenter, float iHalfSize, CATMathPointf & oCenter, float & oHalfSize);
extern CATVizVoxelRep ExportedBySGInfra * CATReadVoxel(const char *filename, CATCgrHeader ** oHeader = NULL);
extern CATVizVoxelRep ExportedBySGInfra * CATReadVoxel(CATILockBytes2 *iLB2, CATCgrHeader ** oHeader = NULL);
extern CATVizPtrList<CATVizVoxelRep> ExportedBySGInfra CATReadVoxels(const char *filename);
extern CATVizPtrList<CATRepPath> ExportedBySGInfra GetCGRReps(CATRepPath & iRepPath);

#ifdef __cplusplus
extern "C" {
#endif
char ExportedBySGInfra *CATVizExtractVoxelTreeFromCGRFile(const char *iCgrPath, unsigned int * oSizeInBytes);
#ifdef __cplusplus
}
#endif

// Intersection methods
extern int ExportedBySGInfra Intersect(CATVizVoxelRep * iVoxelRep, float iPlane[4], float iClearance = 0.0f, const CAT4x4Matrix * iMatrixRep = 0);
extern int ExportedBySGInfra Intersect(CATVizVoxelRep * iVoxelRep1, CATVizVoxelRep * iVoxelRep2, float iClearance = 0.0f, const CAT4x4Matrix * iMatrixRep1 = 0, const CAT4x4Matrix * iMatrixRep2 = 0);
extern int ExportedBySGInfra Intersect(CATRepPath & iRepPath, float iPlane[4], float iClearance = 0.0f);


// Voxels generation

extern CATVizVoxelRep ExportedBySGInfra * CATVizGenerateVoxels(CATRep & iFrom, float iSizeInMM = 10.0f);


#endif