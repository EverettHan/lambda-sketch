#include <ECSketchSerializer.h>
#include <ECSketchDataSet.h>

#include <SWXUtAssert.h>


#define TRACE_ERR(...)                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }


void ECSketchSerializer::saveAsJson(ECSketchDataSet* pSkDataSetIn, Aws::Utils::Json::JsonValue& sketch_json)
{
        /*"SketchName": "sk1",*/
    sketch_json.WithString("SketchName", pSkDataSetIn->getSketchName());

    /*"SketchToWorldTransform": [1.0, 0.0, 0,  0.0, 1.0, 0.0,  0.0, 0.0, 1.0,  1.0, 2.0, 3.0],*/
    double xform[12];
    pSkDataSetIn->getSketchXform(xform);
    Aws::Utils::Array<Aws::Utils::Json::JsonValue> xf_array(12);
    Aws::Utils::Json::JsonValue value;
    xf_array[0] = value.AsDouble(xform[0]);
    xf_array[1] = value.AsDouble(xform[1]);
    xf_array[2] = value.AsDouble(xform[2]);
    xf_array[3] = value.AsDouble(xform[3]);
    xf_array[4] = value.AsDouble(xform[4]);
    xf_array[5] = value.AsDouble(xform[5]);
    xf_array[6] = value.AsDouble(xform[6]);
    xf_array[7] = value.AsDouble(xform[7]);
    xf_array[8] = value.AsDouble(xform[8]);
    xf_array[9] = value.AsDouble(xform[9]);
    xf_array[10] = value.AsDouble(xform[10]);
    xf_array[11] = value.AsDouble(xform[11]);
    sketch_json.WithArray("SketchToWorldTransform", xf_array);

    /*"Points": [
    {
      "EntityName": "pt4",
      "Coordinates": [ 0.0, 0.0, 0.0 ],
      "Fixed": true
    }, ...]*/

    int numOfPts = pSkDataSetIn->m_vecPoints.size();
    Aws::Utils::Array<Aws::Utils::Json::JsonValue> pt_array(numOfPts);

    int ptIndex=0;
    for (auto & spPoint :  pSkDataSetIn->m_vecPoints) 
	{		
        Aws::Utils::Json::JsonValue ptObject;
        
        ptObject.WithString("EntityName", spPoint->getName());

        svGeometryStatus svStat = spPoint->getGeometrySolveStatus();
        ptObject.WithBool("Fixed", svStat==svFixed ? true : false);

        Aws::Utils::Array<Aws::Utils::Json::JsonValue> xyz_array(3);
        Aws::Utils::Json::JsonValue value;
        xyz_array[0] = value.AsDouble(spPoint->getX());
        xyz_array[1] = value.AsDouble(spPoint->getY());
        xyz_array[2] = value.AsDouble(spPoint->getZ());
        ptObject.WithArray("Coordinates", xyz_array);
    

        pt_array[ptIndex] = value.AsObject(ptObject);
        ptIndex++;
	}
    sketch_json.WithArray("Points", pt_array);

    /*"Curves": [
    {
      ...
    },*/

    int numOfCurves = pSkDataSetIn->m_vecCurves.size();
    Aws::Utils::Array<Aws::Utils::Json::JsonValue> curve_array(numOfCurves);

    int cvIndex=0;
    for (auto & spCurve : pSkDataSetIn->m_vecCurves) 
	{			
        Aws::Utils::Json::JsonValue cvObject;
        
        cvObject.WithString("EntityName", spCurve->getName());
        cvObject.WithString("EntityType", spCurve->getTypeString());
        svGeometryStatus svStat = spCurve->getGeometrySolveStatus();
        cvObject.WithBool("Fixed", svStat==svFixed ? true : false);

        std::string skCurveTypeStr = spCurve->getTypeString();
        if (skCurveTypeStr == "Line")
        {
            /*{
            "EntityName": "ln2",
            "EntityType": "Line",
            "LinePoint": [ 0.0, 0.0, 0.0 ],
            "LineDirection": [ 1.0, 0.0, 0.0 ],
            "Fixed": true
            },*/
            shared_ptr<ECSketchLine> spLine = std::dynamic_pointer_cast<ECSketchLine>(spCurve);

            Aws::Utils::Array< Aws::Utils::Json::JsonValue > ptArr(3);
            Aws::Utils::Json::JsonValue value;

            SWXUtLine* pUtLine =  spLine->getGeometry();

            double x, y, z, dir_x, dir_y, dir_z;
            pUtLine->PointCoord(x, y, z);
            pUtLine->DirectionCoord(dir_x, dir_y, dir_z);
                
            ptArr[0] = value.AsDouble(x);
            ptArr[1] = value.AsDouble(y);
            ptArr[2] = value.AsDouble(z);
            cvObject.WithArray("LinePoint", ptArr);

            Aws::Utils::Array< Aws::Utils::Json::JsonValue > dirArr(3);
            dirArr[0] = value.AsDouble(dir_x);
            dirArr[1] = value.AsDouble(dir_y);
            dirArr[2] = value.AsDouble(dir_z);
            cvObject.WithArray("LineDirection", dirArr);

        }
        else if (skCurveTypeStr == "LineSegment")
        {
            /* {
            "EntityName": "ln9",
            "EntityType": "LineSegment",
            "EndPoints": [ "pt5", "pt6" ],
            "Fixed": false
            }*/

            shared_ptr<ECSketchLineSegment> spLineSeg = std::dynamic_pointer_cast<ECSketchLineSegment>(spCurve);

            std::string pt1Name = spLineSeg->getStartPt()->getName();
	        std::string pt2Name = spLineSeg->getEndPt()->getName();

            Aws::Utils::Array< Aws::Utils::Json::JsonValue > ptArr(2);
            Aws::Utils::Json::JsonValue value;
                
            ptArr[0] = value.AsString(pt1Name);
            ptArr[1] = value.AsString(pt2Name);

            cvObject.WithArray("EndPoints", ptArr);         

        }
        else if (skCurveTypeStr == "Circle")
        {
            /*{
            "EntityName": "ci29",
            "EntityType": "Circle",
            "Center": "pt28",
            "Radius": 30.730043393114904,
            "Fixed": false
            }*/
            
            shared_ptr<ECSketchCircle> spCircle = std::dynamic_pointer_cast<ECSketchCircle>(spCurve);

            std::string pt1Name = spCircle->getCenterPt()->getName();
            double r =  spCircle->getRadius();

            cvObject.WithString("Center", pt1Name);
            cvObject.WithDouble("Radius", r);
        }
        else if (skCurveTypeStr == "Arc")
        {
            /*{
            "EntityName": "arc29",
            "EntityType": "Arc",
            "Center": "pt28",
            "StartPoint": "pt29",
            "EndPoint": "pt30",
            "Radius": 30.730043393114904,
            "Fixed": false
            }*/
            
            shared_ptr<ECSketchArc> spArc = std::dynamic_pointer_cast<ECSketchArc>(spCurve);

            std::string pt1Name = spArc->getCenterPt()->getName();
            std::string pt2Name = spArc->getStartPt()->getName();
            std::string pt3Name = spArc->getEndPt()->getName();
            double r =  spArc->getRadius();

            cvObject.WithString("Center", pt1Name);
            cvObject.WithString("StartPoint", pt2Name);
            cvObject.WithString("EndPoint", pt3Name);
            cvObject.WithDouble("Radius", r);
        }
        else if (skCurveTypeStr == "Ellipse")
        {
            /*{
            "EntityName": "el29",
            "EntityType": "Ellipse",
            "Center": "pt28",
            "xDir": [1,0,0],
            "yDir": [0,1,0],
            "MajorRadius": 30.730043393114904,
            "MinorRadius": 10.245043393114904,
            "Fixed": false
            }*/
            
            shared_ptr<ECSketchEllipse> spEllipse = std::dynamic_pointer_cast<ECSketchEllipse>(spCurve);

            std::string pt1Name = spEllipse->getCenterPt()->getName();
            cvObject.WithString("Center", pt1Name);

            SWXUtEllipse* pUtEllipse = spEllipse->getGeometry();

            double xDir_x, xDir_y, xDir_z;
            double yDir_x, yDir_y, yDir_z;
            pUtEllipse->XDirCoord(xDir_x, xDir_y, xDir_z);
	        pUtEllipse->YDirCoord(yDir_x, yDir_y, yDir_z);
                
            Aws::Utils::Array< Aws::Utils::Json::JsonValue > xDirArr(3);
            xDirArr[0] = value.AsDouble(xDir_x);
            xDirArr[1] = value.AsDouble(xDir_y);
            xDirArr[2] = value.AsDouble(xDir_z);
            cvObject.WithArray("xDir", xDirArr);

            Aws::Utils::Array< Aws::Utils::Json::JsonValue > yDirArr(3);
            yDirArr[0] = value.AsDouble(yDir_x);
            yDirArr[1] = value.AsDouble(yDir_y);
            yDirArr[2] = value.AsDouble(yDir_z);
            cvObject.WithArray("yDir", yDirArr);

            double rMajor = pUtEllipse->GetMajorRadius();
            cvObject.WithDouble("MajorRadius", rMajor);
	        double rMinor = pUtEllipse->GetMinorRadius();
            cvObject.WithDouble("MinorRadius", rMinor);
        }
        else
        {
            SWX_VERIFY_CONTINUE(0, "wrong sketch curve type\n"); 
        }

        curve_array[cvIndex] = value.AsObject(cvObject);
        cvIndex++;
	}
    sketch_json.WithArray("Curves", curve_array);

    /*"Constraints": [
    {
      ...
    },*/
    int numOfConstrints = pSkDataSetIn->m_vecConstraints.size();
    Aws::Utils::Array<Aws::Utils::Json::JsonValue> constraint_array(numOfConstrints);

    int cnIndex=0;
    for (auto & spConstraint : pSkDataSetIn->m_vecConstraints) 
	{			
        /*{
        "ConstraintName": "di26",
        "ContraintType": "svDistance",
        "ContraintEntities": [ "pt6", "pt7" ],
        "Value": 95.0
        }*/
        Aws::Utils::Json::JsonValue cnObject;
        
        cnObject.WithString("ConstraintName", spConstraint->getName());
        
        std::string ent1, ent2, ent3, ent4;
        int numOfEnts = spConstraint->getEntitieNames(ent1, ent2, ent3, ent4);
        Aws::Utils::Array< Aws::Utils::Json::JsonValue > entArr(numOfEnts);
        Aws::Utils::Json::JsonValue value;
        if (numOfEnts>=1)
            entArr[0] = value.AsString(ent1);
        if (numOfEnts>=2)
            entArr[1] = value.AsString(ent2);
        if (numOfEnts>=3)
            entArr[2] = value.AsString(ent3);
        if (numOfEnts>=4)
            entArr[3] = value.AsString(ent4);
        cnObject.WithArray("ContraintEntities", entArr);
        
        svConstraintType type = spConstraint->getConstraintType();
        if (type == svParallel)
        {
            cnObject.WithString("ContraintType", "svParallel");
        }
        else if (type == svOrthogonal)
        {
            cnObject.WithString("ContraintType", "svOrthogonal");
        }
        else if (type == svDistance)
        {
            cnObject.WithString("ContraintType", "svDistance");
            double val;
            spConstraint->getConstraintValue(val);
            cnObject.WithDouble("Value", val);
        }
        else
        {
            SWX_VERIFY_CONTINUE(0, "wrong sketch constraint type\n"); 
        }
        
        constraint_array[cnIndex] = value.AsObject(cnObject);
        cnIndex++;
    }
    sketch_json.WithArray("Constraints", constraint_array);

    //SolverOptions
    /*
        "LinearTolerance": 0.0001,
        "AngularTolerance": 1e-9,
        "DiagnosticsMode": "OldAlways",
        "RigidSetDiagnosticsMode": "WithoutDOS",
        "OverdefinedDiagnosticsMode": "Dimensional",
        "VariableDependencyMode": "Never",
        "ChiralityMode": "Keep",
        "PartialSolvingMode": "Always",
        "UpdateMode": "Evaluate",
        "SolvingMode": "Standard",
        "RereadHelpParameters": true,
        "ForceUsingSketch": false,
        "ContactsDiagnosticsMode": "ClashDetected",
        "CheckUnsolvableConstraintsMode": false,
        "UpdateOutOfClashMode": "None",
        "IncrementalMode": false*/
    ECSkSolverOptions* pOpts =  pSkDataSetIn->getSketchSolverOptions();
    SWX_VERIFY_EXIT(pOpts, "null SolverOptions\n");

    Aws::Utils::Json::JsonValue cnObject;        
    cnObject.WithDouble("LinearTolerance",              pOpts->getLinearTolerance());
    cnObject.WithDouble("LinearTolerance",              pOpts->getAngularTolerance());
    cnObject.WithString("DiagnosticsMode",              pOpts->getDiagnosticsModeString());
    cnObject.WithString("RigidSetDiagnosticsMode",      pOpts->getRigidSetDiagnosticsModeString());
    cnObject.WithString("VariableDependencyMode",       pOpts->getVariableDependencyModeString());
    cnObject.WithString("ChiralityMode",                pOpts->getChiralityModeString());
    cnObject.WithString("PartialSolvingMode",           pOpts->getPartialSolvingModeString());
    cnObject.WithString("UpdateMode",                   pOpts->getUpdateModeString());
    cnObject.WithString("SolvingMode",                  pOpts->getSolvingModeString());
    cnObject.WithString("ContactsDiagnosticsMode",      pOpts->getContactsDiagnosticsModeString());
    cnObject.WithString("UpdateOutOfClashMode",         pOpts->getUpdateOutOfClashModeString());
    cnObject.WithBool("RereadHelpParameters",           pOpts->getRereadHelpParameters());
    cnObject.WithBool("ForceUsingSketch",               pOpts->getForceUsingSketch());
    cnObject.WithBool("CheckUnsolvableConstraintsMode", pOpts->getCheckUnsolvableConstraintsMode());
    cnObject.WithBool("IncrementalMode",                pOpts->getIncrementalMode());

    sketch_json.WithObject("SolverOptions", cnObject);
}

