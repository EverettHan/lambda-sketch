
/**
* @level Private
* @usage U3
*/

#ifndef __CATPLMAdapterEvents__h__
#define __CATPLMAdapterEvents__h__

#include "CATWTypes.h"

/** @nodoc */
#define AdpEvent_PrepareConnect  0x00000001
/** @nodoc */
#define AdpEvent_Connect         0x00000002
/** @nodoc */
#define AdpEvent_Query           0x00000004
/** @nodoc */
#define AdpEvent_Expand          0x00000008
/** @nodoc */
#define AdpEvent_Open            0x00000010
/** @nodoc */
#define AdpEvent_FetchQuery      0x00000020
/** @nodoc */
#define AdpEvent_QueryCount      0x00000040
/** @nodoc */
#define AdpEvent_Save            0x00000080
/** @nodoc */
#define AdpEvent_NewVersion      0x00000100
/** @nodoc */
#define AdpEvent_CheckEdit       0x00000200
/** @nodoc */
#define AdpEvent_DeleteRef       0x00000400
/** @nodoc */
#define AdpEvent_Maturity        0x00000800
/** @nodoc */
#define AdpEvent_Clone           0x00001000
/** @nodoc */
#define AdpEvent_LockUnlock      0x00002000
/** @nodoc */
#define AdpEvent_Navigate        0x00004000
/** @nodoc */
#define AdpEvent_Metadata        0x00008000
/** @nodoc */
#define AdpEvent_Disconnect      0x00010000
/** @nodoc */
#define AdpEvent_LoadEnvironment 0x00020000
/** @nodoc */
#define AdpEvent_LoadDomain      0x00040000
/** @nodoc */
#define AdpEvent_Import          0x00080000
/** @nodoc */
#define AdpEvent_Commit          0x00100000
/** @nodoc */
#define AdpEvent_Rollback        0x00200000
/** @nodoc */
#define AdpEvent_PushExpand      0x00400000
/** @nodoc */
#define AdpEvent_LoadModeler     0x00800000
/** @nodoc */
#define AdpEvent_AutoNaming      0x01000000
/** @nodoc */
#define AdpEvent_Versioning      0x02000000
/** @nodoc */
#define AdpEvent_ProcedureCall   0x04000000
/** @nodoc */
#define AdpEvent_ChangeControl   0x08000000
/** @nodoc */
#define AdpEvent_History         0x10000000
/** @nodoc */
#define AdpEvent_Copy            0x20000000
/** @nodoc */
#define AdpEvent_QueryValidity   0x40000000
/** @nodoc */
#define AdpEvent_WspMngt         0x80000000
/** @nodoc */
#define AdpEvent_Refresh         0x100000000LL
/** @nodoc */
#define AdpEvent_SearchQuery     0x200000000LL// EPB FTS 10:03:25

#define AdpEvent_Iteration       0x400000000LL// EPB FTS 10:03:25

#define AdpEvent_CompletionSuggestion 0x800000000LL

#define AdpEvent_WspReservation 0x1000000000LL

// SPD events happen in the same conditions as the corresponding non-SPD events, if the query uses SPD.
/** @nodoc */
#define AdpEvent_SPD_Query          0x2000000000LL
/** @nodoc */
#define AdpEvent_SPD_Expand         0x4000000000LL
/** @nodoc */
#define AdpEvent_SPD_Open           0x8000000000LL
/** @nodoc */
#define AdpEvent_SPD_PushExpand     0x10000000000LL
/** @nodoc */
#define AdpEvent_SPD_SearchQuery    0x20000000000LL

// PLMQL layer, all events will be activated except XMQL event
// Indeed, XMQL event is what we call low level event: each AdpEvent_XXXX will be composed of N XMQL event with N>=1
#define AdpEvent_PLMQL_All          0xFFFFFFFFFFFLL

/** XMQL layer */
#define AdpEvent_CuttingXMQLRequest 0x1000000000000LL

#define AdpEvent_XMQLRequest        0x2000000000000LL

#define AdpEvent_XMQL_All           0xF000000000000LL

#define AdpEvent_All                0xFFFFFFFFFFFFFLL //46 events in total

/** @nodoc */
#include "CATDataType.h"// SpecialAPI PublicInterfaces
typedef CATLONG64 CATPLMAdapterEvents;

class CATPLMAdapterEventsToolbox
{
public:
  static int GetMaxEvents() {
    static int MAX_EVENT = 0;
    if (MAX_EVENT == 0)
    {
      CATPLMAdapterEvents adapterEvents = AdpEvent_All;
      while ((adapterEvents & 0x1) == 1 && adapterEvents != 0)
      {
        adapterEvents = adapterEvents >> 1;
        MAX_EVENT++;
      }
    }
    return MAX_EVENT;
  }
};

#endif // __CATPLMAdapterEvents__h__
