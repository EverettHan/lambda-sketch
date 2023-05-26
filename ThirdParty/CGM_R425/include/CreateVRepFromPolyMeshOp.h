#ifndef CreateVRepFromPolyMeshOp_h
#define CreateVRepFromPolyMeshOp_h

#include "CATBaseUnknown.h"
#include "EnableVRep.h"
#include "ScalarFieldsOperators.h"

#ifdef ENABLE_VREP_DF

class CATPolyError;
class CATIPolyMesh;
class CATVRepTree;
class CATMathBox;
class CATTolerance;
class CATUnicodeString;

class ExportedByScalarFieldsOperators CreateVRepFromPolyMeshOp
{
public:
	CreateVRepFromPolyMeshOp(const CATTolerance & iTol);
	~CreateVRepFromPolyMeshOp();

	CATPolyError * Run(CATVRepTree *& oVRep);

	void SetInputMesh(CATIPolyMesh * iInputMesh);
	void SetSquaredDistance(const int iSquaredDistance);
	void SetWithGradient(const int iSetWithGradient);
	void SetVoxelSize(const double iVoxelSize);
	void SetBothSides(const int iBothSides);
	void SetSetFieldRange(const int iSetFieldRange);
	void SetMinFieldOffset(const double iMinFieldOffset);
	void SetMaxFieldOffset(const double iMaxFieldOffset);
	void SetTargetOffset(const double iTargetOffset);
	void SetEnableMultiThread(const int iEnableMultiThread);
	void SetRoundedBorderMode(const int iRoundedBorderMode);
	void SetExtendedBorderMode(const int iExtendedBorderMode);
	void SetScaleCategory(const CATUnicodeString & iScaleCategory);
	void SetIsClientExpectedDepth(const int iIsClientExpectedDepth);
	void SetExpectedDepth(const int iExpectedDepth);

	const double GetVoxelSize() const;
	const CATMathBox & GetVRepBox() const;
	HRESULT GetInputBox(CATMathBox & ioBox) const;
	HRESULT GetVoxelSizeFromExpectedDepth(double & oVoxelSize);
	HRESULT GetExpectedDepthFromVoxelSize(int & oExpectedDepth);

protected:
	CATIPolyMesh * _PolyMesh;

	// VRep parameters
	int                  _SquaredDistance;
	int                  _WithGradient;
	double               _VoxelSize;
	int                  _IsClientExpectedDepth;
	int                  _ExpectedDepth;
	int                  _BothSides;
	int                  _SetFieldRange;
	double               _MinFieldOffset;
	double               _MaxFieldOffset;
	double               _TargetOffset;
	int                  _EnableMultiThread;
	int                  _RoundedBorderMode;
	int                  _ExtendedBorderMode;
	CATMathBox *         _VRepBox;
	const CATTolerance * _Tol;
};

#endif // ENABLE_VREP_DF

#endif
