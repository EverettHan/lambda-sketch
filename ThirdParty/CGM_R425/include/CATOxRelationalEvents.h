#ifndef CATOxRelationalEvents_H 
#define CATOxRelationalEvents_H
// COPYRIGHT DASSAULT SYSTEMES 2007
/**
 * @level Private
 * @usage U1
 */
enum CATOxRelationalEvent {CATOxRelationalEvent_Created = 0,
                           CATOxRelationalEvent_StateChanged_Destroyed = 1,
                           CATOxRelationalEvent_StateChanged_Garbaged = 2,
                           CATOxRelationalEvent_StateChanged_Valid = 3,
                           CATOxRelationalEvent_UserSynchronized = 4,
                           CATOxRelationalEvent_AutoSynchronized = 5,
                           CATOxRelationalEvent_AutoDesynchronized = 6,
                           CATOxRelationalEvent_BuildSpecSynchronized = 7,
                           CATOxRelationalEvent_Reidentified = 8,
                           CATOxRelationalEvent_Deleted = 9,
                           CATOxRelationalEvent_Unmarshalled = 10};

#endif
