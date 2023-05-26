#ifndef CATSYPMappingTablePointerToPointer_h
#define CATSYPMappingTablePointerToPointer_h

// COPYRIGHT Dassault Systemes 2009

// System framework
#include <CATBaseUnknown.h>
#include <IntroInfra.h>
#include <CATSysSimpleHashTable.h>
#include <CATUnicodeString.h>
#include <CATListOfCATUnicodeString.h>

/**
 * Class used to manage a collection of mappings between two pointers.
 **/
class ExportedByIntroInfra CATSYPMappingTablePointerToPointer
{
  public:
	
	  CATSYPMappingTablePointerToPointer(int iSizeEstimate = 0);
	  virtual ~CATSYPMappingTablePointerToPointer();

	  /**
	   * Inserts the mapping between the key represented by the object Key and the associated object iAssociatedObj.
	   * Returns 0 if an element, equal to the given key, already exists in the hashtable,
	   * Returns 1 if the given element has been inserted successfully.
	   * Returns -1 in case of failure.
	   */
	  int Insert(const void* iKeyObj, const void* iAssociatedObj);

	  /**
	   * Returns a pointer on associated object or NULL if object not found.
	   */
	  const void * Locate(const void* iKeyObj) const;

	  /**
	   * Removes the associated object from the hash table.
	   * Returns the removed object if successful, NULL otherwise.
	   */
	  const void * Remove(void* iKeyObj);

	  /**
	   * Removes all the elements of the hash table.
	   */
	  void RemoveAll();

	  /**
	   * Returns the number of stored elements in the hash table.
	   */
	  int Size() const;

	  /**
	   * Returns the associated element stored in the hash table to the specified index.
	   */
	  void Get(int iPos, const void** o_ppKeyObj, const void** o_ppAssociatedObj) const;

  private:
	  
	  class Relation
	  {
	    public:

			Relation() : _pKeyObj(NULL), _pAssociatedObj(NULL) {};
			Relation(const void * pKeyObj, const void * pAssociatedObj) : _pKeyObj(pKeyObj), _pAssociatedObj(pAssociatedObj) {};
			~Relation() {};

			const void * _pKeyObj;
			const void * _pAssociatedObj;
	  };

	  CATSysSimpleHashTable _table;

	  static unsigned int s_HashFunction(void *iPtr);
	  static int s_CompareFunction(void * iPtr1, void *iPtr2);
};

#endif // CATSYPMappingTablePointerToPointer_h

