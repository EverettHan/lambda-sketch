#ifndef CATSGLinkedList_h_
#define CATSGLinkedList_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
//#include "CATVisFoundation.h"

typedef enum {
    CATELinkedListLoop_No = 0,
    CATELinkedListLoop_Yes = 1
} CATELinkedListLoop;

template<typename ElementType>
class CATSGLinkedList;

template<typename ValueType, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy>
class CATSGLinkedListElement
{
    typedef CATSGLinkedListElement<ValueType, LifeCyclePolicy> ElementType;
    typedef CATSGLinkedList<ElementType> ListType;
public:
    CATSGLinkedListElement()
        : _value(NAT<ValueType>::value())
        , _next(NULL)
    {
    }
    CATSGLinkedListElement(const ValueType& iRing)
        : _next(NULL)
    {
        LifeCyclePolicy<ValueType>::Attach(iRing, &_value);
        _value = iRing;
    }
    CATSGLinkedListElement(const ElementType& iOther)
        : _next(NULL)
    {
        LifeCyclePolicy<ValueType>::Attach(iOther._value, &_value);
        _value = iOther._value;
    }
    ElementType& operator=(const ElementType& iOther)
    {
        LifeCyclePolicy<ValueType>::Detach(_value, &_value);
        _value = NAT<ValueType>::value();
        LifeCyclePolicy<ValueType>::Attach(iOther._value, &_value);
        _value = iOther._value;
        return *this;
    }
    ~CATSGLinkedListElement()
    {
        LifeCyclePolicy<ValueType>::Detach(_value, &_value);
        _value = NAT<ValueType>::value();
        _next = NULL; // <- the list is responsible for deletion
    }
    ValueType& GetValue()
    {
        return _value;
    }
    const ValueType& GetValue() const
    {
        return _value;
    }
    HRESULT GetNext(ListType*& oNextList)
    {
        oNextList = _next;
        return S_OK;
    }
    HRESULT GetNext(const ListType*& oNextList) const
    {
        oNextList = _next;
        return S_OK;
    }
    HRESULT SetNext(ListType* iNextList)
    {
        _next = iNextList;
        return S_OK;
    }
private:
    ValueType   _value;
    ListType*   _next;
};

/**
 * ValueType must have the following interface:
 *
 * class ValueType
 * {
 * public:
 *     HRESULT GetNext(CATSGLinkedList<ElementType>*& oNext);
 *     HRESULT SetNext(CATSGLinkedList<ElementType>*& iNext);
 * };
 */
template<typename ValueType, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy>
class CATSGLinkedListElementLight
{
    typedef CATSGLinkedListElementLight<ValueType, LifeCyclePolicy> ElementType;
    typedef CATSGLinkedList<ElementType> ListType;
public:
    CATSGLinkedListElementLight()
        : _value(NAT<ValueType>::value())
    {
    }
    CATSGLinkedListElementLight(const ValueType& iRing)
    {
        LifeCyclePolicy<ValueType>::Attach(iRing, &_value);
        _value = iRing;
    }
    CATSGLinkedListElementLight(const ElementType& iOther)
    {
        LifeCyclePolicy<ValueType>::Attach(iOther._value, &_value);
        _value = iOther._value;
    }
    ElementType& operator=(const ElementType& iOther)
    {
        LifeCyclePolicy<ValueType>::Detach(_value, &_value);
        _value = NAT<ValueType>::value();
        LifeCyclePolicy<ValueType>::Attach(iOther._value, &_value);
        _value = iOther._value;
        return *this;
    }
    ~CATSGLinkedListElementLight()
    {
        LifeCyclePolicy<ValueType>::Detach(_value, &_value);
        _value = NAT<ValueType>::value();
    }
    ValueType& GetValue()
    {
        return _value;
    }
    const ValueType& GetValue() const
    {
        return _value;
    }
    HRESULT GetNext(ListType*& oNextList)
    {
        if (_value != NULL)
            return _value->GetNext(oNextList);
        return E_INVALIDSTATE;
    }
    HRESULT GetNext(const ListType*& oNextList) const
    {
        if (_value != NULL)
            return _value->GetNext(oNextList);
        return E_INVALIDSTATE;
    }
    HRESULT SetNext(ListType* iNextList)
    {
        if (_value != NULL)
            return _value->SetNext(iNextList);
        return E_INVALIDSTATE;
    }
private:
    ValueType   _value;
};

template<typename ElementType>
class CATSGLinkedList
{
public:
    typedef CATSGLinkedList<ElementType> ListType;

    class ConstIterator
    {
    public:
        ConstIterator()
            : _ref(NULL)
            , _cursor(NULL)
        {
        }
        ConstIterator(const ListType* iRef, const ListType* iCursor)
            : _ref(iRef)
            , _cursor(iCursor)
        {
            if ((iCursor != NULL) && !iCursor->IsValid()) {
                _cursor = NULL;
            }
        }
        ConstIterator(const ConstIterator& iOther)
            : _ref(iOther._ref)
            , _cursor(iOther._cursor)
        {
        }
        ConstIterator& operator=(const ConstIterator& iOther)
        {
            _ref = iOther._ref;
            _cursor = iOther._cursor;
            return *this;
        }
        ~ConstIterator()
        {
            _ref = NULL;
            _cursor = NULL;
        }

