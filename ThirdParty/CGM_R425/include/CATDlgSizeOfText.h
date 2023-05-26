#ifndef CATDLGSIZEOFTEXT_H
#define CATDLGSIZEOFTEXT_H
// COPYRIGHT DASSAULT SYSTEMES 2005
#include "DI0PANV2.h"
#include "CATUnicodeString.h"
ExportedByDI0PANV2 void CATDlgSizeOfText(const CATUnicodeString& iLabel, int* ioHeight, int* ioWidth);
ExportedByDI0PANV2 void CATDlgSplitMessage(const CATUnicodeString &iMessage, CATUnicodeString &oMessage, const int ilmax);
#endif
