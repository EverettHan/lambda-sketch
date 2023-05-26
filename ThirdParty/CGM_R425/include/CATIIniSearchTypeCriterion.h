//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchTypeCriterion_H
#define CATIIniSearchTypeCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchTypeCriterion;

/**
 * Interface to define a type-based search criterion. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on objects of a specified type.
 * <br>The type is defined through Knowledgeware.
 */
class CATIType;

class ExportedByUIModelInterfaces CATIIniSearchTypeCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets the type parameter using a CATIType pointer.
   * <br><b>Role:</b> This method sets the type parameter 
   * thanks to a pointer to @href CATIType representing the type of 
   * objects looked for.
   * @param iSearchedType
   *    A pointer to CATIType representing the type of objects.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @param iWorkbenchInternalName
   *    The internal name of the <tt>workbench</tt> to which the 
   *    type belongs (the NLS name is displayed in the Edit/Search
   *    command's user interface). 
   *    <br>This parameter is only required for printing out the query.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: iWorkbenchInternalName.TypeInternalName</li>
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (const CATIType* iSearchedType, 
                                 CATIniSearchEnumeration::Comparison iOperatingSign,
                                 CATUnicodeString iWorkbenchInternalName="") = 0;

  /**
   * Sets the type parameter using the type internal name.
   * <br><b>Role:</b> This method sets the type parameter 
   * thanks to a CATUnicodeString corresponding to the internal 
   * name of the type of object.
   * @param iSearchedTypeInternalName
   *    The internal name of a type of object.
   *    <br>For instance <tt>GSMScaling</tt> is the internal name 
   *    for the Generative Shape Design scaling operation.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @param iWorkbenchInternalName
   *    The internal name of the <tt>workbench</tt> to which the 
   *    type belongs (the NLS name is displayed in the Edit/Search
   *    command's user interface). 
   *    <br>This parameter is only required for printing out the query.
   *    <br>The internal workbench name corresponding to <tt>GSMScaling</tt>
   *    is <tt>CATPrtSearch</tt>.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: iWorkbenchInternalName.iSearchedTypeInternalName</li>
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iSearchedTypeInternalName, 
                                 CATIniSearchEnumeration::Comparison iOperatingSign,
                                 CATUnicodeString iWorkbenchInternalName="") = 0;

  /**
   * Retrives the type parameter using a CATIType pointer.
   * <br><b>Role:</b> This method Retrives the type parameter 
   * thanks to a pointer to @href CATIType representing the type of 
   * objects looked for.
   * @param oSearchedType
   *    A pointer to CATIType representing the type of objects.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @param oWorkbenchInternalName
   *    The internal name of the <tt>workbench</tt> to which the 
   *    type belongs (the NLS name is displayed in the Edit/Search
   *    command's user interface).
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT GetParameters(CATIType** oSearchedType, 	
								CATIniSearchEnumeration::Comparison	&oOperatingSign,
								CATUnicodeString 	&oWorkbenchInternalName) = 0;
};
#endif
