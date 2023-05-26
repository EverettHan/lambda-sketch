#ifndef CreateMidSurfaceFromScalarField_h
#define CreateMidSurfaceFromScalarField_h

#include "ScalarFields.h"

#include "CATBoolean.h"
#include "CATTolerance.h"
#include "CATSysErrorDef.h"

class CATVRepTree;
class CATIPolyMesh;
class CATCGMProgressBar;
class CATSoftwareConfiguration;

class ExportedByScalarFields CreateMidSurfaceFromScalarField
{
public:  
  /* 
  =============================================================================
  **  @param iSoftwareConfiguration
        The software configuration to respect versioning(always the more recent version if NULL)
  **  @param iInputScalarField
        The input scalarField from which the VRep is filled with, stored into an array.
        Its size must be egal to dimX*dimY*dimZ (iDimField[0]*iDimField[1]*iDimField[2]). 
        iScalarField[0] = (x0, y0, z0), iScalarField[1] = (x1, y0, z0) ... iScalarField[dimX] = (x0, y1, z0) ... iScalarField[dimY * dimX] = (x0, y0, z1)
  **  @param iInputGradientField
        The input gradientField from which the VRep is filled with, stored into an array.
        Its size must be egal to 3*dimX*dimY*dimZ (three scalars for each node).
  **  @param iDimField
        The dimension (number of elements) of the scalar field according to each direction (x, y, z).
  **  @param iOrigin
        The position in space of the first point of the scalar field.
  **  @param iStepBetweenScalar
        The step in space between each value in the scalar field. MUST be the same in all direction.
  **  @param oResultMesh
        The result mesh. This should be an empty mesh that will be filled in
        during computation of the offset.
  **  @param iTol
        The Tolerance is required in order to declare the scale of the global scene and to be consistent 
		with the offset mesh result.
  ==============================================================================
  */
  CreateMidSurfaceFromScalarField(
	CATIPolyMesh & oResultMesh,
	CATSoftwareConfiguration * iSoftwareConfiguration,
	float * iInputScalarField,
	float * iInputGradientField,
	const int iDimField[3],
	const double iOrigin[3],
	double iStepBetweenScalar,
	double iIsoValue,
	double iScalarFieldOffset,
	const CATTolerance & iTol = CATGetDefaultTolerance());
  ~CreateMidSurfaceFromScalarField();

  HRESULT Run();

private:
  /*
  ** Run sub-methods
  */
  // Build a VRep and fill it with the scalar field
  HRESULT BuildAndFillVRep(HRESULT & ioRunCB_OK);
  // From the input, compute the VRep size and depth
  // Also initialize all the data about the VRep (margin, vxlSize...)
  HRESULT ComputeVRepSizeAndDepth();
  // Get a scalar from its position in the 3D field (x, y, z)
  HRESULT GetScalarAndGradientFromXYZ(
	float & oScalar, 
	double * oGradient, 
	int * iXYZ);
  // Get a scalar from its position in the VRep
  // Return S_FALSE if this position is not in the ScalarField
  // (it is then in the margin around the scalarField)
  HRESULT GetScalarAndGradientFromIJK(
	float & oScalar,
	double * oGradient,
	unsigned int *iIJK);
  // For now : DUMB incrementation !
  // Increment accordingly to the scalarField, not accordingly to the VRep !
  HRESULT IncrementIJK(unsigned int &ioI, unsigned int &ioJ, unsigned int &ioK);
  // Update progress (if a CallBack was set)
  HRESULT UpdateProgress(const double iProgress);
  // Perform medial axis
  HRESULT GenerateMedialAxis();

private:
  /*
  ** Private attributes
  */
  CATIPolyMesh &              _ResultMesh;

  double                      _IsoValue;

  const CATTolerance &        _ClientTol;
  CATSoftwareConfiguration *  _SoftwareConfiguration;

  CATCGMProgressBar *         _Callback;

  float *                     _InputScalarField;
  float *                     _InputGradientField;
  int                         _FieldDim[3];
  double                      _Origin[3];
  double                      _StepBetweenScalar;
  double                      _SFOffset;

  CATBoolean                  _IsMinSet;
  CATBoolean                  _IsMaxSet;
  double                      _MinBound;
  double                      _MaxBound;

  int                         _FuzErrorCode;

  // Vrep x_min, x_max, y_min, y_max, z_min, z_max
  double                      _VRepDim[6];
  int                         _VRepDepth;

  // Sized of a voxel in the VRepTree (power of two)
  unsigned int                _VxlSize;

  // Give the first and last voxels with values in the field, but in VRep coordinates
  unsigned int                _FieldPosInVRepSpace[6];

  int                         _NbScalar;

  CATVRepTree *               _VRep;
};

#endif
