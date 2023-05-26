//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchUserCriterion_H
#define CATIIniSearchUserCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchUserCriterion;

/**
 * Interface to define a search criterion based on user-defined attributes.
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion for a user-defined attribute.
 * <br>This criterion has to be used to look for objects that have
 * a user-defined type attribute (as defined through Knowledgeware).
 * <br>Such a criterion must always be used in conjunction with 
 * a @href CATIIniSearchTypeCriterion, as a second argument of the
 * @href CATIIniSearchAndCriterion#SetParameters criterion.
 */
class ExportedByUIModelInterfaces CATIIniSearchUserCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters
   * of the criterion.
   * @param iAttributeName
   *    The name that was given to the user-defined attribute.
   * @param iAttributeValue
   *    The value associated to the attribute.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The authorized values depend on the attribute's type 
   *    (integer, listing, string, etc.).
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iAttributeName,
                                 const CATUnicodeString& iAttributeValue,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Retrives all the parameters of the criterion.
   * <br><b>Role:</b> This method Retrives all the parameters
   * of the criterion.
   * @param oAttributeName
   *    The name that was given to the user-defined attribute.
   * @param oAttributeValue
   *    The value associated to the attribute.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The authorized values depend on the attribute's type 
   *    (integer, listing, string, etc.).
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT GetParameters(CATUnicodeString& 	oAttributeName,
								CATUnicodeString 	&oAttributeValue,	
								CATIniSearchEnumeration::Comparison	&oOperatingSign) = 0;
};
#endif
