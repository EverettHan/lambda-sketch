/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2002
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/
#ifndef CATRepWeakRef_h
#define CATRepWeakRef_h

#include "SGInfra.h"
class CATRep;

/**
* Class representing a weak reference on a CATRep.
* The weak reference is obtained by the @href CATRep#GetRepWeakRef method.
*/
class ExportedBySGInfra CATRepWeakRef
{
    // Friend declarations for the use of constructor, destructor and KillRef method.
    friend class CATRep;

public:

    /**
    * Adds a reference to weak reference.
    */
    void AddRef(void);

    /**
    * Removes a reference to weak reference.
    */
    void Release(void);

    /**
    * Returns the rep pointed by the weak reference. The returned pointer is NULL if the rep was destroyed.
    * Lifecycle deviation : Release must not be called on the returned rep.
    * @return
    * A <tt>CATRep *</tt>
    */
    inline CATRep * GiveRep(void)
    {
        return m_component;
    }

    /** @nodoc */
    void SetRep(CATRep * iRep);

protected:

    /**
    * Only used by CATRep::GetRepWeakRef()
    */
    CATRepWeakRef(CATRep * iRep);

    /**
    * Only used by CATRepWeakRef::Release()
    */
    ~CATRepWeakRef(void);

    /**
    * Only used by CATRep::UnreferenceWeakRef()
    */
    void KillRef(void);

protected:

    CATRep * m_component;

private:

    volatile int m_cref;
};
#endif
