#ifndef CATInterpND_H
#define CATInterpND_H

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002-2005
//
/**
* @level Private
* @usage U2
*/

#include "MathAdvMarsh.h"

#include <stdlib.h>
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATTolerance.h"


class CATMathSetOfPointsND;
class CATGeoFactory;
class CATNurbsCurve;
class CATMathMxNMatrix;
class CATMathNxNFullSymMatrix;

//#define CATInterpND_Complete

const short Pnt_Warning_And_Be_Filtered =-12;
//const short Pnt_Warning_And_Difficult =-11;
const short Pnt_Warning =-10;
const short Pnt_Should_Be_Filtered =-2;
const short Pnt_Is_Difficult =-1;
const short Pnt_Without_Information = 0;
const short Pnt_To_Be_Insert = 1;
const short Pnt_Candidate_Insert = 2;
const short Pnt_To_Be_Insert_And_Modified = 4;
const short Pnt_To_Be_Keep = 10;
const short Pnt_To_Be_Keep_And_Modified = 14;


/**
* Base Class to approximate a set of nD vector with use of an interpolate algorithm
*
* <br><b>Role</b>: Tools to fit 3d fields

* @see @href CATInterp3D
*/
class ExportedByMathAdvMarsh CATInterpND
{
public:
	
	//Constructeur par défaut
	CATInterpND(const CATTolerance & iTol);
	
#ifdef CATInterpND_Complete
	//Le constructeur, à définir...
	CATInterpND(double*& iParam, int iDimOfParam, double*& iPoints, int iDimOfPoints, float* iTol, int iNbPoints);
#endif
	
	virtual ~CATInterpND();

	//Le run
	int Run();
	void SetNorm(int ip);
	int GetNorm();
	int GetNumberOfPoints() const;  
	int GetSubSetSize() const;
  int GetNumberOfPointsToFilter() const; //Le nombre de point auto-filtrer
  int GetTargetWrongPoints() const;
	int* Sample();		//Renvoie les indices du sous-ensemble

	
	//A définir pour la dimension:
	/*param iMoveMode
		-  0 : Decompte des points a deplacer
		-  1 : Keep + Raffinement "local"
		-  2 : Only Keep
	//Cette fonction doit respecter les conditions suivantes pour les valeurs de retour:
	//0 -> Tout est OK, le travail est fini (éventuellement remettre les points _Index.. de 4 à 1)
	//1 -> Il faut continuer le travail
	//-1 -> Aucun point à insérer ni à perturber, c'est fini.
	//-2 -> Il faut perturber les points car on ne peut plus en insérer
	//n<-2 -> Messages d'erreur variés, le calcul est stoppé
	*/
	virtual int TestAndRefine(int iStep, double* oSummary=NULL, 
														const CATBoolean iUpdateFilter = FALSE,
														const short iMoveMode= 0)=0;		//Vérification de l'interpolation

  //calcul le pourcentage de reussite
	virtual int Test(double& oPercent);
	

	//Calculs des nouveaux points
	int ComputeNewPoints();

	int BackUpNewPoints();
	int RestoreNewPoints(const CATBoolean iRestoreOnlyComputedPoints = FALSE);

	//Perturbation du sous-ensemble
	int Perturbation(const double iSeuil = 1.0e21);

	//Insertion des nouveaux points dans le sous ensemble
	int InsertPointsInSubSet(int iNbPointsToInsert);

  //Remet les flag a zero (utile quand on recommence sur le meme sous-ensemble
	int InitSubSetFlag();

	
protected:

  //int SolveCholesky(const CATMathNxNFullSymMatrix* iDecomposed, double *iob);
	
#ifdef CATInterpND_Complete
	//Résolution des moindres carrés
	virtual int LeastSquare();
#endif
	
	//Méthode de Newton
	int Newton();
	void EvalGrad(double*& iPoint, int iSubSetSize, int iIndexCoords, double*& Grad, double* iExtremitiesCoords=NULL);
	void EvalHessien(double*& iPoint, int iSubSetSize, int iIndexCoords, CATMathNxNFullSymMatrix*& ioHessien, double* iExtremitiesCoords=NULL);
	double EvalJX(double*& iPoint, int im, int iIndexCoords, double* iExtremitiesCoords=NULL);
	int Cholesky(const CATMathNxNFullSymMatrix* iMatrix, CATMathNxNFullSymMatrix* C, double iSeuil=5e-3);
	int PerturbationAndRefine(int iStep);
	int StatsStatusofPnts() const;

  // rend le type modifie (protection des warning!)
  void ProtectedChangeType(const short iTargetType, short& ioType) const;
	
	//Calcul de la matrice A, dépend du type d'interpolation
	//virtual int ComputeAMatrix(int iIndexCoords=-1)=0;
	//Choix de la matrice d'interpolation
	virtual void SetAMatrix(int iIndexCoords=-1)=0;

	//Evaluation de la fonction d'interpolation en un point, dépend du type d'interpolation
	virtual double EvalInterp(int iIndexOfti) const=0;

	//Calcul de la distance euclidienne entre deux points de dimension _DimOfPoints
	double Distance(double* iPt1, double* iPt2);
	double Norme(double* iVector, int iVectorSize);
	void Normalize(double* iVector);

  int AllocComputedPoints(const int iSize);

	//Data
	double _Theta;				//Eventuellement pour Newton, pour rajouter un terme quadratique pondéré
  const CATTolerance & _ModelTol;

	CATMathMxNMatrix* _A;		//Matrice d'interpolation
	
	float * _Tol;				//Tolérance associée à chaque élément de l'ensemble initial
	double* _SetOfParameters;	//Ensemble des paramètres
	double* _SetOfPoints;		//Ensemble des points
  double* _FixedParameters;		//Ensemble des points fixe.
	double* _ComputedPoints;	//Nouvelles coordonnées des points après le calcul de Jp
	
	short* _TypeOfUsedPoints;	//Etats des points du sous-ensemble
	short* _BackUpIndex;        //backUp de l'Etats des points du sous-ensemble
	double* _BackUpPnts;        //backUp des points calculees...
	int* _SubSet;				//Index des points du sous-ensemble
	int* _BackUpSubSet;				//Index des points du sous-ensemble

  double _Resolution;
  double _SmallResolution;

	int _NbPoints;				//Nombre d'éléments de l'ensemble initial
  int _NbFixedParameters; //Nombre de points fixe en plus.
  int _NbPntsToBeFiltered;  //Nombre de points exclut a priori des Moindre carre!
	int _SubSetSize;			//Taille du sous-ensemble
	int _BackUp_SubSize;  //backUp de la Taille du sous-ensemble.
	int _p;						//Valeur de la norme utilisée

	short _DimOfParam;			//Dimension de l'espace des paramètres
	short _DimOfPoints;			//Dimension de l'espace des points
	short _KeepExtremities;		//Spécifie s'il faut fixer les extrémités.
};

#endif
