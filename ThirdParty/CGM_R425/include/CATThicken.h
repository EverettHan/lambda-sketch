#ifndef CATThicken_h
#define CATThicken_h

// COPYRIGHT DASSAULT SYSTEMES  1999
// DPS le 30 juin 2004
// Je derive ThickenOp qui est CAA en CATThicken tout court non CAA
// pour pouvoir ajouter des methodes pour usage interne
// Je pense en particulier a tout ce qui concerne l'Approx C1 ou C2

/**
 * NON CAA
 */ 

#include "CATThickenOp.h"

class CATGeoFactory;
class CATBody;
class CATTopData;

/**
 * Class defining the topological operator that thickens a skin body into a volume body.
 * <br>A global offset value can be defined on the body, or faces to thicken can be individually chosen as well
 * as the corresponding offset values.
 *<br>
 * This operator follows the global frame of the topological operators 
 * and satisfies the smart mechanism: the
 * input body is not modified. A new resulting body is created, 
 * possibly sharing data with the input body. A CATThicken operator is not streamable.
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateThicken</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods.
 * <li>Run it
 * <li>Get the result with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 *<li>Delete it with the usual C++ <tt>delete</tt> operator after use.
 *</ul> 
 */  
class ExportedByAdvThickness CATThicken : public CATThickenOp
{
public:


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
  CATThicken(CATGeoFactory     * iFactory ,
             CATBody           * iBody    ,
             double              iOffset1 ,
             double              iOffset2 ,
             CATTopData        * iTopData );

  virtual ~CATThicken ();
  

  // LES METHODES QUI SUIVENT SONT NON CAA ET EN SONT PAS PRESENTES DANS CATThickenOp
  // A USAGE INETRNE UNIQUEMENT !!!
  /**
  * Defines if procedural Offset surfaces must be approximated and
  * replaced by NurbsSurface
  * @param iApproxOffsetMode
  * <br><b>Legal values:</b>
  * <dl><dt>0</dt><dd>Approximation not required
  * <dt>1</dt><dd>Approximation required in C1 mode
  * <dt>2</dt><dd>Approximation required in C2 mode
  * @param iPostProRequired
  * <br><b>Legal values:</b>
  * <dl><dt>0</dt><dd>Approximation required during Offset algorithm
  * <dt>1</dt><dd>Approximation required after Offset algorithm
  * </dl>
  */
 void SetApproxOffsetMode(short iApproxOffsetMode, short iPostProRequired=1);
 
/**
  * Defines the tolerance for C1 approximation 
  * @param iTolC1
  * </dl>
  */
 void SetToleranceForApproxC1(double iTolC1);

/**
  * Defines the tolerance for C2 approximation 
  * @param iTolC2
  * </dl>
  */
 void SetToleranceForApproxC2(double iTolC2);
  
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
ExportedByAdvThickness CATThicken * CATCreateThicken(CATGeoFactory     * iFactory, 
                                                     CATTopData        * iTopData, 
                                                     CATBody           * iBody, 
                                                     double              iOffset1, 
                                                     double              iOffset2 );
#endif
