#ifndef CATWireExtrapolationOnSupport_h
#define CATWireExtrapolationOnSupport_h

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "WireExtrapol.h"
#include "CATTopOperator.h"


class CATBody;
class CATVertex;
class CATWireExtrapolationOpImpl;

/**
 * Class defining the extrapolation operator on a wire body on a shell body.
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateWireExtrapolationOpOnShell</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. 
 * <li>Run it
 * <li>Get the resulting GetResult method. If you do not want 
 * to keep these resulting body, use the @href CATICGMContainer#Remove method to remove them from the 
 * geometric factory, after the operator deletion.
 *<li><tt>delete</tt> it after use  with the usual C++ delete operator.
 */
class ExportedByWireExtrapol CATWireExtrapolationOnSupport : public CATTopOperator
{
public:
  /** @nodoc */
  CATWireExtrapolationOnSupport(  CATGeoFactory * iFacto,CATTopData * iTopData ,CATBody * BodyToExtrapol,CATBody * BodySupport);

  virtual ~CATWireExtrapolationOnSupport();
    
/** 
 * Set extrapolation length for specified vertex.
  * @param iVertex
  * The vertex to be extrapolated.
  * @param iLength
  * The extrapolation length.
 */
  void SetExtrapolation( CATVertex * iVertex, double iLength );

  /** 
 * Set extrapolation length for specified vertex.
  * @param iVertex
  * The vertex to be extrapolated.
  * @param iLength
  * The extrapolation length.
 */
  void SetWireTarget( CATBody * iTargetBody );

 /** @nodoc */
  void SetVersionNumber( CATLONG32 iVersionNumber );

 /** @nodoc */
  void SetSoftwareConfiguration( CATSoftwareConfiguration * iNewConfig );

/** 
 * Runs <tt>this</tt> CATWireExtrapolationOp.
 */
  int Run();
  
/**
 * Returns a pointer to the resulting CATBody of <tt>this</tt> CATWireExtrapolationOp.
 * <br> Must be called after the <tt>Run</tt> method.
 */
  CATBody * GetResult();


/**   
 * Returns the freeze mode of <tt>this</tt> CATWireExtrapolationOp.
 * @return
 * <dl>
 * <dt>0</dt><dd>The resulting CATBody is not frozen: it can be modified afterwards.
 * <dt>1</dt><dd>The resulting CATBody is frozen: it cannot be modified afterwards.
 * </dl>
*/
 
  short GetFreezeMode() const;

  /**
   * Modifies the freeze mode of <tt>this</tt> CATWireExtrapolationOp.
   *<br> At the operator creation, the mode is set to 1.
   * @param iMode
   * <dl>
   * <dt>0</dt><dd>The resulting CATBody is not frozen: it can be modified afterwards.
   * <dt>1</dt><dd>The resulting CATBody is frozen: it cannot be modified afterwards.
   * </dl>
   */
  void  SetFreezeMode(short iMode=1);


  private :
    CATWireExtrapolationOpImpl  * _Implementation;

};

/**
 * Creates a CATWireExtrapolationOpOnShell operator.
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

ExportedByWireExtrapol CATWireExtrapolationOnSupport * CATCreateWireExtrapolationOnSupport( 
                               CATGeoFactory * iFactory,
						                   CATTopData    * iTopData,
                               CATBody       * iBodyToExtrapolate,
                               CATBody       * BodySupport);

#endif
