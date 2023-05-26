/* -*-C++-*-*/
#ifndef CATCreateTPMSTopOper_H
#define CATCreateTPMSTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATCreateTPMSTopOper
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

#include "DSYString.h"
#include "CATErrorDef.h"

// STD
#include <list>

// Fuzzy
#include "CATVRepType.h"

// ScalarFields
#include "SFTypes.h"
#include "CATTPMSType.h"

// CGM
#include "ListPOfCATFace.h"

class CATFace;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATVolume;

/**
* Class defining an operator that put implicit specifications for a TPMS based lattice structure on the specified volume,
* <ul>
*     <li> A <tt>CATCreateTPMSTopOper</tt> operator is created with the <tt>CATCreateCreateTPMSTopOper</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByGMScalarFieldsOperators CATCreateTPMSTopOper : public CATImplicitTopOperator
{
  CATCGMVirtualDeclareClass(CATCreateTPMSTopOper);

public:

  /**
  * Destructor
  */
  virtual ~CATCreateTPMSTopOper();


  //=============================================================================
  // Settings
  //=============================================================================

  /**
  * Volume to which attach implicit specs.
  * @param a CATVolume specifying the cavity to which we need to attach specs.
  */
  virtual void SetVolume(CATVolume* iCavityVolume) = 0;

  /**
  * Let you set the type of Triply Periodic Minimal Surface you want to use
  * to build a lattice structure. This refers directly to the expression
  * template that will be used to specify the implicit geometry of the
  * structure.
  * @param iTPMSType a type of TPMS to be used to build lattice structure.
  */
  virtual void SetTPMSType(const CATTPMSType iTPMSType) = 0;

  /**
  * This argument let you specify how frequently the pattern will
  * appear in a given volume.
  * @param iPeriodicity periodicity of the lattice structure.
  */
  virtual void SetPeriodicity(const double iPeriodicity) = 0;

  /**
   * Some rare TPMS pattern need more than one 'frequency' argument. For most
   * patterns (Gyroids...) these parameters won't be used.
   * @param iArgIndex index of the periodicity argument of the lattice structure.
   * @param iPeriodicityN value of the periodicity argument associated with index N.
   */
  virtual void SetArg(const int iArgIndex, const double iValue) = 0;
  
  /**
  * This parameter let you specify the width of the structure
  * that you want to get in the end (when partitioned body
  * with implicit specs is transformed to explicit geometry).
  * @param iWidth width of the desired structure.
  */
  virtual void SetThickness(const double iWidth) = 0;

  /**
 * In case you want to create a lattice structure with 3 domains, 2 separated empty
 * ones and one full (solid), you often need to specify contact faces for each empty domains.
 * This method allows you to set the contact faces for the first empty domain.
 * This information is used only when you use a DoubleCavity... CATTPMSType
 */
  virtual void SetSubDomain1OpenFaces(ListPOfCATFace& iCavity1ContactFaces) = 0;

  /**
   * In case you want to create a lattice structure with 3 domains, 2 separated empty
   * ones and one full (solid), you often need to specify contact faces for each empty domains.
   * This method allows you to set the contact faces for the second empty domain.
   * This information is used only when you use a DoubleCavity... CATTPMSType
   */
  virtual void SetSubDomain2OpenFaces(ListPOfCATFace& iCavity2ContactFaces) = 0;

  /**
  * In cases where a cylindrical symmetry is desired for the TPMS pattern,
  * is necessary to set this option to true.
  */
  virtual void SetCylindricalTransformation(const CATBoolean iCylindricalOption) = 0;

  /**
  * In cases where a cylindrical symmetry is desired for the TPMS pattern,
  * is necessary to define the cylindrical axis. This method allows the user to set
  * a point belonging to the cylindrical axis.
  */
  virtual void SetCylindricalTransformationAxisOrigin(const CATMathPoint& iCylindricalOrigin) = 0;

  /**
  * In cases where a cylindrical symmetry is desired for the TPMS pattern,
  * is necessary to define the cylindrical axis. This method allows the user to set
  * the cylindrical axis orientation.
  */
  virtual void SetCylindricalTransformationAxisOrientation(const CATMathVector& iCylindricalAxis) = 0;

  /**
  * In cases where a cylindrical symmetry is desired for the TPMS pattern,
  * is necessary to define the angular periodicity. This method allows the user to set
  * set this angular periodicity.
  */
  virtual void SetCylindricalTransformationPeriodicity(const double iCylindricalPeriodicity) = 0;

  /**
  * This argument let you specify how frequently the pattern will
  * appear in a given volume by defining a reference pattern length.
  * @param iPatternLength unitary cell length of the lattice pattern.
  */
  virtual void SetPatternLength(const double iPatternLength) = 0;

  /**
  * This method let you get the lower and higher boundary limits for
  * periodicity parameter value.
  * @param ioMinPeriodicity lower boundary value for periodicity.
  * @param ioMaxPeriodicity Higher boundary value for periodicity.
  */
  virtual HRESULT GetPeriodicityLimits(double& ioMinPeriodicity, double& ioMaxPeriodicity) = 0;

  /**
  * This method let you get the lower and higher boundary limits for
  * thickness parameter value.
  * @param ioMinThickness lower boundary value for Thickness.
  * @param ioMaxThickness Higher boundary value for Thickness.
  */
  virtual HRESULT GetThicknessLimits(double& ioMinThickness, double& ioMaxThickness) = 0;

  /**
  * This method let you know if the desired TPMS type is supported
  * @param iTPMSType the type of Triply Periodic Minimal Surface you want to use
  * to build a lattice structure.
  */
  virtual bool IsSupportedTPMSType(const CATTPMSType iTPMSType) = 0;

  //=============================================================================
  // Get additional information after Run
  //=============================================================================

protected:

  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATCreateTPMSTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATImplicitOperTopExt &iExtensible);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================

  CATCreateTPMSTopOper();
  CATCreateTPMSTopOper(const CATCreateTPMSTopOper& iOneOf);
  CATCreateTPMSTopOper& operator =(const CATCreateTPMSTopOper& iOneOf);
};

/**
 * Creates a CATCreateTPMSTopOper operator
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
ExportedByGMScalarFieldsOperators CATCreateTPMSTopOper * CATCreateCreateTPMSTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iInputBody);

#endif /* CATCreateTPMSTopOper_H */
