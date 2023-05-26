#ifndef TopologicalUtilities_H
#define TopologicalUtilities_H


// COPYRIGHT DASSAULT SYSTEMES 1999


//============================================================================
// 15/04/19 NLD Reception de la configuration dans EvalLocalAngle()
// 08/07/19 NLD Reception de la configuration dans CreateBodyMonoShellMonoFace()
// 04/10/19 DPS Add EvalTopoAreaOrientation() function
//============================================================================
#include "ParallelUtilities.h"
#include "CreateBorder.h"
#include "EvalAndDebug.h"
#include "CheckSkin.h"
#include "EvalConvexityAndSharpness.h"
#include "CATMathDef.h"
#include "GeometricUtilities.h"
#include "CATCell.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATBody.h"
#include "CATListOfInt.h"
#include "CATListOfCATSurParams.h"
#include "CATListOfCATGeometries.h"
#include "GeometricUtilities.h"
#include "CATDynValidShell.h"
#include "CATIsoParameter.h"

#include "TopoUtilitiesForLight.h"

#include "RibbonLight.h"
#include "CATErrorDef.h" // HRESULT

class CATGeoFactory;
class CATCurve;
class CATEdgeCurve;
class CATPoint;
class CATPointOnCurve;
class CATPointOnEdgeCurve;
class CATPointOnSurface;
class CATCGMJournalList;
class CATSoftwareConfiguration;
class CATTopData;

class CATTopology;
class CATBody;
class CATDomain;
class CATVertex;
class CATEdge;
class CATLoop;
class CATFace;
class CATShell;
class CATWire;

class CATSurParam;
class CATCrvParam;
class CATPCurve;
class CATMathVector;
class CATMathDirection;
class CATMathAdvancedBox;
class CATTopologicalOperator;
class CATRibTopOp;
class CATMacroPoint;
class CATListOfCATPointOnEdgeCurves;

#include "TopologicalBasic.h"


//----------------------------------------------------------------------------
// Creation d'un Body mono-wire-mono-edge
// a partir d'une edge, et eventuellement du body s'il existe deja
//----------------------------------------------------------------------------
ExportedByRibbonLight CATBody* CreateBodyMonoWireMonoEdge(CATEdge* iEdge, CATGeoFactory* iGeoFactory, CATBody* iBody=NULL, const CATBoolean iDuplicate=FALSE);

//----------------------------------------------------------------------------
// Creation d'un Body mono-shell
// a partir d'un shell, et eventuellement du body s'il existe deja
//----------------------------------------------------------------------------
ExportedByRibbonLight CATBody * CreateBodyMonoShell(CATShell * iShell, CATGeoFactory *iGeoFactory, CATBody * iBody=NULL);

//----------------------------------------------------------------------------
// Creation d'un Body mono-shell-mono-face
// a partir d'une face, et eventuellement du body s'il existe deja
//----------------------------------------------------------------------------CreateBodyMonoShellMonoFace1
ExportedByRibbonLight CATBody* CreateBodyMonoShellMonoFace(      CATFace      * iFace       ,
                                                                 CATGeoFactory* iGeoFactory ,
                                                                 CATBody      * iBody       = NULL  ,
                                                           const CATBoolean     iDuplicate  = FALSE);

//----------------------------------------------------------------------------
// Creation d'un Body mono-shell-mono-face
// a partir d'une face, et eventuellement du body s'il existe deja
// Deuxieme signature avec arguments plus complets et reordonnés
// N.B Migrer de manière versionner vers la transmission de la configuration
//     NLD080719
//----------------------------------------------------------------------------CreateBodyMonoShellMonoFace2
ExportedByRibbonLight CATBody* CreateBodyMonoShellMonoFace(      CATGeoFactory           * iGeoFactory ,
                                                                 CATSoftwareConfiguration* iConfig     ,
                                                                 CATFace                 * iFace       ,
                                                                 CATBody                 * iBody       = NULL  ,
                                                           const CATBoolean                iDuplicate  = FALSE);

//------------------------------------------------------------------------------
// Get the uv bounding box of an edge on a face
//------------------------------------------------------------------------------
ExportedByRibbonLight void Get2DBoundingBox (CATSoftwareConfiguration * iConfig,
                                             CATEdge                  * iEdge,
                                             CATFace                  * iFace,
                                             CATSurLimits             & o2DBoundingBoxForEdge,
                                             CATVertex                * iStart=NULL, CATVertex *iEnd=NULL);

//------------------------------------------------------------------------------
// Get the CrvLimits of an Edge
// If iCurve, oLimits is related to this Curve, otherwise, it is related to the underlying EdgeCurve. 
//------------------------------------------------------------------------------
ExportedByRibbonLight void GetLimits(CATEdge* iEdge, CATCrvLimits &oLimits, CATCurve* iCurve=NULL) ;

//-----------------------------------------------------------------------------
// Compare the orientation of a shell or a face with a given direction
//-----------------------------------------------------------------------------
ExportedByRibbonLight CATTopSign GetRelativeOrient (CATFace          *iFace,
                                                    CATMathDirection &iDirection,
                                                    CATOrientation    iOrientation  = CATOrientationPositive,
                                                    CATShell         *iShell        = NULL,
                                                    CATBody          *iBody         = NULL,
                                                    CATVertex        *iVertexOnFace = NULL,
                                                    CATEdge          *iEdgeOnFace   = NULL,
                                                    double           iTol = 0.);

