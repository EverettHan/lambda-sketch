#ifndef _CATMarshallableDbSettings_h
#define _CATMarshallableDbSettings_h
// COPYRIGHT DASSAULT SYSTEMES 2003
#include "CATBaseUnknown.h"

class CATMarshallableDbSettings : public CATBaseUnknown
{
   CATDeclareClass;
   public :
     // Methode de Marshalling
     virtual int Marshalling ( int, int );

     // Methode de Unmarshalling
     virtual CATBaseUnknown * Unmarshalling (int, CATBaseUnknown *, int);

};


#endif // _CATMarshallableDbSettings_h
