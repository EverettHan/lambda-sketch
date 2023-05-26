// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2006
//=============================================================================
//								   
// CATSurfacicDistanceUtilities :						   
// Implementation of different services of CATSurfacicDistanceUtilities
//
//=============================================================================
//  26-10-2006 : PMG; Creation.
//=============================================================================
//
#ifndef CATSurfacicDistanceUtilities_h
#define CATSurfacicDistanceUtilities_h


#include "GeoPlate.h"


//fw:GeometricObjects
#include "CATCrvParam.h"


//fw:Mathematics
#include "CATMathPoint.h"


class CATGeoFactory;
class CATCurve;
class CATCrvLimits;
class CATSoftwareConfiguration;


class  CATSurfacicDistanceUtilities
{
	public:

    // Discretisation d'une courbe a l'erreur de corde
  // Utilise la fonction NextPointAtChordalError() pour obtenir les points
  // En retour :
  //    oNbPnts contient le nombre de points discretises. 
  //		oPoints contient les points l'allocation est faite par la methode.
  //		oParams contient les parametres correspondants, l'allocation est faite par la methode.
  //		oLength contient la longueur de la courbe discretisee (approchee)
  // Ne pas oublier de detruire les 2 tables apres usage comme suit
  // if (Points == NULL) {delete [] Points; Points = NULL;}
  // if (Params == NULL) {delete [] Params; Params = NULL;}
    ExportedByGeoPlate static int DiscretiseCurveChordalErrorNew (CATSoftwareConfiguration* iConfig, CATCurve * iCurve, CATCrvLimits * iLimits, const double iErreurCorde,
                                    const int iNbPointTest, const double iLongueurMax,
							                      int  & oNbPoints, CATMathPoint * &oPoints, CATCrvParam * &oParams,
									                  double * oBoxMin, double * oBoxMax, double & oLength,const double iPResolution, const double iResolution);


#ifdef Complete_CATSurfacicDistanceUtilities

  // Renvoie vrai si il y a intersection entre les deux boites englobantes
  // iBox1Min      : Le point minimun de la premiere boite englobante
  // iBox1Max      : Le point maximun de la premiere boite englobante
  // iBox2Min      : Le point minimun de la deuxieme boite englobante
  // iBox2Max      : Le point maximun de la deuxieme boite englobante
  static CATBoolean IsBoxIntersection(double iBox1Min[3] , double iBox1Max[3] , double iBox2Min[3] , double iBox2Max[3]);
  
  // Renvoie vrai si les deux boites englobantes sont identiques a une tolerance pres
  // iBox1Min      : Le point minimun de la premiere boite englobante
  // iBox1Max      : Le point maximun de la premiere boite englobante
  // iBox2Min      : Le point minimun de la deuxieme boite englobante
  // iBox2Max      : Le point maximun de la deuxieme boite englobante
  // iToleranceEqual: Tolerance d'egalite entre 2 points.
  static CATBoolean IsSameBox(double iBox1Min[3] , double iBox1Max[3] , double iBox2Min[3] , double iBox2Max[3] , double iToleranceEqual);
  

  // Renvoie vrai si une boite englobante est incluse dans une autre, et renvoie quelle est la boire englobante incluse dans l'autre
  // iBox1Min      : Le point minimun de la premiere boite englobante
  // iBox1Max      : Le point maximun de la premiere boite englobante
  // iBox2Min      : Le point minimun de la deuxieme boite englobante
  // iBox2Max      : Le point maximun de la deuxieme boite englobante
  // oInclusion	   : determine quelle boite englobante est incluse dans l'autre
  //				 0 si pas d'inclusion, 1 iBox1 est incluse dans iBox2, 2 iBox2 est incluse dans iBox1 
  // iToleranceEqual: Tolerance d'egalite entre 2 points.
  static CATBoolean IsBoxInclusion(double iBox1Min[3] , double iBox1Max[3] , double iBox2Min[3] , double iBox2Max[3], int & oInclusion, double iToleranceEqual);



