//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchVisibilityCriterion_H
#define CATIIniSearchVisibilityCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchVisibilityCriterion;

/**
 * Interface to define a visibility-based criterion.
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on the visibility graphic attribute.
 * <br>The objects found will match the visibility and operating 
 * sign, as specified in the @href #SetParameters method.
 * <br>Objects that do not have this graphic attribute are excluded
 * from the search results, whatever is the chosen operating sign.
 */
class ExportedByUIModelInterfaces CATIIniSearchVisibilityCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Enumeration of available visibility types.
   * <br>The following types are allowed:
   * @param CATShowAttr
   *     for objects that are visible.
   * @param CATNoShowAttr
   *     for objects that are invisible.
   */
  enum ShowAttribut {  CATShowAttr, CATNoShowAttr };

  /**
   * Sets the visibility parameter using a character string.
   * <br><b>Role:</b> This method sets the visibility parameter 
   * thanks to a CATUnicodeString representing the visibility 
   * status.
   * @param iVisibilityString
   *    The string representing the visibility status. The case used is not
   *    important.
   *    <br>It can either be the transformat values <tt>visible</tt> or 
   *    <tt>hidden</tt>
   *    <br>or, the user can use a language specific name (displayed in
   *    the Edit/Search user interface). However the criterion would then 
   *    only work in an application session using this language.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iVisibilityString, 
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Sets the visibility parameter using an enumeration value.
   * <br><b>Role:</b> This method sets the visibility parameter 
   * thanks to an enumeration representing the visibility status.
   * @param iVisible
   *    The enumeration representing the visibility status.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (CATIIniSearchVisibilityCriterion::ShowAttribut iVisible, 
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Gets the visibility parameter using an enumeration value.
   * <br><b>Role:</b> This method gets the visibility parameter 
   * thanks to an enumeration representing the visibility status.
   * @param oVisibility
   *    The enumeration representing the visibility status.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @return 
   *    E_FAIL if the criterion is not correctly retrieved.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT GetParameters(CATIIniSearchVisibilityCriterion::ShowAttribut 	&oVisibility, 	
								CATIniSearchEnumeration::Comparison	&oOperatingSign) = 0;
};
#endif
