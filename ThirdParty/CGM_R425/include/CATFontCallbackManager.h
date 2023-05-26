// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATFontCallbackManager.h
// Header definition of CATFontCallbackManager
//
//===================================================================
//
// Usage notes:
//
//------------------------------------------------------------------------------
// Main methods:    
//
//           DispatchCATFontCallback
//
//------------------------------------------------------------------------------
// Events:    
//	       FONT_NOT_FOUND    (request font not installed)
//===================================================================
//
//  Jan 2009  Creation: YWG
//===================================================================
#ifndef CATFontCallbackManager_H
#define CATFontCallbackManager_H

#include "SGInfra.h"
#include "CATCallbackManager.h"


//-----------------------------------------------------------------------
enum  FontEvent {FontNotFound = 0};

class ExportedBySGInfra CATFontCallbackManager : public CATCallbackManager
{
public:

   CATDeclareClass ;

   CATDeclareCBEvent(FONT_NOT_FOUND);

   // Get the singleton of CATFontCallbackManager.
   // -------------------------------------------
   static CATFontCallbackManager* GetCATFontCallbackManager();

   virtual ~CATFontCallbackManager ();

   HRESULT DispachCATFontCallback(FontEvent iEvent, void * iData = NULL);

private:

   // Standard constructors
   // ---------------------
   CATFontCallbackManager ();

   // Copy constructor and equal operator
   // -----------------------------------
   CATFontCallbackManager (const CATFontCallbackManager & i_original);
   CATFontCallbackManager& operator=(const CATFontCallbackManager & i_original);

private:

   static CATFontCallbackManager* _s_pCATFontCallbackManager;
};
//-----------------------------------------------------------------------

#endif
