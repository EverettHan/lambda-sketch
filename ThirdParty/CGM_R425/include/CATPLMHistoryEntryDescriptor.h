// OperationData
//                                                              Modified                                                     NewVersion
//                                                                under                                                         /
//                                                Create Update Modified Delete ChangeStatus Lock Unlock TransferOwnership NewMinorVersion Clone ChangeAuthorityControl
//CompInstanceOf                                    x      x       x       x        x                            x                 x         x             x                                             
//CreateOriginObject                                x                                                                                                                                              
//SnapshotId                                                       x                                                                                                                               
//ChangeStatusDataPreviousState                                                     x                                                                                                              
//ChangeStatusDataNewState                                                          x                                                                                                              
//ChangeOwnershipDataPreviousOwner                                                                               x                                                                                 
//ChangeOwnershipDataNewOwner                                                                                    x                                                                                 
//ChangeOwnershipDataPreviousProject                                                                             x                                                                                 
//ChangeOwnershipDataNewProject                                                                                  x                                                                                 
//ChangeOwnershipDataPreviousOrg                                                                                 x                                                                                 
//ChangeOwnershipDataNewOrg                                                                                      x                                                                                 
//NewVersionNewObject                                                                                                              x                                                               
//CloneNewObject                                                                                                                             x                                                     
//ChangeAuthorityControlPreviousVal                                                                                                                        x                                       
//ChangeAuthorityControlNewVal                                                                                                                             x                                       

//CompInstanceOf et le CreateOriginObject are externalized in attributes InstanceOf* and DerivedFrom*.

#ifndef CATPLMHistoryEntryDescriptor_H
#define CATPLMHistoryEntryDescriptor_H

#include "CATPLMServicesItf.h"

#include "CATSysErrorDef.h"

#include "CATUnicodeString.h"

class ExportedByCATPLMServicesItf CATPLMHistoryEntryDescriptor
{
public:
  static const CATPLMHistoryEntryDescriptor &s();

  ~CATPLMHistoryEntryDescriptor();

  const CATUnicodeString HistoryEntry;

  const CATUnicodeString Date;//UserFact
  const CATUnicodeString ModificationDate;//Event
  const CATUnicodeString ActionID;
  const CATUnicodeString DerivedFrom;
  const CATUnicodeString CompOwner;
  const CATUnicodeString CompPLMID;
  const CATUnicodeString CompInstanceOf;
  const CATUnicodeString CompCES;
  const CATUnicodeString User;
  const CATUnicodeString Role;
  const CATUnicodeString Project;
  const CATUnicodeString HistoryComment;
  const CATUnicodeString OperationData;
  const CATUnicodeString Operation;
  const CATUnicodeString CompCUS;
  const CATUnicodeString USERDATA;// PLMQL write
  const CATUnicodeString UserData;// Read in XML received after query on XMQL
  const CATUnicodeString UserFactName;
  const CATUnicodeString UserFactID;
  const CATUnicodeString EventID;

private:
  CATPLMHistoryEntryDescriptor();

  CATPLMHistoryEntryDescriptor (CATPLMHistoryEntryDescriptor &);
  CATPLMHistoryEntryDescriptor& operator=(CATPLMHistoryEntryDescriptor&);

};

#endif
