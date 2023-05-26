#ifndef CATPLMBagType_H
#define CATPLMBagType_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U1
 */
#if ! defined ( CATPLMBagType_definition )
#define CATPLMBagType_definition
typedef unsigned int CATPLMBagType;
#endif

/** @nodoc */
#define CATPLMBagType_None             0x00000000

#define CATPLMBagType_All              0xFFFFFFFF

/** @nodoc Number of bits needed inside Bit Fields */
#define CATPLMBagType_Cardinality               5

#define CATPLMBagType_Public           0x00000001    /** Bag of components used for common usage                   */
#define CATPLMBagType_UndoRedo         0x00000002    /** Bag of components used for undo redo usage                */
#define CATPLMBagType_Admin            0x00000004    /** Bag of components used for admin usage                    */
#define CATPLMBagType_LifeGuard        0x00000008    /** Bag of components used for temporary life cycle exclusion */
#define CATPLMBagType_FileLegacy       0x00000010    /** Bag used file legacy usage                                */

#endif
