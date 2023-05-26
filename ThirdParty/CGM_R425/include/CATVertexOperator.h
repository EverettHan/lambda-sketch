#ifndef CATVertexOperator_h
#define CATVertexOperator_h

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "CATTopVertex.h"

class CATDomain;
class CATVertex;
class CATLoop;
class CATVertex;
class CATPoint;
class CATSurface;
class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
class CATVertexOperatorExt;

/** 
 * Deprecated. Use now @href CATTopPointOperator .
* Class representing the operator that creates a point body from one point. 
* <br>To use the CATVertexOperator:
* <ul><li>Create it with the available constructor. 
* <li>If needed, tune some parameters with the <tt>SetXxx</tt> methods.
* <li> <tt>Run</tt> the operator
* <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
* <li><tt>delete</tt> the operator after use.
* </ul>
*/

class ExportedByPrimitivesLight CATVertexOperator :public CATTopVertex
{
  CATCGMVirtualDeclareClass(CATVertexOperator);
public:
 /** @nodoc */
  CATVertexOperator(CATGeoFactory*	iFactory,
		    CATPoint*	    	iPoint,
		    CATBody*          	iTargetBody=NULL,
		    CATBodyFreezeMode   iBodyfreezemode=CATBodyFreezeOn,
		    CATCGMJournalList*	iReport=NULL);
/**
	* Creates an operator to build a point body from one point.
	* @param iFactory
	* The pointer to the factory of the geometry.
	* @param iPoint
	* The pointer to the point used to define the vertex.
	*/
  CATVertexOperator(CATGeoFactory*	iFactory,
		CATTopData * iData,
		    CATPoint*	    	iPoint);
  
  ~CATVertexOperator();

/**
 * Runs <tt>this</tt> operator.
 */
  int Run();
  /* @nodoc @nocgmitf */
  int RunOperator();

 /**
	* Returns the pointer to the vertex of the resulting body.
	* @return
	* The pointer to the vertex of the resulting body. Remember that the whole body is retrieved with
	* the <tt>GetResult</tt> method, and you must manage its deletion if you do not want to keep it.
	*/ 
  CATVertex*     GetVertex() const;

  //***************************************************************************************
  // CGMReplay
  //***************************************************************************************

public:

  /* @nodoc @nocgmitf */
  static const CATString *GetDefaultOperatorId() { return &_OperatorId; }

protected:

  const  CATString  *GetOperatorId();
  CATExtCGMReplay   *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);
  void               RequireDefinitionOfInputAndOutputObjects();

  static CATString   _OperatorId;

  //***************************************************************************************

private:

  /**  @nodoc @nocgmitf */
  CATVertexOperatorExt & GetVertexOperatorExt() const;
};



#endif
