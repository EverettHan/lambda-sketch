#ifndef ECSketchJasonUtils_H
#define ECSketchJasonUtils_H


#include <string>

class ECSketchDataSet;

class ECSketchJasonUtils
{
public:
    static ECSketchDataSet* readJson(std::string& jsonIn);
    static void saveAsJson(ECSketchDataSet* pSkDataSetIn, std::string& jsonOut);

protected:

private:
    ECSketchJasonUtils();
};



#endif //ECSketchJasonUtils_H