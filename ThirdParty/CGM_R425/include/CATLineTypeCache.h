#ifndef CATLineTypeCache_H
#define CATLineTypeCache_H

// Copyright Dassault Systemes 2000
#include "CATVisController.h"
#include "CATBaseUnknown.h"
#include "CATListPV.h"

class CATRep;
class CATDialog;
class CATVizDisplayContext;

/** @nodoc */
typedef struct
{
   unsigned char * bitmap;
   int lineType;
} LineTypeImage;

/** @nodoc */
typedef struct
{
   CATVizDisplayContext * displayContext;
   CATListPV imageList;
} ContextCache;

class ExportedByCATVisController CATLineTypeCache : public CATBaseUnknown
{
 
//------------------------------------------------------------------------------
  public:

/** @nodoc */
     CATLineTypeCache();
/** @nodoc */
     virtual ~CATLineTypeCache();
/** @nodoc */
     static CATLineTypeCache * GetLineTypeCache();
/** @nodoc */
     unsigned char * GetLineTypeBitmap(CATDialog * iParent, int iLineType, CATRep * iRep = NULL);
/** @nodoc */
     unsigned char * GetLineTypeBitmapFromDisplayContext(CATDialog * iParent, int iLineType, CATVizDisplayContext * iVdc, CATRep * iRep = NULL);
/** @nodoc */
     void DeleteLineTypeBitmap(int iLineType = -1);
/** @nodoc */
     void DeleteLineTypeBitmapFromDisplayContext(CATVizDisplayContext * iVdc = NULL, int iLineType = -1);
/** @nodoc */
	 void UpdateAllLinesFromDisplayContext(CATDialog * iParent, CATVizDisplayContext* iVdc);

//------------------------------------------------------------------------------
  protected:

     
//------------------------------------------------------------------------------
  private:

     // gestion des images bitmaps
     static CATLineTypeCache * LineTypeCache;
     CATListPV _imageList;
     CATListPV _contextCacheList;

     unsigned char * GetLineTypeBitmapFromList(CATDialog * iParent, int iLineType, CATListPV & iImageList, CATRep * iRep = NULL, CATVizDisplayContext* iVdc = NULL);
     void DeleteLineTypeBitmapFromList(CATListPV & iImageList, int iLineType = -1);
};

#endif
