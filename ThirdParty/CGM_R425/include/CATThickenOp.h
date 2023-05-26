#ifndef CATThickenOp_h
#define CATThickenOp_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 
#include "CATIACGMLevel.h"

#include "CATMathDef.h" 
#include "CATTopOperator.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATFace.h"
#include "AdvThickness.h"
#include "CATDynOperator.h"

class CATGeoFactory;
class CATBody;
class CATGeometry;
class CATThickenOpImpl;
class CATEdge;

/**
 * Class defining the topological operator that thickens a skin body into a volume body.
 * <br>A global offset value can be defined on the body, or faces to thicken can be individually chosen as well
 * as the corresponding offset values.
 *<br>
 * This operator follows the global frame of the topological operators 
 * and satisfies the smart mechanism: the
 * input body is not modified. A new resulting body is created, 
 * possibly sharing data with the input body. A CATThickenOp operator is not streamable.
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateThickenOp</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods.
 * <li>Run it
 * <li>Get the result with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 *<li>Delete it with the usual C++ <tt>delete</tt> operator after use.
 *</ul> 
 */  
class ExportedByAdvThickness CATThickenOp : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATThickenOp);
public:
/**
 * @nodoc 
 * Constructs an operator that thickens a skin body.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iBody
 * The pointer to the skin body to thicken.
 * @param iReport
 * A pointer to the journal. If <tt>NULL</tt>, the journal is not written.
 */
                             CATThickenOp                           (       CATGeoFactory            * iFactory                 ,
                                                                            CATBody                  * iBody                    ,
                                                                            CATCGMJournalList        * iReport                  );

    /**
     * @nodoc
     * Constructs an operator that thickens a skin body with a given offset value.
     * @param iFactory
     * The pointer to the factory of the geometry.
     * @param iBody
     * The pointer to the skin body to thicken.
     * @param iOffset
     * The value of the offset.
     * @param iReport
     * A pointer to the journal. If <tt>NULL</tt>, the journal is not written.
     */
                             CATThickenOp                           (       CATGeoFactory            * iFactory                 ,
                                                                            CATBody                  * iBody                    ,
                                                                            double                     iOffset                  ,
                                                                            CATCGMJournalList        * iReport                  );

    /**
     * @nodoc
     * Constructs an operator that thickens a skin body with inside and outside offset values.
     * @nodoc
     * @param iFactory
     * The pointer to the factory of the geometry.
     * @param iBody
     * The pointer to the skin body to thicken.
     * @param iOffset1
     * The smaller value of the offset in the side of the natural orientation of the skin.
     * @param iOffset2
     * The larger value of the offset in the side of the natural orientation of the skin.
     * @param iReport
     * A pointer to the journal. If <tt>NULL</tt>, the journal is not written.
     */
                             CATThickenOp                           (       CATGeoFactory            * iFactory                 ,
                                                                            CATBody                  * iBody                    ,
                                                                            double                     iOffset1                 ,
                                                                            double                     iOffset2                 ,
                                                                            CATCGMJournalList        * iReport                  );


    /**
     * @nodoc
     * Constructs an operator that thickens a skin body with inside and outside offset values.
     * @nodoc
     * @param iFactory
     * The pointer to the factory of the geometry.
     * @param iBody
     * The pointer to the skin body to thicken.
     * @param iOffset1
     * The smaller value of the offset in the side of the natural orientation of the skin.
     * @param iOffset2
     * The larger value of the offset in the side of the natural orientation of the skin.
     * @param iTopData
     * A pointer to the topological data (that contains the journal).
     */
                             CATThickenOp                           (       CATGeoFactory            * iFactory                 ,
                                                                            CATBody                  * iBody                    ,
                                                                            double                     iOffset1                 ,
                                                                            double                     iOffset2                 ,
                                                                            CATTopData               * iTopData                 );

  virtual                   ~CATThickenOp ();

  /**
     * This API must not be used.
     * Defines offsets on individual faces.
     * @param iFaces
     * The list of pointer to the faces.
     * @param iOffset1
     * The smaller value of the offset in the side of the natural orientation of the skin.
     * @param iOffset2
     * The larger value of the offset in the side of the natural orientation of the skin.
     */
                  void       Append                                 (const ListPOfCATFace            & iFaces                   ,
                                                                           double                      iOffset1                 ,
                                                                           double                      iOffset2                 = 0.);

  /**
  * Defines how borders are transformed in the neighborhood of sharp edges.
  * @param iSharpBorderOptimisation
  * <br><b>Legal values:</b>
  * <dl><dt>0</dt><dd>Optimization not required
  * <dt>1</dt><dd>Optimization required (Skin handled like a Volume)
  * </dl>
  * This option has no effect when SetCleverRibbonComputation() is set to 1.
  * Default value for optimisation is 1. (Optimization required).
  */
                  void       SetSharpBorderMode                     (       short                      iSharpBorderOptimisation );


  /**
     * @nodoc
     * Internal use.
   */
                  void       SetLimit                                (      CATDynLimit                iStartOrEnd              ,
                                                                            CATDynLimitType            iType                    ,
                                                                            CATGeometry              * iLimit                   );

  /**
     * @nodoc
   * This option has no effect when SetCleverRibbonComputation() is set to 1.
   * Default value for simplification is 0. (No simplification for lateral ribbon).
     * Internal use.
   */
                  void       SetNoSimplify                           ();

     /**
     * @nodoc
     * @nocgmitf
     * Internal use.
     */
                  void       ComputeOnlyOnDomains                    (const ListPOfCATDomain         & iRestriction             );

     /**
     * @nodoc
     * Internal use.
     */
                  void       SetSurfaceForEdge                       (      CATEdge                  * iEdge                    ,
                                                                            CATGeometry              * iSurfaceSpecification    );

     /**
     * Defines a Boolean operation between a given body and the result of 
     * <tt>this</tt> operator.
     * @param iOpType
     * The boolean operation type.
     * @param iOperandBody
     * The pointer to the body representing the first operand of the Boolean operation. 
     * The second operand is the result of the thicken.
     * @param iReport
     * A pointer to the journal corresponding to the Boolean operation. This journal can be different
     * from the journal of the thicken operation itself. If <tt>NULL</tt>, the Boolean journal
     * is not written.
     */
                  void       SetBooleanOperation                     (      CATDynBooleanType          iOpType                  ,
                                                                            CATBody                  * iOperandBody             ,
                                                                            CATCGMJournalList        * iReport                  = 0);


  /**
  * Robust ThickSurface. 
  */
                  void       SetCleverRibbonComputation              (      short                      iCleverRibbonComputation=1);

     /**
     * Runs <tt>this</tt> operator.
     * @return
     * The diagnosis of the computation.
     * <br><b>Legal values</b>: <tt>1</tt> if the computation failed, <tt>0</tt> otherwise. 
     */
                  int        Run                                     ();

  /**
     * Returns the created thickened body.
     * @return
     * The pointer to the result of <tt>this</tt> operator.
     * If you do not want to keep the resulting body, 
     * use the @href CATICGMContainer#Remove method to remove it from the 
     * geometric factory, after the operator deletion.
     */
                  CATBody  * GetResult                               ();

  /**
     * Returns the body created from the Boolean operation between a given body and the thickened body.
     * @return
     * The pointer to the Boolean result.
     * If you do not want to keep the resulting body, 
     * use the @href CATICGMContainer#Remove method to remove it from the 
     * geometric factory, after the operator deletion.
     */
                  CATBody   * GetBooleanResult                       ();
  
  /**
     * @nodoc
     * Internal use.
     */
                  void        SetSoftwareConfiguration               (      CATSoftwareConfiguration * iNewConfig );

    //KY1 : 10-12-2010
public:
    /**    @nodoc @nocgmitf */ 
    static const  CATString  *GetDefaultOperatorId                   ();
    /**    @nodoc @nocgmitf */
           const  CATString  *GetOperatorId                          ();

    //KY1 : 10-12-2010
    /**    @nodoc @nocgmitf */
                  int         RunOperator                            ();
protected:
    /**    @nodoc @nocgmitf */
    //static  CATString  _OperatorId; // Voir ds CATThickenOpImpl
    /**  @nodoc @nocgmitf */
                  void       RequireDefinitionOfInputAndOutputObjects();

protected:
    /**
     * @nodoc
     * Internal use.
     */
  CATThickenOpImpl * _implementation;
  
};

 
    /**
     * Creates an operator that thickens a skin body with inside and outside offset values.
     * @param iFactory
     * The pointer to the factory of the geometry.
     * @param iTopData
     * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
     * is <tt>NULL</tt>, it is not filled.
     * @param iBody
     * The pointer to the skin body to thicken.
     * @param iOffset1
     * The smaller value of the offset in the side of the natural orientation of the skin.
     * @param iOffset2
     * The larger value of the offset in the side of the natural orientation of the skin.
     * @return
     * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
     */
ExportedByAdvThickness CATThickenOp * CATCreateThickenOp( CATGeoFactory     * iFactory, 
                                                          CATTopData        * iTopData, 
                                                          CATBody           * iBody, 
                                                          double              iOffset1, 
                                                          double              iOffset2 );



#endif
