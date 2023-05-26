#ifndef CATIPGMCreateConformalLatticeTopOper_h_
#define CATIPGMCreateConformalLatticeTopOper_h_

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMImplicitTopOperator.h"

class CATBody;
class CATFace;
class CATGeoFactory;
class CATTopData;
class CATVolume;
namespace lattice::poly {class LatticeFrameFields;}

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMCreateConformalLatticeTopOper;

/**
* Class defining an operator that put implicit specifications for a conformal based lattice structure on the specified volume,
* <ul>
*     <li> A <tt>CATIPGMCreateConformalLatticeTopOper</tt> operator is created with the <tt>CATPGMCreateCreateConformalLatticeTopOper</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByCATGMOperatorsInterfaces CATIPGMCreateConformalLatticeTopOper: public CATIPGMImplicitTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMCreateConformalLatticeTopOper();

  //=============================================================================
  // Settings
  //=============================================================================
  /**
  * Desired bar length. Note that the resulting bar graph won't adhere to this but
  * will use instead this value as indicative of the bar length toward which most
  * bars should converge.
  * @param a double specifying the desired iBarLength
  */
  virtual void SetBarLength(const double iBarLength) = 0;

  /**
  * Desired bar radius. Bars of the resulting bar graph will have this radius
  * which will also be used for lattice geometry creation.
  * @param a double specifying the desired iBarLength
  */
  virtual void SetBarRadius(const double iBarRadius) = 0;

  /**
  * Cavity to be filled with conformal lattice.
  * @param a CATVolume specifying the cavity to lattice.
  */
  virtual void SetVolume(CATVolume *iCavityVolume) = 0;

  /**
  * Number of iterations of GaussSeidel.
  * @param a number of iterations.
  */
  virtual void SetNbIterationsGaussSeidel(const int iNbIterationsGaussSeidel) = 0;

  /**
    * Number of iterations of Jacobi.
    * @param a number of iterations.
    */
  virtual void SetNbIterationsJacobi(const int iNbIterationsJacobi) = 0;

  /**
    * Set Frame field to be used for the optimization. If you don't provide
    * this, internally we will generate one that mimic a compression/expansion
    * of the whole exterior surface of the cavity. As it is generated from
    * the geometry alone with a reasonable time budget this might be less
    * precise that results you could get from a full blown physical solver and
    * obviously it won't be optimized for a specific load case. For all these
    * reasons you might want to set yourself the frame field. It should contains
    * both the field and a density value.
    * @param a lattice::poly::LatticeFrameFields.
    */
  virtual void SetFrameField(lattice::poly::LatticeFrameFields* iFrameFields) = 0;

  /**
    * Set density cut off value with respect to the density field provided as part
    * of the FrameField.
    * @param parameter to override the density field threshold value
    * defining the cavity's inside/outside used to optimize an initial lattice which covers the
    * cavity's bounding box.
    * By definition a 0.0 threshold value means that we will optimize the full lattice covering
    * the cavity's bounding box.
    */
  virtual void SetDensityCutOff(const double iDensityCutOff) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMCreateConformalLatticeTopOper(); // -> delete can't be called
};

/**
 * Creates a CATIPGMCreateConformalLatticeTopOper operator
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
ExportedByCATGMOperatorsInterfaces CATIPGMCreateConformalLatticeTopOper *CATPGMCreateCATCreateConformalLatticeTopOper(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  CATBody *iBodyWithCavityToLattice);

#endif /* CATIPGMCreateConformalLatticeTopOper_h_ */
