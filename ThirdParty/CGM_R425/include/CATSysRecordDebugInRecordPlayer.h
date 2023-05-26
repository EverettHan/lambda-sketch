#ifndef CATSysRecordDebugInRecordPlayer_H
#define CATSysRecordDebugInRecordPlayer_H
// COPYRIGHT DASSAULT-SYSTEMES 2016

#include "JS0FM.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

ExportedByJS0FM CATBoolean CATSysGetBubblesVisibility();
ExportedByJS0FM CATBoolean CATSysGetTextsVisibility();
ExportedByJS0FM void CATSysSetBubblesText(CATUnicodeString);


//TVE6 - fonctions pour ajout au recordplayer des screenshots
ExportedByJS0FM CATBoolean CATSysGetIgnoreMotionEventsForScreenshots();
ExportedByJS0FM CATBoolean CATSysGetTakingScreenshots();
ExportedByJS0FM void CATSysSetScreenshotsFolder(CATUnicodeString itext);
ExportedByJS0FM CATUnicodeString CATSysGetScreenshotsFolder();
#endif
