//*****************************************************************************
//* DO NOT USE!                                                               *
//*****************************************************************************

#ifndef _DSYListPtrIUnknown_H
#define _DSYListPtrIUnknown_H

#include "CO0LSTPV.h"           // ExportedByCO0LSTPV
#include "CATListPV.h"          // CATRawCollPV

// _DSYListPtrIUnknown can be inlined or not depending on wether _DSYLIST_IUNKNOWN_INLINE_ is defined or not.
#undef _DSYLIST_IUNKNOWN_INLINE_
// #define _DSYLIST_IUNKNOWN_INLINE_

#if defined(_DSYLIST_IUNKNOWN_INLINE_)
# undef  ExportedByCO0LSTPV 
# define ExportedByCO0LSTPV
#endif  // _DSYLIST_IUNKNOWN_INLINE_

struct IUnknown;

class ExportedByCO0LSTPV _DSYListPtrIUnknown : public CATRawCollPV
{
public:
    _DSYListPtrIUnknown( int iInitAlloc = 0 ) : CATRawCollPV(iInitAlloc)
    {
    }
    _DSYListPtrIUnknown( const _DSYListPtrIUnknown & iCopy ) : CATRawCollPV(iCopy)
    {
        _ElementsAddRef();
    }
    _DSYListPtrIUnknown( void** iArray , int iSize ) : CATRawCollPV(iArray, iSize)
    {
        _ElementsAddRef();
    }        
    virtual ~_DSYListPtrIUnknown ( )
    {
        RemoveAll();
    }
    
    int Append ( void *iAdd );    
    int Append ( const _DSYListPtrIUnknown & iConcat );
    
    int InsertAt ( int iPos , void *iAdd );
    
    int Size ( ) const { return CATRawCollPV::Size(); }
    int Size ( int iSize );
    // int Size ( int iSize, void *iFiller );                   // Not Impl
    
    int  RemoveValue(void *iRemove);
    // int  Remove ( const CATRawCollPV & iSubstract );         // Not Impl
    void RemovePosition(int iPos);
    int  RemovePosition(int iIndex, unsigned int iNbElem);
    
    void RemoveAll(CATCollec::MemoryHandling iMH = CATCollec::ReleaseAllocation)
    {
        _ElementsRelease();
        CATRawCollPV::RemoveAll(iMH);
    }
    
    int RemoveDuplicates( _DSYListPtrIUnknown * ioExtract = NULL );
    
    void FillArray( void ** ioArray , int iMaxSize ) const;
    
    static void Intersection ( const _DSYListPtrIUnknown & iRC1,
                   const _DSYListPtrIUnknown & iRC2,
                   _DSYListPtrIUnknown & ioResult );
    
private:
    void _ElementsAddRef();
    void _ElementsRelease();
};
    
#if defined(_DSYLIST_IUNKNOWN_INLINE_)
# define DSYLIST_IUNKNOWN_INLINE inline // Define DSYLIST_IUNKNOWN_INLINE as inline (the keyword)
# include "DSYListPtrIUnknown.ipp"      // It is included only when _DSYLIST_IUNKNOWN_INLINE_ is defined
#endif  // _DSYLIST_IUNKNOWN_INLINE_

#endif  // _DSYListPtrIUnknown_H
