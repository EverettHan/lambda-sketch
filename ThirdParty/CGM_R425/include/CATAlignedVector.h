#ifndef _CATALIGNEDVECTOR_H_
#define _CATALIGNEDVECTOR_H_


#include "CATAlignedAllocator.h"

#include <new>

// as there is no .cpp exportedby doesnt work
// must explicit the declspec since can't impl .cpp with a template

//STL like vector
//use to satisfy GPU memory alignment specs

//defaault 16 bytes aligned
template< typename T, int Alignment >
class CATAlignedVector {

public :	


	CATAlignedVector() : _Data(0), _Size(0), _Capacity(0), _LastMaxAllocatedSize(0) {}
	~CATAlignedVector() { Clear(); }
	CATAlignedVector(const CATAlignedVector& other) {}




//private :

	CATAlignedAllocator<T, Alignment> _Allocator;
	int _Size;
	int _Capacity;
	T* _Data;
    int _LastMaxAllocatedSize;

	inline void Init()
	{
		_Data = 0;
		_Size = 0;
		_Capacity = 0;
        _LastMaxAllocatedSize = 0;
	}

	inline void Destroy(int begin, int end)
	{
		for(int i = begin; i < end; i++)
			_Data[i].~T();
	}

    inline void* Allocate(int size)
    {
        if(size)
        {
            if(_LastMaxAllocatedSize < size)
                _LastMaxAllocatedSize = size;
            return _Allocator.Allocate(size);
        }
        return 0;
    }

	inline void Deallocate()
	{
		if(_Data) {
			_Allocator.Deallocate(_Data);
			_Data = 0;
		}
	}

	inline void Copy(int begin, int end, T* dst)
	{
		for(int i = begin; i < end; i++)
		{
			new (&dst[i]) T(_Data[i]);
            //dst[i] = _Data[i];
		}
	}


public :

	inline int Size()
	{
		return _Size;
	}

	inline const T& operator[](int i) const
	{
		return _Data[i];
	}

	inline T& operator[](int i)
	{
		return _Data[i];
	}

    inline void Reset()
    {
      _Size = 0;
    }

    inline void Reset(const int& val)
    {
        memset(_Data, val, _Size*sizeof(T));
        _Size = 0;
    }

	inline void Clear()
	{
		Destroy(0, _LastMaxAllocatedSize);
      Deallocate();
      Init();
    }

	inline void Resize(int newSize, const T& data = T())
	{
		if(newSize < _Size)
		{
			for(int i = newSize; i < _Size; i++)
				_Data.~T();

		}
		else
		{
			if(newSize > _Size)
			{
				Reserve(newSize);
			}

			for(int i = _Size; i < newSize; i++)
			{
				new (&_Data[i]) T(data);
			}
		}

		_Size = newSize;
		
	}

    inline void Insert(int position, const T& t)
    {
            if(_Size == _Capacity)
            {
                //growup 50%
                Reserve( (_Size)? _Size * 2:1 );
            }

            new ( &_Data[position] ) T(t);
            //_Data[_Size] = t;

            _Size++;        
    }

    inline void RandomInsert(int position, const T& t)
    {
            if(_Size == _Capacity || position > _Capacity)
            {
                //growup 50%
                Reserve( (_Size)? _Size * 2:1 );
            }

            new ( &_Data[position] ) T(t);
            //_Data[_Size] = t;

            if(position >= _Size)
                _Size = position+1;
    }

	inline int PushBack(const T& t)
	{
		if(_Size == _Capacity)
		{
			//growup 50%
			Reserve( (_Size)? _Size * 2:1 );
		}

		new ( &_Data[_Size] ) T(t);
        //_Data[_Size] = t;

		_Size++;

        return _Size-1;
	}

	inline void PushBackArray(T* t, int size)
	{
		if(_Size + size >= _Capacity)
		{
			Reserve( _Size + size );
		}

		for(int i = 0; i < size; i++ )
		{
			new ( &_Data[_Size] ) T(t[i]);
            //_Data[_Size] = t[i];
			_Size++;
		}


	}

	inline void PopBack()
	{
		_Size--;
		_Data[_Size].~T();		
	}

	inline void Reserve(int nb)
	{
		if(_Capacity < nb)
		{
			T* t = (T*) Allocate(nb);
			Copy(0, _Size, t);
			Destroy(0, _Size);
			Deallocate();
			_Data = t;
			_Capacity = nb;
		}
	}

