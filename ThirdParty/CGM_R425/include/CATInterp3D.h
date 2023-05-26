#ifndef CATInterp3D_H
#define CATInterp3D_H

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002-2005
//
/**
* @level Private
* @usage U2
*/

#include "MathAdvMarsh.h"

#include "CATInterpND.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATBoolean.h"
#include "CATTolerance.h"
#include "CATMathPoint.h"
#include "CATLISTV_CATMathPoint.h"

class CATInterp3DBox;
class CATInterp3DBoxHashTable;
class CATMarshPixellisation;

//#define DEBUG_MODE

//#define Test_Concatenation



/**
* Base Class to approximate a set of 3D vector with use of an interpolate algorithm
*
* <br><b>Role</b>: Tools to fit 3d fields

* @href CATInterpND
*/

class ExportedByMathAdvMarsh CATInterp3D: public CATInterpND
{
public:
	CATInterp3D( const CATTolerance & iTol, const double iPercentMin = 100.);
	virtual ~CATInterp3D();

	//Fonction principale du raffinement
	/*param iMoveMode
		-  0 : Decompte des points a deplacer
		-  1 : Keep + Raffinement "local"
		-  2 : Only Keep
	* code retour :
		- 0 -> Tout est OK, le travail est fini (éventuellement remettre les points _Index.. de 4 à 1)
		- 1 -> Il faut continuer le travail
		- -1 -> Aucun point à insérer ni à perturber, c'est fini.
	  - -2 -> Il faut perturber les points car on ne peut plus en insérer
		- -3 -> Aucun point à insérer ni à perturber, MAIS CE N'EST PAS FINI !!
    **** ATTENTION ****  En mode perturbation ces infos ne sont pas toujoures rendues mieux vaut utiliser oSummary!

    oSummary[0] : %de point OK
		oSummary[1] : Norme de JJ (Moindre puissance p)
		oSummary[2] =  ErrMax;		
		oSummary[3] = NbPointsToInsert;	
		oSummary[4] = NbPointsToMove;
	*/
	int TestAndRefine(int iStep, double* oSumary=NULL, 
		                const CATBoolean iUpdateFilter = FALSE,
										const short iMoveMode= 0);

  //
	void SetInterpolationMode(const CATBoolean isInterpolationOnly) {_InterpolationOnly = isInterpolationOnly;}

	//Calcul des moindres carrés
	virtual int LeastSquareDelta() = 0;


	double GetJValue() const {return _JJ;}  //Avant Projection!


	int GetInsertSize(const int iMode = 0) const;

  int Discretize( CATLISTV(CATMathPoint)& ioDiscretizePnt) const;

  CATBoolean IsMaxStep() const;

#ifdef Test_Concatenation
  // Gestion d'une sequence de concatenation des Points en erreur 
  int StartConcatenation(CATBoolean iFlush=TRUE);
  int StopConcatenation(CATBoolean iFlush=TRUE);
  int AppendConcatenationInInsertPoint();
#endif

#ifdef CATInterp3D_Complete
	// Valide l'operation precedente
	virtual int Validate();

	double GetRelativeSize() const {return _RelativeFraction;};


#endif
  
#ifdef DEBUG_MODE
  	//decompte du voisinage
  int AnalyseConnexity(const double iAnalyseTol, int& oNbMin, int& oNbMax, double& oNbMoy) const;
#endif

	//Mise à jour de l'extérieur, du sous-ensemble avec les nouveaux points
	int UpdateSubSet();
	int UpdateGoodSubSetWithSubSet();
	int UpdateSubSetWithGoodSubSet();
	
	void SetSmallResidus(int);	//1 si les résidus sont faibles, 0 sinon

	void GetIgnoredPoints(CATListOfInt& oListOfIgnoredPoint) const;

  double GetPercentMin() { return _PercentMin;}

  double GetMaxErrorAtCurrentStep() const {return _MaxErrorAtCurrentStep;}

  int GetNbFilterAll() const {return _NbFilterAll ;}

  int Test(double& oPercent) ;

  inline short GetLevel( ) const {return _CodeLevel;}

  static int SortFloatTab(float * ValTab, CATLONG32* Indir, const int iNbFloat);
  static int ComputeNumberDiscr(const double lx, const double ly, const double lz,
                                int& oNx, int& oNy, int& oNz, const int iMaxPointsNumber);

protected:
    void SetLevel( const short iLevel );
	//Gestion des boîtes
	//int ExistsBoxInList(int iCurrentBoxCoords[], CATInterp3DBox** iListOfBoxes, int iNbBoxes);
  int GetSizeBox(double oDim[3], const CATBoolean isIntialBox = FALSE);
	CATInterp3DBox* ExistsBoxInList(int iCurrentBoxCoords[],  CATInterp3DBoxHashTable* TheHasTable) const;
	double FindDistInAdjacentBoxes(CATInterp3DBox* iCuurentBox, CATInterp3DBox** iListOfBoxes, int iNbBoxes);
	int GetIndexInBigBox(int iIndex, int iStep, int* oIndexInBigBox);	//Index d'un point dans la boîte d'encombrement
	int UpdateCuttingStep(int iStep, const CATBoolean iUpdateStep = FALSE );
	int ComputeStats(int& NbPointsToInsert, int&NbPointsToMove, int& NbPointsChanged, 
		               const int iStep, float * EvalFunction,
									 double * oSummary, const short iMoveMode,
									 int * OldPoints=NULL, int * NewPoints=NULL);
	int UpdateFilter(const int NbWorstPoints, float* EvalFunction , float* Tol);
	int BuildBoxes(const int iStep, CATInterp3DBox** ListOfNonEmptyBoxes, int& countOk, double& Errmax,  double& oJ,
		             const float * EvalFunction = NULL, const short iMoveMode=1, CATListOfDouble * ioErrorList=NULL);
	int SortBoxes(const int NbOfNonEmptyBoxes, CATInterp3DBox** ListOfNonEmptyBoxes);
  //int BuildTabooList(const double iConfusion);
  int ToolsForDecimation(CATMarshPixellisation *& oThePixelOpe, double& oFilterValue, 
                         const int iNbPointsToInsert,const double iRadiusFactor=1.0);

