/* -*-c++-*- */
#ifndef CATPLMTypeIdClassification_H
#define CATPLMTypeIdClassification_H

/**
 * @level Private
 * @usage U1       
 */

#include "CATPLMIdentificationAccess.h"

enum ExportedByCATPLMIdentificationAccess CATPLMTypeId_Classification 
{
  TypeIdClassification_Unset        = 0
, TypeIdClassification_Entity       = 1
, TypeIdClassification_Relation     = 2
, TypeIdClassification_Extension    = 3
, TypeIdClassification_NotSpecified = 7
};

#endif
