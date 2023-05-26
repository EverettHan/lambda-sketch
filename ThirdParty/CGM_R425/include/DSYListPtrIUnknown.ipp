/**
 * @fullreview IK8 ADT 15:02:10 Initial delivery - _DSYListPtrIUnknown implementation.
 */
#include "IUnknown.h"

DSYLIST_IUNKNOWN_INLINE int _DSYListPtrIUnknown::Append ( void *iAdd )
{
    int rc = CATRawCollPV::Append(iAdd);
    if(0 == rc)
        if(iAdd) static_cast<IUnknown *>(iAdd)->AddRef();
    return rc;
}

DSYLIST_IUNKNOWN_INLINE int _DSYListPtrIUnknown::Append ( const _DSYListPtrIUnknown & iConcat )
{
    int rc = CATRawCollPV::Append(iConcat);
    if( 0 == rc)
    {
        for(int i = 1; i <= iConcat.Size(); i++)
        {
            void *pItem = iConcat[i];
            if(pItem) static_cast<IUnknown *>(pItem)->AddRef();
        }
    }
    return rc;
}

DSYLIST_IUNKNOWN_INLINE int _DSYListPtrIUnknown::InsertAt ( int iPos , void *iAdd )
{
    int rc = CATRawCollPV::InsertAt(iPos, iAdd);
    if(0 == rc)
        if(iAdd) static_cast<IUnknown *>(iAdd)->AddRef();
    return rc;
}

DSYLIST_IUNKNOWN_INLINE int _DSYListPtrIUnknown::Size ( int iSize )
{
    // Check if there are some elements to release
    int l_CurSize = this->Size();
    if(iSize < l_CurSize)
    {
        for(int i = iSize+1; i <= l_CurSize; i++)
        {
            void *pItem = CATRawCollPV::operator[](i);
            if(pItem) static_cast<IUnknown *>(pItem)->Release();
        }
    }
    int rc = CATRawCollPV::Size(iSize);
    if(iSize > l_CurSize)
    {
        // Zero-initialize new entries (mandatory)
        for(int i = l_CurSize+1; i <= iSize; i++)
            CATRawCollPV::operator[](i) = NULL;
    }
    return rc;
}

DSYLIST_IUNKNOWN_INLINE int _DSYListPtrIUnknown::RemoveValue(void *iRemove)
{
    int l_Index = CATRawCollPV::RemoveValue(iRemove);
    if(l_Index > 0) // Indexes start at 1
        if(iRemove) static_cast<IUnknown *>(iRemove)->Release();
    return l_Index;
}

DSYLIST_IUNKNOWN_INLINE void _DSYListPtrIUnknown::RemovePosition(int iPos)
{
    void *pItem = CATRawCollPV::operator[](iPos);
    if(pItem) static_cast<IUnknown *>(pItem)->Release();
    CATRawCollPV::RemovePosition(iPos);
}

DSYLIST_IUNKNOWN_INLINE int  _DSYListPtrIUnknown::RemovePosition(int iIndex, unsigned int iNbElem)
{
    for(int i = iIndex; i <= iIndex + (int)iNbElem - 1; i++)
    {
        void *pItem = CATRawCollPV::operator[](i);
        if(pItem) static_cast<IUnknown *>(pItem)->Release();
    }
    return CATRawCollPV::RemovePosition(iIndex, iNbElem);
}

DSYLIST_IUNKNOWN_INLINE int _DSYListPtrIUnknown::RemoveDuplicates( _DSYListPtrIUnknown * ioExtract )
{
    // TODO IMPROVEMENT: share algorithm with CATRawCollPV in order to remove unnecessary copies.
    CATRawCollPV l_Duplicates;
    int l_CntDup = CATRawCollPV::RemoveDuplicates(&l_Duplicates);
    for(int i = 1; i <= l_Duplicates.Size(); i++)
    {
        IUnknown *pItem = static_cast<IUnknown *>(l_Duplicates[i]);
        if(ioExtract)
            ioExtract->Append(pItem);   // AddRef if not NULL
        if(pItem) pItem->Release();
    }
    return l_CntDup;
}

DSYLIST_IUNKNOWN_INLINE void _DSYListPtrIUnknown::FillArray( void ** ioArray , int iMaxSize ) const
{
    CATRawCollPV::FillArray(ioArray, iMaxSize);
    for(int i = 0; i < iMaxSize; i++)
    {
        void *pItem = ioArray[i];
        if(pItem) static_cast<IUnknown *>(pItem)->AddRef();
    }
}

DSYLIST_IUNKNOWN_INLINE void _DSYListPtrIUnknown::Intersection ( const _DSYListPtrIUnknown & iRC1,
               const _DSYListPtrIUnknown & iRC2,
               _DSYListPtrIUnknown & ioResult )
{
    int l_SizePrev = ioResult.Size();
    CATRawCollPV::Intersection(iRC1, iRC2, ioResult);
    int l_SizeNext = ioResult.Size();
    for(int i = l_SizePrev+1; i <= l_SizeNext; i++)
    {
        void *pItem = ioResult.CATRawCollPV::operator[](i);
        if(pItem) static_cast<IUnknown *>(pItem)->AddRef();
    }
}

DSYLIST_IUNKNOWN_INLINE void _DSYListPtrIUnknown::_ElementsAddRef()
{
    for(int i = 1; i <= CATRawCollPV::Size(); i++)
    {
        void *pItem = static_cast<void *>(CATRawCollPV::operator[](i));
        if(pItem) static_cast<IUnknown *>(pItem)->AddRef();
    }
}
DSYLIST_IUNKNOWN_INLINE void _DSYListPtrIUnknown::_ElementsRelease()
{
    for(int i = 1; i <= CATRawCollPV::Size(); i++)
    {
        void *pItem = static_cast<void *>(CATRawCollPV::operator[](i));
        if(pItem) static_cast<IUnknown *>(pItem)->Release();
    }
}
