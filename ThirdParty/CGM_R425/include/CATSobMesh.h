//========================================================================================
// Copyright Dassault Systemes Provence 2003, All Rights Reserved
//========================================================================================
//
// CATSobMesh.h
//
//========================================================================================
//
// Usage notes:
//
//========================================================================================
// March,     2021 : RJY1: Factorisation de Code CATSobMeshBase
// December,  2009 : RAQ : Ajout des listeners
// March,     2009 : RAQ : Ajout AddRef/Release
// January,   2008 : RAQ : Déplacement des méthodes GetMaxTagXXX de protected à public
// December,  2006 : RAQ : Ajout IsMeshFrozen
// October,   2006 : RAQ : SetExistsSubdivMesh passe dans CATSobMeshProtected
// October,   2006 : RAQ : Gestion tags sur les vertex
// October,   2005 : RAQ : Ajout Tag pour modif topo
// March,     2005 : RAQ : Ajout de transactions topo. pour update des BM locaux
// February,  2005 : RAQ : Ajout ReorderMeshElements pour optimisation mémoire
// February,  2005 : RAQ : Ajout constructeur par copie
// October,   2004 : RAQ : Optimisation mémoire
// July,      2004 : RAQ : Gestion precision pour le stream avec pertes
// July,      2004 : RAQ : Ajout SetExistsSubdivMesh et ExistsSubdivMesh
// January,   2004 : RAQ : Changement d'architecture des subdivisions
// October,   2003 : RAQ : Suppression des méthodes RemoveXXX et Update
// September, 2003 : JCV : Constructeur a partir d'une liste de faces
// September, 2003 : JCV : Gestion Diag
// February,  2003 : JCV : Creation d'apres le proto de LLR
//========================================================================================
#ifndef CATSobMesh_H
#define CATSobMesh_H

#include "CATSobMeshBase.h"

//Version Catia
#include "CATIAV5Level.h"

//Pour l'export
#include "CATSobObjects.h"

//Objets Subdivision
#include "CATSobDiag.h"
#include "CATSobDefine.h"
#include "CATSobListOfFace.h"
#include "CATSobListOfEdge.h"
#include "CATSobListOfVertex.h"
#include "CATSobAttributes.h"

//Divers
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATLib.h"

class CATSobVertex;
class CATSobEdge;
class CATSobFace;
class CATSobCell;
class CATSobMeshListener;
class CATSobMeshLayer;
class CATSobMeshLayerId;

//#define REMOVE_DESTRUCTOR


/**
 * Interface representing a Mesh
 */
class ExportedByCATSobObjects CATSobMesh : public CATSobMeshBase
{
public:

/**
 * DEPRECATED: Do not use anymore, use AddRef/Release mechanism instead
 */
#ifdef REMOVE_DESTRUCTOR
protected:
#endif  //REMOVE_DESTRUCTOR
  virtual ~CATSobMesh() {}
#ifdef REMOVE_DESTRUCTOR
public:
#endif  //REMOVE_DESTRUCTOR


