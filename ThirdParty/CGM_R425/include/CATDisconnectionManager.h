/**
 * @fullreview SGT  SGT 01:06:27
 */
#ifndef CATDisconnectionManager_H
#define CATDisconnectionManager_H

#include "CATBaseUnknown.h"
#include "CATNotification.h"
// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0ERROR.h"

// flags for SetPolicy iWhatToDo
#define CATDisMgrOverride         1
#define CATDisMgrAnd              2
#define CATDisMgrOr               3

// flags for SetPolicy iFlags
#define CATDisMgrStsIgnoreClients  0x00010000

#include "CATCommand.h"
class CATSigTimer; 

//--------------------------------------------------------------------------------------------
// definition du prototype du callback pour etre rappelé quand le disconnection manager  
// re-sette son timer pour inactivite
typedef void (*CATSysCbkInacReset)();

typedef void (*CATSysCbkWarningBeforeLO)();


class CATSigTimer;

class ExportedByJS0ERROR CATDisconnectionNotification : public CATNotification
{
   public:
   CATDeclareClass;
};

class ExportedByJS0ERROR CATDisconnectionManager : public CATBaseUnknown 
{
  friend class CATDisconnectCmd;
   public:
   CATDeclareClass;
   /**
    * Get the disconnection manager unique object
    */
   static CATDisconnectionManager * GetManager();
   
   private:
   CATDisconnectionManager();
   
   public:
   ~CATDisconnectionManager();

#ifndef _WINDOWS_SOURCE
   int SetWidget( void * iWidget);
   void * GetWidget( );
#endif
   int ApplicationIsInteractive();
   int IsApplicationInteractive();
   /*
    * should be called by Dialog or Visu when CATIA is active
    */
   int ActivityOn();
   /*
    * should be called by Dialog or Visu when CATIA is no more  active
    */
   int ActivityOff();

   /*
    * should be called by command software  when CATIA is active
    */
   int InnerActivityOn();
   /*
    * should be called by command software  when CATIA is no more  active
    */
   int InnerActivityOff();
   /*
    * Suspend the disconnection count 
    */
   int SuspendDisconnections();
   /*
    * resume the disconnection count 
    */
   int ResumeDisconnections();

   /*
    * to be called at the beginning of a transaction  to ignore
    */
   int TransactionToIgnoreBegins();
   /*
    *  to be called at the end of  a transaction to ignore
    */
   int TransactionToIgnoreEnds();

   /*
    * set the disconnection timer value
    *     iNbOfSecondsMax        :               
    *           Maximum number of seconds of inactivity before disconnection                           
    *     iNbOfSecondsForWarning :               
    *          Number of  seconds equal to the duration of the warning
    *          Remark 1 : iNbOfSecondsForWarning must be lower than iNbOfSecondsMax or it will be ignored               
    *          Remark 1 : if iNbOfSecondsForWarning is set to lower of equal to zero it will be ignored
    *  RC : 
    *     Previous value of maximimum number of seconds of inactivity   
    */
   int SetMaximumInactivity(int iNbOfSecondsMax, int iNbOfSecondsForWarning=-1);
   /*
    * set the disconnection timer value
    */
   int GetMaximumInactivity(int *oNbOfSeconds, int *oNbOfSecondsForWarning=NULL);
   /*
    * set the cpu-loop counter
    */
   int SetCPULoopDuration(int iNbOfSeconds);
   /*
    * Get the cpu-loop counter
    */
   int GetCPULoopDuration(int *oNbOfSeconds);
   
   
   /*
    * return 0 is Activity is ON and -1 if Activity is OFF
    */
   int GetActivity() ;
  
    /*
     * this permits to declare a new external client
     */
    int DeclareExternalClient();
    /*
     * this permits to undeclare  an external client
     */
    int UndeclareExternalClient();
    /*
     *  this gets the current number of external clients
     */
    int GetNumberOfExternalClients();
    /*
     *   permits to set the policy toward external clients
     */

    /*
     *   activates the disconnection manager
     *   DO NOT USE
     */
    int ActivatesDisconnection() ;

    /*
     *   deactivates the disconnection manager
     *   DO NOT USE
     */
    int DeactivatesDisconnection();

    /*
     *   return TRUE if the disconnection manager is Active
     */
    int IsActive() ;


    static int InacTimerHandler(void *iInf);
    static int CPUTimerHandler(void *iInf);
    
    int SetPolicy( int iFlags, int iWhatToDo );

    /*
     *   use this method to be called when the disconnection manager resets 
     *   the inactivity timer.
     *   as this method is called very often one should not use this method
     *   systematically
     *   this method is provided specifically to allow the management of a 
     *   warning  that occurs a few minutes before the disconnection
     *   
     *   remark  : the callback is automatically invalidated  when  called
     *   
     *   remark 2 :  minimal activity is recommanded in this callback and in  particular we recommand to avoid
     *                 CATCommand activity
     *
     *   call  CallbackAtInactivityTimerReset iCalledWhenResetInactivityTimer==NULL to reset the callback
     *
     *   ARGUMENTS :
     *        iCalledWhenResetInactivityTimer
     *           One should pass either a function pointer on its reset callback or a null pointer to reset the callback
     *
     *
     *  RETURN VALUES:
     *        last value of CATSysCbkInacReset callback (if not null should be called by the current enabled callback)
     *
     */
    CATSysCbkInacReset CallbackAtInactivityTimerReset(  CATSysCbkInacReset iCalledWhenResetInactivityTimer);

    private:  
    int InactivityDetected();
    int CPULoopDetected();
    int SetTimerForInactivity();
    int ResetTimerForInactivity();
    int SetTimerForCPU();
    int ResetTimerForCPU();
    static CATDisconnectionManager *S_Manager;
    int m_status;
    int m_extClients;
    int m_nbONs; // si besoin est + tard on pourra compter les ON cf aux OFF
                 // aujourd'hui on part du principe que c est absolu
    int m_nbSuspends; // si m_nbSuspends == 0  on n'est pas suspendu sinon si
    int m_MaxCPU; // number of seconds of calculation authorized
                  // without thinking a cpu loop occured
    int m_MaxInactivity; // number of seconds of user inactivity
                         // before disconnection
    int m_MaxInactivityAbs; // number of seconds of user inactivity (absolute)
    int m_WarningDuration ; // duration of the warning (if activated)
    CATSigTimer *m_TimerCPU;
    CATSigTimer *m_TimerInac;
#ifndef _WINDOWS_SOURCE
    void * m_widget;
#endif
    CATSysCbkInacReset m_CallbackAtInactivityTimerReset; // stocke le pointeur sur le callback d'inactivite s'il existe
};



#include "CATThrMessage.h"
class ExportedByJS0ERROR CATDisconnectMsg: public CATThrMessage 
{
  public :  
  CATDeclareMsgClass;
  CATDisconnectMsg() {};
  virtual ~CATDisconnectMsg() {};
};

  
#endif
