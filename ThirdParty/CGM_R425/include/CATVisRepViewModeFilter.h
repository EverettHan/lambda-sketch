//===================================================================
// COPYRIGHT Dassault Systemes 2016/01/06
//===================================================================
// CATVisRepViewModeFilter.cpp
// Header definition of class CATVisRepViewModeFilter
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2016/01/06 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATVisRepViewModeFilter_H
#define CATVisRepViewModeFilter_H

#include "SGInfra.h"
#include "CATVisFilter.h"

//-----------------------------------------------------------------------

class ExportedBySGInfra CATVisRepViewModeFilter: public CATVisFilter
{
  CATDeclareVisFilter(CATVisRepViewModeFilter);

public:
  /** 
  * @nodoc
  * Returns the CATVisRepViewModeFilter set with the input value of repviewmode.
  */
  static CATVisRepViewModeFilter* Create(const int repviewmode);
  /** 
  * @nodoc
  * For the input value of repviewmode sets the valid value of repviewmode
  // #0 If multiple CATVisRepViewModeFilters are applied on a CAT3DRepFilterBagRep, only the first one will be effective, others will be discarded.
  // RepViewMode set through this filter on CAT3DRepFilterBagRep will be applied on all its children ONLY IF:
  // #1. VIEW_REP_OVERLOAD is enabled for the Viewer 
  //  Currently it is disabled if ViewerViewMode contains any of the modes below:
  //      - VIEW_COLORED_EDGES_FROM_FACES
  //      - VIEW_LINEONLINE
  //      - VIEW_HLR
  //      - VIEW_TRANSPARENT
  //      - VIEW_POLYGON
  //      - VIEW_ISOPARS
  //      - VIEW_TOON
  // #2. RepViewMode is not set to REP_VIEW_DISABLED (0x0)
  //      In such a case, ViewerViewMode will be effective for the child reps.
  // #3. No parent of this node is applied with the CATVisRepViewModeFilter
  // #4. No parent of this node is applied with the RepViewMode through CAT3DRep:SetViewMode API
  //      In such a case, RepViewmode set on any child rep will be discarded. RepViewMode of the parent will be effective for the reps.
  // #5. The acceptable values of RepViewModes API are defined in CATRep.h
  // #6. The RepViewModes containing REP_VIEW_OUTLINE (explicit or implicit) won't be taken into account if the ViewerViewMode does not contain VIEW_OUTLINE
  //      In such a case, ViewerViewMode will be effective for the rep. 
  */

  int SetRepViewMode (const int repviewmode);
  /** 
  * @nodoc
  * Returns the saved value of repviewmode
  */
  void GetRepViewMode (int &repviewmode);

protected :
  // Standard constructors and destructors
  // -------------------------------------
  CATVisRepViewModeFilter (const int repviewmode);
  virtual ~CATVisRepViewModeFilter ();


private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVisRepViewModeFilter (CATVisRepViewModeFilter &);
  CATVisRepViewModeFilter& operator=(CATVisRepViewModeFilter&);

};

//-----------------------------------------------------------------------

#endif
