#ifndef CATExtrapolParallelTool_H
#define CATExtrapolParallelTool_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @level Protected
 * @usage U1
 */

//#include "Parallel.h"
#include "ParallelLight.h"
#include "CATTopDefine.h"
#include "CATTopData.h"
#include "CATDataType.h"
#include "CATCGMVirtual.h"

class CATBody;
class CATDistanceTool;
class CATICGMDistanceTool;
class CATGeoFactory;
class CATLaw;
class CATCGMJournalList;

//
//--------------------------------------------------------------------------
//
/**
 * Class defining the parallel computation.
 * <br>This class must be created with the @href CreateExtrapolParallelTool 
 * global function and is used by the @href CATTopParallel operator 
 * to define its parameters.
 */
class ExportedByParallelLight CATExtrapolParallelTool: public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATExtrapolParallelTool);
 public:
/**
 * @nodoc
 */
  CATExtrapolParallelTool(	CATGeoFactory * iGeoFactory, 
							CATTopData * iData,
							CATDistanceTool * iDist,
							CATBody * iSkinBody);

/**
 * @nodoc
 */
  CATExtrapolParallelTool(	CATGeoFactory * iGeoFactory,
							CATTopData * iData,
							CATICGMDistanceTool * iDist,
							CATBody * iSkinBody);

  virtual ~CATExtrapolParallelTool();


/** @nodoc */
  virtual int ComputeExtrapolationPar( CATBody * Wire[2], 
                     CATLaw ** MapLaw1, CATLaw** MapLaw2,
										 CATBody * Parallel[2], CATBody* Extrap[2],
										 CATCGMJournalList * Report, CATLONG32 WT[2])=0;
/** @nodoc */
  virtual int ComputeInMatter( CATBody * Wire, 
                     CATLaw ** MapLaw1, CATBody* PointToLocate,
										 double & Radius, double & MinDist);
    /**
     * Retrieves the type of computation.
     * @param oDistTool
     * The pointer to the definition of the computation type. 
     */
	void GetDistanceTool(CATDistanceTool *& oDistTool);
	
    /**
     * @nocgmitf
     * Retrieves the type of computation.
     * @param oDistTool [out, IUnknown#Release]
     * The pointer to the definition of the computation type.
     */
	void GetDistanceTool(CATICGMDistanceTool *& oDistTool);

    /**
     * Retrieves the factory that creates the resulting body.
     * @param oFactory
     * The pointer to the factory that creates the resulting body. 
     */
	void GetFactory(CATGeoFactory *& oFactory);
	
    /**
     * Retrieves the skin body on which the parallel is computed.
     * @param oSupport
     * The pointer to the skin body. 
     */
	void GetSupport(CATBody *& oSupport);
	
    /**
     * Retrieves the topological data associated with <tt>this</tt> tool.
     * @param oData
     * The pointer to the topological data.
     */
	void GetData (CATTopData *& oData);

    /**
     * Returns the relimitation type.
     * @return
     * The type of relimitation.
     * <br><b>Legal values</b>:
     * <dl><dt><tt>1</tt></dt><dd>Straight relimitation
     * <dt><tt>1</tt></dt><dd>Round relimitation
     * </dl>
     */
	virtual int GetExtrapInfo() = 0;

//#ifdef CATIACGMV5R22
   /** @nodoc */
   void SetReport(CATCGMJournalList *iJournal);
//#endif
 private :

		CATGeoFactory * _Factory;
		CATDistanceTool * _Distance;
		CATICGMDistanceTool * _IDistance;
		CATBody * _Support;
		CATTopData _Data;
};

/**
 * Creates a parallel computation definition.
 * @param iGeoFactory
 * The pointer to the geometry factory that creates the resulting body.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iDist
 * The type of computation (parallel, geodesic).
 * @param iSkinBody
 * The pointer to the skin body on which the parallel is computed.
 * @param iRelimitType
 * The type of relimitation.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>1</tt></dt><dd>Straight relimitation
 * <dt><tt>0</tt></dt><dd>Round relimitation
 * </dl>
 */
ExportedByParallelLight
CATExtrapolParallelTool * CreateExtrapolParallelTool (CATGeoFactory * iGeoFactory, 
						    						  CATTopData * iData,
                                                      CATDistanceTool * iDist,
													  CATBody * iSkinBody,
													  int iRelimitType = 1);

/**
 * @nocgmitf
 * Creates a parallel computation definition.
 * @param iGeoFactory
 * The pointer to the geometry factory that creates the resulting body.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iDist
 * The type of computation (parallel, geodesic).
 * @param iSkinBody
 * The pointer to the skin body on which the parallel is computed.
 * @param iRelimitType
 * The type of relimitation.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>1</tt></dt><dd>Straight relimitation
 * <dt><tt>0</tt></dt><dd>Round relimitation
 * </dl>
 */
ExportedByParallelLight
CATExtrapolParallelTool * CreateExtrapolParallelTool (CATGeoFactory * iGeoFactory,
                                                      CATTopData * iData,
                                                      CATICGMDistanceTool * iDist,
                                                      CATBody * iSkinBody,
                                                      int iRelimitType = 1);

#endif
