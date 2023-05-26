/**
 *  Large Range compatibility certified by DNR (2014-05-21)
 */
//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2004
//==============================================================================================================
// File: CATCldPixellisation.h
//==============================================================================================================
// Usage:
// Creation d'une structure de donnee 2D sur des points 3D en vue de faire des requetes de proximite.
// Les point 3D representent dans la majorite des cas la peau d'une surface. C'est cela qui justifie la methode
// de pixellisation utilisee
// 
// Tout a ete realise dans une optique de performance et de simplicite pour l'utilisateur.
// 
// Au constructeur, on ne donne que le rayon maximum (Rm) des requetes de distance que l'on realisera.
// Pour l'instant on ne sait pas encore s'en passer.
// 
// Attention, Rm a une influence considerable sur les performances.puisqu'elle determine la taille minimum d'un
// pixel. Si Rm est grand, chqaue pixel sera egalement grand et il y en aura peu. S'il y a peu de pixels,
// chacun aura beaucoup de points et la recherche tendra vers une recherche sequentielle en N^2.
// 
// Filtrage des points : Cas particulier d'utilisation
// -------------------
// 
// o Si l'on dispose de tous les points on peut appeler la methode Filtrage pour un rayon donne. 
//   Elle renvoie une table de Flags associee aux points contenant TRUE si ce point n'a pas de voisin
//   dans la sphere (FALSE sinon). Configuration optimum en performance. 
//   Avec une machine 2.8GHz et 1Go de RAM, sur une entree de 5 M points on filtre 3.3 M points en 8s
//   et on est en mode debug
// o Cette methode ne necessite aucun prealable
// 
// 
// Cas General :
// -------------
// 
// a/ La performance optimum est celle ou l'on peut donner tous les points en une seule fois avant de realiser
//    des requetes mais ce n'est pas toujours possible.
// b/ Le cas le plus defavorable est celui ou l'on donne un point apres l'autre apres avoir requete sur son
//    existence dans un rayon donne. 
// c/ On peut ameliorer grandement le cas b/ si l'on peut donner (meme une estimation) la boite englobante avant
//    toute adjonction de point.
// d/ Les points peuvent etre ajoutes unitairement, par paquets, la liberte est complete.
// e/ A chaque point ou a chaque paquet de points, un identificateur est rendu permettant de connaitre sa place
//    dans la SD. En fait, c'est le numero d'ordre d'apparition de 0 a NbPoints-1
// f/ Il n'est pas necessaire que l'utilisateur conserve les points, il peut toujours les recuperer sur
//    interrogation permettant ainsi un gain de place appreciable.
//
// Donner ensuite :
// 
//   o SetBoundingBox               pour la boite englobante si on la connait
//   o AddTableOfPointsInPartition  pour une ou plusieurs series de points
//   o AddPointInPartition          pour un ou plusieurs points
// 
// On peut panacher comme l'on veut, tout est permis
// 
// La principale requete est :
// -------------------------
// A partir des coordonnees d'un point, de connaitre les autres points situes dans une sphere
// de rayon donne. Ce rayon etant inferieur ou egal a la distance passee dans le constructeur.
// La methodologie est la suivante :
//   o Initialiser un iterateur avec les coordonnees (ou le numero) de ce point GetIterator (Point, Rayon)
//   o Boucler en faisant des Next: while (Pixellisation . Next(Neighbor) == 0) 
//     a chaque fois Neighbor contient le numero de point suivant ou -1 si c'est fini
// 
// Remarque : On ne peut prendre qu'un seul iterateur a la fois.
// 
//   o Si l'on veut creer la SD sans doublon, il est necessaire de l'interroger sur l'existence du point
//     (IfExistePoint) avant de l'ajouter. La SD ne contiendra ainsi que des points sans doublons a une
//     distance donnee.
//==============================================================================================================
// 16-Nov-2005 - GDD - SetBoundingBox avec nombre de points
// 27-Jun-2005 - JLH - Reprise dans CATCloudBasicResources et mise � jour de l'ent�te.
// 18-Mar-2005 - CSO - Export via HA 
// 03-Mar-2005 - CSO - Export pour CqgServices
// 26-Apr-2004 - CTJ - Creation (Stagiaire de GDD)
//==============================================================================================================