  // Renvoie vrai si il y a intersection entre les parametres et renvoie la zone d'intersection
  // On considere que le parametre debut est < au parametre fin
  // iPDeb1        : le parametre de debut de la premiere decoupe
  // iPFin1        : le parametre de fin de la premiere decoupe
  // iPDeb2        : le parametre de debut de la deuxieme decoupe
  // iPFin2        : le parametre de fin de la deuxieme decoupe
  // iTolParam	   : tolerance d'egalite de parametre
  // oPDeb         : le parametre de debut de la zone d'intersection
  // oPFin         : le parametre de fin de la zone d'intersection
  static CATBoolean IsEdgeIntersection(double iPDeb1 , double iPFin1 , double iPDeb2 , double iPFin2 , double iTolParam , double &oPDeb , double &oPFin);
  
  // A partir des connexions deja etablies, recherche d'informations.
  // Renvoie vrai si tout l'Edge n'est pas connecte et renvoie les partie non connectees
  // iTolerance    : la tolerance d'assemblage (connexion)
  // iPDeb         : le parametre de debut du segment
  // iPFin         : le parametre de fin du segment
  // iParams       : un tableau contenant les parametres de decoupes sur le segment
  // iNbElems      : le nombre de decoupe
  // oParams       : Liste des partie non connectees (i = ParamDeb , i+1 = ParamFin)
  //static CATBoolean IsEdgesLibres(double iTolerance , double iPDeb , double iPFin , StructParams *iParams , int iNbElems , CATListOfDouble &oParams);

#endif

  // Calcul de la distance carree d'un point a un segment
  // si la projection ne tombe pas a l'interieur du segment, 
  // renvoi la distance du point a une extremite (la + pres)
  // ---------------------------------------------------------------------------
  // Projection orthogonale du point M sur le segment oriente [P1P2]
  // H = Projete orthogonal de M sur [P1P2]
  // lambda = P1M/P1P2  =>      lambda < 0	H est a gauche de [P1P2]
  //	 					 0 <  lambda < 1	H est a l'interieur de [P1P2]	
  //							  lambda > 1    H est a droite de [P1P2]
  //							  lambda = 0	H = P1
  //							  lambda = 1	H = P2
  // ---------------------------------------------------------------------------
  ExportedByGeoPlate static double Dist2_Point_Segment (const double iM[3], const double iP1[3], const double iP2[3] , double & oLambda);
  ExportedByGeoPlate static double Dist2_Point_Segment (const double iM[3], const double iP1[3], const double iP2[3]);

 

  

  


private:

   // Renvoit le prochain point a l'erreur de corde sur une courbe
  // En entree :
  //    iCurve:        Courbe que l'on est en train de discretiser
  //    iLimits:       Portion de la courbe a laquelle on se limite
  //    iPCur:         Parametre courant sur la courbe
  //    iDeltaMini:    Pas parametrique minimum dont on souhaite avancer
  //    iDeltaMaxi:    Pas parametrique maximum dont on souhaite avancer
  //    iErreurCorde:  Erreur de corde a laquelle on discretise la courbe
  //    iNbPointTest:  Nombre de points de la courbe en lesquels on verifie l'erreur de corde
  //                   Il est preferable que ce nombre soit impaire pour que l' on teste l' erreur de corde
  //                   au milieu, la  ou elle est supposee max
  //                   Si negatif ou nul ou > 9, il est impose a 5 
  //    iLongeurMax:   Longueur max d'arrete souhaitee
  //
  // En sortie :
  //		oPoint:  contient le point
  //		oParam:  contient le parametre correspondant
  //		oLength: longueur de l'arrete
  //
  // Retourne : 0 si OK
  //            1 iCurve est NULL
  //            2 iLimits est NULL
  //            3 iLongeurMax vaut 0
  //            4 on est en train de boucler
  //            5 erreur lors de l' intrepolation lineaire
  //           -1 on renvoit le dernier point de la courbe
  static int NextPointAtChordalError (CATCurve * iCurve, CATCrvLimits * iLimits, const CATCrvParam & iPCur, const double iErreurCorde,
        const double iDeltaMini, const double iDeltaMaxi, CATMathPoint & oPoint, CATCrvParam & oParam, double & oLength, const int iNbPointTest, const double iLongeurMax,const double iPResolution);


#ifdef Complete_CATSurfacicDistanceUtilities
  // Verification du respect de l'erreur de corde entre 2 points d'une courbe
  // Renvoi TRUE si l'erreur de corde est respectee en un certain nombre de points (par defaut 5)
  // Si td et tf sont les parametres de debut et de fin d'analyse, on echantillonne en N points entre [td,tf]
  // et on verifie que la distance de chaque point 3D echantillonne sur le segment P(td), P(tf) est < Ec
  //
  //	iCurve				: La courbe
  //	iDeb & iFin	        : En double, correspond au Parametre debut et fin d'etude 
  //                          (on impose rien sur l'ordre, deb < fin ?)
  //	iErreurCorde		: Erreur de corde a respecter
  //	iNbPointTest		: Nombre de points d'echantillonnage (defaut 5)
  static CATBoolean VerificationChordalError (CATCurve * iCurve, const double iDeb, const double iFin, 
									          const double iErreurCorde, const int iNbPointTest = 5);
#endif

