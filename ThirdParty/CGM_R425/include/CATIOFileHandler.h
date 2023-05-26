#ifndef CATIOFileHandler_H
#define CATIOFileHandler_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATIOProtocolHandler.h"
#include "CATIOManager.h"
#include "CATIOAtomics.h"

class ExportedBySGComposites CATIOFileHandler : public CATSGCompositeHost1<CATIOProtocolHandler, CATSGComposite>
{
public:
	CATIOFileHandler(CATIOManagerWeakPtr iIOManager);
	~CATIOFileHandler();

	virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1);

	virtual CATIOUri 			Save(CATIOBufferPtr iIOBuffer, CATIOUri iUri);
    virtual CATIOUri            Append(CATIOBufferPtr iIOBuffer, CATIOUri iUri);
	virtual CATIOBufferPtr 	Load(const CATIOUri iCacheUri);

	virtual CATIOUri 			ProtocolPrefix();
private:
	CATIOManagerWeakPtr 						_ioManager;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOFileHandler_H
