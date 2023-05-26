// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef _CATCCPNotificationS_H
#define _CATCCPNotificationS_H

/**
 * @level Private 
 * @usage U1
 */

#include "AD0XXBAS.h"

#include "CATNotification.h"
#include "CATBaseUnknown.h"


class CATListValCATBaseUnknown_var;


enum CATCCPStatus
{
	DD_MOVE,
    DD_COPY,
	DD_LINK,
	CCP_STD
};



class ExportedByAD0XXBAS CATCCPNotification : public CATNotification
{
  public:
    CATCCPNotification(CATCCPStatus stat);
    virtual ~CATCCPNotification();
    
    virtual int IsAKindOf(const char *) const;
    virtual const char* IsA() const;
    static  const char* ClassName();
    void    FeedPath(const CATBaseUnknown_var& obj);
    CATListValCATBaseUnknown_var* GivePath();
   CATCCPStatus GiveStatus() {return _status;}


  private :
      
      CATListValCATBaseUnknown_var*    _path;
       CATCCPStatus		  _status;

};
  

#endif
