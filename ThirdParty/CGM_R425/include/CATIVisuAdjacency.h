#ifndef CATIVISUADJACENCY_H
#define CATIVISUADJACENCY_H
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
//  Inheritance :   CATIVisuAdjacency
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
#include "CATListOfCATPathElement.h"
#include "CATListOfInt.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIVisuAdjacency;
#else
extern "C" const IID IID_CATIVisuAdjacency;
#endif

class ExportedBySceneGraphManager CATIVisuAdjacency : public CATBaseUnknown
{
	CATDeclareInterface;

public :

	virtual HRESULT ComputeAdjacency(const CATLISTP(CATPathElement)* ipPathElementList, const CATListOfInt& iVisiblePathEltsIndexList, const CATListOfInt& iHiddenPathEltsIndexList, CATListOfInt& oVisibleAndAdjoiningPathEltsIndexList) = 0;

};

CATDeclareHandler(CATIVisuAdjacency, CATBaseUnknown);

#endif

