/* -*-C++-*-*/
#ifndef CATTessSettings_H
#define CATTessSettings_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  1997
// CATTessSettings
/** Settings for the tessellation
  */
//
//=============================================================================
//
// Dec. 1997 JCH Creation            
// Oct. 1999 HKL Gestion d'une sag curve et d'une sag surface
// Dec. 1999 TPD Nombres Isopares en U et V pour "CalIso"
// Sep. 2000 TPD On veut des POL avec ou sans (conique) PLL
// Jan. 2001 TPD Gestion des erreurs : arret du traitement "StopError"
// Avr. 2001 TPD Suppression des barres trop petites "StepMin"
// Fev. 2003 TPD Refonte du CATTessSettings et ajout de "Wysiwyg"
// Mars 2003 TPD On limite l'MaxAngle entre MaxAngleMin et MaxAngleMax de CATTessSettings
// Mars 2004 TPD On active Dortor = 1 ( calcul Tangeantes ) tout le temps
// Oct. 2004 TPD Nouvelle sortie : "Polyedre"
// Nov. 2004 TPD Sortie sans stripe et sans fan ( Doctor = 2 ) (RI464528)
// Oct. 2005 TPD On veut "regulariser" les triangles ( Doctor = 8 ) (RI507524)
// Jan. 2006 TPD On veut trianguler avec PP2D ( Doctor = 16 ) ( usage interne uniquement )
// Mars 2006 TPD On veut activer Tess_0002 et Tess_0003 avec Doctor = 32
//
//=============================================================================

// For Windows NT
#include "TessAPI.h"

// Includes pour le debug
// 
//  #include "CATTessDebug.h"
// 

#include <stddef.h>
#include "CATCGMNewArray.h"
#include "CATDataType.h"
#include "CATMathDef.h"
#include "CATMathDebug.h"
#include "CATLib.h"

#include "CATMathLimits.h"
#include "CATMathConstant.h"
 
#include "CATTessOutputMode.h"
 
#ifndef CATTessFrameworkCaller
#define CATTessFrameworkCallerExpansed(x) #x
#define CATTessFrameworkCaller(x)  CATTessFrameworkCallerExpansed(x)
#endif


/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif


class CATBaseUnknown;
class CATech_CATTessSettingsExt;
class CATechExt;
class CATTessParameters;
class CATTessOperator;

class ExportedByTessAPI CATTessSettings
{
public:

  //=============================================================================
  // Constructors 
  //=============================================================================

