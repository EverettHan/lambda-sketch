#ifndef CATDlgA2XWatcherObject_H
#define CATDlgA2XWatcherObject_H
#include "DI0PANV2.h"
#include "CATUnicodeString.h"
#include <string>

class l_CATDialog;
class CATCommand;
class IDataObject;

/**
 * This class exposes the operations related to A2X and CATDlgFile
 */
class ExportedByDI0PANV2 CATDlgA2XWatcherObject
{
public:
    static CATBaseUnknown* GetRegisteredObject(const std::string& iSessionID);
    static void DestroyElement(l_CATDialog *watchedElement);
    static int DisplayBlocked(l_CATDialog *watchedElement);
	static void SetBusyCursor();
    static void RemoveBusyCursor();
    static void DisplayNonBlocking(l_CATDialog *watchedElement, CATUnicodeString message);
    static CATUnicodeString GetDragString();
    static IDataObject *GetA2XDragObject();
    CATDlgA2XWatcherObject(l_CATDialog *watchedElement);
    CATDlgA2XWatcherObject(CATCommand *watchedElement);
    ~CATDlgA2XWatcherObject();
private:
    l_CATDialog *_watchedElement;
    CATCommand *_watchedGlider;
};
#endif
