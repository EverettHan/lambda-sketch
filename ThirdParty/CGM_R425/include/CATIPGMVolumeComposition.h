#ifndef CATIPGMVolumeComposition_h_
#define CATIPGMVolumeComposition_h_

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMTopOperator.h"

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMVolumeComposition;


/**
 * Interface representing an operator that assembles several volumic bodies.
 *
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateVolumeComposition</tt> global function.
 * <li>Run it
 * <li>Get the resulting body with the <tt>GetResult</tt> method. If you do not want
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the
 * geometric factory, after the operator deletion.
 *<li>delete it after use  with the usual C++ <tt>delete</tt> operator.
 *</ul>
 */
class ExportedByCATGMOperatorsInterfaces CATIPGMVolumeComposition: public CATIPGMTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMVolumeComposition();

  /**
   * Destructor
   */
  virtual ~CATIPGMVolumeComposition();

  /**
  * Forces the priority to be given to bodies by their order in the list
  * (disregarding any further improvement of "priority" criteria)
  * @param iDoThat
  * Whether to force that priority. By default, it is not done.
  */
  virtual void SetForcePriorityToFirstBody(CATBoolean iDoThat) = 0;

  /**
  * Requests (or not) the following of volumes in the journal of the operator
  * @param iDoThat
  * Whether to register the volumes in the journal. By default, it is not done.
  */
  virtual void SetVolumeJournalMode(CATBoolean iDoThat) = 0;

};

/**
 * Creates a CATTopVolumeComposition.
 * @param iFactory
 * The pointer to the factory of the geometry for the creation of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param ipBodiesList
 * List of volumic bodies to join to one another
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByCATGMOperatorsInterfaces CATIPGMVolumeComposition* CATPGMCreateVolumeComposition(
    CATGeoFactory       * ipFactory,
    CATTopData          * ipTopData,
    CATLISTP(CATBody)   * ipBodiesList);

#endif /* CATIPGMVolumeComposition_h_ */
