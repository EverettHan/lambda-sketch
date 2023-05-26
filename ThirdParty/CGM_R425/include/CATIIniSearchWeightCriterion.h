//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
// Création par Johann Chemin (JAC)
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchWeightCriterion_H
#define CATIIniSearchWeightCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"

#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchWeightCriterion;

/**
 * Interface to define a search criterion based on lines' weight. 
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion on the weight graphic attributes of lines.
 * <br>Only objects that have the <tt>CATVPLine</tt> graphic property attribute
 * implemented by the <tt>CATIVisProperties</tt> interface are taken into account
 * in the search results.
 */
class ExportedByUIModelInterfaces CATIIniSearchWeightCriterion : public CATIIniSearchCriterion
{
  CATDeclareInterface;

public:
  /**
   * Sets the weight parameter using a character string.
   * <br><b>Role:</b> This method sets the weight parameter 
   * thanks to a CATUnicodeString representing either the 
   * value in millimeters, or the index.
   * @param iWeightString
   *    The string representing the value.
   *    <br>It could be in the following formats: <b><tt>2.3mm</tt></b>
   *    or <b><tt>3</tt></b>.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>Weight iOperatingSign iWeightString</tt></li>
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All the values are authorized.
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (const CATUnicodeString& iWeightString,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Sets the weight parameter using a millimeter value.
   * <br><b>Role:</b> This method sets the weight parameter 
   * thanks to a float representing the value in millimeters.
   * @param immValue
   *    The value in millimeters.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All the values are authorized.
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (float immValue,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

  /**
   * Sets the weight parameter using the weight index.
   * <br><b>Role:</b> This method sets the weight parameter
   *  using its index.
   * @param iIndexValue
   *    The index representing the value.
   * @param iOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All the values are authorized.
   * @return 
   *    E_FAIL if the criterion is not correctly set up.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT SetParameters (int iIndexValue,
                                 CATIniSearchEnumeration::Comparison iOperatingSign) = 0;

   /**
   * Gets the weight parameter using a character string.
   * <br><b>Role:</b> This method gets the weight parameter 
   * thanks to a CATUnicodeString representing either the 
   * value in millimeters, or the index.
   * @param oWeightString
   *    The string representing the value.
   *    <br>It could be in the following formats: <b><tt>2.3mm</tt></b>
   *    or <b><tt>3</tt></b>.
   *    <br>To retrieve this piece of information you can proceed as follows:
   *    <li>Record a macro command on a scenario based on the Edit/Search 
   *    command with your Search query as input (NLS based query).</li>
   *    <li>Check the macro file. It contains the query under the following
   *    format: <tt>Weight oOperatingSign iWeightString</tt></li>
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All the values are authorized.
   * @return 
   *    E_FAIL if the criterion is not correctly retrieved.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT GetParameters(CATUnicodeString& 	oWeightString, 	
					                            CATIniSearchEnumeration::Comparison	&oOperatingSign)	=	0;

   /**
   * Gets the weight parameter using the weight index.
   * <br><b>Role:</b> This method gets the weight parameter
   *  using its index.
   * @param oIndexValue
   *    The index representing the value.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All the values are authorized.
   * @return 
   *    E_FAIL if the criterion is not correctly retrieved.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT GetParameters(int& iIndexValue,
											   CATIniSearchEnumeration::Comparison	&oOperatingSign)	=	0;

  /**
   * Gets the weight parameter using a millimeter value.
   * <br><b>Role:</b> This method gets the weight parameter 
   * thanks to a float representing the value in millimeters.
   * @param ommValue
   *    The value in millimeters.
   * @param oOperatingSign
   *    The value corresponding to the desired operating sign.
   *    <br>All the values are authorized.
   * @return 
   *    E_FAIL if the criterion is not correctly retrieved.
   *    <br>S_OK otherwise.
   */
  virtual HRESULT GetParameters(float& immValue,
											   CATIniSearchEnumeration::Comparison	&oOperatingSign)	=	0;
};
#endif
