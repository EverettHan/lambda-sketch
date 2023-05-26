//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchListingCriterion_H
#define CATIIniSearchListingCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchListingCriterion;

/**
 * Interface to define a listing-based attribute criterion. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on listing attributes (for example when an 
 * attribute can have one value in a finite list of values).
 * <br>This criterion has to be used to look for objects that have
 * a listing-type attribute (as defined through Knowledgeware).
 * <br>Such a criterion must always be used in conjunction with 
 * a @href CATIIniSearchTypeCriterion, as a second argument of the
 * @href CATIIniSearchAndCriterion#SetParameters criterion.
 */
class ExportedByUIModelInterfaces CATIIniSearchListingCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters
   * of the listing-based attribute criterion.
   * @param iAttributeInternalName
   *    The internal name of the attribute that is being looked for.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>WorkbenchInternalName.TypeInternalName.iAttributeInternalName operator value</tt></li>
   * @param iAttributeValue
   *    The value associated to the attribute.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>the only authorized values are @href #Equal and @href #Different.
   * @param iAttributeNLSName
   *    This parameter is only required for printing out the query.
   *    <br>If no string is provided here, an NLS print of the query
   *    would display the attribute's NLS name, provided the query 
   *    has been run at least once on a document containing at least
   *    one object with the specified attribute. 
   * @param iValueNLSName
   *    This parameter is only required for printing out the query.
   *    <br>If no string is provided here, an NLS print of the query
   *    would display the attribute's NLS value, provided the query 
   *    has been run at least once on a document containing at least
   *    one object with the specified attribute. 
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iAttributeInternalName,
                                 const CATUnicodeString& iValueInternalName,
                                 CATIniSearchEnumeration::Comparison iOperatingSign, 
                                 CATUnicodeString iAttributeNLSName="",
                                 CATUnicodeString iValueNLSName="") = 0;

  /**
   * Retrives all the parameters of the criterion.
   * <br><b>Role:</b> This method Retrives all the parameters
   * of the listing-based attribute criterion.
   * @param oAttributeInternalName
   *    The internal name of the attribute that is being looked for.
   * @param oValueInternalName
   *    The value associated to the attribute.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>the only authorized values are @href #Equal and @href #Different.
   * @param oAttributeNLSName
   *    This parameter is only required for printing out the query.
   *    <br>If no string is provided here, an NLS print of the query
   *    would display the attribute's NLS name, provided the query 
   *    has been run at least once on a document containing at least
   *    one object with the specified attribute. 
   * @param oValueNLSName
   *    This parameter is only required for printing out the query.
   *    <br>If no string is provided here, an NLS print of the query
   *    would display the attribute's NLS value, provided the query 
   *    has been run at least once on a document containing at least
   *    one object with the specified attribute. 
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT GetParameters(CATUnicodeString& 	oAttributeInternalName, 	
								CATUnicodeString&	oValueInternalName,
								CATIniSearchEnumeration::Comparison	&oOperatingSign,
								CATUnicodeString 	& oAttributeNLSName,
								CATUnicodeString 	& oValueNLSName) = 0;
};
#endif
