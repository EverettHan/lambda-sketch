#ifndef CATProxyTransactionPurpose_H
#define CATProxyTransactionPurpose_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
* @level Private
* @usage U3
*/


/** 
* CATProxyTransactionPurpose (Purpose of the transaction)
*/
enum CATProxyTransactionPurpose 
{
  CatPLMTransactionUnknown                 = 0x00000000,
  CatPLMTransactionSave                    = 0x00000001,
  CatPLMTransactionCloning                 = 0x00000002,
  CatPLMTransactionMajorVersioning         = 0x00000004,
  CatPLMTransactionMinorVersioning         = 0x00000008,
  CatPLMTransactionRepositorySwitch        = 0x00000010,
  CatPLMTransactionBrowserDump             = 0x00000020,
  CatPLMTransactionClearing                = 0x00000040,
  CatPLMTransactionRedraw                  = 0x00000080,
  CatPLMTransactionRedrawDispatching       = 0x00000100,
  CatPLMTransactionAsynchronousDispatching = 0x00000200,
  CatPLMTransactionLocalSave               = 0x00000400,
  CatPLMTransactionPartialUpgrade          = 0x00000800,
  CatPLMTransactionDehydration             = 0x00001000,
  CatPLMTransactionReroute                 = 0x00002000,
  CatPLMTransactionSwitch                  = 0x00004000,
  CatPLMTransactionLocking                 = 0x00008000,
  CatPLMTransactionQueryResult             = 0x00010000,     // CATPLMTransactionQueryResultWrapper
  CatPLMTransactionOpen                    = 0x00020000,     // CATPLMSessionManager - Session open
  CatPLMTransactionRestore                 = 0x00040000,     // CATPLMSessionManager - Session restore
  CatPLMTransactionSynchronize             = 0x00080000,     // CATPLMSessionManager - Session synchronize
  CatPLMTransactionCollab                  = 0x00100000,     // CATPLMSessionManager - Session collab
  CatPLMTransactionImportAsNew             = 0x00200000,     // CATPLMSessionManager - Session briefcase import
  CatPLMTransactionOverload                = 0x00400000,     // CATPLMSessionManager - Session overload
  CatPLMTransactionDuplicate               = 0x00800000,     // CATPLMSessionManager - Session duplicate
  CatPLMTransactionReidentify              = 0x01000000,
  CatPLMTransactionReroute_CCM             = 0x02000000,
  CatPLMTransactionReroute_PLMCtxLink      = 0x04000000,
  CatPLMTransactionStreaming               = 0x08000000,
  CatPLMTransactionOpenEngine              = 0x10000000     // similar to "open" but at an "upper" level
};

typedef unsigned int CATProxyTransactionPurposeMask;

#endif
