//===================================================================
//===================================================================
// CATCDSExternalCollisionDetection.cpp
// Header definition of class CATCDSExternalCollisionDetection
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014/10/08 Creation: Code generated by the 3DS wizard
//===================================================================

/**
@brief interface that developper must implement to declare a collision detection engine.

*/

#ifndef CATCDSExternalCollisionDetection_H
#define CATCDSExternalCollisionDetection_H

// Spatial builds CDS on VC12.  Some of the advanced
// C++ features are not supported on this compiler, and the collision detection
// functionality is not needed for them.
#if !defined(_MSC_VER)|| _MSC_VER >=1900

#include "CATCDSExternalObject.h"
#include "CATCDSBoolean.h"
#include "CATCDSFreelessArray.h"
#include "CATCDSVirtual.h"
#include "CATCDS3Vector.h"
#include "CATCDSCollisionData.h" // tmp

class CDSDynCollidable;
class CDSDynCollisionRule;
class CDSDynSolver;
//class CATCDSCollisionData;


// VERTEX mode is used for softbody collision detection
// TRIANGLE mode is the basic one
enum CATCDSMeshElementForCollision
{
	coCOLLISION_TRIANGLE,
	coCOLLISION_VERTEX,
  coCOLLISION_BOOLEAN
};

// =========================================================
//  interfaces for implementation of a clash operator
// =========================================================

class ExportedByCATCDSUtilities CATCDSExternalCollisionDetection : public CATCDSExternalObject
{

public:

  virtual CATCDSBoolean AddCollidable(CDSDynCollidable* ipCollidable) = 0;

  virtual void RemoveCollidable(CDSDynCollidable* ipCollidable) = 0;
  virtual void RemoveAllCollidables() = 0;

  //iMaxDepth : abort computation if depth exceeds this value
  //if negative, finish the computation
  //return FALSE if the depth exceeds iMaxDepth
  virtual CATCDSBoolean Run(double iMaxDepth) = 0;
	virtual CATCDSBoolean RunSoftBodyRules() { return FALSE; }

  virtual int GetNbCollisions() = 0;

  virtual int GetNbWarningContact() = 0;

  virtual void GetCollision(int iIndex, CATCDSCollisionData& ocd) = 0;

	virtual void GetVertexCollision(int iIndex, int& oVertexIndex, double& oDepth, CATCDS3Vector& oNormal, CDSDynCollidable*& opMasterCollidable, CDSDynCollidable*& opSlaveCollidable) {};
	virtual int GetNbVertexCollisions() { return 0;  };
  
  virtual void GetWarning(int iIndex, CATCDSCollisionData& ocd);
   
  virtual double GetMaxDepth() = 0;

  virtual void SetDefaultCollisionActive(CATCDSBoolean iCollisionEnabled) = 0;

  virtual CDSDynCollidable* GetCollidable(int iIndex) const = 0;

  //only for polyhedral clash: same normal for all contacts (TRUE), one normal per contact (FALSE)
  //by default one normal per contact
  virtual void SetOldNormalMode(CATCDSBoolean iMode) = 0;

  virtual void SetKinematicsMode(CATCDSBoolean iMode) = 0;

  virtual void Initialize() {}

  virtual void SetSolver(CDSDynSolver &iSolver) {}

  virtual void ComputeCollisions(CDSDynCollisionRule const &iRule, double iMaxDepth, CATCDSFreelessArray<CATCDSCollisionData> &oCollisions);

	virtual void CreateMeshes(CDSDynCollidable &iCollidable, CATCDSArray<unsigned int> const *ipParts) {}

protected:
  virtual ~CATCDSExternalCollisionDetection();
};

#endif
#endif
