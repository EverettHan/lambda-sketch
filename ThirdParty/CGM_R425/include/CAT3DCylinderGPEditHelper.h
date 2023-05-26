#ifndef CAT3DCylinderGPEditHelper_H_
#define CAT3DCylinderGPEditHelper_H_

// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Helper class to edit CAT3DCylinderGP.
//------------------------------------------------------------------------------


#include "SGInfra.h"
#include "CATGraphicPrimitiveEditHelper.h"
#include "CATSysErrorDef.h"

class CATRep;
class CAT3DCylinderGP;

/**
 * Class to edit CAT3DCylinderGP graphic primitive
 * CATGraphicPrimitive must be edited in context, this class handles edition authorization.
 * NB : Do not keep EditHelper alive wore than necessary. Edition context notifcation is done on destruction. 
 * That's why heap allocation is forbidden.
 */
class ExportedBySGInfra CAT3DCylinderGPEditHelper : public CATGraphicPrimitiveEditHelper
{  
public:
  /**
   * Constructor.
   */
  CAT3DCylinderGPEditHelper();

  /**
   * Destructor.
   * If the EditHelper is not empty, the edition context is notified.
   */
  ~CAT3DCylinderGPEditHelper();

  /**
   * Return the currently edited CAT3DCylinderGP
   * @return
   *  The currently edited CAT3DCylinderGP
   *  If the EditHelper was empty, NULL is returned.
   */
  CAT3DCylinderGP* GetCylinder();

  /**
   * Get if the edition of the given graphic primitive is possible, and if not, why.
   * @param iCyl
   *   The cylinder to be edited
   * @param iRep
   *   The Rep which should contain the cylinder
   * @return
   *  A CATGraphicPrimitiveEditHelper::EditAuthorization value, depending of the context.
   */
  static GPEditAuthorization IsEditionPossible(CAT3DCylinderGP* iCyl, CATRep* iRep);

  /**
   * Change the EditHelper's data from a new primitive with its edition context
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iPipe
   *   The CAT3DCylinderGP instance to be edited.
   *   If the cylinder is not contained in any Rep, this parameter can be NULL
   * @param iRep
   *   Rep containing the Cylinder. Only CAT3DCustomRep are supported at the moment.
   * @return
   *   If the cylinder can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   It should be noted that if the cylinder is contained in more than one Rep, it will always fail.
   */
  HRESULT Reset(CAT3DCylinderGP* iCyl, CATRep* iRep);

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
  CAT3DCylinderGP* m_CurrCyl;
private:
  CAT3DCylinderGPEditHelper(CAT3DCylinderGPEditHelper const& iOther);
  CAT3DCylinderGPEditHelper& operator=(CAT3DCylinderGPEditHelper const& iOther);
};

#endif
