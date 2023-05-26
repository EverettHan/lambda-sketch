#ifndef __CATOmyTestHooks_H
#define __CATOmyTestHooks_H

#include "CATOMYUtils.h"
#include "CATOmyCioUrlUsageCtx.h"

class CATVVSUrl;
class CATUnicodeString;

/**
* Collection of horrible hooks for odts
* This collection allows to test contexts that standard test code with exposed API could not create. Or have a specific dependencies for example to focus testing on a specific part of code. Of course other usage can be found
*
__          __                  _
\ \        / /                 (_)
 \ \  /\  / /__ _  _ __  _ __   _  _ __    __ _
  \ \/  \/ // _` || '__|| '_ \ | || '_ \  / _` |
   \  /\  /| (_| || |   | | | || || | | || (_| |
    \/  \/  \__,_||_|   |_| |_||_||_| |_| \__, |
                                           __/ |
                                          |___/
* READ THIS BEFORE ANY MODIFICATION
* 1) only function pointers can be added to this structure. Any data member is forbidden.
* 2) in tst code Get instance of the structure with Get method as the singleton is not exported in dll. Then define the function pointer that interest equals to a local function defined by you. Once your test(s) ended you should reset you function pointer to NULL
* 3) in genuine code, NEVER call CATOmyTestHooksStruct::Get ! Just get external singleton CATOmbTestHooks and test presence of function in structure with dot operator
* 4) If this function is defined, you can run specific odt code. This function definition or not can simply works like a boolean, do a real job, or return a specific odt value/object

Example (reference to CATOmbTestHooks.h) :
let's take the use of HackPLMIDForCheckStampsInDB (simplified)

in TST :
void TestCheckDBBeforeSwitchHackPLMID(CATPLMID& ioPLMID)
{ do lot of work}

CATOmbTestHooksStruct::Get().HackPLMIDForCheckStampsInDB = &TestCheckDBBeforeSwitchHackPLMID;
CATOxiAssert(S_FALSE == switchEngine->ExecuteSwitchOperations(failures));
CATOmbTestHooksStruct::Get().HackPLMIDForCheckStampsInDB = NULL;

in genuine code :
[...]
if(CATOmbTestHooks.HackPLMIDForCheckStampsInDB) CATOmbTestHooks.HackPLMIDForCheckStampsInDB(PLMID);
=> PLMID is modified in this particular case of odt.

*/

/*#define AuthorizedModule 999
// Check No Hack
#if _MK_MODNAME_ == AuthorizedModule
#error Forbidden Access To CATAsyncTaskListener from a non-authorized module
@error
#endif

// List of authorized infrastructure modules
#define CATAsyncStreamFoundation                  AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATOmyTestHooks from a non-authorized module
@error
#endif

#undef CATAsyncStreamFoundation*/


struct CATOmyTestHooksStruct
{
  int(*ForceMissingFilesForCheckout)(int iNumberOfStreamsToDownload); // returns number of streams not to download
  int(*ForceMissingFilesForCheckout2)(int iNumberOfStreamsToDownload); // returns number of streams not to be download avoiding register in cache (and no GetTicket on them)
  void(*MissingFileDefineReason)(const CATOmyCioUrlUsageCtx& iCtx, CATOmyCioUrlUsageCtx::TransactionStatus& oStatus); // to implement with ForceMissingFilesForCheckout2 to be recalled for each cancel stream. oStatus will be set for canceled stream (Unknown & TransactionOK forbidden here)
  static ExportedByCATOMYUtils CATOmyTestHooksStruct& Get();
  static ExportedByCATOMYUtils CATOmyTestHooksStruct& GetWithoutCATDevelopmentStage();
  CATOmyTestHooksStruct() {}
};

extern CATOmyTestHooksStruct CATOmyTestHooks;

#endif
