#ifndef CATOmbRelationSnapshotSpecification_H
#define CATOmbRelationSnapshotSpecification_H

// COPYRIGHT Dassault Systemes 2008

/**
* @level Protected
* @usage U1
*/

// BSFBuildtimeData
#include "CATIAV5Level.h"
// CATPLMIdentificationAccess
#include "CATListPtrCATIPLMComponent.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATOmbRelationSnapshot;
class CATIPLMComponent;

typedef unsigned int CATOmbRerouteStrategy;

#define CATOmbRerouteStrategy_Cardinality                4
#define CATOmbRerouteStrategy_ALL                        0x11111111 /* All strategies */
#define CATOmbRerouteStrategy_ExistingMinorInSession     0x00000001 /* Minor sensitive relations which have a Not Opened status will be rerouted on existing minor in session if any */
#define CATOmbRerouteStrategy_SynchronizeBuildSpec       0x00000010 /* Minor unsentive relations which have a Solved status on a dynamic minor target in session but with a different build spec will be synchronized on the minor in session if possible */
#define CATOmbRerouteStrategy_ManualRerouteSpecified     0x00000000 /* Strategy specified by manual reroute, i.e. SetSpecifiedPointedComponent */

#if defined(CATIAR425)
#include "CATOmxSharable.h"
class ExportedByCATObjectModelerBase CATOmbRelationSnapshotSpecification : public CATOmxSharable
#else
#include "CATOmbUnknown.h"
class ExportedByCATObjectModelerBase CATOmbRelationSnapshotSpecification : public CATOmbUnknown
#endif
{
public:
  /*
   * Get the relation.
   * @return IUnknown#Release
   *   A pointer on @href CATOmbRelationSnapshot.
   */
  virtual CATOmbRelationSnapshot * GetRelation() = 0;

  /*
   * Get specified pointed components.
   * MUST IUnknown#Release each element of oSpecifiedPointedComponent.
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>S_FALSE</code> if no pointed component is specified.
   *   Otherwise associated failure code..
   */
  virtual HRESULT GetSpecifiedPointedComponent(CATLISTP(CATIPLMComponent) & oSpecifiedPointedComponent) = 0;


  /*
   * Set specified pointed components.
   */
  virtual void SetSpecifiedPointedComponent(CATLISTP(CATIPLMComponent) & iSpecifiedPointedComponent) = 0;

  /**
  *	AnalyseReroutePotential
  * <br><b>Role</b>: Analyse potential reroute strategies chosen by user
  *	for this relation
  * @param ioUserPossibleStrategies
  *		the strategies that can be applied
  * @return
  *   <code>S_OK</code> if everything ran ok and if reroute strategy chosen by user is can be applied.
  *   <code>S_FALSE</code> Reroute strategy chosen as input can not be applied.
  *   Otherwise associated failure code..
  */
  virtual HRESULT AnalyseReroutePotential(int & ioUserPossibleStrategies) = 0;

  /**
  * SetRerouteStrategies
  * <br><b>Role</b>: Set the wanted reroute strategies to be used by reroute.
  * Default value is CATOmbRerouteStrategy_ManualRerouteSpecified.
  * @param iStrategies
  *		the strategies that the manual reroute can use
  */
  virtual void SetRerouteStrategies(const CATOmbRerouteStrategy & iStrategies) = 0;

  /**
  *	GetRerouteStrategies
  * <br><b>Role</b>: Get the reroute strategies on the relation.
  * @param oStrategies
  *		the available strategies on the relation
  */
  virtual CATOmbRerouteStrategy GetRerouteStrategies() = 0;
};

#endif
