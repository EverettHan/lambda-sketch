/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 2000						                */
/*=======================================================================*/
/*                                                                       */
/*  CATComMessageFactory                                                        */
/*                                                                        */
/*  Usage Notes: Public Async Messages                                  */
/*                                                                       */
/*=======================================================================*/
/*  Creation Oct	2000                                 jnm             */
/*=======================================================================*/
#ifndef _CATComMessageFactory_H
#define _CATComMessageFactory_H

#include "CATComServices.h"

class CATComMessage;


class ExportedByCATComServices CATComMessageFactory
{

   public :

	virtual CATComMessage* CreateComMessage(char* mess, int len);
	 

};


#endif

