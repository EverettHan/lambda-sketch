//============================================================================================
// Copyright Dassault Systemes Provence 2018, All Rights Reserved
//============================================================================================
//
// CATPolyContinuousClashDetectionOperator.h
//
//============================================================================================
//
// Usage notes : Operator performing continuous clash detection between moving objects,
//               ie without time discretization.
//
//============================================================================================
// 15.11.2018 : RAQ : Déplacement dans PolyhedralOperatorsAdv
// 03.10.2018 : RAQ : Nouvelle API
// 09/04/2018 : CRE5 : Creation
//============================================================================================
#ifndef CATPolyContinuousClashDetectionOperator_H
#define CATPolyContinuousClashDetectionOperator_H

//Pour l'export
#include "ExportedByCATPolyContinuousClashDetection.h"

//Classe mère
#include "CATPolyRefCounted.h"

//Divers
#include "CATSysErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMSharedPtr.h"

//STL
#include <vector>

class CATIPolyMesh;
class CATPolyCCDObject;
class CATPolyCCDArticulatedTransformation;
class CATMathTransformation;

class ExportedByCATPolyContinuousClashDetection CATPolyContinuousClashDetectionOperator : public CATPolyRefCounted
{
public:

  virtual ~CATPolyContinuousClashDetectionOperator() {}

  //------- Input
  //Add object : the operator addrefs the object
  virtual HRESULT AddObject(CATPolyCCDObject* ipObject) = 0;

  //Enable or disable an object
  //All objects are enabled by default, disabling an object means that all pairs containing this object won't be processed when detecting clashes
  virtual HRESULT DisableObject(const CATPolyCCDObject* ipObject, const CATBoolean iDisable) = 0;

  //Remove object : all pairs referring the input object are removed
  //If iReleaseObject == TRUE : the object is released
  virtual HRESULT RemoveObject(const CATPolyCCDObject* ipObject, const CATBoolean iReleaseObject = FALSE) = 0;

  //Set clashing pairs (updates previous call to this method)
  virtual HRESULT SetClashingPair(const CATPolyCCDObject* ipObject1, const CATPolyCCDObject* ipObject2, const double iClearance) = 0;

  //Check whether a clashing pair is already defined and retrieve its clearance
  virtual HRESULT IsClashingPair(const CATPolyCCDObject* ipObject1, const CATPolyCCDObject* ipObject2, CATBoolean& oIsClashingPair, double* opClearance = 0) = 0;

  //Unset a clashing pair (to remove a pair of clashing elements)
  virtual HRESULT UnsetClashingPair(const CATPolyCCDObject* ipObject1, const CATPolyCCDObject* ipObject2) = 0;

  //Unset all clashing pairs
  virtual HRESULT UnsetAllClashingPairs() = 0;

  //Set/Get trajectory of a given object
  virtual HRESULT SetTrajectory(const CATPolyCCDObject* ipObject, const CATMathTransformation& iStartPosition, const CATMathTransformation& iEndPosition) = 0;
  virtual HRESULT GetTrajectory(const CATPolyCCDObject* ipObject, CATMathTransformation& oStartPosition, CATMathTransformation& oEndPosition) const = 0;

  virtual HRESULT SetTrajectory(const CATPolyCCDObject* ipObject, CATPolyCCDArticulatedTransformation const& iTransformation) = 0;

  //------- Run options :
  //Compute clash time
  virtual void SetComputeClashTime(const CATBoolean iComputeClashTime) = 0;

  //Multithread :
  // if iMaxNbThreads==1 : multithread is disabled
  // if iMaxNbThreads>0 : at most iMaxNbThreads threads will be used
  // if iMaxNbThreads==0 : automatic mode
  virtual void SetMultithread(const unsigned int iMaxNbThreads = 1) = 0;
  
  //------- Run the operator between two positions
  virtual HRESULT Run() = 0;

  //Struct to retrieve the collisions
  struct Collision
  {
    enum Type
    {
      Clearance = 0,
      Clash
    };

    Collision() {}

    Collision(Type iType, const CATPolyCCDObject* ipObject1, const CATPolyCCDObject* ipObject2):
      m_type(iType),
      m_pObject1(ipObject1),
      m_pObject2(ipObject2),
      m_clashTime(-1.0),
      m_clashTimeIsAccurate(true)
    {
    }

    ~Collision()
    {
      m_pObject1=m_pObject2=0;
    }

    //---- Data :
    Type m_type=Clash;
    const CATPolyCCDObject *m_pObject1=nullptr, *m_pObject2=nullptr;
    double m_clashTime=-1.0;
    bool m_clashTimeIsAccurate=true;  //debug only
  };

  //------- Retrieve clash informations
  virtual const std::vector<Collision>& GetAllCollisions() const = 0;


  //------- For debug purpose only
  virtual void SetVerbose(const CATBoolean iVerbose) = 0;
  

protected:

  CATPolyContinuousClashDetectionOperator() {}
};

/**
 * Operator creation, it must me deleted with the usual delete.
 *
 * @param iTrajectoryPrecision
 * The tolerance used to discretize the trajectories, it is the same for all the trajectories.
 * It represents the max sag between the exact shape of a moving object and its approximation.
 *
 * @return
 * A pointer to the operator.
 **/
ExportedByCATPolyContinuousClashDetection
  CATPolyContinuousClashDetectionOperator* CATCreateContinuousClashDetectionOperator(const double iTrajectoryPrecision);

#endif  //CATPolyContinuousClashDetectionOperator_H


