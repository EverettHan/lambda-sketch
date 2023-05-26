// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFillHoleOperObserver.h
//
//===================================================================
// 
//===================================================================
#ifndef CATPolyFillHoleOperObserver_H
#define CATPolyFillHoleOperObserver_H

#include "CATPolyConvexHullExport.h"
#include "CATPolyFillHoleOper.h"
#include "CATIPolyMesh.h"
#include "CATErrorDef.h"


/**
 * Observer class to CATPolyFillHoleOperOper.
 */
class ExportedByCATPolyFillHolesOperators CATPolyFillHoleOperObserver
{

public:

  virtual ~CATPolyFillHoleOperObserver ();

public:

  ///////////////////////
  //ReactTo methods
  virtual void ReactToSetInputMesh (const CATIPolyMesh &iMesh) = 0;
  virtual void ReactToSetHoleID (const CATListOfInt &iList) = 0;  
  virtual void ReactToSetOutputMesh (CATIPolyMesh &iMesh) = 0;

public:
  virtual void AfterConstructor () = 0;
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
  
};

#endif
