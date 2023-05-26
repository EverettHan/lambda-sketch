/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATP2PChangeStatusNotif                                                        */
/*                                                                       */
/*  Usage Notes:            */
/*                                                                       */
/*=======================================================================*/
/*  Creation May	2002                                 jnm             */
/*=======================================================================*/
#ifndef _CATP2PChangeStatusNotif
#define _CATP2PChangeStatusNotif

// COPYRIGHT DASSAULT SYSTEMES 2003


#include "CATP2PNotif.h"
#include "CATP2PCore.h"

#include "CATP2PUserStatus.h"
#include "CATUnicodeString.h"


class CATUnicodeString;




class ExportedByCATP2PCore CATP2PChangeStatusNotif : public CATP2PNotif
{

 public:

   CATP2PChangeStatusNotif(const CATUnicodeString* peer_name, CATP2PUserStatus status, const CATUnicodeString& iDesc);
   virtual ~CATP2PChangeStatusNotif();

   CATP2PUserStatus getStatus() {return _status;}
   HRESULT getDescription(CATUnicodeString& iDesc);
   

   CATDeclareClass;


 private:

	CATP2PUserStatus _status;
	CATUnicodeString _desc;

};


#endif
