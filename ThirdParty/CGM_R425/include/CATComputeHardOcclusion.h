#ifndef CATComputeHardOcclusion_H
#define CATComputeHardOcclusion_H

// COPYRIGHT DASSAULT SYSTEMES 2002

//#include "SceneGraphManager.h"
#include "CATVisController.h"
#include"list.h"

class CATViewpoint;
class CAT3DViewpoint;
class CAT3DRep;
class CATRepPath;


//class ExportedBySceneGraphManager CATComputeHardOcclusion 
class ExportedByCATVisController CATComputeHardOcclusion
{
 public :

  CATComputeHardOcclusion (CAT3DViewpoint *, list<CATRepPath> *);
  virtual ~CATComputeHardOcclusion ();

  inline void SetComputeSize(int, int);

  void Compute();
 
 private :

  CAT3DViewpoint   *_viewpoint;
  CAT3DRep         *_rep;
  list<CATRepPath> *_rep_path_list;

  int _width;
  int _height;
};

inline void CATComputeHardOcclusion::SetComputeSize(int iWidth, int iHeight)
{
 _width  = iWidth;
 _height = iHeight;
}

#endif
