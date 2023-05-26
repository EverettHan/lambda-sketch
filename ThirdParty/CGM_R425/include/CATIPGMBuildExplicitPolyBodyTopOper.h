#ifndef CATIPGMBuildExplicitPolyBodyTopOper_h_
#define CATIPGMBuildExplicitPolyBodyTopOper_h_

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMImplicitTopOperator.h"

#include "CATCollec.h"

class CATBody;
class CATFace;
class CATCell;
class CATGeoFactory;
class CATTopData;
class CATVolume;
class CATLISTP(CATVolume);

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMBuildExplicitPolyBodyTopOper;

/**
* Class defining an operator that put implicit specifications for a bar graph lattice on the specified volume,
* with the provided LatticeNBModel (the bar graph that was previously given to old Lattice APIs in LatticeGMOperaots
* (i.e the bar graph might need to be trimmed previously)
* <ul>
*     <li> A <tt>CATIPGMBuildExplicitPolyBodyTopOper</tt> operator is created with the <tt>CATPGMCreateBuildExplicitPolyBodyTopOper</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByCATGMOperatorsInterfaces CATIPGMBuildExplicitPolyBodyTopOper: public CATIPGMImplicitTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMBuildExplicitPolyBodyTopOper();

  //=============================================================================
  // Settings
  //=============================================================================
  /**
  * Specify the smoothing mode for lattice geometry creation.
  * @param iSmoothingMode
  * The CATVRepType::SmoothingMode
  */
  virtual void SetSmoothingMode(const int iSmoothingMode) = 0;

  /**
  * Specify the smoothing mode for lattice geometry creation.
  * @param iSmoothingAmplitude
  * The amplitude of the smoothing that will be applied during geometry generation
  */
  virtual void SetSmoothingAmplitude(const double iSmoothingAmplitude) = 0;

  /** @nodoc
  * Method allows to specify desired accuracy level. See description of CATGMSFDiscretizationAccuracyLevel
  * @param iDiscretizationAccuracyLevel, the desired level of accuracy.
  */
  virtual void SetDiscretizationAccuracyLevel(const int i123DiscretizationAccuracyLevel) = 0;

  /**
  * Cavity to be filled with conformal lattice.
  * @param a CATVolume specifying the cavity to lattice.
  */
  virtual void SetCavities(const CATLISTP(CATVolume)& iCavityVolumes) = 0;

  /** @nodoc
  * Method allows to retrieve the accuracy level used for the discretization. Some time the specified discretization level
  * is not realistic and can not be used in practiced. Thus internally the operator adjust the accuracy level to what
  * was possible from a memory and performance point of view. This method let's you see whether or not the accuracy level used
  * is consistent with the one you had specified or if the operator had to downgrade the accuracy level.
  * @return the accuracy level used for discretization of the geometry as an int.
  */
  virtual const int GetDiscretizationAccuracyStatus() = 0;

  /** @nodoc
  * Some part of the generation pipeline might use a discretization step (for example some dag node might get evaluated
  * on VRep, in which case the discretization step is in fact the voxel size). That discretization step is computed using
  * the specified accuracy level and will change when internally the operator has to downgrade that accuracy level. This method
  * allows you to retrieve the actual value that was used during a specific run of the operator.
  * @return the discretization step that was used for discrete geometry geometry. If not computed yet return -1.0
  */
  virtual const double GetDiscretizationStep() = 0;

  /** @nodoc
  * When discretized implicit geometry might generate a lot of triangles. You might want in some cases to
  * reduce as much as possible that number of triangles. By default there is no decimation applied. If you want
  * one to be applied you have to enable it by specifying a non zero value for the tolerance to be used. This is
  * provided inside the operator as it might speed up subsequently a lot of the operations that are done to build the
  * final bodyPH. If you want to deactivate the decimation and return to the default situation you can set back
  * a tolerance of 0.0
  * @param iDiscretizationAccuracyLevel, the desired level of accuracy.
  */
  virtual void SetDecimationTolerance(const double iDecimationTolerance) = 0;

  /**
  * Option for enable implicit isosurface genus computation.
  * @param iGenusComputationOpt true if you want to enable the genus computation.
  */
  virtual void EnableGenusComputation(const bool iGenusComputationOpt) = 0;

  /** @nodoc
  * Method allows to retrieve the isosurface genus if computaiton was enabled.
  */
  virtual const int GetIsoSurfaceGenus() = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMBuildExplicitPolyBodyTopOper(); // -> delete can't be called
};

/**
 * Creates a CATIPGMBuildExplicitPolyBodyTopOper operator
 * @param iFactory
 * The factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iBodyWithCavityToLattice
 * The pointer to the 2D body to offset (under progress, not yet available) or the 3D body to thick
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByCATGMOperatorsInterfaces CATIPGMBuildExplicitPolyBodyTopOper *CATPGMCreateBuildExplicitPolyBodyTopOper(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  CATBody *iBodyWithCavityToLattice);

#endif /* CATIPGMBuildExplicitPolyBodyTopOper_h_ */
