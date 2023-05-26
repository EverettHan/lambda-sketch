// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//=============================================================================
//
// CATVizBaseIUnknown
// 
//=============================================================================
// Usage Notes:
//  Base class for Reps, GPs and BoundingElements
// 
//=============================================================================
// Created :
//	November, 22th 2002 :	JQT
//=============================================================================

#ifndef CATVizBaseIUnknown_H
#define CATVizBaseIUnknown_H

#include "SGInfra.h"
#include "IUnknown.h"
#include "CATMacForRtti.h"

/**
 * Base Class for Visualization objects.
 */
class ExportedBySGInfra CATVizBaseIUnknown : public IUnknown
{
  CATDeclareClass_Deprec;

  public:  

    /** @nodoc */
    CATVizBaseIUnknown();
    /** @nodoc */
    CATVizBaseIUnknown(const CATVizBaseIUnknown&);
    /** @nodoc */
    CATVizBaseIUnknown& operator=(const CATVizBaseIUnknown&);

    /** @nodoc */
    virtual ~CATVizBaseIUnknown();

    /** @nodoc */
    virtual HRESULT __stdcall QueryInterface(const IID &iIID, void** oPPV);
    /** @nodoc */
    virtual ULONG __stdcall AddRef();
    /** @nodoc */
    virtual ULONG __stdcall Release() ;

    /** @nodoc */
    virtual int IsNull() const;

  protected:
    unsigned long m_cRef;
};

#endif
