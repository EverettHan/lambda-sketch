// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMCompEventMonitorServices.h
// Define the CATIPLMCompEventMonitorServices interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jun 2012  Creation: FBN
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompEventMonitorServices_H
#define CATIPLMCompEventMonitorServices_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATPLMID_Any;
class CATOmxAny;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompEventMonitorServices;
#else
extern "C" const IID IID_CATIPLMCompEventMonitorServices ;
#endif
//------------------------------------------------------------------

enum LogType {LogDelete};

/**
 * Interface belonging to the <b>Component services</b>.
 * Used to access a  given EventMonitor.
 */
class ExportedByCATPLMServicesItf CATIPLMCompEventMonitorServices: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	 * @param iRepository
	 *   Provider on which the service will be called. Can be NULL : will use the connected provider.
	 * @param iName
	 *   Name of the EventMonitor used.
	 * @param iType
	 *   Type of event.
	 * @param oListOfEntry
	 *   The internal structure of the CATOmxAny is a list of CATOmxKeyValueBlock
   *   Each CATOmxKeyvalueBlock contains 3 keys/values : physicalid / eventdata / objecttype
	 *   The value associated are string values returned by the database.
	 *   - physicalid is an hexadecimal view of a CATUuid.
	 *   - eventdate as a server marshalled view of a date.
	 *   - objecttype is either "BO" or "REL".
   *   Typical use of the oListOfEntry for reading and adding to another CATOmxAny (for later purge for example) is :
   *
   *       CATOmxKeyString ksPhy ("physicalid");
   *       CATOmxAny EntryToPurge;
   *       int nbEntry = oListOfEntry.Size ();
   *       for (int i=1; i<=nbEntry;i++)   {
   *         CATOmxAny tmpEntry = oListEntry [i];
   *         CATOmxKeyValueBlock tmpKVBlock;
   *         tmpEntry >> tmpKVBlock; // Needed : #include "CATOmxAnyMapConvert.h" for this
   *         CATOmxAny tmpVal;
   *         // Get physicalid as a CATUnicodeString
   *         tmpKVBlock.GetValue (ksPhy,tmpVal);
   *         CATUnicodeString physicalid = tmpVal.GetString ();
   *         // Same for eventdate and objectype
   *         if (NeedToPurge ()) // Your logic here
   *           EntryToPurge.Append (tmpEntry);  // just transfert the entry to the other list (no copy in memory)
   *       }
   *   Of course, the EntryToPurge can be build from scratch. It only needs a list of CATOmxKeyValueBlock that contains 
   *   at least the physicalid key and value inside the block (other information are optional for purge commend)
   *   Example :
   *
   *   CATListOfCATUnicodeString listid; // Filled with physicalid for example
   *   CATOmxAny EntryToPurge;
   *   CATOmxKeyString ksPhy ("physicalid");
   *   for (int i=1; i<=listid.Size();i++) {
   *     CATOmxKeyValueBlock tmpKVBlock;
   *     tmpKVBlock.SetValue (ksPhy,listid[i]);
   *     CATOmxAny tmpAny;
   *     tmpAny << tmpKVBlock;  // Needed : #include "CATOmxAnyMapConvert.h" for this
   *     EntryToPurge.Append ( tmpAny );
   *    }
	 */
	virtual HRESULT GetLog(const char *iRepository, CATUnicodeString &iName, LogType iType, CATOmxAny &oListOfEntry) =0;

	/**
	 * @param iRepository
	 *   Provider on which the service will be called. Can be NULL : will use the connected provider.
	 * @param iName
	 *   Name of the EventMonitor used.
	 * @param iType
	 *   Type of event.
	 * @param iListOfEntry
	 *   List of entry to remove. See GetLog for information on the requested inner structure of the CATOmxAny.
	 */
  virtual HRESULT PurgeLog(const char *iRepository, CATUnicodeString &iName, LogType iType, const CATOmxAny &iListOfEntry ) =0;

	/**
   * Purge the corresponding log (creates it if not present).
	 * @param iRepository
	 *   Provider on which the service will be called. Can be NULL : will use the connected provider.
	 * @param iName
	 *   Name of the EventMonitor used.
	 * @param iType
	 *   Type of event.
	 */
  virtual HRESULT PurgeAll(const char *iRepository, CATUnicodeString &iName, LogType iType  ) =0;
};
//------------------------------------------------------------------
#endif
