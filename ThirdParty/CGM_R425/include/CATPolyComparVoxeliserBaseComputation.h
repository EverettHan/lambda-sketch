#ifndef CATPolyComparVoxeliserBaseComputation_H
#define CATPolyComparVoxeliserBaseComputation_H
//====================================================================
// Copyright Dassault Systemes Provence 2011, All Rights Reserved 
//====================================================================
// DESCRIPTION : Voxellisation d'un mesh compatible multithread
// (voxelisation of one triangle inspirated from XXC's CATPolyVoxelPartitionIteratorTriangle)
// It avoids the many small allocation used in XXC's algorithm for each triangles
// And have small separated struct for each thread
// Sample Use using the Pierre Reiss PoolThread:
/*
CATPolyComparVoxeliserBaseComputation Voxeliser(Partition,oTriangles,NbTrianglesToDo,_MaxThreads);
#if defined(_WINDOWS_SOURCE) && defined(_WIN64)
  const bool CanDoMultiThread= _MaxThreads>1  && _TheThreadPool 
    && NbTrianglesToDo>MinTrianglesToEnableMultiThread  ;
#else
  const bool CanDoMultiThread= false;
#endif
  if(CanDoMultiThread)
  {
    //Synchronous Thread Multi-Threading
    _TheThreadPool->SetStobAlgo( (CATBaseComputation*) &Voxeliser,(CATThreadRun) &CATPolyComparVoxeliserBaseComputation::BaseJob );
    //Dispatch and launch the work
    _TheThreadPool->OwordDispatcher  ( NbTrianglesToDo );
  }
  else
  {
    //One Job At once treating all triangles
    Voxeliser.BaseJob(0,0,NbTrianglesToDo);//??
  }

  int VoxeliserErr=Voxeliser. Flatten(oOffsetAndSize,//Previously allocated to NbVoxels)
    oTrianglesByBox);//Allocated inside
*/
//
//=============================================================================
// HISTORIQUE :
//
//  02/05/2011 : RNO     : Creation !!!
//=============================================================================

#include "ExportedByCATPolyComparOperators.h"
#include "CATListOfInt.h"
//#include "VisGPGPUTypes.h"
//#include "DSYSysJob.h"
#include "CATMathInline.h"
#include "CATMathOBB.h"
#include <functional>

class CATPolyVoxelPartition;
class CATMathPoint;

//#define MESHASDOUBLE
//#ifdef MESHASDOUBLE
//#define MESHCOORDTYPE gpgpu_double4
//#else
//#define MESHCOORDTYPE gpgpu_float4
//#endif
class ExportedByCATPolyComparOperators CATPolyComparVoxeliserBaseComputation
{

public :
  //CATPolyComparVoxeliserBaseComputation(const CATPolyVoxelPartition & Partition,
  //  MESHCOORDTYPE * TrianglesCoord, unsigned int NbTriToDo, int NbThread);

 

  ~CATPolyComparVoxeliserBaseComputation();

  void SetApplyOBBToTriangleCoord(const CATMathOBB & OBB);

  //Voxelise les triangles de Debut a Fin et les ranges dans les listes entre _VoxelRes+Tid et _VoxelRes+Tid+NbVoxels
  //int BaseJob(CATLONG64 Tid, CATLONG64 Debut, CATLONG64 Fin);
  

  //int Flatten(gpgpu_uint2 * oOffsetAndSize,//Previously allocated to NbVoxels)
  //          unsigned int *& oTrianglesByBox);



  //RESERVED FOR THE CONNOISSSEURS

   CATPolyComparVoxeliserBaseComputation(const CATPolyVoxelPartition & Partition);
   unsigned int GetHalfGridArea() const{return _HalfPixelArea;}
  //Voxelise a Triangle defined by 3 CATMathPoint 
  //The Method will callback the std::function with VoxelNum , TriNum
  void VoxeliseOneTriangle( const CATMathPoint Triangle[3], 
    char * BuffGrid2D, const std::function<void (unsigned int )> & VoxelEvent);



private:
  bool _ApplyOBB;
  CATMathOBB _OBB;
  const CATPolyVoxelPartition & _Partition;
  unsigned int VoxelSize[3];
  //MESHCOORDTYPE * _TriCoord;
  unsigned int _NbTri, _NbVoxels;
  int _NbThread;
  CATListOfInt * _TrianglesByBox;
  //unsigned int * _Dbg,*_Dbg2;
  //void ConvertTriangleFromMathPointToFl4(CATMathPoint MTri[3],gpgpu_float4 Fri[3]);
 
  void PseudoBresenham(char * grid2D, const unsigned int dimGrid, const unsigned int dim1, const char mask,
                                                            const double a[3], const int Va[3], const double b[3], const int Vb[3],
                                                            const unsigned int dir1, const unsigned int dir2);
  unsigned int _NbVoxelsByDim[3];
  unsigned int _MaxDimGrid;
  unsigned int _HalfPixelArea;//Sommme des pixels du Voxels
  char * _grid2D;//3*Max*NbThread
};


//class CATPolyVoxeliserSysJob : public DSYSysJob
//{
//public :
//  INLINE CATPolyVoxeliserSysJob():DSYSysJob(),m_Job(0),_Tid(0), _Debut(0),  _Fin(0),_Err(0){};
//  INLINE ~CATPolyVoxeliserSysJob(){m_Job=0; }
//  INLINE void SetJob(CATPolyComparVoxeliserBaseComputation * iJob,CATLONG64 iTid, CATLONG64 iDebut, CATLONG64 iFin){m_Job=iJob; _Tid=iTid; _Debut=iDebut;  _Fin=iFin;}
//
//  INLINE void Execute(){_Err=m_Job->BaseJob(_Tid,_Debut,_Fin); };
//private:
//  CATPolyComparVoxeliserBaseComputation * m_Job;;
//  int _Err;
//  CATLONG64 _Tid, _Debut,  _Fin;
//};
#endif

