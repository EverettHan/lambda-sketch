/* -*-C++-*-*/
#ifndef CATBuildExplicitShellSurfaceTopOper_H
#define CATBuildExplicitShellSurfaceTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATBuildExplicitShellSurfaceTopOper
//
// DESCRIPTION:
// Operator that generate a lattice structure within specified
// immersed cavity.
//
//
// History
//
// Nov. 2021 WZC Creation
//=============================================================================

#include "GMScalarFieldsOperators.h"

#include "CATImplicitTopOperator.h" // derivation
#include "CATErrorDef.h"

// Fuzzy
#include "CATVRepType.h"
#include "ListPOfCATImplicitVolume.h"

// ScalarFields
#include "SFTypes.h"

class CATFace;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATVolume;

/**
* Class defining an operator that put implicit specifications for a bar graph lattice on the specified volume,
* with the provided LatticeNBModel (the bar graph that was previously given to old Lattice APIs in LatticeGMOperaots
* (i.e the bar graph might need to be trimmed previously)
* <ul>
*     <li> A <tt>CATBuildExplicitShellSurfaceTopOper</tt> operator is created with the <tt>CATCreateBuildExplicitShellSurfaceTopOper</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByGMScalarFieldsOperators CATBuildExplicitShellSurfaceTopOper : public CATImplicitTopOperator
{
  CATCGMVirtualDeclareClass(CATBuildExplicitShellSurfaceTopOper);

public:

  /**
  * Destructor
  */
  virtual ~CATBuildExplicitShellSurfaceTopOper();


  //=============================================================================
  // Settings
  //=============================================================================


  /**
  * Specify the smoothing mode for lattice geometry creation.
  * @param iSmoothingMode
  * The CATVRepType::SmoothingMode
  */
  virtual void SetSmoothingMode(const CATVRepType::SmoothingMode iSmoothingMode) = 0;

  /**
  * Specify the smoothing mode for lattice geometry creation.
  * @param iSmoothingAmplitude
  * The amplitude of the smoothing that will be applied during geometry generation
  */
  virtual void SetSmoothingAmplitude(const double iSmoothingAmplitude) = 0;

  /** @nodoc  This value is used internally for the decimation that happen
  * on lattice geometry produced by the VRep. If not set sag should be used
  * but this might result in huge meshes so it might be useful sometime
  * to relax a bit that constraint. This option was offered by the 'old' Lattice
  * APIs in LatticeGMOperators used by LatticeDesigner.
  */
  virtual void SetDiscretizationAccuracyLevel(const SF::CATGMSFDiscretizationAccuracyLevel iDiscretizationAccuracyLevel) = 0;

  /** @nodoc
  * Method allows to retrieve the accuracy level used for the discretization. Some time the specified discretization level
  * is not realistic and can not be used in practiced. Thus internally the operator adjust the accuracy level to what
  * was possible from a memory and performance point of view. This method let's you see whether or not the accuracy level used
  * is consistent with the one you had specified or if the operator had to downgrade the accuracy level.
  * @return the accuracy level used for discretization of the geometry.
  */
  virtual const SF::CATGMSFDiscretizationAccuracyLevel GetDiscretizationAccuracyStatus() = 0;

  /** @nodoc
  * Some part of the generation pipeline might use a discretization step (for example some DAG node might get evaluated
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
  * Cavity to be filled with conformal lattice.
  * @param a CATVolume specifying the cavity to lattice.
  */
  virtual void SetCavities(const ListPOfCATImplicitVolume& iCavityVolumes) = 0;

  /**
  * Option for enable implicit isosurface genus computation.
  * @param iGenusComputationOpt true if you want to enable the genus computation.
  */
  virtual void EnableGenusComputation(const bool iGenusComputationOpt) = 0;

  /** @nodoc
  * Method allows to retrieve the isosurface genus if computaiton was enabled.
  */
  virtual const int GetIsoSurfaceGenus() = 0;

  //=============================================================================
  // Get additional information after Run
  //=============================================================================

protected:

  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATBuildExplicitShellSurfaceTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATImplicitOperTopExt &iExtensible);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================

  CATBuildExplicitShellSurfaceTopOper();
  CATBuildExplicitShellSurfaceTopOper(const CATBuildExplicitShellSurfaceTopOper& iOneOf);
  CATBuildExplicitShellSurfaceTopOper& operator =(const CATBuildExplicitShellSurfaceTopOper& iOneOf);
};

/**
 * Creates a CATBuildExplicitShellSurfaceTopOper operator
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
ExportedByGMScalarFieldsOperators CATBuildExplicitShellSurfaceTopOper * CATCreateBuildExplicitShellSurfaceTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyWithCavityToLattice);

#endif /* CATBuildExplicitShellSurfaceTopOper_H */
