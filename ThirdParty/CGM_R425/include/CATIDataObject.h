/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIDataObject_h
#define CATIDataObject_h

//====================================================================================
//
// Interface CATIDataObject :
//     
//       Interface to specify the object supported formats 
//
//====================================================================================
// Usage Notes:
//
//  Methods
//      - ExportData ..... Renders the data describe in the input format and returns it
//                         into the where.
//      - ListFormats .... List of the object supported formats   
//      - QueryGetData ... Check if the object supports the input format
//
//====================================================================================

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

#include "CORBAAnyDef.h"
#include "CosDataObject.h"

class CATStreamArea;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIDataObject ;

class ExportedByAD0XXBAS CATIDataObject : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

    virtual void     ExportData ( format choice , CATStreamArea*  where)  = 0;

    virtual Formats  ListFormats ()  = 0;

    virtual boolean  QueryGetData ( format choice)  = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDataObject , CATBaseUnknown ) ;


#endif
