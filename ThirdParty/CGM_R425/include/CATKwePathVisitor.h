// COPYRIGHT DASSAULT SYSTEMES  2001
//=============================================================================
//
// CATKwePathVisitor.cpp:
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// 24/10/2001   Creation                                   CHL
//=============================================================================


#ifndef _CATKwePathVisitor_
#define _CATKwePathVisitor_

#include "CATVisitorAdapter.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "CATIType.h"
#include "CATIVisitor.h"
#include "CATBaseUnknown.h"
#include "CATIParmPublisher.h"
#include "CATIChildrenAccess.h"
#include "CATListOfCATUnicodeString.h"
#include "CATLifLibrary.h"

/**
* Basic visitor: finds an object through a path
*/
class ExportedByCATLifLibrary CATKwePathVisitor : public CATVisitorAdapter
{
	CATDeclareClass;
public:
	CATKwePathVisitor(	const CATIType_var			&type,
						const CATUnicodeString		&path,
						const CATBaseUnknown_var    &pub); // can be a CATIChildrenAccess or a CATIParmPublisher

	virtual ~CATKwePathVisitor();

	// methode a appeler de l'exterieur pour trouver l'objet a partir de son path
	HRESULT Find (CATBaseUnknown_var &fiFound);

	// methode appelee lors de la visite
	HRESULT Visit(CATBaseUnknown *instance);
	
	//methode qui cree un path corrige 
	HRESULT CorrectPath(CATUnicodeString &oPath, const CATBaseUnknown_var &iFinalObject);
	
	CATBaseUnknown_var GetPrd();
	CATUnicodeString GetCurrentName();
	CATLISTV(CATBaseUnknown_var) GetInstancesOnPath();
	CATBaseUnknown_var GetRepInstance();
	CATBaseUnknown_var GetPublication();
private:
	CATKwePathVisitor(const CATKwePathVisitor&);
	void operator=(const CATKwePathVisitor&);

	// Type de l'objet recherche
	CATIType_var              _Type;

	// Path d'entree
	CATUnicodeString		  _Path;
	// convertit en liste de string
	CATListOfCATUnicodeString _Lst;

	// Objet de depart
	CATIParmPublisher_var     _Pub;
	CATIChildrenAccess_var   _CompAccess;

	// Dernier objet trouve
	CATBaseUnknown_var        _Current;

	// Nom que l'on recherche
	CATUnicodeString          _CurrentName;

	// L'a t on trouve
	int                       _Found;

	// est on sur le dernier
	int                       _Last;

	// Cherche t - on un objet ou un parametre
	CATCke::Boolean			  _WeWantObject;

	//On stocke la product instance qui est associee
	CATBaseUnknown_var			 _PrdInsance;
	CATBaseUnknown_var			 _PrdRef;
	CATBaseUnknown_var			 _PrdRefOrRep;
	//On stocke aussi la rep instance
	CATBaseUnknown_var           _RepInstance; 
	int                          _CurrentPathIndex;

	int _WalkThrough;
	CATUnicodeString _ExpectedType;

	CATLISTV(CATBaseUnknown_var) _InstancesOnPath;
	CATBaseUnknown_var _Publication;
};


#endif
