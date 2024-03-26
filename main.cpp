#include <stdio.h>
#include <stdlib.h>

#include <aws/lambda-runtime/runtime.h>
#include <aws/core/utils/Array.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/SimpleStringStream.h>

#include <CATBody.h>
#include <CATSoftwareConfiguration.h>
#include <CATTopData.h>
#include <CATMathPoint.h>
#include <CATMathVector.h>
#include <CATMathAxis.h>
#include <CATMathPlane.h>
#include <CATMathBox.h>
#include <CATGeoFactory.h>
#include <CATICGMTopOperator.h>
#include <CATErrorMacros.h>
#include <CATICGMSolidCuboid.h>
#include <CATICGMSolidCylinder.h>
#include <CATICGMTopRevol.h>
#include <CATICGMSolidSphere.h>
#include <CATICGMSolidTorus.h>
#include <CATICGMSolidPyramid.h>
#include <CATICGMCloseOperator.h>
#include <CATCGMContainerMngt.h>
#include <CATGeoFactoryMngt.h>
#include <CATCloneManager.h>
#include <CATSGMC1GeoUtilities.h>
#include <CATCGMStream.h>
#include <CATCGMNoMoreMemory.h>
#include <CATCGMTable.h>
#include <CATLib.h>   
#include <CATCGMDebug.h>
#include <CATCGMStreamVersionUtilities.h>

#include <CATMath.h>
#include <CATPoint.h>
#include <CATPlane.h>                   // Geometric plane
#include <CATVertex.h>                 // Vertex
#include <CATFace.h>                   // Face   
#include <CATCone.h>                                            
#include <ListPOfCATCell.h>                                           
#include <ListPOfCATFace.h>                                                     
#include <ListPOfCATVertex.h>   
#include <CATCrvLimits.h>          // Limits on a curve
#include <CATPCurve.h>
#include <CATPLine.h>
#include <CATICGMTopSkin.h>                // skin operator
#include <CATTopObject.h>
#include <CATTopology.h>

#include "ECSketchDataSet.h"
#include "ECSketchSerializer.h"

#include <SWXUtAssert.h>

#include <fstream.h>

using namespace std;
using namespace Aws::Utils::Json;
using namespace aws::lambda_runtime;

#define TRACE_ERR(...)                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }

#define _DEBUG

static bool saveAsNCGM(CATBody *pBodyIn, const char *pFileName)
{
    TRACE_ERR("Running in save() \n")
    CATGeoFactory *pContainer = NULL;
    CATTry
    {
        pContainer = CATCreateCGMContainer();
        TRACE_ERR("\t Called  CATCreateCGMContainer() \n")
        CATSoftwareConfiguration *pConfig = CATCreateSoftwareConfiguration();
        if (pConfig != NULL)
            TRACE_ERR("\t Successfully getting pConfig = %p \n", (void *)pConfig)
        else
            TRACE_ERR("\t Failed getting pConfig \n")

        CATCloneManager cloneMan(pContainer, CatCGMFullDuplicate, pConfig);
        cloneMan.Add(pBodyIn);
        cloneMan.Run();

        CATGeometry* pResultGeo = (CATGeometry*) cloneMan.ReadImage(pBodyIn);
        CATCGMDebug::PutColor(pResultGeo, 7, 7, 7);
        CATCGMDebug::NoShow(pResultGeo);
        CATCGMDebug::Show(pResultGeo);

        TRACE_ERR("\t Body is cloned \n")

        ofstream filetowrite(pFileName, ios::binary);

        CATSaveCGMContainer((CATGeoFactory *)pContainer, filetowrite);

        filetowrite.close();

        if (!filetowrite)
            TRACE_ERR("\t Failed writing the body into ofstream \n")

        pContainer->Release();
    }
    CATCatch(CATError, err)
    {
        TRACE_ERR("\t Exception is thrown. The error message is: %s \n", err->GetMessageText())
        // TRACE_ERR("\t Exception is thrown. The error message is: %s \n", err->GetNLSMessage().ConvertToChar())

        if (pContainer)
            pContainer->Release();
        return false;
    }
    CATEndTry;

    return true;
}

static ECSketchDataSet* openSketchJSON(const char *pFileName)
{
    std::ifstream fileToRead(pFileName);

    Aws::Utils::Json::JsonValue sketch_json(fileToRead); 
    
    if (!sketch_json.WasParseSuccessful())
    {
        TRACE_ERR("Failed to parse the input sketch JSON. \n")
        return NULL;
    }  

    return ECSketchSerializer::restoreFromJson(sketch_json);
}


