#ifndef EvalAndDebug_H
#define EvalAndDebug_H


// COPYRIGHT DASSAULT SYSTEMES 1999

// Export
#include "TopUtilLight.h"

#include "CATBoolean.h"
#include "CATListOfCATGeometries.h"

class CATBody;
class CATDomain;
class CATVertex;
class CATEdge;
class CATLoop;
class CATFace;
class CATShell;

class CATSurParam;
class CATCrvParam;
class CATPCurve;
class CATMathPoint;
class CATMathVector;
class CATTopologicalOperator;
class CATSoftwareConfiguration;

#include "TopologicalBasic.h"



// -------------------------------------------------------------------------------
// Calcul d'un point et/ou d'une tangente a une edge
// -------------------------------------------------------------------------------

ExportedByTopUtilLight CATBoolean EvalOnEdge // true si eval ok, false sinon 
(
 CATCrvParam   &iParmOnCurve,     // Parametre ou se fait l'evaluation 
 CATEdge       *iEdge,            // edge 
 int            iEvalCommand,     // Commande d'evaluation: 1 Point - 2 Tangente - 3 Pt + tangente
 CATMathPoint  *oEndPoint,        // point
 CATMathVector *oEndTangent=NULL, // tangente "normee"
 CATBoolean     iNormTgt=1        // true si l'on souhaite une tangente normee  
);


// -------------------------------------------------------------------------------
// Calcul d'un point et/ou d'une normale a une face 
// -------------------------------------------------------------------------------

ExportedByTopUtilLight CATBoolean EvalOnFace // true si eval ok, false sinon 
(
 CATSurParam   &iParmOnSur,      // Parametre ou se fait l'evaluation 
 CATFace       *iFace,           // face 
 int            iEvalCommand,    // Comande d'evaluation: 1 Point - 2 Normale - 3 Pt + normale
 CATMathPoint  *oEndPoint,       // point
 CATMathVector *oEndNormal=NULL, // normale "normee"
 CATBoolean     iNormNor=1,      // Normale normee - Calculee en fonction de EvalCommand  
 CATMathVector *oUTangent = NULL,
 CATMathVector *oVTangent = NULL     
);


// -------------------------------------------------------------------------------
// Calcul d'un point et/ou d'une normale a une cellule en un vertex full sur
// la cellule ou full sur une cellule bordante
// -------------------------------------------------------------------------------

ExportedByTopUtilLight CATBoolean EvalOnCell // True si eval ok, false sinon 
(CATSoftwareConfiguration * iConfig,
 CATVertex     *  iVertex,      // vertex ou se fait l'evaluation    
 CATCell       *  iBrdrCell,    // cellule ou le vertex est full 
 CATCell       *  iBnddCell,    // cellule dont le fond sert a l'evaluation 
 int              iEvalCommand, // Comande d'evaluation: 1 Point - 2 Normale - 3 Pt + normale
 CATMathPoint  *  oPtsLim,      // Point resultant de l'evaluation 
 CATMathVector *  oVecLim=NULL, // Normale resultant de l'evaluation 
 CATBoolean       iNormVec=1    // true si l'on souhaite un vecteur normee  
);


//------------------------------------------------------------------------------
// Compute tangent vector to the intersection between two faces at a given
// vertex
//------------------------------------------------------------------------------
/*
CATBoolean EvalIntersectionTangent
(CATSoftwareConfiguration * iConfig,
 CATVertex     *iVertex,     // Vertex for evaluation of normal planes
 CATCell       *iLinkCell,   // Cell that may be linking iVertex to iFace1 and/or iFace2
 CATFace       *iFace1,      // First face
 CATFace       *iFace2,      // Second face
 CATMathVector &oVector,     // Tangent vector
 CATBoolean     iNormVec);   // true if oVector should be of length 1
*/

//------------------------------------------------------------------------------
// Calcul du CATSurParam d'un vertex une face ou sur une edge "incluse" sur 
// une face 				       
// (la fonction retourne un CATBoolean qui indique si le parametre
// est une spec du POEC ou non)
//------------------------------------------------------------------------------

ExportedByTopUtilLight CATBoolean GetGeometryOn
(CATSoftwareConfiguration * iConfig,
 CATFace     * iFace,      // Face 
 CATCell     * iBrdrCell,  // Cell ou est pose le vertex 
 CATVertex   * iVertex,    // Vertex 
 CATSurParam & ParmOnSur); // Parm sur le fond de iFace du vertex

//------------------------------------------------------------------------------
// Service de dump pour debug
//------------------------------------------------------------------------------

// ExportedByTopUtilLight void DumpGeometryOnVertex(CATVertex* iVertex, CATEdge* iEdge);
// ExportedByTopUtilLight void DumpGeometryOnEdge  (CATEdge  * iedge);
// ExportedByTopUtilLight void DumpGeometryOnFace  (CATFace  * iFace);

//------------------------------------------------------------------------------
// Visualize a cell
// Please note: this only works with Vertices, Edges and Faces
//------------------------------------------------------------------------------
/*
ExportedByTopUtilLight CATLISTP(CATGeometry) Show
(CATBody *iBody,        // Body for creation
 CATCell *iCell,        // Cell to visualize
 CATLONG32     iVertexIndex, // 0-NoShow, 1-ShowStart, 2-ShowEnd, 3-ShowBoth
 CATLONG32     iRedColor,    // Red color component (0 thru 15)
 CATLONG32     iGreenColor,  // Blue color component (0 thru 15)
 CATLONG32     iBlueColor);  // Green color component (0 thru 15)


//------------------------------------------------------------------------------
// Un-visualize a cell
// Please note: the function simply removes a list of CATGeometry objects
//              that may have been created with an implicit GeoFactory
//              (contained in the provided body)
//------------------------------------------------------------------------------

ExportedByTopUtilLight void NoShow
(CATBody               *iBody,        // Body for removal
 CATLISTP(CATGeometry) &iGeoBag);     // List of CATGeometry objects to remove
*/

#endif
