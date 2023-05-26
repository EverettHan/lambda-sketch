/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2000
#ifndef CATIList_H
#define CATIList_H

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */


/*  CAA2Reviewed by FRH */


#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "CATICkeParm.h"
#include "CATLifSpecs.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIList;
#else
extern "C" const IID IID_CATIList;
#endif

/**
*
* Interface dedicated to the management of  list objects.<br>
* A list is an ordered collection of items, which are objects.<br>
* This interface is multi implemented (on List feature and volatile list implementation).<br>
* Volatile list can reference any kind of object (CATBaseUnknown) including parameters (CATICkeParm).<br>
* List feature can only reference persisten features (CATISpecObject) or literals (CATICkeParm).<br>
* Lists are created with CATICkeParmFactory
* @see CATICkeParmFactory
*/
class ExportedByCATLifSpecs CATIList : public CATBaseUnknown
{

public:

	/**
	* Returns the size of the list.
	* i.e. non null elements of the list.
	     * @return list size.
	 */
	virtual int GetSize() = 0;

	/**
  * Retrieves an item in the list.
  * @param iIndex Starts at 1.
  * @param oItem Object to return.
  *
  * @return
 <br><b>Legal values</b>: 
	* <dl>
	* <dt><tt>S_OK</tt><dd> if the index is comprised between 1 and the size of the list 
	*   and the returned object is different from NULL.
	* <dt><tt>S_FALSE</tt><dd> if the index is comprised between 1 and the size of the list
	*   but the returned object is equal to NULL.
	* <dt><tt>E_FAIL</tt><dd> else.
	* </dl>
  */
  virtual HRESULT GetItem(int iIndex, CATBaseUnknown_var& oItem) = 0;

  /** 
  * New method to access item, for performance reasons in massive usage.
  * AddRefs the returned pointer.
  */ 
  virtual CATBaseUnknown * GetItem(int iIndex) = 0;
	
	/**
	 * Retrieves the position of the first occurence if the item in the list,	starting from the index iStartIndex included.
	 * @param iValue item
	 * @param iStartIndex index to start in the list
	 * @return index of the item and 0 if the item is not found.
	 * Returns 0 if the item is not found.
	 */
  virtual int GetIndexOfItem(CATBaseUnknown* iValue, int iStartIndex = 1) = 0;

	/**
	* Sets an item in the list. Does an AddRef on the item.
	* @param index Starts at 1.
	* @param iValue the item to set.
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>    <dd> if the index is comprised between 
	* 0 (means append) and the size of the list and if the 
	* object type is correct.
	*   <dt><tt>E_FAIL</tt>  <dd> if the object type is not correct, 
	* if index is out of bounds or if you try to insert an already 
	* existing element while IsDuplicateElementsAllowed is equal to
	* FALSE.
	*   </dl>
	*/

  virtual HRESULT SetItem(int index,
							 CATBaseUnknown* iValue) = 0; 

	/**
	* Insert an item in the list. Does an AddRef on the item.
	* @param index Starts at 1.
	* @param iValue the inserted item.
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>    <dd> if the index is comprised between 
	* 1 and the size of the list and if the object type is correct.
	*   <dt><tt>E_FAIL</tt>  <dd> if the object type is not correct, 
	* if index is out of bounds or if you try to insert an already 
	* existing element while IsDuplicateElementsAllowed is equal to
	* FALSE.
	*   </dl>
	*/

	virtual HRESULT InsertItem(int index,
		                       CATBaseUnknown* iValue) = 0; 

	/**
	* Removes an item from the list. Does a Release on the item.
	* This method pushes back all following items of the list.
	* @param index index of the object to suppress. Starts at 1.
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>    <dd> if the index is comprised between 
	* 1 and the size of the list and if the operation succeeded.
	*   <dt><tt>E_FAIL</tt>  <dd> if the object has not been removed 
	* or if index is out of bounds. 
	*   </dl>
	*/
	virtual HRESULT RemoveItem(int index) = 0;

 	 /**
	* Removes all the items from the list. Does a Release on the items.
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>    <dd> if the the operation succeeded 
	* and if all the objects have been removed.
	*   <dt><tt>E_FAIL</tt>  <dd> if the objects have not been removed. 
	*   </dl>
	*/

	virtual HRESULT RemoveAll() = 0;

