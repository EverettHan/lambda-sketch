#ifndef CATRectangularSurfRep_h
#define CATRectangularSurfRep_h

// COPYRIGHT DASSAULT SYSTEMES 1999

// Classe qui sert a construire des faces rectangulaires (initialement, 
//  des faces d'une skin extrapolee d'une autre skin), mais pensee pour
//  etre eventuellement reutilisable.

#include "Primitives.h"
#include "CATListOfCATGeometries.h"
#include "CATCGMJournal.h"

class CATCGMJournalList;
class CATTopData;
class CATGeoFactory;
class CATBody;
class CATGeometry;
class CATSurface;
class CATCell;
class CATFace;
class CATEdge;
class CATVertex;
class CATRectangularSideData;
class CATSurParam;

class ExportedByPrimitives CATRectangularSurfRep 
{

public:

  enum CATRectangularSurfSide { RectangularBottomSide, RectangularLeftSide, 
                                RectangularTopSide, RectangularRightSide };

  // Constructeur.
  CATRectangularSurfRep( CATBody           * iResultBody,
                         CATSurface        * iSurface, 
                         CATTopData        * iTopData );
  virtual ~CATRectangularSurfRep();

  // Ajoute un element a la liste des elements de construction, pour un cote
  // donne. 
  void AddSideData( CATRectangularSurfSide  iSide,
                    CATEdge               * iEdge, 
                    int                     iOrientation,
                    CATLISTP(CATGeometry) & iInitGeometries,
                    short                   iAdditionalInfo = 0);

  void SetSideData( CATRectangularSurfSide   iLocation,
                    CATRectangularSideData * iNewSideData );

  // Recupere les objets de construction (au sens journal topologique) neces-
  // saires a un cote.
  void GetConstructionObjects( CATRectangularSurfSide  iLocation,
                               CATLISTP(CATGeometry) & oInitGeometries );
  // Lance le calcul.
  void RunForEdges();
  void RunForFace();

  // Recupere le resultat
  void GetResult( CATFace * & oFace );

  // Decoupe une surf-rep en deux (l'une est reutilisee, l'autre est creee
  // et passee en argument).
  void  SplitInTwo( CATRectangularSurfRep * & oNewSurfRep );

  // Decoupe une surf-rep en deux a une edge donnee (elle est specifiee sur
  // le cote Bottom).
  void  SplitInTwoAt( short iNumEdge, CATRectangularSurfRep * & oNewSurfRep );
  void  ComputeSurParamForSplitCurve( CATEdge     * edge, 
                                      int           edgeOrientation, 
                                      CATSurParam & oSurParam,
                                      CATVertex * & oVertexAtMiddle );

  // Determine ou on doit couper (a base de calculs de longueurs d'edges)
  short CalcSplitLocation();

  // Verification de l'integrite des donnees
  void Check();

  // Remplit le journal topologique correspondant a la creation de la face
  void FillInJournalForFace();

  // Remplit le journal topologique correspondant a la creation des edges
  void FillInJournalForEdges();

	// Active l'enregitrenment des infos provenant du cote iside ( 0 a 3 )
	// par defaut seules les infos du cote 0 sont inscrites.
	void ActivInfoFromSide(int iside); 

	// Set ExtruderMode :: Pourune utilisation avec le sweep
	void SetExtruderMode();

private :

  // Recupere un sidedata donne
  void GetSideData( short iNumSide, CATRectangularSideData * & oSideData );

  // Utilitaire pour remplir le journal topologique
  void AddJournalItem( CATCGMJournalList     * iJournal,
                       CATLISTP(CATGeometry) & iOriginCellsList, 
											 CATCell               * iCellCreated,
											 CATCGMJournal::Type     iJournalType,
											 short                   iNumber );

  // Conversion un side en short (de 0 a 3)
  static short ConvertLocationToShort( CATRectangularSurfSide iLocation );

  // Dump
//  void Dump();

  CATBody                * _ResultBody;
  CATGeoFactory          * _Factory;
  CATSurface             * _Surface;
  CATRectangularSideData * _SideData[4];
	CATBoolean							 _InfoFromSide[4];
  CATCGMJournalList      * _Journal;
  CATFace                * _Face;
	int                      _ExtruderMode;
  CATTopData             * _topData;
};

#endif
