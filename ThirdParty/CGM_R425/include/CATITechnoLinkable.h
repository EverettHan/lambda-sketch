/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATITechnoLinkable_h
#define CATITechnoLinkable_h

/**
 * @level Private 
 * @usage U3
 */

#include "TECHNLNK.h"
//#include "CATBaseUnknown.h"
#include "IUnknown.h"
#include "CATMacForIUnknown.h"
#include "CATLISTPIUnknown.h"
#include "CATListPtrCATITechnoLinkable.h"

#include <wchar.h>

extern ExportedByTECHNLNK IID IID_CATITechnoLinkable ;

// ******************************************************************
//
//  Interface de gestion de parcours/nommage de liens technologiques
//
//  Les liens technologiques sont des liens relatifs entre 2 entites
//  le pointant et le pointe (au sens referencement) 
//
//  methodes de parcours:
//  --------------------
//  GetProtName            :     recuperation du protocole de parcours
//
//  GetObject              :     recuperation de l'objet que j'ai su nommer.
//      Le nom peut etre compose => je decode la partie que je sais interpreter
//      et je donne le reste a la suite.
//								 Le pointeurs retourne correspond a l'interface dont le GUID a ete donne en entree
//
//  methodes de nommage:
//  --------------------
//  GetName                :     recuperation du nom que je donne a un objet
//
//  GetObjectFromNameOnly  :     recuperation d'un objet nomme immediatement
//								 Le pointeurs retourne correspond a l'interface dont le GUID a ete donne en entree
//
//  ListNamedObjects       :     liste des objets que je sais nommer
//
// methodes sur objet vu comme lien lui meme
// ------------------------------------------
// GetPathObject           :     recuperation de l'ensemble des objets
//                               correspondant a un chemin donne.
//								 Les pointeurs retournes sont,
//									- pour chaque element intermediaire du chemin :
//										l'interface derivee de CATITechnolinkable utilisee lors du dereferencement
//									- pour l'element final, l'interface de GUID InterfaceID donnee en entree de la methode
//
// GetPathName             :     construction du nom du chemin correspondant
//                               a une liste de points de passage donnee.
// 
// ******************************************************************

class CATITechnoLinkListener;

class ExportedByTECHNLNK CATITechnoLinkable : public IUnknown
{
  CATDeclareInterface;

public:

	// Methodes implementees par CATTechnoRootExt
  virtual HRESULT GetPathName(const CATLISTP(CATITechnoLinkable) iIntermediates,
							const IUnknown* iTarget,
							wchar_t** oPath) const = 0 ;

  virtual HRESULT GetObject(const wchar_t* iPathName,
							const IID iTargetInterfaceID,
							IUnknown** oTarget) const = 0 ;

  virtual HRESULT GetPathObject(const wchar_t* iName,
							const IID iTargetInterfaceID,
							CATLISTP(CATITechnoLinkable)*  oIntermediates,
							IUnknown** oTarget) const = 0 ;

  
	// Methodes a surcharger pour chaque adhesion
  virtual HRESULT GetProtocol(wchar_t** oProtocol) const = 0;

  virtual HRESULT ListNamedObjects(CATLISTP(IUnknown)* oNamedObjects) const = 0 ;

  virtual HRESULT GetName (const IUnknown* iNamedObject,
							wchar_t** oName) const = 0 ;
   
  virtual HRESULT GetObjectFromNameOnly(const wchar_t* iName,
							const IID iNamedObjectInterfaceID,
							IUnknown** oNamedObject) const = 0 ;

  //Methodes pouvant etre surchargees

  virtual HRESULT ListenPathObject( const wchar_t* iName,
									const IID iTargetInterfaceID,
									CATITechnoLinkListener *iListener,
									CATLISTP(CATITechnoLinkable)*  oIntermediates,
									IUnknown** oTarget)  = 0;
  
  //methode a surcharger par les protocoles non constants 
  virtual HRESULT ListenNamedObject( const wchar_t* iName,
									 const IID iNamedObjectInterfaceID,
									 CATITechnoLinkListener *iListener,
									 IUnknown** oNamedObject) = 0;


};


#endif
