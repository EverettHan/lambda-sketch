#ifndef CATTopUntrimOperator_h
#define CATTopUntrimOperator_h

#include "CATTopOperator.h"
#include "BasicTopology.h"

class CATBody;
class CATTopUntrimOperatorExt;
class CATString;
class CATGeoFactory;
class CATTopData;
class CATExtTopOperator;
class CATTopUntrimContextForFastRun;

/**
* Class defining an operator to untrim a surface or a curve.
*
* Create it using <tt>CATCreateTopUntrimOperator</tt> function (see comments of that function on how to use it).
* Execute it by calling <tt>Run</tt> method, and get the result via <tt>GetResult</tt>.
*/
class ExportedByBasicTopology CATTopUntrimOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopUntrimOperator);

public:

  /**
  * @nodoc @nocgmitf
  */
  virtual ~CATTopUntrimOperator();

  /**
  * @nodoc
  * Return the fastrun context if it exists, otherwise create it.
  * @return [out, CATBaseUnknown#Release]
  */
  CATTopUntrimContextForFastRun * GetOrCreateTopUntrimContextForFastRun();

  /**
  * @nodoc
  * Return the fastrun context if it exists.
  * @return [out, CATBaseUnknown#Release]
  */
  CATTopUntrimContextForFastRun * GetNoCreateTopUntrimContextForFastRun();

  /**
  * @nodoc @nocgmitf
  * To be called after Run.
  * Returns the untrimmed body.
  */
  virtual CATBody * GetResult();

  /**
  * @nodoc
  * To be called after Run.
  * If the operation is impossible, returns a value different from 0.
  *
  * If the input body contains cells which are not all on the same support, returns 1, and <tt>GetResult</tt> will return NULL.
  */
  CATLONG32 GetErrorCode();

  /**
  * @nodoc
  * To be called after Run.
  * If the input surface is twisted, returns TRUE.
  * In this case the call to <tt>GetResult</tt> will return a body built
  * using the 2D bounding box of the input face(s).
  */
  CATBoolean GetIsTwisted();

  /**
  * @nodoc
  * To be called before Run.
  * Desextrapolation before the untrim
  */
  void SetDesextrapolation(CATBoolean iDesextrapolation, CATBoolean iUseOriginalLimits);

  /**
  * @nodoc @nocgmitf
  * Creates a CATTopUntrimOperator from a CATTopUntrimOperatorExt.
  * INTERNAL USE ONLY.
  */
  static CATTopUntrimOperator * Create(CATTopUntrimOperatorExt & iExtensible);

  /**
  * @nodoc @nocgmitf
  * Returns the ID of the operator.
  */
  virtual const CATString * GetOperatorId();

  /**
  * @nodoc @nocgmitf
  * INTERNAL USE ONLY.
  */
  CATTopUntrimOperatorExt & GetTopUntrimOperatorExt();

  /**
  * @nodoc @nocgmitf
  * INTERNAL USE ONLY.
  */
  CATBody * GetBodyToBeUntrimmed();

  /**
  * @nodoc @nocgmitf
  * INTERNAL USE ONLY.
  */
  void GetCellsForUntrim(CATListPtrCATCell & oCellsForUntrim);

  /**
  * @nodoc @nocgmitf
  * INTERNAL USE ONLY.
  */
  void SetInputs(CATBody * iBodyToBeUntrimmed, CATListPtrCATCell * iListOfCells);

protected:

  CATTopUntrimOperator(CATGeoFactory * iFactory, CATTopData * iTopData, CATExtTopOperator * iExtensible);
  virtual int RunOperator();

  virtual void RequireDefinitionOfInputAndOutputObjects();
};

/**
* @nodoc
* Creates an untrim operator.
*
* @param iFactory
*   The geometrical factory.
* @param iConfig
*   The software configuration.
* @param iBodyToBeUntrimmed
*   The input body. It must be a 2D or 1D body, whose cells are all on the same support.
* @param iListOfCells
*   In the case of a 2D body only, to perform a partial untrim.
*   If the list is specified, for each edge of the list we test if it is able to cut in 2 the result of global untrim.
*   If it is true for all edges of the list, then we build the result face using the non-selected edges + the extra parts associated to each selected edge.
* @param iJournal
*   The topological journal, that will be filled by the operator.
*   Example of the final journal in the case of a 2D body:
*     [] -Creation -> [F_755] Info=1
*     [] -Creation -> [E_759] Info=2
*     [] -Creation -> [E_765] Info=3
*     [] -Creation -> [E_771] Info=4
*     [] -Creation -> [E_777] Info=5
*/
ExportedByBasicTopology CATTopUntrimOperator * CATCreateTopUntrimOperator(
  CATGeoFactory & iFactory,
  CATSoftwareConfiguration & iConfig,
  CATBody * iBodyToBeUntrimmed,
  CATListPtrCATCell * iListOfCells,
  CATCGMJournalList * iJournal);

#endif
