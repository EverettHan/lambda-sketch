#ifndef _CATMarshallableDbServer_h
#define _CATMarshallableDbServer_h
// COPYRIGHT DASSAULT SYSTEMES 2003
#include "CATBaseUnknown.h"

class CATMarshallableDbServer : public CATBaseUnknown
{
   CATDeclareClass;
   public :
     // Methode de Marshalling
     virtual int Marshalling ( int, int );

     // Methode de Unmarshalling
     virtual CATBaseUnknown * Unmarshalling (int, CATBaseUnknown *, int);

};


#endif // _CATMarshallableDbServer_h
