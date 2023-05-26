/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                          */
/*===========================================================================*/
/*                                                                           */
/*  CATCreateCorba                                                           */
/*                                                                           */
/*  Usage Notes:                                                             */
/*  Definition of the interface CATCreateCorba                               */
/*===========================================================================*/
/*  Creation September 1996                                                  */
/*===========================================================================*/
#ifndef __CATCreateCorba
#define __CATCreateCorba
#include "CATBaseUnknown.h"
#include "JS0MRSHL.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0MRSHL IID IID_CATCreateCorba;
#else
extern "C" const IID IID_CATCreateCorba;
#endif


/* definition of the interface CATCreateCorba */

class ExportedByJS0MRSHL CATCreateCorba : public CATBaseUnknown

{

   CATDeclareInterface;
   public :

      /* Create Object generique */
      virtual CATBaseUnknown * CreateObject (int i,
				   CATBaseUnknown *pt, int j, int&k) = 0;

};

#endif
