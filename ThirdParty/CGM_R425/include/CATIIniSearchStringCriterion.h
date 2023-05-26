//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchStringCriterion_H
#define CATIIniSearchStringCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"
#include "CATBoolean.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchStringCriterion;

/**
 * Interface to define a string-based attribute criterion. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on string attributes.
 * <br>This criterion has to be used to look for objects that have
 * a string type attribute (as defined through Knowledgeware).
 * <br>Such a criterion must always be used in conjunction with 
 * a @href CATIIniSearchTypeCriterion, as a second argument of the
 * @href CATIIniSearchAndCriterion#SetParameters criterion.
 */
class ExportedByUIModelInterfaces CATIIniSearchStringCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters of 
   * the criterion.
   * @param iAttributeInternalName
   *    The internal name of the string attribute that is being looked for.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>WorkbenchInternalName.TypeInternalName.iAttributeInternalName operator value</tt></li>
   * @param iAttributeValue
   *    The value associated to the attribute.
   *    <br>The @href CATIIniSearchServices#GetWildCardCharacter character replaces
   *    from 0 to n characters. If this character is a character by itself, enclose it 
   *    within single quotes. If the quote character is a character by itself, double it.
   *    The easiest is to use the @href CATIIniSearchServices#CorrectString
   *    service.
   * @param iCaseSensitivity
   *    If the case of iAttributeValue is to be respected, the value must be TRUE.
   *    Otherwise, it must be set to FALSE.
   *    <br><b>Example:</b><br> If you are looking for objects whose name contains the 
   *    <tt>Shell</tt> string, without objects whose name contains the <tt>shell</tt>
   *    string, the value should be set to TRUE.
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
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iAttributeInternalName,
                                 const CATUnicodeString& iAttributeValue,
                                 CATBoolean iCaseSensitivity,
                                 CATIniSearchEnumeration::Comparison iOperatingSign, 
                                 CATUnicodeString iAttributeNLSName="") = 0;

  /**
   * Retrives all the parameters of the criterion.
   * <br><b>Role:</b> This method Retrives all the parameters of 
   * the criterion.
   * @param oAttributeInternalName
   *    The internal name of the string attribute that is being looked for.
   * @param oAttributeValue
   *    The value associated to the attribute.o
   * @param oCaseSensitivity
   *    If the case of oAttributeValue is to be respected, the value must be TRUE.
   *    Otherwise, it must be FALSE.
   *    <br><b>Example:</b><br> If you are looking for objects whose name contains the 
   *    <tt>Shell</tt> string, without objects whose name contains the <tt>shell</tt>
   *    string, the value should be set to TRUE.
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
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT GetParameters(CATUnicodeString& 	oAttributeInternalName, 	
								CATUnicodeString&	oAttributeValue,
								CATBoolean 	&oCaseSensitive,
								CATIniSearchEnumeration::Comparison	&oOperatingSign,
								CATUnicodeString 	& oAttributeNLSName) = 0;
};
#endif
