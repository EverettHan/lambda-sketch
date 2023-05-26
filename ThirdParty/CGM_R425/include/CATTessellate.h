/* -*-C++-*-*/
#ifndef CATTessellate_H
#define CATTessellate_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  1997
// CATTessellate
/** Tessellation operator
  * To use this operator you need to:
  * 1) instanciate a CATTessSettings object that contains
  *    your Sag, Step and MaxAngle settings
  * 2) instanciate a CATTessellate object for a given CATBody
  * 3) run the operator
  * 4) instanciate an object derived from CATTessStore and use it to get the results
  * You can reuse the same operator for several bodies with the SetBody method
  */
//
//=============================================================================
// Dec. 97  Jose CHILLAN (jch)    Creation            
// Avr. 99  Herve KABLA (hkl)     Tessellation de courbes et surfaces isolees
// Oct. 2002 TPD on modifie la valeur minimale de la SAG : methode "PetiteSag"
// Jan. 2003 TPD On cree un "CATTessellateV4" pour mailler les elements V4
// Mars 2004 TPD On chaine les Points Bords de faces entre eux par les CATTessPoints correspondants
// Juil 2004 TPD mise en place de "Stat" pour la CPU
// Oct. 2004 TPD Nouvelle sortie : "Polyedre"
// Jan. 2005 TPD Nouvelle gestion du MemoryManager Temporaiare (RI489565)
// Mai. 2005 CHU par delegation: Ajout d'un body de reference pour orienter les faces issues de CATCellTessellator (ri 488827) monocode 
// Mars 2006 TPD Creation de "ImpactConfig"
// Mars 2006 TPG External Discretization Function
// Juin 2006 TPG External Flip Bar Function
//=============================================================================


//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "TessAPI.h"
//#define CATTESSCPU
//=============================================================================
// Other includes
//-----------------------------------------------------------------------------
// 

/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif
#include "CATCGMNewArray.h"
#include "CATDataType.h"

#include "CATTessDiagnostic.h"
#include "CATTessSettings.h"
#include "CATTessOutputMode.h"
#include "CATTessIncrMode.h"

// Pour CATLISTP(xxx)
#include "CATCollec.h"
#include "CATCGMNewArray.h"

#include "CATCrvLimits.h"
#include "CATMathSetOfPointsND.h"

#include "CATListOfCATICGMObjects.h"


//=============================================================================
// Forward declarations
//-----------------------------------------------------------------------------

class CATTessOperator;
class CATTessStore;
class CATTessToleranceSet;
class CATTessInCell;
class CATBaseUnknown;
class CATTessContainer;

class CATBody;
class CATCrvLimits;
class CATCrvParam;
class CATCurve;
class CATEdge;
class CATFace;
class CATSurface;
class CATSurLimits;
class CATSurParam;
class CATVertex;
class CATSoftwareConfiguration;

class CATLISTP(CATCrvParam);
class CATLISTP(CATEdge);
class CATLISTP(CATFace);
class CATLISTP(CATGeometry);
class CATLISTP(CATSurParam);

class CATech_CATTessellateExt;
class CATechExt;
class CATCellHashTable;
class CATTessCurveDiscretizer;
class CATTessSurfaceDiscretizer;
class CATTessSurfaceRegularizer;

class CATTessFaceQueryInterface;
class CATTessEdgeQueryInterface;

