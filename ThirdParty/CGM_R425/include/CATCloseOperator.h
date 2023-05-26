#ifndef CATCloseOperator_h
#define CATCloseOperator_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @level Protected
* @usage U1
*/

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATDynOperator.h"
#include "CATTopOperator.h"
#include "Thick.h"
#include "ListPOfCATBody.h"

class CATBody;
class CATCGMJournalList;
class CATCloseOperatorImp;

/**
 * Class representing the operator that closes a skin body.
 * If the body is a closed shell (set of faces), it simply creates a volume body out of it. 
 * If it is an open shell, it will try to close it with as many planar faces as possible.
 * <br>The close operator can not create new edges. For instance, trying to
 * close a half-cylinder surface face will fail, because, even if it may
 * be closed by three planes, two new edges need to be created (at the
 * intersection of those planes).
 * <br>To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateCloseOperator</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. 
 * <li>Run it
 * <li>Get the resulting GetResult method. If you do not want 
 * to keep these resulting body, use the @href CATICGMContainer#Remove method to remove them from the 
 * geometric factory, after the operator deletion.
 *<li><tt>delete</tt> it after use  with the usual C++ delete operator.
 *</ul> 
 */
class ExportedByThick CATCloseOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATCloseOperator);
public:
  /** @nodoc */
  CATCloseOperator(CATGeoFactory    * iFactory, 
                   CATBody          * iBodyToClose, 
                   CATCGMJournalList* iReport=0);

   /** @nodoc */
  CATCloseOperator(CATGeoFactory    * iFactory, 
                   CATBody          * iBodyToClose, 
                   CATTopData       * iTopData );

  // Destructor
  ~CATCloseOperator();
  
  /** 
   * Asks for a boolean operation with the output of the operator
   * (the so called closed skin) and <tt>iOperandBody</tt>.
   * @param iReport
   * The pointer to the journal to fill, if not <tt>NULL</tt>.
   * It can be different from the operator journal given in CATTopData.
  */
  void SetBooleanOperation(CATDynBooleanType   iOpType, 
                           CATBody           * iOperandBody, 
                           CATCGMJournalList * iReport=0);

  /**
   * Runs the operator.
   * @return
   * <br><b>Legal values</b>: <tt>0</tt> if ok, <tt>1</tt> if failed
   */
  int Run();

  /**
   * Returns the resulting body of the closure operation.
   * @return
   * The pointer to the created body.If you do not want 
   * to keep these resulting body, use the @href CATICGMContainer#Remove method to remove them from the 
   * geometric factory, after the operator deletion.
   */
  CATBody * GetResult();

  /**
	 * Returns the body created from the Boolean operation between a given body and the thickened body.
	 * @return
	 * The pointer to the Boolean result.
	 * If you do not want to keep the resulting body, 
     * use the @href CATICGMContainer#Remove method to remove it from the 
     * geometric factory, after the operator deletion.
	 */
  CATBody * GetBooleanResult();

  // Set a tolerance for closing plane creation, and curve merge. This
  // tolerance may not be smaller than modeler resolution, which is the
  // default value.
  /**  @nodoc */
  void SetTolerance( double iTolerance );
 
  /** 
   * Give the list of input profile bodies used for input body generation
   * This service is usefull in case of Loft operation to retrieve underlying plane of body
   * ( topological model and size simplification )
   * Special mode available to search for any type of closing surface under profiles edges
   * (restricted use)
  */
  /**  @nodoc */
  void SetInputProfileBodiesList( CATLISTP(CATBody) & iInputProfileBodiesList,
                                  int iSearchForAnyTypeOfSurface=0 );

#if  defined  (  CATIACGMV5R21  )
	//KY1 : 10-12-2010
public:
	/**	@nodoc */ 
	static const  CATString  *GetDefaultOperatorId();
#endif

#if  defined  (  CATIACGMV5R21  )
	//KY1 : 10-12-2010
	/**	@nodoc @nocgmitf */
	int RunOperator();
	/**	@nodoc @nocgmitf */
	//static  CATString  _OperatorId; // Voir ds CATCloseOperatorImpl
	/**	@nodoc @nocgmitf */
	const  CATString  *GetOperatorId();
protected:
	/**  @nodoc @nocgmitf */
	void   RequireDefinitionOfInputAndOutputObjects();
#endif

protected:
  /**  @nodoc */
  CATCloseOperatorImp * _implementation;
};

/**
 * Creates an operator that closes a skin body.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iBodyToClose
 * The pointer to the skin body to close.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator after use.
 */
ExportedByThick CATCloseOperator * CATCreateCloseOperator( CATGeoFactory * iFactory,
                                                           CATTopData    * iTopData, 
                                                           CATBody       * iBodyToClose );

#endif
