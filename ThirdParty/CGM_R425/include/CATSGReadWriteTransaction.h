#pragma once

#include "CATStdLib.h"
#include "CATSGReadOnlyTransaction.h"
#include "SGInfra.h"

class CATSceneGraphImpl;
class CATRep;
class CATGraphicPrimitive;
class CATSceneGraph;
class CATSGReadWriteTransactionImpl;

class ExportedBySGInfra CATSGReadWriteTransaction : public CATSGReadOnlyTransaction
{
public:
	/**
	Append a child rep under iParent. If iParent is NULL, the rep will be added under the current node of the transaction (if possible)
	*/
	HRESULT AppendChildRep(CATRep *ioRep, CATRep * iParent=0);

	/**
	Append a child scene under iParent. If iParent is NULL, the scene will be added under the current node of the transaction (if possible)
	*/
	HRESULT AppendChildScene(const CATSceneGraph & ioGraph, CATRep * iParent=0);

	/**
	Remove a rep from the scene. If ioRep is null, the current node of the transaction will be used.
  Choice is given for the removed rep lifecycle : destroy or not.
	*/
	HRESULT RemoveRep(CATRep * ioRep=0, CATBoolean destroyRep=TRUE);

	/**
	Append a GP under iParent. If iParent is NULL, the GP will be added under the current node of the transaction (if possible)
	*/
	HRESULT AddGPToRep(CATGraphicPrimitive * ioGP, CATRep * iParent=0);

	/**
	Removes a GP from iParent. If iParent is NULL, the method will try to remove the GP from current node of the transaction (if possible)
	*/
	HRESULT RemoveGPFromRep(CATGraphicPrimitive * ioGP, CATRep * iParent=0);

	/**
	Adds the rep to the index, under iIndexID. if iRep is null, the current node of the transaction will be used
	if an existing rep was already indexed with the same ID, it will be replaced.
	*/
	HRESULT SetRepIndexID(const CATUnicodeString &iIndexID, CATRep * iRep=0);

	/**
	Set a metadata value attached to a rep. if iRep is null, the current node of the transaction will be used
	*/
	HRESULT SetRepMetadata(const CATUnicodeString &iMetaName, const CATUnicodeString &iMetaValue, CATRep * iRep=0);

	/** Computes the bounding element of iRep. if iRep is null, the current node of the transaction will be used
	* The bounding element should be the smallest possible sphere containing the representation.
	* @param iShowSpace
	* <br><b>Legal Values</b>:
	* <ol>
	*<li> 0 :  </li>
	*<li> 1 :  </li>
	* </ol>
	*/
	HRESULT ComputeBoundingElement(int iShowSpace = 1, CATRep * iRep = 0);
	// TODO: SGv6

	HRESULT Commit();
	HRESULT Rollback();
	CATSGReadWriteTransactionImpl * GetImpl() const;

private:
	// all ctor/dtor are private: this cannot be instanciated/freed by anything but a CATSceneGraphImpl
	CATSGReadWriteTransaction();
	CATSGReadWriteTransaction(CATSceneGraphImpl * iSG);
	CATSGReadWriteTransaction(const CATSGTransaction &);
	virtual ~CATSGReadWriteTransaction();
	
	
	friend class CATSceneGraphImpl;
	
};
