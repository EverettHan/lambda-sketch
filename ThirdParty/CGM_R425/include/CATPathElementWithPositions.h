#ifndef CATPathElementWithPositions_h_
#define CATPathElementWithPositions_h_

#include "SceneGraphManager.h"

#include "CATBaseUnknown.h"
#include "CATPathElement.h"

#include <vector>

class ExportedBySceneGraphManager CATPathElementWithPositions : public CATPathElement
{
    /** @nodoc */
    CATDeclareClass;

public:
    CATPathElementWithPositions(const CATBaseUnknown* iObject = nullptr);
    CATPathElementWithPositions(const CATPathElementWithPositions& iOther);
    CATPathElementWithPositions(const CATPathElement& iOther);
    CATPathElementWithPositions& operator=(const CATPathElementWithPositions& iOther);
    CATPathElementWithPositions& operator=(const CATPathElement& iOther);

    virtual ~CATPathElementWithPositions();

    /** Caller needs to call Release on the returned CATPathElement when he is done with it. */
    virtual CATPathElement* Clone() const;

    virtual CATPathElementWithPositions* SafeCastToPathElementWithPositions();
    virtual const CATPathElementWithPositions* SafeCastToPathElementWithPositions() const;

    /** Returns 1 if equal. Returns 0 if different. */
    virtual int operator==(const CATPathElement& iOther) const;
    /** Returns 1 if equal. Returns 0 if different. */
    virtual int CompareStrong(const CATPathElementWithPositions& iOther) const;
    /** Returns 1 if equal. Returns 0 if different. */
    virtual int CompareWeak(const CATPathElement& iOther) const;

    /** No need to call Release. */
    virtual HRESULT GetPositioningPath(const CATBaseUnknown* iObject, CATPathElement*& oPositioningPath) const;
    virtual HRESULT SetPositioningPath(const CATBaseUnknown* iObject, CATPathElement* iNewPositioningPath);
    virtual HRESULT RemovePositioningPath(const CATBaseUnknown* iObject, CATPathElement* iPositioningPathToRemove = nullptr);

    virtual void AddFatherElement(const CATBaseUnknown* iObject, const CATBaseUnknown* iChildObject = nullptr);
    virtual void AddChildElement(const CATBaseUnknown* iObject, const CATBaseUnknown* iFatherObject = nullptr);
    virtual void RemoveElement(const CATBaseUnknown* iObject);

private:
    HRESULT _SetPositioningPaths(const std::vector<CATPathElement*>& iPositioningPaths);
    /** Assigns a new value to a path in the vector. Handles AddRef/Release automatically. */
    inline HRESULT _SetPositioningPathAt(int i, CATPathElement* iNewPositioningPath);
    /** Inserts a path into the vector. Only works if (_PositioningPaths.size() == _ref.length() - 1). */
    HRESULT InsertPositioningPath(const CATBaseUnknown* iObject, CATPathElement* iNewPositioningPath);
    /** Removes a path from the vector. Only works if (_PositioningPaths.size() == _ref.length() + 1). */
    HRESULT ErasePositioningPath(const CATBaseUnknown* iObject);
    /** Returns 1 if equal. Returns 0 if different. */
    int _ComparePositioningPaths(const std::vector<CATPathElement*>& iOtherPositioningPaths) const;

private:
    std::vector<CATPathElement*> _PositioningPaths;
};

#endif // !CATPathElementWithPositions_h_
