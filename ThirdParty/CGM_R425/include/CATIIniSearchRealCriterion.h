//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchRealCriterion_H
#define CATIIniSearchRealCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchRealCriterion;

/**
 * Interface to define a real-based attribute criterion. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on real attributes.
 * <br>This criterion has to be used to look for objects that have
 * a real type attribute (as defined through Knowledgeware).
 * <br>Such a criterion must always be used in conjunction with 
 * a @href CATIIniSearchTypeCriterion, as a second argument of the
 * @href CATIIniSearchAndCriterion#SetParameters criterion.
 */
class ExportedByUIModelInterfaces CATIIniSearchRealCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters
   * of the criterion.
   * @param iAttributeInternalName
   *    The internal name of the real attribute that is being looked for.
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
                                 double iAttributeValue,
                                 CATIniSearchEnumeration::Comparison iOperatingSign, 
                                 CATUnicodeString iAttributeNLSName="") = 0;

  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters
   * of the criterion.
   * It is to be used when looking for objects having a specified attribute, 
   * whose value belongs (or not) to a range of values.
   * @param iAttributeInternalName
   *    The internal name of the string attribute that is being looked for.
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
                                 double iAttributeValue1, double iAttributeValue2,
                                 CATIniSearchEnumeration::Comparison iOperatingSign, 
                                 CATUnicodeString iAttributeNLSName="") = 0;
};
#endif
