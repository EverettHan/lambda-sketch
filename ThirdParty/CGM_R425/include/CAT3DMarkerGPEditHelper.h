#ifndef CAT3DMarkerGPEditHelper_H_
#define CAT3DMarkerGPEditHelper_H_

// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Helper class to edit CAT3DMarkerGP.
//------------------------------------------------------------------------------


#include "SGInfra.h"
#include "CATGraphicPrimitiveEditHelper.h"
#include "CATSymbolType.h"
#include "CATSysErrorDef.h"

class CATRep;
class CAT3DMarkerGP;
class CATViz3DMarker;

/**
 * Class to edit CAT3DMarkerGP graphic primitive
 * CATGraphicPrimitive are immutable objects. To be able to modify these object's data without having to copy the whole primitive,
 * this class empty the original graphic primitve, exposes methods to modify these data, then creates a new primitive with these data.
 * The old primitive can then be replaced with the new primitive.
 */
class ExportedBySGInfra CAT3DMarkerGPEditHelper : public CATGraphicPrimitiveEditHelper
{
public:

  static const unsigned int ReplaceByDuplicateIfMultiAggreg;
  
  /**
   * Constructor.
   */
  CAT3DMarkerGPEditHelper();
  
  /**
   * Destructor.
   * If the EditHelper is not empty, the edition context is notified.
   */
  ~CAT3DMarkerGPEditHelper();

  /**
   * Get if the edition of the given graphic primitive is possible, and if not, why.
   * @param iMarker
   *   The marker to be edited
   * @param iRep
   *   The Rep which should contain the marker
   * @return
   *  A CATGraphicPrimitiveEditHelper::EditAuthorization value, depending of the context.
   */
  static GPEditAuthorization IsEditionPossible(CAT3DMarkerGP* iMarker, CATRep* iRep);

  /**
   * Set the currenlty edited CAT3DMarkerGP with its edition context. Compared to Reset, this methods supports additional flags
   * which can perform operation to ensure that some edition features will be supported.
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iMarker
   *   The CAT3DMarkerGP instance which will be edited.
   * @param iRep
   *   The Rep containing the CAT3DMarkerGP. Currently supported rep are CATSurfacicRep and CAT3DCustomRep.
   *   If the marker is not contained in any Rep, this parameter can be NULL
   * @return
   *   If the marker can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   It should be noted that if the marker is contained in more than one Rep, it will always fail.
   *   If the marker is contained in a Stripped SurfacicRep, it will fail.
   */
  HRESULT Reset(CAT3DMarkerGP* iMarker, CATRep* iRep);

  /**
   * Set the currenlty edited CAT3DMarkerGP with its edition context. Compared to Reset, this methods supports additional flags
   * which can perform operation to ensure that some edition features will be supported.
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iMarker
   *   The CAT3DMarkerGP instance which will be edited.
   * @param iRep
   *   The Rep containing the CAT3DMarkerGP. Currently supported rep are CATSurfacicRep and CAT3DCustomRep.
   *   If the marker is not contained in any Rep, this parameter can be NULL
   * @param iFlags
   *   Additional flags which will perform operation needed to access some edition features.
   *     -ReplaceByDuplicateIfMultiAggreg : If the marker is aggregated in more than one Rep, this flag will make a copy of the marker and replace the 
   *                                        original marker in the rep.
   * @return
   *   If the marker can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   It should be noted that if the marker is contained in more than one Rep, it will always fail.
   *   If the marker is contained in a Stripped SurfacicRep, it will fail.
   */
  HRESULT ResetExtended(CAT3DMarkerGP* iMarker, CATRep* iRep, unsigned int iFlags);

  /**
   * Return the currently edited CAT3DMarkerGP
   * @return
   *  The currently edited CAT3DMarkerGP
   *  If the EditHelper was empty, NULL is returned.
   */
  CAT3DMarkerGP* GetMarker();

  /**
   * Retrieves marked points coordinates and the symbol type used
   * to mark them.
   * This method must be called this way:
   * <pre>
   * float const* points;
   * int nbPoints;
   * SymbolType symbol;
   *
   * Get(&points, &NbPoints, &symbol);
   * </pre>
   * @param oPoints
   *   Retrieves an array containing marked points coordinates: XYZXYZXYZ...
   *   Its size is equal to three times the number of marked points.
   * @param oNbPoints
   *   Retrieves the number of points marked by this 3D marker.
   * @param oSymbol
   *   Retrieves the symbol used to mark the points.
   */
  void Get (float **oPoints, int *oNbPoint, CATSymbolType * oSymbol) const;

  /**
   *sets the symbol used to mark the points to a new value.
   *@param iSymbol
   * The new symbol you wish to use.
   */
  void SetSymbolType (CATSymbolType iSymbol);

  /**
   * @nodoc
   * iPrim is emptied, then released.
   */
  void AdoptVizPrimitive(CATViz3DMarker* iPrim);

  /**
   * @nodoc
   */
  void CopyVizPrimitive(CATViz3DMarker const* iPrim);

protected:
  CAT3DMarkerGP* m_MarkerGP;
};
#endif