        ConstIterator& operator++()
        {
            if (_cursor != NULL)
            {
                const ListType* next = NULL;
                if (SUCCEEDED(_cursor->GetNext(next)) && (next == _ref))
                {
                    _cursor = NULL;
                }
                else
                {
                    _cursor = next;
                }
            }
            return *this;
        }
        bool operator==(const ConstIterator& iOther) const
        {
            return ((iOther._ref == _ref) && (iOther._cursor == _cursor));
        }
        bool operator!=(const ConstIterator& iOther) const
        {
            return !(operator==(iOther));
        }
        const ElementType& operator*() const
        {
            if (_cursor != NULL)
            {
                return _cursor->GetElement();
            }
            return ListType::_nullValue;
        }
        const ElementType* operator->() const
        {
            if (_cursor != NULL)
            {
                return &(_cursor->GetElement());
            }
            return NULL;
        }
        operator bool() const
        {
            return (_cursor != NULL);
        }
        static ConstIterator NaTValue()
        {
            return ConstIterator();
        }

    private:
        const ListType*     _ref;
        const ListType*     _cursor;
    };

    class Iterator
    {
    public:
        Iterator()
            : _ref(NULL)
            , _cursor(NULL)
        {
        }
        Iterator(ListType* iRef, ListType* iCursor)
            : _ref(iRef)
            , _cursor(iCursor)
        {
            if ((iCursor != NULL) && !iCursor->IsValid()) {
                _cursor = NULL;
            }
        }
        Iterator(const Iterator& iOther)
            : _ref(iOther._ref)
            , _cursor(iOther._cursor)
        {
        }
        Iterator& operator=(const Iterator& iOther)
        {
            _ref = iOther._ref;
            _cursor = iOther._cursor;
            return *this;
        }
        ~Iterator()
        {
            _ref = NULL;
            _cursor = NULL;
        }

        Iterator& operator++()
        {
            if (_cursor != NULL)
            {
                ListType* next = NULL;
                if (SUCCEEDED(_cursor->GetNext(next)) && (next == _ref))
                {
                    _cursor = NULL;
                }
                else
                {
                    _cursor = next;
                }
            }
            return *this;
        }
        bool operator==(const Iterator& iOther) const
        {
            return ((iOther._ref == _ref) && (iOther._cursor == _cursor));
        }
        bool operator!=(const Iterator& iOther) const
        {
            return !(operator==(iOther));
        }
        ElementType& operator*() const
        {
            if (_cursor != NULL)
            {
                return _cursor->GetElement();
            }
            return ListType::_nullValue;
        }
        ElementType* operator->() const
        {
            if (_cursor != NULL)
            {
                return &(_cursor->GetElement());
            }
            return NULL;
        }
        operator bool() const
        {
            return (_cursor != NULL);
        }
        static Iterator NaTValue()
        {
            return Iterator();
        }

    private:
        ListType*   _ref;
        ListType*   _cursor;
    };

    CATSGLinkedList()
        : _element()
    {
        _nullValue = NAT<ElementType>::value();
        _element = _nullValue;
    }
    CATSGLinkedList(ElementType iT, CATELinkedListLoop iLoop = CATELinkedListLoop_No)
        : _element()
    {
        _nullValue = NAT<ElementType>::value();
        _element = _nullValue;
        PushBack(iT, iLoop);
    }

    ~CATSGLinkedList()
    {
        Clear();
    }
    HRESULT Clear()
    {
        HRESULT hr = S_OK;
        ListType* next = NULL;
        while (SUCCEEDED(GetNext(next)) && (next != NULL) && (next != this))
        {
            PopBack();
        }
        if (IsValid())
        {
            hr = SetNext(NULL);
            _element = _nullValue;
        }
        return hr;
    }

    bool IsValid() const
    {
        return (!Op<ElementType>::Equal(_element, _nullValue));
    }

    const int Size() const
    {
        int result = 0;
        ConstIterator it = CBegin();
        const ConstIterator endIt = CEnd();
        for (; it != endIt; ++it)
        {
            ++result;
        }
        return result;
    }

    const int SizeInBytes() const
    {
        int result = 0;
        ConstIterator it = CBegin();
        const ConstIterator endIt = CEnd();
        for (; it != endIt; ++it)
        {
            result += sizeof(ListType);
        }
        if (result == 0)
        {
            result += sizeof(ListType);
        }
        return result;
    }

    Iterator Begin()
    {
        return Iterator(this, this);
    }

    Iterator End()
    {
        return Iterator(this, NULL);
    }

    ConstIterator CBegin() const
    {
        return ConstIterator(this, this);
    }

    ConstIterator CEnd() const
    {
        return ConstIterator(this, NULL);
    }

