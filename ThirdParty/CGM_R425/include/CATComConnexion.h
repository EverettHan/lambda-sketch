/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 2000						                */
/*=======================================================================*/
/*                                                                       */
/*  CATComConnexion                                                        */
/*                                                                        */
/*  Usage Notes: Batch Protocol                           */
/*                                                                       */
/*=======================================================================*/
/*  Creation Oct	2000                                 jnm             */
/*=======================================================================*/
#ifndef _CATComConnexion_H
#define _CATComConnexion_H

#include "CATComServices.h"

#include "CATComConnexionType.h"
#include "CATErrorDef.h"
#include <stdlib.h>

class CATComMessage;
class CATComMessageFactory;

struct ExportedByCATComServices  CATComProcessInfo
{
	int pid;
	int status;
};


class ExportedByCATComServices CATComConnexion
{


   public :

	   CATComConnexion ();
	   virtual ~CATComConnexion ();

	   virtual int Connect(const char* QM, CATComMessageFactory* fact)=0;
	   virtual int Disconnect()=0;
	   virtual int PutComMessage(CATComMessage& mess, const char* dest, const char* host, char* filter=NULL)=0;
	   virtual CATComMessage* GetComMessage(const char* src, int timeout, char* filter = NULL)=0;
	   virtual HRESULT DeclareWait(const char* queue)=0;
	   virtual CATComMessage* WaitingLoop(const char* src, int timeout, int& ier) = 0;
	   
  

	   int _ReentranceProof;
	   int _InLoop;
	   int _SomethingToDo;
	   CATComProcessInfo _info;

};


#endif

