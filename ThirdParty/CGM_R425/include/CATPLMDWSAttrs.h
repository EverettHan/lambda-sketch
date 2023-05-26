#ifndef CATPLMDWSAttrs_h
#define CATPLMDWSAttrs_h

#include "CATPLMIntegrationBase.h"
#include "CATString.h"
#include "CATUnicodeString.h"

class ExportedByCATPLMIntegrationBase CATPLMDWSAttrs
{
public:
  static CATString type_TableEntry;

  static CATString attr_physicalIdWS;
  static CATString attr_logicalIdWS;
  static CATString attr_majorIdWS;
  static CATString attr_typeWS;
  static CATString attr_physicalIdParentWS;
  static CATString attr_logicalIdParentWS;
  static CATString attr_majorIdParentWS;
  static CATString attr_typeParentWS;
  static CATString attr_physicalIdObject;
  static CATString attr_logicalIdObject;
  static CATString attr_majorIdObject;
  static CATString attr_typeObject;
  static CATString attr_physicalIdObjectInParentWS;
  static CATString attr_logicalIdObjectInParentWS;
  static CATString attr_majorIdObjectInParentWS;
  static CATString attr_typeObjectInParentWS;
  static CATString attr_compCES;
  static CATString attr_status;

  static int enum_statusEmpty;
  static int enum_statusNew;
  static int enum_statusModified;
  static int enum_statusDeleted;

  static CATString attr_localReserve;
  static CATString attr_parentReserve;
  static CATString attr_workspaceid;
};
#endif
