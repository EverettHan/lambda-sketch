#ifndef CATTopRelimitBody_h
#define CATTopRelimitBody_h

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * Not yet CAA
 */ 

#include "BONEWOPE.h"
#include "CATTopOperator.h"
#include "CATCGMVirtualMacros.h"
#include "ListPOfCATFace.h"
#include "CATDynOperatorDef.h"
#include "CATBoolean.h"

class CATGeoFactory;
class CATTopData;
class CATExtTopOperator;
class CATBody;
class CATCell;
class CATExtCGMReplay;
class CATCGMStream;
class CATString;
class CATCGMOutput;

/**
 * Class defining the operator which relimits a body,  by the given operand.
 * If the operand doesn't intersect the body being relimited, the returned result is the input body.
 * <br>
 * The <tt>CATTopRelimitBody</tt> operator follows the global frame of the topological operators 
 * and satisfies the smart mechanism: the input bodies are not modified. The resulting body is equal to 
 * the first input body, or is a new created body, possibly sharing data with the input bodies.
 * <ul>
 * <li>A <tt>CATTopRelimitBody</tt> operator is created with the <tt>CATCreateTopRelimitBody</tt>
 * global function: It must be directly deleted after use with the usual C++ <tt>delete</tt> operator. 
 * It is not streamable. 
 * <li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometry factory. 
 * </ul>
 */
class ExportedByBONEWOPE CATTopRelimitBody : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopRelimitBody);

public:
/**
 * Virtual constructor of a <tt>CATTopRelimitBody</tt> operator.<br>
 * Do not call this constructor, instead use the <tt>CATCreateTopRelimitBody</tt> global function
 * to create a CATTopRelimitBody operator.
 */
  CATTopRelimitBody(CATGeoFactory     * ipFactory   ,
                              CATTopData        * ipTopData   ,
                              CATExtTopOperator * ipExtensible);
/**
 * Destructor.
 */
  virtual ~CATTopRelimitBody();

  /** @nodoc */
  void SetNoSimplif(CATBoolean iNoSimplif);

  /** @nodoc @nocgmitf : CATCGMReplay */
  static const CATString * GetDefaultOperatorId() { return &_OperatorId; }

protected :

  /** @nodoc @nocgmitf */
  int RunOperator();  

  /** @nodoc @nocgmitf : CATCGMReplay */
  const CATString * GetOperatorId() { return &_OperatorId; }

  /** @nodoc @nocgmitf : CATCGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();

#ifdef CATIAR420   
  // Hybrid Management
  // Exact only
  virtual int RunExactOperator();
  // With Polyhedral data
  virtual int RunPolyOperator();
#endif

private:

  /** @nodoc @nocgmitf */
  static CATString _OperatorId;
};

/**

 * Creates a <tt>CATTopRelimitBody</tt> operator.
 * @param ipFactory
 * The factory of the geometry. 
 * @param ipTopData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>ipTopData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iTrimmingBody
 * The pointer to the input body to trim to.
 * @param iRelimitedBody
 * The pointer to the body relimited by the trimming body.
 * @param iSideToKeep
 * The side to keep 
 * <br><b>Legal values</b>:
 * <dl><dt>1</dt><dd> The left side is kept
 * <dt>-1</dt><dd>The right side is kept
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByBONEWOPE
CATTopRelimitBody * CATCreateTopRelimitBody(CATGeoFactory * ipFactory    ,
                                            CATTopData    * ipTopData    ,                                  
                                            CATBody       * iTrimmingBody,
                                            CATBody       * iRelimitedBody ,
                                            int             iSideToKeep);


#endif
