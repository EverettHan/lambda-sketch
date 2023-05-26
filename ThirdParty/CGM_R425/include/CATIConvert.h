/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIConvert_H
#define CATIConvert_H
#include "CORBAAnyDef.h"
#include "CosDataObject.h"
#include "CATBaseUnknown.h"

class CATDocument;
class CATStreamArea;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIConvert;



class ExportedByAD0XXBAS CATIConvert: public CATBaseUnknown
{
  CATDeclareInterface;
  public:
   virtual void Transcript( CATDocument* doc , CATStreamArea* where ) = 0;
};

CATDeclareHandler( CATIConvert , CATBaseUnknown ) ;

#endif
