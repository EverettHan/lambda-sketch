/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeRelationIter_H
#define CATPLMTypeRelationIter_H

#include "CATPLMIdentificationAccess.h"
#include "CATOmxArray.h"
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATPLMTypeRelation.h"

template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATPLMTypeRelation>::manager();

class ExportedByCATPLMIdentificationAccess CATPLMTypeRelationIter
{
public:
  CATPLMTypeRelationIter();
  virtual ~CATPLMTypeRelationIter();

/**
 * Get the next PLM relation.
 * <br><b>Role:</b>Give access to the next PLM relation (@href CATPLMTypeRelation) of the enumeration.
 *
 * @param oRelation [out]
 * The PLM relation.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if a PLM relation is given back.</li> 
 * <li><tt>S_FALSE</tt> if the end of the iteration is reached.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * </ul>
 */
  HRESULT NextRelation( CATPLMTypeRelation & oRelation );

/**
 * Get the number of Relations.
 * <br><b>Role:</b>Give access to the number of Relations available in the iterator.
 *
 * @return
 * <ul>
 * <li>The number of Relations.</li> 
 * </ul>
 */
  int Count();

protected:

  friend class PLMTypeBehaviorsRelationsFilter;
  friend class CATPLMTypeTools;
  HRESULT AddRelation( const CATPLMTypeRelation & iRelation );
  HRESULT Finalize( int & oNbRelations );

private:
  CATPLMTypeRelationIter( const CATPLMTypeRelationIter & );
  CATPLMTypeRelationIter & operator =( const CATPLMTypeRelationIter & );

private:
  CATOmxArray<CATPLMTypeRelation> _PLMRelations;
  int _Index;
};

#endif
