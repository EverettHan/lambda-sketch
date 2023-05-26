#ifndef CATIPGMPolyhedralORMIsoSurface_h_
#define CATIPGMPolyhedralORMIsoSurface_h_

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMTopOperator.h"

#include "ListPOfCATFace.h"

class CATCGMOrmModel;
class CATGMPolyORMIsoSurfaceTopExt;
class CATGeoFactory;
class CATGeoPolyFactory;
class CATTopData;
class CATVolume;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMPolyhedralORMIsoSurface;

/**
* Class defining an operator that generate an IsoSurface from a volumic OrmModel
* <ul>
*     <li> A <tt>CATICGMPolyhedralORMIsoSurface</tt> operator is created with the <tt>CATCGMCreatePolyhedralORMIsoSurface</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
*     <li> The resulting journal should contain additional informations about the types of the faces generated.
*             Convention : 0=Frozen, 1=BorderOfDesignSpace, 2=Optimized, 3=FrozenAndBorderDesign, 4=Unknown
* </ul>
*/
class ExportedByCATGMOperatorsInterfaces CATIPGMPolyhedralORMIsoSurface: public CATIPGMTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMPolyhedralORMIsoSurface();

  //===========================================================================
  // ORIGIN CONTEXT MANAGEMENT
  //===========================================================================
  //--------------------------------------------------------------------------
  // Method: SetOriginContext
  //
  // Description: 
  //  Set the list of origin bodies used to create the OrmModel.
  //		For now, this operator is implemented only for the mono-body cases.
  //	Also set the list of frozen cells among this body.
  //
  // Return:
  //   E_FAIL if there is more or less than one body // TODO RBU3 : E_FAIL doit être faux maintenant.
  //--------------------------------------------------------------------------
  virtual HRESULT SetOriginContext(
    const CATLISTP(CATBody) &iBodyList,
    const CATLISTP(CATCell) &iFrozenCells) = 0;

  //--------------------------------------------------------------------------
  // Method: AddMergedFaces
  //
  // Description: 
  //  Add a group of origin-CATFaces that are to be considered as merged.
  //
  // CAUTION : a CATFace can be in only one group.
  //--------------------------------------------------------------------------
  virtual void AddMergedFaces(const CATLISTP(CATFace) &iMergedFaces) = 0;

  //--------------------------------------------------------------------------
  // Method: SetIgnoreInvalidTags
  // 
  // Description:
  //   Activate or deactivate the IgnoreInvalidTags mode
  //   If this mode is activated, an invalid tag (tag that is in the
  //     OrmModel but not in the originBody for example) will be ignored.
  //   Otherwise, an invalid tag lead to an error.
  //
  // For now this mode is activated by default, but you can deactivate it to
  //   know if the model is valid. // TODO : Ne pas le mettre par défaut.
  //--------------------------------------------------------------------------
  virtual void SetIgnoreInvalidTags(CATBoolean iIgnoreInvalidTags) = 0;

  //=============================================================================
  // Settings
  //=============================================================================
  // Method: EnableConvergenceToOrigin()
  // 
  // Description:
  //   Converge the points generated on the bars of the OrmModel onto
  //   the origin-elements generating those bars (CATFace or CATEdge).
  //
  //   It will converge the border of the optimised/frozen parts onto the originBody
  //     geometry.
  virtual void EnableConvergenceToOrigin() = 0;

  //--------------------------------------------------------------------------
  // Method: SetIgnoreFrozenElements
  //
  // Description: 
  //  Ignore the frozenElements while generating the results
  //  The border of the frozen zone are then managed as the border of the design space
  //--------------------------------------------------------------------------
  virtual void SetIgnoreFrozenElements(CATBoolean iIgnore) = 0;

  //--------------------------------------------------------------------------
  // Method: SetIgnoreNonOptimizableElements
  //
  // Description: 
  //  Ignore the elements outside the list of elements to optimize.
  //    The border of the union of volumes-to-optimize are then managed as the
  //    border of the design space.
  //--------------------------------------------------------------------------
  virtual void SetIgnoreNonOptimizableElements(CATBoolean iIgnore) = 0;

  //--------------------------------------------------------------------------
  // Method: SetIsoValue
  //
  // Description: 
  //  Set the iso-value 
  //--------------------------------------------------------------------------
  virtual void SetIsoValue(double iIsoValue) = 0;

  //--------------------------------------------------------------------------
  // Method: SetOrmBoundaryExtraction
  //
  // Description: 
  // Only generate the faces that are either on the border of the OrmModel,
  //   on the border of the design-space or on the border of the frozen areas.
  // iType gives the type of border to extract:
  // 	 1 : all faces on the border of the OrmModel.
  //   2 : all faces on the border of the design-space.
  //   3 : all faces on the border of a frozen-area.
  //
  // It disables the computation of the isocut based on the densities.
  //
  // WARNING : if a list of volume to optimize is set, the extraction of
  //   the frozen-borders (3) will include the non-optimizable volumes too.
  //--------------------------------------------------------------------------
  virtual void SetOrmBoundaryExtraction(int iType) = 0;

  //--------------------------------------------------------------------------
  // Method: SetVolumesToOptimize
  //
  // Description: 
  //  The optimization will only be computed into those volumes.
  //  The elements linked to the other volumes will be considered as Frozen
  //    Thus, their densities will not be used to compute the node density around them
  //    and they will entirely be in the result, exept with the IgnoreFrozenElement mode.
  //  CAUTION : as the element outside the listed volumes are set to Frozen,
  //    the faces generated on the border of those volumes will be tagged as Frozen.
  //--------------------------------------------------------------------------
  virtual void SetVolumesToOptimize(
    const CATLISTP(CATCell) &iListVolumeToOptimize) = 0;

  //--------------------------------------------------------------------------
  // Method: SetReverseIsoSurface
  //
  // Description: 
  // Reverse the generation of the isosurface.
  //   aka, generate the part below the density threshold.
  //--------------------------------------------------------------------------
  virtual void SetReverseIsoSurface(CATBoolean iReverseIsoSurface) = 0;

  //--------------------------------------------------------------------------
  // Method: SetVolumePartitionMode
  //
  // Description: 
  // Activate or not the volume-partition mode.
  //   With this mode, the generation of the isoSurface is computed
  //   and the result is a volume partition of the design space
  //   with the volumes:
  //     - Frozen
  //     - InsideIsoSurface
  //     - OutsideIsoSurface
  //     - NonOptimizable
  //--------------------------------------------------------------------------
  virtual void SetVolumePartitionMode(CATBoolean iActivated) = 0;

  //--------------------------------------------------------------------------
  // Method: GetVolumeFiliation
  //
  // Description: 
  // ONLY if VolumePartitionMode is activated.
  //
  // Given a volume, return its filiation : type & origin CATVolumes
  // 
  // Types possibles:
  //   0: unknown (error).
  //   1: Frozen.
  //   2: Inside Iso-Surface.
  //   3: Outside Iso-Surface.
  //   4: Non-optimizable volume.
  //
  // return E_FAIL without VolumePartitionMode, or before the Run or if iResVolume is not in the result.
  //--------------------------------------------------------------------------
  virtual HRESULT GetVolumeFiliation(CATVolume *iResVolume, int &oVolumeType, CATLISTP(CATCell) &oListOriginVolumes) = 0;


  //--------------------------------------------------------------------------
  // Method: GetOriginVolumeImages
  //
  // Description: 
  // ONLY if VolumePartitionMode is activated.
  //
  // Given a volume of the OriginBody, return its images in the result.
  //   Also return the type of each of its child-volume
  // 
  // Types possibles:
  //   0: unknown (error).
  //   1: Frozen.
  //   2: Inside Iso-Surface.
  //   3: Outside Iso-Surface.
  //   4: Non-optimizable volume.
  //
  // return E_FAIL without VolumePartitionMode, or before the Run.
  // return S_FALSE if the originVolume is not in the map OriginVolume -> ListImages.
  //--------------------------------------------------------------------------
  virtual HRESULT GetOriginVolumeImages(CATVolume *iOriginVolume, CATLISTP(CATCell) &oListVolumesImages, CATListOfInt &oVolumesTypes) = 0;

  //--------------------------------------------------------------------------
  // Method: SetMergeOfIsoNodes()
  // 
  // Description:
  //   Activate or deactivate the merge of the isoNodes too close to each other.
  //   This merge prevent the operator from generating small or invalid triangles.
  //
  // If iTol is not NULL, it will be used as the threshold to consider 2 isoNodes too close.
  // 
  // By default : this mode is activated at the resolution of the model.
  //--------------------------------------------------------------------------
  virtual void SetMergeOfIsoNodes(
    CATBoolean iActivateMerging,
    double *iTol = NULL) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMPolyhedralORMIsoSurface(); // -> delete can't be called
};

/**
 * Creates a CATIPGMPolyhedralORMIsoSurface operator
 * @param iFactory : MANDATORY
 *   The factory of the geometry.
 * @param iTopData
 *   The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 *   is <tt>NULL</tt>, it is not filled.
 * @param iOrmModel : MANDATORY
 *   The pointer to the 3D OrmModel
 * @return [out, IUnknown#Release]
 *   The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 *   Or NULL if the OrmModel or the factory are NULL.
 */
ExportedByCATGMOperatorsInterfaces CATIPGMPolyhedralORMIsoSurface *CATPGMCreatePolyhedralORMIsoSurface(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  CATCGMOrmModel *iOrmModel);

#endif /* CATIPGMPolyhedralORMIsoSurface_h_ */
