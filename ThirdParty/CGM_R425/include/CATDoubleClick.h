#ifndef CATDoubleClick_H
#define CATDoubleClick_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Elementary event sent by the physical device to the logical 
//		device (CATDevice) containing the physical button number
//		when it has been double-clicked.
//------------------------------------------------------------------------------
// Usage :	Used to communicate from the GraphicWindow (that reaceve
//		X-events) to the Viewer which dispatch then to the device.
//------------------------------------------------------------------------------
// Class :	CATDoubleClick
//		  CATTimeStampedEvent
//------------------------------------------------------------------------------
#include "CATTimeStampedEvent.h"
#include "CATVisFoundation.h"
class CATDevice;
class CATSupport;


class ExportedByCATVisFoundation CATDoubleClick : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :

    CATDoubleClick();
    virtual ~CATDoubleClick();

    CATDevice *Device;
    CATSupport *pSupport;
    int Button;

    int XPos;
    int YPos;

private :

	int _MouseFlags; // mouse buttons state  cf CATMouseEvent for masks


	friend class CATGraphicWindow;
	friend class CATMouseDevice;
	friend class CATViewer;
  friend class CATMouseDeviceEditor;
	
};
#endif
