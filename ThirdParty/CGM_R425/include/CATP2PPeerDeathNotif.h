/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATP2PPeerDeathNotif                                                        */
/*                                                                       */
/*  Usage Notes:            */
/*                                                                       */
/*=======================================================================*/
/*  Creation May	2002                                 jnm             */
/*=======================================================================*/
#ifndef _CATP2PPeerDeathNotif
#define _CATP2PPeerDeathNotif

#include "CATP2PNotif.h"

class CATUnicodeString;


class ExportedByCATP2PCore CATP2PPeerDeathNotif : public CATP2PNotif
{

 public:

   CATP2PPeerDeathNotif(const CATUnicodeString* peer_name);

   virtual ~CATP2PPeerDeathNotif();

 
   CATDeclareClass;


 private:




};


#endif