class ExportedByTessAPI CATTessellate
{
public:
  //=============================================================================
  // Constructors and desctructor
  //=============================================================================
  /**
   *  Constructor
   *  iConfig = 0 : running without configuration ( the lastest coding configuration is active )
   */
  CATTessellate(CATBody * iBody,
                CATTessSettings * iSettings, 
                CATSoftwareConfiguration * iConfig = 0,
                const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_)  );
  
  /**
   *  Destructor
   */
  virtual ~CATTessellate();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;

  //=============================================================================
  // Methods
  //=============================================================================
  /** Changing the body to tessellate
   */
  void SetBody(CATBody * iBody);

  /** Changing the Polyedron to tessellate
   */
  void SetPoly(CATTessInCell * iPoly);

  /** Changing the step
   */
  void SetStep(double iStep);

  /** Changing the tessellation output format
   */
  void SetOutputMode(CATTessOutputMode iMode);

  /** Changing the incremental tessellation mode
   */
  void SetIncrMode(CATTessIncrMode iMode);

  /** Adds geometry to tessellate
   */
  void AddCurve(CATCurve * iCurve, const CATCrvLimits & iLimits);
  void AddSurface(CATSurface * iSurface, const CATSurLimits & iLimits);

  /** Adds cell to tessellate
   */
  void AddEdge(CATEdge * iEdge);
  void AddFace(CATFace * iFace);
  
  /** Add edge whose tessellation is already known. Provide information
   *  about the known tessellation using CATTessEdgeQueryInterface
   *  This method is valid only when the incremental tessellation mode is either
   *  CATTessIncrModeNoPropagation or CATTessIncrModeNoPropagationDegenTriangles.
   *  Note that CATTessellate will own the CATTessEdgeQueryInterface object 
   *  being passed here (i.e. it will be deleted by CATTessellate)
   */
  void AddEdgeKnown(CATEdge* iEdge, CATTessEdgeQueryInterface* iKnownEdgeTessellation);

  /** Add face whose tessellation is already known. Provide information
   *  about the known tessellation using CATTessFaceQueryInterface
   *  This method is valid only when the incremental tessellation mode
   *  is CATTessIncrModePropagation.
   *  Note that CATTessellate will own the CATTessFaceQueryInterface object 
   *  being passed here (i.e. it will be deleted by CATTessellate)
   */
  void AddFaceKnown(CATFace * iFace, CATTessFaceQueryInterface* iKnownFaceTessellation);

  /** Sets the dimension of cells to tessellate, 0 < iDimension < 2
   */
  void SetMaxDim(CATLONG32 iDimension);

  /** Computes the tesselation
   */
  virtual CATTessDiagnostic Run(CATTessStore &iStorage);
  CATTessDiagnostic RunPoly(CATTessStore &iStorage);
  
  /** Retrieves result for each CATVertex
   */
  virtual CATTessDiagnostic GetVertices(CATTessStore &iStorage);
  virtual CATTessDiagnostic GetVertex(CATVertex * iVertex, CATTessStore &iStorage);

  /** Retrieves result for each CATEdge
   */
  virtual CATTessDiagnostic GetEdges(CATTessStore &iStorage);
  virtual CATTessDiagnostic GetEdge (CATEdge * iEdge, CATTessStore &iStorage);

  /** Retrieves result for each CATFace
   */
  virtual CATTessDiagnostic GetFaces(CATTessStore &iStorage);
  virtual CATTessDiagnostic GetFace (CATFace * iFace, CATTessStore &iStorage);

  /** Retrieves result Points for the Body ( Only for Polyhedron Outputw )
   */
  CATTessDiagnostic GetPoints(CATTessStore &iStorage);

  // INTERNAL USE ONLY
  // Retrieves result for each CATSurface

  CATTessDiagnostic GetSurfaces(CATTessStore &iStorage);

  /*
   * permet de descendre la SAG sous la resolution
   */
  void PetiteSag();

  // Retrieves result for each CATSurface
  CATTessDiagnostic GetLastResultOfRun();
 
 
  void SetAgregatingBodyForIndividualFaces(CATBody * iAgregatingBody);


/** Provide external function to:
 *  compute the discretization of curve
 *  oSetOfPoints is created by the external function and will be deleted inside the tessellation operator
 */
  void SetExternalDiscretizationFunction (int (*iExternalDiscretization) (void * iContext, const CATCurve *iCurve, const CATCrvLimits &iLimits,
																		  CATMathSetOfPointsND * &oSetOfPoints),
										  void * iContext);
/** Provide external function to:
 *  compute the discretization of surface
 *  oWIsopar and oSetOfPoints are created by the external function and will be deleted inside the tessellation operator
 */
  void SetExternalSurfaceDiscretizationFunction (int (*iExternalSurfaceDiscretization) (void * iContext, const CATSurface * iSurface, const CATSurLimits &iLimits, 
																						int iIsoparDir,  // 1: IsoparU  -  2: IsoparV
																						CATMathSetOfPointsND * &oWIsopar, CATMathSetOfPointsND ** &oTabIsopar),																			
												 void * iContext);
