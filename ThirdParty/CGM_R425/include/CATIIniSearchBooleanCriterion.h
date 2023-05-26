//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchBooleanCriterion_H
#define CATIIniSearchBooleanCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"
#include "CATBoolean.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchBooleanCriterion;

/**
 * Interface to define a boolean-based attribute criterion. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on boolean attributes.
 * <br>This criterion has to be used to look for objects that have
 * a boolean type attribute (as defined through Knowledgeware).
 * <br>This criterion has to be used to look for objects that have
 * a boolean type attribute (as defined through Knowledgeware).
 * <br>Such a criterion must always be used in conjunction with 
 * a @href CATIIniSearchTypeCriterion, as a second argument of the
 * @href CATIIniSearchAndCriterion#SetParameters criterion.
 */
class ExportedByUIModelInterfaces CATIIniSearchBooleanCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters
   * of the criterion.
   * @param iAttributeInternalName
   *    The internal name of the boolean attribute that is being looked for.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>WorkbenchInternalName.TypeInternalName.iAttributeInternalName operator value</tt></li>
   * @param iAttributeValue
   *    The value associated to the attribute. 
   *    <br>It can either be TRUE (or 1), or FALSE (0).
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
                                 CATBoolean iAttributeValue, 
                                 CATIniSearchEnumeration::Comparison iOperatingSign,
                                 CATUnicodeString iAttributeNLSName="") = 0;
  /**
   * Retrives all the parameters of the criterion.
   * <br><b>Role:</b> This method Retrives all the parameters
   * of the criterion.
   * @param oAttributeInternalName
   *    The internal name of the boolean attribute that is being looked for.
   * @param oAttributeValue
   *    The value associated to the attribute. 
   *    <br>It can either be TRUE (or 1), or FALSE (0).
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
  virtual HRESULT GetParameters (CATUnicodeString& 	oAttributeInternalName, 	
								 CATBoolean 	&oAttributeValue,
								 CATIniSearchEnumeration::Comparison	&oOperatingSign,
								 CATUnicodeString 	& oAttributeNLSName) = 0;
};
#endif
