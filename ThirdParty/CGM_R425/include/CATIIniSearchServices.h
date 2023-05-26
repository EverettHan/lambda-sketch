//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES   2002
//=============================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchServices_H
#define CATIIniSearchServices_H

// System framework
#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

// InteractiveInterfaces framework
#include "CATIIniSearchCriterion.h"
#include "CATIIniSearchContext.h"
#include "UIModelInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchServices;
#else
extern "C" const IID IID_CATIIniSearchServices;
#endif

/**
 * Class providing general services for analysing a query (string format 
 * of a criterion).
 * <b>Role</b>: This class offers different services to generate a criterion
 * from a query.
 * <br>A query is a string format of a criterion. There exist two kinds of 
 * queries: 
 * <br>
 * <li><b>NLS</b> queries are dependant on the session's language</li>, 
 * <li><b>TransFormat</b> queries are independant on this parameters.</li>
 * <br><br>
 * NLS queries are useful in a user interface, whether TransFormat queries
 * are useful for a stable and language independant view. TransFormat queries
 * can be used in .CATSettings files, in a code definition of a query for instance.
 */
class ExportedByUIModelInterfaces CATIIniSearchServices : public IUnknown
{
public:
  /**
   * Decodes a query into a criterion.
   * <br><b>Role</b>: This service enables the conversion of a query without 
   * context into a Search criterion. In addition, there is the possibility
   * to display a pop-up window on the screen in case the query is incorrect:
   * the message would indicate where the errors lay.
   * <br><br>
   * <b>Example</b>: 
   * <br>Let us consider the following NLS query: <tt>Name=*1</tt>.
   * <br>This service would decompose it as a CATIIniSearchNameCriterion pointer, 
   * and return S_OK.
   * <br><br>
   * Let us consider the following TransFormat query: <tt>CATPrtSearch.Pad</tt>.
   * <br>This service would decompose it as a CATIIniSearchTypeCriterion pointer, 
   * and return S_OK.
   * <br><br>
   * Let us consider the following incorrect NLS query: <tt>NameWithTypo=*1</tt>.
   * <br>It is impossible to decompose this query. Hence, a pop-up window would
   * show up (if iDisplayMessage==TRUE), and E_FAIL would be returned.
   * @param iQueryString
   *    The NLS or TransFormat query corresponding to the criterion.
   * @param iDisplayMessage
   *    A CATBoolean to indicate if a pop-up window should be displayed in 
   *    case the query is incorrect.
   * @param oCriterion
   *    The Search criterion generated from the NLS or TransFormat query.
   * @return 
   *    <ul><li>S_OK if the conversion is successful.</li>
   *    <li>E_FAIL otherwise. The pointer to CATIIniSearchCriterion is then NULL.</li></ul>
   */
  virtual HRESULT DecodeStringToCriterion(const CATUnicodeString& iQueryString,
                                          CATBoolean iDisplayMessage,
                                          CATIIniSearchCriterion*& oCriterion) = 0;

  /**
   * Decomposes a complete query (i.e. a query and the string-format
   * context) into a query and a context.
   * <br><b>Role</b>: This service enables the decomposition of an NLS or TransFormat
   * complete query string (i.e. a string containing both the query and the context),
   * into an NLS or TransFormat query (which will be used to generate a criterion) 
   * and a context.
   * <br>
   * The validity of the query part of the complete string is not analyzed.
   * <br><br>
   * <b>Example</b>: 
   * <br>Let us consider the following complete complete query: <tt>Name=*1,all</tt>.
   * <br>This service would decompose it as a query <tt>Name=*1</tt>, and a 
   * CATIIniSearchContext pointer. S_OK is returned.
   * <br><br>
   * Let us consider the following complete query: <tt>CATPrtSearch.Pad,in</tt>.
   * <br>This service would decompose it as a query <tt>CATPrtSearch.Pad</tt>, 
   * and a CATIIniSearchContext pointer. S_OK is returned.
   * <br><br>
   * Let us consider the following incorrect complete query: <tt>NameWithTypo=*1</tt>.
   * <br>This service would decompose it as a query <tt>NameWithTypo=*1</tt> and a
   * CATIIniSearchContext pointer. S_OK is returned. 
   * <br>When nothing is specified at the end of the string, the default context
   * is taken into account (refer to <tt>InUIActiveObject</tt> in @href CATIIniSearchContext#Scope ).
   * <br><br>
   * @param iCompleteQuery
   *    The complete NLS or TransFormat query to be decomposed.
   * @param oQuery
   *    The corresponding NLS or TransFormat query, that can be fed into 
   *    the @href #DecodeStringToCriterion method to generate a criterion.
   * @param oContext
   *    The corresponding context.
   * @param iTransFormat
   *    A CATBoolean to specify if the query is a TransFormat query. 
   *    <ul><li>TRUE, if the query is a TransFormat query.</li>
   *    <li>FALSE, if the query is an NLS query.</li></ul>
   * @return
   *    <ul><li>S_OK, if the complete query has successfully been decomposed into a query 
   *    and a context part.</li>
   *    <li>E_FAIL, if the context (when found) is incorrect.</li></ul>
   */
  virtual HRESULT GetQueryAndContextFromString(const CATUnicodeString& iCompleteQuery, 
                                               CATUnicodeString& oQuery, 
                                               CATIIniSearchContext*& oContext, 
                                               CATBoolean iTransFormat) = 0;