/**
* EvalTopoAreaOrientation() function
* The main purpose of this function consists in guessing the global orientation of a topological object in regards with a given direction.
* This function will compute signed areas from the boundary of the object and won't depend on any local evaluation of normal, 
* avoiding this way many unstabilities due to the randomly choice of one reference point from the topological object.
* The caller is supposed to use this service for open surfacic bodies, faces or closed wire bodies (according to the 'turns left' convention), 
* defining a closed area from their boundaries unfold in a mathematical plane (whose the normal is the input direction)
* In case of conflict between positive and negative areas, the biggest one will give its sign to the returned orientation.
* In case of perfect balance between negative and positive areas, or if no area can be computed (vertical face asking its orientation in Z direction),
* the output orientation will be CATOrientationUnknown !
* This service is available for both exact and polyhedral objects.
* @param iConfig
* The pointer to the software configuration driving the versionning of code modifications
* @param iTopObject
* The topological object defining a closed oriented area : 
* open CATShell, open CATFace, CATLoop (if not full), closed CATWire, or CATBody containing open Shells or closed Wires
* all other types of topological objects (like points or volumes) will be refused (returning E_FAIL)
* @param iRefDirection
* The reference direction used to compute the signed area onto a plane (whose the normal is this direction)
* @param oTopoAreaOrientation
* CATOrientationPositive if the sum of positive areas is bigger than the negative one(s),
* CATOrientationNegative if the sum of negative areas is bigger than the positive one(s),
* CATOrientationUnknown if the computed area is null or perfectly balanced between negative and positive areas,
* @return 
* E_FAIL if the request doesn't make sense because the input topological object doesn't define any oriented area,
* S_FALSE if the returned orientation is Unknown after computation on a valid input,
* S_OK if a positive or negative orientation has been computed and returned
*/
ExportedByRibbonLight HRESULT EvalTopoAreaOrientation(CATSoftwareConfiguration * iConfig, 
                                                      CATTopology              * iTopObject, 
                                                      const CATMathDirection   & iRefDirection, 
                                                      CATOrientation           & oTopoAreaOrientation);

/**
* ComputeTopoAdvancedBox() function
* The main purpose of this function consists in computing the advanced bounding box of a topological object.
* The optional direction allows the caller to force the output box to be an extrusion of a 2D-Box in this input direction
* The returned AdvancedBox might wrap an OBB, an OBBCloud or an AABB according to the specification of the smallest bounding box.
* see CATMathAdvancedBoxTypeEnum.h for the different types, CATMathOBB2DType is not supported by this function
* This service is available for both exact and polyhedral objects.
* @param iConfig
* The pointer to the software configuration driving the versionning of code modifications
* @param iTopObject
* The topological object defining a bounding box : 
* CATBody, CATDomain, CATCell
* @return 
* The pointer to the computed CATMathAdvancedBox, to be deleted by the caller after use
* Null if the request doesn't make sense because the input topological object doesn't define any bounding box (empty body ?)
* 3 possible types (CATMathAdvancedBoxType) for the returned CATMathAdvancedBox
* CATMathAABBType     Axis Aligned Bounding Box
* CATMathOBBType      Oriented Bounding Box
* CATMathOBBCloudType Oriented Bounding Box Tree
*(CATMathOBB2DType    not supported by this function)
*/
ExportedByRibbonLight CATMathAdvancedBox * ComputeTopoAdvancedBox(CATSoftwareConfiguration * iConfig,
                                                                  CATTopology              * iTopObject);

//------------------------------------------------------------------------------
// finds all the faces adjacent to the RefFace
// iPropagMod    = CATSmooth (default) : propagation through smooth edges only
//               = Other               : propagation through all edges
// faces :         List of the adjacent faces which verify the propagation mode
// OtherAdjFaces : List of the "stopping" faces (adjacent, but don't propagate)
// iPropagEdges  : Input list of the edges which mandatory propagate
// oTransitEdges : List of the propagation edges corresponding to each result face
//                 = edge, if the edge was in iPropagEdge
//                 = NULL, else
// OnlyPropag    : TRUE if oTransitEdges will contains only mandatory propagate edges
// oBorders      : Edges n'ayant pas propage pour cette adjacence (bords)
// iForbiddenBoundingEdges : Les faces bordees par une des edges de cette liste seront eliminees
//                 de la solution
//------------------------------------------------------------------------------ 
ExportedByRibbonLight void GetAllAdjacentFaces (CATSoftwareConfiguration *iConfig,
                                                CATBody                  *InitBody,
                                                CATFace                  *RefFace, 
                                                ListPOfCATFace           *faces,
                                                CATDomain                *iDomain=0,
                                                int                       iPropagMod              = CATSmooth,
                                                ListPOfCATFace           *OtherAdjFaces           = NULL,
                                                ListPOfCATEdge           *oTransitEdges           = NULL,
                                                ListPOfCATEdge           *iPropagEdges            = NULL,
                                                CATBoolean                OnlyPropag              = FALSE,
                                                ListPOfCATEdge           *oBorders                = NULL,
                                                ListPOfCATEdge           *iForbiddenBoundingEdges = NULL);


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// CGM Private section
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Create an edge based on a given EdgeCurve and vertices
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATEdge *CreateEdge(CATBody             *iCreationBody,
                                          CATEdgeCurve        *iEdgeCurve,
                                          CATOrientation       iOrientation,
                                          CATPointOnEdgeCurve *iStartPOEC,
                                          CATVertex           *iStartVertex,
                                          CATPointOnEdgeCurve *iEndPOEC,
                                          CATVertex           *iEndVertex,
                                          CATFace             *iFace = NULL);

//------------------------------------------------------------------------------
// Extrapolation de Edge
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
//ExportedByRibbonLight CATEdge *Extrapol (CATBody *Body, 
//                                    CATPositionOnLimits &Position, 
//                                    CATEdge *Edge);