  //-------------------------------- TOPOLOGICAL SERVICES --------------------------------//

/**
 * Adds a List Of Faces in the Mesh.
 *
 * @param iFaces
 * The List Of Faces to add.
 *
 * @return
 * The information value.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>CATSobDiag_OK                   </tt> <dd> OK.
 * <dl><dt><tt>CATSobDiag_InputNullList        </tt> <dd> iFaces is null
 * <dl><dt><tt>CATSobDiag_InputNullListElement </tt> <dd> one face of iFaces is null.
 * </dl>
 * Use @href CATSobDiag include to see all the information values.
 */
  virtual CATSobDiag AddFaces(CATLISTP(CATSobFace)* iFaces) = 0;

/**
 * Creates a Face in the Mesh.
 *
 * @param iEdges
 * The List Of Edges to define de boundary of the Face.
 *
 * @return
 * the pointer on the created Face 
 * if this pointer is Null,
 * get the information value using GetDiag.
 *
 * The information value.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>CATSobDiag_OK                   </tt> <dd> OK.
 * <dl><dt><tt>CATSobDiag_InputNullList        </tt> <dd> iEdges is null
 * <dl><dt><tt>CATSobDiag_InputInvalidSize     </tt> <dd> number of edges must be greater or equal to 3.
 * <dl><dt><tt>CATSobDiag_InputNullListElement </tt> <dd> one edge of iEdges is null.
 * <dl><dt><tt>CATSobDiag_FaceNotConnectedEdge </tt> <dd> all edge must be connected (same vertex) with the next edge
 * <dl><dt><tt>CATSobDiag_FaceNotClose         </tt> <dd> the first and the last edge must be connected.
 * </dl>
 * Use @href CATSobDiag include to see all the information values.
 */
  virtual CATSobFace* CreateFace(CATLISTP(CATSobEdge)* iEdges) = 0;
  

/**
 * Removes a face given by its pointer.
 *
 * @param ioFace
 * the pointer of the face to remove
 * after remove, the pointer is put to null
 *
 * @return
 * The information value.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>CATSobDiag_OK            </tt> <dd> OK.
 * <dl><dt><tt>CATSobDiag_InputNullFace </tt> <dd> ioFace is null
 * </dl>
 * Use @href CATSobDiag include to see all the information values.
 */
	virtual CATSobDiag RemoveFace(CATSobFace*& ioFace) = 0;

/**
 * Removes a face given by its index in the list of faces of the mesh.
 *
 * @param iIndex (1..number of faces)
 * the index of the face to remove
 *
 * @return
 * The information value.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>CATSobDiag_OK                </tt> <dd> OK.
 * <dl><dt><tt>CATSobDiag_InputInvalidIndex </tt> <dd> iIndex is null or greater than number of faces
 * </dl>
 * Use @href CATSobDiag include to see all the information values.
 */
  virtual CATSobDiag RemoveFace(const int iIndex) = 0;


  //-------------------------------- CELLS RETRIEVING UTILITIES --------------------------------//

/**
 * Gets the number of faces in 'this' mesh
 *
 * @return
 * The number of faces in 'this' mesh
 */
  virtual int GetNbFaces() const = 0;
  

/**
 * Gets all Faces defined in the Mesh.
 *
 * @param ioFaces
 * a pointer on the list of faces defined in the mesh
 *
 * @return
 * the number on the defined Faces 
 */
  virtual int GetAllFaces(CATLISTP(CATSobFace)*& ioFaces) const = 0;


/**
 * Retreives a CATSobFace of 'this' mesh from its tag
 *
 * @param iTag
 * The tag of the face to be retreived
 *
 * @return
 * The face whose tag is iTag
 */
  virtual CATSobFace* GetFaceFromTag(const unsigned int iTag) const = 0;


/**
 * Retrieves a CATSobEdge from the tag of a face containing it and 
 * the index of the edge in this face (see CATSobFace.h)
 * @param iFaceTag
 * The tag of the edge containing the edge
 * @param iEdgeIndex
 * The indx of the edge in the face
 * @return
 * The corresponding edge or NULL if not found
 */
  virtual CATSobEdge* GetEdgeInFace(const unsigned int iFaceTag, const unsigned int iEdgeIndex) = 0;


/**
 * Gets the highest tag on faces in 'this' mesh
 *
 * @return
 * The highest tag
 */
  virtual unsigned int GetMaxTagForFaces() const = 0;

/**
 * Gets the maximum valence on all vertices of the mesh
 *
 * @return
 * The maximum valence
 */
  virtual int GetValenceMax() const = 0;

