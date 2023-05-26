/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                          */
/*===========================================================================*/
/*                                                                           */
/*  CATSerialize                                                             */
/*                                                                           */
/*  Usage Notes:                                                             */
/*  Definition of the interface CATSerialize                                 */
/*===========================================================================*/
/*  Creation September 1996                                                  */
/*===========================================================================*/
#ifndef __CATSerialize
#define __CATSerialize
#include "CATBaseUnknown.h"
#include "JS0MRSHL.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0MRSHL IID IID_CATSerialize;
#else
extern "C" const IID IID_CATSerialize;
#endif


/* definition of the interface CATSerialize */

class ExportedByJS0MRSHL CATSerialize : public CATBaseUnknown

{
   CATDeclareInterface;
   public :


      /* Marshalling */
      virtual int Marshalling (int i,int j) = 0;

      /* Unmarshalling */
      virtual CATBaseUnknown * Unmarshalling (int i,
					    CATBaseUnknown *pt, int j) = 0;

};

#endif
