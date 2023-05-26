#ifndef CATIOContainers_H
#define CATIOContainers_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATIOAtomics.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

template <typename T>
class CATIOFIFO
{
public:
    CATIOFIFO(const int iSize) : _storage(NULL), _cursor(0)
    {
        _storage = new T[iSize];
        _size = iSize;
    }

    virtual ~CATIOFIFO()
    {
        if (_storage) {
            delete _storage;
            _storage = NULL;
        }
        _cursor = -1;
    }

    int Size() { return _cursor; }

    T&    operator[](int iIndex)
    {
        if (iIndex < _cursor) {
            return _storage[iIndex];
        }
        else {
            // irk :( , we should throw :) but...
            return NAT<T>::value();
        }
    }

    HRESULT PushBack(const T& iT)
    {
        if (_cursor < _size) {
            _storage[_cursor] = iT;
            ++_cursor;
        }
        else {
            return E_FAIL;
        }
        return S_OK;
    }

    HRESULT InsertAt(const int iAt, const T& iT)
    {
        HRESULT hr = E_FAIL;

        if (iAt<0 || iAt>_cursor) {
            return E_INVALIDARG;
        }

        if (iAt == _cursor) {
            hr = PushBack(iT);
        }
        else {
            if (_cursor >= _size) {
                return E_FAIL;
            }
            for (int i = _cursor; i > iAt; --i) {
                _storage[i] = _storage[i - 1];
            }
            ++_cursor;
            _storage[iAt] = iT;
            hr = S_OK;
        }
        return hr;
    }

    HRESULT InsertSorted(const T& iT)
    {
        return InsertSortedInRange(iT, 0, _cursor);
    }

    HRESULT InsertSortedInRange(const T& iT, const int iRangeStart, const int iRangeEnd)
    {
        if (_cursor == 0) {
            return PushBack(iT);
        }
        if (iRangeStart < 0 || iRangeStart >= _cursor || iRangeStart > iRangeEnd) {
            return E_INVALIDARG;
        }
        if (iRangeEnd <= 0 || iRangeEnd > _cursor) {
            return E_INVALIDARG;
        }

        int rs = iRangeStart;
        int re = iRangeEnd;
        int mid = floor(0.5f * (re - rs)) + rs;
        while (mid > rs && mid < re) {
            if (Op<T>::Compare((*this)[mid], iT)) {
                rs = mid;
            }
            else {
                re = mid;
            }
        }

        return InsertAt(mid, iT);
    }

    T  PopFront()
    {
        if (Size() > 0) {
            --_cursor;
            T res = _storage[0];
            if (_cursor > 0) {
                for (int i = 0; i < _cursor - 1; ++i) {
                    _storage[i] = _storage[i + 1];
                }
            }
            return res;
        }
        else {
            // irk :( , we should throw :) but...
            return NAT<T>::value();
        }
    }
private:
    T*              _storage;
    volatile int    _cursor;
    volatile int    _size;
};


template <typename T>
class CATIOThreadSafeFIFO
{
public:
    CATIOThreadSafeFIFO(const int iSize) : _stack(iSize)
    {

    }

    virtual ~CATIOThreadSafeFIFO()
    {

    }

    HRESULT PushBack(const T& iT)
    {
        HRESULT hr = E_FAIL;
        {
            CATIOAtomicStackLock stackLock(_lock);
            hr = _stack.PushBack(iT);
        }
        return hr;
    }

    HRESULT TryPop(T& oT)
    {
        HRESULT hr = E_FAIL;
        if (_lock.TryLock() == CATMutexSuccessful) {
            if (_stack.Size() > 0) {
                oT = _stack.PopFront();
                hr = S_OK;
            }
            _lock.Unlock();
        }
        else {
            oT = NAT<T>::value();
            hr = E_FAIL;
        }
        return hr;
    }

private:
    CATIOFIFO<T>    _stack;
    CATIOAtomicLock _lock;
};


template<typename TK, typename TV>
class CATIOThreadSafeHash
{
public:
    CATIOThreadSafeHash()
    {

    }

    virtual ~CATIOThreadSafeHash()
    {

    }

    HRESULT Insert(const TK& iTK, const TV& iTV)
    {
        CATIOAtomicStackLock stackLock(_lock);
        Iter it = _hash.find(iTK);
        if (it != _hash.end()) {
            it->second = iTV;
        }
        else {
            _hash.insert(std::make_pair(iTK, iTV));
        }
        return S_OK;
    }

