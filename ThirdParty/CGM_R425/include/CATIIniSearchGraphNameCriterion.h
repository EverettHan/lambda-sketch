//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002-2007
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchGraphNameCriterion_H
#define CATIIniSearchGraphNameCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"
#include "CATBoolean.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchGraphNameCriterion;

/**
 * Interface to define a graph name-based search criterion. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on names as displayed in the specification tree,
 * and supported by the @href CATINavigateObject interface.
 */
class ExportedByUIModelInterfaces CATIIniSearchGraphNameCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method completely defines all the 
   * parameters of the graph search criterion.
   * @param iName
   *    The name that is being looked for. 
   *    The @href CATIIniSearchServices#GetWildCardCharacter method gives the wild 
   *    card character that replaces from 0 to n characters. If this character
   *    is a character by itself, enclose it within single quotes. 
   *    If the quote character is a character by itself, double it.
   *    The easiest is to use the @href CATIIniSearchServices#CorrectString
   *    service.
   *    <br><b>Example:</b><br> If you are looking for objects that are called
   *    <tt>You're a *</tt>, the string passed should be <tt>You''re a '*'</tt>.
   * @param iCaseSensitivity
   *    If the case of iName is to be respected, the value must be TRUE.
   *    Otherwise, it must be set to FALSE.
   *    <br><b>Example:</b><br> If you are looking for objects whose name contains the 
   *    <tt>Shell</tt> string, without objects whose name contains the <tt>shell</tt>
   *    string, the value should be set to TRUE.
   * @param iCodeSensitivity
   *    Some languages (Japanese for example) use two different unicode values for the
   *    same character depending on whether the user types it using Double-byte
   *    or Single-byte.
   *    If such characters must be considered as different, the value must be TRUE.
   *    Otherwise, it must be set to FALSE.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only possible values are Equal and Different.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up: usually if iName is a 
   *    0-length CATUnicodeString, or if the iOperatingSign is not correct.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iName, 
                                 CATBoolean iCaseSensitivity,
                                 CATBoolean iCodeSensitivity,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Sets all the parameters of the criterion.
   * <br><b>Role:</b> This method completely defines all the 
   * parameters of the graph search criterion.
   * @param iName
   *    The name that is being looked for. 
   *    The @href CATIIniSearchServices#GetWildCardCharacter method gives the wild 
   *    card character that replaces from 0 to n characters. If this character
   *    is a character by itself, enclose it within single quotes. 
   *    If the quote character is a character by itself, double it.
   *    The easiest is to use the @href CATIIniSearchServices#CorrectString
   *    service.
   *    <br><b>Example:</b><br> If you are looking for objects that are called
   *    <tt>You're a *</tt>, the string passed should be <tt>You''re a '*'</tt>.
   * @param iCaseSensitivity
   *    If the case of iName is to be respected, the value must be TRUE.
   *    Otherwise, it must be set to FALSE.
   *    <br><b>Example:</b><br> If you are looking for objects whose name contains the 
   *    <tt>Shell</tt> string, without objects whose name contains the <tt>shell</tt>
   *    string, the value should be set to TRUE.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only possible values are Equal and Different.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up: usually if iName is a 
   *    0-length CATUnicodeString, or if the iOperatingSign is not correct.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iName, 
                                 CATBoolean iCaseSensitivity,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;
};
#endif
