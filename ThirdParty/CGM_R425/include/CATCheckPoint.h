#ifndef CATCheckPoint_h
#define CATCheckPoint_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0FM.h"
#include "CATCommand.h"
#include "CATBaseUnknown.h"
/**
 * CATCheckPoint is the base class for debugging checkpoint.
 * This is a class reserved for use from DASSAULT-SYSTEM only and only for    
 * debugging purposes.
 *
 * <p>
 * THIS MECHANISM CAN NOT AND MUST NOT BE USED IN NORMAL CONDITIONS  
 *
 * <p>
 * Now, how does it works ?                  
 * <p>
 * An instance of checkpoints group  may be created only with the static method
 * CATCheckPoint *CATCheckPoint::CreateCheckPoint(char *iCheckPointGroupName).
 * The constructor is protected so that it can't be directly called.
 * <p>
 * Once you have created your checkpoints group you can instanciate checkpoints
 * by calling the Checkpoint method.                                       
 * <p>
 * The TestCheckPoint method is an informative method permitting the application
 * to know if a checkpoint will be activated.                    
 */



class ExportedByJS0FM CATCheckPoint
{
  public :
  static CATCheckPoint *CreateCheckPoint(char *iCPGroupName);
  virtual ~CATCheckPoint();
/**
 * place a checkpoint : when in this method if the checkpoint is active
 *                      the user can see the current state of his model,
 *                      pannels , and so one. The visualization is refreshed
 *                      the user may conduct a debug dialog ..                 
 * @param iCPName
 *   The name of the checkpoint. Which can be user by the UI of the checkpoint
 *   manager
 * @param iCurrentActiveCmd
 *   The pointer to the current active command if the programmer knows it
 *   This command will be removed from the CATCommandSelector at the beginning
 *   of the checkpoint and will be reactived at the end
 *    
 * @return 
 *     0 : OK, the checkpoint has been used
 *     1 : check-points are deactivated.Use checkpoint manager pannel to 
 *         activate them
 *     2 : check-point has been skipped 
 *    -1 : Trace CheckPtDebug is not active. Use Trace pannel to activate it
 *           in CNEXT
 *    -2 : We are already in a checkpoint : checkpoint ignored
*/
 virtual int CheckPoint(char *iCPName,  CATCommand *iCurrentActiveCmd=NULL,
                         CATCommand *iCmdToActivate=NULL )=0;



/**
 * test  a checkpoint : indicates if a checkpoint will be activated or no
 * @param iCPName
 *   The name of the checkpoint. Which can be user by the UI of the checkpoint
 *   manager
 * @return 
 *     0 : OK, the checkpoint will be used  
 *     1 : check-points are deactivated.Use checkpoint manager pannel to 
 *         activate them
 *     2 : check-point will be skipped 
 *    -1 : Trace CheckPtDebug is not active. Use Trace pannel to activate it
 *           in CNEXT
*/
  virtual int TestCheckPoint(char *iCPName )=0;


/**
 * viewpoint          : when in this method if the checkpoint is active
 *                      the user can see the current state of his model,
 *                      pannels , and so one. The visualization is refreshed.
 *                      No dialog may be conducted
 * @param iCPName
 *   The name of the checkpoint. Which can be user by the UI of the checkpoint
 *   manager
 *    
 * @return 
 *     0 : OK, the checkpoint has been used
 *     1 : check-points are deactivated.Use checkpoint manager pannel to 
 *         activate them
 *     2 : check-point has been skipped 
 *    -1 : Trace CheckPtDebug is not active. Use Trace pannel to activate it
 *           in CNEXT
 *    -2 : We are already in a checkpoint : checkpoint ignored
*/
  virtual int ViewPoint(char *iCPName )=0;
  virtual CATCommand *GetDialog( )=0;
  protected:
  CATCheckPoint();
};


#endif