  // Calcul du pas d'incrementation a realiser a partir d'un point pour progresser sur la courbe
	// en respectant l'erreur de corde
	//
	// iCurve			    : La courbe
	// iTCur			    : Parametre a partir duquel on veut progresser
	// iErreurCorde		: Erreur de corde a respecter

	// oIncrement		  : En sortie, en double correspond au pas d'incrementation a realiser par rapport a iTCur
  // Return         :
	//                  -1 ==> Pb qque on ne peut pas progresser, il faut un traitement special.
	//				                 Actuellement le seul cas est une courbe nulle !!
	//                  0 ==> Tous est Ok
	//			            1 ==> Rayon de courbure infini
	//			            2 ==> Rayon de courbure nul
	static int ProgressionChordalError (CATCurve * iCurve, const CATCrvParam & iTCur, const double iErreurCorde, 
								 double & oIncrement);

#ifdef Complete_CATSurfacicDistanceUtilities
    // Ramene en plus la Courbure et la Normale au point de depart
	static int ProgressionChordalErrorNew (CATCurve * iCurve, const CATCrvParam & iTCur, const double iErreurCorde, 
								 double & oIncrement, double & oCourbure, CATMathVector & oNormale);

    // Calcule la Position, Courbure et la Normale en un point de parametre donne sur une courbe
    // Rem : Si la courbe est une pCurve, c'est bien la courbure et la Normale a la courbe sur la surface qui est calcule
    // Return Courbure infini (Tres grande) si pas de courbe
	static void EvalPointCourbureNormale (CATCurve * iCurve, const CATCrvParam & iTCur,  
                                          CATMathPoint & oPoint, double & oCourbure, CATMathVector & oNormale);
#endif

   // CTJ: nouveau calcul de distance visant a ameliorer les performances
  // On ne calcul en fait ici que la distance du point a la droite donne par le segment [P0P1]
  // On ne teste pas si le point se projette a l'interieur ou pas
  //
  // Input: - iM:				Point a projete
  //        - iP0:				Origine du segment sur lequel on projette
  //        - iP0P1:			Composante du vecteur definissant le segment
  //		- iInvNorme2P0P1:	Inverse du carre le la norme du segment P0,P1
  // 
  // Return: Carre de la distance de iM au support de [P0P1]
  //
  // Attention iInvNorme2P0P1 doit etre non nul, pour ne pas faire de division on prend l'inverse
  //           Cette methode est a utiliser l'orsqu'elle est appellee plusieurs fois avec les 2 meme points P0,P1
  //           en ne modifiant que M
  static double Dist2_Point_SegmentNew (const double iM[3], const double iP0[3], const double iP0P1[3], const double iInvNorme2P0P1);

  // Renvoie la distance point-point
  inline static double Dist_Carre_3D_d(const double ip1[3],const double ip2[3]);

};


inline double CATSurfacicDistanceUtilities::Dist_Carre_3D_d(const double p1[3],const double p2[3]){
return((*p1-*p2)*(*p1-*p2)+(*(p1+1)-*(p2+1))*(*(p1+1)-*(p2+1))+(*(p1+2)-*(p2+2))*(*(p1+2)-*(p2+2)));
}



#endif











