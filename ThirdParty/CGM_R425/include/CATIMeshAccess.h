#ifndef CATIMeshAccess_H
#define CATIMeshAccess_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//    Interface defining access to mesh required functions:
//      . Generation of a tesselation,
//      . Generation of a 3D bounding element.
//
//******************************************************************************
//  Usage:
//  ------
//
//******************************************************************************
//  Inheritance:
//  ------------
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************

#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"
#include "CATDataType.h"

class CAT3DBoundingSphere;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIMeshAccess;
#else
extern "C" const IID IID_CATIMeshAccess;
#endif




class ExportedBySceneGraphManager CATIMeshAccess : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
  
  public:
    
    virtual void GetMesh (int *nbtopo,int *topo,
			  double *sag,double *step,
			  double *basesom,int *ialsom,CATINTPTR *iofsom,int *nbsom,
			  double *basenor,int *ialnor,CATINTPTR *iofnor,int *nbnor,
			  double *basetri,int *ialtri,CATINTPTR *ioftri,int *nbtri,
			  double *baseelt,int *ialelt,CATINTPTR *iofelt,int *nbelt,
			  double *baserec,int *ialrec,CATINTPTR *iofrec,int *nbrec,
			  int *ier) = 0;
    
    virtual CAT3DBoundingSphere *GetBoundingElement () = 0;

    virtual int IsShaded() = 0 ;
}; 


CATDeclareHandler(CATIMeshAccess,CATBaseUnknown);


#endif
