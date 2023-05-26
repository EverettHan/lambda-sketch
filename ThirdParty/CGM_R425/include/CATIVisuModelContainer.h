#ifndef CATIVISUMODELCONTAINER_H
#define CATIVISUMODELCONTAINER_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  pour participer au moteur de visualisation.
//
//             ( permet de definir le fait qu'un element modele
//               peut etre vue d'une certaine maniere. La maniere etant
//               definie par le type (au sens IsAKindOf) de l'interface de
//               visu )
//            
//              
//   
//-----------------------------------------------------------------
//
//  Usage :    cette interface est derivee de facon a definir les differents
//  -------    types de visu d'un element ( un objet modele peut
//             adherer a plusieurs types d'interfaces de visu )
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIVisuModelContainer
//  -------------     CATInterfaceObject
//
//-----------------------------------------------------------------
//
//  Main Methods :
//  --------------
//
//
//-----------------------------------------------------------------
#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIVisuModelContainer;
#else
extern "C" const IID IID_CATIVisuModelContainer;
#endif

class ExportedBySceneGraphManager CATIVisuModelContainer : public CATBaseUnknown
{
	CATDeclareInterface;

public :

	virtual HRESULT GetModelContainer(CATBaseUnknown*& opModelContainer) = 0;

};

CATDeclareHandler(CATIVisuModelContainer, CATBaseUnknown);

#endif

