#ifndef _CATDynHashTable_H
#define _CATDynHashTable_H

#include <CATView.h>
#include <CATHashTable.h>

/**
 * Wrapper for CATHashTable with dynamic resize
 **/
class ExportedByCATView CATDynHashTable
{
public:
	/**
	 * Constructor
	 **/
    CATDynHashTable( CATCollec::PFHash iPFH= HashPtr, CATCollec::PFCompare iPFC= ComparePtr );
	/**
	 * Destructor
	 **/
	~CATDynHashTable(void);
	/**
	 * CATHashTable::Insert
	 **/
    inline int Insert( void* iAdd );
	/**
	 * CATHashTable::Locate
	 **/
    inline void* Locate( void* iLocate ) const;
	/**
	 * CATHashTable::Remove
	 **/
    inline void* Remove( void* iRemove );
	/**
	 * CATHashTable::Size
	 **/
	inline int Size(void) const;
	/**
	 * CATHashTable::operator []
	 **/
    inline void* operator[] ( const CATHashCodeIter& iIter ) const;
	/**
	 * CATHashTable::RemoveAll
	 **/
    inline void RemoveAll(void);
	/**
	 * Get internal hashtable
	 **/
	inline CATHashTable *GetHashTable(void) const;
private:
	void CheckAndResize(void);
	int _checkCountdown;
	CATCollec::PFHash _HashFunction;
	CATCollec::PFCompare _CompareFunction;

	static unsigned int HashPtr( const void *iPtr );
	static int ComparePtr( const void *iPtr1, const void *iPtr2 );
	CATHashTable *_table;
};


inline int CATDynHashTable::Insert( void* iAdd )
{
	if( _table )
	{
		_checkCountdown--;
		if( _checkCountdown<=0 )
		{
			CheckAndResize();
		}
		return _table->Insert( iAdd );
	}
	return 0;
}

inline void* CATDynHashTable::Locate( void* iLocate ) const
{
	if( _table )
	{
		return _table->Locate( iLocate );
	}
	else
	{
		return NULL;
	}
}

inline void* CATDynHashTable::Remove( void* iRemove )
{
	if( _table )
	{
		return _table->Remove( iRemove );
	}
	else
	{
		return NULL;
	}
}

inline int CATDynHashTable::Size(void) const
{
	if( _table )
	{
		return _table->Size();
	}
	else
	{
		return 0;
	}
}

inline void* CATDynHashTable::operator[] ( const CATHashCodeIter& iIter ) const
{
	if( _table )
	{
		return (*_table)[iIter];
	}
	else
	{
		return NULL;
	}
}

inline void CATDynHashTable::RemoveAll(void)
{
	if( _table )
	{
		_table->RemoveAll();
	}
}

inline CATHashTable *CATDynHashTable::GetHashTable(void) const
{
	return _table;
}

#endif
