/**
 * @level Protected
 * @usage U2
 */
/* -*-c++-*- */

// COPYRIGHT DASSAULT SYSTEMES  2005
//=============================================================================
//
//  Adapter class CATOmcElementAdapter :  Adapter for the new V4 Containers.
//
//=============================================================================
// Usage Notes:
//=============================================================================
//


#ifndef CATOmcElementAdapter_H_
#define CATOmcElementAdapter_H_

#include <CATExtensionAdapter.h>
#include "AC0CATPL.h"
#include "CATBaseUnknown.h"
// OGM le 27/04/2005 pour cause de catastrophe ODT dans LIP1501
//#include "CATIContainer.h"
// Fin OGM du 27/04/2005

class CATIAModel;

/**
 * Adapter class for LifeCycleObject, CATImplementationCATIA and CATIAscendant 
 * interfaces.
 * <b>Role:</b> Deriving from this adapter enables you to implement the 
 *							CATImplementationCATIA, CATIAscendant and LifeCycleObject 
 *							interfaces, inheriting implementation.<br>
 */

//Derivation C++ obligatoire pour BOA des implementations
//qui heritent de CATOmcElementAdapter
// OGM le 27/04/2005 pour cause de catastrophe ODT dans LIP1501
// class ExportedByAC0CATPL CATOmcElementAdapter : public CATIContainer
class ExportedByAC0CATPL CATOmcElementAdapter : public CATExtensionAdapter
// Fin OGM du 27/04/2005
{
	public:

		/**
		* Constructs a CATOmcElementAdapter.
		*/
		CATOmcElementAdapter();
		virtual ~CATOmcElementAdapter();

// OGM le 27/04/2005 pour cause de catastrophe ODT dans LIP1501
		/**
		* Interface CATIContainer : obligatoire pour derivation C++
		*/
    
//		virtual SEQUENCE(CATBaseUnknown_ptr) ListMembers (const CATIdent interfaceID) ;
//		virtual CATLONG32                             ListMembersHere (const CATIdent interfaceID, SEQUENCE(CATBaseUnknown_ptr)& list);
// Fin OGM du 27/04/2005

		/**
		* Interface LifeCycleObject
		*/
		void                      remove() ;
		void                      remove( int context ) ;

		/**
		* CATImplementationCATIA
		*/
		int                       GetReferenceJele() ;
		int                       GetReferenceMnum() ;
		CATIAModel*               GetReferenceModel() ;
		CATBaseUnknown*           GetElementContainer( CATClassId InterfaceID ) ;
		CATBaseUnknown*           GetElementContainer( const GUID& iid ) ;

		/**
		* CATIAscendant 
		*/
		CATBaseUnknown_var        GetFather() ;

	//private:
		//CATBaseUnknown* FindContFather(CATBaseUnknown* iContainer, CATBaseUnknown* iRootContainer);
		//CATBaseUnknown* FindV4V5ContFather(CATBaseUnknown* iContainer, CATBaseUnknown* iRootContainer);

};

#endif

