//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchV4ModelCriterion_H
#define CATIIniSearchV4ModelCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchV4ModelCriterion;

/**
 * Interface to define a type-based criterion for V4 objects. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on objects whose type is of a V4 kind.
 */
class ExportedByUIModelInterfaces CATIIniSearchV4ModelCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method sets all the parameters of 
   * the criterion.
   * @param iV4TypesList
   *    The list of internal name for the V4 types to be looked for.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>WorkbenchInternalName.TypeInternalName.iAttributeInternalName operator value</tt></li>
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @param iNLSName
   *    This parameter is only required for printing out the query.
   *    <br>If no string is provided here, an NLS print of the query
   *    would display the attribute's NLS name, provided the query 
   *    has been run at least once on a document containing at least
   *    one object with the specified attribute. 
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters(const CATListOfCATUnicodeString& iV4TypesList, 
                                CATIniSearchEnumeration::Comparison iOperatingSign,
                                CATUnicodeString iNLSName="") = 0;
};
#endif
