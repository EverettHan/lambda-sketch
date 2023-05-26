/**
 * @fullreview IK8 15:02:10 Initial delivery - Generic list of pointer based on CATRawCollPV (~ same API).
 *                           - Take care of AddRef/Release for IUnknown-derived objects
 *                           - No code overhead for other objects
 *                           TODO: implement interactions between lists of related pointers (A <- B for e.g.)
 *                           TODO IMPLEMENT:
 *                           - int  Size ( int iSize, void *iFiller );
 *                           - int  Remove ( const CATRawCollPV & iSubstract );
 *                           DO NOT IMPLEMENT: 
 *                           - void QuickSort (int (*iPFCompare) (const void*, const void*));   -> Not reentrant nor thread-safe
 */

//*****************************************************************************
//* INTERNAL USE ONLY!                                                        *
//*****************************************************************************
 
#ifndef _DSYListPtr_H
#define _DSYListPtr_H

#include "CATListPV.h"          // CATRawCollPV
#include "DSYListPtrIUnknown.h" // _DSYListPtrIUnknown

// STL
#include <type_traits>          // is_base_of

/**
 * DSYListPtr<T>
 * List of pointers of type T.
 * If T derives from IUnknown, AddRef/Release are automatically performed when adding/removing elements from the list.
 */

/**
 * List of pointers.
 * NOTE: in order to enhance portability, this design does not make use of template partial specialization (cf. constraints on Solaris). 
 */
template<int IsGeneric>
class _DSYListPtr : public CATRawCollPV
{
public:
    _DSYListPtr( int iInitAlloc = 0 ) : CATRawCollPV(iInitAlloc)
    {
    }
    _DSYListPtr( const _DSYListPtr<IsGeneric> & iCopy ) : CATRawCollPV(iCopy)
    {
    }
    _DSYListPtr( void** iArray , int iSize ) : CATRawCollPV(iArray, iSize)
    {
    }
    virtual ~_DSYListPtr ( ) {}
};

/**
 * Specialization for types deriving from IUnknown (AddRef/Release support).
 */    
template<>
class _DSYListPtr<1> : public _DSYListPtrIUnknown
{
public:
    _DSYListPtr( int iInitAlloc = 0 ) : _DSYListPtrIUnknown(iInitAlloc)
    {
    }
    _DSYListPtr( const _DSYListPtr<1> & iCopy ) : _DSYListPtrIUnknown(iCopy)
    {
    }
    _DSYListPtr( void** iArray , int iSize ) : _DSYListPtrIUnknown(iArray, iSize)
    {
    }
    virtual ~_DSYListPtr ( )
    {
    }
};


template<typename _Typ>
class DSYListPtr
{
    template <class T> friend class DSYListPtr;
public:
    // Constructors
    DSYListPtr( int iInitAlloc = 0 ) : m_list(iInitAlloc)
    {
    }
    DSYListPtr( const DSYListPtr<_Typ> & iCopy ) : m_list(iCopy.m_list)
    {            
    }
    DSYListPtr( _Typ** iArray , int iSize ) : m_list(iArray, iSize)
    {
    }
    virtual ~DSYListPtr ( )
    {
    }
    
    // Assignment operator        
    DSYListPtr & operator = (const DSYListPtr<_Typ> & iCopy )
    {
        // NOTE: regarding error: "there are no arguments to ‘RemoveAll’ that depend on a template parameter, so a declaration of ‘RemoveAll’ must be available"
        // Solution: one should explicitly invoke base class member functions in a class template through the this pointer.
        m_list.RemoveAll();
        m_list.Append(iCopy.m_list);
        return *this;
    }
    
    int Append ( _Typ *iAdd )
    {
        return m_list.Append(reinterpret_cast<void *>(iAdd));
    }
    
    template <typename U>
    int Append ( const DSYListPtr<U> & iConcat )
    {
        _Typ *p = static_cast<U *>(NULL);   // Buildtime type checking
        return m_list.Append(iConcat.m_list);
    }
    
    int InsertAt ( int iPos , _Typ *iAdd )
    {
        return m_list.InsertAt(iPos, reinterpret_cast<void *>(iAdd));
    }
    
    int Size ( ) const { return m_list.Size(); }
    
    int Size ( int iSize ) { return m_list.Size(iSize); }
    
    _Typ *& operator[] ( int iPos )
    {
        return reinterpret_cast<_Typ *&>(m_list.operator[]( iPos ));
    }
    
    _Typ * operator[] ( int iPos ) const
    {
        return static_cast<_Typ *>(m_list.operator[]( iPos ));
    }
    
    int Locate(_Typ *iLocate , int iFrom = 1) const
    {
        return m_list.Locate(iLocate, iFrom);
    }
    
    int RemoveValue(_Typ *iRemove)
    {
        return m_list.RemoveValue(iRemove);
    }
    
    void RemovePosition(int iPos)
    {
        m_list.RemovePosition(iPos);
    }
    
    int  RemovePosition(int iIndex, unsigned int iNbElem)
    {
        return m_list.RemovePosition(iIndex, iNbElem);
    }
    
    void RemoveAll(CATCollec::MemoryHandling iMH = CATCollec::ReleaseAllocation)
    {
        m_list.RemoveAll(iMH);
    }
    
    int RemoveNulls( )
    {
        return m_list.RemoveNulls();
    }
    
    int RemoveDuplicates( DSYListPtr<_Typ> * ioExtract = NULL )
    {
        if(ioExtract)
            return m_list.RemoveDuplicates(&(ioExtract->m_list));
        return m_list.RemoveDuplicates(NULL);
    }
    
    int operator == ( const DSYListPtr<_Typ> & iRC ) const
    {
        return (m_list == iRC.m_list);
    }
    
    int operator != ( const DSYListPtr<_Typ> & iRC ) const
    {
        return (m_list != iRC.m_list);
    }
    
    static int Compare( const DSYListPtr<_Typ> & iRC1 , const DSYListPtr<_Typ> & iRC2, 
                 int (*iPFCompare) (const _Typ *, const _Typ *) )
    {
        return _DSYListPtr<std::is_base_of<IUnknown, _Typ>::value>::Compare(iRC1.m_list, iRC2.m_list, reinterpret_cast<int (*) (const void *, const void *)>(iPFCompare));
    }
    
    void Swap ( int iPos1 , int iPos2 )
    {
        m_list.Swap(iPos1, iPos2);
    }
    
    void QuickSort_s (int (*iPFCompare) (const _Typ *const*, const _Typ *const*))
    {
        return m_list.QuickSort_s(reinterpret_cast<int (*) (const void *const*, const void *const*)>(iPFCompare));
    }
    
    void FillArray( _Typ ** ioArray , int iMaxSize ) const
    {
        m_list.FillArray(reinterpret_cast<void **>(ioArray), iMaxSize);
    }
    
    int NbOccur( _Typ *iTest )
    {
        return m_list.NbOccur(iTest);
    }
    
    static void Intersection ( const DSYListPtr<_Typ> & iRC1,
                   const DSYListPtr<_Typ> & iRC2,
                   DSYListPtr<_Typ> & ioResult )
    {
        return _DSYListPtr<std::is_base_of<IUnknown, _Typ>::value>::Intersection(iRC1.m_list, iRC2.m_list, ioResult.m_list);
    }
    
private:
    // Members
    _DSYListPtr<std::is_base_of<IUnknown, _Typ>::value> m_list;
};

#endif  // _DSYListPtr_H
