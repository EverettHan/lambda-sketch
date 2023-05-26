#ifndef CATPLMPathDataEnum_H
#define CATPLMPathDataEnum_H

namespace CATPLMPathDataEnum
{
  /*
  * When you READ data:
  * If in CATIPLMQueryFilter you set PLMQY_PATHTYPES to PLMQY_PUREPATHTYPE or to PLMQY_ALL then iState == CATPLMPathDataEnum::eall.
  * If in CATIPLMQueryFilter you set PLMQY_PATHTYPES to PLMQY_PUREPATHTYPE_ID_ONLY or to PLMQY_ALL_ID_ONLY then iState == CATPLMPathDataEnum::eid.
  *
  * When you WRITE data:
  * then iState == CATPLMPathDataEnum::eall_except_id (it is automatically set).
  */
  enum ePathStateOfLoading { eundefined = 0, eall = 1 /*READ*/, eid = 2 /*READ*/, eall_except_id = 3/*CREATE/UPDATE/WRITE*/, eid_idrel = 4 /*READ*/};
};

#endif
