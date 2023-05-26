#ifndef SAGRemeshing_H
#define SAGRemeshing_H

#include "CATErrorDef.h" // HRESULT
#include "TessImpl.h"    // Exported by

// Mathematics
#include "CATMathVector.h"

// STD
#include <map>
#include <vector>
#include <set>

class CATMathPoint;
class CATSurParam;
class CATMathDirection;
class CATTessBarre;
class CATTessContour;
class CATTessFace;
class CATTessAssCont;
class CATTessPoint;
class CATICGMDistanceMinPtSur;
class CATPolyDualMeshBuilderHelper;
class RemeshingParam;

class SAGRemeshingData
{
public:
	/*
	** Reconciliation data
	*/
	class ReconcileData
	{
	public:
		/*
		** Setters
		*/
		void Reset();
		void SetReconcile(CATBoolean iReconcile);
		void SetBarre1(CATTessBarre * iBr);
		void SetBarre2(CATTessBarre * iBr);

		/*
		** Getters
		*/
		CATBoolean Reconcile() const;
		CATTessBarre * GetBarre1() const;
		CATTessBarre * GetBarre2() const;

	private:
		CATBoolean _reconcile;
		CATTessBarre * _barre1;
		CATTessBarre * _barre2;
	};

	/*
	** Getters
	*/
	CATBoolean IsBreakable() const;
	CATTessBarre * GetBarre() const;
	const double GetDistance() const;
	CATTessContour * GetContour() const;
	const ReconcileData & GetReconcileData() const;
	// Point data
	double * GetPoint_UVCoords();
	double * GetPoint_XYZCoords();
	CATMathVector & GetPoint_Normal();
	const double * GetPoint_UVCoords() const;
	const double * GetPoint_XYZCoords() const;
	const CATMathVector & GetPoint_Normal() const;

	/*
	** Setters
	*/
	void Reset();
	void Set(
		const double iDistance,
		CATTessBarre * iBr,
		CATTessContour * iContour);
	void Set(
		const double iDistance,
		const CATMathPoint & iPtXyz,
		const CATSurParam & iPtSurParam,
		const CATMathDirection & iPtNormalDir,
		CATTessBarre * iBr,
		CATTessContour * iContour);
	void SetBarre(CATTessBarre * iBr);
	void SetReconcileData(
		CATTessBarre * iResBr1, 
		CATTessBarre * iResBr2);
	void SetReconcileData(
		const CATBoolean iReconcile,
		CATTessBarre * iResBr1,
		CATTessBarre * iResBr2);

private:
	ReconcileData    _recData; // Activate reconcile twin broken barres
	CATBoolean       _breakable;
	double           _distance;
	double           _ptUv[2];
	double           _ptXyz[3];
	CATMathVector    _ptNormal;
	CATTessBarre *   _barre;
	CATTessContour * _contour;
};

class SAGRemeshing
{
public:
	/*
	** Typedefs
	*/
	using ContoursSet = std::set<CATTessContour*>;

	/*
	** Constructor(s) & destructor
	*/
	SAGRemeshing(
		CATTessFace * iFace,
		const double iSAG,
		const CATLONG32 & iNbMaxCont,
		const double iSpaceConfusionTol);
	~SAGRemeshing();

	/*
	** Main methods
	*/
	HRESULT Init(CATTessFace * iFace);
	HRESULT Run();
	HRESULT RunSingleDepth(
		CATLONG32 & ioNbCont,
		CATTessAssCont * ioAssContTrian,
		ContoursSet & oNewContours,
		const ContoursSet & iContoursToProcess);
	// Projection
	HRESULT ComputeDistancePtEdge(
		SAGRemeshingData & ioData,
		double & oDistance,
		double iPtXyz[3],
		CATTessBarre * iBr);
	HRESULT ComputeDistancePtSur(
		SAGRemeshingData & ioData,
		double & oDistance,
		double iPtXyz[3],
		CATTessBarre * iBr,
		CATTessContour * iCt);

	static ExportedByTessImpl RemeshingParam * _param; // owned
	static ExportedByTessImpl CATPolyDualMeshBuilderHelper * _helper; // owned

protected:
	/*
	** Typedefs
	*/
	using VisitedBarresMap = std::map<CATTessBarre *, SAGRemeshingData>;
	using VisitedBarresIterator = std::map<CATTessBarre *, SAGRemeshingData>::iterator;
	using VisitedBarresConstIterator = std::map<CATTessBarre *, SAGRemeshingData>::const_iterator;

