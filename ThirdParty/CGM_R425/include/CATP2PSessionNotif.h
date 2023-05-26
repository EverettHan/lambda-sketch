/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATP2PSessionNotif                                                        */
/*                                                                       */
/*  Usage Notes:            */
/*                                                                       */
/*=======================================================================*/
/*  Creation May	2002                                 jnm             */
/*=======================================================================*/
#ifndef _CATP2PSessionNotif
#define _CATP2PSessionNotif

// COPYRIGHT DASSAULT SYSTEMES 2003


#include "CATP2PNotif.h"
#include "CATP2PCore.h"


class CATUnicodeString;




class ExportedByCATP2PCore CATP2PSessionNotif : public CATP2PNotif
{

 public:
 
 CATDeclareClass;

   CATP2PSessionNotif(const CATUnicodeString* peer_name,  int iSessionType, unsigned char eventType);
   ~CATP2PSessionNotif();

  int getSessionType() {return _sessionType;}
  unsigned char getEventType() {return _eventType;}

 private:
 
		int _sessionType;
		unsigned char _eventType;

};


#endif
