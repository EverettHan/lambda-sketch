#ifndef CATCommandServices_H
#define CATCommandServices_H
// Copyright DASSAULT SYSTEMES 2001

/**
 * Reserved services for CATCommands
 *
 */

#include "CATCommand.h"
#include <stdio.h>


//===================================================================================
/* Returns the last active command */
/* Warning : may return NULL       */
ExportedByJS0FM CATCommand *CATSysGetLastActiveCommand();


//===================================================================================
/* Returns the last  deactivated or canceled command */
/* Warning : may return NULL                         */
ExportedByJS0FM CATCommand *CATSysGetLastStoppedCommand();

//===================================================================================
/* dump the children of the command on a FILE
 *    iCmd : CATCommand whose children must be dumped 
 *    oOut : output stream
 *    iRecurse : 0 dump only the direct children
 *               -1 dump all the descendants
 */
ExportedByJS0FM int CATCmdDumpChildren(CATCommand *iCmd,FILE *oOut,int iRecurse);

//===================================================================================
/* enumerate the children of a   command
 *    iCmd : CATCommand whose children must be enumerated
 *    iRecurse : 0 enumerate only the direct children
 *               -1 enumerate all the descendants
 *    iTreat : fonction pointer . iTreat will be called once for each descendant of
 *             the CATCommand with the following arguments
 *                  iChldCmd : children or descendant command
 *                  iCmdParent : Parent of iChldCmd
 *                  iClientData : client data pointer
 *                  iLevel     : number of degrees between the enumerated CATCommand iChldCmd 
 *                  and iCmd
 *    iClientData : pointer on client structure which will be given as argument to all the iTreat calls
 *
 */
ExportedByJS0FM int CATCmdEnumChildren(  
           CATCommand *iCmd,int iRecurse,
           int  (*iTreat)(CATCommand *iCmd, CATCommand *iCmdParent,void *iClientData, int iLevel ),
           void *iClientData );
#endif
