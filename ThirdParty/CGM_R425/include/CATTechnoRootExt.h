/* -*-c++-*- */
#ifndef CATTechnoRootExt_h
#define CATTechnoRootExt_h
/**
 * @level Private
 * @usage U1       
 */

// COPYRIGHT DASSAULT SYSTEMES   1998
//=============================================================================
//
// class CATTechnoRootExt :
//    base class for implementations of interface CATItechnoLinkable
//
//=============================================================================
// Usage Notes:
//
// 
//=============================================================================
// Sept. 98   Creation           RCI
// Jan.  99   Modification       OST
// Dec.  99   Modification       FRG                   
//=============================================================================


#include "CATExtensionAdapter.h"
#include "TECHNLNK.h"
#include "CATITechnoLinkable.h"
#include "CATITechnoLinkListener.h"

class ExportedByTECHNLNK CATTechnoRootExt : public CATExtensionAdapter
{
  CATDeclareClass ;

public:
  CATTechnoRootExt();
  virtual ~CATTechnoRootExt();
  
   // methodes de l'interface a ne pas surcharger
  //------------------------------------------------

  virtual HRESULT GetPathName(const CATLISTP(CATITechnoLinkable) iIntermediates,
							const IUnknown* iTarget,
							wchar_t** oPath) const;

  virtual HRESULT GetObject(const wchar_t* iPathName,
							const IID iTargetInterfaceID,
							IUnknown** oTarget) const;

  virtual HRESULT GetPathObject(const wchar_t* iName,
							const IID iTargetInterfaceID,
							CATLISTP(CATITechnoLinkable)*  oIntermediates,
							IUnknown** oTarget) const;



   // methodes de l'interface a surcharger obligatoirement
  //-------------------------------------------------------------

  virtual HRESULT GetProtocol(wchar_t** oProtocol) const = 0;

  virtual HRESULT ListNamedObjects(CATLISTP(IUnknown)* oNamedObjects) const = 0 ;

  virtual HRESULT GetName (const IUnknown* iNamedObject,
							wchar_t** oName) const = 0 ;
   
  virtual HRESULT GetObjectFromNameOnly(const wchar_t* iName,
							const IID NamedObjectInterfaceID,
							IUnknown** oNamedObject) const = 0 ;


  // methodes pouvant etre surcharges
  //-----------------------------------

  virtual HRESULT ListenPathObject( const wchar_t* iName,
									const IID iTargetInterfaceID,
									CATITechnoLinkListener *iListener,
									CATLISTP(CATITechnoLinkable)*  oIntermediates,
									IUnknown** oTarget) ;
  
  //methode a surcharger par les protocoles non constants 
  virtual HRESULT ListenNamedObject( const wchar_t* iName,
									 const IID iNamedObjectInterfaceID,
									 CATITechnoLinkListener *iListener,
									 IUnknown** oNamedObject);



   // methodes privees definies pour des besoins internes
  //-------------------------------------------------------------
private:
	HRESULT GetProtocol(CATUnicodeString &oProtocol) const;
  // historical slow algorithm
  HRESULT _GetPathObject(const wchar_t* iName,
							const IID iTargetInterfaceID,
							CATLISTP(CATITechnoLinkable)*  oIntermediates,
							IUnknown** oTarget) const;
  friend class CATTechnoPathDecoder;
};

#endif

