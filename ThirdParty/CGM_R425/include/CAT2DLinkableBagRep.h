/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CAT2DLinkableBagRep for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CAT2DLinkableBagRep_H
#define CAT2DLinkableBagRep_H

#include "SGInfra.h"
#include "CAT2DBagRep.h"
#include "CATUuid.h"

class ExportedBySGInfra CAT2DLinkableBagRep : public CAT2DBagRep
{
	friend class CAT2DBagRepWithAdvancedTables;

	CATDeclareClass;

public:
	// Standard constructors and destructors
	// -------------------------------------
	virtual ~CAT2DLinkableBagRep();

	inline void           SetUuid(const CATUuid& iUuid);
	inline CATUuid&       GetUuid();
	inline const CATUuid& GetUuid() const;

private:
	CAT2DLinkableBagRep();

	CATUuid _uuid;
};

inline void CAT2DLinkableBagRep::SetUuid(const CATUuid& iUuid)
{
    _uuid = iUuid;
}

inline CATUuid& CAT2DLinkableBagRep::GetUuid()
{
    return _uuid;
}

inline const CATUuid& CAT2DLinkableBagRep::GetUuid() const
{
    return _uuid;
}

#endif


