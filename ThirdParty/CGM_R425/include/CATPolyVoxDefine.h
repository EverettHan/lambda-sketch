//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//==============================================================================================================

// CATPolyVoxDefine : definitions of constants used to bound the memory size of a CATPolyBasicOctree and its dependant classes

//==============================================================================================================
// Creation : DPS/CHU March 2006
//==============================================================================================================

#ifndef CATPolyVoxDefine_H
#define CATPolyVoxDefine_H

// _MaxOctreeDepth_ is the depth of the smallest possible voxels, taking 0 for the root itself

//    => there are at most 2**_MaxOctreeDepth_ smallest voxels per dimension X, Y or Z
//       or 2**(3*_MaxOctreeDepth_) = 8**_MaxOctreeDepth_ smallest voxels in total
//    => the smallest voxel's size is the reference box size divided by 2**_MaxOctreeDepth_
//       (note that the "reference box" mentioned above is generally obtained by inflating
//        the processed body by a value that covers all expected offset values)
//    => the maximum total number of voxels (of all sizes) is [8**(_MaxOctreeDepth_+1)-1] / (8-1)

//    => there are at most 1+2**_MaxOctreeDepth_ addressable points (corners) per dimension X, Y or Z,
//       but a CATPolyVtxOctree cannot set information on the X-max or Y-max or Z-max points because points are
//       always referenced by the _MaxOctreeDepth_voxel that they bound at its X-min, Y-min, Z-min corner
//    => theoretically, points may be indexed between 0 and _MaxIJKIndexOfCorner_ = 2**_MaxOctreeDepth_,
//       but useable points (qualifying to bear a field) in a CATPolyVtxOctree are indexed between 0 and 2**_MaxOctreeDepth_
//    => In a Vtx-Octree, the number of bits required to code an addressable point in each dimension is _MaxOctreeDepth_

// This number of bits per corner coordinate is called _NbBitsPerCornerCoord_

// The following definition ensures that _NbBitsPerCornerCoord_ = _MaxOctreeDepth_ + 1
enum { _MaxOctreeDepth_ = 15, _NbBitsPerCornerCoord_ };

enum { _MaxIJKIndexOfCorner_ = 32768 }; // must remain = 2**_MaxOctreeDepth_ (leftmost corner has index=0 by convention)

// Dump syntax for octrees abd vreps hold versioning :
// Version 1 : CATPolyOctreeOld (fat model) and associated vreps
// Version 2 : CATPolyBasicOctree (current) and associated vreps
enum { _BasicOctreeDumpVersion = 2 };
enum { _VRepDumpVersion = 2 };

// CATPolyOctoCube objects bear tags for debug purposes only, if the following 
// variable is set (re-build VRep.m after a change)
//#define VREP_DEBUG

// if the following  variable is set (re-build VRep.m after a change), all objects will be counted
//#define VREP_COUNTER

#endif
