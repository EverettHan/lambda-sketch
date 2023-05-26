#ifndef CATSurDegreeModification_H
#define CATSurDegreeModification_H

// COPYRIGHT DASSAULT SYSTEMES  2001

/**
 * @level Protected
 * @usage U1
 */

#include "CreateSurDegreeModification.h"

#include "FrFOpeSur.h"
#include "CATIACGMLevel.h"

#include "CATCGMVirtual.h"

/**
 * Class defining an operator that modifies the degree of a Nurbs surface.
 * The CATSurDegreeModification operator follows the global frame of the geometric operators: 
 *<ul>
 * <li>A CATSurDegreeModification operator is created with 
 * the <tt>CreateSurDegreeModification</tt> global function 
 * and must be directly deleted with the usual C++ <tt>delete</tt> operator after use.
 * It is is not streamable. 
 *<li>In case of <tt>BASIC</tt> mode,
 * the operation is automatically performed at the operator creation. 
 * In case of <tt>ADVANCED</tt> mode,
 * options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *</ul>
 */

class ExportedByFrFOpeSur CATSurDegreeModification : public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATSurDegreeModification);
  public :
 /** 
   * Destructor. 
   */
  virtual ~CATSurDegreeModification();
 /** 
   * Runs <tt>this</tt> operator. 
   */
  virtual void Run()=0;
  /**
   * Specifies the new degree along U.
   * @param iNewDegreeU
   * The new degree along U.
   */
  virtual void SetDegreeU(const CATLONG32 &iNewDegreeU)=0;
 /**
   * Specifies the new degree along V.
   * @param iNewDegreeV
   * The new degree along V.
   */
  virtual void SetDegreeV(const CATLONG32 &iNewDegreeV)=0;
 /**
  * Returns the maximum deviation between the initial and the new surface. 
  * This method should be used when decreasing the degree.
  * @return
  * The maximum deviation value.
  */
  virtual double GetMaxDeviation()=0;
 /**
  * @nodoc
  * Returns the maximum degree along U statisfying the tolerance and/or the
  * target degree. 
  * This method should be used when decreasing the degree
  * with a given tolerance.
  * @return
  * The new degree along U.
  */

  virtual CATLONG32 GetNewDegreeU()=0;
  /**
  * @nodoc
  * Returns the maximum degree along V statisfying the tolerance and/or the
  * target degree. 
  * This method should be used when decreasing the degree
  * with a given tolerance.
  * @return
  * The new degree along V.
  */
  virtual CATLONG32 GetNewDegreeV()=0;
 /**
  * @nodoc
  * Sets a new tolerance. 
  * This method should be used when decreasing the degree
  * with a given tolerance.
  * @param iTolerance
  * The new tolerance.
  */
  virtual void SetTolerance (const double iTolerance)=0;


/**
  * @nodoc
  * Imposes a given continuity at the surface extremities. Authorized values
  * are 0,1,2 for G0, G1 and G2 continuities. Default value is 0.
  * This method should be used when decreasing the degree
  * with a given tolerance.
  * @param iStartContinuityU
  * The continuity at the start extremity along U.
  * @param iEndContinuityU
  * The continuity at the end extremity along U.
  * @param iStartContinuityV
  * The continuity at the start extremity along V.
  * @param iEndContinuityV
  * The continuity at the end extremity along V.
  */
  virtual void SetContinuityAtEnds(CATLONG32 iStartContinuityU,CATLONG32 iEndContinuityU,
                                   CATLONG32 iStartContinuityV,CATLONG32 iEndContinuityV)=0;  
};

#endif
