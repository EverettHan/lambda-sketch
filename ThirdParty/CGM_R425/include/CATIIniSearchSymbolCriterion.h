#ifndef CATIIniSearchSymbolCriterion_H
#define CATIIniSearchSymbolCriterion_H
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchSymbolCriterion;

/**
 * Interface to define a search criterion based on lines' Symbol. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on the Symbol graphic attributes of lines.
 * <br>Only objects that have the <tt>CATVPLine</tt> graphic property attribute
 * implemented by the <tt>CATIVisProperties</tt> interface are taken into account
 * in the search results.
 */
class ExportedByUIModelInterfaces CATIIniSearchSymbolCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets the symbol parameter using a character string.
   * <br><b>Role:</b> This method sets the symbol parameter 
   * thanks to a CATUnicodeString representing either the 
   * NLS name, or the index.
   * @param iSymbolString
   *    The string representing the value.
   *    <br>It could be in the following formats: 
   *    <ul><li>either the NLS format, <b><tt>Cross</tt></b>, which can be retrieved from the Edit/Search user interface.</li>
   *    <li>or the Transformat format, <b><tt>3</tt></b>.</li></ul>
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>Symbol iOperatingSign iSymbolString</tt></li>
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All the values are authorized.
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iSymbolString,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Sets the Symbol parameter using the Symbol index.
   * <br><b>Role:</b> This method sets the Symbol parameter
   *  using its index.
   * @param iSymbolIndex
   *    The index representing the type of point symbol.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>Symbol iOperatingSign iSymbolIndex</tt></li>
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All the values are authorized.
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (unsigned int iSymbolIndex,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;
};
#endif
