/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2003  
//-----------------------------------------------------------------------------
// class CATWSMergeTransactionsLog :
// 
// Log object for Warm-Start Undo-Redo management.
// Logs the merge of a merged CATSpecTransaction into a target CATSpecTransaction.
// Can also be used to log the purging of a CATSpecTransaction (when no target 
// transaction is provided).
// Implements CATIWSUndoRedoLog.
// See CATWSMarshalMergeTransactionsLog extension for marshalling/unmarshalling
// 
//-----------------------------------------------------------------------------
// Creation by User led
//-----------------------------------------------------------------------------

#ifndef CATWSMergeTransactionsLog_H
#define CATWSMergeTransactionsLog_H

/**
 * @level Private
 * @usage U1
 */

#include "CATWSTransactionID.h"
#include "CATOmbWarmStart.h"
#include "CATBaseUnknown.h"

class CATWSUndoRedoInfo;

class ExportedByCATOmbWarmStart CATWSMergeTransactionsLog : public CATBaseUnknown {
	CATDeclareClass;
	friend class CATWSMarshalMergeTransactionsLog;

public:
	CATWSMergeTransactionsLog(CATWSTRANSACTIONID merged, CATWSTRANSACTIONID target);
	virtual ~CATWSMergeTransactionsLog();

	// CATIWSUndoRedoLog implementation
	virtual HRESULT UpdateUndoRedoInfo(CATWSUndoRedoInfo *iopInfo);
/*
private:
	// identifier for the merged CATSpecTransaction
	CATWSTRANSACTIONID	_merged_transaction_id;
	// identifier for the target(absorbing) CATSpecTransaction
	CATWSTRANSACTIONID	_target_transaction_id;

	// disabled copy operator
	CATWSMergeTransactionsLog & operator=(CATWSMergeTransactionsLog& Icopy) { return *this; };
	// disabled copy constructor
	CATWSMergeTransactionsLog(CATWSMergeTransactionsLog& Icopy) {};*/

};

#endif 
