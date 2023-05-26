#ifndef CATCreateTPMSLimits_H
#define CATCreateTPMSLimits_H

#include "GMScalarFieldsOperators.h"

// System
#include "CATCollec.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

// CGM
#include "CATCGMVersionDefinition.h"
#include "CATICGMObject.h"
#include "CATBody.h"
#include "CATFace.h"
#include "CATShell.h"
#include "CATVolume.h"


// Scalar Fields
#include "SFTypes.h"
#include "CATImplicitResource.h"
#include "ScalarFieldsOperatorsCommon.h"

// GM Scalar Fields
#include "CATTPMSType.h"

// STD
#include <memory>

/**
 * Class exposes different methods that can be usefull to validate parameters given to the
 * CATCreateTPMSTopOper operator. At the moment that operator blocs the creation of TPMS
 * structures that would be difficult to convert to polyhedral representations. Internally
 * if does use this same class to validate if the provided inputs  should be allowed or not.
 *
 * As you will see we tried to make the method appear in the order you should follow in order
 * to query the values of the various settings you can use. Please bear in mind that in order
 * to call some of the query method you should have provided information to this class via
 * the various Set method that appear before that query method.
 * For example in order to use method like GetThicknessLimits you should have specified the
 * type of TPMS, the periodicity, whether you have sub domains faces...
 */
class ExportedByGMScalarFieldsOperators CATCreateTPMSLimits
{
public:

  typedef std::unique_ptr<CATCreateTPMSLimits>      UPtr;
  typedef std::shared_ptr<CATCreateTPMSLimits>      Ptr;

  /**
   * ctor
   *
   */
  CATCreateTPMSLimits(CATBody& iBody);

  /**
   * dtor
   */
  virtual ~CATCreateTPMSLimits();

  /**
   * Volume to which you plan to attach TPMS. This will need to be specified before
   * you can ask question to the service.
   * @param a CATVolume specifying the cavity to which we need to attach specs.
   */
  virtual void SetVolume(CATVolume* iCavityVolume);

  /**
   * CATCreateTPMSTopOper can be used in two different modes. Default mode is when
   * you don't specify any Faces either through SetSubDomain1OpenFaces/SetSubDomain2OpenFaces
   * in that case the supported parameters might be slightly different from what is supported
   * in the other mode. So if you plan to use the mode to generate thermal exchanger with two
   * fluids you should call here these two methods first in order to be able to query the allowed
   * values.
   */
  virtual void SetSubDomain1OpenFaces(ListPOfCATFace& iCavity1ContactFaces);

  /**
   * CATCreateTPMSTopOper can be used in two different modes. Default mode is when
   * you don't specify any Faces either through SetSubDomain1OpenFaces/SetSubDomain2OpenFaces
   * in that case the supported parameters might be slightly different from what is supported
   * in the other mode. So if you plan to use the mode to generate thermal exchanger with two
   * fluids you should call here these two methods first in order to be able to query the allowed
   * values.
   */
  virtual void SetSubDomain2OpenFaces(ListPOfCATFace& iCavity2ContactFaces);

  /**
   * This method let you know if the desired TPMS type is supported.
   * @param iTPMSType the type of Triply Periodic Minimal Surface you want to use
   * to build a lattice structure.
   */
  virtual bool IsSupportedTPMSType(const CATTPMSType iTPMSType);

  /**
   * Before specifying the type of Lattice you should use IsSupportedTPMSType in order to verify
   * if the type of TPMS you are planning to use is supported in the choosen mode
   * (which depends on wether you have provided faces with SetSubDomain1OpenFaces and
   * SetSubDomain2OpenFaces.
   * @param iTPMSType a type of TPMS to be used to build lattice structure.
   */
  virtual void SetTPMSType(const CATTPMSType iTPMSType);

  /**
   * This method let you get the lower and higher boundary limits for
   * periodicity parameter value.
   * @param ioMinPeriodicity lower boundary value for periodicity.
   * @param ioMaxPeriodicity Higher boundary value for periodicity.
   */
  virtual HRESULT GetPeriodicityLimits(double& ioMinPeriodicity, double& ioMaxPeriodicity);

  /**
   * This method let you get the lower and higher boundary limits for
   * periodicity parameter value.
   * @param ioMinPeriodicity lower boundary value for periodicity.
   * @param ioMaxPeriodicity Higher boundary value for periodicity.
   */
  virtual HRESULT GetPatternLength(double& ioMinPatternLength, double& ioMaxPatternLength);

  /**
  * This argument let you specify how frequently the pattern will
  * appear in a given volume you should set it here to finish querying the limits
  * that you can indeed use with CATCreateTPMSTopOper operators.
  * @param iPeriodicity periodicity of the lattice structure.
  */
  virtual void SetPeriodicity(const double iPeriodicity);

    /**
  * This argument let you specify how frequently the pattern will
  * appear in a given volume by specifying the dimension of the unit cell.
  * You should set it here to finish querying the limits
  * that you can indeed use with CATCreateTPMSTopOper operators.
  * @param iPeriodicity periodicity of the lattice structure.
  */
  virtual void SetPatternLength(const double iPatternLength);

  /**
   * Some rare TPMS pattern need more than one 'frequency' argument. For most
   * patterns (Gyroids...) these parameters won't be used.
   * @param iArgIndex index of the periodicity argument of the lattice structure.
   * @param iPeriodicityN value of the periodicity argument associated with index N.
   */
  virtual void SetArg(const int iArgIndex, const double iValue);

  /**
  * This parameter let you specify the width of the structure
  * that you want to get in the end (when partitioned body
  * with implicit specs is transformed to explicit geometry).
  * @param iWidth width of the desired structure.
  */
  virtual void SetThickness(const double iWidth);

  /**
  * This method let you get the lower and higher boundary limits for
  * thickness parameter value.
  * @param ioMinThickness lower boundary value for Thickness.
  * @param ioMaxThickness Higher boundary value for Thickness.
  */
  virtual HRESULT GetThicknessLimits(double& ioMinThickness, double& ioMaxThickness);

private:

  CATBody&                    _inputBody;
  CATVolume*                  _volume;
  CATTPMSType                 _tpmsType;
  double                      _periodicity;
  CATListOfDouble             _args;
  double                      _thickness;
  double                      _interWallDistance;
  ListPOfCATFace              _subDomain1OpenFaces;
  ListPOfCATFace              _subDomain2OpenFaces;

};

#endif // CATCreateTPMSLimits_H
