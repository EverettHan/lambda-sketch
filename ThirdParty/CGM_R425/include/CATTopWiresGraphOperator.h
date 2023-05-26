#ifndef CATTopWiresGraphOperator_h
#define CATTopWiresGraphOperator_h

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "Parallel.h"
#include "CATTopOperator.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATCGMJournalList;



/** 
* Deprecated. Use now @href CATTopWire .
* Class representing the operator that creates a wire body from one or several curves. 
* <br>To use the CATTopWiresGraphOperator:
* <ul><li>Create it with one of the available constructors. You must order the input curves and precise the
* limits of each, as well as their relative orientation, such that the end of
* one curve (possibly reversed) is the beginning of the following.
* <br>Every created edge is positively oriented in the wire. 
* <li>If needed, tune some parameters with the <tt>SetXxx</tt> methods.
* <li> <tt>Run</tt> the operator
* <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
* <li><tt>delete</tt> the operator after use.</ul>
* If there is only one closed curve, the operator creates a wire with two edges.
*/
class ExportedByParallel CATTopWiresGraphOperator :public CATTopOperator
{
public:
	CATTopWiresGraphOperator(CATGeoFactory      *iFactory,
		CATTopData * iData);
	
	~CATTopWiresGraphOperator();

	/**
	 * Runs <tt>this</tt> operator.
	 */
	virtual int Run()=0;

  virtual CATBody * GetResult()=0;

  virtual CATBody * GetResult(CATCGMJournalList * iJournal)=0;

  virtual int GetNbConnexion()=0;

  virtual CATBody * GetConnexBody(int iNumConnexPart)=0;

  virtual void GetFreeVerticesOfConnexPiece(int iNumConnexPart, CATLISTP(CATCell) & iVerticesList)=0;
	
};

ExportedByParallel CATTopWiresGraphOperator * 
CATCreateTopWiresGraphOperator(CATGeoFactory * iFacto, CATTopData * iData, CATBody * iBodyListOfWires);

#endif
