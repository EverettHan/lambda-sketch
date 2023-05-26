//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES   2002
//=============================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchCriterion_H
#define CATIIniSearchCriterion_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchCriterion;

/**
 * Interface to use an already defined search criterion. 
 * <b>Role:</b> This interface is the basic interface from 
 * which every Search criterion interface derive.
 * <br>It defines the common services awaited on a Search 
 * criterion: printing, testing.
 */
class ExportedByUIModelInterfaces CATIIniSearchCriterion : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  /**
   * Retrieves a string-format criterion.
   * <br><b>Role:</b> This method enables the retrieval of a string-format
   * criterion (i.e. query), using the session language (NLS support).
   * @param oQueryString
   *    The NLS query corresponding to the criterion.
   * @return 
   *    E_FAIL if the criterion is not correctly set up (refer the adequate 
   *    <tt>SetParameters</tt> method of the criterion).
   *    S_OK otherwise.
   */
  virtual HRESULT GetNLSQuery(CATUnicodeString &oQueryString) = 0;

  /**
   * Retrieves a string-format criterion.
   * <br><b>Role:</b> This method enables the retrieval of a string-format
   * criterion (i.e. query), using the transformat language. This language
   * enables a query to be correctly analyzed and transformed into a 
   * criterion whatever the session language
   * ( @href CATIIniSearchServices#DecodeStringToCriterion method).
   * @param oTFQueryString
   *    The transformat query corresponding to the criterion.
   * @return 
   *    <ul><li>E_FAIL if the criterion is not correctly set up (refer the adequate 
   *    <tt>SetParameters</tt> method of the criterion).</li>
   *    <li>S_OK otherwise.</li></ul>
   */
  virtual HRESULT GetTransFormatQuery(CATUnicodeString &oTFQueryString) = 0;

  /**
   * Tests if an object matches the criterion.
   * <br><b>Role:</b> This method enables to test if an object matches
   * the criterion as defined through the adequate <tt>SetParameters</tt> method.
   * @param iObject
   *    The object to test.
   * @return 
   *    <ul><li>S_OK if the object fits the criterion.</li>
   *    <li>E_FAIL otherwise.</li></ul>
   */
  virtual HRESULT IsObjectMatching(const CATBaseUnknown_var& iObject) = 0;
};
#endif
