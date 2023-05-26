#ifndef CATModifyReloadVisProperties_h
#define CATModifyReloadVisProperties_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATModify.h"

class ExportedByCATVisItf CATModifyReloadVisProperties : public CATModify
{
	CATDeclareClass;
	
public:
    CATModifyReloadVisProperties(CATBaseUnknown *iObject, int type = -1);
	
    virtual ~CATModifyReloadVisProperties();
	
	virtual CATModelNotification * Clone();
	
	inline int GetType() const;

private :
	int _type;
};

inline int CATModifyReloadVisProperties::GetType() const
{
  return _type;
};


#endif
