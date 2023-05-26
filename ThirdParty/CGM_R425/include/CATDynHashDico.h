#ifndef _CATDynHashDico_H
#define _CATDynHashDico_H

#include <CATView.h>
#include <CATHashDico.h>

/**
 * Wrapper for CATHashDico with dynamic resize
 **/
class ExportedByCATView CATDynHashDico
{
public:
	/**
	 * Constructor
	 **/
    CATDynHashDico(void);
	/**
	 * Destructor
	 **/
	~CATDynHashDico(void);
	/**
	 * CATHashDico::Insert
	 **/
    inline int Insert( const CATUnicodeString& iLocate, void* iAdd );
	/**
	 * CATHashDico::Locate
	 **/
    inline void* Locate( const CATUnicodeString& iLocate ) const;
	/**
	 * CATHashDico::Remove
	 **/
    inline void* Remove( const CATUnicodeString& iRemove );
	/**
	 * CATHashDico::Size
	 **/
	inline int Size(void) const;
	/**
	 * CATHashDico::operator []
	 **/
    inline void* operator[] ( const CATHashCodeIter& iIter ) const;
	/**
	 * CATHashDico::RemoveAll
	 **/
    inline void RemoveAll(void);
	/**
	 * CATHashDico::ItemName
	 **/
    inline const CATUnicodeString* ItemName ( const CATHashCodeIter& iIter ) const;
	/**
	 * Get internal hashtable
	 **/
	inline CATHashDico *GetHashDico(void) const;
private:
	void CheckAndResize(void);
	int _checkCountdown;

	CATHashDico *_table;
};


inline int CATDynHashDico::Insert( const CATUnicodeString& iLocate, void* iAdd )
{
	if( _table )
	{
		_checkCountdown--;
		if( _checkCountdown<=0 )
		{
			CheckAndResize();
		}
		return _table->Insert( iLocate, iAdd );
	}
	return 0;
}

inline void* CATDynHashDico::Locate( const CATUnicodeString& iLocate ) const
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

inline void* CATDynHashDico::Remove( const CATUnicodeString& iRemove )
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

inline int CATDynHashDico::Size(void) const
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

inline void* CATDynHashDico::operator[] ( const CATHashCodeIter& iIter ) const
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

inline void CATDynHashDico::RemoveAll(void)
{
	if( _table )
	{
		_table->RemoveAll();
	}
}

inline CATHashDico *CATDynHashDico::GetHashDico(void) const
{
	return _table;
}

inline const CATUnicodeString* CATDynHashDico::ItemName ( const CATHashCodeIter& iIter ) const
{
	if( _table )
	{
		return _table->ItemName( iIter );
	}
	else
	{
		return NULL;
	}
}

#endif
