#ifndef CreateMidSurfaceFromInputMesh_h
#define CreateMidSurfaceFromInputMesh_h

#include "ScalarFields.h"

#include "CATBoolean.h"
#include "CATTolerance.h"
#include "CATSysErrorDef.h"

class CATMathBox;
class CATVRepTree;
class CATIPolyMesh;
class CATCGMProgressBar;
class CATSoftwareConfiguration;

class ExportedByScalarFields CreateMidSurfaceFromPolyMesh
{
public:  
  /* 
  =============================================================================
  **  @param iSoftwareConfiguration
        The software configuration to respect versioning(always the more recent version if NULL)
  **  @param oResultMesh
        The result mesh. This should be an empty mesh that will be filled in
        during computation of the offset.
  **  @param iTol
        The Tolerance is required in order to declare the scale of the global scene and to be consistent 
		with the offset mesh result.
  ==============================================================================
  */
  CreateMidSurfaceFromPolyMesh(
	CATIPolyMesh & oResultMesh,
	CATSoftwareConfiguration * iSoftwareConfiguration,
	const CATIPolyMesh & iInputMesh,
	const double iIsoValue,
	const double iVoxelSize,
	const CATTolerance & iTol = CATGetDefaultTolerance());
  ~CreateMidSurfaceFromPolyMesh();

  HRESULT Run();

private:
  /*
  ** Run sub-methods
  */
  // Update progress (if a CallBack was set)
  HRESULT UpdateProgress(const double iProgress);
  HRESULT GetInputBox(CATMathBox & ioBox) const;
  HRESULT GetIsoValueFromVoxelSize();
  HRESULT GetVoxelSizeFromExpectedDepth();

private:
  /*
  ** Private attributes
  */
  CATIPolyMesh &              _ResultMesh;
  const CATIPolyMesh &        _InputMesh;

  const CATTolerance &        _ClientTol;
  CATSoftwareConfiguration *  _SoftwareConfiguration;

  CATCGMProgressBar *         _Callback;

  double                      _IsoValue;
  double                      _VoxelSize;
  double                      _TargetOffset;
  int                         _ExpectedDepth;
  int                         _ErosionExtendedBorderMode;

  int                         _FuzErrorCode;
};

#endif
