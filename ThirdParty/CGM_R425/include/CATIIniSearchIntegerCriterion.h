//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchIntegerCriterion_H
#define CATIIniSearchIntegerCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchIntegerCriterion;

/**
 * Interface to define an integer-based attribute criterion.
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on integer attributes.
 * <br>This criterion has to be used to look for objects that have
 * a integer-type attribute (as defined through Knowledgeware).
 * <br>Such a criterion must always be used in conjunction with 
 * a @href CATIIniSearchTypeCriterion, as a second argument of the
 * @href CATIIniSearchAndCriterion#SetParameters criterion.
 */
class ExportedByUIModelInterfaces CATIIniSearchIntegerCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters
   * of the criterion.
   * @param iAttributeInternalName
   *    The internal name of the integer attribute that is being looked for.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>WorkbenchInternalName.TypeInternalName.iAttributeInternalName operator value</tt></li>
   * @param iAttributeValue
   *    The value associated to the attribute.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All values are authorized.
   * @param iAttributeNLSName
   *    This parameter is only required for printing out the query.
   *    <br>If no string is provided here, an NLS print of the query
   *    would display the attribute's NLS name, provided the query 
   *    has been run at least once on a document containing at least
   *    one object with the specified attribute. 
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iAttributeInternalName,
                                 int iAttributeValue, 
                                 CATIniSearchEnumeration::Comparison iOperatingSign, 
                                 CATUnicodeString iAttributeNLSName="") = 0;

  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters
   * of the criterion.
   * It is to be used when looking for objects having a specified attribute, 
   * whose value belongs (or not) to a range of values.
   * @param iAttributeInternalName
   *    The internal name of the integer attribute that is being looked for.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>WorkbenchInternalName.TypeInternalName.iAttributeInternalName operator value</tt></li>
   * @param iAttributeValue1
   *    The lower limit value of the range. It is included in the search.
   * @param iAttributeValue2
   *    The upper limit value of the range. It is included in the search.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @param iAttributeNLSName
   *    This parameter is only required for printing out the query.
   *    <br>If no string is provided here, an NLS print of the query
   *    would display the attribute's NLS name, provided the query 
   *    has been run at least once on a document containing at least
   *    one object with the specified attribute. 
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iAttributeInternalName,
                                 int iAttributeValue1, int iAttributeValue2,
                                 CATIniSearchEnumeration::Comparison iOperatingSign, 
                                 CATUnicodeString iAttributeNLSName="") = 0;

  /**
   * Retrives all the parameters of the criterion.
   * <br><b>Role:</b> This method Retrives all the parameters
   * of the criterion.
   * It is to be used when looking for objects having a specified attribute, 
   * whose value belongs (or not) to a range of values.
   * @param oAttributeInternalName
   *    The internal name of the integer attribute that is being looked for.
   * @param oValuetype
   *    It gives us value in form "Range" or "NotRange" it depends on whether
   *    oAttributeValue1 and oAttributeValue2 are both present i.e. range.
   *    If only one of them is present means not range.
   * @param oAttributeValue1
   *    The lower limit value of the range. It is included in the search.
   * @param oAttributeValue2
   *    The upper limit value of the range. It is included in the search.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @param oAttributeNLSName
   *    This parameter is only required for printing out the query.
   *    <br>If no string is provided here, an NLS print of the query
   *    would display the attribute's NLS name, provided the query 
   *    has been run at least once on a document containing at least
   *    one object with the specified attribute. 
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT GetParameters(CATUnicodeString& 	oAttributeInternalName, 	
								CATUnicodeString&	oValuetype ,
								int 	&oAttributeValue1,
								int 	&oAttributeValue2,
								CATIniSearchEnumeration::Comparison	&oOperatingSign,
								CATUnicodeString 	& oAttributeNLSName) = 0;
};
#endif