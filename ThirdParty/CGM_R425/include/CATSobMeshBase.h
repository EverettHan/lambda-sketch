
//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
// CATSobMeshBase
//
//====================================================================
//
// Usage notes:  CATSobMeshBase contient les methodes communes a CATSobMesh et CATSobMeshCurve 
// CATSobMesh et CATSobMeshCurve  heritent de CATSobMeshBase 
//
//====================================================================
// Dec  , 2022 : MPS  : Industrialisation proto RJY1. Passage des methodes internes 
// aux subdivision  dans CATSobMeshBaseProtected
// March, 2021 : RJY1 : Creation from CATSobMesh
//====================================================================
#ifndef CATSobMeshBase_H
#define CATSobMeshBase_H 


//Version Catia
#include "CATIAV5Level.h"

//Pour l'export
#include "CATSobObjects.h"

//Objets Subdivision
#include "CATSobDiag.h"
#include "CATSobDefine.h"
#include "CATSobListOfEdge.h"
#include "CATSobListOfVertex.h"
#include "CATSobAttributes.h"

// For attributes
#include "CATSobListOfMeshLayer.h"
#include "CATSobListOfMeshListener.h"
#include "CATSobVertexTagVertexHashTable.h"

//Divers
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATLib.h"

class CATSobVertex;
class CATSobEdge;
class CATSobCell;
class CATSobMeshListener;
class CATSobMeshLayer;
class CATSobMeshLayerId;
class CATSobMesh;
class CATSobMeshCurve;
class CATSobMeshBaseProtected;


class ExportedByCATSobObjects CATSobMeshBase {


public:

	/**
	* Increments the reference counter of 'this' mesh.
	*
	* @return
	* The new reference counter
	*/
	int AddRef();

	/**
	 * Decrement the reference counter of 'this' mesh
	 */
	void Release();

	// ---------------------- Creation de primitives géométriques --------------------//

	/**
	* Creates an Edge in the Mesh.
	*
	* @param iStart
	* The start vertex of the edge
	*
	* @param iEnd
	* The end vertex of the edge.
	*
	* @return
	* the pointer on the created Edge
	* if this pointer is Null,
	* get the information value using GetDiag.
	*
	* The information value.
	* <br><b>Legal values</b>:
	* <dl><dt><tt>CATSobDiag_OK              </tt> <dd> OK.
	* <dl><dt><tt>CATSobDiag_InputNullVertex </tt> <dd> iStart or iEnd is null
	* </dl>
	* Use @href CATSobDiag include to see all the information values.
	*/
	CATSobEdge* CreateEdge(CATSobVertex* iStart,
		CATSobVertex* iEnd);

	/**
	 * Creates a Vertex in the Mesh.
	 *
	 * @param iX
	 * Define the first coordinate of the Vertex
	 * @param iY
	 * Define the second coordinate of the Vertex
	 * @param iZ
	 * Define the third coordinate of the Vertex
	 *
	 * @return
	 * the pointer on the created Vertex
	 * if this pointer is Null,
	 * get the information value using GetDiag.
	 *
	 * The information value.
	 * <br><b>Legal values</b>:
	 * <dl><dt><tt>CATSobDiag_OK</tt> <dd> OK.
	 * </dl>
	 * Use @href CATSobDiag include to see all the information values.
	 */
	CATSobVertex* CreateVertex(const double& iX, const double& iY, const double& iZ);

	/**
	 * Creates a Vertex in the Mesh.
	 *
	 * @param iX
	 * An array of three double containing the coordinates of the Vertex
	 *
	 * @return
	 * the pointer on the created Vertex
	 * if this pointer is Null,
	 * get the information value using GetDiag.
	 *
	 * The information value.
	 * <br><b>Legal values</b>:
	 * <dl><dt><tt>CATSobDiag_OK</tt> <dd> OK.
	 * </dl>
	 * Use @href CATSobDiag include to see all the information values.
	 */
	CATSobVertex* CreateVertex(const double iCoords[]);