    HRESULT GetNext(ListType*& oNext)
    {
        return _element.GetNext(oNext);
    }
    HRESULT GetNext(const ListType*& oNext) const
    {
        return _element.GetNext(oNext);
    }
    HRESULT SetNext(ListType* iNext)
    {
        return _element.SetNext(iNext);
    }
    ElementType& GetElement()
    {
        return _element;
    }
    const ElementType& GetElement() const
    {
        return _element;
    }
    /** Warning: This method might iterate on the whole list (use only when necessary). */
    HRESULT GetLast(ListType*& oLast)
    {
        ListType* last = this;
        ListType* next = this;
        while ((last != NULL) && SUCCEEDED(last->GetNext(next)) && (next != NULL) && (next != this))
        {
            if (last == next)
            {
                break;
            }
            last = next;
        }
        oLast = last;
        return S_OK;
    }
    /** Warning: This method might iterate on the whole list (use only when necessary). */
    HRESULT GetPrev(ListType*& oPrev)
    {
        ListType* last = this;
        ListType* next = this;
        while ((last != NULL) && SUCCEEDED(last->GetNext(next)) && (next != NULL) && (next != this))
        {
            if (last == next)
            {
                break;
            }
            last = next;
        }
        if (next == this)
        {
            oPrev = last;
            return S_OK;
        }
        return E_FAIL;
    }

    HRESULT PushBack(const ElementType& iT, CATELinkedListLoop iLoop = CATELinkedListLoop_No)
    {
        HRESULT hr = E_FAIL;
        const ListType* next = NULL;
        ListType* newElem = NULL;
        ListType* last = this;
        if (SUCCEEDED(iT.GetNext(next)) && (next != NULL))
        {
            // We can't allow 2 lists to share elements because _next might not be in the Element lass
            return E_INVALIDARG;
        }
        if (FAILED(GetLast(last)) || (last == NULL))
        {
            return E_FAIL;
        }
        if (!last->IsValid())
        {
            newElem = last;
            _element = iT;
            hr = S_OK;
        }
        else
        {
            if (SUCCEEDED(last->GetNext(next)) && (next == this)) // if there is a loop, conserve it
            {
                iLoop = CATELinkedListLoop_Yes;
            }
            newElem = new ListType(iT);
            if (newElem != NULL)
            {
                hr = last->SetNext(newElem);
            }
        }
        if (SUCCEEDED(hr) && (iLoop == CATELinkedListLoop_Yes))
        {
            hr = newElem->SetNext(this);
        }
        return hr;
    }

    ElementType PopBack()
    {
        HRESULT hr = E_FAIL;
        ListType* prev = NULL;
        ListType* current = this;
        ListType* next = NULL;
        while (SUCCEEDED(current->GetNext(next)) && (next != NULL) && (next != this))
        {
            prev = current;
            current = next;
        }
        ElementType result = current->_element;
        hr = result.SetNext(NULL);
        current->_element = _nullValue;
        if (SUCCEEDED(hr) && (prev != NULL))
        {
            hr = prev->SetNext(next);
            delete current;
        }
        return result;
    }

    /**
     * WARNING: If 'iT' is the first element of the list, you are responsible for
     * catching the next element before calling this method (risk of memory leak) !
     */
    HRESULT Remove(const ElementType& iT)
    {
        HRESULT hr = E_FAIL;
        ListType* prev = NULL;
        ListType* current = this;
        ListType* next = NULL;
        while (SUCCEEDED(current->GetNext(next)) && (next != NULL) && (next != this))
        {
            if (Op<ElementType>::Equal(current->GetElement(), iT))
            {
                if (prev == NULL)
                {
                    hr = current->GetPrev(prev);
                }
                break;
            }
            prev = current;
            current = next;
        }
        if (!Op<ElementType>::Equal(current->GetElement(), iT)) // not found
        {
            return E_FAIL;
        }
        ElementType result = current->_element;
        hr = result.SetNext(NULL);
        current->_element = _nullValue;
        if (SUCCEEDED(hr) && (prev != NULL))
        {
            hr = prev->SetNext(next);
            delete current;
        }
        return hr;
    }

    Iterator Find(const ElementType& iT)
    {
        Iterator it = Begin();
        const Iterator endIt = End();
        for (; ((it != endIt) && !Op<ElementType>::Equal(*it, iT)); ++it)
        {
        }
        return it;
    }

    ConstIterator CFind(const ElementType& iT) const
    {
        ConstIterator it = CBegin();
        const ConstIterator endIt = CEnd();
        for (; ((it != endIt) && !Op<ElementType>::Equal(*it, iT)); ++it)
        {
        }
        return it;
    }

    bool IsHere(const ElementType& iT) const
    {
        return (CFind(iT) != CEnd());
    }

    bool SameContent(const ListType& iOther) const
    {
        return Op<ElementType>::Equal(_element, iOther.GetElement());
    }

private:
    CATSGLinkedList(const ListType&);
    ListType& operator=(const ListType&);
    bool operator==(const ListType&);
    bool operator!=(const ListType&);

private:
    ElementType         _element;
    static ElementType  _nullValue;
};

template<typename ElementType>
ElementType CATSGLinkedList<ElementType>::_nullValue;

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGLinkedList_h_
