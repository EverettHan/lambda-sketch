// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
// Nov 2014 Creation D1A
//===================================================================
#ifndef CATPolyFixSmallAngleTrianglesOperParams_H
#define CATPolyFixSmallAngleTrianglesOperParams_H

#include "CATPolyFixSmallAngleTrianglesOper.h"

#include "CATIPolyMesh.h"
#include "CATTolerance.h"
#include "CATListOfInt.h"
#include "CATCGMModif.h"

#include "CATPolyFace.h"
#include "CATIPolySurface.h"
#include "CATPolyMeshImpl.h"
#include "CATPolyBody.h"
#include "CATPolyBodyServices.h"
#include "CATIPolyMesh.h"

// For Phoenix
#include "CATechHandle.h"
#include "CATechSetup.h"
#include "CATechSet.h"
#include "CATechChannel.h"
#include "CATechAttribute.h"

/**
 * Class encapsulating the Operator parameters for cpaturing/running the operator
 * PolyFixSmallAngleTrianglesOper.  
 * During Phoenix Capture, the input parameters are saved.
 * During Phoenix replay, these parameters are read from an XML file.
 */

class ExportedByCATPolyRegularizeOperators CATPolyFixSmallAngleTrianglesOperParams
{

public:

  CATPolyFixSmallAngleTrianglesOperParams ();
  virtual ~CATPolyFixSmallAngleTrianglesOperParams ();

public:    

  void SetPolyMesh(CATIPolyMesh * iPMesh);
  CATIPolyMesh * GetPolyMesh();
  
  void SetAngleTolerance(double iAngTol);
  double GetAngleTolerance();
  

  void SetSmallTriangles(CATListOfInt& triangles);
  CATListOfInt & GetSmallTriangles();

  void SetDecimatedTriangles(CATListOfInt& triangles);
  CATListOfInt & GetDecimatedTriangles();

  CATBoolean IsOperRunDone();
  void SetOperRunDone(CATBoolean runDone);

  void SetAPIcall(CATUnicodeString api);
  CATLISTV(CATUnicodeString) & GetAPIcalls();

  CATBoolean IsInputMeshAvailable();

  void AppendTriangles(const CATListOfInt & triangles);
  CATListPV & GetListOfTriangles();
  CATListOfInt & getTrianglesSize();
    
private :

  double _AngleTol;
  CATListOfInt _TriangleIDs;
  CATIPolyMesh* _polyMesh;
  CATListPV _listOfTriangles;
  CATListOfInt _trianglesSize;

  CATListOfInt _decimatedTriangles;
  CATListOfInt _smallTriangles;
  CATBoolean _runDone;
  CATLISTV(CATUnicodeString) _APIcalls;
};

#endif
