#ifndef CATDlgBlackBoxProtected_H
#define CATDlgBlackBoxProtected_H

#include "CATDlgBlackBox.h"

/**
 * This class provides some usefull helpers
 */
class ExportedByDI0PANV2 CATDlgBlackBoxProtected
{
public:
	/**
   * @deprecated R425 Use GetParentWidgetEx
	 * Get the parent widget of a native widget
	 * @param iWidget the widget whose parent is requested
	 * @return the parent widget
	 */
	static CATSysWidget GetParentWidget(CATSysWidget iWidget);

	/**
	 * Get the parent widget of a native widget
	 * @param iWidget the widget whose parent is requested
	 * @return the parent widget
	 */
	static CATSysWidgetEx GetParentWidgetEx(CATSysWidgetEx iWidget);
};

#endif
