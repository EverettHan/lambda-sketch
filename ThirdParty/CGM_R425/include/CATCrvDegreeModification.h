#ifndef CATCrvDegreeModification_H
#define CATCrvDegreeModification_H

// COPYRIGHT DASSAULT SYSTEMES  2001

/**
 * @level Protected
 * @usage U1
 */

#include "CATIACGMLevel.h"

#include "FrFOpeCrv.h"

#include "CreateCrvDegreeModification.h"
#include "CATCGMVirtual.h"

/**
 * Class defining an operator that modifies the degree of a curve.
 * The CATCrvDegreeModification operator follows the global frame of the geometric operators: 
 *<ul>
 * <li>A CATCrvDegreeModification operator is created with the <tt>CreateCrvDegreeModification</tt> global function 
 * and must be directly deleted with the usual C++ <tt>delete</tt> operator after use.
 * It is is not streamable. 
 *<li>In case of <tt>BASIC</tt> mode,
 * the operation is automatically performed at the operator creation. 
 * In case of <tt>ADVANCED</tt> mode,
 * options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *</ul>
 */

class ExportedByFrFOpeCrv CATCrvDegreeModification : public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATCrvDegreeModification);
  public :
   /** 
   * Destructor. 
   */
  virtual ~CATCrvDegreeModification();
   /** 
   * Runs <tt>this</tt> operator. 
   */
  virtual void Run()=0;
   /**
   * Specifies the new degree.
   * @param iNewDegree
   * The new degree.
   */
  virtual void SetDegree(const CATLONG32 &iNewDegree)=0;
  /**
  * Returns the maximum deviation between the initial and the new curve. 
  * This method should be used when decreasing the degree.
  * @return
  * The maximum deviation value.
  */
  virtual double GetMaxDeviation()=0;
  /**
  * @nodoc
  * Returns the new degree. 
  * This method should be used when decreasing the degree
  * with a given tolerance.
  * @return
  * The new degree.
  */
  virtual CATLONG32 GetNewDegree()=0;
 /**
  * @nodoc
  * Sets a new tolerance. 
  * This method should be used when decreasing the degree
  * with a given tolerance.
  * @param iTolerance
  * The new tolerance.
  */
  virtual void SetTolerance(const double iTolerance)=0;

 /**
  * @nodoc
  * Imposes a given continuity at the curve extremities. Authorized values
  * are 0,1,2 for G0, G1 and G2 continuities. Default value is 0.
  * This method should be used when decreasing the degree
  * with a given tolerance.
  * @param iStartContinuity
  * The continuity at the start extremity.
  * @param iEndContinuity
  * The continuity at the end extremity.
  */
  virtual void SetContinuityAtEnds(CATLONG32 iStartContinuity,CATLONG32 iEndContinuity)=0;  
};

#endif