	/**
	* Reorders an element by moving it from current position to target position.
	* Doesn't change the list if either position is out of the list.
	* @param iCurrent current position of item to reorder
	* @param iTarget target position
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>    <dd> if the the operation succeeded. 
	*   <dt><tt>E_FAIL</tt>  <dd> if cannot reorder. 
	*   </dl>
	*/
	virtual HRESULT Reorder(int iCurrent,
							                int iTarget) = 0;

  	/**
	* @nodoc : suppressed
	* Sorts the list.
	* Returns E_FAIL if there is no sorting expression, or the list
	* cannot manage sorting.
	*/
	virtual HRESULT Sort() = 0;

	/** 
	* @nodoc : suppressed
	 * Sets a sorting expression used to sort the list.
	 * The sorting expression must take two parameters, and will be called
	 * for both parameters. They are to be called a1 and a2.
	 * @param iExpression a String expressing the sort function.
	 */
	virtual HRESULT SetSortingExpression(const CATUnicodeString& iExpression) = 0;

	/** 
	* @nodoc : suppressed
	 * Gets the sorting expression used to sort the list.
	 * @return sorting expression or an empty String if there is no expression.
	 */
	virtual CATUnicodeString GetSortingExpression() = 0;

    /**
	* @nodoc : suppressed
	 * 1 if the list is sorted according to its sorting expression.
	 * 0 if it is not sorted.
	* Indicates if the list is sorted.
	* @return 1 if the list is sorted according to its sorting expression,0 if it is not sorted.
*/
	virtual int IsSorted() = 0;

	/**
	 * Limits the elements in the interface to instances of a certain type.
	 * If there are already elements of another type, returns E_FAIL.
	 * Note the argument should be a type structure, but which one???
	 * Passing a null argument will have same effect as UnsetListType.
	 * @param iTypeName Name of the type.
	 * @return classic HRESULT
	 */
    virtual HRESULT SetListType(const CATUnicodeString& iTypeName) = 0;

	/**
	 * Returns the type allowed for elements of the list.
	 * Returns a null string if type is not set.
	 */
    virtual const CATUnicodeString GetListType() = 0;

	/**
	* Locks the type of the items in the list for users modifications.
	* @return E_FAIL if the list type has not been valuated.
	 */
	virtual HRESULT LockListType() = 0;

	/**
	* UnLocks the List type modifications.
	* @return E_FAIL if the list type has not been valuated.
	 */
	virtual HRESULT UnLockListType() = 0;

	/**
	* Indicates if the list type has been locked.
	* @return 1 if the list type is locked,0 if it is not Locked.
	 */
	virtual int IsListTypeLocked() = 0;

	/**
	* Indicates if the type of the elements of the list has been set.
	* @return 1 if elements of the list must be of a given type, 0 otherwise.
	 */
	 virtual int IsTypeSet() = 0;

	/**
	 * Authorize objects of any type to be put in the list.
	 * @return classic HRESULT
	 */
    virtual HRESULT UnsetListType() = 0;

    /**
	* Indicates if the list can contain duplicate items. 
	* @return 1 if elements can be duplicated, 0 otherwise.
	 */
	virtual int IsDuplicateElementsAllowed() = 0;

	/**
	 * Prevents or allows duplication of elements. Allowed by default.
	 * @param iDuplicate If iDuplicate is 0, prevents, otherwise, allows duplication.
     * Note this method doesn't remove duplicate elements already present.
     * It just allows to set whether duplicates should be alloed or not.
	 * @return classic HRESULT
	 */
	virtual HRESULT AllowDuplicateElements(int iDuplicate) = 0;

    /**
	* @nodoc : suppressed
	* Sets an operation to compute a result. The operation is effected between
	* elements of the list that follow one another:
	* For instance if operation is f(x,y) and list has elements 1,2,3,4,
	* The result is f(f(f(1,2),3),4). with f = +, this means 1+2+3+4
	*/
	virtual void SetOperation(const CATUnicodeString& iOperation) = 0;
	
	/**
	* @nodoc : suppressed
	* Returns the operation associated to the list. 
	*/
	virtual CATUnicodeString GetOperation() = 0;
	
	/**
	* @nodoc : suppressed
	* Returns the result of the operation on elements of the list, like 1+2+3+4.
	* @return E_FAIL if no operation defined (NONE operation).
	*/
	virtual HRESULT GetOperationResult(CATICkeParm_var& oResult) = 0;

  CATDeclareInterface;
};

CATDeclareHandler(CATIList,CATBaseUnknown);

#endif
