#ifndef DirtyCmdEnded_H_
#define DirtyCmdEnded_H_

// COPYRIGHT DASSAULT SYSTEMES 2019

#include "AfrComputeServer.h"
#include "CATNotification.h"

/** 
 * Class representing a notification sent when a command that has dirtyfied the model will 
 * end. 
 */
class ExportedByAfrComputeServer DirtyCmdEnded : public CATNotification
{
 
  CATDeclareClass;

  public:
   /** @nodoc */ 
   
   DirtyCmdEnded ();
   virtual ~DirtyCmdEnded();


   private:
    // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    DirtyCmdEnded (const DirtyCmdEnded &);
    DirtyCmdEnded & operator= (const DirtyCmdEnded &);

};

#endif

