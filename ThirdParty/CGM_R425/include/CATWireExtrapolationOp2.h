#ifndef CATWireExtrapolationOp2_h
#define CATWireExtrapolationOp2_h

// COPYRIGHT DASSAULT SYSTEMES 2004


#include "WireExtrapol.h"
#include "CATTopOperator.h"


class CATBody;
class CATVertex;
class CATWireExtrapolationOpImpl;
class CATPlane;

/**
 * Class defining the extrapolation operator on a wire body.
 * The same than CATWireExtrapolationOp (CAA) with more option:
 *                 -define a support for extrapolation G2 on support 
 *                  (only on faces with same geometry)
 *                 -define upto body for extrapolation upto
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateWireExtrapolationOp2</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. 
 * <li>Run it
 * <li>Get the resulting GetResult method. If you do not want 
 * to keep these resulting body, use the @href CATICGMContainer#Remove method to remove them from the 
 * geometric factory, after the operator deletion.
 *<li><tt>delete</tt> it after use  with the usual C++ delete operator.
 */
#include "CATIACGMLevel.h"
#ifdef CATIACGMV5R22
class CATWireExtrapolationOp2 : public CATTopOperator
#else
class ExportedByWireExtrapol CATWireExtrapolationOp2 : public CATTopOperator
#endif
{
public:
  /** @nodoc */
  CATWireExtrapolationOp2(CATGeoFactory * iFacto,CATTopData * iTopData,CATBody * iBodyToExtrapolate,CATBody * iBodySupport=NULL );

  virtual ~CATWireExtrapolationOp2();
    
  /** 
  * Set extrapolation length for specified vertex.
  * @param iVertex
  * The vertex to be extrapolated.
  * @param iLength
  * The extrapolation length.
  */
  void SetExtrapolation( CATVertex * iVertex, double iLength );

  /** 
  * Set up to plane for specified vertex.
  * @param iVertex
  * The vertex to be extrapolated.
  * @param iPlane
  * The plane to reach.
  */
  void SetExtrapolation( CATVertex * iVertex, CATPlane * iPlane );

  /** @nodoc */
  void SetWireTarget( CATBody * iTargetBody );

 /** @nodoc */
  void SetVersionNumber( CATLONG32 iVersionNumber );

/** 
 * Runs <tt>this</tt> CATWireExtrapolationOp2.
 */
  int Run();
  
/**
 * Returns a pointer to the resulting CATBody of <tt>this</tt> CATWireExtrapolationOp.
 * <br> Must be called after the <tt>Run</tt> method.
 */
  CATBody * GetResult();


  private :
    CATWireExtrapolationOpImpl  * _Implementation;

};
/**
 * Creates a CATWireExtrapolationOp operator.
 * @param iFactory
 * The pointer to the geometry factory.
 * @param iTopData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iBodyToExtrapolate
 * The pointer to the wire body to be extrapolated.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator after use.
 */

#ifdef CATIACGMV5R22
CATWireExtrapolationOp2 * CATCreateWireExtrapolationOp2( 
#else
ExportedByWireExtrapol CATWireExtrapolationOp2 * CATCreateWireExtrapolationOp2( 
#endif
                               CATGeoFactory * iFactory,
						                   CATTopData    * iTopData,
                               CATBody       * iBodyToExtrapolate,
                               CATBody       * BodySupport=NULL);

#endif
