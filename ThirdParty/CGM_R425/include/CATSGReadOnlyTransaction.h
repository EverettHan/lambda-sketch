#pragma once

#include "CATStdLib.h"
#include "CATUnicodeString.h"
#include "CATSGTransaction.h"
#include "SGInfra.h"

class CATSceneGraphImpl;
class CATRep;
class CATSGReadOnlyTransactionImpl;
class VisPrimitive;
class CATGraphicPrimitive;
class CATSGPrimitiveReadOnlyTransaction;

class ExportedBySGInfra CATSGReadOnlyTransaction : public CATSGTransaction
{
public:
	/**
	Set the root rep of the scene as the current object for the transaction
	*/
	HRESULT		MoveToRootRep();

	/**
	Set iRep as the current object for the transaction
	fails if iRep doesn't belong to the current scene
	*/
	HRESULT		MoveToRep(CATRep * iRep);

	/**
	Set the current object for the transaction from the passed ID
	fails if there is no rep with this ID in the scene
	*/
	HRESULT		MoveToRep(const CATUnicodeString &iSGRepID);

	/**
	Set the current object for the transaction to a childrep of the current rep.
	fails if the current rep isn't a bagrep, or if the index is out of bound.
	*/
	HRESULT		MoveToChildRep(CATULONG32 iPos);

	/**
	Set the current object for the transaction to a parent of the current rep.
	fails if the index is out of bound.
	@param iPos The parent index, for diamond configurations. 0 being the first parent
	*/
	HRESULT		MoveToParentRep(CATULONG32 iPos=0);

	/**
	Set the current object for the transaction to the next sibling of the current object. Fails if there is no next sibling
	Note: for diamond configuration, the parent in which the move is performed has to be given, otherwise it fails.
	*/
	HRESULT		MoveToNextSibling(CATRep* iParentRep = NULL);

	/**
	Set the current object for the transaction to the previous sibling of the current object. Fails if there is no previous sibling
	Note: for diamond configuration, the parent in which the move is performed has to be given, otherwise it fails.
	*/
	HRESULT		MoveToPrevSibling(CATRep* iParentRep = NULL);

	/**
	Get the current rep.
	*/
	CATRep *		GetCurrentRep() const;

  /**
	Clone the current rep. Lifecyle management is given to the caller.
	*/
	CATRep *		CloneCurrentRep() const;


	/**
	Retrieves the id from the current rep
	*/
	HRESULT		GetRepID(CATUnicodeString &oID) const;

	/**
	Retrieves the index id from the current rep (or fails if the index doesn't reference the current rep)
	*/
	HRESULT		GetRepIndexID(CATUnicodeString &oIndexID) const;

	/**
	Returns TRUE when a metadata of given name exists for the current rep
	*/
	CATBoolean HasRepMetadata(const CATUnicodeString &iMetaName) const;

	/**
	Retrieves a metadata from the current rep, given the metadata name
	Fails if there is no metadata matching the iMetaName for the current rep.
	*/
	HRESULT		GetRepMetadata(const CATUnicodeString &iMetaName, CATUnicodeString &oMetaValue) const;

	/**
	Returns the number of child reps from the current node
	*/
	CATULONG32	GetChildRepCount() const;

	/**
	Returns the number of primitives on the current rep. 0 for bagreps
	*/
	CATULONG32			GetPrimitiveCount() const;

	/**
	Creates a sub transaction to access a primitive
	*/
	HRESULT	CreatePrimitiveReadOnlyTransaction(CATSGPrimitiveReadOnlyTransaction *& oTrx, CATULONG32 iPrimIndex);

	HRESULT ClosePrimitiveTransaction(CATSGPrimitiveReadOnlyTransaction *& oTrx);
	/**
	Returns a primitive from the current rep
	*/
	CATGraphicPrimitive * GetPrimitive(CATULONG32 iPos) const;

	/**
	Returns a VisPrimitive from the current rep
	*/
	VisPrimitive *		GetVisPrimitive(CATULONG32 iPos) const;

	/** @return TRUE is the current node is a CAT2DBagRep */
	CATBoolean  IsCurrentACAT2DBagRep() const;

	/** @return TRUE is the current node is a CAT2DCustomRep */
	CATBoolean  IsCurrentACAT2DCustomRep() const;

	/** @return TRUE is the current node is a CAT2DTo3DRep */
	CATBoolean  IsCurrentACAT2DTo3DRep() const;

	/** @return TRUE is the current node is a CAT3DBagRep */
	CATBoolean  IsCurrentACAT3DBagRep() const;

	/** @return TRUE is the current node is a CAT3DFilterBagRep */
	CATBoolean  IsCurrentACAT3DFilterBagRep() const;

	/** @return TRUE is the current node is a CAT3DSemanticBagRep */
	CATBoolean  IsCurrentACAT3DSemanticBagRep() const;

	/** @return TRUE is the current node is a CAT3DBagRepWithToleranceScale */
	CATBoolean  IsCurrentACAT3DBagRepWithToleranceScale() const;

	/** @return TRUE is the current node is a CATSurfacicRep */
	CATBoolean  IsCurrentACATSurfacicRep() const;

	/** @return TRUE is the current node is a CAT3DCustomRep */
	CATBoolean  IsCurrentACAT3DCustomRep() const;

	/** @return TRUE is the current node is a CATMonoWireRep */
	CATBoolean  IsCurrentACATMonoWireRep() const;

	/** @return TRUE is the current node is a CAT3DCurveRep */
	CATBoolean  IsCurrentACAT3DCurveRep() const;

	/** @return TRUE is the current node is a CAT3DLineRep */
	CATBoolean  IsCurrentACAT3DLineRep() const;

	/** @return TRUE is the current node is a CAT3DPlanRep */
	CATBoolean  IsCurrentACAT3DPlanRep() const;

	/** @return TRUE is the current node is a CAT3DPointRep */
	CATBoolean  IsCurrentACAT3DPointRep() const;

	/** @return TRUE is the current node is a CAT3DAxisRep */
	CATBoolean  IsCurrentACAT3DAxisRep() const;

	/** @return TRUE is the current node is a CAT3DCylinderRep */
	CATBoolean  IsCurrentACAT3DCylinderRep() const;

	/** @return TRUE is the current node is a CAT3DCurvedPipeRep */
	CATBoolean  IsCurrentACAT3DCurvedPipeRep() const;

	/** @return TRUE is the current node is a CAT3DGeomRep */
	CATBoolean  IsCurrentACAT3DGeomRep() const;

	/** @return TRUE is the current node is a CAT3DPointCloudRep */
	CATBoolean  IsCurrentACAT3DPointCloudRep() const;

	/** @return TRUE is the current node is a CAT3DCanonicalRep */
	CATBoolean  IsCurrentACAT3DCanonicalRep() const;

	/** @return the rep dimention (0 for a point, 1 for a line, 2 for a surface, 3 for a solid, -1 if not applicable) */
	CATLONG		GetRepDimension() const;

private:
	// all ctor/dtor are private: this cannot be instanciated by anything but a CATSceneGraphImpl
	CATSGReadOnlyTransaction();
	CATSGReadOnlyTransaction(CATSceneGraphImpl * iSG);
	CATSGReadOnlyTransaction(const CATSGTransaction &);
	virtual ~CATSGReadOnlyTransaction();

	friend class CATSceneGraphImpl;
	friend class CATSGReadWriteTransaction;

	CATSGReadOnlyTransactionImpl * _Impl;

};