//------------------------------------------------------------------------------
// Extrapolation de Face
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
//ExportedByRibbonLight CATFace *Extrapol (CATBody             *Body,
//                                    CATPositionOnLimits &Position,
//                                    CATFace             *Face);


//------------------------------------------------------------------------------
// Couture d'un manifold sur un manifold. Peut etre appele autant de fois 
// qu'il y a de manifold a connecter. Dans ce cas, l'obtention du resultat final
// se fera parfois en passant par des etats invalides (volume ouvert si l'on doit
// coudre une skin connectant deux volumes).
// Si elle est necessaire, la decoupe des faces ou se fait la connexion entre le
// manifold a coudre et son "appui" est faite a la volee. Bien sur, toutes les 
// toutes les coupantes devront avoir ete correctement instanciees au prealable. 
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
/*
ExportedByRibbonLight void Sewing
(CATBody                  * iCreationBody,   // : Body de creation 
 CATSoftwareConfiguration * iConfig,
 CATDomain                * iManToSplit,     // : Manifold sur lequel on coud. 
 CATDomain                * iManToSew,       // : Manifold a coudre 
 ListPOfCATDomain        ** iBrdrOfManToSew, // : Tableau de listes de Manifolds contenant les
                                             //   bords du Manifold a coudre  
 CATSide                 * iSideToKeep,      // : Cote a garder pour tout les elements d'une liste 
                                             //   pointee par iBrdrOfManToSew
 CATLONG32                      iNbBrdr,          // : Nombre de listes contenues dans iBrdrOfManToSew. Donne
                                             //   egalement le nombre d'elements de iSideToKeep
 CATDomain               * iResult,          // : Manifold devant contenir le resultat 
 CATDomain               * iRemoved=NULL);   // : Manifold contenant les faces retirees (optionnel)
*/
//------------------------------------------------------------------------------
// Update an edge by adding a PCurve
// Please note: 1) If the edge's EdgeCurve already contains a PCurve on
//                 the same surface as iPCurve, then nothing happens
//              2) Until further notice, only iOrientationOnPCurve =
//                 PositiveOrientation is accepted
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void AddPCurveToEdge (CATGeoFactory *iGeoFactory,           // GeoFactory for creation of elements
                                            CATEdge       *iEdge,                 // Edge to be updated
                                            CATEdgeCurve  *iEdgeCurve,            // optional: EdgeCurve under iEdge
                                            CATPCurve     *iPCurve,               // PCurve to be added
                                            CATTopSign     iOrientationOnPCurve,  // Orientation on iPCurve
                                            CATBoolean     iForceAdd = FALSE);    // Optional: Forces additional PCurve into Edge even if already on surface


//------------------------------------------------------------------------------
// Get the border domain containing a given Edge or an edge of a given loop
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATDomain *GetDomainOfBorderCell(CATBody    *iBody,
                                                       CATLoop    *iLoop,   
                                                       CATEdge    *iEdge,   
                                                       CATFace    *iFace,
                                                       CATBoolean *oDomainFoundWithProvidedEdge = NULL);  


//------------------------------------------------------------------------------
// Get the border cells of a given cell in a given domain (this
// function also provides the corresponding matter side values)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void GetBorderCells(CATCell           *iCell,       // Bordered cell
                                          CATDomain         *iDomain,     // Domain in bordered cell
                                          ListPOfCATCell    &oBorderCell, // List of border cells
                                          CATSide          *&oSide);      // Matter side values

//------------------------------------------------------------------------------
// Calcule le gap entre deux points poses sur des cellules au moins adjacentes
// (elles peuvent etre confondues).
// 
// Le booleen renvoye vaut true si modulo la tolerance de creation du plus 
// petit element, les points sont confondus. 
//
// Les valeurs de gap renvoyees se decomposent en deux valeurs:
//
//   GapTang : Represente le gap tangentiel. C'est lui qui represente le "bruit"  
//   -------   potentiel (i.e compressable via une deformation) entre deux 
//             points 
//
//   GapCell : Represente le gap le CATLONG32 de la cellule lien liant les deux 
//   -------   cellules sur lesqueslles sont posees les vertex auxquels on 
//             s'interesse ici. Ce gap est incompressible car il traduit 
//             simplement la qualite du B-Rep sur lesquels sont poses les 
//             vertex a checker.
//
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean ComputeGap(CATSoftwareConfiguration *iConfig,
                                            CATVertex   * EndVertex ,
                                            CATCell     * Track     ,
                                            CATCell     * CellSupp  ,
                                            CATVertex   * Cible     ,
                                            CATCell     * CommonCell,
                                            CATCell     * CellSupp2 ,
                                            double      & gaptang,
                                            double      & gapcell,
                                            CATGeometry * iGeoRef       = NULL,
                                            CATBoolean  * oGTPSComputed = NULL,
                                            double      * oGapTangPS    = NULL);

//------------------------------------------------------------------------------
// Get the vertex that borders a given edge on a given face in a given loop
// in a given direction ("Forward" meaning that one searches in the positive
// rotation direction with respect to the face's normal vector, i.e. the face
// is to the LEFT of an OUTER border edge and to the RIGHT of an INNER border
// edge)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATVertex *GetBrdrVertexOnFace(CATBody        *iBody,
                                                     CATShell       *iShell,
                                                     CATEdge        *iEdge,
                                                     CATFace        *iFace,
                                                     CATTopSign      iDirection,
                                                     CATLoop       **oLoop = NULL);


