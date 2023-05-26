#ifndef _CATPLMComponentRedrawListener_H
#define _CATPLMComponentRedrawListener_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @level Protected
 * @usage U1       
 */
#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATPLMComponentEvent;
class CATPLMComponentEventIterator;
class CATITosRedrawListener;
class CATPLMComponentSpaceFilter;
class CATIPLMSpace;

/**
*  Allows to manage a Redraw feedback on TOS modifications for GUI refresh
*
*  Redraw feedback will be launch at the end of CATCommands to prevent GUI refresh during data model modifications.
*  An asynchronous and synthetic status will be sent to subscribers (No capture of history, No Undo/Redo integration). 
*  
*  Asynchronous mode :
*   *) Events will be dispatched when OnEndTransaction System callback will be raised. 
*   *) In case of several imbricated CATCommands, refresh feedback will be launched when the last CATCommand will be ended
*     
*  Using subscription is made in two steps :
*   *) Build-Time : Derivation of C++ class CATPLMComponentRedrawListener 
*   *) Run-Time   : dynamic subsription
*                   CATPLMComponentRedrawListener::Register(CATIPLMSpace * iSpace)
*
*  Registration mode :
*   *) Space level registration allows to register a space content based on filters. 
*       *) This is the best solution for low memory consumption.
*       *) Not necessary to register each component
*       *) Not necessary to manage unregistration if component is deleted
*       *) Not necessary to manage Listener life cycle
* 
*  Code sample : Space registration
*  
*     void StartListener()
*      {
*         // 1. creates a static listener 
*         static CATAppRedrawListener myListener;  
*
*         // 2. gets handle on resolution space (The default resolution space is CATIA3D authoring) 
*         CATIPLMSpace * mySpace = NULL;
*         CATPLMSpaceServices::GetResolutionSpace (mySpace);
* 
*         // 3. Defines events
*         CATPLMComponentEvent_Editability myEvt1; 
*         CATPLMComponentEvent_Relational  myEvt2; 
*         CATPLMComponentEvent_Versioned  myEvt3; 
*
*         // 4. Defines filters
*         CATPLMComponentSpaceFilter myFilter;
*         myFilter.SetCoreTypeFilter(PLMCoreRepReference).SetCoreTypeFilter(PLMPort);
*
*         // 5. Subscribes events. Registration will be effective until space deletion.
*         myListener.Register (mySpace, myEvt1, &myFilter);
*         myListener.Register (mySpace, myEvt2);
*         myListener.Register (mySpace, myEvt3);
*
*         CATSysReleasePtr(mySpace);
*      }
*
*      class CATAppRedrawListener : public CATPLMComponentRedrawListener
*      {
*         HRESULT OnRedrawEvents (CATBaseUnknown & iComponent, CATPLMComponentEventIterator & iEventIterator)
*         {
*            const CATPLMComponentEvent * CurEvent = NULL;
*            while(CurEvent = iEventIterator++)
*            {
*               switch(CurEvent->GetType())
*               {
*                  case CATPLMComponentEventType_Editability:
*                  {
*                     // Redraw component editability
*                     break;
*                  }
*                  case CATPLMComponentEventType_Relational:
*                  {
*                     // Redraw relational view
*                     break;
*                  }
*                  case CATPLMComponentEventType_Versioned:
*                  {
*                     // Redraw version ID
*                     break;
*                  }
*               }
*            }    
*            return S_OK;
*         }
*      };
*/
class ExportedByCATPLMIdentificationAccess CATPLMComponentRedrawListener
{
public:

  CATPLMComponentRedrawListener();
  virtual ~CATPLMComponentRedrawListener();

  /**
  * Available events :
  *
  *  @see CATPLMComponentEvent_Editability
  *  @see CATPLMComponentEvent_Relational 
  *  @see CATPLMComponentEvent_Versioned
  *  @see CATPLMComponentEvent_Synchronized
  */

 /**
  * Registration at space level
  *
  * @param iSpace
  *   Data space on which registration is done 
  * @param iEvent
  *   Event on which registration is done
  * @param iSpaceFilter
  *   Allows to apply filter on space content 
  *    
  * @return
  *   S_OK if request succeeded <br>
  *   E_NOTIMPL if iComponent is not a component's implementation <br> 
  *   E_UNEXPECTED if listener has been instanciated without existing GUI application <br>
  *   E_FAIL if request failed <br>
  */
	HRESULT Register(CATIPLMSpace * iSpace, const CATPLMComponentEvent & iEvent, const CATPLMComponentSpaceFilter * iSpaceFilter = 0);

  /**
  * Remove all Registration associated to this presentation
  *
  * @return
  *   S_OK if request succeeded <br>
  *   E_UNEXPECTED if listener has been instanciated without existing GUI application <br>
  *   E_FAIL if request failed <br>
  */
  HRESULT FlushRegistrations();
  
  /**
  * Checks if listener is valid in current environment
  * If redraw listener is not valid, all methods will returned E_UNEXPECTED
  * A redraw listener is valid only if a GUI application is available.
  */
  CATBoolean IsValid();

  /**
  * Is called before asynchrone events dispatching (Can be overloaded)
  */
  virtual void OnRedrawStarting(){}

  /** 
  * Redraw notification (Has to be implemented)
  * Data model modifications are not authorized during this operation
  * 
  * @param iComponent
  *   Component on which events has been raised
  *
  * @param iEvents_MaskAnd
  *   Associated Events
  *    
  * @return
  *   S_OK if request succeeded <br>
  *   E_FAIL if request failed <br>
  */
  virtual HRESULT OnRedrawEvents (CATBaseUnknown & iComponent, CATPLMComponentEventIterator & iEventIterator) = 0;

  /**
  * Is called after asynchrone events dispatching (Can be overloaded)
  */
  virtual void OnRedrawEnding(){} 

private:

  /* forbidden operations */
  CATPLMComponentRedrawListener (CATPLMComponentRedrawListener &);
  CATPLMComponentRedrawListener& operator=(CATPLMComponentRedrawListener&);

  CATITosRedrawListener * _OxListener;
};

#endif
