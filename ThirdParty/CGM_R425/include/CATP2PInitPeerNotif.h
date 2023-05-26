/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATP2PInitPeerNotif                                                        */
/*                                                                       */
/*  Usage Notes:            */
/*                                                                       */
/*=======================================================================*/
/*  Creation May	2002                                 jnm             */
/*=======================================================================*/
#ifndef _CATP2PInitPeerNotif
#define _CATP2PInitPeerNotif

#include "CATP2PNotif.h"

class CATUnicodeString;


class ExportedByCATP2PCore CATP2PInitPeerNotif : public CATP2PNotif
{

 public:

   CATP2PInitPeerNotif(const CATUnicodeString* peer_name);

   virtual ~CATP2PInitPeerNotif();

 
   CATDeclareClass;


 private:




};


#endif
