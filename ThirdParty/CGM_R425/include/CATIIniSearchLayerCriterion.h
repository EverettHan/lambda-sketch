//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchLayerCriterion_H
#define CATIIniSearchLayerCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchLayerCriterion;

/**
 * Interface to define a layer-based search criterion. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on the layer attribute.
 * <br>The objects found will match the layer number and operating 
 * sign, as specified in the @href #SetParameters method.
 */
class ExportedByUIModelInterfaces CATIIniSearchLayerCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters
   * of the criterion.
   * @param iLayer
   *    The layer number for objects to be found.
   *    <br>It can be a number or <tt>NoneLayer</tt>, if the criterion
   *    is for objects that do not belong to any layer.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All values are authorized.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iLayer,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Retrives all the parameters of the criterion.
   * <br><b>Role:</b> This method Retrives all the parameters
   * of the criterion.
   * @param oLayer
   *    The layer number for objects to be found.
   *    <br>It can be a number or <tt>NoneLayer</tt>, if the criterion
   *    is for objects that do not belong to any layer.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All values are authorized.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT  GetParameters(CATUnicodeString& 	oLayer, 	
								 CATIniSearchEnumeration::Comparison	&oOperatingSign) = 0;
};
#endif
