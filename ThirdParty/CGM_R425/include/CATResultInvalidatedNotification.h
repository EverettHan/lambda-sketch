/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATResultInvalidatedNotification_h
#define CATResultInvalidatedNotification_h

#include "CATResultNotification.h"

class ExportedByAD0XXBAS CATResultInvalidatedNotification : public CATResultNotification
{
  CATDeclareClass;
  public:
  
    CATResultInvalidatedNotification(CATBaseUnknown *iObject);
    virtual ~CATResultInvalidatedNotification();
    virtual CATResultNotification* Clone();
	private:
		CATResultInvalidatedNotification( const CATResultInvalidatedNotification& );
};

#endif