//------------------------------------------------------------------------------
// Get the edge bordered by a given vertex, in a given loop, on a given face
// and in a given direction ("Forward" meaning that one searches in the positive
// rotation direction with respect to the face's normal vector, i.e. the face
// is to the LEFT of an OUTER border edge and to the RIGHT of an INNER border
// edge)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void GetBnddEdgesOnFaceAndLoop(CATVertex      *iVertex,
                                                     CATFace        *iFace,
                                                     CATLoop        *iLoop,
                                                     CATTopSign      iDirection,
                                                     ListPOfCATEdge *oEdge,
                                                     CATListOfInt   *oSide = NULL);


//------------------------------------------------------------------------------
// Read the chain of cells that lie underneath a given cell and get ALL
// the last cells
//
// Please note: 1) The function reads all cells
//              2) If no support cell is found then the function returns
//                 NULL
//              3) If the oSupportVertex list is provided then all
//                 support cells that are really vertices are ALSO
//                 stored in it (the same goes for oSupportEdge and
//                 oSupportFace)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void GetAllLastSupportCells(CATBody                  *iCreationBody,
                                                  CATSoftwareConfiguration *iConfig,
                                                  CATCell                  *iCell,
                                                  CATLISTP(CATCell)        *oSupportCell   = NULL,
                                                  ListPOfCATVertex         *oSupportVertex = NULL,
                                                  ListPOfCATEdge           *oSupportEdge   = NULL,
                                                  ListPOfCATFace           *oSupportFace   = NULL);

//------------------------------------------------------------------------------
// Read the chain of cells that lie underneath a given cell and get the
// the last cell
//
// Please note: 1) The function assumes that each cell is lying on only
//                 one cell (i.e. it's a linear chain)
//              2) If no support cell is found then the function returns
//                 NULL
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
/*
ExportedByRibbonLight CATCell *GetLastSupportCell (CATCell                  *iCell, 
                                              CATBody                  *iCreationBody,
                                              CATSoftwareConfiguration *iConfig);
*/


//------------------------------------------------------------------------------
// Get the side of a face in a shell
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATSide GetSideFaceVsShell (CATDomain * shell, CATFace* fac);


//------------------------------------------------------------------------------
// Get the uv bounding box of all the PCurves of a face, up to their max limits, exept PLine
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void GetMaxPCurvesBoxUV(CATSoftwareConfiguration * iConfig, CATFace * iFace, CATSurLimits & oBoxUV);


//------------------------------------------------------------------------------
// Check if Edge is valid
// Check if Start and End Vertices of the Edge are compatible with
// the orientation of the edge vs the edge curve
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void CheckEdgeIsValid(CATEdge *iEdge, CATBoolean & oIsEdgeValid) ;

//------------------------------------------------------------------------------
// Duplicate a domain :
// input  : InitialBody, FinalBody, InitialDomain
// return : the duplicated domain 
//          (= InitialDomain if the two input bodies are equal)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
/*
ExportedByRibbonLight CATDomain * DuplicateDomain (CATBody * InitialBody,
                                                   CATBody * FinalBody, 
                                                   CATDomain * InitialDomain);
*/

//------------------------------------------------------------------------------
// finds all the faces adjacent to the iReferenceListe and not referenced by
// iKnownFaces nor Stopping Faces
// iPropagMod = CATSmooth (default) : propagation through smooth edges only
//            = Other               : propagation through all edges
// faces :    List of the adjacent faces which verify the propagation mode
// stopping : List of the "stopping" faces (adjacent, but don't propagate)
// iPropagEdges  : Input list of the edges which mandatory propagate
// oTransitEdges : List of the propagation edges corresponding to each result face
//                 = edge, if the edge was in iPropagEdge
//                 = NULL, else
// OnlyPropag    : TRUE if oTransitEdges will contains only mandatory propagate edges
// oBorders      : Edges n'ayant pas propage pour cette adjacence (bords)
// iForbiddenBoundingEdges : Les faces bordees par une des edges de cette liste seront eliminees
//                 de la solution
//------------------------------------------------------------------------------ 
/* @nodoc @nocgmitf */
ExportedByRibbonLight void GetAllAdjacentFaces (CATSoftwareConfiguration *iConfig,
                                                CATBody                  *InitBody,
                                                ListPOfCATFace           *iReferenceListe,
                                                CATListPV                &iKnownFaces,
                                                int                       nKF,
                                                ListPOfCATFace           *stopping,
                                                ListPOfCATFace           *faces,
                                                int                       iPropagMod              = CATSmooth,
                                                ListPOfCATEdge           *oTransitEdges           = NULL,
                                                ListPOfCATEdge           *iPropagEdges            = NULL,
                                                CATBoolean                OnlyPropag              = FALSE,
                                                ListPOfCATEdge           *oBorders                = NULL,
                                                ListPOfCATEdge           *iForbiddenBoundingEdges = NULL);

//------------------------------------------------------------------------------ 
// Get the two vertices that border a list of connected edges bounding a
// given face
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean GetBorderVertices (ListPOfCATEdge  &iEdge,
                                                    CATFace         *iFace,
                                                    CATVertex      *&oStartVertex,
                                                    CATVertex      *&oEndVertex,
                                                    CATEdge        **oStartEdge = NULL,
                                                    CATEdge        **oEndEdge   = NULL);

//------------------------------------------------------------------------------
// Find out if a shell defines a volume, i.e. if it's a closed or open domain
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
//ExportedByRibbonLight CATBoolean IsVolume (CATBody *iBody, CATShell *iShell);

