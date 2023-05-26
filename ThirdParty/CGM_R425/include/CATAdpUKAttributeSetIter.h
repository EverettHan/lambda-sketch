/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpUKAttributeSetIter_H
#define CATAdpUKAttributeSetIter_H

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
class CATPLMTypeH;
class CATAdpStdAttributeSet;
class CATAdpPrivateUKAttributeSet;
class CATAdpUKAttributeValueIter;

/**
 * Class giving access to sets of attributes from a UK Id.
 *
 * <br><b>Role</b>: provide access to sets of attributes from a UK Id .
 */
class ExportedByCATPLMIntegrationAccess CATAdpUKAttributeSetIter
{
public:

  CATAdpUKAttributeSetIter();
  /**
   * copy ctor
   */
  CATAdpUKAttributeSetIter(const CATAdpUKAttributeSetIter &);

  /**
   * operator =
   */
  CATAdpUKAttributeSetIter& operator=(const CATAdpUKAttributeSetIter&);

  /**
  * Destructor.
  */
  virtual ~CATAdpUKAttributeSetIter();

/** 
 * Retrieves the iterator to access datas on attribute sets.
 *
 * <br><b>Role</b>: Allow to acces atributes values on a attribute set associated to a PLM type. The whole scan can been done only once.
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
 * Deprecated.
 */
  HRESULT Next(  int&    ioPosition,    CATPLMTypeH & oType,  CATAdpUKAttributeValueIter    *&    oAttributeIter );



private:
  friend class CATAdpRestrictedUKServices;
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
