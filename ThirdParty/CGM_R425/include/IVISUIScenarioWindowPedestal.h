// COPYRIGHT DASSAULT SYSTEMES 2011

#ifndef IVISUIScenarioWindowPedestal_H
#define IVISUIScenarioWindowPedestal_H

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIScenario.h"



extern ExportedByIVInterfaces IID IID_IVISUIScenarioWindowPedestal;


/**
 * Interface enabling an object-centric navigation scenario.
 * <strong>Role</strong>: This interface allows the user to walk around a virtual object as if it were exposed on a virtual pedestal.
 *
 * @see IVISUIManager, IVISUIScenario
 */
class ExportedByIVInterfaces IVISUIScenarioWindowPedestal : public IVISUIScenario
{

  CATDeclareInterface;

public: 

  /**
   * Allows to lock the navigation to match the physical gravity.
   *
   * @param [in] iGravityLock
   *   Should be set to 1 in order to lock navigation around the physical gravity, 0 otherwise. 
   *
   */
	virtual void SetPhysicalGravityLock(const unsigned int iGravityLock) = 0;
  
  /**
   * Allows to tell if the navigation has been locked to match the physical gravity.
   *
   * @return
   *   1 if the navigation has been locked (default value), 0 otherwise.
   */
  virtual unsigned int GetPhysicalGravityLock() const = 0;


};

CATDeclareHandler(IVISUIScenarioWindowPedestal, IVISUIScenario);

#endif