//------------------------------------------------------------------------------ 
// HKL 18 01 99 Add a PCurve to an edge and modify the edge's curve as required
//              THIS IS NOT THE SAME AS THE FORMER AddPCurveToEdge
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
// ExportedByRibbonLight void AddPCurveToEdge(CATPCurve*iPCurve, CATEdge*iEdge, CATSoftwareConfiguration * iConfig);

//------------------------------------------------------------------------------ 
// LAT 18 08 99 Add a PCurve to an edge and modify the edge's curve as required.
//              Optional surface may be used to simplify the resulting edge-curve
//              (only keep the necessary geometry : e.g. iPCurve and the p-curve
//              of iEdge that lies on iSurfaceUnderEdge).
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void AddPCurveToEdge_2(CATSoftwareConfiguration *iConfig,
                                             CATPCurve                *iPCurve, 
                                             CATEdge                  *iEdge,
                                             double                    iTolerance, 
                                             CATSurface               *iSurfaceUnderEdge=NULL);

//------------------------------------------------------------------------------
// MergePCurveToEdgeCurve
//
// Try to merge a CATPCurve and a CATEdgeCurve between specified limits, within
// a specified tolerance. The result is a CATEdgeCurve that contains :
//
//   - the 2 curves if iSurfaceUnderEdge is NULL
//   - only 2 CATPCurves if iSurfaceUnderEdge has been set in such a way as to
//   select the proper CATPCurve within the CATEdgeCurve. This is recommended
//   since it avoids the creation of unnecessarily complex CATEdgeCurves.
//
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATEdgeCurve * MergePCurveToEdgeCurve( CATSoftwareConfiguration * iConfig,
                                                            CATPCurve                * iPCurve, 
                                                            CATCrvLimits             & iPCurveLimits,
                                                            CATEdgeCurve             * iEdgeCurve,
                                                            CATCrvLimits             & iEdgeCurveLimits,
                                                            double                     iTolerance, 
                                                            CATSurface               * iSurfaceUnderEdge,
                                                            CATOrientation           & oOriNewEdgeCurveVsPrev );

//------------------------------------------------------------------------------
// MergePCurveWithEdgeCurve
//
// Try to merge a CATPCurve and a CATEdgeCurve between specified limits, within
// a specified tolerance. The result is a CATEdgeCurve that contains :
//
//   - the 2 curves if iPCurveUnderEdge is NULL
//   - only 2 CATPCurves if iPCurveUnderEdge 
//   This is recommended since it avoids the creation of unnecessarily complex CATEdgeCurves.
//
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATEdgeCurve * MergePCurveWithEdgeCurve(CATSoftwareConfiguration * iConfig,
                                                              CATPCurve                * iPCurve, 
                                                              CATCrvLimits             & iPCurveLimits,
                                                              CATEdgeCurve             * iEdgeCurve,
                                                              CATCrvLimits             & iEdgeCurveLimits,
                                                              double                     iTolerance, 
                                                              CATPCurve                * iPCurveUnderEdge,
                                                              CATOrientation           & oOriNewEdgeCurveVsPrev);

//------------------------------------------------------------------------------
// ReplaceEdgeCurve
//
// Replaces the CATEdgeCurve by another one. Both CATEdgeCurve must share a 
// common CATCurve. 
//
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void ReplaceEdgeCurve( CATEdge        * iEdge, 
                                            CATEdgeCurve   * iNewEdgeCurve,
                                            CATOrientation   iOriNewEdgeCurveVsPrev,
                                            CATCurve       * iCommonCurve );

//------------------------------------------------------------------------------
// Une edge est-elle bord de shell ? 
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
//ExportedByRibbonLight CATBoolean IsOnBorderOfDomain(CATEdge  *iEdge,
//                                               CATBody  *iBody,
//                                               CATShell *iShell);        

//---------------------------------------------------------------------------
// Finds out if a given edge is a free border edge, i.e. whether the edge
// either lies on only one support face or if it borders only one face
//---------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean IsFreeBorderEdge (CATBody *iBody,
                                                   CATSoftwareConfiguration* iConfig,
                                                   CATEdge *iEdge,
                                                   CATLONG32    &oNbBnddFaces,
                                                   CATLONG32    &oNbCutFaces);

//---------------------------------------------------------------------------
// Finds out if a Face is covered by a plane. Returns CATSideLeft if ok.
//---------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATSide IsCovered(CATSoftwareConfiguration* iConfig,
                                        CATVertex        * iVertex,
                                        CATFace          * iFace,
                                        CATMathDirection & iDir ,
                                        CATMathPoint     & iPt  );

//------------------------------------------------------------------------------
// Get the curvature of the surface underlying the face at the given vertex and
// along the given direction.
// iFace : the face pointing to the surface
// iCell : the cell on which the vetex is defined (can be equal to iFace or an edge)
// iVertex : vertex at which we want to calculate the curvature
// iTgt    : direction along which we want to calculate the curvature
// TgtRef  : the reference of the calculation 
// (if NULL the curvature is calculated according to the normal to the surface)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight double GetCurvatureOfFace     (CATSoftwareConfiguration* iConfig,
                                                     CATFace                  *iFace,       
                                                     CATCell                  *iCell,
                                                     CATVertex                *iVertex, 
                                                     CATMathVector            &iTgt,
                                                     CATMathVector            *TgtRef=NULL);

//------------------------------------------------------------------------------
// Compare two algebraic curvature values.
// Test done with standard tolerance (linked to the Resolution) values, 
//  extrem scale compliant.
// For customized tolerance values, please see CompareCurvatures ().
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight int CompareCurvaturesWithDefaultTol (double iC1,
                                                           double iC2,
                                                           CATGeoFactory* iGeoFac);

