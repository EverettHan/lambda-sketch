/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
//
// class CATOmbDocUpdateStampServices :
// 
// Provides applicative access to document Update Stamp management
// (access to internal storage stucture is masked)
//
//-----------------------------------------------------------------------------
// 01/06/04 Creation                                                        VCS
//-----------------------------------------------------------------------------

#ifndef CATOmbDocUpdateStampServices_H
#define CATOmbDocUpdateStampServices_H

#include "AD0XXBAS.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATOmbUpdateStamp.h"

#include "CATOmbDocUpdateStampRestricted.h"

class CATDocument;

/**
* Services to manage modification stamp informations stored on CATDocument 
* <br><b>Role:</b> Trigger, Update and read modification (update stamp) management informations 
* <br> about changes that happened in the CATDocument currently handled, as an external
* <br> blackbox package of informations.
*/

class ExportedByAD0XXBAS CATOmbDocUpdateStampServices
{
public:

	/**
	* Registers the UpdateStamp on current document beeing Saved. 
	* <br><b>Role:</b> Registers the current UpdateStamp value on current document  
    * <br> so that the document becomes NOT Dirty at the end of save.
	* <br> use MUST be restricted to register in session during document SAVE phase or controled un-dirtyfication
	* @param ipDocument
	*     Document wich UpdateStamp is to be set to its non-Dirty value
	* @return
	*		 S_OK : successfully ended
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT RegisterUpdateStampOnSave(CATDocument * ipDocument);

	/**
	* Re-activates the storage of UpdateStamp modifications on current Document.
	* <br><b>Role:</b> Re-activates the storage of UpdateStamp modifications on current Document
	* <br> To be used during Open-Save transactions and any other irrelevant document modifications.
	* <br> Activated by default.
	* @param ipDocument
	*     Document wich UpdateStamp data storage is to be re-activated
	* @return
	*		 S_OK : activation successfully ended
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT ActivateUpdateStampStorage(CATDocument * ipDocument);

	/**
	* Deactivates the storage of UpdateStamp modifications on current Document.
	* <br><b>Role:</b> Deactivates the storage of UpdateStamp modifications on current Document.
	* <br> To be used during Open-Save transactions and any other irrelevant document modifications.
	* @param ipDocument
	*     Document wich UpdateStamp data storage is to be deactivated
	* @return
	*		 S_OK : deactivation successfully ended
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT DeactivateUpdateStampStorage(CATDocument * ipDocument);

	/**
	* Triggers off UpdateStamp incrementation on current Document.
	* <br><b>Role:</b> triggers off UpdateStamp incrementation and storage on current Document:
	* <ul>
	* <li>monitored by dialog engine transaction changes, in interactive session</li>
	* <li>always performed in batch session </li>
	* </ul>
	* @param ipDocument
	*     Document wich UpdateStamp data are to be touched
	* @param oUpdateStampModified 
	*     TRUE: indicates that UpdateStamp effectively updated then stored on current document
	* @param iPropagateToRepRef 
	*     TRUE: by default.Propagates the modification to RepRef current document is attached to
	* @return
	*		 S_OK : successfully ended
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT TouchUpdateStamp(CATDocument * ipDocument, CATBoolean & oUpdateStampModified, CATBoolean iPropagateToRepRef=TRUE);

	/**
	* Reads the document dirty status management version.
	* <br><b>Role:</b> reads the document dirty status management version:
	* @param oOldDocDirtyStatus
	*     0: Document dirty status based on CATOmbUpdateStamp value
	*     1: Document dirty status based on CATDocTransaction/OSM modifications
	* @return
	*		 S_OK : successfully ended
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT IsOldDocDirtyStatusOn(int & oOldDocDirtyStatus);

  static int ODTPhase1();

	/**
	* Re-activates the storage of UpdateStamp modifications on all Documents.
	* <br><b>Role:</b> Globally re-activates the storage of UpdateStamp modifications on all Documents
	* <br> To be used during New-Open-Save transactions and any other irrelevant document modifications.
	* @return
	*		 S_OK    : activation successfully performed
	*		 S_FALSE : requested activation not performed, while other global deactivations still pending
	* <br> E_FAIL : a software error occured
	*/	
	static HRESULT GloballyActivateUpdateStampStorage();

	/**
	* Deactivates the storage of UpdateStamp modifications on all Documents.
	* <br><b>Role:</b> Globally deactivates the storage of UpdateStamp modifications on current Document.
	* <br> To be used during New-Open-Save transactions and any other irrelevant document modifications.
	* <br> deactivations can be performed successively.The same number of reactivations need to be performed
	*      then to reactivate effectively the storage of UpdateStamp modifications.
	* @return
	*		 S_OK : deactivation successfully ended
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT GloballyDeactivateUpdateStampStorage();

	/**
	* Triggers off UpdateStamp incrementation on current Document.
	* <br><b>Role:</b> triggers off undoable UpdateStamp incrementation and storage on current Document:
	* <ul>
	* <li>undoable, as stamp value before modification is accessible</li>
	* <li>monitored by dialog engine transaction changes, in interactive session</li>
	* <li>always performed in batch session </li>
	* </ul>
	* @param ipDocument
	*     Document wich UpdateStamp data are to be touched
	* @param oOldUpdateStamp 
	*     the current value of UpdateStamp before it is effectively updated on current document
    *     through this output value, the modified stamp is undoable by caller, using SwapUpdateStamp 
	* @param iPropagateToRepRef 
	*     TRUE: by default.Propagates the modification to RepRef current document is attached to
	* @return
	*		 S_OK : successfully ended and UpdateStamp modified
	*		 S_FALSE : successfully ended but UpdateStamp NOT modified (dirtify deactivated)
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT TouchUpdateStamp(CATDocument * ipDocument, CATOmbUpdateStamp & oOldUpdateStamp, CATBoolean iPropagateToRepRef=TRUE);

	/**
	* Triggers off UpdateStamp incrementation on current Document.
	* <br><b>Role:</b> triggers off UpdateStamp incrementation and storage on current Document:
	* <ul>
	* <li>not undoable, as stamp value before modification is not accessible</li>
	* <li>monitored by dialog engine transaction changes, in interactive session</li>
	* <li>always performed in batch session </li>
	* </ul>
	* @param ipDocument
	*     Document wich UpdateStamp data are to be touched
	* @param iPropagateToRepRef 
	*     TRUE: by default.Propagates the modification to RepRef current document is attached to
	* @return
	*		 S_OK : successfully ended and UpdateStamp modified
	*		 S_FALSE : successfully ended but UpdateStamp NOT modified (dirtify deactivated)
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT TouchNonUndoableUpdateStamp(CATDocument * ipDocument, CATBoolean iPropagateToRepRef=TRUE);

	/**
	* Swaps New/old value of UpdateStamp for undo/redo management.
	* <br><b>Role:</b> Swaps New/old value of UpdateStamp when performing undo/redo modifications on current Document
	* @param ipDocument
	*     Document wich UpdateStamp is to be swapped
	* @param iNewUpdateStamp 
	*     the new current value set to UpdateStamp
	* @param oOldUpdateStamp 
	*     the previous current value of UpdateStamp, before it is set to iNewUpdateStamp
	* @return
	*		 S_OK : successfully ended and UpdateStamp modified
	* <br> E_FAIL : a software error occured
	*/
	static HRESULT SwapUpdateStamp(CATDocument * ipDocument, CATOmbUpdateStamp iNewUpdateStamp, CATOmbUpdateStamp & oOldUpdateStamp);

};
#endif
