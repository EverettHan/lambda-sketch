/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATResultCompletedNotification_h
#define CATResultCompletedNotification_h

#include "CATResultNotification.h"

class ExportedByAD0XXBAS CATResultCompletedNotification : public CATResultNotification
{
  CATDeclareClass;

  public:
    CATResultCompletedNotification(CATBaseUnknown *iObject);
    virtual ~CATResultCompletedNotification();
    virtual CATResultNotification* Clone();
	private:
		CATResultCompletedNotification( const CATResultCompletedNotification& );
};

#endif
