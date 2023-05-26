#ifndef CATIPGMCreateConformalGCLatticeTopOper_h_
#define CATIPGMCreateConformalGCLatticeTopOper_h_

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMImplicitTopOperator.h"

class CATBody;
class CATFace;
class CATEdge;
class CATGeoFactory;
class CATTopData;
class CATVolume;
class LatticeNBModel;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMCreateConformalGCLatticeTopOper;

/**
* Class defining an operator that put implicit specifications for a conformal based lattice structure on the specified volume,
* <ul>
*     <li> A <tt>CATIPGMCreateConformalGCLatticeTopOper</tt> operator is created with the <tt>CATPGMCreateCreateConformalGCLatticeTopOper</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByCATGMOperatorsInterfaces CATIPGMCreateConformalGCLatticeTopOper: public CATIPGMImplicitTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMCreateConformalGCLatticeTopOper();

  //=============================================================================
  // Settings
  //=============================================================================
  /**
  * Volume to which attach implicit specs.
  * @param a CATVolume specifying the cavity to which we need to attach specs.
  */
  virtual void SetVolume(CATVolume *iCavityVolume) = 0;

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
  * The unit cell bar graph for the lattice you want to create.
  * By passing a latticeNBModel you transfer it's ownership, don't delete or
  * release it on your side.
  * @param iLatticeNBModel a LatticeNBModel specifying the bars of the lattice
  */  
  virtual void SetLatticePatternNBModel(LatticeNBModel* iLatticePatternNBModel) = 0;

  /**
  * The Generalized Cylinder support face defining the cavity to be latticed.
  * @param iSupportFace a pointer to a CATFace belonging the cavity's volume
  */
  virtual void SetSupportFace(CATFace* iSupportFace) = 0;

  /**
  * The Generalized Cylinder support edge defining the start edge inside the support face.
  * @param iSupportEdgeStart a pointer to a CATEdge belonging to the cavity's volume
  */
  virtual void SetSupportEdgeStart(CATEdge* iSupportEdgeStart) = 0;

  /**
  * The Generalized Cylinder support edge defining the end edge inside the support face.
  * @param iSupportEdgeEnd a pointer to a CATEdge belonging to the cavity's volume
  */
  virtual void SetSupportEdgeEnd(CATEdge* iSupportEdgeEnd) = 0;

  /**
  * The Generalized Cylinder guide face defining the cavity to be latticed.
  * @param iGuideFace a pointer to a CATFace belonging the cavity's volume
  */
  virtual void SetGuideFace(CATFace* iGuideFace) = 0;

  /**
  * The Generalized Cylinder guide edge defining the start edge inside the guide face.
  * @param iGuideEdgeStart a pointer to a CATEdge belonging to the cavity's volume
  */
  virtual void SetGuideEdgeStart(CATEdge* iGuideEdgeStart) = 0;

  /**
  * The Generalized Cylinder guide edge defining the end edge inside the guide face.
  * @param iGuideEdgeEnd a pointer to a CATEdge belonging to the cavity's volume
  */
  virtual void SetGuideEdgeEnd(CATEdge* iGuideEdgeEnd) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMCreateConformalGCLatticeTopOper(); // -> delete can't be called
};

/**
 * Creates a CATIPGMCreateConformalGCLatticeTopOper operator
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
ExportedByCATGMOperatorsInterfaces CATIPGMCreateConformalGCLatticeTopOper *CATPGMCreateCreateConformalGCLatticeTopOper(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  CATBody *iInputBody);

#endif /* CATIPGMCreateConformalGCLatticeTopOper_h_ */
