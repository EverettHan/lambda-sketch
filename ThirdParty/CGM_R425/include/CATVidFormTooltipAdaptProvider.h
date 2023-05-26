// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATVidFormTooltipAdaptProvider
//
//=============================================================================
// Usage notes: Adapter to define a tooltip on a property.
//
//=============================================================================
// Mar 2011  Creation                                                   T. Pech
//=============================================================================
#ifndef CATVidFormTooltipAdaptProvider_H
#define CATVidFormTooltipAdaptProvider_H

#include "VisuDialogEx.h"
#include "CATISYPIntrospectableProvider.h"
#include "CATString.h"
#include "CATUnicodeString.h"

class CATISYPIntrospectable_var;

//-----------------------------------------------------------------------------
class ExportedByVisuDialogEx CATVidFormTooltipAdaptProvider: public CATISYPIntrospectableProvider
{
  CATDeclareClass;

  public:
    CATVidFormTooltipAdaptProvider ();
    virtual ~CATVidFormTooltipAdaptProvider ();

    // Must Impemented by the User Object.
    virtual CATISYPIntrospectable_var GetIntrospectable() = 0;
    virtual CATISYPIntrospectableProvider_var Clone() = 0;

    virtual const CATString& GetPropertyId( )const;
    virtual void SetPropertyId( const CATString& i_PropertyId );
    virtual const CATUnicodeString& GetClassName( )const;
    virtual void SetClassName( const CATUnicodeString& i_ClassName );

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATVidFormTooltipAdaptProvider (CATVidFormTooltipAdaptProvider &);
    CATVidFormTooltipAdaptProvider& operator=(CATVidFormTooltipAdaptProvider&);

    CATString           _PropId;
    CATUnicodeString    _ClassName;
};
#endif
