/* -*-c++-*- */
#ifndef CATMaterialNotification_H
#define CATMaterialNotification_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATNotification.h"
#include "SGInfra.h"

/** 
* Type of Material notification.
* @param CATRedrawNotification 
*   force redraw of scene  
* @param CATUpdateTCNotification
*   force recalculation of texture coordinates 
* @see CATMaterialNotification
*/
enum CATMaterialNotificationType { CATRedrawNotification, CATUpdateTCNotification };

/**
 * Class to create a notification to use with graphic materials and mapping operators.
 * <b>Role</b>: Send this notification to force an update after modifying a
 * graphic material or a mapping operator applied to a representation.
 * @see CATGraphicMaterial, CATMappingOperator
 */
class ExportedBySGInfra CATMaterialNotification : public CATNotification
{
  // macros
  CATDeclareClass;

public:

  // 'tors
  virtual ~CATMaterialNotification();

  /** 
   * Constructs a notification.
   * @param iType
   */
  CATMaterialNotification(CATMaterialNotificationType iType);

  /** Returns the type of the notification. */
  CATMaterialNotificationType GetMaterialNotificationType() const;

private:
  CATMaterialNotificationType _TypeNotification;
};

#endif // CATMaterialNotification_H
