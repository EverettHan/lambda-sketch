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

#include "ECSketchDataSet.h"

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

static void writeSketchData(ECSketchDataSet* pSketchData, JsonValue& sketch_json)
{
}

static ECSketchDataSet* readSketchData(JsonValue& sketch_json)
{
    auto sketch_view = sketch_json.View();

    
    ECSketchDataSet* pSketch = new ECSketchDataSet();
    SU_VERIFY_RETURN(pSketch, "null sketch set\n", NULL);

    TRACE_ERR("\t parsing payload data \n")
    try {
        //SketchName
        if (!sketch_view.ValueExists("SketchName"))
            SU_VERIFY_RETURN(pSketch, "null SketchName\n", NULL);
        std::string skNameStr = sketch_view.GetString("SketchName");
        pSketch->setSketchName(skNameStr);

        //SketchSolveStatus
        if (!sketch_view.ValueExists("SketchSolveStatus"))
            SU_VERIFY_RETURN(pSketch, "null SketchSolveStatus\n", NULL);
        std::string skStatusStr = sketch_view.GetString("SketchSolveStatus");
        pskpSketchetch->setSketchSolveStatus(skStatusStr);

        //SketchToWorldTransform
        Array< JsonValue > xform = sketch_view.GetArray("SketchToWorldTransform");
        SU_VERIFY_RETURN(xform.GetLength()==12, "wrong sketch transform\n", NULL); 
        double coeffs[12];
        coeffs[0] = xform[0].AsDouble();
        coeffs[1] = xform[1].AsDouble();
        coeffs[2] = xform[2].AsDouble();
        coeffs[3] = xform[3].AsDouble();
        coeffs[4] = xform[4].AsDouble();
        coeffs[5] = xform[5].AsDouble();
        coeffs[6] = xform[6].AsDouble();
        coeffs[7] = xform[7].AsDouble();
        coeffs[8] = xform[8].AsDouble();
        coeffs[9] = xform[9].AsDouble();
        coeffs[10]= xform[10].AsDouble();
        coeffs[11]= xform[11].AsDouble();
        pSketch->setSketchXform(coeffs);

        //Points
        Array< JsonValue > ptArr = sketch_view.GetArray("Points");
        SU_VERIFY_RETURN(ptArr.GetLength() > 0, "no sketch points defined\n", NULL); 
        for (int idx = 0; idx <ptArr.GetLength(); idx++)
        {
            JsonValue aPt = ptArr[idx];
            auto skPt_view = aPt.View();
            std::string skPtNameStr = skPt_view.GetString("EntityName");
            
            Array< JsonValue > xyzArr = skPt_view.GetArray("Coordinates");
            double x_coor = xyzArr[0].AsDouble();
            double y_coor = xyzArr[1].AsDouble();
            double z_coor = xyzArr[2].AsDouble();

            bool bIsFixed = skPt_view.GetBool("Fixed");

            shared_ptr<ECSketchPoint> spPt = std::make_shared<ECSketchPoint>(x_coor, y_coor, z_coor);
            spPt->setName(skPtNameStr);
            svGeometryStatus svStat = bIsFixed ? svFixed : svInvalidGeomStatus;
            spPt->setGeometrySolveStatus(svStat);

            pSketch->addPoint(spPt);
        }

        //Curves
        Array< JsonValue > curveArr = sketch_view.GetArray("Curves");
        SU_VERIFY_RETURN(curveArr.GetLength() > 0, "no sketch points defined\n", NULL); 
        for (int idx = 0; idx <curveArr.GetLength(); idx++)
        {
            JsonValue aCurve = curveArr[idx];
            auto skCurve_view = aCurve.View();
            std::string skCurveNameStr = skCurve_view.GetString("EntityName");
            bool bIsFixed = skCurve_view.GetBool("Fixed");
            svGeometryStatus svStat = bIsFixed ? svFixed : svInvalidGeomStatus;

            std::string skCurveTypeStr = skCurve_view.GetString("EntityType");
            if (skCurveTypeStr == "Line")
            {
                Array< JsonValue > ptArr = skCurve_view.GetArray("LinePoint");
                double x_pt = ptArr[0].AsDouble();
                double y_pt = ptArr[1].AsDouble();
                double z_pt = ptArr[2].AsDouble();

                Array< JsonValue > dirArr = skCurve_view.GetArray("LineDirection");
                double x_dir = dirArr[0].AsDouble();
                double y_dir = dirArr[1].AsDouble();
                double z_dir = dirArr[2].AsDouble();
                
                shared_ptr<ECSketchLine> spln = std::make_shared<ECSketchLine>(x_pt, y_pt, z_pt, x_dir, y_dir, z_dir);
                spln->setName(skCurveNameStr);
                spln->setGeometrySolveStatus(svStat);

                pSketch->addCurve(spln);
            }
            else if (skCurveTypeStr == "LineSegment")
            {
                Array< JsonValue > ptArr = skCurve_view.GetArray("EndPoints");
                std::string pt1Name = ptArr[0].AsString();
                std::string pt2Name = ptArr[1].AsString();
                std::shared_ptr<ECSketchPoint> spPt1 = pSketch->findSketchPoint(pt1Name);
                std::shared_ptr<ECSketchPoint> spPt2 = pSketch->findSketchPoint(pt2Name);

                SU_VERIFY_RETURN(spPt1 != nullptr && spPt2 != nullptr, "no sketch points found for lineSegment\n", NULL);

                shared_ptr<ECSketchLineSegment> splnSeg = std::make_shared<ECSketchLineSegment>(spPt1, spPt2);
                splnSeg->setName(skCurveNameStr);
                splnSeg->setGeometrySolveStatus(svStat);

                pSketch->addCurve(splnSeg);

            }
            else if (skCurveTypeStr == "Circle")
            {
                std::string centerNameStr = skCurve_view.GetString("Center");
                std::shared_ptr<ECSketchPoint> spPt1 = pSketch->findSketchPoint(centerNameStr);
                double r = skCurve_view.GetDouble("Radius");
                CATMathDirection dirIn(0.0, 0.0, 1.0);

                shared_ptr<ECSketchCircle> spCircle = std::make_shared<ECSketchCircle>(spPt1, dirIn, r);
                spCircle->setName(skCurveNameStr);
                spCircle->setGeometrySolveStatus(svStat);

                pSketch->addCurve(spCircle);
            }
            else if (skCurveTypeStr == "Arc")
            {
                std::string centerNameStr = skCurve_view.GetString("Center");
                std::shared_ptr<ECSketchPoint> spPt1 = pSketch->findSketchPoint(centerNameStr);
                std::string centerNameStr = skCurve_view.GetString("StartPoint");
                std::shared_ptr<ECSketchPoint> spPt2 = pSketch->findSketchPoint(centerNameStr);
                std::string centerNameStr = skCurve_view.GetString("EndPoint");
                std::shared_ptr<ECSketchPoint> spPt3 = pSketch->findSketchPoint(centerNameStr);
                double r = skCurve_view.GetDouble("Radius");
                CATMathDirection dirIn(0.0, 0.0, 1.0);

                shared_ptr<ECSketchArc> spArc = std::make_shared<ECSketchArc>(spPt1, spPt2, spPt3, dirIn, r);
                spArc->setName(skCurveNameStr);
                spArc->setGeometrySolveStatus(svStat);

                pSketch->addCurve(spArc);
            }
            else if (skCurveTypeStr == "Ellipse")
            {
                std::string centerNameStr = skCurve_view.GetString("Center");
                std::shared_ptr<ECSketchPoint> spPt1 = pSketch->findSketchPoint(centerNameStr);
                double r1 = skCurve_view.GetDouble("MajorRadius");
                double r2 = skCurve_view.GetDouble("MinorRadius");

                shared_ptr<ECSketchCircle> spEllipse = std::make_shared<ECSketchCircle>(spPt1, x_dirIn, y_dir, r1, r2);
                spEllipse->setName(skCurveNameStr);
                spEllipse->setGeometrySolveStatus(svStat);

                pSketch->addCurve(spEllipse);
            }
            else
            {
                SU_VERIFY_RETURN(0, "wrong sketch curve type\n", NULL); 
            }
        }

        //Constraints
        Array< JsonValue > constraintArr = sketch_view.GetArray("Constraints");
        SU_VERIFY_RETURN(constraintArr.GetLength() > 0, "no sketch points defined\n", NULL); 
        for (int idx = 0; idx <constraintArr.GetLength(); idx++)
        {
            JsonValue aConstraint = constraintArr[idx];
            auto constraint_view = aConstraint.View();

            std::string constraintNameStr = constraint_view.GetString("ConstraintName");
            bool bIsFixed = constraint_view.GetBool("Fixed");
            svGeometryStatus svStat = bIsFixed ? svFixed : svInvalidGeomStatus;

            std::string constraintTypeStr = constraint_view.GetString("ContraintType");
            if (constraintTypeStr == "svParallel")
            {
                /* 
                {
                    "ConstraintName": "pa21",
                    "ContraintType": "svParallel",
                    "ContraintEntities": [ "ln9", "ln2" ]
                }
                */

                Array< JsonValue > entArr = constraint_view.GetArray("ContraintEntities");
                size_t count = entArr.GetLength();
                std::string ent1Name;
                if (count >= 1) ent1Name = entArr[0].AsString();
                std::string ent2Name;
                if (count >= 2) ent2Name = entArr[1].AsString();
                std::string ent3Name;
                if (count >= 3) ent3Name = entArr[2].AsString();
                std::string ent4Name;
                if (count >= 4) ent4Name = entArr[3].AsString();
                std::shared_ptr<ECSketchEntity> spEnt1 = pSketch->findSketchPoint(pt1Name);
                std::shared_ptr<ECSketchEntity> spEnt2 = pSketch->findSketchPoint(pt2Name);
                std::shared_ptr<ECSketchEntity> spEnt3 = pSketch->findSketchPoint(pt3Name);
                std::shared_ptr<ECSketchEntity> spEnt4 = pSketch->findSketchPoint(pt4Name);
                 
                shared_ptr<ECSketchConstraint> spConstraint = std::make_shared<ECSketchConstraint>(svConstraintType::svParallel, spEnt1, spEnt2, spEnt3, spEnt4);
                spConstraint->setName(constraintNameStr);

                bool didIt = pSketch->addSolverConstraint(spConstraint);
            }
            else if (constraintTypeStr == "svOrthogonal")
            {
                /*
                {
                    "ConstraintName": "pe22",
                    "ContraintType": "svOrthogonal",
                    "ContraintEntities": [ "ln9", "ln2" ]
                }
                */

                
                Array< JsonValue > entArr = constraint_view.GetArray("ContraintEntities");
                size_t count = entArr.GetLength();
                std::string ent1Name;
                if (count >= 1) ent1Name = entArr[0].AsString();
                std::string ent2Name;
                if (count >= 2) ent2Name = entArr[1].AsString();
                std::string ent3Name;
                if (count >= 3) ent3Name = entArr[2].AsString();
                std::string ent4Name;
                if (count >= 4) ent4Name = entArr[3].AsString();
                std::shared_ptr<ECSketchEntity> spEnt1 = pSketch->findSketchPoint(pt1Name);
                std::shared_ptr<ECSketchEntity> spEnt2 = pSketch->findSketchPoint(pt2Name);
                std::shared_ptr<ECSketchEntity> spEnt3 = pSketch->findSketchPoint(pt3Name);
                std::shared_ptr<ECSketchEntity> spEnt4 = pSketch->findSketchPoint(pt4Name);
                 
                shared_ptr<ECSketchConstraint> spConstraint = std::make_shared<ECSketchConstraint>(svConstraintType::svParallel, spEnt1, spEnt2, spEnt3, spEnt4);
                spConstraint->setName(constraintNameStr);

                bool didIt = pSketch->addSolverConstraint(spConstraint);
            }
            else if (constraintTypeStr == "svDistance")
            {
                /*
                {
                    "ConstraintName": "di26",
                    "ContraintType": "svDistance",
                    "ContraintEntities": [ "pt6", "pt7" ],
                    "Value": 95.0
                }
                */

                
                Array< JsonValue > entArr = constraint_view.GetArray("ContraintEntities");
                double valueIn = constraint_view.GetDouble("Value");
                size_t count = entArr.GetLength();
                std::string ent1Name;
                if (count >= 1) ent1Name = entArr[0].AsString();
                std::string ent2Name;
                if (count >= 2) ent2Name = entArr[1].AsString();
                std::string ent3Name;
                if (count >= 3) ent3Name = entArr[2].AsString();
                std::string ent4Name;
                if (count >= 4) ent4Name = entArr[3].AsString();
                std::shared_ptr<ECSketchEntity> spEnt1 = pSketch->findSketchPoint(pt1Name);
                std::shared_ptr<ECSketchEntity> spEnt2 = pSketch->findSketchPoint(pt2Name);
                std::shared_ptr<ECSketchEntity> spEnt3 = pSketch->findSketchPoint(pt3Name);
                std::shared_ptr<ECSketchEntity> spEnt4 = pSketch->findSketchPoint(pt4Name);
                 
                shared_ptr<ECSketchConstraint> spConstraint = std::make_shared<ECSketchConstraint>(svConstraintType::svParallel, spEnt1, spEnt2, spEnt3, spEnt4, valueIn);
                spConstraint->setName(constraintNameStr);

                bool didIt = pSketch->addSolverConstraint(spConstraint);
            }
            else if (constraintTypeStr == "svCoincident") { }             
            else if (constraintTypeStr == "svAngle") { }
            else if (constraintTypeStr == "svRadius") { }
            else if (constraintTypeStr == "svTangent") { }
            else if (constraintTypeStr == "svConcentric") { }
            else if (constraintTypeStr == "svArcLength") { }
            else if (constraintTypeStr == "svMidPoint") { }
            else if (constraintTypeStr == "svHorizontal") { }
            else if (constraintTypeStr == "svVertical") { }
            else if (constraintTypeStr == "svAlongX") { }
            else if (constraintTypeStr == "svAlongY") { }
            else if (constraintTypeStr == "svAlongZ") { }
            else if (constraintTypeStr == "svCollinear") { }
            else if (constraintTypeStr == "svAlongZ") { }

        }
    }
    catch (std::exception &e) { 
       ...
    };
    return pSketch;
   
}

