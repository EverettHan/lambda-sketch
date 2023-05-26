//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchDashedCriterion_H
#define CATIIniSearchDashedCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchDashedCriterion;

/**
 * Interface to define a search criterion based on line types. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on the dashed graphic attribute associated with lines.
 * <br>Only objects that have the <tt>CATVPLine</tt> graphic property attribute
 * implemented by the <tt>CATIVisProperties</tt> interface are taken into account
 * in the search results.
 */
class ExportedByUIModelInterfaces CATIIniSearchDashedCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets the dashed parameter using a character string.
   * <br><b>Role:</b> This method sets the dashed parameter 
   * thanks to a CATUnicodeString representing either the 
   * NLS name, or the index.
   * @param iDashedString
   *    The string representing the value.
   *    <br>It could be in the following formats: 
   *    <ul><li>either the NLS format, <b><tt>Dotted</tt></b>, which can be retrieved from the Edit/Search user interface.</li>
   *    <li>or the Transformat format, <b><tt>3</tt></b>.</li></ul>
   *    <br>To retrieve this last piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>Dashed iOperatingSign iDashedString</tt></li>
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (const CATUnicodeString & iDashedString,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;
 
  /**
   * Sets the dashed parameter using the index value.
   * <br><b>Role:</b> This method sets the dashed parameter 
   * thanks to the index value.
   * @param iDashedIndex
   *    The index representing the type of dashed line.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>Dashed iOperatingSign iDashedIndex</tt></li>
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT SetParameters (unsigned int iDashedIndex,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Retrives the dashed parameter using the index value.
   * <br><b>Role:</b> This method Retrives the dashed parameter 
   * thanks to the index value.
   * @param oDashedString
   *    The index representing the type of dashed line.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>The only authorized values are Equal and Different.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up.</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT GetParameters (CATUnicodeString& 	oDashedString, 	
								 CATIniSearchEnumeration::Comparison	&oOperatingSign) = 0;
};
#endif
