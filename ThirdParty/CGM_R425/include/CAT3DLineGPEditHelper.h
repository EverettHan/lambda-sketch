#ifndef CAT3DLineGPEditHelper_H_
#define CAT3DLineGPEditHelper_H_

// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Helper class to edit CAT3DLineGP.
//------------------------------------------------------------------------------


#include "SGInfra.h"
#include "CATGraphicPrimitiveEditHelper.h"
#include "CATSysErrorDef.h"

class CATRep;
class CAT3DLineGP;
class CATViz3DLine;
class CAT3DInternalSmoothEdgeGP;
class CAT3DLineGPWithCrvParams;

/**
 * Class to edit CAT3DLineGP graphic primitive
 * CATGraphicPrimitive must be edited in context, this class handles edition authorization.
 * NB : Do not keep EditHelper alive wore than necessary. Edition context notifcation is done on destruction. 
 * That's why heap allocation is forbidden.
 */
class ExportedBySGInfra CAT3DLineGPEditHelper : public CATGraphicPrimitiveEditHelper
{
public:

  static const unsigned int ReplaceByDuplicateIfMultiAggreg;

  /**
   * Destructor.
   * If the EditHelper is not empty, the edition context is notified.
   */
  ~CAT3DLineGPEditHelper();

  /**
   * Constructor.
   */
  CAT3DLineGPEditHelper();

  /**
   * Get the currently edited CAT3DLineGP.
   * @return
   *  The currently edited CAT3DLineGP.
   *  If the EditHelper was empty, NULL is returned.
   */
  CAT3DLineGP* GetLine(); 

  /**
   * @nodoc
   * @return
   *  The currently edited CAT3DInternalSmoothEdgeGP.
   *  If the EditHelper was empty, or if the egde is not a CAT3DInternalSmoothEdgeGP, NULL is returned.
   */
  CAT3DInternalSmoothEdgeGP* GetSmoothEdge(); 

  /**
   * @nodoc
   * @return
   *  The currently edited CAT3DLineGPWithCrvParams.
   *  If the EditHelper was empty, or if the egde is not a CAT3DLineGPWithCrvParams, NULL is returned.
   */
  CAT3DLineGPWithCrvParams* GetLineWParams();

  /**
   * Get if the edition of the given graphic primitive is possible, and if not, why.
   * @param iLine
   *   The line to be edited
   * @param iRep
   *   The Rep which should contain the line
   * @return
   *  A CATGraphicPrimitiveEditHelper::EditAuthorization value, depending of the context.
   */
  static GPEditAuthorization IsEditionPossible(CAT3DLineGP* iLine, CATRep* iRep);

  /**
   * Set the currenlty edited CAT3DLineGP with its edition context
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iFace
   *   The CAT3DLineGP instance which will be edited.
   * @param iRep
   *   The Rep containing the CAT3DLineGP. Currently supported rep are CATSurfacicRep and CAT3DCustomRep.
   *   If the line is not contained in any Rep, this parameter can be NULL
   * @return
   *   If the line can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   It should be noted that if the line is contained in more than one Rep, it will always fail.
   *   If the line is contained in a Stripped SurfacicRep, it will fail.
   */
  HRESULT Reset(CAT3DLineGP* iGP, CATRep* iRep);

  /**
   * Set the currenlty edited CAT3DLineGP with its edition context. Compared to Reset, this methods supports additional flags
   * which can perform operation to ensure that some edition features will be supported.
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iFace
   *   The CAT3DLineGP instance which will be edited.
   * @param iRep
   *   The Rep containing the CAT3DLineGP. Currently supported rep are CATSurfacicRep and CAT3DCustomRep.
   *   If the line is not contained in any Rep, this parameter can be NULL
   * @param iFlags
   *   Additional flags which will perform operation needed to access some edition features.
   *     -ReplaceByDuplicateIfMultiAggreg : If the line is aggregated in more than one Rep, this flag will make a copy of the line and replace the 
   *                                        original line in the rep.
   * @return
   *   If the line can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   It should be noted that if the line is contained in more than one Rep, it will always fail.
   *   If the line is contained in a Stripped SurfacicRep, it will fail.
   */
  HRESULT ResetExtended(CAT3DLineGP* iGP, CATRep* iRep, unsigned int iFlags);

  /**
   * Retrieves line parameters, such as points coordinates, number of points and line type.
   * <b>Role</b>:This method must be called in the following way :<br>
   * <tt><pre>
   *                float const* points;
   *                int nbPoints, lineType;
   *
   *                Get(&points, &nbPoints, &lineType);
   * </pre></tt>
   * @param oPoints
   *    Retrieves the points coordinates array.
   *    Array of points coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the number of points.
   * @param oNbPoints
   *    Retrieves the number of points.
   * @param oLineType
   *    Retrieves the line type.
   *    <br><b>Legal values</b>:
   *    <dl>
   *      <dt>LINES</dt>
   *        <dd>The number of points must be even. A line will be drawn
   *            between points 1 and 2, an other line will be drawn between
   *            points 3 and 4, ...</dd>
   *      <dt>LINE_STRIP</dt>
   *        <dd>The number of points can be either even or odd. A line will
   *            be drawn between points 1 and 2, then, an other line will be drawn
   *            between points 2 and 3, ...</dd>
   *      <dt>LINE_LOOP</dt>
   *        <dd>Same as <tt>LINE_LOOP</tt>, excepted that one more line will be
   *            drawn between the last and the first points.</dd>
   *    </dl>
   */
  void Get (float **oPoints, int *oNbPoints,int *oLineType);

  /**
   * @nodoc
   */
  void Get (float **oPoints, int *oNbPoints,int *oLineType, float **oCrvParams);

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
   * This call will copy tangents.
   */
  HRESULT SetTangents(float const *tangents);

  /**
   * @nodoc
   * iPrim is emptied, then released.
   */
  void AdoptVizPrimitive(CATViz3DLine* iPrim);

  /**
   * @nodoc
   */
  void CopyVizPrimitive(CATViz3DLine const* iPrim);


protected:
  CAT3DLineGP*   m_Line;
  bool           m_HasCrvParams;
  bool           m_IsSmooth;
};

#endif