#ifndef CATCldPixellisation_h
#define CATCldPixellisation_h

#include "ExportedByCATCloudBasicResources.h"
#include "CATMathPoint.h"

class ExportedByCATCloudBasicResources CATCldPixellisation
{
public:


/*--------------------------------------Constructeur---------------------------------------------*/

	// Constructeur
	//  Parametres: - iDistanceMax: Distance maximale de recherche des voisins dans les requetes
	//				  Cette valeur determinera la taille minumum d'un pixel. 
	//				  Dans toutes les requetes qui demandent une distance, celle ci ne pourra pas etre 
	//                superieure a iDistanceMax en l'etat actuel des choses.

	// Attention, iDistanceMax a une influence considerable sur les performances.puisqu'elle determine
	// la taille minimum d'un pixel.
	// Si iDistanceMax est grand, chqaue pixel sera egalement grand et il y en aura peu. S'il y a peu de pixels, 
	// chacun aura beaucoup de points et la recherche tendra vers une recherche sequentielle en N^2.

	CATCldPixellisation(const double iDistanceMax);

	// Destructeur
	virtual ~CATCldPixellisation();

/*----------------------------------La boite englobante---------------------------------------*/

	// La boite englobante. Si on la connait, autant la donner. 
	// Si on la donne, le faire en premier, avant d'ajouter des points
	// Elle n'est pas necessaire a priori car calculee au fur et a mesure mais,
	// si on la connait, meme un ordre de grandeur, les calculs en seront acceleres
	// PMin : coordonnees du coin inferieur gauche
	// PMax : coordonnees du coin superieur droit

	// Rem : Il n'y a aucun test de validite.

	// NbPointsPrev: Un ordre du nombre de points a gerer pour calculer (a peu pres) le Nombre de Pixels Maximum.
	//               Utile au niveau perfs si l'on connait exactement ou par une estimation meme grossiere 
	//               le nombre de points que l'on traitera.
	//               On s'est rendu compte que si l'on utilisait cet algo souvent mais avec peu de points,
	//               on utilisait qu'un seul pixel et que la recherche a l'interieur etait donc en N^2.
	//               si l'on declare une table au maximum des pixels, son initialisation au depart a -1
	//               coute plus cher que les tests en N^2. D'ou, si l'on sait que l'on a peu de points,
	//               il y a interet a mettre peu de pixels d'entree

	void SetBoundingBox (const CATMathPoint &iPMin,    const CATMathPoint &iPMax   , int NbPointsPrev = -1);
	void SetBoundingBox (const double        iPMin[3], const double        iPMax[3], int NbPointsPrev = -1);
	void SetBoundingBox (const float         iPMin[3], const float         iPMax[3], int NbPointsPrev = -1);


/*-----------------------------------Pour Setter des Valeurs------------------------------------*/
	// Pour setter des points dans la table des coordonnees

	// iNbPoints	: Le nombre de points
	// iTabPoints	: La table des points a prendre en compte
	// oNumero		: Le Numero du premier point dans la table des points [0, ...]
	// Retour		: 0 Si tout est OK

	int AddTableOfPointsInPartition (const int iNbPoints, const CATMathPoint * iTabPoints, int &oNumero);
	int AddTableOfPointsInPartition (const int iNbPoints, const double       * iTabPoints, int &oNumero);
	int AddTableOfPointsInPartition (const int iNbPoints, const float        * iTabPoints, int &oNumero);

	// Pour setter un point dans la table des coordonnees
	//
	// iPnt3D	: Le point a rajouter
	// oNumero	: Le Numero du point dans la table des points [0, ...]
	// Retour	:  0 ==> OK
	//			   1 ==> Pb d'allocation memoire

	int AddPointInPartition(const CATMathPoint  &iPnt3D,    int &oNumero);
	int AddPointInPartition(const double         iPnt3D[3], int &oNumero);
	int AddPointInPartition(const float          iPnt3D[3], int &oNumero);

	// Test d'existence d'un point dans la partition
	// iPnt3D	: Le point dont on veut savoir s'il existe deja
	// iRayon	: Le rayon de la sphere de confusion
	// oNumero	: Le Numero du point dans la table des points [0, ...] si le point existe (-1 sinon)
	// Retour FALSE si le point n'existe pas dans la tolerance de confusion

