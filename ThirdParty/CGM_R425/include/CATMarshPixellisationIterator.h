// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2004
//=============================================================================
//								   
// CATMarshPixelisation :	
/*
	Objectif : Creation d'une structure de donnee 2D sur des points 3D en vue de faire des requetes de proximite.
	           Les point 3D representent dans la majorite des cas la peau d'une surface. C'est cela qui justifie 
			   la methode de pixellisation utilisee

	   Tout a ete realise dans une optique de performance et de simplicite pour l'utilisateur.

	a/ La performance optimum est celle ou l'on peut donner tous les points en une seule fois avant de realiser
		des requetes mais ce n'est pas toujours possible.
	b/ Le cas le plus defavorable est celui ou l'on donne un point apres l'autre apres avoir requete sur son existence 
		dans un rayon donne. 
	c/ On peut ameliorer grandement le cas b/ si l'on peut donner (meme une estimation) la boite englobante avant
		toute adjonction de point.
	d/ Les points peuvent etre ajoutes unitairement, par paquets, la liberte est complete.
	e/ A chaque point ou a chaque paquet de points, un identificateur est rendu permettant de connaitre sa place
		dans la SD. En fait, c'est le numero d'ordre d'apparition de 0 a NbPoints-1
	f/ Il n'est pas necessaire que l'utilisateur conserve les points, il peut toujours les recuperer sur interrogation
		permettant ainsi un gain de place appreciable.

	Au constructeur, on ne donne que la taille maximum des requetes de distance que l'on realisera. Pour l'instant 
	on ne sait pas encore s'en passer.
	
	Donner ensuite :

		o SetBoundingBox				pour la boite englobante si on la connait
		o AddTableOfPointsInPartition	pour une ou plusieurs series de points
		o AddPointInPartition			pour un ou plusieurs points

		On peut panacher comme l'on veut, tout est permis
	
	La principale requete est :
	-------------------------
		A partir des coordonnees d'un point, de connaitre les autres points situes dans une sphere
	de rayon donne. Ce rayon etant inferieur ou egal a la distance passee dans le constructeur.
	La methodologie est la suivante :

		o Initialiser un iterateur avec les coordonnees (ou le numero) de ce point GetIterator(Point, Rayon)
		o Boucler en faisant des Next: while (Pixellisation . Next(Neighbor) == 0) 
					a chaque fois Neighbor contient le numero de point suivant ou -1 si c'est fini

		Rem : On ne peut prendre qu'un seul iterateur a la fois.

	Filtrage des points :
	-------------------

		o Si l'on dispose de tous les points on peut appeler la methode Filtrage pour un rayon donne. 
			Elle renvoie une table de Flags associee aux points contenant TRUE si ce point n'a pas de voisin
			dans la sphere. Configuration optimum en performance. 
			Avec une machine 2.8GHz et 1Go de RAM, sur une entree de 5 M points on filtre 3.3 M points en 8s
			et on est en mode debug
		o Si l'on veut creer la SD sans doublon, il est necessaire de l'interroger sur l'existence du point
			(IfExistePoint) avant de l'ajouter. La SD ne contiendra ainsi que des points sans doublons a une
			distance donnee.


*/
//=============================================================================
//  26/04/2004 : CTJ: Creation (Stagiaire de GDD)
//=============================================================================
//
#ifndef CATMarshPixellisationIterator_h
#define CATMarshPixellisationIterator_h

#include "MathMarsh.h"

#include "CATMathPoint.h"

//#include "CATMarshPixellisation.h"

class CATMarshPixellisation;
//#define CATMarshPixellisation_Double

class ExportedByMathMarsh CATMarshPixellisationIterator
{
public:


/*--------------------------------------Constructeur---------------------------------------------*/

	// Constructeur
	//  Parametres: - iDistanceMax: Distance maximale de recherche des voisins dans les requetes
	//				  Cette valeur determinera la taille minumum d'un pixel. 
	//				  Dans toutes les requetes qui demandent une distance, celle ci ne pourra pas etre 
	//                superieure a iDistanceMax en l'etat actuel des choses.
  //               - iResolution : la resolution de l'espace 

	CATMarshPixellisationIterator(const CATMathPoint &iCurrent,  const double iRayon, CATMarshPixellisation* iPixelisation);

	// Destructeur
	virtual ~CATMarshPixellisationIterator();

  int Update(const CATMathPoint &iCurrent, const double iRayon, CATMarshPixellisation* iPixelisation);

/*------------------------------------------Requetes---------------------------------------------*/

  
  
  // La methodologie se resume a prendre un iterateur (GetIterator) en precisant le point et le rayon 
  // de la sphere d'influence puis d'iterer avec la fonction Next ==> Point suivant

  // Exemple d'utilisation
  // 1. Cree un objet CATMarshPixellisation, par exemple Pixellisation
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

  


  // Iterateur sur les voisins d'un point
  // renvoit le numero du point suivant
  // retourne  0 si OK
  //           1 erreur: la pixellisation n'a pas ete construite correctement
  //           2 erreur: si l'utlisateur n'a pas fait de GetIterator()
  //          -1 on a traite tous les points
  int Next(int & oNumPoint);

  CATBoolean IsOK() const { return _IsOK; }


private:
 
	
  CATMarshPixellisation * _pPixelisation;
	
	// Le point dont on est en train de calculer les voisins
	double _CurPoint[3];
	
	// Rayon de la sphere de recherche des voisins
	// Doit etre inferieur a _TailleMinPixel
	double _SearchRay;
	// Rayon au carre de la sphere de recherche des voisins
	double _SearchRay2;
	
	// Table des voisinages d'un point dans la pixellisation le premier -1 indique la fin, cad le dernier pixel
	int _PixelVoisin[9];
	int _IndexVoisin;

  // Iterateur pour obtenir les voisins potentiels d'un point
  // Le pixel ou se trouve le point
  // Position de l'iterateur dans le tableau de Points

  int _PosIterPixel, _PosIterPoint;
  CATBoolean _IsOK;


	CATBoolean GetPositionPixel (const double iPosU, const double iPosV, int & oPixel, const CATBoolean iLocateVoisins = FALSE);
		
	// Iterateur sur les voisins potentiels d'un point
	// renvoit le numero du point suivant
	// retourne  0 si OK
	//           1 erreur: la pixellisation n'a pas ete construite correctement ou l'utilisateur n'a pas
	//                     fait de Run() 
	//           2 erreur: si l'utlisateur n'a pas fait de GetIterator()
	//          -1 on a traite tous les points
	int NextPotentiel(int & oNumPoint);

  int InitIterator();

  inline double Distance2PointPoint(const double X[3], const double Y[3]);

};

// -------------------------------------------------------------------------------
// retourne la distance au carre du point X au point Y : ie la norme du vecteur XY
// -------------------------------------------------------------------------------
inline double CATMarshPixellisationIterator::Distance2PointPoint(const double X[3], const double Y[3]) {
	return ((X[0]-Y[0])*(X[0]-Y[0])+(X[1]-Y[1])*(X[1]-Y[1])+(X[2]-Y[2])*(X[2]-Y[2]));
}

#endif
