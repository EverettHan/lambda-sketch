// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATVisuServices_H
#define CATVisuServices_H

#include "CATVisCommands.h"
#include "CATErrorDef.h"

class CATIStandardValue;
class CATViewer;
class CATIStandardUIObject;

extern void  ExportedByCATVisCommands CATSetStandard(CATIStandardValue *, char *, CATViewer*);

extern void  ExportedByCATVisCommands CATSetLineTypeStandard(CATIStandardValue *, char *, CATViewer*);

extern HRESULT  ExportedByCATVisCommands CATSetStandardFromViewer(CATIStandardUIObject *, char *, CATViewer*);

#endif
