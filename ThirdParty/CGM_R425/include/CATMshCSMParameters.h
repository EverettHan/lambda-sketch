#ifndef CATMshCSMParameters_h
#define CATMshCSMParameters_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATMshCSMParameters :
// Object to handle the CSM Parameters
//
//=============================================================================
// January 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================
#include "CATMshCSMCommonExport.h"

#include "CATMshBase.h"
#include "string"

class ExportedByCATMshCSMCommon CATMshCSMParameters : public CATMshBase
{

public:

  CATMshCSMParameters();

  virtual ~CATMshCSMParameters();

  /* Generic options */
  std::string *Mesher;
  int Verbose;
  int Valid;
  int Debug;
  std::string *DebugDirectory;
  int MaxNumberOfThreads;
  std::string *ElementType;

  /* Size control */
  double MeshSize;
  double ChordalError;
  double GeometricApproximationAngle;
  double Gradation;
  double VolumeGradation;
  int GradationIter;
  double MinSize;
  double MaxSize;
  int AnisotropicMeshing;
  double AnisotropicRatio;
  int StructuredBoundaryLayers;
  int SmallEdgeInGradation;
  double SmallEdgeInGradationRatio;
  int LocalPhysical;
  int LocalGeometric;

  int ForceChordalError; 
  int ForceMaxSize;

  std::string *Tags;
  int RespectGeometry;

  int ForceSliverSuppression;
  double SliverEPS;
  int ForceTinyEdgeSuppression;
  double TinyEdgeSuppressionEPS;
  int ForceTinyEdgeOptimisation;
  double TinyEdgeOptimisationEPS;
  int TinyEdgeRespectGeometry;
  int TinyEdgeAvoidIntersection;
  int SplitOverConstrainedElement;
  double OverConstrainedElementAngle;
  int SplitOverConstrainedEdge;

  std::string *OptimisationLevel;
  double QuadrangleEquiangleSkew;
  int AvoidTriangleOnBoundary;
  double QuadrangleOnBoundaryEquiangleSkew;
  double QuadranglePlanarityThreshold;
  int AllowPI;

  /* High Order */
  int ElementOrder;
  int CorrectJacobian;
  int JacobianRespectGeometry;
  int JacobianSplitQuadrangle;
  std::string *JacobianType;
  double JacobianEPS;

  double MeshMatchingEPS;
  double MeshMatchingSplitEPS;

  /* Proximities */
  int VolumeProximityLayers;
  double VolumeProximityRatio;
  int SurfaceProximityLayers;
  double SurfaceProximityRatio;

  int CorrectIntersection;
  double IntersectionCorrectionMaxCost;

  /* Lineic mesher */
  int OptimiseThinStrip;

  int TightUVMode;
  std::string *CADKernel;
  int GenerateRectangleTriangle;
  int PreserveManifold;
  int OptimiseMeshflow;
  double DestructuringCoefficient;
  int UseTessellationForMissingPatch;

  /* CAD preprocessor option */
  int ClosedGeometry;
  int ManifoldGeometry;
  int DiscardInputTopology3D;
  int DiscardInputTopology2D;
  int ProcessTopology3D;
  int ProcessTopology2D;
  double SewingEPS;
  double SewingDiscreteEPS;
  int MergeEdges;
  std::string *DeformationControlLevel;
  int ComputeRidges;
  double RidgeAngle;
  double InputMeshResolutionLength;
  int DiscardInputSliverPatch;
  int ProcessSliverPatchRecognition;
  double SliverPatchEPS;
  double SliverPatchShapeFactor;
  int RemoveDuplicateCADFace;
  std::string *CADPreprocessorGeometryAccuracy;
  int Ignore3DCurveIssue;
  int RemoveTinyUVEdges;
  int InitialiseIDsWithPersistentTags;

  HRESULT SetParameter(std::string iName, double iValue);
  HRESULT SetParameter(std::string iName, int iValue);
  HRESULT SetParameter(std::string iName, std::string iValue);

private:

  HRESULT ReadInBoolLikeParam(int iValue, int *oParam);

};

#endif
