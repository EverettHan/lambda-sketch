#ifndef CATItfPtrList_H
#define CATItfPtrList_H

#include "SGComposites.h"

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include <algorithm>

template<class T>
class CATIODBufferedArray
{
public:
    typedef typename std::vector<T>::iterator Iterator;
    typedef typename std::vector<T>::const_iterator ConstIterator;

    typedef T type;

    CATIODBufferedArray() {
        _views[0] = &_vector0;
        _views[1] = &_vector1;
        _switch = 0;
    }

    virtual ~CATIODBufferedArray(){}

    HRESULT PushBack(T& iPtr) {
        CATIOAtomicStackLock writeLock(_writeLock);
        _writeView().push_back(iPtr);
        return S_OK;
    }
    HRESULT Remove(T& iPtr) {
        CATIOAtomicStackLock writeLock(_writeLock);
        auto it = std::find(_writeView().begin(), _writeView().end(), iPtr);
        if (it != _writeView().end())
            _writeView().erase(it);
            return S_OK;
        return E_FAIL;
    }

    int SizeInBytes()
    {
        return static_cast<int>(sizeof(T)*(_vector0.size() + _vector1.size()));
    }

    Iterator Begin() { return _readView().begin(); }
    Iterator End() { return _readView().end(); }
    ConstIterator CBegin() const { return _creadView().cbegin(); }
    ConstIterator CEnd() const { return _creadView().cend(); }

    Iterator Find(const T& iT)
    {
        return std::find(Begin(), End(), iT);
    }

    ConstIterator Find(const T& iT) const {
        return std::find(CBegin(), CEnd(), iT);
    }

    HRESULT Switch()
    {
        CATIOAtomicStackLock writeLock(_writeLock);
        HRESULT hr = E_FAIL;
        int currentSwitch = _switch;
        int switchWas = CATIOAtomicCmpExch(&_switch, (currentSwitch == 0 ? 1 : 0), currentSwitch);
        if(switchWas==currentSwitch)
        {
            _writeView() = _creadView();
            hr = S_OK;
        }
        return hr;
    }

    HRESULT Swap(int i, int j)
    {
        CATIOAtomicStackLock writeLock(_writeLock);
        std::iter_swap(_writeView().begin()+i, _writeView().begin()+j);
        return S_OK;
    }

    HRESULT InsertAt(const int iIndex, T& iT) {
        CATIOAtomicStackLock writeLock(_writeLock);
        // fill with dummies if needed !
        for(int i=static_cast<int>(_writeView().size()); i<=iIndex; ++i) {
            _writeView().push_back(NAT<T>::value());
        }
        _writeView().push_back(iT);
        if(iIndex!=_writeView().size()-1) {
            Swap(iIndex, static_cast<int>(_writeView().size()-1));
            if(_writeView()[_writeView().size()-1]==NAT<T>::value()) {
                _writeView().pop_back();
            }
        }
        return S_OK;
    }
protected:

    std::vector<T>&          _readView() { return *_views[_switch]; }
    const std::vector<T>&    _creadView() const  { return *_views[_switch]; }
    std::vector<T>&          _writeView() { return *_views[(_switch == 0 ? 1 :0)]; }
    CATIOAtomicLock          _writeLock;

private:
    std::vector<T>   _vector0;
    std::vector<T>   _vector1;
    std::vector<T>*  _views[2];
    ALIGNED_INT volatile int    _switch;//in {0,1} : init to 0 in cstr and manipulated with (currentSwitch == 0 ? 1 : 0)
};

/**
 * Same remark as for CATItfPtr don't use this directly. Use the typedef explicit instantiation of this
 * template class.
 */
template<class T>
class ExportedBySGComposites CATCompositePtrList : public CATIODBufferedArray<T>
{
public:
    CATCompositePtrList() {}
    virtual ~CATCompositePtrList() {}

    HRESULT TraverseAll(CATSGTraverse<T>& iTraverse)
    {
        bool keepRolling = true;
        for (typename CATIODBufferedArray<T>::Iterator it = this->Begin(); keepRolling && (it != this->End()); ++it)
        {
            if ((*it).IsValid())
                keepRolling = iTraverse(*it);
        }
        return S_OK;
    }

    HRESULT TraverseAll(CATSGConstTraverse<T>& iTraverse) const
    {
        bool keepRolling = true;
        for (typename CATIODBufferedArray<T>::ConstIterator cit = this->CBegin(); keepRolling && (cit != this->CEnd()); ++cit)
        {
            if ((*cit).IsValid())
                keepRolling = iTraverse(*cit);
        }
        return S_OK;
    }

    bool SameContent(const CATCompositePtrList<T>& iOther) const
    {
        return std::equal(this->CBegin(), this->CEnd(), iOther.CBegin());
    }

    HRESULT Copy(const CATCompositePtrList& iOther)
    {
        CATIOAtomicStackLock writeLock(CATIODBufferedArray<T>::_writeLock);
        this->_writeView() = iOther._creadView();
        return S_OK;
    }
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATItfPtrList_H
