#ifndef CAT2DFilterBagRep_H
#define CAT2DFilterBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 2004

#include "SGInfra.h"
#include "CAT2DBagRep.h"
#include "list.h"
#include "CATErrorDef.h"
#include "CATEventSubscriber.h"
#include "VisFilteringEnums.h"
#include <map>

class CATVisFilter;
class VisSGFilterVisitor;
class CATFilterNotification;
class CATVisAnnotation;

class ExportedBySGInfra CAT2DFilterBagRep : public CAT2DBagRep
{
  friend class CAT2DFilterBagRepHelper;

  CATDeclareClass;

public:

  // creation of a CAT2DBagRep that can carry a certain number of filters
  // which will be applied to all its children
  static CAT2DFilterBagRep* CreateRep();


  virtual ~CAT2DFilterBagRep();

  // add a filter
  // (AddRef is called on "filter")
  HRESULT AddFilter(CATVisFilter* filter);


  // remove a filter
  // (Release is called on "filter")
  HRESULT RemoveFilter(CATVisFilter* filter);

  // remove all filters
  // (Release is called on all filters)
  void EmptyFilters();

  // this function allows you to find the number of filters (of a certain type)
  // carried by the bag. To get the type of a filter, just call
  // the static method: GetFilterType on the latter.
  // ex : bag->GetFilterNumber(CATVisLayerFilter::GetFilterType());
  // NB: id 0 corresponds to CATVisFilter -> by default this function returns the total number of filters in the bag
  int GetFilterNumber(unsigned int iType = 0);

  //// Gets the value of RepViewMode set in first CATVisRepViewModeFilter on this into iNum; retunrs E_FAIL if such filter not present
  //HRESULT GetRepViewModeInFilter(int& iNum);
  //inline bool HasAFForceShowMode() { return _bHasAFForceShowMode ? true : false; }

  //// Gets the ZFilter value if present else returns ZModeFilterEnum::eNoFilter
  //ZModeFilterEnum GetZModeFilterValue() const;

  // Gets the GASFilter Value if filter not available then returns E_FAIL.
  HRESULT GetGASInheritFilterValue(int& oVal) const;

  // Calls GetGASFilterAttribute on CATVisGASInheritFilter. Check CATVisGASInheritFilter.h , (GetGASFilterAttribute) for return rule.
  HRESULT GetGASFilterAttribute(CATGraphicAttributeSet& oAttributeSet) const;

  //// function to retrieve the first layer filter
  //// carried by the rep. If the rep does not contain such a filter
  //// E_FAIl will be returned otherwise S_OK will be returned and oFilter will be filled
  //HRESULT GetLayerFilter(unsigned char oFilter[1024]);


  //// function to update layer filters
  //// contained in the bag from the current layer filter
  //// Indirectly, this function is only used to update the NONE type filters of the dittos
  //void UpdateLayerFilter(const unsigned char iCurrentFilter[1024]);

  // assignement operator
  CAT2DFilterBagRep& operator = (const CAT2DFilterBagRep&);

  // internal use
  virtual void ComputeBoundingElement(int iShowSpace = 1);

  // AZX: (A2X migration) This rep is not derived thus making draw functions final 
  virtual void DrawShading(CATRender& ioRender, int iInside) override final;
  virtual void DrawPath(CATRender& ioRender, int iInside, CATRepPath& ioPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  void Visit(VisSGFilterVisitor& iVisitor) const;

  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

protected:

  CAT2DFilterBagRep();


  void UpdateFilterCB(CATCallbackEvent event, void* client, CATNotification* notification, CATSubscriberData data, CATCallback callback);

  void UpdateFilter(CATVisFilter* filter, CATFilterNotification* iNotif);

  void CheckFiltersForObserver();

  const ::list<CATVisFilter>& GetFilters() const 
  { 
    return _filters; 
  }

private:
  ::list<CATVisFilter> _filters;
  typedef std::map<void*, CATCallback> CallbackMap;
  CallbackMap _CallbackMap;
  //unsigned int _bHasAFForceShowMode;
  //bool _bHadAFForceShowMode;
  bool _declaredObservable = false;
};

#endif // CAT2DFilterBagRep_H
