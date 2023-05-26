#ifndef CATWheelEvent_H
#define CATWheelEvent_H

/* COPYRIGHT DASSAULT SYSTEMES 2002 */

#include "CATTimeStampedEvent.h"
#include "CATVisFoundation.h"
#include "CATMouseEvent.h"

class CATDevice;
class CATSupport;


class ExportedByCATVisFoundation CATWheelEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :
    CATWheelEvent();
    virtual ~CATWheelEvent();
  
    CATDevice *Device;
    CATSupport *pSupport;
    float _wheel;

    //Donnees temporaires: a supprimer
    //--------------------------------
    int _pressedButton;		// Pressed mouse button 
    int GeneralModifier;	// Modifiers status shared by all devices

    #define ShiftModifierOn    (1<<0)
    #define ControlModifierOn  (1<<2)
    #define AltModifierOn      (1<<3)
    #define SpaceModifierOn    (1<<4)
    //--------------------------------


private :

	int _MouseFlags; // mouse buttons state  cf CATMouseEvent for masks

	friend class CATGraphicWindow;
 	friend class CATMouseDevice;
    friend class CATViewer;
};
#endif
