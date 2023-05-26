#ifndef _CATALIGNEDALLOCATOR_H_
#define _CATALIGNEDALLOCATOR_H_



//STL allocator like for aligned vector (@see CATAlignedVector)
//use to satisfy GPU memory alignment specs


#if defined(_WINDOWS_SOURCE)

#include <malloc.h>
#elif defined(_LINUX_SOURCE)
#include <stdlib.h>
#include <malloc.h>
#else

#endif




template <typename T, int Alignment>
class CATAlignedAllocator {

    typedef CATAlignedAllocator< T , Alignment > self_t;

public:

    //allocation methods depends on OS
    //debug stuff
    int NbAlignedAllocs;
    int NbAlignedFree;


    CATAlignedAllocator() : NbAlignedAllocs(0), NbAlignedFree(0)
    {}

    template < typename Other >
    CATAlignedAllocator( const CATAlignedAllocator< Other , Alignment > & )  : NbAlignedAllocs(0), NbAlignedFree(0)
    {}




    T* Allocate( int n ) {
        return reinterpret_cast<T*>(AlignedAlloc( sizeof(T) * n , Alignment ));
    }


    void Deallocate( T* ptr ) {
        AlignedFree( reinterpret_cast<void*>( ptr ) );
    }


    void Destroy( T* ptr )
    { ptr->~T(); }




    inline void* AlignedAlloc(size_t size, int alignment)
    {
        NbAlignedAllocs++;
#if defined(_WINDOWS_SOURCE)

        return _aligned_malloc(size, (size_t)alignment);
#elif defined(_LINUX_SOURCE)
        return memalign(alignment, size);
#else
        //alignment not support
        return malloc(size);
#endif
    }



    inline void AlignedFree(void* ptr)
    {
        NbAlignedFree++;
#if defined(_WINDOWS_SOURCE)

        _aligned_free(ptr);
#elif defined(_LINUX_SOURCE)
        free(ptr);
#else
        free(ptr);
#endif
    }


};


#endif
