/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIGraphContainer_h
#define CATIGraphContainer_h

/**
 * @level Protected 
 * @usage U3
 */

#include "CATBaseUnknown.h"

#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATIGraphContainer;

class CATIGraphNode_var;
class CATIGraphLink_var;
class CATListValCATUnicodeString;
class CATListValCATBaseUnknown_var;


class ExportedByCATOmnMain CATIGraphContainer: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	// Ajout, suppression tree
	virtual void AddTree(const CATIGraphNode_var& pere,const CATIGraphNode_var& tree)=0;
	virtual void RemoveTreeAfter(const CATIGraphNode_var& tree)=0;
	virtual void RemoveTree(const CATIGraphNode_var& tree)=0;
	virtual void RemoveTree(const CATIGraphLink_var& link)=0;

	// Recuperation des racines
	virtual CATListValCATBaseUnknown_var* GetRootNodes()=0;

	// Graphe ou arbre
	virtual int HasGraphCapabilities()=0;
		
	// Update du container
	virtual void Update()=0;

	// Selection globale
	virtual void RemoveAllSelected()=0;
};

// Declaration du handler

CATDeclareHandler ( CATIGraphContainer, CATBaseUnknown);


#endif

