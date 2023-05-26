#ifndef _CATRepPath_WR_H
#define _CATRepPath_WR_H

#include <CATRepPath.h>
#include <CATRepWeakRef.h>
#include <list.h>

/**
 * A list of weak reference: can be used as a 'safe' CATRepPath
 **/
class CATRepPath_WR
{
public:
	/*
	 * Constructors
	 */
	inline CATRepPath_WR(void);
	inline CATRepPath_WR( const CATRepPath *iPath );
	/**
	 * Destructor
	 **/
	inline ~CATRepPath_WR(void);
	/*
	 * operators
	 */
	inline CATRepPath_WR &operator += ( CATRep *iObject );
	inline CATRepPath_WR &operator -= ( CATRep *iObject );
	inline CATRep *operator [] ( int iIndex ) const;
	/**
	 * Remove all
	 **/
	inline void RemoveAll( void );
	/**
	 * Get size
	 **/
	inline int Size(void) const;
	/**
	 * Add to rep path
	 **/
	inline void Append( CATRepPath &oPath, int iLength= -1 ) const;
	/**
	 * Set from a rep path
	 **/
	inline void Set( const CATRepPath *iPath );
private:
	CATRepPath_WR( const CATRepPath_WR &iList );
	CATRepPath_WR &operator = ( const CATRepPath_WR &iList );
	list<CATRepWeakRef> _list;
};

inline CATRepPath_WR::CATRepPath_WR(void)
{
}

inline CATRepPath_WR::CATRepPath_WR( const CATRepPath *iPath )
{
	if( iPath )
	{
		for( int i= 0; i<iPath->Size(); i++ )
		{
			CATRep *object= (*iPath)[i];
			if( object )
			{
				CATRepWeakRef *wr= object->GetRepWeakRef();
				if( wr )
				{
					_list+= wr;
				}
			}
		}
	}
}

inline void CATRepPath_WR::Set( const CATRepPath *iPath )
{
	RemoveAll();
	if( iPath )
	{
		for( int i= 0; i<iPath->Size(); i++ )
		{
			CATRep *object= (*iPath)[i];
			if( object )
			{
				CATRepWeakRef *wr= object->GetRepWeakRef();
				if( wr )
				{
					_list+= wr;
				}
			}
		}
	}
}

inline CATRepPath_WR::~CATRepPath_WR(void)
{
	RemoveAll();
}

inline CATRepPath_WR &CATRepPath_WR::operator += ( CATRep *iObject )
{
	if( iObject )
	{
		CATRepWeakRef *wr= iObject->GetRepWeakRef();
		if( wr )
		{
			_list+= wr;
		}
	}
	return *this;
}

inline CATRepPath_WR &CATRepPath_WR::operator -= ( CATRep *iObject )
{
	if( iObject )
	{
		CATRepWeakRef *wr= iObject->GetRepWeakRef();
		if( wr )
		{
			_list-= wr;
			wr->Release();
		}
	}
	return *this;
}

inline CATRep *CATRepPath_WR::operator [] ( int iIndex ) const
{
	CATRepWeakRef *wr= _list[iIndex];
	if( !wr ) return NULL;
	return wr->GiveRep();
}

inline void CATRepPath_WR::RemoveAll( void )
{
	for( int i= 0; i<_list.length(); i++ )
	{
		CATRepWeakRef *wr= _list[i];
		if( wr )
		{
			wr->Release();
		}
	}
	_list.empty();
}

inline int CATRepPath_WR::Size(void) const
{
	return _list.length();
}

inline void CATRepPath_WR::Append( CATRepPath &oPath, int iLength ) const
{
	if( iLength==-1 ) iLength= _list.length();
	for( int i= 0; i<iLength; i++ )
	{
		CATRepWeakRef *wr= _list[i];
		if( !wr ) continue;
		CATRep *object= wr->GiveRep();
		if( !object ) continue;
		oPath.AddRep( *object );
	}
}

#endif