	/*
	** Run sub-routines
	*/
	// Main
	HRESULT RunOnContour(
		SAGRemeshingData(&ioData)[4],
		CATTessContour * & iCt);
	HRESULT RunOnBarre(
		SAGRemeshingData & ioData,
		double & oDistance,
		CATTessBarre * iBr,
		const double(&iXyz1)[3],
		const double(&iXyz2)[3]);
	HRESULT ProcessRemeshingData(
		ContoursSet & oNewContours,
		CATTessContour * & ioCt,
		CATTessAssCont * ioAssConTrian,
		SAGRemeshingData(&iData)[4]);
	HRESULT UpdateRemeshingData(
		SAGRemeshingData & ioData,
		const double iDistance,
		CATTessBarre * iBr,
		CATTessContour * iCt);
	HRESULT UpdateVisitedBarresMap(
		SAGRemeshingData(&iData)[4]);
	HRESULT ReconcileTwinBrokenBarres(
		CATTessBarre * iBr1, 
		CATTessBarre * iBr2,
		CATTessBarre * iBrJum1,
		CATTessBarre * iBrJum2);
	HRESULT ReconcileTwinBrokenBarres(
		CATTessBarre * iBr1,
		CATTessBarre * iBr2);
	HRESULT RemeshContour(
		ContoursSet & oNewContours,
		CATTessAssCont * ioAssContTrian,
		CATTessContour * iCt,
		SAGRemeshingData(&iData)[4]);
	HRESULT RemeshContour_BreakOnlyOneBarre(
		ContoursSet & oNewContours,
		CATTessAssCont * ioAssContTrian,
		CATTessContour * iCt,
		SAGRemeshingData(&iData)[4]);
	HRESULT RemeshContour_BreakOnlyTwoBarres(
		ContoursSet & oNewContours,
		CATTessAssCont * ioAssContTrian,
		CATTessContour * iCt,
		SAGRemeshingData(&iData)[4]);
	HRESULT RemeshContour_BreakAllBarres(
		ContoursSet & oNewContours,
		CATTessAssCont * ioAssContTrian,
		CATTessContour * iCt,
		SAGRemeshingData(&iData)[4]);
	// Element modification
	// NB : BreakBarreByPoint doesn't propagate to neighboring faces now
	// NB2 : Read function comment in src to understand output state of the contour
	HRESULT BreakBarreByPoint(
		SAGRemeshingData & ioRemeshingData,
		CATTessPoint * iPt,
		CATTessBarre * iBr);
	HRESULT BreakContourByPoint(
		ContoursSet & oNewContours,
		CATTessPoint * iPt,
		CATTessContour * iCt,
		CATTessAssCont * iAssContTrian);
	// Element creation
	CATTessPoint * GetPointToBreakBarre(
		SAGRemeshingData & iData);
	CATTessPoint * GetPointToBreakContour(
		SAGRemeshingData & iData);
	CATTessPoint * CreatePoint(
		double * iPtXyz,
		double iPtSurParam[2],
		CATMathVector & iPtNormal);
	CATTessBarre * CreateBarre(
		CATTessPoint * iTessPt0,
		CATTessPoint * iTessPt1,
		CATTessBarre * iBrJum,
		const CATBoolean iUpdateBarreJum = TRUE);
	CATTessContour * CreateContour(
		CATTessAssCont * iAssContTrian);
	CATTessContour * CreateContour(
		CATTessContour * iContourPrec,
		CATTessAssCont * iAssContTrian);
	// Element update
	void UpdateBarre(
		CATTessBarre * ioBr,
		CATTessPoint * iPt0,
		CATTessPoint * iPt1,
		const CATBoolean iUpdateBarreJum = TRUE);
	void UpdateContour(
		CATTessContour * ioContour,
		CATTessBarre * iBr0,
		CATTessBarre * iBr1,
		CATTessBarre * iBr2);
	// Others
	HRESULT ConstructContoursSet(
		ContoursSet & oContours,
		CATTessAssCont * iAssContTrian);
	const unsigned int IsIsoBarre(const CATTessBarre * iBr) const;
	const unsigned int IsEdgeBarre(const CATTessBarre * iBr) const;
	const CATBoolean IgnoreBarre(const CATTessBarre * iBr) const;
	const CATBoolean isCandidateForBreaking(
		const double iDistance, 
		const CATBoolean iSquared = FALSE) const;
	void UpdateReconciliationData(
		SAGRemeshingData & ioData, 
		CATTessBarre * iResBr1, 
		CATTessBarre * iResBr2);

	/*
	** Attributes
	*/
	double _sag;
	unsigned int _depth;
	double _spaceConfusionTol;
	const CATLONG32 & _nbMaxCont;
	CATTessFace * _face; // Not owned
	CATICGMDistanceMinPtSur * _distanceMinPtSurOperator; // owned
	VisitedBarresMap _visitedBarres;
};
#endif
