//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */
#ifndef CATIniSearchEnumeration_H
#define CATIniSearchEnumeration_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"

extern ExportedByUIModelInterfaces IID IID_ExportedByUIModelInterfaces;

/**
 * Class defining operating signs for search criterion.
 */
class ExportedByUIModelInterfaces CATIniSearchEnumeration : public CATBaseUnknown
{
public:
  /**
   * Operators used in search criterion.
   * <br><b>Role:</b> Enumeration of the different operating signs 
   * that can be used during the initialization of the search criterion.
   * @param NoOperator
   *    This should never be used.
   * @param InfEqual
   *    This corresponds to the <= mathematical operating sign.
   * @param Inferior
   *    This corresponds to the <  mathematical operating sign.
   * @param SupEqual
   *    This corresponds to the >= mathematical operating sign.
   * @param Superior
   *    This corresponds to the >  mathematical operating sign.
   * @param Different
   *    This corresponds to the != mathematical operating sign.
   * @param Equal
   *    This corresponds to the =  mathematical operating sign.
   */
  enum Comparison { NoOperator=0,
                    InfEqual,
                    Inferior,
                    SupEqual,
                    Superior,
                    Different,
                    Equal}; 
};
#endif
