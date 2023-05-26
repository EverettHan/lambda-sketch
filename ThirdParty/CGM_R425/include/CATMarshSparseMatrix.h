 /// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
//
// CATMarshSparseMatrix : Matrice Creuse pour Marshmallow
// Cette Matrice passe par 2 phases 
//  1] NoFreeze 
//     - Aucun Coefficient ne peut etre stocker
//     - Le profil peut etre modifier
//
//  2] Freeze
//    - Les coefficient sont stocker 
//    - Le profil ne peut plus etre modifier.
//
//=============================================================================
//
//
//=============================================================================
// Oct  .2004    Creation                         P.Mangin
//=============================================================================
#ifndef CATMarshSparseMatrix_HeaderFile
#define CATMarshSparseMatrix_HeaderFile



#include "CATMathDef.h"
class CATMathNxNFullSymMatrix;
	
class CATMarshSparseMatrix
{
public :
 
   CATMarshSparseMatrix(const int iN); 
   virtual ~CATMarshSparseMatrix();
  
 /*  int ActiveBloc(const int iFirstLine, const int iLastLine,
																		 const int iFirstCol, const int iLastCol);*/

 // ==================================================================
 // ======   Gestion posible avant le FREEZE
 // ==================================================================

	// rend la dimension de la matrice.
	 int GetSizeOfMatrix() const;

 // Demare une session de modification du profil pour la ligne <iLine>
	// return 0 si OK
  int InitSession(const int iLine);
 // Valide les modification du profil pour la ligne <iLine>
 // return 0 si OK
  int CloseSession(const int iLine);
 // Active la colonne iCol => dans la ligne courante
 // return 0 si OK
  int ActivateCol(const int iCol);


  // Permet de geler le profile
  // Et de creer un contenu (initialiser a 0.0).
   int Freeze();

   //  Fill the sparse structure from a full matrix
   int FillFrom(const CATMathNxNFullSymMatrix& iFullMat);


 // ==================================================================
 // ======   Gestion posible apres le FREEZE
 // ==================================================================

	// donne la premiere colonne dans la structure 
	// retourne -1 s'il n'y en a pas....
	 int FirstJ(const int i) const;
	// donne la colonne suivante dans la structure 
	// retourne -1 s'il n'y en a pas....
	 int GetNextJ() const;

	//retourne l'index correspondant au coef i,j
	// retourn -1 s'il n'existe pas.
	 int GetIndexFirstJ(const int i) const;


	// renvoie le tableaux de coefficients.
	 double * GetCoeffs() const;

  // renvoie le nombre de Coeff non Nuls
   int  GetNbCoeffs() const;

	// renvoie le profile au format "SkyLine"
	 int  GetProfile(int*&  oEndOflinePointer, int*& oColumn  ) const;

   // Calcul le vecteur Ax
	 // Les tableau iX et oAX doivent etre de dimension N
	 int Multiply(const double * iX, double * oAX) const;


	 double SchurNorm () const ;

   void SetCodeLevel(const short iCodeLevel = 1) { _CodeLevel = iCodeLevel;}

   void SetMute(const bool isMute) { _isMute = isMute;}

private :	

  CATMarshSparseMatrix();
  CATMarshSparseMatrix(const CATMarshSparseMatrix&);

	inline int LinearIndex(const int row, const int col) const;
	int FreezeProfil();
	int CleanTab();


  
	int * _EndOflinePointer;
	int *  _ColumnPtr;
	int **  _TabColumnPtr;
  double * _CoeffsPtr;
	int * _profil_line;
	//char * _Profil;
	char*  _LineSky;
	int _N;
	int _cacheI, _cachePos, _cacheDeb;
  short _CodeLevel;
  bool _isMute;
};

inline int CATMarshSparseMatrix::LinearIndex(const int row, const int col) const
{
  //if (row>=col)
  return (row*(row+1)>>1)+col;   
}

#endif

