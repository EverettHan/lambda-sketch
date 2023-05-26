#ifndef CATModifyReferencePlaneProperties_h
#define CATModifyReferencePlaneProperties_h

#include "CATModify.h"
#include "CAT3DReferencePlaneProperties.h"

class ExportedByCATVisItf CATModifyReferencePlaneProperties : public CATModify
{
	CATDeclareClass;

public:

	CATModifyReferencePlaneProperties(CATBaseUnknown* iObject, const CAT3DReferencePlaneProperties& iProperties);

	virtual ~CATModifyReferencePlaneProperties();

	virtual CATModelNotification* Clone();

	void GetProperties(CAT3DReferencePlaneProperties& oProperties) const;

private:
	CAT3DReferencePlaneProperties _properties;
};

#endif
