/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 2000						                */
/*=======================================================================*/
/*                                                                       */
/*  CATComDriver                                                        */
/*                                                                        */
/*  								 *	/
/*                                                                       */
/*=======================================================================*/
/*  Creation Oct	2000                                 jnm             */
/*=======================================================================*/
#ifndef _CATComDriver_H
#define _CATComDriver_H

#include "CATComServices.h"
#include "CATComConnexionType.h"
#include "CATErrorDef.h"

#include <stdio.h>

class CATComConnexion;
class CATHashDico;
class CATComMessageFactory;



class ExportedByCATComServices CATComDriver
{


   public :

		static CATComConnexion* GetCurrentConnexion() { return _CurrentCnx;};
		static CATComConnexionType GetCurrentConnexionType() { return _CurrentCnxType;};
		static void SetCurrentQ(const char* queue);
		static char* GetCurrentQ();

		static CATComConnexion* SelectConnexion(CATComConnexionType cnx, const char* host=NULL);
		static CATComConnexion* SelectConnexion(const char* host=NULL);

		static HRESULT ReleaseAllConnexions();

		static char* GetComHostname();

		static void DesactivateTrace();
		static void ActivateTrace();

		//for server
		static HRESULT DeclareDriverType(CATComConnexionType);

   private :

	    static CATComConnexion* CreateConnexion(CATComConnexionType cnx, const char* host);
		static CATComConnexion*	GetConnexion(CATComConnexionType cnx);

		//for client
		static HRESULT FindDriverType(const char* host, CATComConnexionType& type);


		

		static CATComConnexion*		_CurrentCnx;
		static CATComConnexionType _CurrentCnxType;

		static CATHashDico*	_QDico;

		static char* _ComHostname;

		static CATComMessageFactory* _fact;

		static int _loop_cond;

		static int QSet;


};


#endif

