#ifndef CATSysNetworkStatisticsNotification_H
#define CATSysNetworkStatisticsNotification_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "JS03TRA.h"
#include "CATNotification.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/
//===============================================================
//===============================================================
/**
 * @class CATSysNetworkStatisticsNotification
 * @brief Network statistics published event notification
 */
class ExportedByJS03TRA CATSysNetworkStatisticsNotification : public CATNotification
{
  // Used in conjunction with CATImplementClass in the .cpp file 
  CATDeclareClass;

public:
  /// Constructor
  CATSysNetworkStatisticsNotification()
  { }

  /// Destructor
  virtual ~CATSysNetworkStatisticsNotification()
  { }

private:
  // Copy constructor, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATSysNetworkStatisticsNotification(const CATSysNetworkStatisticsNotification &iObjectToCopy);

  // Assignment operator, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATSysNetworkStatisticsNotification & operator = (const CATSysNetworkStatisticsNotification &iObjectToCopy);
};

#endif // CATSysNetworkStatisticsNotification_H
