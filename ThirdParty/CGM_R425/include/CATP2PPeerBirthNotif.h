/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATP2PPeerBirthNotif                                                        */
/*                                                                       */
/*  Usage Notes:            */
/*                                                                       */
/*=======================================================================*/
/*  Creation May	2002                                 jnm             */
/*=======================================================================*/
#ifndef _CATP2PPeerBirthNotif
#define _CATP2PPeerBirthNotif

#include "CATP2PNotif.h"

class CATUnicodeString;


class ExportedByCATP2PCore CATP2PPeerBirthNotif : public CATP2PNotif
{

 public:

   CATP2PPeerBirthNotif(const CATUnicodeString* peer_name);

   virtual ~CATP2PPeerBirthNotif();

 
   CATDeclareClass;


 private:




};


#endif
