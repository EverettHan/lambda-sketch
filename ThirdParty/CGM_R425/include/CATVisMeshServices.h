// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATVisMeshServices
// Header definition of CATVisMeshServices
//
//===================================================================
//
// Usage notes: Utility services operating on triangle meshes
//
//===================================================================
//
//  October 2006                                      Creation: FOR
//===================================================================
#ifndef CATVisMeshServices_H
#define CATVisMeshServices_H

#include "SGInfra.h"
#include "CATErrorDef.h"
class CAT3DFaceGP;

/**
* Class of utility services operating on triangle meshes
* <p>
* @href CATVisMeshAdjacencyOperator, CAT3DFaceGP
*/
class ExportedBySGInfra CATVisMeshServices
{
public:

  /**
  * Retrieves the indices defining simple triangles from a <tt>CAT3DFaceGP</tt>.
  * Since a <tt>CAT3DFaceGP</tt> contains, among others, simple triangles, as well as triangle strips and triangle fans,
  * this method computes the indices of the face so that all vertices are seen as simple triangles.
  *
  * Example: Drawing simple triangles one by one from a CAT3DFaceGP
  *
  *    int allocate;
  *    float *vertices = NULL;    
  *    ...
  *    pFaceGP->Get( &allocate, &vertices, ... );
  *
  *    unsigned int nbTriangles = 0;
  *    int* pIndices = NULL;
  *
  *    HRESULT hr = TransformFaceIntoSimpleTriangles(pFaceGP, nbTriangles, (unsigned int**) &pIndices);
  *
  *    if(SUCCEEDED(hr))
  *    {
  *      for(int triIdx=0; triIdx<nbTriangles; triIdx++)
  *      {
  *        float triCoords[9];            
  *
  *        int ind1 = pIndices[triIdx*3]/3;
  *        int ind2 = pIndices[triIdx*3+1]/3;
  *        int ind3 = pIndices[triIdx*3+2]/3;
  *
  *        // First Vertex
  *        triCoords[0] = vertices[ind1*3];
  *        triCoords[1] = vertices[ind1*3+1];
  *        triCoords[2] = vertices[ind1*3+2];
  *
  *        // Second Vertex
  *        triCoords[3] = vertices[ind2*3];
  *        triCoords[4] = vertices[ind2*3+1];
  *        triCoords[5] = vertices[ind2*3+2];
  *
  *        // Third Vertex
  *        triCoords[6] = vertices[ind3*3];
  *        triCoords[7] = vertices[ind3*3+1];
  *        triCoords[8] = vertices[ind3*3+2];
  *
  *        CAT3DLineGP * lineGP = new CAT3DLineGP(triCoords, 3, ALLOCATE, LINE_LOOP);
  *        ...
  *      }
  *    }
  *
  * @param ipFace
  *        A pointer to the <tt>CAT3DFaceGP</tt> we want to transform into simple triangles.
  *
  * @param oNbSimpleTriangles
  *        The number of simple triangles <tt>ipFace</tt> contains after converting all the internal structures.
  *
  * @param opSimpleTriangleIndices
  *        A pointer to an array of indices representing each triangle.
  *        These indices can be used with the vertex coordinates of <tt>ipFace</tt> retrieved by @href CAT3DFaceGP#Get()
  *        See example above.
  *        NOTE: This array is allocated by teh method and should be deleted by the caller when no longer useful.
  *
  * @return 
  *        <ul>
  *          <li>E_INVALIDARG if <tt>CAT3DFaceGP</tt> is <tt>NULL</tt>.  
  *          <li>E_INVALIDARG if the <tt>*opSimpleTriangleIndices</tt> passed as a parameter is non <tt>NULL</tt>.
  *          <li>E_OUTOFMEMORY if <tt>*opSimpleTriangleIndices</tt> could not be allocated.
  *          <li>S_OK if the neighbors have been sucessfully computed.
  *          <li>E_FAIL if the <tt>*opSimpleTriangleIndices</tt> is <tt>NULL</tt> before returning.
  *        </ul>
  */
  static HRESULT TransformFaceIntoSimpleTriangles(CAT3DFaceGP* ipFace, unsigned int& oNbSimpleTriangles, unsigned int** opSimpleTriangleIndices);
};

#endif // #ifndef CATVisMeshServices_H