  /**
   * Corrects a string before feeding it into a query.
   * <br><b>Role</b>: Sometimes input strings can contain symbols that 
   * could be analyzed as special caracters in a Search query. 
   * It is then necessary to enclose those symbols within special
   * exclusive caracters, so that they could be recognized.
   * <br><br>Let us consider the following query string: <tt>Name=little, johnny</tt>
   * <br>The GetQueryAndContextFromString method would return E_FAIL, 
   * for the string would be decomposed as <tt>Name=little</tt>, and 
   * an unknown context <tt>johnny</tt> would have been found.
   * <br>The solution is to call this method so that the <tt>little, johnny</tt>
   * string is corrected into a String1 CATUnicodeString instance, which in turned 
   * could be correctly analyzed.
   * <br><br>Let us consider the following query string: <tt>NAME=Lonely*</tt>
   * <br>This looks for every object whose name starts with Lonely (case sensitivity
   * respected). But what if we are looking for every object named Lonely* (star
   * being part of the name) ?
   * <br>The <tt>Lonely*</tt> string should be fed into the CorrectString method,
   * and the returned CATUnicodeString instance could be then correctly used.
   * <br><br>
   * @param iStringToCorrect
   *    The string to be corrected.
   * @param oCorrectedString
   *    The string once corrected.
   * @return 
   *    S_OK always
   */
  virtual HRESULT CorrectString(const CATUnicodeString& iStringToCorrect,
                                CATUnicodeString& oCorrectedString) = 0;

  /**
   * Tests the validity of a string as a digital value.
   * <br><b>Role</b>: This service checks if an input string is a valid 
   * digital value.
   * <br><br>
   * @param iValue
   *    a CATUnicodeString format of a possible digital value (1.2 for instance).
   * @param iWithDecimal
   *    TRUE if the string can contain a decimal symbol.
   *    FALSE if the string must not contain any decimal symbol.
   * @return
   *    <ul><li>S_OK if the CATUnicodeString is a valid digital value.
   *    E_FAIL if the CATUnicodeString is not a valid digital value (for instance 1.2.3)</li></ul>
   */
  virtual HRESULT TestNumValidity(const CATUnicodeString &iValue, 
                                  CATBoolean iWithDecimal) = 0;

  /**
   * Tests the validity of a string as a digital value with a unit.
   * <br><b>Role</b>: This service checks if an input string is a valid digital
   * value with a unit.
   * <br><br>
   * @param iValueUnit
   *    a CATUnicodeString format of a possible digital value with unit (1.2kg for instance)
   * @param iWithDecimal
   *    TRUE if the digital value can contain a decimal symbol.
   *    FALSE if the digital value must not contain any decimal symbol.
   * @param oValue
   *    The digital value as a CATUnicodeString. Then use the appropriate
   *    @href CATUnicodeString#ConvertToNum method to convert it into the desired format.
   *    <br>A CATUnicodeString containing <tt>1.2</tt> is returned in our example.
   * @param oUnit
   *    The unit found in the input string.
   *    <br>A CATUnicodeString containing <tt>kg</tt> is returned in our example.
   * @return
   *    <ul><li>S_OK if the CATUnicodeString is a valid digital value.</li>
   *    <li>S_FALSE if no unit has been found.</li>
   *    <li>E_FAIL if the CATUnicodeString is not a valid digital value (for instance 1.2.3)</li></ul>
   */
  virtual HRESULT TestNumValidity(const CATUnicodeString &iValueUnit, CATBoolean iWithDecimal,
                                  CATUnicodeString &oValue, CATUnicodeString &oUnit) = 0;
  
  /**
   * Converts a TransFormat query into an NLS query.
   * <br><b>Role</b>: This service enables you to convert a TransFormat query into 
   * an NLS query without tinkering with a CATIIniSearchCriterion pointer.
   * @param iTransFormatQuery
   *    The TransFormat query
   * @param oNLSQuery
   *    The equivalent NLS query
   * @return
   *    <ul><li>S_OK if iTransFormatQuery corresponds to a correct query</li>
   *    <li>E_FAIL otherwise</li></ul>
   */
  virtual HRESULT ConvertFromTransFormatToNLS(const CATUnicodeString& iTransformatQuery,
                                              CATUnicodeString& oNLSQuery) = 0;
  
  /**
   * Converts an NLS query into a Transformat query.
   * <br><b>Role</b>: This service enables you to convert an NLS query into 
   * a Transformat query without tinkering with a CATIIniSearchCriterion pointer.
   * @param iNLSQuery
   *    The NLS query
   * @param oTransformatQuery
   *    The equivalent Transformat query
   * @return
   *    <ul><li>S_OK if iNLSQuery corresponds to a correct query.</li>
   *    <li>E_FAIL otherwise.</li></ul>
   */
  virtual HRESULT ConvertFromNLSToTransFormat(const CATUnicodeString& iNLSQuery,
                                              CATUnicodeString& oTransformatQuery) = 0;


  /**
   * Retrieves the wild characters.
   * <br><b>Role</b>: This service enables you to retrieve the wild card 
   * character used to replace from 0 to n characters.
   * @param oWildCardChar
   *    The wild card character.
   * @return
   *    <ul><li>S_OK on success.</li>
   *    <li>E_FAIL otherwise.</li></ul>
   */
  virtual HRESULT GetWildCardCharacter(CATUnicodeChar& oWildCardChar) = 0;

};
#endif
