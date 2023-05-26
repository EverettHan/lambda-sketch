// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATHashObject_h
#define CATHashObject_h

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOMY.h"
#include "CATHashTable.h"

class CATHashCodeIter;

class ExportedByCATOMY CATHashObject : public CATHashTable
{

  public:

    CATHashObject(int iSize = 200);
    virtual ~CATHashObject();

    int Put(void* iKey,void* iContent);
    int Insert (void* iKey,void* iContent);
    void* Get(void* iKey);
    void* RemoveValue ( void* iKey );

    void Begin();
    int Next(void*& key,void*& value);
    
    void  RemoveAll ();
    
  private:

    // Structure definition
    struct HashManagement {
	void*	_key;
	void*	_value;
	};

    CATHashCodeIter* _iter;
    
    static unsigned int Hash ( const void* value );
    static int Compare ( const void* value1,const void* value2 );
};


#endif // CATHashObject_h
