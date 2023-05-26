#ifndef _CATOpenContextualMenuNotif
#define _CATOpenContextualMenuNotif

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATNotification.h"
#include "CATVisFoundation.h"

#ifdef _WINDOWS_SOURCE
#else
#ifndef _POINTL_DEFINED
#define _POINTL_DEFINED
/**
 * @nodoc 
 */
typedef struct _POINTL
{
        LONG x;
        LONG y;
}POINTL;
#endif
#endif

class ExportedByCATVisFoundation CATOpenContextualMenuNotif : public CATNotification
{
  CATDeclareClass;

  public:
    CATOpenContextualMenuNotif(POINTL& ipoint);
    virtual ~CATOpenContextualMenuNotif();
    POINTL& GetAnchorPoint ();

private :
  POINTL _point;
};

#endif
