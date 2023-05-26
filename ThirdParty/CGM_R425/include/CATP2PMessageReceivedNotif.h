/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATP2PMessageReceivedNotif                                                        */
/*                                                                       */
/*  Usage Notes:            */
/*                                                                       */
/*=======================================================================*/
/*  Creation May	2002                                 jnm             */
/*=======================================================================*/
#ifndef _CATP2PMessageReceivedNotif
#define _CATP2PMessageReceivedNotif

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATP2PNotif.h"
#include "CATP2PCore.h"


class CATUnicodeString;





class ExportedByCATP2PCore CATP2PMessageReceivedNotif : public CATP2PNotif
{

 public:
 
 CATDeclareClass;

   CATP2PMessageReceivedNotif(const CATUnicodeString* peer_name, const CATUnicodeString* iHeader, unsigned char type, char* buffer, unsigned int length);
   ~CATP2PMessageReceivedNotif();

  char* getBuffer() {return _buffer;}
  unsigned int getLength() {return _length;}
  unsigned char getType() {return _type;}
  const CATUnicodeString* getHeader() {return _head;}
  
  
 private:
 
		char* _buffer;
		unsigned int _length;
		unsigned char _type;
		const CATUnicodeString* _head;

};


#endif
