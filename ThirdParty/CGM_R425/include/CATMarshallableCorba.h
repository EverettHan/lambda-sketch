/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                          */
/*===========================================================================*/
/*                                                                           */
/*  CATMarshallableCorba                                                     */
/*                                                                           */
/*  Usage Notes:                                                             */
/*  Definition of the interface CATMarshallableCorba                         */
/*===========================================================================*/
/*  Creation September 1996                                                  */
/*===========================================================================*/
#ifndef __CATMarshallableCorba
#define __CATMarshallableCorba
#include "CATBaseUnknown.h"
#include "JS0MRSHL.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0MRSHL IID IID_CATMarshallableCorba;
#else
extern "C" const IID IID_CATMarshallableCorba;
#endif


/* definition of the interface CATMarshallable */

class ExportedByJS0MRSHL CATMarshallableCorba : public CATBaseUnknown

{
   CATDeclareInterface;
   public :

      /* Marshalling */
      virtual int Marshalling (int i,int j) = 0;

      /* Unmarshalling */
      virtual CATBaseUnknown* Unmarshalling (int i,
					     CATBaseUnknown *pt, int j) = 0;

};

#endif
