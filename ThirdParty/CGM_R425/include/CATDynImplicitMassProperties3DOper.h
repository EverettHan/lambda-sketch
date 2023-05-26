/* -*-C++-*-*/
#ifndef CATDynImplicitMassProperties3DOper_H
#define CATDynImplicitMassProperties3DOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2023
//
// CATDynImplicitMassProperties3DOper
//
// DESCRIPTION: Operator that computes mass properties on a CATBody
// containing lattice implicit data.
//
//
// History
//
// 2023-02 MRI14/XXC Creation
//=============================================================================

#include "GMScalarFieldsOperators.h"

#include "CATImplicitGeoOperator.h" // derivation
#include "CATErrorDef.h"

// ScalarFields
//#include "SFTypes.h"
#include "CATMathPoint.h"
#include "CATMath3x3Matrix.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;
class CATVolume;
class CATDynImplicitMassProperties3DExt;

/**
* Class defining an operator that computes an approximation of mass
* properties of a CATBody containing implicit surfaces attributes on
* some volumes, without computing the corresponding geometry.
* <ul>
*     <li> A <tt>CATDynImplicitMassProperties3DOper</tt> operator is created with the <tt>CATCreateDynImplicitMassProperties3DOper</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByGMScalarFieldsOperators CATDynImplicitMassProperties3DOper : public CATImplicitGeoOperator
{
  CATCGMVirtualDeclareClass(CATDynImplicitMassProperties3DOper);

public:

  /**
  * Destructor
  */
  virtual ~CATDynImplicitMassProperties3DOper();


  //=============================================================================
  // Accessors
  //=============================================================================

  /**
   * Returns the volume of the analyzed body.
   * @return
   * The volume (in case of solid bodies). <tt>0.</tt> for shell bodies.
   */
  virtual double GetVolume() = 0;

  /**
   * Returns the surface of the analyzed body.
   * @return
   * The surface area. In case of a 3D bodies (lump domains),
   * the computed surface is the outside surface: cavities immersed
   * inside the 3D body are not taken into account. In case of 2D bodies (shell domains),
   * the holes are taken into account.
   */
  virtual double GetWetArea() = 0;

  /**
   * Returns the length of the analyzed body.
   * @return
   * Useful in case of 1D bodies (wire domains).
   */
  virtual double GetLength() = 0;

  /**
   * Returns the center of gravity of the analyzed body.
   * @return
   * The center of gravity.
   * For body made of shell , the center of gravity is equivalent to a extruded volume from the shell with a unitary thickness.
   * For body made of wire  , the center of gravity is equivalent to a sweeped volume along the wire with a unitary cross section.
   */
  virtual CATMathPoint GetCenterOfGravity()  = 0;

  /**
   * Returns the inertia matrix of the analyzed body.
   * @return
   * The inertia matrix.
   * The inertia matrix is relative to the center of gravity.
   * For body made of shell , the inertia matrix is equivalent to a extruded volume from the shell with a unitary thickness.
   * For body made of wire  , the inertia matrix is equivalent to a sweeped volume along the wire with a unitary cross section.
   */
  virtual CATMath3x3Matrix GetInertiaMatrix() = 0;

  // /**
  //  * Returns an estimation of the volume relative error.
  //  * @param oIsRelativeErrorAvailableWithMethod
  //  * TRUE if the relative error is available with the method or FALSE else.
  //  * @return
  //  * The estimation of the volume relative error if applicable or 0.
  //  */
  // virtual double GetVolumeRelativeError ( CATBoolean & oIsRelativeErrorAvailableWithMethod );

  // /**
  //  * Returns an estimation of the wet area relative error.
  //  * @param oIsRelativeErrorAvailableWithMethod
  //  * TRUE if the relative error is available with the method or FALSE else.
  //  * @return
  //  * The estimation of the wet area relative error if applicable or 0.
  //  */
  // virtual double GetWetAreaRelativeError ( CATBoolean & oIsRelativeErrorAvailableWithMethod );


  // /**
  //  * Returns an estimation of the center of gravity relative error.
  //  * @param oIsRelativeErrorAvailableWithMethod
  //  * TRUE if the relative error is available with the method or FALSE else.
  //  * This method is not applicable for body made of wire.
  //  * @param oRelativeError
  //  * gives the relative center of gravity position error along axis X , Y , Z
  //  * @param oMaximalDimension
  //  * gives the maximal dimension of the part along axis X , Y , Z.
  //  * This value is not the exact dimension but is extracted from the bounding box of the body.
  //  * <br>To have the absolute center of gravity error :
  //  * <ul>
  //  * <li>* oRelativeError[0] * ( 1 + oMaximalDimension[0] ) gives the absolute error along axis X
  //  * <li>* oRelativeError[1] * ( 1 + oMaximalDimension[1] ) gives the absolute error along axis X
  //  * <li>* oRelativeError[2] * ( 1 + oMaximalDimension[2] ) gives the absolute error along axis X
  //  * </ul>
  //  * This method is not applicable to the body made of wires.
  //  */
  // virtual void GetCenterOfGravityRelativeError ( CATBoolean & oIsRelativeErrorAvailableWithMethod ,
  //                                                double       oRelativeError   [3]                ,
  //                                                double       oMaximalDimension[3]                );



protected:

  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATDynImplicitMassProperties3DOper(CATGeoFactory & iFactory, CATDynImplicitMassProperties3DExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================

  CATDynImplicitMassProperties3DOper();
  CATDynImplicitMassProperties3DOper(const CATDynImplicitMassProperties3DOper& iOneOf);
  CATDynImplicitMassProperties3DOper& operator =(const CATDynImplicitMassProperties3DOper& iOneOf);
};

/**
 * Creates a CATDynImplicitMassProperties3DOper operator
 * @param iFactory
 * The factory of the geometry.
 * @param iConfig
 * The pointer to the software configuration.
 * @param iBodyToAnalyze
 * The pointer to the body to analyze, containing implicit surface attribute for some volumes
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMScalarFieldsOperators CATDynImplicitMassProperties3DOper * CATCreateDynImplicitMassProperties3DOper(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATBody * iBodyToAnalyze);

#endif /* CATDynImplicitMassProperties3DTopOper_H */