//-----------------------------------------------------------------------------
//
//   WARNING : For standard and Xtrm Scale compliant tolerances values,
//              use CompareCurvaturesWithDefaultTol (just above).
//             If you need customized tolerance values, please notice that :
//              iTolZero   is homogeneous to 1/Length
//              iTolRadius is homogeneous to Length
//             These values must be Xtrm Scale compliant.
//
// Compare two algebraic curvature values by first testing whether they are
// zero (with respect to iTolZero) and then by comparing their values (and signs)
// with (respect to iTolRadius). The resulting integer value is the index of the
// higher curvature value.
//-----------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight int CompareCurvatures (double iC1,
                                             double iC2,
                                             double iTolZero,
                                             double iTolRadius);

//-----------------------------------------------------------------------------
// Get the edge that is adjacent to a given edge at given vertex on the
// border of a given face
//-----------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATEdge *GetAdjacentEdge (CATFace    *iFace,
                                                CATVertex  *iVertex,
                                                CATEdge    *iKnownEdge = 0);

/* @nodoc */
ExportedByRibbonLight void GetComplementaryCell(CATBody        *iBody,              // Body containing iCell
                                                CATSoftwareConfiguration* iConfig, 
                                                CATCell        *iCell,              // Initial cell
                                                CATCell        *iBorderCell,        // Border cell to be contained in all
                                                // generated complementary cells
                                                ListPOfCATCell &oComplementaryCell, // List of complementary cells
                                                CATBody        *iNewBody = NULL,    // Optional Body for complementary cell creation
                                                CATDomain      *iDomain = NULL);    // optional domain for complementary cell
// (must have same dimension and
/*
ExportedByRibbonLight void GetComplementaryCell(CATBody        *iBody,              // Body containing iCell
CATCell        *iCell,              // Initial cell
CATCell        *iBorderCell,        // Border cell to be contained in all
// generated complementary cells
ListPOfCATCell &oComplementaryCell, // List of complementary cells
CATBody        *iNewBody = NULL,    // Optional Body for complementary cell creation
CATDomain      *iDomain = NULL);    // optional domain for complementary cell
*/
//------------------------------------------------------------------------------
// Enrobage de CATLoop::InsertEdge qui calcule automatiquement l'orientation
// a fournir. Fonctionne si l'edge a inserer partage deja ses vertex avec
// les edges au milieu desquelles on l'insere
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void InsertEdgeInLoop(CATLoop *iLoo, 
                                            CATEdge *iEdge, 
                                            int      iInsertRank,                                            
                                            CATSoftwareConfiguration* iConfig);

//------------------------------------------------------------------------------
// Indique si 2 vertex sont lies, avec un diagnostic pour la nature de ce lien
// donne par *oDiag:
// 0 - Pas de lien <=> la methode rend FAUX
// 1 - Egalite des 2 Vertex
// 2 - iVertex1 est pose coupant sur iVertex2
// 3 - iVertex2 est pose coupant sur iVertex1
// 4 - iVertex1 et iVertex2 sont poses coupants sur un meme vertex
// Dans les cas 2, 3 et 4, *oSuppCell est le vertex support des vertex
// poses coupants.
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean AreVertexLinked(CATVertex                *iVertex1,
                                                 CATVertex                *iVertex2,
                                                 CATBody                  *iBody,
                                                 CATSoftwareConfiguration *iConfig,  
                                                 CATCell                 **oSuppCell = NULL,
                                                 int                      *oDiag = NULL);

//------------------------------------------------------------------------------
// De merge d'1 edge dans un body modifiable
// Output:  ioModifiedFaces, if not NULL, carries back the modified faces(corresponding to iModifiedLoop)
//          ioNewEdges, if not NULL, carries back the new edges created
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void UnMergeEdge (CATSoftwareConfiguration *iConfig,
                                        CATBody                  *iBodyToModify,
                                        CATEdge                  *iEdgeToUnMerge,
                                        ListPOfCATDomain         *iModifiedLoop,
                                        CATLISTP(CATCell)        *ioModifiedFaces = NULL, //Modified SUH 2006:01:03
                                        CATLISTP(CATCell)        *ioNewEdges = NULL); 

//------------------------------------------------------------------------------
// De merge d'1 vertex dans un body modifiable
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void UnMergeVertex (CATSoftwareConfiguration *iConfig,
                                          CATBody                  *iBodyToModify,
                                          CATVertex                *iVertexToUnMerge);

//------------------------------------------------------------------------------
// SUH 2005:12:31
// Unmerge 1 vertex in an unmodifiable body- More liberal than UnMergeVertex above
// Some restrictions in UnMergeVertex are not followed. Like UnMergeVertex demanded that 
// the vertex should only be joining two otherwise separate faces. Against this, UnMergeVertex2
// can handle a face connected by only this vertex to many other faces.
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void UnMergeVertex2 (CATSoftwareConfiguration *iConfig,
                                           CATBody                  *iBodyToModify,
                                           CATVertex                *&iVertexToUnMerge,
                                           CATLISTP(CATCell)        *ioNewVertices = NULL);

