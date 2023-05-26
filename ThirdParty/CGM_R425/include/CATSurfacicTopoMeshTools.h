// --------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011 
//==========================================================================
//
//    CATSurfacicTopoMeshTools       
//
//==========================================================================
// Aug 2011 KTU : Creation 
//==========================================================================

#ifndef CATSurfacicTopoMeshTools_h
#define CATSurfacicTopoMeshTools_h

#include "CATSurfacicTopoOperators.h"

#include "CATTopDefine.h"
#include "CATMathVector.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATListOfInt.h"
#include "CATMathLimits.h"
#include "CATBoolean.h"


//class CATPolyMeshDistance;
//class CATTessPolyMeshVertexAttributeLayer;
class CATGeoFactory;
class CATBody;
class CATTessPolyMeshVertexUV;
class CATIPolyMesh;
class CATIPolyFactory;
class CATCldPolygon;
class CATMathStream;
class CATSoftwareConfiguration;
class CATMathSetOfPoints;
class CATMathPlane;


class ExportedByCATSurfacicTopoOperators CATSurfacicTopoMeshTools
{
public:
	
	
	////-----------------------------------------------------------------------------------------------------------------------
	//// Function:CreateEmpyPolyMesh..
	//// Purpose : creates an empty cat polymesh 
	////          if the input is not null,  it will be deleted. So be carrefull.
	//// can be transferred to tools file. very independant.
	////-----------------------------------------------------------------------------------------------------------------------
	//static int CreateEmptyPolyMesh(CATIPolyFactory* ipPolyContainer, CATIPolyMesh *&oPolyMesh);

	////-----------------------------------------------------------------------------------------------------------------------
	//// TesselateBody..
	////-----------------------------------------------------------------------------------------------------------------------
	//static int TesselateBody(CATIPolyFactory* ipPolyContainer,  CATSoftwareConfiguration *ipConfig
	//	,CATBody *ipBodyToTesselate, const CATTessSettings & iTessSetting
	//	,CATIPolyMesh *&oPolyMesh , const CATLONG32 iVertexInfo=0, CATTessPolyMeshVertexAttributeLayer* opVertexAttributeLayer=NULL
	//	);

  //-----------------------------------------------------------------------------------------------------------------------
	// GetVertexNormal
	//-----------------------------------------------------------------------------------------------------------------------
  static int GetVertexNormal( CATTessPolyMeshVertexUV * pVtxContext, CATOrientation iOrientationFaceBody , CATMathVector &oNormal, CATBoolean &oIsDegenerated );

  //-----------------------------------------------------------------------------------------------------------------------
	// GetVertexNormal
	//-----------------------------------------------------------------------------------------------------------------------
  static CATCldPolygon * CreateCldPolygon( CATGeoFactory * iFactory,  CATIPolyMesh * iPolyMesh );

  static double SquareMaxEdgeTriangle(CATMathPoint& iP1, CATMathPoint& iP2, CATMathPoint& iP3);

  static int Discretize(CATBody * iB, 
                        CATLISTV(CATMathPoint)& ioDiscretizedPoints,
                        const float iSag, 
                        const float iStep = (float) CATMathInfinite);
	
  static CATIPolyMesh * Meshing3D(CATLISTV(CATMathPoint)& iCloudPoints, 
                        const double iCharactDist, CATListOfInt* ioMapIndexes=0/*, const int iIdxMin=0*/);
  static int AppendMesh(CATIPolyMesh * ioMesh, const CATIPolyMesh * iMeshToAppend);

  static int CleanMesh(CATIPolyMesh * ioMesh);

  static int AutoStich(CATIPolyMesh * ioPolyMesh,  const double iCharactDist, const int iMaxIdxFirstPart=0);

  static int FlagBoundVtx(CATIPolyMesh *ipPolyMesh , CATBoolean *&opIsBound, int &oNbBound);


  //----------------------------------------------------------------------------------------------------------------------------------------------------
  //WritePolyMesh
  //----------------------------------------------------------------------------------------------------------------------------------------------------
  static int WritePolyMesh(CATMathStream  & ioWriteStream, CATIPolyMesh*ipMesh, const unsigned int LayerFilter);
  //----------------------------------------------------------------------------------------------------------------------------------------------------
  // ReadPolyMEsh 
  //----------------------------------------------------------------------------------------------------------------------------------------------------
  static int ReadPolyMesh(CATMathStream  & iReadStream, const unsigned int LayerFilter, CATIPolyMesh*&opMesh);
   //----------------------------------------------------------------------------------------------------------------------------------------------------
  // ReadPolyMEsh 
  //----------------------------------------------------------------------------------------------------------------------------------------------------
  static int GetOrienMeshVsShell(CATSoftwareConfiguration* ipConfig,  CATIPolyMesh* ipMesh, CATBody* ipBodypShell, short & oOrien  );
  //-----------------------------------------------------------------------------------------------------------------------
  // Function RetrieveMeshPoints
  // Purpose:  Retrievall of  active  vertices.
  //------------------------------------------------------------------------------------------------------------------------
  static int RetrieveMeshPoints(CATIPolyMesh*ipPolyMesh, CATMathSetOfPoints *&opSetOfPoints );
  //-----------------------------------------------------------------------------------------------------------------------
  // Function ComputeMeanPlanar
  // Purpose: Compute inertia plane of the  mesh ans  minimize  the UVBox 
  //------------------------------------------------------------------------------------------------------------------------
  static int ComputeMeanPlanar(CATIPolyMesh*ipPolyMesh, const CATTolerance &iTolerance, CATMathPlane *&opPlane, double oUVBox[4] );

  //----------------------------------------------------------------------------------------------------------------------------------------------------
  // Function : CheckTopologyIdentity	
  // Purpose :  Check if the 2 meshes have the same topology
  //----------------------------------------------------------------------------------------------------------------------------------------------------
  static int CheckTopologyIdentity(CATIPolyMesh* ipMesh0, CATIPolyMesh* ipMesh1)  ;
  //-----------------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------------------------------------------
  // Function : GeSquareTololeranceForGeometryCheck	
  // Purpose : returns the  square tolerance according to  the given relative  tolerance (the relative is in order 2)
  //----------------------------------------------------------------------------------------------------------------------------------------------------
  static int GeSquareToleranceForGeometryCheck(CATIPolyMesh *ipMesh, const double  iRelativeTol, double  &oSquareTolerance) ;

  //----------------------------------------------------------------------------------------------------------------------------------------------------
  // Function : GeSquareTololeranceForGeometryCheck	
  // Purpose :  Max deviation between 2 meshes
  //----------------------------------------------------------------------------------------------------------------------------------------------------
  static int MaxSquareGeometryDeviation(CATIPolyMesh *ipMesh0, CATIPolyMesh *ipMesh1, double  &oMaxSquareDeviation)  ;


private:
    static int ExtractBorder(CATIPolyMesh * ioPolyMesh,  CATListOfInt& oVerticesOfMesh);
   
};

#endif
