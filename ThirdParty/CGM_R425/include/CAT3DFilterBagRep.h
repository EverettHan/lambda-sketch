#ifndef CAT3DFilterBagRep_H
#define CAT3DFilterBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 2004

#include "SGInfra.h"
#include "CAT3DBagRep.h"
#include "list.h"
#include "CATErrorDef.h"
#include "CATEventSubscriber.h"
#include "VisFilteringEnums.h"
#include <map>

class CATVisFilter;
class IVisSG3DNodeGroup;
class CAT3DFilterBagRepIVisSG3DNodeGroupBOAImpl;
class VisSGFilterVisitor;
class CATFilterNotification;
class CATVisAnnotation;

class ExportedBySGInfra CAT3DFilterBagRep : public CAT3DBagRep
{
  friend class SGCGRStreamerFor3DFilterBagRep;
  friend class CATDmuStream3DFilterBagRep;
  friend class CAT3DFilterBagRepHelper;
  friend class CAT3DFinalFilterBagRep;
  friend class CAT3DPLMBagRep;

	CATDeclareClass;
	
public:
  //++ SGCAAPlan
  friend class CAT3DFilterBagRepIVisSG3DNodeGroupBOAImpl;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DFilterBagRep, IVisSG3DNodeGroup, CAT3DFilterBagRepIVisSG3DNodeGroupBOAImpl);
  //-- SGCAAPlan

    // creation d'une CAT3DBagRep pouvant porter un certain nombre de filtre
    // qui seront appliques a tous ses enfants
  static CAT3DFilterBagRep* CreateRep();

protected:

	virtual ~CAT3DFilterBagRep();
	
public:
    // ajout d'un filtre
    // (AddRef est appele sur "filter")
	HRESULT AddFilter(CATVisFilter* filter);

    // retrait d'un filtre
    // (Release est appele sur "filter")
	HRESULT RemoveFilter(CATVisFilter* filter);

    // retrait de tous les filtres
    // (Release est appele sur tous les filtres)
	void EmptyFilters();

    // cette fonction permet de retrouver le nombre de filtre (d'un certain type) 
    // portes par la bag. Pour avoir le type d'un filtre, il suffit d'appeler
    // la methode statique : GetFilterType sur ce dernier.
    //
    //    ex : bag->GetFilterNumber(CATVisLayerFilter::GetFilterType());
    //
    // NB: l'id 0 correspond a CATVisFilter -> par defaut cette fonction renvoie le nombre de filtres total de la bag
    int GetFilterNumber(unsigned int iType = 0);

    // Gets the value of RepViewMode set in first CATVisRepViewModeFilter on this into iNum; retunrs E_FAIL if such filter not present
    HRESULT GetRepViewModeInFilter(int &iNum); 
    inline bool HasAFForceShowMode() { return _bHasAFForceShowMode ? true : false; }
    
    // Gets the ZFilter value if present else returns ZModeFilterEnum::eNoFilter
    ZModeFilterEnum GetZModeFilterValue() const;
    // Gets the GASFilter Value if filter not available then returns E_FAIL.
    HRESULT GetGASInheritFilterValue(int &oVal) const;
    // Calls GetGASFilterAttribute on CATVisGASInheritFilter. Check CATVisGASInheritFilter.h , (GetGASFilterAttribute) for return rule.
    HRESULT GetGASFilterAttribute(CATGraphicAttributeSet& oAttributeSet) const;
		
    // fonction permettant de recuperer le premier filtre de layer
    // porte par la rep. Si la rep ne contient pas de filtre de ce type
    // E_FAIl sera retourne sinon S_OK sera retourne et oFilter sera rempli
    HRESULT GetLayerFilter(unsigned char oFilter[1024]);

    // fonction permettant d'updater les filtres de layers
    // contenus dans la bag a partir du filtre de layer courant 
    // Indirectement, cette focntion sert uniquement a updater les filtres de type NONE des dittos
    void UpdateLayerFilter(const unsigned char iCurrentFilter[1024]);

    // assignement operator
    CAT3DFilterBagRep& operator = (const CAT3DFilterBagRep&);

    // usage interne
	virtual void ComputeBoundingElement(int iShowSpace=1);
	virtual void DrawShading(CATRender &ioRender, int iInside);
	virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath); 
	
  void Visit(VisSGFilterVisitor& iVisitor) const;

  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

protected:
  BEGIN_MIGRATE_REP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CAT3DFinalFilterBagRep to derive from" )
#endif
  CAT3DFilterBagRep();
  END_MIGRATE_REP_CTOR

  void UpdateFilterCB(CATCallbackEvent event, void* client, CATNotification* notification, CATSubscriberData data, CATCallback callback);
  void UpdateFilter(CATVisFilter* filter, CATFilterNotification* iNotif);
  void CheckFiltersForObserver();
  const ::list<CATVisFilter>& GetFilters() const { return _filters; }

private :
	::list<CATVisFilter> _filters;
  typedef std::map<void*, CATCallback> CallbackMap;
  CallbackMap _CallbackMap;
  unsigned int _bHasAFForceShowMode;
  bool _bHadAFForceShowMode;
  bool _declaredObservable = false;
};

#endif // CAT3DFilterBagRep_H
