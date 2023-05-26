// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef _CATClip_H_
#define _CATClip_H_
///////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// interface du clipboard CATIA
// 23/02/96
/////////////////////////////////////////////////////////////////////////////////// 

/**
 * @level Protected 
 * @usage U1
 */

// System
#include "CATBaseUnknown.h"
// ObjectModelerBase
#include "CATFormat.h"
#include "CATFormats.h"
#include "CP0CLIP.h"

class CATCLE;
class CATDocument;

//Clipboard Initialization (e.g. for copy/cut operations)
ExportedByCP0CLIP
void CATOpenClipboard();
 
ExportedByCP0CLIP
void CATSetClipboard(CATBaseUnknown_ptr, const CATFormat*);
 
ExportedByCP0CLIP
void CATCloseClipboard();

//Clipboard Query (e.g. for paste operation)
ExportedByCP0CLIP
CATBaseUnknown_ptr CATGetClipboard(const CATFormat*);
 
ExportedByCP0CLIP
CATLISTP(CATFormat) CATGetClipboardFormats();
 
//-------------------- System Depandant Implementation for multi-process

//Pour demarer correctement un clipboard interactif a partir des headers...
ExportedByCP0CLIP
int IsSessionClipViewerLaunched();

ExportedByCP0CLIP
CATBaseUnknown* CATGetObjectClipboard();

ExportedByCP0CLIP
int CATSetSystemClipboard(void* system_data);

ExportedByCP0CLIP
void* CATGetSystemClipboard();

//--------------------  Useful Service ----------------------
// Document valuated as a source document
ExportedByCP0CLIP
void CATSetSourceDocument( CATDocument* Doc);
ExportedByCP0CLIP 
boolean CATClipIsDocSource ( const CATDocument& Doc);
ExportedByCP0CLIP
CATDocument* CATGetSourceDocument();

//Clipboard Initialization (e.g. for copy/cut operations)

ExportedByCP0CLIP
void CATOpenClipboardOle();

#endif
