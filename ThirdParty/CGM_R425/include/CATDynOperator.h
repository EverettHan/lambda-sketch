#ifndef CATDynOperator_H
#define CATDynOperator_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "BODYNOPE.h"
#include "CATString.h"
#include "CATTopOperator.h"
#include "CATDynOperatorDef.h"
#ifndef NULL
#define NULL 0
#endif

class CATBody;
class CATGeoFactory;
class CATCGMJournalList;
class CATCGMActivateDebug;

/**
* Abstract base class for the operators of filleting, drafting, chamfering, shelling and Boolean operations.
* <br> A topological operation is realized with the appropriate operator. 
* These operators follow the global frame of the topological operators and satisfy the smart mechanism: 
* the input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>A derived operator is created with a global function.
* It must be
* directly deleted after use with the usual C++ <tt>delete</tt> operator.
* It is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method. 
*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method.  
*</ul>
*/  
class ExportedByBODYNOPE CATDynOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATDynOperator);
public:

/**
 * @nodoc
 * Virtual constructor of a CATDynOperator.<br>
 * Cannot be called. Use the <tt>CATDynCreateXxx</tt> global function
 * to create the Xxx operator.
 */
	CATDynOperator(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtTopOperator* iExtensible=NULL);
/** @nodoc */	
#if defined ( CATIACGMV5R20 )
  CATDynOperator(CATGeoFactory* iFactory, CATCGMJournalList* iJournal=0, CATExtTopOperator* iExtensible=NULL);
#else
	CATDynOperator(CATGeoFactory* iFactory, CATCGMJournalList* iJournal=0);
#endif 
	
/**
 * Destructor.
 */
  virtual ~CATDynOperator ();

/**
 * @nodoc
 * Deprecated.
 * Returns a pointer to the body resulting from the boolean operation between the input
 * body and the result of <tt>this</tt> CATDynOperator.<br>
 * This is available for prism, revol and sweep operator, and allows two operations
 * in one way.
 */
  CATBody*           GetBooleanResult()  const;

/**
 * @nodoc
 * Deprecated.
 * Returns a pointer to the topological journal corresponding to the boolean operation after
 * the CATDynOperator.
 * (see <tt>GetBooleanResult</tt>).
 * <br>Only available if a journal was given at the creation of the operator.
 */
  CATCGMJournalList* GetBooleanJournal() const;


protected:
	/** @nodoc */
  void SetBooleanResult(CATBody*);
	/** @nodoc */
  void SetBooleanJournal(CATCGMJournalList* iBooleanJournal);
	/** @nodoc */
  CATCGMActivateDebug* _AssociatedBreakPoint;
	/** @nodoc */
  void SetLog(CATLONG32 );
  /** @nodoc */
  CATCGMJournalList*   _OldJournal;

private:
  CATCGMJournalList*   _BooleanJournal;
	CATCGMJournalList*   _UnusedToDelete;
  CATBody*             _BooleanResult;
};

/** 
 * @nodoc 
 */
ExportedByBODYNOPE void Remove(CATDynOperator*& iOperator);


#endif
