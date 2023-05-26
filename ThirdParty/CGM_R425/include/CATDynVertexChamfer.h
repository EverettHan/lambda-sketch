#ifndef CATDynVertexChamfer_H
#define CATDynVertexChamfer_H

#include "CATDynOperator.h"
#include "CATTopDefine.h"
#include "CATCGMVirtualMetaClass.h"
#include "CATTopData.h"
#include "ListPOfCATEdge.h"
#include "CATListOfDouble.h"

class CATGeoFactory;
class CATBody;
class CATVertex;


class ExportedByBODYNOPE CATDynVertexChamfer : public CATDynOperator
{
	CATCGMVirtualDeclareClass(CATDynVertexChamfer);
public:
	/**
* @nodoc
* Virtual constructor of a CATDynVertexChamfer operator.<br>
* Cannot be called. Use the <tt>CATDynVertexChamfer </tt> global function
* to create a CATDynVertexChamfer operator.
*/
	CATDynVertexChamfer (CATGeoFactory* iContainer,
											 CATTopData*		iData);
	virtual ~CATDynVertexChamfer();

	// CPT: impact on SWx!!!
	virtual void SetVertex(CATVertex* iVertex) = 0;
	virtual void SetEdges(ListPOfCATEdge& iEdges) = 0;
	virtual void SetSetbacks(double* iSetbacks) = 0;
  
	virtual void Append (CATVertex * iVertex, const ListPOfCATEdge & iEdges, const CATListOfDouble & iSetbacks) = 0;
  virtual void SetPrevisualizationOnly () = 0;
};

ExportedByBODYNOPE CATDynVertexChamfer* CATCreateDynVertexChamfer (CATGeoFactory* iContainer,
																																	 CATTopData*		iData,
																																	 CATBody*				iPart);


ExportedByBODYNOPE CATDynVertexChamfer* CATCreateDynVertexChamfer (CATGeoFactory*					iContainer,
																																	 CATTopData*						iData,
																																	 CATBody*								iPart,
																																	 CATVertex*							iVertex,
																																	 const ListPOfCATEdge&	iEdges,
																																	 const CATListOfDouble& iSetbacks);

#endif