	unsigned char ExistePointInPartition (const CATMathPoint &iPnt3D,    const double iRayon, int &oNumero);
	unsigned char ExistePointInPartition (const double        iPnt3D[3], const double iRayon, int &oNumero);
	unsigned char ExistePointInPartition (const float         iPnt3D[3], const double iRayon, int &oNumero);

	// Recuperation du nombre de points dans la SD

	int GetSizeOfPartition ();

	// Recuperation des coordonnees d'un point a partir de son numero
	// iNumero	: Numero du point a recuperer (0 a ...)
	// oPnt3D	: Le point recupere
	// Retour FALSE si le numero est invalide.

	// Rem : On peut avoir le nombre de points par le GetSizeOfPartition

	unsigned char GetPointInPartition (const int iNumero, CATMathPoint &oPnt3D);
	unsigned char GetPointInPartition (const int iNumero, double        oPnt3D[3]);
	unsigned char GetPointInPartition (const int iNumero, float         oPnt3D[3]);

	// Recuperation de la boite englobante
	// oPntMin : coin inferieur gauche
	// oPntMax : coin superieur droit

	void GetBoundingBox (CATMathPoint &oPntMin,    CATMathPoint &oPntMax);
	void GetBoundingBox (double        oPntMin[3], double        oPntMax[3]);
	void GetBoundingBox (float         oPntMin[3], float         oPntMax[3]);


/*------------------------------------------Requetes particuliere--------------------------------*/

	// Filtrage : Construction d'une table de flag associee a la table des points. La valeur TRUE
	//            signifie que le point correspondant n'a pas de doublon a une distance <= Rayon
	//            Le tableau de Flag est cree dans la methode, si le pointeur n'est pas NULL, le
	//            tableau est detruit puis reconstruit.
	// iNbPoints	: Le nombre de points
	// iTabPoints	: La table des points a prendre en compte
	// iRayon     : Le rayon de la sphere de filtrage (<= valeur donnee dans le constructeur)

	// Retour : 0 OK

	int Filtrage (const int iNbPoints, const CATMathPoint * iTabPoints, const double iRayon, unsigned char * & ioFlag);

	int Filtrage (const int iNbPoints, const double       * iTabPoints, const double iRayon, unsigned char * & ioFlag);

	int Filtrage (const int iNbPoints, const float        * iTabPoints, const double iRayon, unsigned char * & ioFlag);

/*------------------------------------------Requetes---------------------------------------------*/

	// Elle consiste, a partir d'un point donne par son numero ou par ses coordonnees, a recuperer 
	// les indices des points d'origine dont les coordonnees sont a une distance maximum donnee en 
	// parametre (Rayon)

	// La methodologie se resume a prendre un iterateur (GetIterator) en precisant le point et le rayon 
	// de la sphere d'influence puis d'iterer avec la fonction Next ==> Point suivant

	// Attention: On ne peut utiliser qu'un iterateur a la fois (C'est dommage mais c'est ainsi !)

	// Exemple d'utilisation
	// 1. Cree un objet CATCldPixellisation, par exemple Pixellisation
	// 2. Setter les points : Pixellisation.AddPoints.....();
	// 3. Initialiser l'iterateur: Pixellisation.GetIterator(PointoSearchNeighbor, SeuilFusion);
	// 4. Boucler en faisant des Next: while(Pixellisation.Next(Neighbor) == 0)

	// Iterateur sur les voisins potentiels d'un point
	// Initialise l'iterateur
	// Parametre: le numero du point dans le tableau
	// retourne  0 si OK
	//           1 erreur: la pixellisation n'a pas ete construite correctement 
	//           2 erreur: iNumPoint n'est pas valide
	//           3 erreur: iRayon est superieur a la Distance maximale passee en parametre dans le constructeur

	int GetIterator(const int iNumPoint, const double iRayon);

	// Iterateur sur les voisins potentiels d'un point
	// Initialise l'iterateur
	// Parametre: Un point quelconque
	// retourne  0 si OK
	//           1 erreur: la pixellisation n'a pas ete construite correctement
	//           2 erreur: iRayon est superieur a la Distance maximale passe en parametre dans le constructeur
	//           3 erreur: le numero de pixel calcule est incorrect (erreur interne)
	int GetIterator(const CATMathPoint & iPoint,    const double iRayon);
	int GetIterator(const double         iPoint[3], const double iRayon);
	int GetIterator(const float          iPoint[3], const double iRayon);


