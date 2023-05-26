//===================================================================
// CATGeomVisuTessSetting.h
//===================================================================

#ifndef CATGeomVisuTessSetting_H
#define CATGeomVisuTessSetting_H

#include "SGInfra.h"
#include "CATSysDataType.h"
#include "CATSysBoolean.h"

//-----------------------------------------------------------------------
#define OVERRIDE_SAG3D                          0x01  // 0000 0000 0001
#define OVERRIDE_SAG2D                          0x02  // 0000 0000 0010
#define OVERRIDE_SAG                            0x03  // 0000 0000 0011
#define OVERRIDE_REGULARIZATIONFLAGS            0x04  // 0000 0000 0100
#define OVERRIDE_USETESSCACHE                   0x08  // 0000 0000 1000
#define OVERRIDE_CURVESAG                       0x10  // 0000 0001 0000
#define OVERRIDE_SAGMODE2D                      0x20  // 0000 0010 0000
#define OVERRIDE_SAGMODE3D                      0x40  // 0000 0100 0000
#define OVERRIDE_SAGMODE                        0x60  // 0000 0110 0000
#define OVERRIDE_MESHTYPE                       0x80  // 0000 1000 0000 // triangles, or tri.fan.strips
#define OVERRIDE_USEPERSISTENTVERTEXCACHE       0x100 // 0001 0000 0000
#define OVERRIDE_ADAPTIVEQUALITYTESSELLATION    0x200 // 0010 0000 0000
#define OVERRIDE_EDGEHIGHCURVATURSTEPTHRESHOLD  0x300 // 0100 0000 0000

#define OVERRIDE_EVERYTHING                     0xFFF // 1111 1111 1111
//-----------------------------------------------------------------------

/** Accuracy ( = SAG ) mode
	* @param ProportionalSAG : An object will be tessellated based upon the given accuracy AND its bounding element size.
	* @param FixedSAG : An object will be tessellated based upon the given accuracy only.
	* @param AutoAdaptiveSAG : An object will be tessellated based upon an accuracy resulting from autonomous computation (parameters are : 0.2 base-value, bounding element size, model range, local curvature). Only available for 3D.
	* @param AutoAdaptiveCoarseSAG : An object will be tessellated based upon twice the AutoAdaptive accuracy. Only available for 3D.
	*/
enum SAGMode
{
	ProportionalSAG = 0,
	FixedSAG = 1,
	AutoAdaptiveSAG = 2,			// Only 3D
	AutoAdaptiveCoarseSAG = 3	// Only 3D
};

/** Mesh type
	* @param TrianglesStripsFans : Mesh will be generated using strip and fans triangle patterns
	* @param TrianglesOnly : Mesh will be generated using only singe triangle pattern
	*/
enum MeshType
{
	TrianglesStripsFans = 0,
	TrianglesOnly = 1	
};


/** Base class to provide or override settings for the tessellation services
	* 
	* You might end up here if you want to :
	* 1. GET tessellation settings either coming from override or CATSettings
	* WARNING : in this situation, please use more generic CATGeomVisuTessParamAccess class
	* 2. SET tessellation settings in order to override CATSettings
	* WARNING : in this situation, you need to master what you are doing as your override might impact the whole session.  Contact a SceneGraph team member if needed.
	*/
class ExportedBySGInfra CATGeomVisuTessSetting
{
public:

	CATGeomVisuTessSetting();
	~CATGeomVisuTessSetting();

	double		Get2DSag() const;
	double		Get3DSag() const;
	SAGMode		GetSagMode2D() const;
	SAGMode		GetSagMode3D() const;
	double		GetCurveSag() const;

	void  Get3DSagInformations(SAGMode& _sagmode, double& _sagvalue, double& _curvevalue) const;
	void  Get2DSagInformations(SAGMode& _sagmode, double& _sagvalue) const;
	// in AA and AAcoarse modes, given sagvalue and curvevalue are useless as these modes work with their own self-computed sag and curve ratio is hard coded to 1.0
	void  Set3DSagInformations(SAGMode sagmode, double sagvalue, double curvevalue);
	// AA and AAcoarse modes are forbidden for 2DSag
	void  Set2DSagInformations(SAGMode sagmode, double sagvalue);

	MeshType		GetMeshType() const;
	void				SetMeshType(MeshType p_Type);

	CATULONG32	GetRegularizationFlag() const;
	void				SetRegularizationFlag(CATULONG32 iFlag);

	CATULONG32	GetMaxTrianglesThreshold() const;

	CATBoolean	GetUseTessellationCache() const;
	void				SetUseTessellationCache(CATBoolean iUse);

  CATBoolean	GetUsePersistentVertexCache() const;
	void				SetUsePersistentVertexCache(CATBoolean iUse);

	CATBoolean	GetAdaptiveQualityTessellation() const;
	void				SetAdaptiveQualityTessellation(CATBoolean iAdaptiveQualityTessellation);

	void GetEdgeHighCurvatureStepInformations(CATBoolean& oActivated, double& oThreshold) const;
	void SetEdgeHighCurvatureStepInformations(CATBoolean iActivated, double iThreshold);

	CATBoolean	AreDecorationsRequested() const;
	void				RequestDecorations(CATBoolean iRequest);

	CATULONG32  GetRepColor() const;
	void				SetRepColor(CATULONG32 iARGB);

	// WARNING : to be called with extreme precaution
	static void SetOverridingSettings(CATGeomVisuTessSetting* iSettings, CATULONG32 iOverridingFlags = OVERRIDE_SAGMODE | OVERRIDE_SAG | OVERRIDE_CURVESAG);

	static CATGeomVisuTessSetting* GetOverridingSettings(CATULONG32* oOverridingFlags = 0);

	// static methods that will call their CATSetting counterpart, but after checking if the setting was overriden.
	static CATULONG32		CATGet3DAccuracyMode();
	static double				CATGet3DFixedAccuracy();
	static double				CATGet3DProportionnalAccuracy();
	static CATULONG32		CATGet2DAccuracyMode();
	static double				CATGet2DFixedAccuracy();
	static double				CATGet2DProportionnalAccuracy();
	static double				CATGet3DCurveAccuracy();
	static CATULONG32		CATGetOptimizedMeshMode();
	static CATULONG32		CATGetMaxTrianglesThreshold();
	static CATBoolean		CATGetEdgeHighCurvatureStepThresholdActivated();
	static double				CATGetEdgeHighCurvatureStepThreshold();
	static CATBoolean		CATGetAdaptiveQualityTessellation();

private:
  CATBoolean    _UseTessellationCache;
  CATBoolean    _UsePersistentVertexCache;
  CATBoolean    _AdaptiveQualityTessellation;

  double        _3DSag;
  double        _2DSag;
  SAGMode       _SagMode2D;
  SAGMode       _SagMode3D;
  double        _CurveSag;
  CATULONG32    _RegularizationFlag;
  CATULONG32    _MaxTrianglesThreshold;
  CATULONG32    _RepColor;
  MeshType      _MeshType;
  CATBoolean		_AddDecorations;
	CATBoolean		_EdgeHighCurvatureStepThresholdActivated;
	double				_EdgeHighCurvatureStepThreshold;

	// static member: not great. However, no other way to pass settings to the BuildRep	
	static CATGeomVisuTessSetting*	g_OverridingSettings;
	static CATULONG32								g_OverridingFlag;
};

#endif
