//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
//Pas exposée pour le moment
#ifndef CATIIniSearchSelectionSetCriterion_H
#define CATIIniSearchSelectionSetCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"
#include "CATBoolean.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchSelectionSetCriterion;

/**
 * Interface to define a selection set-based <b>attribute criterion</b>. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on the selection set attribute.
 * <br>The user defines that the objects found will belong (or not, 
 * depending on the operating sign) to the specified selection set.
 */
class ExportedByUIModelInterfaces CATIIniSearchSelectionSetCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets the selection set parameter using a character string.
   * <br><b>Role:</b> This method sets the selection set parameter 
   * thanks to a CATUnicodeString representing the name of the 
   * selection set.
   * @param iSelectionSetName
   *    The string representing the name of the selection set.
   *    <br>The wild card character <tt>*</tt> can be used.
   * @param iCaseSensitivity
   *    If the case in the iSelectionSetName is important, the 
   *    parameter should be set to <tt>TRUE</tt>. 
   *    <br>Otherwise set it to <tt>FALSE</tt>.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iSelectionSetName, 
                                 CATBoolean iCaseSensitivity,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;
};
#endif