	// Iterateur sur les voisins d'un point
	// renvoit le numero du point suivant
	// retourne  0 si OK
	//           1 erreur: la pixellisation n'a pas ete construite correctement
	//           2 erreur: si l'utlisateur n'a pas fait de GetIterator()
	//          -1 on a traite tous les points
	int Next(int & oNumPoint);


private:


/*-----------------------------------------Variables--------------------------------------------*/
 
	// Indique si la pixellisation a ete faite et en plus correctement correctement.
	// Rem : Elle est necesaire pour la prise d'iterateur
	unsigned char _IsDone;

	// Flag pour savoir si l'on a fait une requete de positionnement
	// Tant que il n'y en a pas eu une, il est inutile de partitionner.
	// Il suffir de maintenir la Bdx a jour, et d'entasser les points dans la table
	// et a la premiere requete, on fait comme avant.
	// On gagnera dans le cas ou l'on donne un tableau d'un coup ou meme plusieurs.

	unsigned char _RequetteDemandee;
	
	// La boite englobante des points
	double		_BoxMin[3], _BoxMax[3] ;
	// _BdxIsModify = TRUE si la Bdx a ete modifiee cf AddPoint - (Sert a la re-pixellisation)
	unsigned char  _BdxIsModify ;
	
	//Tableau des Coordonnes des Points
	float 		* _CoordsOfPoints;

	// Pour la gestion des allocations dynamiques

	int			_NbIncre;		// Nombre de points d'incrementation. 
	int			_SzPoint;		// Taille en byte d'un Point  =  3 * sizeof(float);
	int			_MaxPoint;		// Nombre de points maximun de la table allouee courante
	
	// Les indices des axes de projection U et V (0 ==> X, 1 ==> Y, 2 ==> Z)
	// Par defaut on projette sur le plan [X,Y] donc dans la direction des Z 
	// _UProj = 0, VProj = 1
	short _UProj, _VProj;
	
	// Tableau des points, on chaine les points d'un meme pixel
	// Contient l'identificateur du point suivant dans le pixel, ou -1 si c'est le dernier
	int * _TabPoints;
	
	// Nombre de points
	int _NbPoints;
	
	// Tableau des pixels
	// Contient l'indentficateur dans _TabPoints du premier point du pixel, 
	// ou -1 si le pixel ne contient aucun point
	int * _TabPixels;

	int	_MaxPixels;			// Nombre de Pixels maximum autorise
	int	_MinPixels;			// Nombre de Pixels minimum autorise
	int	_MaxPointParPixel;	// Nb points maxi dans un pixel pour le calcul du nombre de pixel

	// Divers pour les statistiques
	// Nombre de points OutSide de la partition
	// Nombre de pixel occupes
	// Nombre moyen de points par pixel

	int _OutSide;
	int _NbPixelOccupe, _NbPointMoyenPixel;
	int _MaxOutSide;


	//Nombre de Pixel en U, V et total
	int _NbPixelU, _NbPixelV, _NbPixels ;
	
	// taille d'un pixel, longueur = largeur = _Pas et son inverse
	double _Pas, _InvPas;
	
	// Taille minimum d'un pixel
	// C'est aussi la distance de recherche maximum, si on veut etre sur d'avoir a parcourir
	// que 9 pixels
	double _TailleMinPixel;
	
	// Boite englobante
	double _UMin, _UMax, _VMin, _VMax;

	
	// Iterateur pour obtenir les voisins potentiels d'un point
	// Le pixel ou se trouve le point
	// Position de l'iterateur dans le tableau de Points
	
	int _PosIterPixel, _PosIterPoint;
	
	// Le point dont on est en train de calculer les voisins
	float _CurPoint[3];
	
	// Rayon de la sphere de recherche des voisins
	// Doit etre inferieur a _TailleMinPixel
	double _SearchRay;
	// Rayon au carre de la sphere de recherche des voisins
	double _SearchRay2;
	
	// Table des voisinages d'un point dans la pixellisation le premier -1 indique la fin, cad le dernier pixel
	int _PixelVoisin[9];
	int _IndexVoisin;

