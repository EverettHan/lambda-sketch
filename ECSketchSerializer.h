#ifndef ECSketchSerializer_H
#define ECSketchSerializer_H


#include <aws/core/utils/Array.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/SimpleStringStream.h>

#include <string>

class ECSketchDataSet;

class ECSketchSerializer
{
public:
    static ECSketchDataSet* restoreFromJson(Aws::Utils::Json::JsonValue& sketch_json);
    static void saveAsJson(ECSketchDataSet* pSkDataSetIn, Aws::Utils::Json::JsonValue& sketch_json);

protected:

private:
    ECSketchSerializer();
};



#endif //ECSketchSerializer_H