	/**
	* Verifies the validity  of the mesh
	* - No Null Faces
	* - Connexity
	* - Lenght of Edge
	*
	* @return
	* The information value.
	* <br><b>Legal values</b>:
	* <dl><dt><tt>CATSobDiag_OK                   </tt> <dd> OK.
	* <dl><dt><tt>CATSobDiag_FaceNull             </tt> <dd> Null Faces exist in Mesh
	* <dl><dt><tt>CATSobDiag_EdgeNull             </tt> <dd> Null Edges exist in Mesh
	* <dl><dt><tt>CATSobDiag_MeshInvalidConnexity </tt> <dd> not connec Faces
	* <dl><dt><tt>CATSobDiag_EdgeLenghtMin        </tt> <dd> Lenght Edge too small
	* </dl>
	* Use @href CATSobDiag include to see all the information values.
	*/
	virtual CATSobDiag Verification() = 0;

	/**
	 * Updates the mesh
	 * - Remove Nulls pointer in the lists
	 * - Edges Not used by faces
	 * - Vertex Not used by edge
	 * After Update, the mesh must be connect.
	 *
	 * @return
	 * The information value.
	 * <br><b>Legal values</b>:
	 * <dl><dt><tt>CATSobDiag_OK </tt> <dd> OK.
	 * </dl>
	 * Use @href CATSobDiag include to see all the information values.
	 */
	virtual CATSobDiag Update() = 0;

	//----------------------------- Suppression de primitives géométriques -------------------//

	/**
	* Removes a Edge given by its pointer.
	*
	* @param ioEdge
	* the pointer of the Edge to remove
	* after remove, the pointer is put to null
	*
	* @return
	* The information value.
	* <br><b>Legal values</b>:
	* <dl><dt><tt>CATSobDiag_OK            </tt> <dd> OK.
	* <dl><dt><tt>CATSobDiag_InputNullEdge </tt> <dd> ioEdge is null
	* </dl>
	* Use @href CATSobDiag include to see all the information values.
	*/
	virtual CATSobDiag RemoveEdge(CATSobEdge*& iEdge);

	/**
	 * Removes a Vertex given by its pointer.
	 *
	 * @param ioVertex
	 * the pointer of the Vertex to remove
	 * after remove, the pointer is put to null
	 *
	 * @return
	 * The information value.
	 * <br><b>Legal values</b>:
	 * <dl><dt><tt>CATSobDiag_OK              </tt> <dd> OK.
	 * <dl><dt><tt>CATSobDiag_InputNullVertex </tt> <dd> ioVertex is null
	 * </dl>
	 * Use @href CATSobDiag include to see all the information values.
	 */
	virtual CATSobDiag RemoveVertex(CATSobVertex*& iVertex);

	/**
	* Removes an Edge given by its index in the list of Edges of the mesh.
	*
	* @param iIndex (1..number of Edges)
	* the index of the Edge to remove
	* @param ipEdge
	* the edge to remove : build in the method if not
	*
	* @return
	* The information value.
	* <br><b>Legal values</b>:
	* <dl><dt><tt>CATSobDiag_OK                </tt> <dd> OK.
	* <dl><dt><tt>CATSobDiag_InputInvalidIndex </tt> <dd> iIndex is null or greater than number of Edges
	* </dl>
	* Use @href CATSobDiag include to see all the information values.
	*/
	virtual CATSobDiag RemoveEdge(const int iIndex, CATSobEdge* ipEdge = NULL);

	/**
	 * Removes a Vertex given by its index in the list of Vertices of the mesh.
	 *
	 * @param iIndex (1..number of Vertices)
	 * the index of the Vertex to remove
	 *
	 * @return
	 * The information value.
	 * <br><b>Legal values</b>:
	 * <dl><dt><tt>CATSobDiag_OK                </tt> <dd> OK.
	 * <dl><dt><tt>CATSobDiag_InputInvalidIndex </tt> <dd> iIndex is null or greater than number of Vertexs
	 * </dl>
	 * Use @href CATSobDiag include to see all the information values.
	 */
	virtual CATSobDiag RemoveVertex(const int iIndex);

	// ------------------------------ Gestion des primitives --------------------//

	/**
	* Gets the number of edges in 'this' mesh
	*
	* @return
	* The number of edges in 'this' mesh
	*/
	inline int GetNbEdges() const;

