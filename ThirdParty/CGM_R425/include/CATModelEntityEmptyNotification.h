#ifndef CATModelEntityEmptyNotification_H
#define CATModelEntityEmptyNotification_H

#include "CATModelEntityNotification.h"

// E8C
// WARNING : internal use
// this class is meant to be use by xDesign to notify 3DSync of a pure SceneGraph modification for their preview visualization

/** @nodoc */
class ExportedByCATVisItf CATModelEntityEmptyNotification : public CATModelEntityNotification
{
  CATDeclareClass;

public:
	CATModelEntityEmptyNotification(CATBaseUnknown* iObject);
	~CATModelEntityEmptyNotification();

	virtual CATModelNotification* Clone();

private:

	// NOT implemented, to prevent default
	CATModelEntityEmptyNotification(const CATModelEntityEmptyNotification&);
	CATModelEntityEmptyNotification& operator=(const CATModelEntityEmptyNotification&);
};

#endif
