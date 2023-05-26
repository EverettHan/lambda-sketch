
#ifndef CATInterpOptimData_H
#define CATInterpOptimData_H
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009
//==========================================================================

#include "MathAdvMarsh.h"

#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATBoolean.h"


class ExportedByMathAdvMarsh CATInterpOptimData
{
public:
	CATInterpOptimData(const int iSize, 
                     const double iTargetRatio,
                     const double iResolution,
                     const double* iPointForAlpha0 = NULL,
                     const double* iPointForAlpha1 = NULL);
	virtual ~CATInterpOptimData();

  int SetTargetRatio(const double iTargetRatio);

  // 0 : alpha = relaxation parameter (default)
  // 1 : alpha = smoothing parameter.
  void SetModeEvaluation(const int iMode) {_ModeEvaluation = iMode;}

	// Reglage des parametres de l'algo
	int AddInfo(const double iAlpha, 	const double iRatio,	
              const double * iRefPoints, const int iCountK0, 
              const double iEnergy, const double iDelta=0.0);	

  int GetInfo(const int iIndex, double& oAlpha, double& oRatio, int& oCountKO) const;
  double GetEnergy(const int iIndex) const ;
  const double * GetOptimizedPoints()const;

  double GetDelta(const int iIndex) const;

  double GetRatioTarget() const {return _TargetRatio;}

  int GetIndexSolution() const {return _OptimalIndex;}

  int GetModeEvaluation()const {return _ModeEvaluation;}

  int NbRecords() const;

  // rend les points pour alpha donne, 
  // NE PAS DETRUIRE oPoints
  int GetPointsForAlpha(const double iAlpha, const double *& oPoints);

  int SetParabolic();

  // Authorise a garder une solution pour ratio dans [ refRatio-iMargeRatio, refRatio+iMargeRatio]
  // suivant l'energie.
  int SetRefRatio(const double iRefRatio, const double iMargeRatio);

  // Ne garde une solution que si l'energie s'ameliore (sauf si cela devient valide!)
  int SetChkEnergy();

  void Dump();

private:
	// Data
  CATListOfDouble _AlphaTab;
  CATListOfDouble _RatioTab;
  CATListOfDouble _EnergyTab;
  CATListOfDouble _DeltaTab;
  CATListOfInt    _CountKOTab;
  double*         _OptimizedPoint;
  const double*   _PointForAlpha0;
  const double*   _PointForAlpha1;
  double*         _ExposantForAlpha;
  double*         _Point_Alpha;
  double          _OptimizedRatio;
  double          _OptimizedEnergy;
  double          _TargetRatio;
  double          _RefRatio;
  double          _MargeRatio;
  double          _Resolution;
  int             _Size;
  int             _OptimalIndex;
  int             _ModeEvaluation;
  CATBoolean      _IsValid;
  CATBoolean      _IsOptimizedRatio; //indique que le ratio est optimise => Ne plus tenir compte de la reeference.
  CATBoolean      _ChkEnergy;
};
	
#endif


