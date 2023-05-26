// COPYRIGHT DASSAULT SYSTEMES 2012

#ifndef IVISUIMarker_H
#define IVISUIMarker_H

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"

#include "IVISUIPositionedElement.h"

extern ExportedByIVInterfaces IID IID_IVISUIMarker;

/**
* Interface representing a marker.
*
* <strong>Role</strong>: Marker is a specialization of PositionedElement representing a tangible marker, landmark or beacon.
* It is especially useful in Augmented Reality scenarios, as it provides a link between the virtual and the real worlds.
* Its position and orientation can be retrieved using @see IVISUIPositionedElement#GetPose .
* Its position is the position of its center.
*
* @see IVISUIPositionedElement, IVISUIPhysicalEnvironment
*/

class ExportedByIVInterfaces IVISUIMarker: public IVISUIPositionedElement
{

  CATDeclareInterface;

public:
  
 /**
  * Sets the size of the Marker in millimeters.
  * This is the real-world size, as measured accurately using a ruler.
  * The width corresponds to the dimension along the x axis, and the height to the dimension along the y axis.
  *
  * NOTE: You can use this method before calling IVISUIScenarioMagicWindow#AddMarker.
  * However, if the marker has already been added to a scenario, this method should no longer be used!
  * Use IVISUIScenarioMagicWindow#SetMarkerSize instead!
  *
  * @param iWidth [in]
  *   The width of the marker in millimeters.
  * @param iHeight [in]
  *   The height of the marker in millimeters.
  */
  virtual void SetSize(double iWidth, double iHeight) = 0;

 /**
  * Retrieves the size of the Marker in millimeters.
  * This is the real-world size, as measured accurately using a ruler.
  * The width corresponds to the dimension along the x axis, and the height to the dimension along the y axis.
  *
  * @param oWidth [out]
  *   The width of the marker in millimeters.
  * @param oHeight [out]
  *   The height of the marker in millimeters.
  */
  virtual void GetSize(double& oWidth, double& oHeight) const = 0;

};

CATDeclareHandler(IVISUIMarker, IVISUIPositionedElement);

#endif
