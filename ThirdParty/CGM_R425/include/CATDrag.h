// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATDrag_H
#define CATDrag_H
///////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// interface du Drag CATIA
// 23/02/96
/////////////////////////////////////////////////////////////////////////////////// 

/**
* @level Protected
* @usage U1
*/

#ifdef _WINDOWS_SOURCE
#include <ole2.h>
#endif

// System
#include "CATBaseUnknown.h"
// ObjectModelerBase
#include "CATFormat.h"
#include "CATFormats.h"
#include "CP0CLIP.h"

#ifdef _WINDOWS_SOURCE
#if defined(_MFC_VER) && _MFC_VER>=0x0800
typedef DWORD DROPEFFECT;
#define      DROPEFFECT_NONE ( 0 )
#define      DROPEFFECT_COPY ( 1 )
#define      DROPEFFECT_MOVE ( 2 )
#define      DROPEFFECT_LINK ( 4 )
#define      DROPEFFECT_SCROLL       ( 0x80000000 )
#else
#include <afxwin.h>
#endif
#else
#ifndef UIUTIL_H
typedef enum tagDROPEFFECT {
  DROPEFFECT_NONE = 0,
  DROPEFFECT_COPY = 1,
  DROPEFFECT_MOVE = 2,
  DROPEFFECT_LINK = 4,
  DROPEFFECT_SCROLL = 0x80000000
} DROPEFFECT;
#endif
#endif


class CATCLE;

//Drag Initialization (e.g. for copy/cut operations)
ExportedByCP0CLIP
  void CATOpenDrag();

ExportedByCP0CLIP
  void CATSetDrag(CATBaseUnknown_ptr, const CATFormat*);

// either 0: nothing more to do; 1: copy_only ; 2 cut/remove may be done 
ExportedByCP0CLIP
  int CATCloseDrag(DWORD PossibleEffects = DROPEFFECT_NONE);

//Drag Query (e.g. for paste operation)
ExportedByCP0CLIP
  CATBaseUnknown_ptr CATGetDrag(const CATFormat*);

ExportedByCP0CLIP
  CATLISTP(CATFormat) CATGetDragFormats();

//-------------------- System Depandant Implementation for multi-process

ExportedByCP0CLIP
  CATBaseUnknown* CATGetObjectDrag();

ExportedByCP0CLIP
  int CATSetSystemDrag(void* system_data);

ExportedByCP0CLIP
  void* CATGetSystemDrag();

#ifdef _WINDOWS_SOURCE
//Dragged data format
ExportedByCP0CLIP
  CLIPFORMAT CATGetLastDragDataFormat();
#endif

#endif
