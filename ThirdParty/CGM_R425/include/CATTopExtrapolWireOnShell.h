// COPYRIGHT DASSAULT SYSTEMES  2002

#ifndef CATTopExtrapolWireOnShell_h
#define CATTopExtrapolWireOnShell_h

/**
* @level Protected
* @usage U1
*/

//------------------------------------------------------------------------------
#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATHybDef.h"
#include "HybOper.h"
#include "CATTopDef.h"
#include "CATTopOperator.h"

class CATString;

/**
* Class representing the operator that computes the extrapolation of a wire on a skin body.
* <br>The CATTopExtrapolWireOnShell operator follows the global frame of the topological operators
* and satisfies the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>A CATTopExtrapolWireOnShell operator is created with the <tt>CATCreateTopExtrapolWireOnShell</tt>
* global function.
* It must be directly deleted with the usual C++ <tt>delete</tt> operator after use. It is not streamable. 
*<li>The computation is done by the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory, after the operator deletion.
*</ul>
*/

class ExportedByHybOper CATTopExtrapolWireOnShell : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopExtrapolWireOnShell);
public:
  
  //  Constructor
  /** @nodoc */
  CATTopExtrapolWireOnShell( CATGeoFactory * iFactory, 
                             CATTopData    * iTopData, 
			                       CATBody       * BodyWire,
			                       CATBody       * BodyShell );
  //  Destructor.
  virtual ~CATTopExtrapolWireOnShell();     

  /**
    * Runs <tt>this</tt> operator.
    */
#if  defined  (  CATIACGMV5R21  )
	int RunOperator();
#else
  int Run();
#endif
  
  /**
    * Returns the pointer to the resulting body.
    * @return
    * The pointer to the resulting body. If you do not want to keep it, 
    * use the @href CATICGMContainer#Remove method to remove it from the 
    * geometric factory, after the operator deletion.
    */
  CATBody * GetResult();

#if  defined  (  CATIACGMV5R21  )
	 /**	@nodoc @nocgmitf */ 
   static const  CATString  *GetDefaultOperatorId();
#endif

protected:
#if  defined  (  CATIACGMV5R21  )
	//KY1 : 10-12-2010
	/**	@nodoc @nocgmitf */
	static  CATString  _OperatorId;
	/**	@nodoc */
	const  CATString  *GetOperatorId();
	 /**  @nodoc @nocgmitf */
  void   RequireDefinitionOfInputAndOutputObjects();
#endif

  /** @nodoc */
  CATBody*		             _WireBody;      // the  initial wire
  /** @nodoc */
  CATBody*		             _ShellBody;     // the shell
  /** @nodoc */
  CATBody*		             _ResultBody;    // the body containing the result
  /** @nodoc */
  CATLONG32                     _IsGetted;
  
};

/**
* Creates a CATExtrapolWireOnShell operator that computes the extrapolation of a wire on a shell.
* <b>Orientation</b>: The resulting wire is oriented as the input one.<br>
* @param iFactory
* The pointer to the factory of the resulting body.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled.
* @param iBodyWire
* The pointer to the body defining the wire to extrapolate. 
* @param iBodyShell
* The pointer to the body defining the support on which the input wire will be extrapolated.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/
ExportedByHybOper CATTopExtrapolWireOnShell * CATCreateTopExtrapolWireOnShell(
                            CATGeoFactory * iFactory, 
			                      CATTopData    * iTopData,
                            CATBody       * iBodyWire,
			                      CATBody       * iBodyShell);

#endif











