#ifndef CATPLMIDTextStreamExtensions_H
#define CATPLMIDTextStreamExtensions_H

#include "CATPLMIdentificationAccess.h"

class CATOmxTextStream;

class CATPLMID;
/**outputs a CATPLMID for debugging purpose*/
ExportedByCATPLMIdentificationAccess CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATPLMID& id);

class CATPLMID_Simple;
/**outputs a CATPLMID for debugging purpose*/
ExportedByCATPLMIdentificationAccess CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATPLMID_Simple& id);

class CATPLMID_Any;
/**outputs a CATPLMID_Any for debugging purpose*/
ExportedByCATPLMIdentificationAccess CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATPLMID_Any& id);

class CATPLMTypeH;
/**outputs a CATPLMTypeH for debugging purpose*/
ExportedByCATPLMIdentificationAccess CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATPLMTypeH& type);

class CATPLMTypeId;
/**outputs a CATPLMTypeId for debugging purpose*/
ExportedByCATPLMIdentificationAccess CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATPLMTypeId& type);

class CATPLMType;
/**outputs a CATPLMType for debugging purpose*/
ExportedByCATPLMIdentificationAccess CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATPLMType* type);
/**outputs a CATPLMType for debugging purpose*/
inline CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATPLMType& type) { return out << &type; }

class CATPLMRepositoryName;
/**outputs a CATPLMRepositoryName for debugging purpose*/
ExportedByCATPLMIdentificationAccess CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATPLMRepositoryName& repository);

class CATComponentId;
//this one is there because there is a bad constructor CATPLMType(const CATComponentId& ) which causes unwanted implicit casts
#if defined __CATPLMIdentification
DSYExport
#else
DSYImport
#endif
/**outputs a CATComponentId for debugging purpose*/
CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATComponentId& cid);

#endif
