#ifndef UIVCoreToolsCATDeclareClass_withexport_H
#define UIVCoreToolsCATDeclareClass_withexport_H

// COPYRIGHT DASSAULT SYSTEMES  2017
#include "CATMacForIUnknownEx.h"    // CATDeclareClass_CustomExport

#define CATDeclareClass_withexport(ExportedBy)  \
        CATDeclareClass_CustomExport(ExportedBy,/*Empty_VirtualNoExport*/)

#endif  // UIVCoreToolsCATDeclareClass_withexport_H
