/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATResultNotification_h
#define CATResultNotification_h

#include "AD0XXBAS.h"
#include "CATNotification.h"
#include "CATBaseUnknown_WR.h"

class ExportedByAD0XXBAS CATResultNotification : public CATNotification
{
  CATDeclareClass;
  public:
		CATResultNotification( CATBaseUnknown *iObject );

    virtual ~CATResultNotification();
    virtual CATResultNotification* Clone() = 0;
    virtual CATBaseUnknown* GetObject();
	protected:
		CATBaseUnknown_WR _object;
	
	private:
		CATResultNotification( const CATResultNotification& );
};

#endif
