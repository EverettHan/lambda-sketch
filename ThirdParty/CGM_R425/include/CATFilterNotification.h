/* -*-c++-*- */
#ifndef CATFilterNotification_H
#define CATFilterNotification_H

// COPYRIGHT DASSAULT SYSTEMES 2018


#include "CATNotification.h"
#include "SGInfra.h"

enum class CATFilterNotificationType 
{
	CATUpdateFilterNotification,
	CATInvalidRep,
    CATAFAddFilter,
    CATAFRemFilter,
	CATAFAddPathNotif,
    CATAFAddAllPathsNotif,
	CATAFRemPathNotif,
    CATAFRemAllPathsNotif,
	CATAFPathValueChangeNotif,
	CATAFPathValueNonObsrvNotif
};

class ExportedBySGInfra CATFilterNotification : public CATNotification
{
  // macros
  CATDeclareClass;

public:

  // 'tors
  virtual ~CATFilterNotification();

  /** 
   * Constructs a notification.
   * @param iType
   */
  CATFilterNotification(CATFilterNotificationType iType);

  /** Returns the type of the notification. */
  CATFilterNotificationType GetFilterNotificationType() const;

private:
  CATFilterNotificationType _TypeNotification;
};

#endif // CATfilterNotification_H
