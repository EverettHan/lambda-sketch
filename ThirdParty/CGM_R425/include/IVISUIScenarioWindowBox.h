	// COPYRIGHT DASSAULT SYSTEMES 2011

#ifndef IVISUIScenarioWindowBox_H
#define IVISUIScenarioWindowBox_H

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIScenario.h"



extern ExportedByIVInterfaces IID IID_IVISUIScenarioWindowBox;


/**
* Interface representing an interaction context.
* <strong>Role</strong>: This interface provides methods to access the User Element entities and the PhysicalEnvironment entity attached to the InteractionContext.
*
* @see IVISUIManager, IVISUIElement, IVISUIUser, IVISUIPhysicalEnvironment
*/
class ExportedByIVInterfaces IVISUIScenarioWindowBox : public IVISUIScenario
{

  CATDeclareInterface;

public: 	

  enum InertialTrackerMode
  {
    eGravity = 0,
    eGyroscope = 1
  };	

  /**
  * Changes the way the current pose is computed regarding its reference pose. See #InertialTrackerMode
  *
  * @param [in] iMode
  *   The new way the device orientation is computed.
  *   By setting the mode to @c eGravity, the returned pose will be computed only from the gravity vector (rotation around Y Up axis are not taken into account, but the orientation of the box is not affected when the user rotate around himself).
  *   By setting the mode to @c eGyroscope, the returned pose wil be computed from the gyroscope (all rotation axis fully works, but if the user rotate around himself, the box's orientation is affected).
  *   
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd><tt>oMode</tt> is successfully set</dd>
  *     <dt>E_FAIL</dt>
  *     <dd><tt>oMode</tt> could not be set</dd>
  *   </dl>
  */
virtual HRESULT SetInertialTrackerMode(const IVISUIScenarioWindowBox::InertialTrackerMode iMode) = 0;


protected:


private:


 

};

CATDeclareHandler(IVISUIScenarioWindowBox, IVISUIScenario);

#endif
