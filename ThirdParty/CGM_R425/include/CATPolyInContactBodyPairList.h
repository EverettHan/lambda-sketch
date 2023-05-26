// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInContactBodyPairList.h
//
//===================================================================
//
// Usage notes: Data resulting from the contact operator (in a
// Simulia® way) between two visualisation reps. Represent a list of
// CATPolyBody's pairs, each of them containing a list of cells pairs
// in contact. See also @CATPolyBVHContact and
// @CATPolyInContactBodyPair.
//
//===================================================================
// 2009/06/24 XXC: New
//===================================================================
#ifndef CATPolyInContactBodyPairList_h
#define CATPolyInContactBodyPairList_h

#include "PolyVisuContact.h"
#include "CATPolyBVHContact.h"

#include "CATErrorDef.h"
#include "CATMathInline.h"
#include "CATBoolean.h"
#include "CATHTable_D.h"
#include "CATListPV.h"

class CAT4x4Matrix;
class CATPolyInContactBodyPair;
class CATPolyInContactFacePairList;
class CATPolyBody;
class CATMathTransformation;
class CATMapOfPtrToPtr;
class CATMathPoint;
class CATMathVector;
class CATPickPath;

/**
 * Structure designed to manage a list of pairs of bodies
 * (CATPolyBody) as the result of the contact operator
 * CATPolyBVHContact between to tesselated assemblies.
 * Structures that represent pairs of in contact bodies
 * (CATPolyInContactBodyPair), list of in contact faces
 * (CATPolyInContactFacePairList) and pairs of in contact faces are
 * for internal use only. The access to these data is done through an
 * iterator (class
 * CATPolyInContactBodyPairList::InContactFacesIterator).
 */

class ExportedByPolyVisuContact CATPolyInContactBodyPairList
{
 public:
  class ExportedByPolyVisuContact InContactFacesIterator
  {
  public:
    InContactFacesIterator(CATPolyInContactFacePairList & iRef);
    ~InContactFacesIterator();
    
    void Begin();
    CATBoolean End();
    void Next();

    int GetSize() const;
    
    /** DEPRECATED. Use GetFirstCellData
     * Gets all usefull contact data for the FIRST face in the
     *  current pair.
     *@param oFace: the face index, in a CATPolyBody, that is in
     *contact with the other one.
     *@param oWitness: the witness point that realize the contact on
     *the face.
     *@param oNormal: the normal vector to the face at the witness
     *point.
     *@param oIndex: the index, in the CATIPolySurface, of the facet
     *where the witness point is.
     */
    void GetFirstFaceData(int & oFace, CATMathPoint & oWitness, CATMathVector & oNormal, int & oIndex) const;
    /** DEPRECATED. Use GetSecondCellData
     * Gets all usefull contact data for the SECOND face in the
     *  current pair.
     *@param oFace: the face index, in a CATPolyBody, that is in
     *contact with the other one.
     *@param oWitness: the witness point that realize the contact on
     *the face.
     *@param oNormal: the normal vector to the face at the witness
     *point.
     *@param oIndex: the index, in the CATIPolySurface, of the facet
     *where the witness point is.
     */
    void GetSecondFaceData(int & oFace, CATMathPoint & oWitness, CATMathVector & oNormal, int & oIndex) const;
    /** Gets all usefull contact data for the FIRST cell in the
     *  current pair.
     *  @param oDim: Cell dimension, 1 for an edge, 2 for a face
     *  @param oCell: the face or edge index, in a CATPolyBody, that is in
     *  contact with the other one.
     *  @param oWitness: the witness point that realize the contact on
     *  the face.
     *  @param oNormal: the normal vector to the face at the witness
     *  point.
     *  @param oIndex: the index, in the CATIPolySurface, of the facet
     *  where the witness point is, or the index of the bar in the 
     *  CATIPolyCurve.
     */
    void GetFirstCellData(int & oDim, int & oCell, CATMathPoint & oWitness, CATMathVector & oNormal, int & oIndex) const;
    /** Gets all usefull contact data for the SECOND cell in the
     *  current pair.
     *  @param oDim: Cell dimension, 1 for an edge, 2 for a face
     *  @param oCell: the face or edge index, in a CATPolyBody, that is in
     *  contact with the other one.
     *  @param oWitness: the witness point that realize the contact on
     *  the face.
     *  @param oNormal: the normal vector to the face at the witness
     *  point.
     *  @param oIndex: the index, in the CATIPolySurface, of the facet
     *  where the witness point is, or the index of the bar in the 
     *  CATIPolyCurve.
     */
    void GetSecondCellData(int & oDim, int & oCell, CATMathPoint & oWitness, CATMathVector & oNormal, int & oIndex) const;
    /** Gets the dimensions of the CATPolyCell's in contact in the
     *  corresponding CATPolyBody's.
     *@param oDim1: the dimension of the first Cell in contact.
     *@param oDim2: the dimension of the second Cell in contact.
     */
    void GetCellsDimensions(int & oDim1, int & oDim2) const;
    /** Gets the indices of the CATPolyFace's in contact in the
     *  corresponding CATPolyBody's.
     *@param oFace1: the index of the first face in contact.
     *@param oFace2: the index of the second face in contact.
     */
    void GetFacesIndices(int & oFace1, int & oFace2) const;
    /** Gets the two points founded that realise the contact between
     *  the two faces.
     *@param oWitness1: the witness point on the first face in
     *contact.
     *@param oWitness2: the witness point on the the second face in
     *contact.
     */
    void GetWitnessPoints(CATMathPoint & oWitness1, CATMathPoint & oWitness2) const;
    /** Gets the normal vectors to the faces in contact at the witness
     *  points.
     *@param oNormal1: the normal vector for the first face in contact.
     *@param oNormal2: the normal vector for the second face in contact.
     */
    void GetNormalVectors(CATMathVector & oNormal1, CATMathVector & oNormal2) const;
    /** Gets the indices of facets where are the witness points.
     *@param oIndex1: index of the corresponding facet in the first
     *face in contact.
     *@param oIndex2: index of the corresponding facet in the second
     *face in contact.
     */
    void GetFacetIndices(int & oIndex1, int & oIndex2) const;

