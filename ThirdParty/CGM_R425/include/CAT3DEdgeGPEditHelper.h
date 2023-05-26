#ifndef CAT3DEdgeGPEditHelper_H_
#define CAT3DEdgeGPEditHelper_H_

// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Helper class to edit CAT3DEdgeGP.
//------------------------------------------------------------------------------


#include "SGInfra.h"
#include "CATGraphicPrimitiveEditHelper.h"
#include "CATSysErrorDef.h"

class CATRep;
class CAT3DBoundingGP;
class CAT3DEdgeGP;
class CAT3DEdgeGPWithCrvParams;
class CATViz3DEdge;
class CATViz3DEdgeMutable;

/**
 * Class to edit CAT3DEdgeGP graphic primitive
 * CATGraphicPrimitive must be edited in context, this class handles edition authorization.
 * NB : Do not keep EditHelper alive wore than necessary. Edition context notifcation is done on destruction. 
 * That's why heap allocation is forbidden.
 */
class ExportedBySGInfra CAT3DEdgeGPEditHelper : public CATGraphicPrimitiveEditHelper
{
public:

  static const unsigned int ReplaceByDuplicateIfMultiAggreg;

  /**
   * Destructor.
   * If the EditHelper is not empty, the edition context is notified.
   */
  ~CAT3DEdgeGPEditHelper();

  /**
   * Constructor.
   */
  CAT3DEdgeGPEditHelper();

  /**
   * Return the currently edited CAT3DEdgeGP
   * @return
   *  The currently edited CAT3DEdgeGP.
   *  If the EditHelper was empty, NULL is returned.
   */
  CAT3DEdgeGP* GetEdge(); 

  /**
   * @nodoc
   * @return
   *  The currently edited CAT3DEdgeGP
   *  If the EditHelper was empty, or if the edge is not a CAT3DEdgeGPWithCrvParams, NULL is returned.
   */
  CAT3DEdgeGPWithCrvParams* GetEdgeWParams();

  /**
   * Get if the edition of the given graphic primitive is possible, and if not, why.
   * @param iEdge
   *   The edge to be edited
   * @param iRep
   *   The Rep which should contain the edge
   * @return
   *  A CATGraphicPrimitiveEditHelper::EditAuthorization value, depending of the context.
   */
  static GPEditAuthorization IsEditionPossible(CAT3DEdgeGP* iEdge, CATRep* iRep);

  /**
   * Set the currenlty edited CAT3DEdgeGP with its edition context.
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iFace
   *   The CAT3DEdgeGP instance which will be edited.
   * @param iRep
   *   The Rep containing the CAT3DEdgeGP. Currently supported rep are CATSurfacicRep and CAT3DCustomRep.
   *   If the edge is not contained in any Rep, this parameter can be NULL
   * @return
   *   If the edge can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   It should be noted that if the edge is contained in more than one Rep, it will always fail.
   *   If the edge is contained in a Stripped SurfacicRep, it will fail.
   */
  HRESULT Reset(CAT3DEdgeGP* iGP, CATRep* iRep);

  /**
   * Set the currenlty edited CAT3DEdgeGP with its edition context. Compared to Reset, this methods supports additional flags
   * which can perform operation to ensure that some edition features will be supported.
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iFace
   *   The CAT3DEdgeGP instance which will be edited.
   * @param iRep
   *   The Rep containing the CAT3DEdgeGP. Currently supported rep are CATSurfacicRep and CAT3DCustomRep.
   *   If the edge is not contained in any Rep, this parameter can be NULL
   * @param iFlags
   *   Additional flags which will perform operation needed to access some edition features.
   *     -ReplaceByDuplicateIfMultiAggreg : If the edge is aggregated in more than one Rep, this flag will make a copy of the edge and replace the 
   *                                        original edge in the rep.
   * @return
   *   If the edge can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   If the edge is contained in a Stripped SurfacicRep, it will fail.
   */
  HRESULT ResetExtended(CAT3DEdgeGP* iGP, CATRep* iRep, unsigned int iFlags);

  /**
   * Retrieves edge's vertices and faces informations.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it has to be called like this :<br>
   * <tt><pre>
   * CAT3DBoundingGP * fref1, *fref2;
   * float * verticesFref1;
   * ...
   * Get(&fref1, &fref2, &verticesFref1, ...);
   * </pre></tt><br>
   * @param oFref1
   *    Retrieves a pointer to the edge first face.
   * @param oFref2
   *    Retrieves a pointer to the edge second face.
   * @param oVerticesFref1
   *    Retrieves the first face vertices coordinates array: XYZXYZXYZ...
   *    The edge vertices can be retrieved from this array thanks to their
   *    indices stored in *oIndices.
   * @param oIndices
   *    Retrieves the array of edge vertices indices. These indices allow the
   *    the access to vertices coordinates thanks to the *oVerticesFref1 array.
   *    For example, to get the edge first vertex coordinates, one must use
   *    the *oVerticesFref1 array combined with the *oIndices array, like this :
   *    v0.x = (*oVerticesFref1)[(*oIndices)[0]], v0.y = (*oVerticesFref1)[(*oIndices)[0]+1], v0.z = (*oVerticesFref1)[(*oIndices)[0]+2].
   * @param oIndicesSize
   *    Retrieves the oIndices array size.
   */
  void Get (CAT3DBoundingGP **oFref1,CAT3DBoundingGP **oFref2,
            float const**oVerticesFref1,int **oIndices,int *oIndicesSize);
  /**
   * @nodoc
   */
  void Get (CAT3DBoundingGP **oFref1,CAT3DBoundingGP **oFref2,
            float const**oVerticesFref1,int **oIndices,int *oIndicesSize, float **oCrvParams);

  /**
   * @nodoc
   */
  HRESULT GetCrvParams(float **oCrvParams);

  /**
   * @nodoc
   */
  HRESULT GetTangents(float **tangents);

  /**
   * @nodoc
   * if copy == 0 -> adopt pointer
   * if copy == 1 -> copy pointer
   */
  HRESULT SetTangents(float *tangents, int copy);

  /**
   * @nodoc
   */
  //void SetBoundingGP(CAT3DBoundingGP* iFref1,CAT3DBoundingGP* iFref2);

  /**
   * @nodoc
   * This call will copy tangents.
   */
  HRESULT SetTangents(float const *tangents);

  
  /**
   * @nodoc
   * iPrim is emptied, then released.
   */
  void AdoptVizPrimitive(CATViz3DEdge* iPrim);

  /**
   * @nodoc
   */
  void CopyVizPrimitive(CATViz3DEdge const* iPrim);

  /**
   * @nodoc
   */
  void GetRaw (void * & oIndices, unsigned int & oIndicesSize, unsigned int& indexType, int unpack = 1);

protected:
  CAT3DEdgeGP*         m_Edge;
  CATViz3DEdgeMutable* m_VizEdge;
  bool                 m_HasCrvParams;
};

#endif
