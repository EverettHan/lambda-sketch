#ifndef CATEContExternalLinks_H
#define CATEContExternalLinks_H
// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AC0XXLNK.h"
#include "CATLISTV_CATBaseUnknown.h"
/**
 * @level Private
 * @usage U2
 */



/*
// Adaptor for CATIExternalLinks interfaces
*/
class ExportedByAC0XXLNK CATEContExternalLinks : public CATBaseUnknown
{ 
public:

   CATEContExternalLinks();
   virtual ~CATEContExternalLinks();
 
   virtual HRESULT GetExternalLinks(CATLISTV(CATBaseUnknown_var)& oExternalLinks);
};

#endif      