//------------------------------------------------------------------------------
// D1A October 2022
// Tear the face with inner edge, the inner edge occurs twice in face loop, e.g. E1 edge in loop V1 -> E1 -> V2 -> -> V2 -> E1 -> V1 -> ->
// It creates 2 new edges replacing the input inner edge
// Output:  ioModifiedLoop carries the modified loops
//          ioModifiedFaces carries the modified faces(corresponding to iModifiedLoop)
//          ioNewEdges carries the new edges created
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void TearBodyFaceWithInnerEdge(CATSoftwareConfiguration* iConfig,
                                                     CATBody* iBodyToModify,
                                                     CATFace * iFaceToTear,
                                                     CATEdge* iInnerEdgeToUnMerge,
                                                     ListPOfCATDomain & ioModifiedLoop,
                                                     CATLISTP(CATCell)& ioModifiedFaces,
                                                     CATLISTP(CATCell)& ioNewEdges);

//------------------------------------------------------------------------------
// D1A October 2022
// Tear the vertex that bounds the 2 edges created by breaking an inner edge
// It creates 2 new vertices replacing the input vertex
// Output:  ioNewVertices carries  the new vertices 
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void TearInnerEdgeVertex(CATSoftwareConfiguration* iConfig,
                                               CATBody* iBodyToModify,
                                               CATFace * iFaceWithInnerEdge,
                                               const CATLISTP(CATEdge)& iBrokenInnerEdges,
                                               CATVertex * iVertexToUnmerge,
                                               CATLISTP(CATCell)& ioNewVertices);

//------------------------------------------------------------------------------
// D1A October 2022
// Find the inner edges, i.e. edges that occur twice in face loop, e.g. E1 edge in loop V1 -> E1 -> V2 -> -> V2 -> E1 -> V1 -> ->
// Output:  ioEdges carries the  innner edges
//          ioFaces carries the faces  (corresponding to ioEdges)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void GetInnerEdgesAndCorrespondingFaces(CATSoftwareConfiguration* iConfig,
                                                              CATBody* iBody,
                                                              CATLISTP(CATEdge) & ioEdges,
                                                              CATLISTP(CATFace) & ioFaces);

//------------------------------------------------------------------------------
// Mise A jour d'une liste d'edges avec les infos du journal
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void UpdateEdgesListWithJournal (ListPOfCATEdge *ioOldCells, CATCGMJournalList * iJournal, CATBoolean iListProtection = FALSE);

//------------------------------------------------------------------------------
// Updates the ioOfficialJournal with the information in iPrivateJournal
// If the iOldCells are mentioned, only the information about them is copied,
// otherwise all information about the faces is copied.
// If the iEdgeReporting is TRUE, then all information about the edges is copied.
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void UpdateOfficialJournalWithPrivate (CATCGMJournalList * ioOfficialJournal, 
                                                             CATCGMJournalList * iPrivateJournal, 
                                                             CATLISTP(CATGeometry) *iOldCells=NULL,
                                                             int iEdgeReporting=0);

//------------------------------------------------------------------------------
// GetCellSupport reccursif
// Si la lecture directe echoue, on recherche un pose sur indirect.
// L'element rendu est toujours celui de plus haut niveau
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATCell * AdvGetCellSupport(CATTopologicalOperator * TopOp,
                                                  CATCell * iCell, 
                                                  CATCell * iSupportOwningCell=NULL, 
                                                  int     * NbContainers=NULL,
                                                  CATCell ** iUpperSupport=NULL,
                                                  CATBody *  iBodyCreation=NULL);

//------------------------------------------------------------------------------
// Duplicate common topology between two Shells of a Body
//
// Please note: If a common topology exists, iShellToSeparate is
//              modified (iShell remains unchanged)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void SeparateShells(CATBody                   *iBody,
                                          CATShell                  *iShell,
                                          CATCGMJournalList         *iJournal,
                                          CATSoftwareConfiguration  *iSoftwareConfiguration,
                                          CATShell                 *&iShellToSeparate);

//------------------------------------------------------------------------------
// Duplicata d'un journal dans un autre, avec filtres eventuels
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void FilterAndInsertJournal(CATCGMJournalList * iJournal,
                                                  CATCGMJournalList * oJournal,
                                                  CATListOfInt      * iGeometricTypesOnly);

//------------------------------------------------------------------------------
// Evaluation de l'angle entre 2 faces en un parametre donne sur une 
// EdgeCommune
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void EvalLocalAngle(CATSoftwareConfiguration* iConfig          ,
                                          CATEdge                 * iEdge            ,
                                          CATCrvParam             & iParamOnEdgeCurve,
                                          CATFace                 * iFace1           ,
                                          CATFace                 * iFace2           ,
                                          CATAngle                & oAngle           ,
                                          double                  & oCosAngle        );
//----------------------------------------------------------------------------
// Creation d'un Body mono-vertex
// a partir d'un vertex, et eventuellement du body s'il existe deja
//----------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBody * CreateBodyMonoVertex(      CATVertex     * iVertex    ,
                                                           CATGeoFactory * iGeoFactory,
                                                           CATBody       * iBody      = NULL,
                                                     const CATBoolean      iDuplicateVertex=TRUE);

//----------------------------------------------------------------------------
// Creation d'un Body mono-shell-multi-face
// a partir d'une liste de faces, et eventuellement du body s'il existe deja
//----------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBody * CreateBodyMonoShellMultiFace(CATLISTP(CATFace) &iFaces,
                                                             CATListOfInt      &iSides,
                                                             CATGeoFactory     *iGeoFactory,
                                                             CATBody           *iBody=NULL);

//--------------------------------------------------------------------------------
// Diagnostic d'applatissement d'une face (degenerescence d'une face en une arete)
// a une tolerance donnee
//--------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean IsFaceCanBeDegenerated(CATFace * iFace, double iTolerance, CATBody * iBody, CATSoftwareConfiguration *iConfig);

