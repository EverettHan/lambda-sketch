// COPYRIGHT Dassault Systemes 2011
//=================================================================================================
#ifndef CATVisuNavigationNotifyToolbox_H
#define CATVisuNavigationNotifyToolbox_H

#include "CATVisController.h"
#include "CATDlgUtility.h"

class CATUnicodeString;
class CATString;
class CATDlgWindow;

class ExportedByCATVisController CATVisuNavigationNotifyToolbox
{
public:
	/**
	*  Displays a notify window (CATDlgNotify)
	* @param iObjectName
	*   The internal name of the popup window.
	* @param &iTitle
	*   The title of the window.
	* @param iText
	*   The message displayed by the window.
	* @param iStyle
	*   The style of the popup window. (see CATDlgNotify)
	* @return
	*   An integer identifying the button which has been pressed. (see CATDlgNotify)
	*/
	static int DisplayNotify(const CATString& iObjectName, CATDlgWindow *pWindow,
		const CATUnicodeString &iTitle,
		const CATUnicodeString &iText,
		CATDlgStyle iStyle = CATDlgNfyWarning | CATDlgNfyOK);

private:
	CATVisuNavigationNotifyToolbox();
	~CATVisuNavigationNotifyToolbox();
	CATVisuNavigationNotifyToolbox(const CATVisuNavigationNotifyToolbox&);
	CATVisuNavigationNotifyToolbox& operator= (const CATVisuNavigationNotifyToolbox&);
};
#endif