static void saveSketchJSON(ECSketchDataSet* pSkDataSet, const char *pFileName)
{
    Aws::Utils::Json::JsonValue sketch_json;      
    ECSketchSerializer::saveAsJson(pSkDataSet, sketch_json);
    auto sketch_view = sketch_json.View();
    Aws::String aws_json_str = sketch_view.WriteReadable();

    std::string std_json_str(aws_json_str.c_str(), aws_json_str.size());
    std::ofstream fileToWrite(pFileName);
    fileToWrite << std_json_str;
    fileToWrite.close();
}

static invocation_response my_handler(invocation_request const &request)
{
    TRACE_ERR("Running in my_handler() \n")

    Aws::Utils::Json::JsonValue json_request(request.payload);
    
    if (!json_request.WasParseSuccessful())
    {
        return invocation_response::failure("Failed to parse the input sketch JSON", "InvalidJSON");
    }  

    ECSketchDataSet* pSkDataSet = ECSketchSerializer::restoreFromJson(json_request);

    if (pSkDataSet)
    {
        bool sketchOk = pSkDataSet->solve();
        if (sketchOk)
        {
            CATBody_var spSkCountourSheet = pSkDataSet->extractCountours();
        }

    }
}

static void runTests()
{
    TRACE_ERR("Running in runTests() \n")

    {   // test 1: 
        ECSketchDataSet* pSkDataSet = openSketchJSON("/home/zhn/git/lamda-sketch/samplesketch.json");
        if (pSkDataSet != NULL)
            TRACE_ERR("\t Successfully getting pSkData = %p \n", (void *)pSkDataSet)
        else
            TRACE_ERR("\t Failed getting pSkDataSet \n")
        if (pSkDataSet)
        {
            saveSketchJSON(pSkDataSet, "/home/zhn/git/lamda-sketch/samplesketch_solved.json");
        }
        delete pSkDataSet;
        pSkDataSet = NULL; 
    }

    {   // test 2: 
        ECSketchDataSet* pSkDataSet = openSketchJSON("/home/zhn/git/lamda-sketch/samplesketch.json");
        if (pSkDataSet != NULL)
            TRACE_ERR("\t Successfully getting pSkData = %p \n", (void *)pSkDataSet)
        else
            TRACE_ERR("\t Failed getting pSkDataSet \n")
        if (pSkDataSet)
        {
            bool sketchOk = pSkDataSet->solve();
            saveSketchJSON(pSkDataSet, "/home/zhn/git/lamda-sketch/samplesketch_solved.json");
            if (sketchOk)
            {
                CATBody_var spSkCountourSheet = pSkDataSet->extractCountours();
                saveAsNCGM(spSkCountourSheet,"/home/zhn/git/lamda-sketch/samplesketch_countour.ncgm");
            }

        }
        delete pSkDataSet;
        pSkDataSet = NULL; 
    }
}


static void initializeCGM()
{
    TRACE_ERR("Running in initializeCGM() \n")

    int status = CATCGMTable(0, 314159);
    printf("CATCGMTable returns status = %d\n", status);
#ifdef _DEBUG
    CATPutEnv("CATDictionaryPath=/home/zhn/git/lambda-prism/ThirdParty/CGM_R425/linux_a64/code/dictionary");
#endif

    const char *pDicPath = CATGetEnv("CATDictionaryPath");
    TRACE_ERR("\t CATDictionaryPath is set at: %s \n", pDicPath);

    TRACE_ERR("\t To call CATCreateCGMContainer \n")
    CATGeoFactory *pFactory = CATCreateCGMContainer();
    if (pFactory != NULL)
        TRACE_ERR("\t Successfully getting pFactory = %p \n", (void *)pFactory)
    else
        TRACE_ERR("\t Failed getting pFactory \n")

    CATCloseCGMContainer(pFactory);
}

int main()
{
    TRACE_ERR("Running in main() \n")

    initializeCGM();

#ifdef _DEBUG
    TRACE_ERR("\t Calling runTests() \n")
    runTests();
#else
    TRACE_ERR("\t Calling my_handler() \n")
    run_handler(my_handler);
#endif
    return 0;
}