	/**
	 * Gets the number of vertices in 'this' mesh
	 *
	 * @return
	 * The number of vertices in 'this' mesh
	 */
	inline int GetNbVertices() const;

	/**
	* Gets all Edges defined in the Mesh.
	*
	* @param ioEdges
	* a pointer on the list of Edges defined in the mesh
	*
	* @return
	* the number on the defined Edges
	*/
	int GetAllEdges(CATLISTP(CATSobEdge)*& ioEdges) const;

	/**
	 * Gets all Vertices defined in the Mesh.
	 *
	 * @param ioVertices
	 * a pointer on the list of Vertices defined in the mesh
	 *
	 * @return
	 * the number on the defined Vertices
	 */
	int GetAllVertices(CATLISTP(CATSobVertex)*& ioVertices) const;

	/**
	* Retreives a CATSobVertex of 'this' mesh from its tag
	*
	* @param iTag
	* The tag of the vertex to be retreived
	*
	* @return
	* The vertex whose tag is iTag
	*/
	CATSobVertex* GetVertexFromTag(const unsigned int iTag) const;

	/**
	* Retrieves a CATSobEdge from its vertices.
	* @param iVertex1
	* The first vertex
	* @param iVertex2
	* The second vertex
	* @return
	* The corresponding edge or NULL if not found
	*/
	CATSobEdge* GetEdgeBetweenVertices(CATSobVertex* iVertex1, CATSobVertex* iVertex2) const;

	/**
	 * Retrieves a CATSobEdge from the tag of its extremity vertices.
	 * @param iVertexTag1
	 * The first vertex tag
	 * @param iVertexTag2
	 * The second vertex tag
	 * @return
	 * The corresponding edge or NULL if not found
	 */
	CATSobEdge* GetEdgeBetweenVertices(const unsigned int iVertexTag1, const unsigned int iVertexTag2) const;

	/**
	* Gets the highest tag on vertices in 'this' mesh
	*
	* @return
	* The highest tag
	*/
	unsigned int GetMaxTagForVertices() const;
	

	//--------------- Freeze du Mesh ------------------------------------//
	/**
	* Check whether 'this' mesh is frozen
	*
	* @return
	* TRUE if the mesh is frozen, FALSE otherwise.
	*/
	CATBoolean IsMeshFrozen() const;


	//---------------- Gestion des Listeners -------------------------//

	/**
	* Adds a listener to 'this' mesh.
	*
	* @param iListener
	* The listener to add.
	*/
	 void AddListener(CATSobMeshListener* iListener);

	/**
	 * Removes a listener from 'this' mesh.
	 *
	 * @param iListener
	 * The listener to remove.
	 */
	void RemoveListener(CATSobMeshListener* iListener);

	//------------------ Gestion des Layers ---------------------------//

	/**
	* Adds a layer to 'this' mesh.
	*
	* @param iMeshLayer
	* The layer to add, a reference is added on it.
	*/
	void AddLayer(CATSobMeshLayer* iMeshLayer);

	/**
	 * Removes a layer from 'this' mesh.
	 *
	 * @param iMeshLayer
	 * The layer to remove, it is released.
	 */
	void RemoveLayer(CATSobMeshLayer* iMeshLayer);

	/**
	* Retreives a layer from a LayerID.
	* /!\ No AddRef is done on the returned layer.
	*
	* @param iID
	* The layer ID.
	* @param iName
	* In case of multiple layers having the same ID, retrieves from the layer name.
	*
	* @return
	* The layer if found.
	*/
	CATSobMeshLayer* GetMeshLayer(const CATSobMeshLayerId* iID, const CATLONGPTR iName = 0);

	//-------------------------------- MISC UTILITIES --------------------------------//

	/**
	* Verifies the closure of the mesh
	*
	* @return
	* The closure information.
	* 0 : The mesh is not Close
	* 1 : The mesh is Close
	*/
	virtual int IsClose() = 0;


	/**
	* Set that mesh topology state has changed.
	*
	* @param iTopoChanged
	* If iTopoChanged is TRUE the topology state of the mesh is "Changed",
	* else it is "Not Changed"
	**/
	 void SetTopologyChanged(const CATBoolean iTopoChanged);