//--------------------------------------------------------------------------------
// Diagnostic d'inclusion "geometrique" d'une edge (iEdge1) dans une autre (iEdge2)
// return TRUE si inclusion
//--------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean InclusionEdgeEdgeDiagnosis (CATGeoFactory * iGeoFactory, CATEdge* iEdge1, CATEdge * iEdge2, 
                                                             double iTolerance, CATSoftwareConfiguration *iConfig);

//------------------------------------------------------------------------------
// Get the list of faces contained in a skin (the method also returns 
// the number of faces)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight int GetSkinFaces(CATShell       *iSkinToSew,
                                       ListPOfCATFace &ioSkinFaces);

//------------------------------------------------------------------------------
// Compute the maximum ABSOLUTE sharpness angle of an edge with respect to
// two faces that belong to two shells (which may be identical)
//
// Please note:
// 1) The method returns TRUE if a value has been computed
// 2) If iSideOfEdgeVsLeftShell!=CATSideUnknown, the method also computes
//    the global sharpness, and therefore checks whether the sharpness angle
//    has the SAME SIGN all over the edge (otherwise the edge's convexity is
//    unknown)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean EvalSharpnessAngle(CATSoftwareConfiguration *iConfig,
                                                    CATEdge           *iEdge,
                                                    CATLISTP(CATFace) &iLeftFaces,
                                                    CATLISTP(CATFace) &iRightFaces,
                                                    CATShell          *iLeftShell,
                                                    CATShell          *iRightShell,
                                                    CATBody           *iBody,
                                                    CATOrientation     iRightShellOrientation,
                                                    CATAngle          &oMaxAngle,
                                                    CATSide            iSideOfEdgeVsLeftShell = CATSideUnknown,
                                                    CATTopSharpness   *oGlobalSharpness       = NULL);

//------------------------------------------------------------------------------
// Compute the relative orienation between two edges, one of which is lying on
// the other
//
// Please note:
// The method ASSUMES that iCuttingEdge lies on iBaseEdge, and therefore ONLY
// checks that iCuttingedge's EdgeCurve contains iBaseEdge's EdgeCurve
// If no relationship can be established on this basis, the method returns
// CATOrientationUnkown
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATOrientation GetRelativeEdgeOrientation(CATEdge *iCuttingEdge,
                                                                CATEdge *iBaseEdge);

/* @nodoc @nocgmitf */
//ExportedByRibbonLight int CATLocaleFromGR(CATGeoFactory *iGeoFactory,CATWire * Wire, const double & GR, CATEdge *& LocalEdge, double & LR);

/* @nodoc @nocgmitf */
//ExportedByRibbonLight double GetWireLength(CATWire * iWire);

//------------------------------------------------------------------------------
// Check if the 3D boxes of two given cells are intersecting
//
// Please note: The two cells can be inflated by an optional
//              common length value
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean CheckCellBoxesIntersection(CATCell *iLeftCell,
                                                            CATCell *iRightCell,
                                                            double   iInflateLength = 0);

/* @nodoc @nocgmitf */
//ExportedByRibbonLight CATBoolean IsOnFaceBorder(CATCell *iBoundingCell, CATFace *iFace);

//------------------------------------------------------------------------------
// Determine whether the fillet's tangency limit is on it's U or V parameters,
// i.e. the method returns CATIsoParamU if the tangency limit of the fillet
// is an isoparametric curve along the U parameter, and CATIsoParamV if it's
// an isoparametric curve along the V parameter
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATIsoParameter GetFilletTangencyIsoParam(CATFace *iFace);

/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBody *CreateBodyFromEdges(CATGeoFactory *iFactory, ListPOfCATEdge &iEdges);
/* @nodoc @nocgmitf */
ExportedByRibbonLight void AddEdgesInsideBody(CATBody *iTargetBody, ListPOfCATEdge &iEdges,
                                              CATRibTopOp *iRibTopTopWhoWantsToKeepDomains = NULL);

//------------------------------------------------------------------------------
// Find out if cutting the edge again is justified by tangency conditions at either end
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean CheckCutAgain(CATSoftwareConfiguration *iConfig,
                                               CATEdge                  *iCurTrackEdge,
                                               CATFace                  *iCurSupportFace,
                                               CATBoolean                iOnlyEdgeInFace = TRUE);

//------------------------------------------------------------------------------
// Find out which bodies have no image trough iJournal
// This function manages faces only (can be improved)
//------------------------------------------------------------------------------
/* @nodoc @nocgmitf */
ExportedByRibbonLight void GetBodiesWithoutImage(CATLISTP(CATBody) &iNoCopyBodies, CATCGMJournalList &iJournal, 
                                                 CATLISTP(CATBody) &oNoCopyBodiesWithoutImage);

/* @nodoc @nocgmitf */
ExportedByRibbonLight void AddKeepOrderForFacesFromNoCopyBodies(CATLISTP(CATBody) &iNoCopyBodies, CATCGMJournalList *ioJournal, CATBody *iResultBody);

/* @nodoc @nocgmitf */
ExportedByRibbonLight double GetMinimumDistanceEdgeEdge(CATGeoFactory *iGeoFactory, CATSoftwareConfiguration *iConfig, 
                                                        CATEdge *iEdge1, CATEdge *iEdge2, double iMaxDist);

ExportedByRibbonLight CATBoolean GetParamOfVxOnGivenEC(CATVertex * iVertex, CATEdgeCurve * iEdgeCurve, CATCrvParam & ioParam);

ExportedByRibbonLight void RetrievePOECListFromMacroPoint(CATMacroPoint *iMacroPoint, CATLISTP(CATPointOnEdgeCurve) &ioPOECListToFill);

#endif
