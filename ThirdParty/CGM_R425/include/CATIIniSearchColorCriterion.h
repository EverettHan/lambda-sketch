//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchColorCriterion_H
#define CATIIniSearchColorCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchColorCriterion;

/**
 * Interface to define a color-based search criterion. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion based on the color graphic attribute.
 * <br>The objects found will match the color and operating 
 * sign, as specified in the @href #SetParameters method.
 * <br>Only objects that have the color graphic property attribute
 * implemented by the <tt>CATIVisProperties</tt> interface are taken
 * into account in the search results. Their assumed color is the one
 * displayed in the graphic property toolbar.
 */
class ExportedByUIModelInterfaces CATIIniSearchColorCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets the color parameters using the RGB code.
   * <br><b>Role:</b> This method sets the color parameters 
   * thanks to its RGB code.
   * @param iRed
   *    The red component of the color's RGB code. 
   *    <br>It must be located between 0 and 255.
   * @param iGreen
   *    The green component of the color's RGB code. 
   *    <br>It must be located between 0 and 255.
   * @param iBlue
   *    The blue component of the color's RGB code. 
   *    <br>It must be located between 0 and 255.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are <tt>Equal</tt> and <tt>Different</tt>.
   * @param iColorString
   *    This parameter is to be used only for the NLS print out of the query.
   *    <br>If it is not provided, the RGB code will be used for the print out.
   *    Refer to @href CATIIniSearchCriterion#GetNLSQuery .
   *    <br>This information can be retrieved from the 
   *    @href #FindColorNameFromRGBColorCode method.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (unsigned int iRed, unsigned int iGreen, unsigned int iBlue,
                                 CATIniSearchEnumeration::Comparison iOperatingSign,
                                 CATUnicodeString iColorString="") = 0;

  /**
   * Retrives the color parameters using the RGB code.
   * <br><b>Role:</b> This method Retrives the color parameters 
   * thanks to its RGB code.
   * @param oRed
   *    The red component of the color's RGB code. 
   *    <br>It must be located between 0 and 255.
   * @param oGreen
   *    The green component of the color's RGB code. 
   *    <br>It must be located between 0 and 255.
   * @param oBlue
   *    The blue component of the color's RGB code. 
   *    <br>It must be located between 0 and 255.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are <tt>Equal</tt> and <tt>Different</tt>.
   * @param oColorString
   *    This parameter is to be used only for the NLS print out of the query.
   *    <br>If it is not provided, the RGB code will be used for the print out.
   *    Refer to @href CATIIniSearchCriterion#GetNLSQuery .
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT GetParameters (unsigned int&	oRed,
								unsigned int&	oGreen,
								unsigned int&	oBlue,
								CATIniSearchEnumeration::Comparison	&oOperatingSign,
								CATUnicodeString&	oColorString)= 0;

  /**
   * Retrieves the object's RGB color code.
   * <br><b>Role:</b> This method retrieves the RGB color code
   * of an object.
   * @param iObject
   *    The object implementing <tt>CATIVisProperties</tt> from 
   *    which the color code will be retrieved.
   * @param oColors
   *    The RGB color code, as a size-3 integer array.
   *    <br>The caller has to delete the returned pointer.
   *    <br>If the return code is a failure, this pointer is NULL.
   * @return
   *    <ul><li>S_OK if the color has been found.</li>
   *    <li>E_FAIL otherwise.</li></ul>
   */
  virtual HRESULT FindRGBColorCodeFromObject(const CATBaseUnknown_var& iObject, 
                                             unsigned int*& oColors) = 0;

  /**
   * Retrieves a color's name from the RGB code.
   * <br><b>Role:</b> This method retrieves the color's name
   * from its RGB code.
   * @param iColors
   *    A size-3 integer array representing the RGB code.
   * @param oName
   *    The name of the color corresponding to the RGB code.
   * @return 
   *    <ul><li>S_OK if the RGB code corresponds to a basic or a customized color.</li>
   *    <li>E_FAIL otherwise.</li></ul>
   */
   virtual HRESULT FindColorNameFromRGBColorCode(unsigned int const * iColors, 
                                                 CATUnicodeString& oName) = 0;
};
#endif
