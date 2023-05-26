// COPYRIGHT DASSAULT SYSTEMES 2015
#ifndef CATRepEvent_H
#define CATRepEvent_H

#include "SGInfra.h"
#include "CATTimeStampedEvent.h"
#include "CATUnicodeString.h"
#include "CATRep.h"
#include "CATVizVertexBuffer.h"

//class CATFont;

/**
* Class notification for CATFont events.
*/
//===============================================================================
class ExportedBySGInfra CATRepEvent : public CATTimeStampedEvent
{
   CATDeclareClass;

public :

   /** @nodoc */
   CATRepEvent(CATUnicodeString iEventName, CATRep* iRepBeingDeleted); 
   CATRepEvent(CATUnicodeString iEventName, CATVizVertexBuffer* iVertexBufferBeingDeleted); 
   /** @nodoc */
   virtual ~CATRepEvent();

   /** @nodoc */
   CATUnicodeString & GetRepEventName();
   /** @nodoc */
   CATRep * GetRepBeingDeleted();   

    /** @nodoc */
   CATVizVertexBuffer * GetVertexBufferBeingDeleted();   

private :

   CATUnicodeString _RepEventName;
   CATRep*        _RepBeingDeleted;
   CATVizVertexBuffer* _VertexBufferBeingDeleted;
};

//===============================================================================
#endif
