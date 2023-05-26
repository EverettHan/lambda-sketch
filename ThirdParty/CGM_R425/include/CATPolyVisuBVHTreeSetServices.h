#ifndef CATPolyVisuBVHTreeSetServices_H_
#define CATPolyVisuBVHTreeSetServices_H_

#include <string>

#include "DSYExport.h"

class CATPolyVisuBVHTreeSet;
class DSYSysJSONValue;

// Helper to stream bvhtree inputs.

extern "C" DSYExport void CATPolyVisuBVHTreeSetToJson(CATPolyVisuBVHTreeSet &iotreeset, std::string BaseFile, DSYSysJSONValue & oJson);

extern "C" DSYExport void CATPolyVisuBVHTreeSetToJsonFile(CATPolyVisuBVHTreeSet &iotreeset, std::string BaseFile);

extern "C" DSYExport void CATPolyVisuBVHTreeSetFromJson(DSYSysJSONValue &iJson, CATPolyVisuBVHTreeSet &iotreeset);
extern "C" DSYExport void CATPolyVisuBVHTreeSetFromJsonFile(std::string iJsonFile, CATPolyVisuBVHTreeSet &iotreeset);

#endif