static ECSketchDataSet* openSketchJSON(const char *pFileName)
{
    std::ifstream filetoread(pFileName);

    JsonValue sketch_json(filetoread);  
    
    if (!sketch_json.WasParseSuccessful())
    {
        TRACE_ERR("Failed to parse the input sketch JSON. \n")
        return NULL;
    }  

    return readSketchData(sketch_json);
}


static void saveSketchJSON(ECSketchDataSet* pSkDataSet, const char *pFileName)
{
    std::ofstream fileToWrite(pFileName);

    JsonValue sketch_json(fileToWrite);  
    
    return writeSketchData(pSkDataSet, sketch_json);
}

static invocation_response my_handler(invocation_request const &request)
{
    TRACE_ERR("Running in my_handler() \n")

    JsonValue json_request(request.payload);
    
    if (!json_request.WasParseSuccessful())
    {
        return invocation_response::failure("Failed to parse the input sketch JSON", "InvalidJSON");
    }  

    ECSketchDataSet* pSkDataSet = readSketchData(json_request);

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

    ECSketchDataSet* pSkDataSet = openSketchJSON("/home/zhn/git/lamda-sketch/samplesketch.json");
    if (pSkDataSet != NULL)
        TRACE_ERR("\t Successfully getting pSkData = %p \n", (void *)pSkDataSet)
    else
        TRACE_ERR("\t Failed getting pSkDataSet \n")

    

    {   // test 1: 
        if (pSkDataSet)
        {
            bool sketchOk = pSkDataSet->solve();
            saveSketchJSON(pSkDataSet, "/home/zhn/git/lamda-sketch/samplesketch_solved.json");
            if (sketchOk)
            {
                CATBody_var spSkCountourSheet = pSkDataSet->extractCountours();
            }

        }
    }
    delete pSkDataSet;
    pSkDataSet = NULL; 
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