    inline void InitFill(int value, int size)
    {
        if(size <= 0)
            return;

        if(size > _Capacity)
        {
            Reserve(size);
        }

        _Size = size;
        memset(_Data, value, _Size*sizeof(T));        
    }




};



//specialized template for type pointer
//not usefull for aligned data recquirement for GPU

template< typename T, int Alignment >
class CATAlignedVector<T*, Alignment> {

public :	


	CATAlignedVector() : _Data(0), _Size(0), _Capacity(0), _LastMaxAllocatedSize(0) {}
	~CATAlignedVector() { Clear(); }
	CATAlignedVector(const CATAlignedVector& other) {}


	CATAlignedAllocator<T, Alignment> _Allocator;
	int _Size;
	int _Capacity;
	T** _Data;
    int _LastMaxAllocatedSize;

	inline void Init()
	{
		_Data = 0;
		_Size = 0;
		_Capacity = 0;
        _LastMaxAllocatedSize = 0;
	}

	inline void Destroy(int begin, int end)
	{
		for(int i = begin; i < end; i++)
			_Data[i]->~T();
	}

	inline void* Allocate(int size)
	{
		if(size)
        {
            if(_LastMaxAllocatedSize < size)
                _LastMaxAllocatedSize = size;
			return _Allocator.Allocate(size);
        }
		return 0;
	}

	inline void Deallocate()
	{
		if(_Data) {
            for(int i = 0; i < _Size; i++ )
			    _Allocator.Deallocate(_Data[i]);
			_Data = 0;
		}
	}

	inline void Copy(int begin, int end, T** dst)
	{
		for(int i = begin; i < end; i++)
		{
			//new (&dst[i]) T(_Data[i]);
            dst[i] = _Data[i];
		}
	}


public :

	inline int Size()
	{
		return _Size;
	}

	inline const T* operator[](int i) const
	{
		return _Data[i];
	}

	inline T* operator[](int i)
	{
		return _Data[i];
	}

    inline void Reset()
    {
        _Size = 0;
    }

    inline void Reset(const int& val)
    {
        memset(_Data, val, _Size*sizeof(T));
        _Size = 0;
    }

	inline void Clear()
	{
		Destroy(0, _LastMaxAllocatedSize);
		Deallocate();
		Init();
	}

	inline void Resize(int newSize, const T& data = T())
	{
		if(newSize < _Size)
		{
			for(int i = newSize; i < _Size; i++)
				_Data->~T();

		}
		else
		{
			if(newSize > _Size)
			{
				Reserve(newSize);
			}

			//for(int i = _Size; i < newSize; i++)
			//{
			//	new (&_Data[i]) T(data);
			//}
		}

		_Size = newSize;
		
	}


    inline void Insert(int position, T* t)
    {
            if(_Size == _Capacity)
            {
                //growup 50%
                Reserve( (_Size)? _Size * 2:1 );
            }

            _Data[position] = t;

            _Size++;        
    }

    inline void RandomInsert(int position, T* t)
    {
            if(_Size == _Capacity || position > _Capacity)
            {
                //growup 50%
                Reserve( (_Size)? _Size * 2:1 );
            }

            //new ( &_Data[position] ) T(t);
            _Data[position] = t;

            if(position > _Size)
                _Size = position+1;
    }

	inline int PushBack(T* t)
	{
		if(_Size == _Capacity)
		{
			//growup 50%
			Reserve( (_Size)? _Size * 2:1 );
		}

		//new ( &_Data[_Size] ) T(t);
        _Data[_Size] = t;

		_Size++;

        return _Size-1;
	}

	inline void PushBackArray(T* t, int size)
	{
		if(_Size + size >= _Capacity)
		{
			Reserve( _Size + size );
		}

		for(int i = 0; i < size; i++ )
		{
			//new ( _Data[_Size] ) T(t[i]);
            _Data[_Size] = t[i];
			_Size++;
		}


	}

	inline void PopBack()
	{
		_Size--;
		_Data[_Size]->~T();		
	}

	inline void Reserve(int nb)
	{
		if(_Capacity < nb)
		{
			T** t = (T**) Allocate(nb);
			Copy(0, _Size, t);
			//Destroy(0, _Size);
			Deallocate();
			_Data = t;
			_Capacity = nb;
		}
	}




};


#endif
