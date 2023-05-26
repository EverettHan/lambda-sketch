#ifndef VisMaterialNotification_H
#define VisMaterialNotification_H

#include "CATMaterialNotification.h"

class ExportedBySGInfra VisMaterialNotification : public CATMaterialNotification
{
	// macros
	CATDeclareClass;

public:
	/**
	 * Constructs a notification.
	 * @param iType
	 */
	VisMaterialNotification(const CATMaterialNotificationType iType,
		const bool iIsSparse = false);

	virtual ~VisMaterialNotification();

	const bool& GetIsSparse(void) const { return _IsSparse; }

private:
	bool _IsSparse;
};

#endif // VisMaterialNotification_H