  /**
   * Constructor with the sag and the step and the angle, with default values for step and angle
   * iCalIsopare = 0 : Sorties pour la VISU des    TRIANGLES et pas d'Isopares
   *             = 1 : Sorties pour la VISU des    TRIANGLES et   des Isopares
   *             = 2 : Sorties pour la VISU pas de TRIANGLES et   des Isopares
   * iNbIsoU, iNbIsoV : Nombre d'isopares en U et V ( actif si iCalIsopare = 1 ou 2 )
   */
  CATTessSettings(double      iSag,
				  		    double      iStep       = ( double ) CATMathInfinite,
		  		    	  double      iMaxAngle   = ( double ) ( CATPI * 0.25 ),
		  		    	  CATLONG32  iCalIsopare = 0,
		  		    	  CATLONG32  iNbIsoU     = 2,
		  		    	  CATLONG32  iNbIsoV     = 3,
                  const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_)  );

  /**
   *  Copy Constructor
   */
  CATTessSettings(const CATTessSettings & iSettings);
  
  /**
  * Copy Settings
  */
  CATTessSettings& operator=(const CATTessSettings &iCopySettings);

  /**
   *  Destructor
   */
  ~CATTessSettings();

  //=============================================================================
  // Methods
  //=============================================================================
  /**
   * Sets the max angle
   */
  void SetMaxAngle(double iMaxAngle);

  /**
   * Get the max angle
   */
  double GetMaxAngle() const;
  
  /**
   * Sets the sag
   */
  void SetSag(double iSag);
  void SetSag1D(double iSag1D);
  void SetSag2D(double iSag2D);
  void SetTargetSagForMesh0(double iTargetSagForMesh0);
  void SetTargetRefinementLevelForMesh0(int iTargetRefinementLevelForMesh0);

  void SetScale(double iScale);
  double GetScale() const;

  /**
   * Get the sag
   */
  double GetSag() const;
  double GetSag1D() const;
  double GetSag2D() const;
  double GetTargetSagForMesh0() const;
  int   GetTargetRefinementLevelForMesh0() const;

  /**
   * Sets the step. This method implicitly activates the Step criterion for the 
   * tessellation.
   */
  void SetStep(double iStep);
  
  /**
   * Disactivates the step criterion
   */
  void DisactivateStep();
  
  /**
   * Get the step
   */
  double GetStep() const;

  /** 
   * Returns 1 is the step criterion is active
   */
  CATBoolean IsStepActive() const;
  
  /**
   * Sets the StepMin
   * ( Longueur minimum des barres, On peut ne plus respecter les autres criteres SAG, .. )
   * This method implicitly activates the StepMin criterion for the tessellation.
   */
  void SetStepMin( double iStepMin );
  
  /**
   * Disactivates the StepMin criterion
   */
  void DisactivateStepMin();
  
  /**
   * Get the StepMin
   */
  double GetStepMin() const;

  /** 
   * Returns 1 is the StepMin criterion is active
   */
  CATBoolean IsStepMinActive() const;

  /**
   * Sets the threshold of triangles used to consider the tessellation of a body as dangerous or not.
   */
  void SetTrianglesThreshold(unsigned int);

  /**
   * Returns the threshold of triangles used to consider the tessellation of a body as dangerous or not.
   */
  unsigned int GetTrianglesThreshold() const;

	/**  Regularize Option
	* 0 : standard, no regularization
  * 1 : Pour  OPTIMIZE_MESH_FOR_TEXTURING
  *     On calcule un critere de Step en fonction de la Sag
  * 2 : On gere la discretisation en U et en V pour un meilleur ShapeFactor des triangles
  *     La complexité des contours est tenu en compte pour la discrétisation à l’intérieur de la face.
  *     Un ratio est imposé entre le pas en U et le pas en V à chaque point pour éviter les triangles allongés, mais pas de régularité globale. 
  * 3 : discrétisation régulière dichotomique pour une continuité des isolines entre les faces (critère du tessellateur RTT)
  * 4 : discrétisation régulière uniforme type tessellation V4
  *      Tessellation avec une grille uniforme, la dimension de la grille 
  *     est conditionnée par le point de plus forte courbure. La tessellation peut donc être dense, c’est semblable à la tessellation V4 
  *     réclamée par BMW pour leur appli Analyse de Surfaces.
  * 5 : discrétisation régulière non uniforme 
  *     Tessellation avec une grille variable, les pas sont estimés à partir du point courant 
  *     en commençant par le début du bloc limitation de la face. Cette discrétisation est utilisée dans Machining et semblable à la tessellation de RTT
	*/
	void SetTessRegularize(CATLONG32 iRegularizeOption);
	CATLONG32 GetTessRegularize() const;

  /**  Adaptive Quality Option
* 0 : standard, no Adaptive Quality
*/
  void SetTessAdaptiveQuality(CATLONG32 iAdaptiveQualityOption);
  CATLONG32 GetTessAdaptiveQuality() const;

  /**
    * Set du Type de sortie
    * iTypeSortie = 0 : VISU
    *             = 1 : HLR
    *             = 2 : Polyedre
    */
  void SetTypeSortie( CATLONG32 iTypeSortie );

  CATBoolean IsPP2DPossible();
  /*
  TemporaryActiveNewModeWithVersionning : Consists in setting the NouvoMode as it
  can be done by set TESS_NEWCONFIG=1  see Info.cpp.
  This method will be removed as soon as the new behaviour is introduced V5R23SP...
  */
  void TemporaryActiveNewModeWithVersionning();
  void DesactiveNewModeWithVersionning();
  /**
    * Get du Type de sortie
    */
  CATLONG32 GetTypeSortie() const;
  
  /**
   * Sets the Calcul des Isopares
   * iCalIsopare = 0 : Sorties pour la VISU des    TRIANGLES et pas d'Isopares
   *             = 1 : Sorties pour la VISU des    TRIANGLES et   des Isopares
   *             = 2 : Sorties pour la VISU pas de TRIANGLES et   des Isopares
   *             = 3 : Sorties pour le HLR avec Pll
   *             = 4 : Sorties pour le HLR sans Pll
   */
  void SetCalIsopare(CATLONG32 iCalIsopare);

  /**
   * Get the Calcul des Isopares
   */
  CATLONG32 GetCalIsopare() const;
  
  /**
   * Sets du nombre d'Isopares en U
   */
  void SetNbIsoU(CATLONG32 iNbIsoU);
  
  /**
   * Get du nombre d'Isopares en U
   */
  CATLONG32 GetNbIsoU() const;

  /**
   * Sets du nombre d'Isopares en V
   */
  void SetNbIsoV(CATLONG32 iNbIsoV);

  /**
   * Get du nombre d'Isopares en V
   */
  CATLONG32 GetNbIsoV() const;

  /**
   * Get des Parametres pour le HLR
   */
  CATLONG32 GetParamHlr() const;

  /**
   * Set des Parametres pour le HLR
   * iParamHlr = 0 : On veut les Pll
   *           = 1 : On ne veut pas de Pll
   */
  void SetParamHlr(CATLONG32 iParamHlr);

  /**
   * Set de StopError
   * iStopError = 0 : si on trouve une erreur on continue le maillage de la face
   *            = 1 : en cas d'erreur on arrete le maillage de la face, mais on maille les autres
   */
  void SetStopError( CATLONG32 iStopError );

  /**
   * Get de StopError
   */
  CATLONG32 GetStopError() const;

  /**
   * Get du WYSIWYG pour la VISU
   */
  CATLONG32 GetWysiwyg() const;

  /**
    * Veut-on un calcul WYSIWYG
    * iWysiwyg = 0 : non
    *          = 1 : pour le lineique
    *          = 2 : pour le surfacique et lineique
    */
  void SetWysiwyg(CATLONG32 iWysiwyg);

  /**
  * WTTessellation
  */

  /**
  * Get du param
  */
  CATLONG32 GetWTTMode() const;

  /*
  * Set du param
  **/
  void SetWTTMode(CATLONG32 iWTTMode);
  
    /**
   * Get du "Doctor"
   */
  CATLONG32 GetDoctor() const;

  /**
   * Aide au maillage
   *     =  0 : On ne fait rien
   *     +  1 : On veut generer les Isopares des surfaces ( Create Surfaces Points ) dans l'atelier Maillage de NCGM
   *     +  2 : On genere uniquement des triangles en sorties ( pas de stripe ni de fan )
   *     +  4 : ExtrapolatedSurfaceMode: tenir compte de l'extrapolation eventuelle des surfaces
   *     +  8 : Post traitement pour "regulariser" les triangles
   *     + 16 : On veut trianguler avec PP2D ( usage interne uniquement )
   *     + 32 : On veut activer Tess_0002 et Tess_0003 pour RR TEMPORAIREMENT
   *     + 64 : For quality management and complexity matrix management (IR IR592501_Unfold : symptome Self-Intersecting)
   *     + 128 : TEMPORARY SETTING IN ORDER TO UNACTIVATE VERSIONNING VARIABLES
   * Rq : pour chaque appel on ajoute la valeur
   */
  void SetDoctor(CATLONG32 iDortoc);


  void UnsetDoctor(CATLONG32 iDortoc);
  /**
   * Remise a 0 du "Doctor"
   */
  void ResetDoctor();

  /**
   * Sets du nombre  Maximum de Points par isopares en U et en V
   */
  void SetNbPtsIsoMax( CATLONG32 iNbPtsIsoMaxU, CATLONG32 iNbPtsIsoMaxV );

  /**
   * Get du nombre Maximum de Points par isopares en U et en V
   */
  void GetNbPtsIsoMax( CATLONG32 & oNbPtsIsoMaxU, CATLONG32 & oNbPtsIsoMaxV ) const;

  /**
    * Get du Numero de Version
    */
  CATLONG32 GetNuVersion() const;

  /**
   * Get the tessellation output mode.
   */
  CATTessOutputMode GetOutputMode() const;

  /**
   * Get the tessellation output mode. See definition of enum for
   * details about the modes.
   */
  void SetOutputMode(CATTessOutputMode iMode);
 
  /**
   * Dump of the class CATTessBarre in a stream, with a debug level
   * ( 1 by default)
   */
  void DumpStream(ostream & iStream, CATLONG32 iDepth, CATLONG32 iSpace) const;

  /** Dumps the object in the standard output
   *      iDepth = 1 : Dump du Settings
   */
  void Dump(CATLONG32 iDepth = 1, CATLONG32 iSpace = 0) const;
 
   //=============================================================================
  //  
  //=============================================================================
  static double GetDefaultMaxAngleMax();
  static double GetDefaultMaxAngleMin();
 
  static const double DefaultMaxAngle;
  static const double DefaultStep;

  inline CATTessParameters * GetTessParameters();

  //=============================================================================
  // INTERNAL DATAS
  //=============================================================================
protected:
 

  /** Manage Hidden implementation .
  */
  CATTessParameters *   _MyTessParameters ;

  friend class CATTessParameters;
  friend class CATTessOperator;

};
  
//=============================================================================
// inline
//=============================================================================
inline CATTessParameters * CATTessSettings::GetTessParameters()
{  return _MyTessParameters; }

#endif
