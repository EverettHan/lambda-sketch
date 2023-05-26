// COPYRIGHT Dassault Systemes 2016

#ifndef CATCSContact_H
#define CATCSContact_H

#include "CATCDSVirtual.h"
#include "CATCDSBoolean.h"
#include "CATCDS.h"
#include "CATCSConstraint.h"
#include "CATCDSEnums.h"
#include "CATCDSListP.h"

class CATCSRigidSet;

//-----------------------------------------------------------------------

/**
 * A basic class for contacts.
 */
class ExportedBySolverInterface CATCSContact : public CATCSConstraint
{
public:
  /**
   * Constructs an instance of the contact between iRS1 and iRS2.
   */
  CATCSContact(CATCSRigidSet* iRS1, CATCSRigidSet* iRS2);

  virtual ~CATCSContact();

  /**
   * Checks whether the entity is matched to a specific type. The entity can
   * be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual CATCDSType GetType() const CATCDSOverride;

  void GetRigidSets(CATCSRigidSet*& oRS1, CATCSRigidSet*& oRS2);

private:
  CATCSRigidSet *_rs1, *_rs2;
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSContact, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif
