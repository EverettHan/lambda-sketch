#ifndef CATGeometrySizeOptimization_H
#define CATGeometrySizeOptimization_H

// COPYRIGHT DASSAULT SYSTEMES  2006

/**
* @level Protected
* @usage U1
*/ 

#include "GeometrySizeOptimization.h"
#include "CATTopOperator.h"

/**
 * Class defining the operator that optimizes the size of a factory
 * by cleaning extrapolated geometries.
 */
class ExportedByGeometrySizeOptimization CATGeometrySizeOptimization : public CATTopOperator
{
   CATCGMVirtualDeclareClass(CATGeometrySizeOptimization);
public:

   /**
   * @nodoc
   * Do not use. Use the <tt>CATCreateGeometrySizeOptimization</tt> global function
   * to create a CATGeometrySizeOptimization operator.
   */
                                  CATGeometrySizeOptimization(   CATGeoFactory           *  iFactory                  ,
                                                                 CATTopData              *  iTopData                  );

   /**
   * Cleans the NURBS objects without keeping the original limits (only the useful limits will be kept).
   * <tt>Warning<tt> : This mode is not reversible, you may loose original creation data. 
   */
         void                     SetForgetNURBSOriginalLimits();

   /**
   * Runs <tt>this</tt> operator.
   * @return
   * <tt>1</tt> if the computation failed, <tt>0</tt> otherwise.
   */
         int                      Run                      ();

   /**
   * Returns the diagnosis of the computation.
   * @return
   * The diagnosis of the computation.<br>
   * <tt>0</tt> : Geometry has not been modified<br>
   * <tt>1</tt> : Geometry has been modified (write required).
   */
         int                      GetDiagnosis             ();

   /**
   * Destructor.
   */
  virtual                        ~CATGeometrySizeOptimization();

   //KY1 : 10-12-2010
public:
   /**   @nodoc @nocgmitf */ 
   static const  CATString      * GetDefaultOperatorId     ();

   //KY1 : 10-12-2010
protected:
   /**   @nodoc @nocgmitf */
         int                      RunOperator();
   /**   @nodoc @nocgmitf */
   const  CATString             * GetOperatorId();
   /**  @nodoc @nocgmitf */
          void                    RequireDefinitionOfInputAndOutputObjects();

protected:
   static  CATString  _OperatorId;

private:
           CATBoolean _ForgetNURBSOriginalLimits;
           int        _Diagnosis;
};

/**
* Creates a CATGeometrySizeOptimization operator.
* @param iFactory
* The pointer to the factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration. 
* @return
* The pointer to the created operator. To delete with the usual <tt>delete</tt> C++ operator.
*/
ExportedByGeometrySizeOptimization CATGeometrySizeOptimization *
CATCreateGeometrySizeOptimization( CATGeoFactory * iFactory, 
                                   CATTopData    * iTopData);

#endif