	/**
	 * Check whether the mesh topology has changed.
	 *
	 * @return
	 * TRUE if mesh topology has changed, else FALSE
	 **/
	 CATBoolean HasTopologyChanged() const;


	/**
	* Check if a subdivision has already been processed on 'this' mesh.
	*
	* @return
	* TRUE if a subdivision has already been processed, FALSE else
	*/
    CATBoolean ExistsSubdivMesh() const;

	/**
	* Returns the information value of the last method
	* @return
	* The information value.
	* Use @href CATSobDiag include to see all the information values.
	*/
	inline CATSobDiag GetDiag() const;

	/**
	 * Set the diagnostic of the mesh
	 * @param iDiag
	 * The diagnostic of the mesh
	 */
	inline void SetDiag(CATSobDiag iDiag);

	/**
	* Release all buffers used during subdivision
	*/
	virtual void ResetAllSubdivisionBuffers();

	/**
	* RemoveAllAttributesOfType
	* Release On All Mesh's Cell the Attributes of the Given Type
	*/
	virtual void RemoveAllAttributesOfType(CATSobAttributesId* iType, CATLONGPTR iName = 0);


	/**
	 * Set that mesh details are expressed in global or local frame(s).
	 *
	 * @param iUseLocalFrame
	 * If iUseLocalFrame is TRUE, details are expressed in local frames,
	 * else they are expressed in global frame.
	 **/
	void SetUseLocalFrame(const CATBoolean iUseLocalFrame);

	/**
	 * Return whether mesh details are expressed in global or local frame(s)
	 *
	 * @return
	 * If returned value is TRUE mesh details are expressed in local frame,
	 * else they are expressed in global frame.
	 **/
	CATBoolean GetUseLocalFrame() const;

	/**
	 * Local Cut: Check if a topological modification step is open on 'this' mesh
	 *
	 * @return
	 * 0 if no topological moficiation step is open, else 1.
	 */
	CATBoolean IsTopoModifTransactionOpen() const;

	/**
	*Local Cut : Begin of a step of topological modification.
	* None of the local base meshes will be updated until the step is closed
	*/
	void OpenTopoModifTransaction(); 

	unsigned int GetValenceMax();

	/**
	*
	* Use only to cast to a CATSobMesh type
	*/
	virtual CATSobMesh* CastToCATSobMesh() const { return NULL; }

	/**
	*
	* Use only to cast to a CATSobMeshCurve type
	*/
	virtual CATSobMeshCurve* CastToCATSobMeshCurve() const { return NULL; }


	/**
	*
	* Access to the letter
	*/
	CATSobMeshBaseProtected* GetMeshBaseProtected() const
	{ 
		return _pMeshBaseProtected; 
	}

	virtual ~CATSobMeshBase();


	CATSobMeshBase();
		

protected:
	
	

	//---------------------- Attributes ---------------------------------//
	int _RefCounter;
	//Diag
	CATSobDiag _Diagnostic;

	//Eléments du base mesh
	CATLISTP(CATSobVertex) _AllVertices;
	CATLISTP(CATSobEdge) _AllEdges;

	//Listeners et layers
	CATSobListOfMeshListener _MeshListeners;
	CATSobListOfMeshLayer _MeshLayers;
	virtual void ResetArraysForSubdivision();
	
	//Debug
	unsigned int m_ID;

private: 
		
		
	void Initialize();

	//Tentative de création d'edge
	CATSobDiag TryEdgeCreation(CATSobVertex* iStartVertex, CATSobVertex* iEndVertex);
   
	CATSobMeshBaseProtected* _pMeshBaseProtected ;

};



CATSobDiag CATSobMeshBase::GetDiag() const
{
	return _Diagnostic;
}


void CATSobMeshBase::SetDiag(CATSobDiag iDiag)
{
	_Diagnostic = iDiag;
}

inline int CATSobMeshBase::GetNbEdges() const
{
	return _AllEdges.Size();
}

inline int CATSobMeshBase::GetNbVertices() const
{
	return _AllVertices.Size();
}


#endif