	// Le coefficient de multipliction du nombre de pixels pour chaque CreatePartition
	// A depart il vaut 1 et a chaque passage dans CreatePartition il est * 1.47875 de telle sorte
	// qu'en 10 passages il soit multiplie par 50, le nombre de pixels maximum sera atteint puisque
	// le minimum est 10000 et le maxi 500000 (ratio = 50)

	double _CoefMultPixel;

	// Nombre de requetes au un Next (Pour debug)

	unsigned int _NbReqIter;

/*------------------------------------Methodes internes---------------------------------------------*/

	// Requete pour avoir de la memoire pour la construction de la tables des points et des tables associees
	// iNbPoints	: Le nombre de points a allouer 

	unsigned char RequestMemory(const int iNbPoints);

	// Transformation des coordonnees d'un point dans le systeme interne
	void TransformCoord (const CATMathPoint & iPnt3D,    float oXYZ[3]);
	void TransformCoord (const double         iPnt3D[3], float oXYZ[3]);

	// Mise a jour de la Bounding Box a partir d'un tableau
	void UpdateBoundingBox (const int iNbPoints, const CATMathPoint * iTabPoints);
	void UpdateBoundingBox (const int iNbPoints, const double       * iTabPoints);
	void UpdateBoundingBox (const int iNbPoints, const float        * iTabPoints);

	// Faut'il refaire une pixellisation et si oui, on la lance par le create partition
	// retourne TRUE si la partition a ete refaite

	unsigned char BesoinPartition ();

	// Creation du partitionnement a partir de points deja existant
	// Retour : TRUE si creation OK
	unsigned char CreatePartition ();

	// Gestion memoire - Ajout d'un point dans la table des coordonnees, il n'est pas chaine dans les pixels
	//
	// iPnt3D	: Le point a rajouter dans une table de float
	// oNumero	: Le Numero du point dans la table des points (si negatif ==> Pb)
	// Retour	:  0 ==> OK
	//			   1 ==> Pb d'allocation memoire
	//			   2 ==> Pb de logique, a debugger

	int AddPointInMemory (const float iPnt3D[3], int & oNumero) ;

	// Ajoute le point numero i dans la structure de donnees de la Pixellisation
	// iNumPoint	: Le Numero du point dans la table des points 
	// retourne  0 si OK

	int AddPointToPixel(const int iNumPoint) ;

	
	// A partir des coordonnees U & V d'un point sur la grille, calcul de la position dans la grille
	// Sur option remplit la table des pixels voisins (defaut a FALSE) dans _PixelVoisin
	// iPosu iPosv		: Coordonnees du point dans le 2D
	// oPixel			: Numero de pixel recadre dans la grille [0, NbPixel]
	//
	
	// Retour : TRUE si le point tombe a l'interieur de la grille

	// Pour le numero de pixel k, les voisins de k sont dans la table _PixelVoisin[9] dans l'ordre suivant :
	//
	//					o	o	o				6	7	8		
	//					o	k	o				3	4	5
	//					o	o	o				0	1	2
	//
	// Chaque element contient le numero de pixel, une valeur negative indique qu'il n'y a pas de pixel voisin

	unsigned char GetPositionPixel (const double iPosU, const double iPosV, int & oPixel, const unsigned char iLocateVoisins = FALSE);
		
	// Iterateur sur les voisins potentiels d'un point
	// renvoit le numero du point suivant
	// retourne  0 si OK
	//           1 erreur: la pixellisation n'a pas ete construite correctement ou l'utilisateur n'a pas
	//                     fait de Run() 
	//           2 erreur: si l'utlisateur n'a pas fait de GetIterator()
	//          -1 on a traite tous les points
	int NextPotentiel(int & oNumPoint);

	// Edition de statistiques

	void EditionStatistiques ();

	inline float Distance2PointPoint(const float X[3], const float Y[3]);

};

// -------------------------------------------------------------------------------
// retourne la distance au carre du point X au point Y : ie la norme du vecteur XY
// -------------------------------------------------------------------------------
inline float CATCldPixellisation::Distance2PointPoint(const float X[3], const float Y[3]) {
	return ((X[0]-Y[0])*(X[0]-Y[0])+(X[1]-Y[1])*(X[1]-Y[1])+(X[2]-Y[2])*(X[2]-Y[2]));
}

#endif