ECSketchDataSet* ECSketchSerializer::restoreFromJson(Aws::Utils::Json::JsonValue& sketch_json)
{
    ECSketchDataSet* pSketch = new ECSketchDataSet();
    SWX_VERIFY_RETURN(pSketch, "null sketch set\n", NULL);
    
    auto sketch_view = sketch_json.View();

    TRACE_ERR("\t parsing payload data \n")
    try {
        //SketchName
        if (!sketch_view.ValueExists("SketchName"))
            SWX_VERIFY_RETURN(pSketch, "null SketchName\n", NULL);
        std::string skNameStr = sketch_view.GetString("SketchName");
        pSketch->setSketchName(skNameStr);

        //SketchSolveStatus
        SWX_VERIFY_RETURN(sketch_view.ValueExists("SketchSolveStatus"), "null SketchSolveStatus\n", NULL);
        std::string skStatusStr = sketch_view.GetString("SketchSolveStatus");
        pSketch->setSketchSolveStatus(skStatusStr);
        
        //SolverOptions
        /*
            "LinearTolerance": 0.0001,
            "AngularTolerance": 1e-9,
            "DiagnosticsMode": "OldAlways",
            "RigidSetDiagnosticsMode": "WithoutDOS",
            "OverdefinedDiagnosticsMode": "Dimensional",
            "VariableDependencyMode": "Never",
            "ChiralityMode": "Keep",
            "PartialSolvingMode": "Always",
            "UpdateMode": "Evaluate",
            "SolvingMode": "Standard",
            "RereadHelpParameters": true,
            "ForceUsingSketch": false,
            "ContactsDiagnosticsMode": "ClashDetected",
            "CheckUnsolvableConstraintsMode": false,
            "UpdateOutOfClashMode": "None",
            "IncrementalMode": false*/
        ECSkSolverOptions* pOpts =  pSketch->getSketchSolverOptions();
        SWX_VERIFY_RETURN(pOpts, "null SolverOptions\n", NULL);

        SWX_VERIFY_RETURN(sketch_view.ValueExists("SolverOptions"), "null SolverOptions in Json\n", NULL);
        Aws::Utils::Json::JsonView skOptions_view = sketch_view.GetObject("SolverOptions");
        
        double dLinearTol = skOptions_view.GetDouble("LinearTolerance");
        pOpts->setLinearTolerance(dLinearTol);
        
        double dAngularTol = skOptions_view.GetDouble("AngularTolerance");
        pOpts->setAngularTolerance(dAngularTol);

        std::string skDiagnosticsModeStr = skOptions_view.GetString("DiagnosticsMode");
        pOpts->setDiagnosticsMode(skDiagnosticsModeStr);
        
        std::string skRigidDiagnosticsModeStr = skOptions_view.GetString("RigidSetDiagnosticsMode");
        pOpts->setRigidSetDiagnosticsMode(skRigidDiagnosticsModeStr);
        
        std::string skVariableDependencyModeStr = skOptions_view.GetString("VariableDependencyMode");
        pOpts->setVariableDependencyMode(skVariableDependencyModeStr);
        
        std::string skChiralityModeStr = skOptions_view.GetString("ChiralityMode");
        pOpts->setChiralityMode(skChiralityModeStr);
        
        std::string skPartialSolvingModeStr = skOptions_view.GetString("PartialSolvingMode");
        pOpts->setPartialSolvingMode(skPartialSolvingModeStr);
        
        std::string skUpdateModeStr = skOptions_view.GetString("UpdateMode");
        pOpts->setUpdateMode(skUpdateModeStr);
        
        std::string skSolvingModeStr = skOptions_view.GetString("SolvingMode");
        pOpts->setSolvingMode(skSolvingModeStr);
        
        std::string skContactsDiagnosticsModeStr = skOptions_view.GetString("ContactsDiagnosticsMode");
        pOpts->setContactsDiagnosticsMode(skContactsDiagnosticsModeStr);
        
        std::string skUpdateOutOfClashModeStr = skOptions_view.GetString("UpdateOutOfClashMode");
        pOpts->setUpdateOutOfClashMode(skUpdateOutOfClashModeStr);
        
        bool bRereadHelpParameters = skOptions_view.GetBool("RereadHelpParameters");
        pOpts->setRereadHelpParameters(bRereadHelpParameters);
        
        bool bForceUsingSketch = skOptions_view.GetBool("ForceUsingSketch");
        pOpts->setForceUsingSketch(bForceUsingSketch);
        
        bool bCheckUnsolvableConstraintsMode = skOptions_view.GetBool("CheckUnsolvableConstraintsMode");
        pOpts->setCheckUnsolvableConstraintsMode(bCheckUnsolvableConstraintsMode);
        
        bool bIncrementalMode = skOptions_view.GetBool("IncrementalMode");
        pOpts->setIncrementalMode(bIncrementalMode);



        //SketchToWorldTransform
        Aws::Utils::Array< Aws::Utils::Json::JsonView > xform = sketch_view.GetArray("SketchToWorldTransform");
        SWX_VERIFY_RETURN(xform.GetLength()==12, "wrong sketch transform\n", NULL); 
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
        Aws::Utils::Array< Aws::Utils::Json::JsonView > ptArr = sketch_view.GetArray("Points");
        SWX_VERIFY_RETURN(ptArr.GetLength() > 0, "no sketch points defined\n", NULL); 
        for (int idx = 0; idx < (int)ptArr.GetLength(); idx++)
        {
            auto skPt_view = ptArr[idx];
            std::string skPtNameStr = skPt_view.GetString("EntityName");
            
            Aws::Utils::Array< Aws::Utils::Json::JsonView > xyzArr = skPt_view.GetArray("Coordinates");
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
        Aws::Utils::Array< Aws::Utils::Json::JsonView > curveArr = sketch_view.GetArray("Curves");
        SWX_VERIFY_RETURN(curveArr.GetLength() > 0, "no sketch points defined\n", NULL); 
        for (int idx = 0; idx < (int)curveArr.GetLength(); idx++)
        {
            auto skCurve_view = curveArr[idx];
            std::string skCurveNameStr = skCurve_view.GetString("EntityName");
            bool bIsFixed = skCurve_view.GetBool("Fixed");
            svGeometryStatus svStat = bIsFixed ? svFixed : svInvalidGeomStatus;

            std::string skCurveTypeStr = skCurve_view.GetString("EntityType");
            if (skCurveTypeStr == "Line")
            {
                Aws::Utils::Array< Aws::Utils::Json::JsonView > ptArr = skCurve_view.GetArray("LinePoint");
                double x_pt = ptArr[0].AsDouble();
                double y_pt = ptArr[1].AsDouble();
                double z_pt = ptArr[2].AsDouble();

                Aws::Utils::Array< Aws::Utils::Json::JsonView > dirArr = skCurve_view.GetArray("LineDirection");
                double x_dir = dirArr[0].AsDouble();
                double y_dir = dirArr[1].AsDouble();
                double z_dir = dirArr[2].AsDouble();
                
                shared_ptr<ECSketchLine> spln = std::make_shared<ECSketchLine>(x_pt, y_pt, z_pt, x_dir, y_dir, z_dir);
                spln->setName(skCurveNameStr);
                spln->setGeometrySolveStatus(svStat);

                pSketch->addCurve(std::dynamic_pointer_cast<ECSketchCurve>(spln));
            }
            else if (skCurveTypeStr == "LineSegment")
            {
                Aws::Utils::Array< Aws::Utils::Json::JsonView > ptArr = skCurve_view.GetArray("EndPoints");
                std::string pt1Name = ptArr[0].AsString();
                std::string pt2Name = ptArr[1].AsString();
                std::shared_ptr<ECSketchPoint> spPt1 = pSketch->findSketchPoint(pt1Name);
                std::shared_ptr<ECSketchPoint> spPt2 = pSketch->findSketchPoint(pt2Name);

                SWX_VERIFY_RETURN(spPt1 != nullptr && spPt2 != nullptr, "no sketch points found for lineSegment\n", NULL);

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
                std::string startPtNameStr = skCurve_view.GetString("StartPoint");
                std::shared_ptr<ECSketchPoint> spPt2 = pSketch->findSketchPoint(startPtNameStr);
                std::string endPtNameStr = skCurve_view.GetString("EndPoint");
                std::shared_ptr<ECSketchPoint> spPt3 = pSketch->findSketchPoint(endPtNameStr);
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

                Aws::Utils::Array< Aws::Utils::Json::JsonView > xArr = skCurve_view.GetArray("xDir");
                double x_xDir = xArr[0].AsDouble();
                double y_xDir = xArr[1].AsDouble();
                double z_xDir = xArr[2].AsDouble();
                CATMathDirection x_dirIn(x_xDir, y_xDir, z_xDir);

                Aws::Utils::Array< Aws::Utils::Json::JsonView > yArr = skCurve_view.GetArray("yDir");
                double x_yDir = yArr[0].AsDouble();
                double y_yDir = yArr[1].AsDouble();
                double z_yDir = yArr[2].AsDouble();
                CATMathDirection y_dirIn(x_yDir, y_yDir, z_yDir);

                double r1 = skCurve_view.GetDouble("MajorRadius");
                double r2 = skCurve_view.GetDouble("MinorRadius");

                shared_ptr<ECSketchEllipse> spEllipse = std::make_shared<ECSketchEllipse>(spPt1, x_dirIn, y_dirIn, r1, r2);
                spEllipse->setName(skCurveNameStr);
                spEllipse->setGeometrySolveStatus(svStat);

                pSketch->addCurve(spEllipse);
            }
            else
            {
                SWX_VERIFY_RETURN(0, "wrong sketch curve type\n", NULL); 
            }
        }

        //Constraints
        Aws::Utils::Array< Aws::Utils::Json::JsonView > constraintArr = sketch_view.GetArray("Constraints");
        SWX_VERIFY_RETURN(constraintArr.GetLength() > 0, "no sketch points defined\n", NULL); 
        for (int idx = 0; idx < (int)constraintArr.GetLength(); idx++)
        {
            auto constraint_view = constraintArr[idx];

            std::string constraintNameStr = constraint_view.GetString("ConstraintName");
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

                Aws::Utils::Array< Aws::Utils::Json::JsonView > entArr = constraint_view.GetArray("ContraintEntities");
                size_t count = entArr.GetLength();
                std::string ent1Name;
                if (count >= 1) ent1Name = entArr[0].AsString();
                std::string ent2Name;
                if (count >= 2) ent2Name = entArr[1].AsString();
                std::string ent3Name;
                if (count >= 3) ent3Name = entArr[2].AsString();
                std::string ent4Name;
                if (count >= 4) ent4Name = entArr[3].AsString();
                std::shared_ptr<ECSketchEntity> spEnt1 = pSketch->findSketchPoint(ent1Name);
                std::shared_ptr<ECSketchEntity> spEnt2 = pSketch->findSketchPoint(ent2Name);
                std::shared_ptr<ECSketchEntity> spEnt3 = pSketch->findSketchPoint(ent3Name);
                std::shared_ptr<ECSketchEntity> spEnt4 = pSketch->findSketchPoint(ent4Name);
                 
                shared_ptr<ECSketchConstraint> spConstraint = std::make_shared<ECSketchConstraint>(svConstraintType::svParallel, spEnt1, spEnt2, spEnt3, spEnt4);
                spConstraint->setName(constraintNameStr);

                bool didIt = pSketch->addConstraint(spConstraint);
                SWX_VERIFY_CONTINUE(didIt, "Failed to add svParallel constraint. \n");
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

                
                Aws::Utils::Array< Aws::Utils::Json::JsonView > entArr = constraint_view.GetArray("ContraintEntities");
                size_t count = entArr.GetLength();
                std::string ent1Name;
                if (count >= 1) ent1Name = entArr[0].AsString();
                std::string ent2Name;
                if (count >= 2) ent2Name = entArr[1].AsString();
                std::string ent3Name;
                if (count >= 3) ent3Name = entArr[2].AsString();
                std::string ent4Name;
                if (count >= 4) ent4Name = entArr[3].AsString();
                std::shared_ptr<ECSketchEntity> spEnt1 = pSketch->findSketchPoint(ent1Name);
                std::shared_ptr<ECSketchEntity> spEnt2 = pSketch->findSketchPoint(ent2Name);
                std::shared_ptr<ECSketchEntity> spEnt3 = pSketch->findSketchPoint(ent3Name);
                std::shared_ptr<ECSketchEntity> spEnt4 = pSketch->findSketchPoint(ent4Name);
                 
                shared_ptr<ECSketchConstraint> spConstraint = std::make_shared<ECSketchConstraint>(svConstraintType::svOrthogonal, spEnt1, spEnt2, spEnt3, spEnt4);
                spConstraint->setName(constraintNameStr);

                bool didIt = pSketch->addConstraint(spConstraint);
                SWX_VERIFY_CONTINUE(didIt, "Failed to add svOrthogonal constraint. \n");
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

                
                Aws::Utils::Array< Aws::Utils::Json::JsonView > entArr = constraint_view.GetArray("ContraintEntities");
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
                std::shared_ptr<ECSketchEntity> spEnt1 = pSketch->findSketchPoint(ent1Name);
                std::shared_ptr<ECSketchEntity> spEnt2 = pSketch->findSketchPoint(ent2Name);
                std::shared_ptr<ECSketchEntity> spEnt3 = pSketch->findSketchPoint(ent3Name);
                std::shared_ptr<ECSketchEntity> spEnt4 = pSketch->findSketchPoint(ent4Name);
                 
                shared_ptr<ECSketchConstraint> spConstraint = std::make_shared<ECSketchConstraint>(svConstraintType::svDistance, spEnt1, spEnt2, spEnt3, spEnt4, valueIn);
                spConstraint->setName(constraintNameStr);

                bool didIt = pSketch->addConstraint(spConstraint);
                SWX_VERIFY_CONTINUE(didIt, "Failed to add svDistance constraint. \n");
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
       TRACE_ERR("Failed to parse the input sketch JSON. \n")
    };
    return pSketch;
}