/** Provide external function to:
 *  flip the bar between two adjacent triangles according to an external criteria
 *  to use with SetDoctor(10) on CATTessSettings
 *
 *
 *               1                    1
 *              / \                  /|\
 *             /   \                / | \
 *            / T1  \              /  |  \
 *           /       \            /   |   \
 *          2---------4          2 T3 | T4 4
 *           \  T2   /            \   |   /
 *            \     /              \  |  /
 *             \   /                \ | /
 *              \ /                  \|/
 *               3                    3
 *
 *     return    0                    1
 *
 *  iSurface: support surface
 *  iPoints[12]: point1 -> point4
 *  iNormals[12]: normal1 -> normal4
 *  iuv[8]: uv1 -> uv4 for optimization purpose
 *  return 0: no flip edge required - 1: flip edge required 
 */
  void SetExternalFlipBarFunction (int (*iExternalFlipBarFunction) (void * iContext, CATSurface *iSurface, double *iPoints, double *iNormals, double *iuv), void * iContext);

  void SetExternalCurveDiscretizer(CATTessCurveDiscretizer* iCurveDiscretizer);
  void SetExternalSurfaceDiscretizer(CATTessSurfaceDiscretizer* iSurfaceDiscretizer);
  void SetExternalSurfaceRegularizer(CATTessSurfaceRegularizer* iSurfaceRegularizer);

/**  Regularize Option
	*/
	void SetTessRegularize(int iRegularizeOption, double * iRegularizeParams = 0);

  /**  Adaptive quality Option
    */
  void SetTessAdaptiveQuality(int iAdaptiveQualityOption);

  //=============================================================================
  // ExcludedCellsForDoYouNeed (..)     Available
  //=============================================================================

  void       SetExcludedCellsForDoYouNeed( const  CATLISTP(CATICGMObject) &  iCATICGMObjects );

  void       GetExcludedCellsForDoYouNeed( CATLISTP(CATICGMObject) &  oCATICGMObjects );

  void       UnsetExcludedCellsForDoYouNeed();

  CATBoolean IsExcludedCellsForDoYouNeed();

  //=============================================================================
  // Local Tessellation integration
  //=============================================================================
  // For Local Tessellation : cache TessEdge
  void ResetForLocalTessellation();  

  //=============================================================================
  // Phoenix integration (smart extended extension)
  //=============================================================================

  // For Phoenix Tools : a Phoenix pattern
  void SetPhoenixExtension(CATechExt *iExtension, CATBoolean iDeleteCATTessellate = FALSE );

  // For Phoenix Tools : a Phoenix pattern
  //   DO NOT RELEASE returned value
  CATBaseUnknown * HasPhoenixExtension( CATBoolean iForceCreation = FALSE );

  inline CATTessOperator * GetTessOperator();

#ifdef CATTESSCPU
  // Stat pour la Cpu
  double const * GetResultCpu();
#endif


  //=============================================================================
  // INTERNAL METHODS
  //=============================================================================
protected:

  void ReInit(CATBody * iBody);
  void ReInit(CATFace * iFace);
  void ReInit(CATEdge * iEdge);
  //=============================================================================
  // for CATTessellateV4
  //=============================================================================
  CATBody                * GetBody();

  CATTessToleranceSet    * GetTolerances();
  void                     SetTolerances(CATTessToleranceSet    *iNewTolerances);

  CATTessSettings        & GetSettings();

  CATTessContainer       * GetBigBox();
  void                     SetBigBox(CATTessContainer    *iBigBox);

  inline  CATBoolean      IsObjAllReadySet() const;

  /** Discretizes all the vertices.
  */
  CATTessOperator *   _MyTessOperator;

  CATBoolean          _ObjSet;

  friend class CATTessOperator;
  friend class CATTessOperatorForPoly;

  //=============================================================================
  // AVOID constructor-by-copy  or  ..
  //=============================================================================
  CATTessellate (const CATTessellate &);          
  CATTessellate& operator=(const CATTessellate&);  

};


//=============================================================================
// inline
//=============================================================================
inline CATTessOperator * CATTessellate::GetTessOperator()
{  return _MyTessOperator; }

inline CATBoolean CATTessellate::IsObjAllReadySet() const
{
  return _ObjSet;
}

#endif