    HRESULT TryFind(const TK& iTK, TV& oTV)
    {
        HRESULT hr = E_FAIL;
        if (_lock.TryLock() == CATMutexSuccessful) {
            Iter foundIt = _hash.find(iTK);
            if (foundIt != _hash.end()) {
                oTV = foundIt->second;
                hr = S_OK;
            }
            _lock.Unlock();
        }
        else {
            oTV = NAT<TV>::value();
            hr = E_FAIL;
        }
        return hr;
    }

    HRESULT Remove(const TK& iTK)
    {
        CATIOAtomicStackLock stackLock(_lock);
        HRESULT hr = E_FAIL;
        Iter it = _hash.find(iTK);
        if (it != _hash.end()) {
            _hash.erase(it);
            hr =  S_OK;
        }
        return hr;
    }

private:
    typedef typename std::unordered_map<TK, TV>::iterator Iter;
    std::unordered_map<TK, TV>   _hash;
    CATIOAtomicLock     _lock;
};


template <typename T>
class CATIOThreadSafePriorityQueue
{
public:
    CATIOThreadSafePriorityQueue(const int iSize) : _sizeLimit(iSize)
    {
        _priorityQueue.reserve(_sizeLimit);
    }

    virtual ~CATIOThreadSafePriorityQueue()
    {

    }

    HRESULT PushBack(const T& iT, T& oDropped)
    {
        HRESULT hr = E_FAIL;
        _lock.ReadLock();
        if (_priorityQueue.Size() < _sizeLimit) {
            _lock.ReadUnlock();
            _lock.WriteLock();
            hr = _priorityQueue.InsertSorted(iT);
            _lock.WriteUnlock();
        }
        else {
            const T& frontT = _priorityQueue.Front();
            if (Op<T>::Compare(frontT, iT) > 0) {
                _lock.ReadUnlock();
                _lock.WriteLock();
                oDropped = _priorityQueue.front();
                _priorityQueue.erase(_priorityQueue.begin());
                hr = _priorityQueue.InsertSorted(iT);
                _lock.WriteUnlock();
            }
            else {
                _lock.ReadUnlock();
                hr = E_FAIL;
            }
        }
        return hr;
    }

    HRESULT TryPop(T& oT)
    {
        HRESULT hr = E_FAIL;
        _lock.ReadLock();
        if (_priorityQueue.Size() > 0) {
            _lock.ReadUnlock();
            _lock.WriteLock();
            oT = _priorityQueue.pop_back();
            _lock.WriteUnlock();
            hr = S_OK;
        }
        else {
            _lock.ReadUnlock();
            oT = NAT<T>::value();
            hr = E_FAIL;
        }
        return hr;
        //HRESULT hr = E_FAIL;
        //if (_lock.TryLock() == CATMutexSuccessful) {
        //    if (_priorityQueue.Size() > 0) {
        //        oT = _priorityQueue.PopBack();
        //        hr = S_OK;
        //    }
        //    _lock.Unlock();
        //}
        //else {
        //    oT = NAT<T>::value();
        //    hr = E_FAIL;
        //}
        //return hr;
    }

    HRESULT Remove(T& iT)
    {
        CATIOAtomicStackWriteLock stackLock(_lock);
        HRESULT hr = E_FAIL;
        auto it = std::find(_priorityQueue.begin(), _priorityQueue.end(), iT);
        if (it != _priorityQueue.end())
        {
            _priorityQueue.erase(it);
            hr = S_OK;
        }
        return hr;
    }

    HRESULT Sort()
    {
        // TODO very naive sort. Change this.
        CATIOAtomicStackWriteLock stackLock(_lock);

        int sizeInBytes = _priorityQueue.size()*sizeof(T);

        if (sizeInBytes == 0) //To avoid Null size allocations
            return S_OK;

        T* savedContent = (T*)malloc(sizeInBytes);
        if (savedContent == NULL) {
            return E_OUTOFMEMORY;
        }
        int elementCount = _priorityQueue.Size();
        for (int i = elementCount - 1; i >= 0; --i) {
            savedContent[i] = _priorityQueue.pop_back();
        }

        for (int i = 0; i < elementCount; ++i) {
            T oDropped;
            PushBack(savedContent[i], oDropped);
        }

        free(savedContent);

        return S_OK;
    }

    int GetSizeLimit() const
    {
        return _sizeLimit;
    }

    HRESULT SetSizeLimit(const int iSizeLimit)
    {
        _sizeLimit = iSizeLimit;
        return S_OK;
    }

    int Size()
    {
        return _priorityQueue.Size();
    }

private:
    std::vector<T>  _priorityQueue;
    CATIOAtomicReadWriteLock        _lock;
    int                             _sizeLimit;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOContainers_H
