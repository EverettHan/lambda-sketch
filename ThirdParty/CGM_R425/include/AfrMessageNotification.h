#ifndef AfrMessageNotification_H_
#define AfrMessageNotification_H_

// COPYRIGHT DASSAULT SYSTEMES 2015

#include "AfrComputeServer.h"
#include "CSIMessage.h"
#include "CSICommands.h"
#include "CSINode.h"
#include "CATNotification.h"

/** 
 * Class representing a notification sent when a message will 
 * be sent to client. 
 * @see AfrMessageCompiler
 */
class ExportedByAfrComputeServer AfrMessageNotification : public CATNotification
{
 
  CATDeclareClass;

  public:
   /** @nodoc */ 
   
   AfrMessageNotification ();
   virtual ~AfrMessageNotification();

   void SetMessage(CSI::Message * ioutputs);
   CSI::Message * GetMessage();

   void SetMsgType(int iclientMsg);
   int GetMsgType();

   void SetIsIterative(int iint );
   int GetIsIterative();

   void SetViewOption(int iint);
   int GetViewOption();

   void SetCommands(CSI::Commands * icommands);
   CSI::Commands * GetCommands();

   void SetNode(CSI::Node* ipNode);
   CSI::Node* GetNode();

   private:
    // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    AfrMessageNotification (const AfrMessageNotification &);
    AfrMessageNotification & operator= (const AfrMessageNotification &);

    CSI::Message * _outputs;
    /*Donnee membre representant le type de message
      correspondance :
      
      enum msgValue {
        START_COMMAND  = 0,
        STOP_COMMAND    = 1,
        CANCEL_OPERATION  = 2,
        EXECUTE_SERVICE = 3,
        BEGIN_SERVICE   = 4,
        DO_OPERATION      = 5,
        END_SERVICE     = 6
    };

    */
    int _clientMsg;
    int _isAStateCmd;
    int _viewOption;

    CSI::Commands * _commands;
    CSI::Node *     _node;

};

#endif

