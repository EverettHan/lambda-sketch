#ifndef CATDlgXToolkit_H
#define CATDlgXToolkit_H

// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "DI0PANV2.h"

#ifdef DRIVER_MOTIF

//#include <Xm/Xm.h>
#include <X11/Xlib.h>      // Display
#include <X11/Intrinsic.h> // XtAppContext

/** 
 * Class specific to Unix platforms, provides some XToolkit parameters.
 * <br>
 * <b>Role</b>:
 * Lets retrieve XToolkit application context and display.
 * <br>
 * It is targeted for very specific usages. Most application developers do not have to deal with this class.
 */

class ExportedByDI0PANV2 CATDlgXToolkit
{
public:
	/**
	 * Gets XToolkit application context.
	 */
	static XtAppContext GetXtAppContext();

	/**
	 * Gets XToolkit display.
	 */
	static Display * GetXtDisplay();
};

#endif

#endif
