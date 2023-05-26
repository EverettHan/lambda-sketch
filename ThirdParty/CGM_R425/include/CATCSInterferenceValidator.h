// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSInterferenceValidator.h
// Header definition of CATCSInterferenceValidator
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sept 2013  Creation:                       Emmanuel Lechine
//===================================================================

#ifndef CATCSInterferenceValidator_H
#define CATCSInterferenceValidator_H

#include "CATCDS.h"
#include "CATCSEntity.h"
#include "CATCDSListP.h"
#include "CATCDSGlobalParameters.h"
#include "CATCSGeometry.h"

//#define COLLISION_TECHNO_TRACE_ON
#define FEDERATE_MODE

class CATCSNIntermittentModel;
class CATCDSTransformation;
class CATCDS3Vector;
class CATCSRigidSet;
class CATCSInterferenceDescription;
class CATCSContact;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSInterferenceValidator
{
public:
  CATCSInterferenceValidator();
  CATCSInterferenceValidator(int iNbRigidSets, CATCSRigidSet **iaRigidSets);
  virtual ~CATCSInterferenceValidator();

  virtual void Initialize();

  /**
  * Computes a clash detection between the declared rigid sets
  * @param oBadness
  *   A pointer to a double (optional) : global badness of the collisions (positive ratio with the following meaning :
  *                                      <= 1. -> we are in the tolerance area : contact
  *                                      > 1.  -> we have an outright clash)
  * @return
  *   The number of detected collisions
  */
  virtual int IncompatiblePositions(double* oBadness = NULL) = 0;

  /**
  * Returns collision information computed during the last call to IncompatiblePositions
  * @param oRigidSetsInCollision
  *   A pointer to a list of CATCSGeometry (optional) : geometries involved in a collision.
  * @param oRigidSetCouplesInCollision
  *   A pointer to a list of CATCSGeometry (optional) : geometries involved in a collision sorted by couples.
  * @param oRigidSetCouplesBadness
  *   A pointer to a list of double (optional) : badness of collision couples.
  * @return
  *   TRUE if a collision occured, FALSE otherwise
  * @see #ResetCollisionInformation
  */
  virtual CATCDSBoolean IsCollisionDetected(CATCDSLISTP(CATCSGeometry)* oRigidSetsInCollision = NULL, CATCDSLISTP(CATCSGeometry)* oRigidSetCouplesInCollision = NULL, CATCDSArray<double> *oRigidSetCouplesBadness = NULL) = 0;

  /**
  * Resets the cumulative collision information
  * @see #GetCumulativeCollisionInformation
  */
  virtual void ResetCumulativeCollisionInformation() = 0;

  /**
  * Retreives the cumulative collision information computed since the last call to ResetCumulativeCollisionInformation (or the creation of the object)
  * @param oRigidSetsInCollision
  *   A pointer to a list of CATCSGeometry (optional) : geometries involved in a collision.
  * @return
  *   TRUE if a collision occured, FALSE otherwise
  * @see #ResetCumulativeCollisionInformation
  */
  virtual CATCDSBoolean GetCumulativeCollisionInformation(CATCDSLISTP(CATCSGeometry) & oRigidSetsInCollision) = 0;

  // interference mode
  void SetInterferenceMode(CATCDSInterferenceMode iInterferenceMode);
  inline CATCDSInterferenceMode GetInterferenceMode() {return _InterferenceMode;}

  // Set/Get rigidsets
  virtual void SetRigidSets(int iNbRigidSets, CATCSRigidSet **iaRigidSets);
  virtual void GetRigidSets(int &oNbRigidSets, CATCSRigidSet **&oaRigidSets);

  virtual void SetTransformation(int iRigidSetIndex, const double iMatrix[3][3], const double iTranslation[3]) = 0;
  virtual void ComposeTransformation(int iRigidSetIndex, const double iMatrix[3][3], const double iTranslation[3]){};
  virtual void ResetAllTransformations(){};


  //todo migrate all subclasses to pure virtual
  virtual CATCSInterferenceDescription*  GetInterferenceDescription(CATCSContact* iContact) {return NULL;}


protected:
  CATCDSInterferenceMode _InterferenceMode;
  CATCSRigidSet **_aRigidSets;
  int _nRigidSets;

};
 
//-----------------------------------------------------------------------

#endif
