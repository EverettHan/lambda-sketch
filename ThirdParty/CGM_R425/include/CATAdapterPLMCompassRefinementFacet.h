// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATAdapterPLMCompassRefinementFacet.h
// Provides adapter to interface
//    CATIPLMCompassRefinementFacet (BOA)
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Mar 2011  Creation: olc
//===================================================================
#ifndef CATAdapterPLMCompassRefinementFacet_H
#define CATAdapterPLMCompassRefinementFacet_H

#include "UIModelInterfaces.h"

#include "CATIPLMCompassRefinementFacet.h"

#include "CATSysBoolean.h"
#include "CATString.h"
#include "CATUnicodeString.h"

/**
 *
 */
class ExportedByUIModelInterfaces CATAdapterPLMCompassRefinementFacet : public CATIPLMCompassRefinementFacet
{
  public:

    // Standard constructors and destructors for an implementation class
    // -----------------------------------------------------------------
    CATAdapterPLMCompassRefinementFacet();
    virtual ~CATAdapterPLMCompassRefinementFacet();

    virtual HRESULT GetFacetUniqueID(CATString &oFacetID);
    virtual HRESULT GetFacetAlias(CATUnicodeString &oFacetAlias);
    virtual HRESULT GetFacetTooltip(CATUnicodeString &oFacetTooltip);

    virtual HRESULT GetFacetGroup(CATSetOfCATUnicodeString &oFacetGroup);

    /**
     * Compass quadrant associated to the facet
     */
    virtual HRESULT GetQuadrant(CompassQuadrant &oQuadrant);

    /**
     * Get the W associated to this facet
     */
    virtual HRESULT GetAssociatedW(RefinementW &oRefinementW);

    /**
     * Mode of the facet
     * Free value
     * one dimension value
     * One value in a list
     */
    virtual HRESULT GetFacetMode(FacetModes &oFacetMode);

    virtual HRESULT GetRefinementProperties(CATListPtrCATBaseUnknown &oListProperty);
    virtual HRESULT GetRefinementProperties(CATFacetStyle iFacetStyle, CATListPtrCATBaseUnknown &oListProperty);

    virtual HRESULT ShadingModified();
    virtual HRESULT GetShadingActive(CATBoolean &oShadingActive);
    virtual HRESULT SetShadingActive(CATBoolean iShadingActive);

    virtual HRESULT ClassificationModified();
    virtual HRESULT GetClassificationActive(CATBoolean &oClassificationActive);
    virtual HRESULT SetClassificationActive(CATBoolean iClassificationActive);

    virtual HRESULT PropertyModified();

    virtual HRESULT GetExpandStatus(CATBoolean &oExpandStatus);
    virtual HRESULT SetExpandStatus(CATBoolean iExpandStatus);

    virtual HRESULT GetDashboardingMode(DashboardingMode &oDashboardingMode);
    virtual HRESULT SetDashboardingMode(DashboardingMode iDashboardingMode);

    /**
     *
     * <br><b>Role</b>: Returns the style of the facet to display (Combination of styles)
     * @return
     * Style of the facet
     */
    virtual CATFacetStyle GetFacetStyle();

    /**
     * In case of multiple properties check modification at once (due to select all command for example),
     * a unique call to this method will be made
     */
    virtual HRESULT OnUserCheck(const CATListPtrCATBaseUnknown &iListProperty, const CATListOfCATBoolean &iListCheckStatus);

    /**
     * Determine if Reset cmd should be displayed or not
     */
    virtual HRESULT IsResetCmdAvailable(CATBoolean &obIsAvailable);
    /**
     * When user clicks on Reset cmd, this method will be called
     * A default behavior is delivered in the adapter but can be overloaded to have a different one
     */
    virtual HRESULT OnUserResetRequest();

    /**
     * Determine if Invert cmd should be displayed or not
     */
    virtual HRESULT IsInvertCmdAvailable(CATBoolean &obIsAvailable);

    virtual HRESULT SendRefinementUpdateNotification(int iRefreshType);

protected:

  CATString                _FacetID;
  CATUnicodeString         _NLSFacet;
  CATSetOfCATUnicodeString _NLSFacetGroup;
  CompassQuadrant          _Quadrant;
  RefinementW              _RefinementW;
  FacetModes               _FacetMode;
  CATBoolean               _ShadingActive;
  CATBoolean               _ClassificationActive;
  CATBoolean       _StarMode;   // to remove as soon as possible, added for compilation purpose (tree IC1R2) : OLC
  CATListPtrCATBaseUnknown _ListProperty;
  CATFacetStyle            _FacetStyle;
  DashboardingMode         _DashboardingMode;

private:
  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATAdapterPLMCompassRefinementFacet(CATAdapterPLMCompassRefinementFacet &);
  CATAdapterPLMCompassRefinementFacet& operator=(CATAdapterPLMCompassRefinementFacet&);

};
#endif
