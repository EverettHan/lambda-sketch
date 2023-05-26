/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpStdAttributeSetIter_H
#define CATAdpStdAttributeSetIter_H

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
class CATPLMTypeH;
class CATAdpStdAttributeSet;
class CATAdpPrivateUKAttributeSet;

/**
 * Class giving access to sets of attributes from a UK Id.
 *
 * <br><b>Role</b>: provide access to sets of attributes from a UK Id .
 */
class ExportedByCATPLMIntegrationAccess CATAdpStdAttributeSetIter
{
public:

  CATAdpStdAttributeSetIter();
  /**
   * copy ctor
   */
  CATAdpStdAttributeSetIter(const CATAdpStdAttributeSetIter &);

  /**
   * operator =
   */
  CATAdpStdAttributeSetIter& operator=(const CATAdpStdAttributeSetIter&);

  /**
  * Destructor.
  */
  virtual ~CATAdpStdAttributeSetIter();

/** 
 * Retrieves the iterator to access datas on attribute sets.
 *
 * <br><b>Role</b>: Allow to acces atributes values on a attribute set associated to a PLM type. 
 *
 * @param oType [out]
 *   The PLM type associated to the attribute set.
 * @param oAttributeSet [out]
 *   The object to read attributes values inside a set.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more attribute set is available.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *   </ul>
 *
 */
  HRESULT Next(CATPLMTypeH & oType,  CATAdpStdAttributeSet & oAttributeSet) const;
/** 
 * Reinitialize the iterator on the begining.
 *
 * <br><b>Role</b>: Allow to reinitialize the iterator on the begining in order to retrieve the first attribute set. 
 *
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   </ul>
 *
 */  
  HRESULT Rewind() const;


private:
  friend class CATAdpRestrictedUKServices;
  friend class CATAdpComponentQuery;
  /** 
  * Adds a couple CATPLMTypeH, CATAdpStdAttributeSet to the UK attribute set.
  *
  * <br><b>Role</b>: Adds a new couple (CATPLMTypeH/CATAdpStdAttributeSet) to the UK attribute set.
  *
  * @param iTypeH [in]
  *   The type corresponding to the attribute set.
  * @param iAttributeSet [in]
  *   The attribute set containing values 
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if the couple Type/AttributeSet was added in the set.</li>
  *   <li><code>E_FAIL</code> if an internal error occured.</li>
  *   </ul>
  */

  HRESULT AddAttributeSet(const CATPLMTypeH & iTypeH, const  CATAdpStdAttributeSet & iAttributeSet);

  CATAdpPrivateUKAttributeSet * _letter;
};
#endif
