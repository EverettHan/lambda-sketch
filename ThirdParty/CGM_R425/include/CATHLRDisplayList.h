#ifndef CATHLRDisplayList_H
#define CATHLRDisplayList_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//    This class manages a list of representation required by the HLR algorithm
//    interface.
//
//******************************************************************************
//  Usage:
//  ------
//    Once created empty, instances are added through the AddInstance method,
//    that defines the representation to be added and it's absolute spatial
//    position.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CATHLRDisplayList.
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************

#include <SGInfra.h>

#include "CATVizPtrList.h"
#include "CATRep.h"
#include "CAT4x4Matrix.h"
#include "CATGraphicAttributeSet.h"

class CATModelIdentificator;
class CATVisHLRClippingVolume;
class CATSupport;
class CAT3DViewpoint;


class ExportedBySGInfra CATHLRDisplayList
{  
  public:

    // Construction and destruction methods:
    // -------------------------------------
    
		CATHLRDisplayList (void);
		virtual ~CATHLRDisplayList (void);


		// Managing the list of instances:
		// -------------------------------
		//   When adding an instance, representations are shared and matrices are
		//   duplicated.

		void                    AddInstance          (CATRep *rep,
			CAT4x4Matrix &matrix,
			CATGraphicAttributeSet &att,
			unsigned int inheritanceMode = 0,
			const CATModelIdentificator *iModelId = NULL,
			unsigned int viewNumber = 0);
		void Clear                                   (void);
		inline int                     NbInstances          (void);
		inline CAT4x4Matrix           &GetInstancePosition  (unsigned int num_instance);
		inline CATRep                 *GetInstanceRep       (unsigned int num_instance);
		inline CATGraphicAttributeSet &GetInstanceAttribute (unsigned int num_instance);
		inline unsigned int GetInstanceGasInheritanceMode(unsigned int num_instance);
		inline const CATModelIdentificator		*GetInstanceModelId			(unsigned int num_instance);
		inline const CATVizPtrList<CATVisHLRClippingVolume>	*GetInstanceClippingVolume	(unsigned int num_instance);
		inline unsigned int	GetInstanceViewNumber	(unsigned int num_instance);
		inline const CATRep						*GetInstanceClippedRep		(unsigned int num_instance);
		inline void SetInstanceClippedRep		(unsigned int num_instance, CATRep *iRep);

		void  RemoveInstance(unsigned int num_instance);

		unsigned int GetNbViews(void) const;

		inline void PushClippingVolume(CATVisHLRClippingVolume *iClippingVolume);
		inline void PopClippingVolume();
		
//		HRESULT RunOcclusionMap(const CATSupport *iSupport, const CAT3DViewpoint *iViewpoint, unsigned int iMapSize = 0);
    
  protected:

	struct HLRDLItem {
		HLRDLItem() 
		{
			rep					= NULL;
			modelId			= NULL;
			clippingList= NULL;
			clippedRep	= NULL;
			gasInheritanceMode= 0;
			viewNumber	= 0;
		}
		~HLRDLItem()
		{
			rep	= NULL;
			modelId = NULL;
			if (clippingList)
			{
				clippingList->Empty();
				delete clippingList;
				clippingList = NULL;
			}
			if (clippedRep)
			{
				clippedRep->Destroy();
				clippedRep = NULL;
			}
		}
		CATRep	*rep;
		CAT4x4Matrix	matrix;
		CATGraphicAttributeSet	gas;
		const CATModelIdentificator	*modelId;
		CATVizPtrList<CATVisHLRClippingVolume>	*clippingList;
		CATRep	*clippedRep;
		int gasInheritanceMode;
		unsigned int viewNumber;
	};

	CATVizPtrList<HLRDLItem>	_items;

	CATVizPtrList<CATVisHLRClippingVolume> _clippingHLRVolume;
	CATVizPtrList<CATVisHLRClippingVolume> _clippingHLRVolumeCurrentStack;
    
  private:
    
};

inline void CATHLRDisplayList::PushClippingVolume(CATVisHLRClippingVolume *iClippingVolume)
{
	if (iClippingVolume) 
	{
		_clippingHLRVolume.AddHead(iClippingVolume);
		_clippingHLRVolumeCurrentStack.AddHead(iClippingVolume);
	}
}
inline void CATHLRDisplayList::PopClippingVolume()
{
	if (_clippingHLRVolumeCurrentStack.Length() > 0)
		_clippingHLRVolumeCurrentStack.RemoveAtHead();
}


//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************

inline int CATHLRDisplayList::NbInstances (void)
{
	return _items.Length();
};


inline CAT4x4Matrix &CATHLRDisplayList::GetInstancePosition (unsigned int num_instance)
{
	return _items[num_instance]->matrix;
}


inline CATRep *CATHLRDisplayList::GetInstanceRep (unsigned int num_instance)
{
	return _items[num_instance]->rep;
}


inline CATGraphicAttributeSet &
		      CATHLRDisplayList::GetInstanceAttribute (unsigned int num_instance)
{
	return _items[num_instance]->gas;
}

inline unsigned int CATHLRDisplayList::GetInstanceGasInheritanceMode(unsigned int num_instance)
{
	return _items[num_instance]->gasInheritanceMode;
}

inline const CATModelIdentificator *
		      CATHLRDisplayList::GetInstanceModelId (unsigned int num_instance)
{
	return _items[num_instance]->modelId;
}

inline const CATVizPtrList<CATVisHLRClippingVolume> *
		      CATHLRDisplayList::GetInstanceClippingVolume (unsigned int num_instance)
{
	return _items[num_instance]->clippingList;
}

inline unsigned int	CATHLRDisplayList::GetInstanceViewNumber	(unsigned int num_instance)
{
	return _items[num_instance]->viewNumber;
}

inline const CATRep *
		      CATHLRDisplayList::GetInstanceClippedRep (unsigned int num_instance)
{
	return _items[num_instance]->clippedRep;
}

inline void CATHLRDisplayList::SetInstanceClippedRep	(unsigned int num_instance, CATRep *iRep)
{
	if (_items[num_instance]->clippedRep)
		_items[num_instance]->clippedRep->Destroy();
	_items[num_instance]->clippedRep = iRep;
}

#endif
