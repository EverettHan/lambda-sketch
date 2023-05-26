#ifndef CATTopCurveOperator_h
#define CATTopCurveOperator_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @required Protected
 * @usage U1
 */ 

#include "CATIAV5Level.h"
#include "CATIACGMLevel.h" 

#include "BasicTopology.h"
#ifdef CATIACGMR215CAA
#include "CATTopMultiResult.h"
#else
#include "CATTopOperator.h"
#endif

class CATCGMODTScaleManager;
/**
 * Abstract class of the topological operators that creates 
 * 1D bodies from geometry.
 * The curve can lie on a support, defined as an unique shell domain
 * of a body.
 */
#ifdef CATIACGMR215CAA
class ExportedByBasicTopology CATTopCurveOperator :public CATTopMultiResult
#else
class ExportedByBasicTopology CATTopCurveOperator :public CATTopOperator
#endif
{
//-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATTopCurveOperator);
public:
//-------------------------------------------------------------------

/**
 * @nodoc
 */
  CATTopCurveOperator(CATGeoFactory* iFactory, CATTopData* iData);
/**
 * @nodoc
 * Deprecated
 */
  CATTopCurveOperator(CATGeoFactory* iFactory, CATCGMJournalList* ioJournal=0);

  virtual ~CATTopCurveOperator();


/** 
 * Sets whether the curve is closed.
 * @param iClosed
 * The closure of the curve:
 * <b>Legal values</b>:
 *<dl><dt>2</dt><dd> for a closed curve with C2 Curvature respect on the closure</dd>
 *    <dt>1</dt><dd> for a closed curve</dd>
 *    <dt>0</dt><dd> for an open curve</dd>
 *</dl>
 * @return
 * 0 if the closure is compatible with the geometry, 
 * positive otherwise (in case of a closure setting for a line) 
 */
 virtual CATLONG32 SetClosure(CATLONG32 iClosed);  
                                
/**
 * Sets the support of the curve.
 * @param iSupport
 * The body containing an unique shell domain. This shell domain is
 * the support of the curve.
 */
 virtual CATLONG32 SetSupport(CATBody * iSupport); 

 
/**
 * Retrieves the closure of the curve.
 * @param ioClosed
  * The closure of the curve:
 * <b>Legal values</b>:
 *<dl><dt>1</dt><dd> for a closed curve</dd>
 *    <dt>0</dt><dd> for an open curve</dd>
 *</dl>
 */
 virtual CATLONG32 GetClosure(CATLONG32 &ioClosed); 

/**
 * Retrieves the support of the curve.
 * @param ioSupport
 * The body containing an unique shell domain, if the curve
 * has a support. NULL otherwise. 
 *
*/
 virtual CATLONG32 GetSupport(CATBody *& ioSupport); 

/**
 * @nodoc @nocgmitf CGMReplay
 */
  static void LoadInOutput(CATCGMStream& ioStream, 
     CATGeoFactory*          &iFactory,
     CATTopData              &ioTopData,
     CATBodyFreezeMode       &iFreezeMode,
     CATLONG32                    &iClosed,
     CATLISTP(CATICGMObject) &ioInputCopy,
     CATLISTP(CATICGMObject) &ioInputNoCopy, 
     CATBody*                &ioOutputBody,
     CATBody*                &ioSupport,
     CATLISTP(CATICGMObject) *ioInputNeutral = NULL,
     CATCGMODTScaleManager   *ioODTScaleManager = NULL);

protected :

/**
 * @nodoc CGMReplay
 */
  void RequireDefinitionOfIOObjectsTopCurve();

/**
 * @nodoc CGMReplay
 */
  void WriteInputTopCurve(CATCGMStream &Str);

/**
 * @nodoc CGMReplay
 */
  void DumpTopCurve(CATCGMOutput& os);

  CATBody * _Support;
  CATLONG32 _Closed;

};

#endif
