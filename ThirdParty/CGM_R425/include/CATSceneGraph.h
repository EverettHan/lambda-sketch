#pragma once

#include "CATStdLib.h"
#include "SGInfra.h"

class CATRep;
class CATSceneGraphImpl;
class CATSGReadOnlyTransaction;
class CATSGReadWriteTransaction;
class CATSGVisuTransaction;
class CATSGTransaction;
class CATUnicodeString;
class CATSceneGraphIndex;
class CATSceneGraphMetaDataManager;
class CATVisScene;
class CATILockBytes2;

class ExportedBySGInfra CATSceneGraph
{
public:
	CATSceneGraph();
	virtual ~CATSceneGraph();

	// Attach the CATSceneGraph to a root rep. The lifecycle of this rep will be managed by the CATSceneGraph
	/** @nodoc */
	HRESULT AttachTo(CATRep * iRep);

	// Detach the CATSceneGraph from its root rep, and clears the associated index and the metadata. The lifecycle of this rep will no longer managed by the CATSceneGraph.
	// The method will fail if the passed rep is not the root rep of the scenegraph
	/** @nodoc */
	HRESULT DetachFrom(CATRep * iRep);

	/** @nodoc */
	CATRep * GetRootRep() const;

	/** @nodoc */
	HRESULT Clear();

	/** @nodoc */
	HRESULT CreateReadOnlyTransaction(CATSGReadOnlyTransaction * &ioTrx) const;
	/** @nodoc */
	HRESULT CreateReadWriteTransaction(CATSGReadWriteTransaction * &ioTrx);
	/** @nodoc */
	HRESULT CreateVisuTransaction(CATSGVisuTransaction * &ioTrx);
	/** @nodoc */
	HRESULT CloseTransaction(CATSGReadOnlyTransaction * &ioTrx) const;
	/** @nodoc */
	HRESULT CloseTransaction(CATSGReadWriteTransaction * &ioTrx);
	/** @nodoc */
	HRESULT CloseTransaction(CATSGVisuTransaction * &ioTrx);

	/** @nodoc */
	CATSceneGraphIndex*  GetIndex() const;
	/** @nodoc */
	CATSceneGraphMetaDataManager*	GetMetadataManager() const;
	/** @nodoc */
	CATVisScene* GetVisScene();

	/** @nodoc */
	CATSceneGraphImpl * GetImpl() const;

	/** no doc
	INTERNAL USAGE ONLY, DO NOT CALL WITHOUT ASKING SCENE GRAPH AND VISU TEAM!
	*/
	/** @nodoc */
	HRESULT LoadFromCGR(const CATUnicodeString & iPath);
	/** @nodoc */
	HRESULT SaveToCGR(const CATUnicodeString & iPath) const;
	/** @nodoc */
	HRESULT ImportFromFile(const CATUnicodeString & iPath);
	/** @nodoc */
	HRESULT ExportToFile(const CATUnicodeString & iPath) const;

private:	
	CATSceneGraph(const CATSceneGraph &);

	CATSceneGraphImpl * _Impl;
};
