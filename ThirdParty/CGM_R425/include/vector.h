/* COPYRIGHT DASSAULT SYSTEMES 1999 */


#ifndef VECTOR_H
#define VECTOR_H

#include <new.h>
#include <stddef.h>

#if ( defined(_AIX_SOURCE) && (__xlC__ < 0x0500) ) 
typedef int bool;
#elif defined(_SUNOS_SOURCE) && !defined(_BOOL)
typedef int bool;
#endif


template<class T> class vector {

    T* _start;
    T* _finish;
    T* _end_of_storage;

public:

    ///////////////////////////////////////////////////////////////////////////
    // types:

    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;

    ///////////////////////////////////////////////////////////////////////////
    // construct/copy/destroy:

    vector(size_type n = 0)
    {
        if (n > 0) {
            _start = new T[n];
            _finish = _end_of_storage = _start + n;
        } else {
            _finish = _start = new T[1];
            _end_of_storage = _start + 1;
        }
    }

#ifdef _AIX_SOURCE
    vector(const vector<T>& rhs)
#else
    vector(const vector& rhs)
#endif
    {
        size_type n = rhs.size();
        if (n > 0) {
            _start = new T[n];
            _finish = _end_of_storage = _start + n;
            T *i = _start, *j = rhs._start;
            while (i != _finish)
                *i++ = *j++;
        } else {
            _finish = _start = new T[1];
            _end_of_storage = _start + 1;
        }
    }

    ~vector() { delete[] _start; }

#ifdef _AIX_SOURCE
    vector<T>& operator=(const vector<T>& rhs)
#else
    vector& operator=(const vector& rhs)
#endif
    {
        if (&rhs != this) {
            delete[] _start;
            size_type n = rhs.size();
            if (n > 0) {
                _start = new T[n];
                _finish = _end_of_storage = _start + n;
                T *i = _start, *j = rhs._start;
                while (i != _finish)
                    *i++ = *j++;
            } else {
                _finish = _start = new T[1];
                _end_of_storage = _start + 1;
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////////
    // iterators:

    iterator begin() { return _start; }
    const_iterator begin() const { return _start; }

    iterator end() { return _finish; }
    const_iterator end() const { return _finish; }

    ///////////////////////////////////////////////////////////////////////////
    // capacity:

    size_type size() const { return _finish - _start; }

    size_type capacity() const { return _end_of_storage - _start; }

    bool empty() const { return _start == _finish; }

    void reserve(size_type n)
    {
        if (n > capacity()) {
            T* V = new T[n];
            T *i = V, *j = _start;
            while (j != _finish)
                *i++ = *j++;
            delete[] _start;
            _start = V;
            _finish = i;
            _end_of_storage = _start + n;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // element access:

    reference operator[](size_type i) { return *(_start + i); }
    const_reference operator[](size_type i) const { return *(_start + i); }

    reference front() { return *_start; }
    const_reference front() const { return *_start; }

    reference back() { return *(_finish - 1); }
    const_reference back() const { return *(_finish - 1); }

    ///////////////////////////////////////////////////////////////////////////
    // modifiers:

    void push_back(const T& x)
    {
        if (_finish == _end_of_storage)
            reserve(size()*2);

        *_finish++ = x;
    }

    void erase(iterator x)
    {
        --_finish;
        for (; x != _finish; ++x)
            *x = *(x+1);
        _finish->~T();
        new(_finish) T;
    }

    void clear()
    {
        while (_finish != _start) {
            --_finish;
            _finish->~T();
            new(_finish) T;
        }
    }

	iterator insert(iterator pos, const T& x)
	{
		if (pos == end())
		{
			push_back(x);
			return (_finish-1);
		}
		else if (_finish == _end_of_storage)
		{
			// not enough capacity
			size_type n = size()*2;
            T* V = new T[n];
            T *i = V, *j = _start;
			T* ix;
            while (j != pos)
                *i++ = *j++;
			ix = i;
			*i++ = x;
			while (j != _finish)
			{
				*i++ = *j++;
			}
            delete[] _start;
            _start = V;
            _finish = i;
            _end_of_storage = _start + n;
			return ix;
        }
		else
		{
			// there's enough capacity
            T *j = _finish-1;
			T* i = _finish++;
            while (i != pos)
                *i-- = *j--;
			*i = x;
			return pos;
		}
	}

	void swap( vector<T>& _other )
	{
	    T* start_tmp = _start;
		T* finish_tmp = _finish;
		T* end_of_storage_tmp = _end_of_storage;

		_start = _other._start;
		_finish = _other._finish;
		_end_of_storage = _other._end_of_storage;

		_other._start = start_tmp;
		_other._finish = finish_tmp;
		_other._end_of_storage = end_of_storage_tmp;
	}


};


#endif // VECTOR_H