  //-------------------------------- MISC UTILITIES --------------------------------//


/**
 * Test whether the mesh contains triangular faces
 *
 * @return
 * 1 if the mesh contains triangular faces, 0 else
 */
  virtual int HasTriangularFaces() const = 0;


/**
 * Reorder mesh elements (ie. Faces, edges and vertices) in the lists
 * given by GetAllXXX for buffer optimisation.
 *
 * @return
 * CATSobDiag_OK if no problem, else see CATSobDiag.h
 */
  virtual CATSobDiag ReorderMeshElements() = 0;

/**
 * Set the precision to use while lossy streaming 'this' mesh
 * If the precision is negative, the mesh will be exactly saved
 *
 * @param iPrecision
 * The precision value
 */
  virtual void SetPrecisionForLossyStream(const float iPrecision) = 0;

/**
 * Get the precision used while lossy streaming 'this' mesh
 *
 * @return
 * The precision used if positive, else stream is exact
 */
  virtual float GetPrecisionForLossyStream() const = 0;


/**
 * Local Cut: Close a step of topological modification.
 * Local base meshes are automatically updated.
 *
 * @return
 * CATSobDiag_OK if no problem, else see CATSobDiag.h
 */
  virtual CATSobDiag CloseTopoModifTransaction() = 0;


  virtual void FreeAllCellRankWithKey(CATLONGPTR iKey)=0;
  
  
/************* DEPRECATED ***********
 * Gets the Quad Mesh
 *
 * @return CATSobMesh
 * The Quad Mesh. Null if not exist.
 */
#ifdef _WINDOWS_SOURCE
  virtual __declspec(deprecated("Deprecated subdiv method, Do not use anymore")) CATSobMesh* GetQuadMesh() const = 0;
#else
  virtual CATSobMesh* GetQuadMesh() const = 0;
#endif  //_WINDOWS_SOURCE
  

/************* DEPRECATED ***********
 * Gets QuadState of the mesh
 *
 * @return 
 * the State Mesh. Legal Values :
 * - CATSobQuad_Undef : Undef -> necessary to use the Quad Operator to define if mesh is quad 
 * - CATSobQuad_Yes   : Mesh is Quad
 * - CATSobQuad_No    : Mesh is Not Quad
 * Use @href CATSobDefine include to see all the state values.
 */
  virtual CATSobQuadState GetQuadState() const = 0;

/************* Debug: Do Not Use ***********
 * Loop subdivision
 **/
  virtual CATSobDiag SetLoopMesh(const CATBoolean iOnOff = TRUE) = 0;
  virtual CATBoolean IsLoopMesh() const = 0;

protected:

  //Constructeur
  CATSobMesh() : CATSobMeshBase() {} // Constructeur modifié pour intégrer la classe parente

private :
  // Copy constructor and equal operator
  CATSobMesh (CATSobMesh &);
  CATSobMesh& operator=(CATSobMesh&);

};


/**
 * Subdivision mesh constructor
 *
 * @return
 * A pointer to a CATSobMesh object
 */
ExportedByCATSobObjects CATSobMesh* CATSobCreateMesh();

/**
 * Subdivision mesh copy constructor
 *
 * @param iMeshToCopy
 * A pointer to an existing mesh to copy
 *
 * @param iCopyCellsFlags
 * DO NOT USE, only default value must be used
 * if iCopyCellsFlags is TRUE, the method copies flags associated to each cell.
 *
 * @return
 * A pointer to a CATSobMesh object. The new mesh has the same
 * topology that the input mesh, details, sharpness and weights are
 * also copied.
 */
ExportedByCATSobObjects CATSobMesh* CATSobCreateMesh(CATSobMesh*      iMeshToCopy,
                                                     const CATBoolean iCopyCellsFlags = FALSE);

/**
 * Builds a mesh from a set of faces, cells tags, details, weights... are reported.
 *
 * @param iInputFaces
 * The faces to copy in 'this' new mesh.
 *
 * @return
 * A pointer to the new mesh if copy is successful.
 **/
ExportedByCATSobObjects CATSobMesh* CATSobCreateMesh(const CATLISTP(CATSobFace)& iInputFaces);


#endif
