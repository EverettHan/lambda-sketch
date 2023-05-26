#ifndef CATMagnifierPanel_H
#define CATMagnifierPanel_H
 
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1998
//------------------------------------------------------------------------------
// Abstract : 	
//------------------------------------------------------------------------------
// Usage    :	
//------------------------------------------------------------------------------
// Class    : CATMagnifierPanel
//               CATDlgDialog (Dialog framework)
//------------------------------------------------------------------------------
#include "CATVisPanel.h"

#include "CATDlgDialog.h"

class CATViewer;
class CATViewpoint;
class CAT3DViewer;
class CAT2DCustomRep;
class CAT2DBagRep;
class CAT2DManipulator;

class ExportedByCATVisPanel CATMagnifierPanel : public CATDlgDialog 
{
 public :

   CATMagnifierPanel(CATDialog *parent, CATViewer *, const CATString &, CATDlgStyle style = CATDlgFraNoTitle);
   virtual ~CATMagnifierPanel();

   CAT3DViewer * GetViewer();

   void CleanPanel(void);

//------------------------------------------------------------------------------
  
 private :

   void Modify (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
   void ModifyBackground (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
   void ModifyFog (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);

   void Cursor         (CATCommand *cmd, CATNotification *notif, CATCommandClientData );
   void ManipulateT    (CATCommand *cmd, CATNotification *notif, CATCommandClientData );
   void ManipulateS    (CATCommand *cmd, CATNotification *notif, CATCommandClientData );
   void EndManipulateT (CATCommand *cmd, CATNotification *notif, CATCommandClientData );
   void EndManipulateS (CATCommand *cmd, CATNotification *notif, CATCommandClientData );

   void UpdateView();
   void UpdateGP(const int);
   void UpdateBackground();
   void UpdateFog();

   CAT2DManipulator *_translate, *_zoom1, *_zoom2;
   CATViewer *_master;
   CAT3DViewer *_viewer;
   CAT2DCustomRep *_repT, *_repS1, *_repS2;
   CAT2DBagRep *_rep;
   CATViewpoint *_vp2D, *_vp3D;

   CATCallback _ViewpointCB;

   float _originX, _originY;
   int _size, _max_size;   
};

#endif

