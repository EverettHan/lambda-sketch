#ifndef CATOxRelationalDirtyStatus_H 
#define CATOxRelationalDirtyStatus_H
// COPYRIGHT DASSAULT SYSTEMES 2007
/**
 * @level Private
 * @usage U1
 */
enum class CATOxRelationalDirtyStatus : unsigned char
{
  NotDirty = 0,
  MinorChanges = 1, // Minor changes[Only light internal data modifications.e.g.:Synchro / Desynchro]
  MajorChanges = 2  //Major changes [Strong modifications with new or deleted relations]
};

#endif
