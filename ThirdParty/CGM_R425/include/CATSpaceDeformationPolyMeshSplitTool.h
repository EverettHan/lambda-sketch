#ifndef CATSpaceDeformationPolyMeshSplitTool_H
#define CATSpaceDeformationPolyMeshSplitTool_H

// COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATSpaceDeformationCldSplitTool.h"
#include "InfraMorph.h"

#include "CATBoolean.h"
#include "CATListOfInt.h"
#include "CATIAV5Level.h"

class CATGeoFactory;
class CATIPolySurface;
class CATSoftwareConfiguration;
class CATBody;
class CATMathSetOfPoints;
class CATMathPoint;
//class CATPolyPointMeshDistanceAccelerator;
//class CATIPolyMeshTriangleIterator;
class CATIPolyMesh;




/**
 * Class defining the cloud definition of the map deformation.
 * This class is used by the @href CATTopSimulation class.
 * It answers to the question : What is morphed ? What is freezed ?
 * <br>
 * Warning : There is not implementation of this class at the Topological Level
 * </ul>
 */

class ExportedByInfraMorph  CATSpaceDeformationPolyMeshSplitTool : public CATSpaceDeformationCldSplitTool
{      
  public:

    

    virtual ~CATSpaceDeformationPolyMeshSplitTool();


  /**
 * Defines the PolySurface to deform.
 * @param  iSurfaceToDeform
 * The pointer to the cloud body to deform
 */
    virtual void SetPolySurface(CATIPolySurface* iSurfaceToDeform)=0;
 
//
///**
// * Defines the configuration.
// * @param iConfig
// * The pointer to the data defining the configuration.
// */
//	virtual void SetSoftwareConfiguration(CATSoftwareConfiguration* iConfig);
//
//

	virtual int SetPointToDeform(const int iNumberOfPoints, const CATMathPoint* iPntToDeform)=0;





protected :

 CATSpaceDeformationPolyMeshSplitTool();
 
};

ExportedByInfraMorph CATSpaceDeformationPolyMeshSplitTool * CATCreateSpaceDeformationPolyMeshSplitTool(CATGeoFactory*	iFactory, const CATBody* iSplitBodyWire, const int iSide);


#endif



