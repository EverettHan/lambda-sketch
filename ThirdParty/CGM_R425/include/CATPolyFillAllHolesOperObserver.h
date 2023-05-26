// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFillAllHolesOperObserver.h
//
//===================================================================
// 
//===================================================================
#ifndef CATPolyFillAllHolesOperObserver_H
#define CATPolyFillAllHolesOperObserver_H

#include "CATPolyConvexHullExport.h"
#include "CATPolyFillAllHolesOper.h"
#include "CATIPolyMesh.h"
#include "CATErrorDef.h"


/**
 * Observer class to CATPolyFillAllHolesOperOper.
 */
class ExportedByCATPolyFillHolesOperators CATPolyFillAllHolesOperObserver
{

public:

  virtual ~CATPolyFillAllHolesOperObserver (){};

public:

  ///////////////////////
  //ReactTo methods
  virtual void ReactToSetInputMesh (const CATIPolyMesh &iMesh){};
  virtual void ReactToSetOutputMesh (CATIPolyMesh &iMesh){};

  virtual void ReactToHoleSize (int iSize){};
  virtual void ReactToLargestHoleFillOption (CATBoolean iSignal){};
  virtual void ReactToHolesLeft (int iNbHoles){};
  
public:
  virtual void AfterConstructor () = 0;
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
  
};

#endif
