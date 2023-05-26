#ifndef CATExtrapolParallelTool2_H
#define CATExtrapolParallelTool2_H

// COPYRIGHT DASSAULT SYSTEMES 2003
#include "ParallelLight.h"
#include "CATExtrapolParallelTool.h"
#include "CATTopDefine.h"
#include "CATTopData.h"

class CATBody;
class CATDistanceTool;
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
class ExportedByParallelLight CATExtrapolParallelTool2 : public CATExtrapolParallelTool
{
  CATCGMVirtualDeclareClass(CATExtrapolParallelTool2);
 public:
/**
 * @nodoc
 */
  CATExtrapolParallelTool2(	CATGeoFactory * iGeoFactory, 
							CATTopData * iData,
							CATDistanceTool * iDist,
							CATBody * iSkinBody);

  CATExtrapolParallelTool2(	CATGeoFactory * iGeoFactory, 
    CATTopData * iData,
    CATICGMDistanceTool * iDist,
    CATBody * iSkinBody);

  virtual ~CATExtrapolParallelTool2();


/** @nodoc */
  virtual int ComputeExtrapolationPar( CATBody * Wire[2], 
                     CATLaw ** MapLaw1, CATLaw** MapLaw2,
										 CATBody * Parallel[2], CATBody* Extrap[2],
										 CATCGMJournalList * Report, CATLONG32 WT[2])=0;

   

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

	virtual CATLONG32 GetConnexionInfo() =0;

};
#endif