  int SetSmoothDeviation(float*& ioSmothDeviationValues);

  virtual double ConfusionForDecimation() const;
  int EvalFunc(double& oValMax, CATListOfDouble * oList, const double iTol, int& oCountKO);

  //int DistanceFromSubSet(const CATMathPoint& iP, double& oDist) const;
  int DistanceFromSubSet(const int iIndex, double& oDist) const;
  int InitializeDistanceFromSubSet();

  int GetBox(CATMathPoint& origine, CATMathVector& oDeltaX, CATMathVector& oDeltaY, CATMathVector& oDeltaZ) const;

  virtual double UpdateRelativeRadius() {return 1.0;}

  int UpdatePercentMin(const int iAddNbPntsToIgnore);
  
	
#ifdef DEBUG_MODE
	//Affichage de certains objets
	virtual int DisplayActiveBoxes(CATInterp3DBox**& ListOfNonEmptyBoxes, int NbOfNonEmptyBoxes, int iStep) =0;
	virtual int DisplayErrorPoints(float*& EvalFunction) =0;
  virtual int DisplaySubset(int iStep) =0;
#endif
		
	//Evaluation de la fonction de déformation
	
	//Data
	CATListOfInt _ListOfIgnoredPoint;
  CATListOfInt _ListOfTabooPoint; //Les points que l'on interdit d'etre handle (pour pb de confusion et conditionnemnt)
                                  //Ce sont des points trop proche d'autres points!
	
	double _TwoPowerStep[3];
	double _DistDiag;
  double _BandLength;
	double _JJ; // La valeur du critere des moindres carres (c'est donc un carre)
	
  double _MaxErrorAtCurrentStep;
	double _PrevScore;
	double _NewPrevScore;
	double _PerCentWorstPoints;
	double _PercentMin;
	double _RelativeFraction;  //relatif a la taille des boite
  
	int* _GoodSubSet;
	double* _GoodSubSetTarget;
	double* _BoxCorner;				//Coordonnées des points de la boîte d'encombrement
  float *    _DistanceToLimit; //La distance de chaque source a la limite.
  float *    _DistanceToPlane; //La distance de chaque source au plan de symetrie. 
  const float *_SmoothDeviation; //La distance entre Target et "Smooth" Target.
  
	int _GoodSubSetSize;
	int _SmallResidus;
	int _Step;
	int _CuttingStep[3];
	int _CountWorstPoints;		//Nbre de points n'intervenant pas dans le calcul car trop difficiles à tenir     
	int _KeepFirstPoints;			//Option permettant de toujours garder les points initiaux
	int _PerturbationLoop;
	int _InterpolationLoop;
	int _InterpolationOnly;			//Mode interpolation uniquement
  int _NbFilterAll; //Compte le nombre de filtre absolu consecutif
 
	short _CodeLevel;
  short _CenteredMode;

private :
  int CandidatDecimation(int& ioNbPointsToInsert);

#ifdef CATDebug_RSOSym
  int CheckBoxSymetry(CATInterp3DBoxHashTable* iBoxHasTable, const double iConfusion, const int iStep);
  int CheckActivationSymetry(CATInterp3DBoxHashTable* iBoxHasTable, const int iStep);
#endif
#ifdef CATTry_SymetrizeBox
  int CompleteSymActivation(CATInterp3DBoxHashTable * iBoxHasTable, CATInterp3DBoxHashTable& ioNewActivedBoxHasTable, const int iStep) const;
#endif
  CATInterp3DBox*  HasMirror(CATInterp3DBox*iCurrentBox, const int istep, const int iCoord, CATInterp3DBoxHashTable* iBoxHasTable) const;

  CATListOfInt _ConcatenationOfWrongPoints;
  CATMarshPixellisation * _PixelOpeForDistance;
  
  double _RadiusForDist;
  int _NbPointsToInsert;      //Nbre de point a inserer a la prochaine etape
  int _NbPntToInsert_BeforeDecima;      //Nbre de point a inserer a la prochaine etape
  short _CountSameStep;				//Prévention une éventuelle boucle infinie
  CATBoolean _IsAppendError; //Conserve les point hors Tol via EvalFunc
								
};

#endif