    /** Gets the kind of contact there is between the given pair of
     *  faces (penetration or just a contact within the tolerance
     *  defined). If it is only a contact, gives an indication of
     *  where are the witness points (on a triangle edge, a triangle
     *  vertex or into a triangle).
     */
    CATPolyBVHContact::ContactStatus GetContactStatus() const;
    
    /** Gives a read-only access to the pathes that allows to access,
     *  through the visualization tree, to the Graphic Primitives that
     *  correspond to the current Faces pair.
     * Important note: Root Reps of pick pathes are NOT the root
     * representation of the document, they are the reps used to
     * generate the trees given to the contact operator. To obtain a
     * complete path from the document rep, one must concatenate the
     * path from the root rep of the document to the root rep of the
     * tree. Note that this service is CPU costly (one draw of root
     * rep is done.).
     *@param oFirstPath: path for the first face in the current pair.
     *@param oSecondPath: path for the second face in the current pair.
     */
    HRESULT GetPathes(const CATPickPath * & oFirstPath, const CATPickPath * & oSecondPath) const;
    
  private:
    CATPolyInContactFacePairList & _ref;
  };
  
 public:

  ~CATPolyInContactBodyPairList ();

  /** Gets the size of the pair list.
   *@return the size (number of pairs) of the list.
   */
  INLINE int GetSize();

  /** Allows to iterate on the pairs contained in the list. Sets the
   *  iterator to the first poly bodies pair.
   */
  INLINE void Begin();
  /** Allows to iterate on the pairs contained in the list. Indicates
   *  if the iterator points after the last pair.
   *@return TRUE if the last element has been reached, FALSE
   *otherwise.
   */
  INLINE CATBoolean End();
  /** Allows to iterate on the pairs contained in the list. Set the
   * iterator to the following pair in the list.
   */
  INLINE void Next();

  /** Data access during iterations: returns the first CATPolyBody,
   *  and its position, contained in the current pair.
   *@oPosition: the position of the CATPolyBody
   *@return a reference to the CATPolyBody
   */
  const CATPolyBody * GetFirstPolyBody(CATMathTransformation & oPosition);
  /** Data access during iterations: returns the second CATPolyBody,
   *  and its position, contained in the current pair.
   *@oPosition: the position of the CATPolyBody
   *@return a reference to the CATPolyBody
   */
  const CATPolyBody * GetSecondPolyBody(CATMathTransformation & oPosition);
  /** Data access during iterations: returns an iterator to iterate on
   *  the faces pairs in contact for the current pair of
   *  CATPolyBody's in contact.
   *@return a new iterator. Must be deleted after use.
   */
  CATPolyInContactBodyPairList::InContactFacesIterator * GetFacesPairIterator();

private:
  // To allow an exclusive access in order to construct new pairs of
  // CATPolyBody's in contact.
  friend class CATPolyBVHContact;
  friend class CATPolyVisuContact;

  CATPolyInContactBodyPairList (CATBoolean ForcePolyBodyDeletion = FALSE);

  /** Add in the list and return a new (empty) Body pair.
   *@param iBody1: first CATPolyBody in the new pair to create and add to the list.
   *@param iBody2: second CATPolyBody in the new pair to create and add to the list.
   *@param iPosition1: position of the first CATPolyBody in the new pair.
   *@param iPosition2: position of the second CATPolyBody in the new pair.
   *@return the new created face pair.
   */
  CATPolyInContactBodyPair * NewPair(CATPolyBody * iBody1, CATPolyBody * iBody2,
                                     const CATMathTransformation * iPosition1 = NULL, const CATMathTransformation * iPosition2 = NULL);
  
  // Do not copy pair lists !
  CATPolyInContactBodyPairList (const CATPolyInContactBodyPairList & copy);
  CATPolyInContactBodyPairList & operator = (const CATPolyInContactBodyPairList & copy);

  INLINE const CATPolyInContactBodyPair * GetPair(int index) const;
  INLINE CATPolyInContactBodyPair * GetPair(int index);

private:
  CATBoolean _ForcePolyBodyDeletion;
  CATListPV _ContactBodyPairs;
  int _CurrentPair;
  // To manage memory for multiple referenced allocated CATPolyBody's:
  // allows to delete them only once.
  CATHTable_D _refPolyBodies;
};

INLINE int CATPolyInContactBodyPairList::GetSize()
{
  return _ContactBodyPairs.Size();
}

INLINE void CATPolyInContactBodyPairList::Begin()
{
  _CurrentPair = 1; // listPVs start at 1
}

INLINE CATBoolean CATPolyInContactBodyPairList::End()
{
  return (_CurrentPair > GetSize() ? TRUE : FALSE);
}

INLINE void CATPolyInContactBodyPairList::Next()
{
  _CurrentPair++;
}

INLINE const CATPolyInContactBodyPair * CATPolyInContactBodyPairList::GetPair(int index) const
{
   return (CATPolyInContactBodyPair *) _ContactBodyPairs[index];
}

INLINE CATPolyInContactBodyPair * CATPolyInContactBodyPairList::GetPair(int index)
{
  return (CATPolyInContactBodyPair *) _ContactBodyPairs[index];
}

#endif // CATPolyInContactBodyPairList_H
