#ifndef CAT3DCurvedPipeGPEditHelper_H_
#define CAT3DCurvedPipeGPEditHelper_H_

// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Helper class to edit CAT3DCurvedPipeGP.
//------------------------------------------------------------------------------

#include "SGInfra.h"
#include "CATGraphicPrimitiveEditHelper.h"
#include "CATSysErrorDef.h"

class CATRep;
class CAT3DCurvedPipeGP;
/**
 * Class to edit CAT3DCurvedPipeGP graphic primitive
 * CATGraphicPrimitive must be edited in context, this class handles edition authorization.
 * NB : Do not keep EditHelper alive wore than necessary. Edition context notifcation is done on destruction. 
 * That's why heap allocation is forbidden.
 */
class ExportedBySGInfra CAT3DCurvedPipeGPEditHelper : public CATGraphicPrimitiveEditHelper
{  
public:
  /**
   * Constructor.
   */
  CAT3DCurvedPipeGPEditHelper();

  /**
   * Destructor.
   * If the EditHelper is not empty, the edition context is notified.
   */
  ~CAT3DCurvedPipeGPEditHelper();

  /**
   * Return the currently edited CAT3DCurvedPipeGP
   * @return
   *  The currently edited CAT3DCurvedPipeGP
   *  If the EditHelper was empty, NULL is returned.
   */
  CAT3DCurvedPipeGP* GetCurvedPipe();

  /**
   * Get if the edition of the given graphic primitive is possible, and if not, why.
   * @param iPire
   *   The pipe to be edited
   * @param iRep
   *   The Rep which should contain the pipe
   * @return
   *  A CATGraphicPrimitiveEditHelper::EditAuthorization value, depending of the context.
   */
  static GPEditAuthorization IsEditionPossible(CAT3DCurvedPipeGP* iPipe, CATRep* iRep);

  /**
   * Change the EditHelper's data from a new primitive with its edition context
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iPipe
   *   The CAT3DCurvedPipeGP instance to be edited.
   *   If the pipe is not contained in any Rep, this parameter can be NULL
   * @param iRep
   *   Rep containing the Pipe. Only CAT3DCustomRep are supported at the moment.
   * @return
   *   If the pipe can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   It should be noted that if the pipe is contained in more than one Rep, it will always fail.
   */
  HRESULT Reset(CAT3DCurvedPipeGP* iPipe, CATRep* iRep);

  /**
   * Retrieves the texture coordinates.
   * This method must be used like this:
   * <br><tt><pre>
   * float * textureCoord;
   * GetTextureCoord(&textureCoord);
   * <br></pre></tt>
   * @param oTextureCoord
   *    Retrieves the array of texture coordinates.
   *    Each vertex has an associated position
   *    in the texture map. The number of texture coordinates groups is always equal to the number of
   *    vertices. 
   * @param oDimension
   *    Retrieve the number of coordinates per vertex.
   */
  void GetTextureCoordinates(float ** oTextureCoord, int * oDimension);

  /**
   * Sets the texture coordinates.
   * @param iTextureCoord
   *    Array of texture coordinates. Each vertex has an associated position
   *    in the texture map. The number of texture coordinates groups is always equal to the number of
   *    vertices. 
   * @param iTextureFormat
   *    iTextureFormat is the number of fields associated to one vertex in the <tt>iTextureCoord</tt> array.
   *    It is also the number of texture coordinates associated to each vertex.
   *    Indeed, each vertex has associated coordinates in the texture map. The
   *    number of coordinates depends on the map dimension: the texture map
   *    may be in 1D, 2D or 3D. 
   * <br><b>Legal values</b>:
   *   <dl>
   *      <dt>1</dt>
   *        <dd>The texture map is a one dimension map. Each vertex has a single associated texture coordinate</dd>
   *      <dt>2</dt>
   *        <dd>The texture map is a two-dimension map. Each vertex has two associated texture coordinates</dd>
   *      <dt>3</dt>
   *        <dd>The texture map is a three-dimension map. Each vertex has three associated texture coordinates</dd>
   *   </dl>
   */
  void SetTextureCoordinates(float const* iTC, unsigned int iDim);

protected:
  CAT3DCurvedPipeGP* m_CurrPipe;
private:
  CAT3DCurvedPipeGPEditHelper(CAT3DCurvedPipeGPEditHelper const& iOther);
  CAT3DCurvedPipeGPEditHelper& operator=(CAT3DCurvedPipeGPEditHelper const& iOther);
};

#endif
