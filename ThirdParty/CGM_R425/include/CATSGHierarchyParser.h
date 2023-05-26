#ifndef CATSGHierarchyParser_H
#define CATSGHierarchyParser_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES
#ifdef __EMSCRIPTEN__

template <typename Processor, typename TraitToBeProcessed, typename TResult>
class CATSGHierarchyParser
{
public:
    typedef std::vector<TResult> Results;

    CATSGHierarchyParser(Processor& iProcessor) : _processor(iProcessor)
    {

    }

    virtual ~CATSGHierarchyParser()
    {

    }

    HRESULT Run(CATSGCompositeRing& iRing)
    {
        HRESULT hr = E_FAIL;

        hr = _processor.PreProcess(iRing);
        if(FAILED(hr)) {
            return hr;
        }

        CATOnStackBorrowPtr<TraitToBeProcessed> borrow;
        hr = iRing.BorrowViewFromTag(CATTraitInfo<TraitToBeProcessed>::GetTraitTag(), borrow);
        if(SUCCEEDED(hr) && borrow.IsValid()) {
            TResult result;
            hr = _processor(borrow, result);

            if(SUCCEEDED(hr)) {
                hr = _results.PushBack(result);
            }
            if(hr!=S_OK) {
                return hr;
            }
        }

        CATCompHierarchyBorrowPtr hierarchy;
        iRing.BorrowViewFromTag(CATTraitInfo<CATCompHierarchy>::GetTraitTag(), hierarchy);
        if(hierarchy.IsValid()) {
            CATSGCompositeRings& children = hierarchy->GetChildren();

            CATSGCompositeRings::Iterator endIt = children.End();
            for(CATSGCompositeRings::Iterator it = children.Begin(); (hr == S_OK) && (it!= endIt); ++it)
            {
                if(it->IsValid())
                {
                    hr = this->Run(**it);
                }
            }

        }

        hr = _processor.PostProcess(iRing);
        return hr;
    }

    const Results CGetResults() const
    {
        return _results;
    }

protected:
    Processor&      _processor;
    Results         _results;
};

#endif // __EMSCRIPTEN__
#endif // SG_COMPOSITES

#endif // CATSGHierarchyParser_H

