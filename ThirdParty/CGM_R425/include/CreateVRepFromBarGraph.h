#ifndef CreateVRepFromBarGraph_h
#define CreateVRepFromBarGraph_h

#include "ScalarFieldsOperators.h"

// ScalarFields
#include "EnableVRep.h"

// CATFuzzyOperators
#include "CATVRepType.h"

// Mathematics
#include "CATTolerance.h"

//#ifdef ENABLE_VREP_DF

class CATMathBox;
class CATVRepTree;
class CATPolyError;
class LatticeNBModel;
class CATUnicodeString;
class CATSoftwareConfiguration;

class ExportedByScalarFieldsOperators CreateVRepFromBarGraph
{
public:
  CreateVRepFromBarGraph(
	const LatticeNBModel &iInputBarGraph,
	CATSoftwareConfiguration * iSoftwareConfiguration = nullptr,
	const CATTolerance & iTol = CATGetDefaultTolerance());
  ~CreateVRepFromBarGraph();

  HRESULT Run(CATVRepTree *& oVRep);

  void SetSquaredDistance(const int iSquaredDistance);
  void SetWithGradient(const int iSetWithGradient);
  void SetVoxelSize(const double iVoxelSize);

  HRESULT ComputeVoxelSizeFromLatticeNBModel();
  HRESULT ComputeVoxelSizeFromLatticeNBModelAndSag(const double iSag);

  void SetTargetOffset(const double iTargetOffset);
  void SetEnableMultiThread(const int iEnableMultiThread);
  void SetRoundedBorderMode(const int iRoundedBorderMode);
  void SetExtendedBorderMode(const int iExtendedBorderMode);
  void SetIsClientExpectedDepth(const int iIsClientExpectedDepth);
  void SetExpectedDepth(const int iExpectedDepth);

  const double GetVoxelSize() const;
  const CATMathBox & GetVRepBox() const;
  HRESULT GetInputBox(CATMathBox & ioBox) const;

  HRESULT GetVoxelSizeFromExpectedDepth(double & oVoxelSize);
  HRESULT GetExpectedDepthFromVoxelSize(int & oExpectedDepth);
protected:
  //=====================================================================================
  // Internal methods 
  //=====================================================================================


  //==============================================================================
  // Internal attributes
  //==============================================================================
  const LatticeNBModel     & _InputBarGraph;
  int                        _SquaredDistance;
  int                        _WithGradient;
  double                     _VoxelSize;
  double                     _InflateValue;
  int                        _IsClientExpectedDepth;
  int                        _ExpectedDepth;
  double                     _TargetOffset;
  int                        _EnableMultiThread;
  int                        _RoundedBorderMode;
  int                        _ExtendedBorderMode;
  CATVRepType::SmoothingMode _SmoothingMode;
  float                      _SmoothingAmpl;
  const CATTolerance       & _ClientTol;
  CATSoftwareConfiguration * _SoftwareConfiguration;
  CATMathBox *               _VRepBox;
};

//#endif // ENABLE_VREP_DF

#endif
