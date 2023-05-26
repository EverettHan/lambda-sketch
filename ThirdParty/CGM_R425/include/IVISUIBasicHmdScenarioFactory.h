//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2018
// -----------------------------------------------------------------------------
#ifndef IVISUIBasicHmdScenarioFactory_H
#define IVISUIBasicHmdScenarioFactory_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "IVISUIScenarioMultipipe.h"
class CATVizViewer;
class IVSUIExternalBehaviourFactory;

//-----------------------------------------------------------------------------
extern ExportedByIVInterfaces IID IID_IVISUIBasicHmdScenarioFactory;

//-----------------------------------------------------------------------------
/**
 * IVISUIBasicHmdScenarioFactory
 *
 * This factory can be used in order to build an IV Scenario which by default
 * provides an HMD device and displays its 
 *
 * You can tune/add some extra capabilities to the created scenario by using
 * the provided API.
 *
 * In order to create such a scenario, an HMD must be available.
 *
 */
class ExportedByIVInterfaces IVISUIBasicHmdScenarioFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Avatar display
   *
   * @param iOnOff Toggle the display controllers/tracker. By default the
   * controllers/trackers are displayed
   */
  virtual void Avatar(bool iOnOff) = 0; // default: true

  /**
   * Fly navigation
   *
   * @param iOnOff Enable the fly mode in the scenario. By default the
   * scenario doesnt provide the fly navigation mode.
   *
   * @note that this call is ignored if the display of the avatar is not
   * enabled
   */
  virtual void Fly(bool iOnOff) = 0; // default: false

  /**
   * Walk navigation
   *
   * @param iOnOff Enable the walk mode in the scenario. By default the
   * scenario doesnt provide the walk navigation mode.
   *
   * @note that this call is ignored if the display of the avatar is not
   * enabled
   */
  virtual void Walk(bool iOnOff) = 0; // default: false

  /**
   * Teleport navigation
   *
   * @param iOnOff Enable the teleport mode in the scenario. By default the
   * scenario doesnt provide the teleport navigation mode.
   *
   * @note that this call is ignored if the display of the avatar is not
   * enabled
   */
  virtual void Teleport(bool iOnOff) = 0; // default: false

  /**
   * Selection interaction
   *
   * @param iOnOff Enable the selection mode in the scenario. By default the
   * scenario doesnt provide the selection interaction mode.
   *
   * @note that this call is ignored if the display of the avatar is not
   * enabled
   */
  virtual void Selection(bool iOnOff) = 0; // default: false

  /**
   * Model scale
   *
   * @param iOnOff Set the model scale. The interaction context is initialized
   * accordingly.
   */
  virtual void Scale(double iScale) = 0; // default: 1.0

  /**
   * MasterRendering
   *
   * @param iOnOff Toggle the update of the 3DExperience viewer during the
   * scenario. By default the 3DExperience is still refreshed
   */
  virtual void MasterRendering(bool iOnOff) = 0; // default: true

  /**
   * Highlight/Prehighlight
   *
   * @param iOnOff Toggle the management of the highlight/prehighlight during
   * the scenario. By default the highlight prehighlight are not disabled.
   */
  virtual void Highlight(bool iOnOff) = 0;       // default: true
  virtual void PreHighlight(bool iOnOff) = 0;    // default: true

  /**
   * Mirror window
   *
   * @param iOnOff Toggle the availability of the feedback window. By default,
   * the mirror window is created.
   */
  virtual void MirrorWindow(bool iOnOff) = 0;    // default: true

  /**
   * External behaviours
   */
  virtual void AddExternalBehaviour(IVSUIExternalBehaviourFactory* iBehaviourFactory) = 0;

  /**
   * Build the IV scenario.
   *
   * @return The scenario. NULL if internal error or preconditions not met
   * (e.g. HMD not available)
   */
  virtual IVISUIScenarioMultipipe_var BuildScenario() const = 0;
};

//-----------------------------------------------------------------------------
/**
 * IVISUIBasicHmdScenarioFactory_var
 */
CATDeclareHandler(IVISUIBasicHmdScenarioFactory, CATBaseUnknown);

//-----------------------------------------------------------------------------
/**
 * Instantiate a factory
 */
IVISUIBasicHmdScenarioFactory_var ExportedByIVInterfaces IVISUIBasicHmdScenarioFactory_Create(CATVizViewer* iVP);

#endif
