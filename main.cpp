#include <stdio.h>
#include <stdlib.h>

#include <aws/lambda-runtime/runtime.h>
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

#include <PrimitiveData.h>

#include <fstream.h>
using namespace std;

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

static ECSketchData* openSketchJSON(const char *pFileName)
{
    std::ifstream filetoread(pFileName);

    using namespace Aws::Utils::Json;

    JsonValue sketch_json(filetoread);    

    return readSketchData(sketch_json);
}

static ECSketchData* readSketchData(JsonValue& sketch_json)
{
    if (!sketch_json.WasParseSuccessful())
    {
        return invocation_response::failure("Failed to parse the input sketch JSON", "InvalidJSON");
    }

    auto sketch_view = sketch_json.View();

    if (sketch_view.ValueExists("primitive_type"))
    {
        TRACE_ERR("\t parsing payload data \n")
        std::string typeStr = request_view.GetString("primitive_type");
        PrimitiveType primitive_type = PrimitiveType::None;
        if (typeStr == "primitive_cuboid")
            primitive_type = PrimitiveType::Cuboid;
        if (typeStr == "primitive_pyramid")
            primitive_type = PrimitiveType::Pyramid;
        else if (typeStr == "primitive_cylinder")
            primitive_type = PrimitiveType::Cylinder;
        else if (typeStr == "primitive_cone")
            primitive_type = PrimitiveType::Cone;
        else if (typeStr == "primitive_sphere")
            primitive_type = PrimitiveType::Sphere;
        else if (typeStr == "primitive_torus")
            primitive_type = PrimitiveType::Torus;
        else
        {
            TRACE_ERR("\t Wrong primitive_type parameter!!! exception thrown \n")
            return invocation_response::failure("'primitive_type' is wrong", "InvalidJSON");
        }
        double x = request_view.GetDouble("location_X");
        double y = request_view.GetDouble("location_Y");
        double z = request_view.GetDouble("location_Z");
        double l = request_view.GetDouble("size_length");
        double w = request_view.GetDouble("size_width");
        double h = request_view.GetDouble("size_height");

    }
}

static invocation_response my_handler(invocation_request const &request)
{
    TRACE_ERR("Running in my_handler() \n")

    using namespace Aws::Utils::Json;

    JsonValue json_request(request.payload);
    ECSketchData* pSkData = readSketchData(json_request);
}

static void runTests()
{
    TRACE_ERR("Running in runTests() \n")

    ECSketchData* pSkData = openSketchJSON("samplesketch.json");
    if (pSkData != NULL)
        TRACE_ERR("\t Successfully getting pSkData = %p \n", (void *)pSkData)
    else
        TRACE_ERR("\t Failed getting pSkData \n")

    TRACE_ERR("\t To call CATCreateSoftwareConfiguration \n")
    CATSoftwareConfiguration *pConfig = CATCreateSoftwareConfiguration();
    if (pConfig != NULL)
        TRACE_ERR("\t Successfully getting pConfig = %p \n", (void *)pConfig)
    else
        TRACE_ERR("\t Failed getting pConfig \n")
    
    

    {// test 1: 
    
    }
     
    CATCloseCGMContainer(pFactory);
    pFactory = NULL;
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
