#ifndef CATI3DMultiViewpointViewer_H
#define CATI3DMultiViewpointViewer_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATCommand.h"

#include "CATUnicodeString.h"
#include "CATListPV.h"
#include "CATViewerUtility.h"
#include "CATListOfInt.h"

class CATViewpoint;
class CATBasic3DViewpointEditor;
class CATViewConfig;
class CATIndicator;

enum  CATViewpointType {VIEWPOINT3D, VIEWPOINT2D};

struct ExportedByCATVisItf DefinedVP
{
   int isSynchro;
   int isMain;
   int TranslationLock;
   int RotationLock;

   CATUnicodeString name;

   CATViewpoint * viewpoint;
   CATViewpoint * viewpointAux;
   CATBasic3DViewpointEditor * vpEditor;
   CATViewConfig * viewConfig;
   CATIndicator * indic;

   DefinedVP()
   {
      isSynchro = 0;
      isMain = 0;
      TranslationLock = 0;
      RotationLock = 0;

      name = "default name";
      
      viewpoint = NULL;
      viewpointAux = NULL;
      vpEditor = NULL;
      viewConfig = NULL;
      indic = NULL;
   }
} ;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATI3DMultiViewpointViewer;
#else
extern "C" const IID IID_CATI3DMultiViewpointViewer;
#endif
//===============================================================================================
class ExportedByCATVisItf CATI3DMultiViewpointViewer : public CATBaseUnknown
{
   CATDeclareInterface;

   public :
  
      virtual void SetViewConfig(CATViewConfig * viewconfig) = 0;
      virtual CATViewConfig * GetViewConfig() = 0;
      virtual void AddViewpointToConfig(CATViewpoint * iViewpoint, CATViewConfig * iConfig, const CATViewerPlacement iPlace, CATUnicodeString iName = "") = 0;

      virtual CATListPV GetDefinedVPList() = 0;
      virtual void SetViewpointSynchroMode(const int iSyncMode) = 0;
      virtual int  GetViewpointSynchroMode() = 0;

      virtual void  ReframeAllViewpoints(const int allvp=0) = 0;
      virtual int   IsMultiViewpointMode() = 0;

      /**
      * Creates a Grid view by splitting viewer into m * n grid.
      * @param inbRows Number of rows.
      * @param inbCols Number of columns. Sight Direction (Direction where the observator looks at)
      * @param ipListIntRotation List of integer to set rotation lock flag 0 = unlocked 1 = locked. 
      * @param ipListIntTranslation List of integer to set translation lock flag 0 = unlocked 1 = locked. 
      * @param iSightDirection List of (m*n) CATMathDirectionf to set Sight Direction for each view
      * @param iViewName Name of main view (first), other view will append the prefix 1,2,3... Default name is View 
      */
      //virtual HRESULT CreateViewGrid( int inbRows, int inbCols, CATListOfInt ipListIntRotation , CATListOfInt ipListIntTranslation, const CATListPV & iSightDirection, CATUnicodeString iViewName="View ") = 0;

};
//===============================================================================================
   CATDeclareHandler(CATI3DMultiViewpointViewer,CATBaseUnknown);
//===============================================================================================
#endif
