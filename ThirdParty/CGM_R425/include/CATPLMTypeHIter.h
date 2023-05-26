/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeHIter_H
#define CATPLMTypeHIter_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeH.h"
#include "CATOmxMapIter.h"


class ExportedByCATPLMIdentificationAccess CATPLMTypeHIter
{
public:
  CATPLMTypeHIter( const CATPLMTypeHIter & );
  virtual ~CATPLMTypeHIter();

/**
 * Get the next PLM type of the collection.
 * <br><b>Role:</b>Give access to the next PLM type (@href CATPLMTypeH) of the collection.
 *
 * @param oPLMType [out]
 * The PLM type.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if a PLM type is given back.</li> 
 * <li><tt>S_FALSE</tt> if the end of the iteration is reached.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * </ul>
 */
  HRESULT Next( CATPLMTypeH & oPLMType );

private:
  friend class CATPLMTypeHSet;
  CATPLMTypeHIter();
  CATPLMTypeHIter( const CATOmxMapIter<CATPLMTypeH, int> & iIter );
  CATPLMTypeHIter & operator =( const CATPLMTypeHIter & );

private:
  CATOmxMapIter<CATPLMTypeH, int> _Iter;
};

#endif
