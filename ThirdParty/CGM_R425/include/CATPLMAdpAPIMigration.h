#ifndef __CATPLMAdpAPIMigration__h__
#define __CATPLMAdpAPIMigration__h__

/**
* @level Private
* @usage U3
*/

#include "CATPLMServicesItf.h"

/**
* @nodoc 
* Class used to activate a global development launched by the PLMAdapter.
*/
class ExportedByCATPLMServicesItf CATPLMAdpAPIMigration
{
public:
  /**
  * @nodoc
  * Returns the activation of the CATVariant update.
  */
  static int CATVariantMigration ();

  static int IsCATVariantMigrationFullyFinished();

  /**
  * @nodoc
  * Returns the activation of the Omx Attr Bloc in MOne.
  */
  static int CATPLMKeyValueBlockMigration ();

  /**
  * @nodoc
  * Returns the activation of the Omx value modification for binary and list.
  */
  static int CATPLMOmxAttrValueMigration ();

  /**
  * @nodoc
  * Checks if the connected is M1, then return if the server is still using a mapping for IRPC (1) or not (0).
  * If M1 is not connected (TST provider ?), return -1.
  * Only the 0 value should be check IMO.
  * For ODT checks, it is possible to force the value of this method with the variable : PLM_M1MAPPINGRETURN= 1 / 0 / -1
  */
  //static int IsM1MappingActivated ();

};

#endif
