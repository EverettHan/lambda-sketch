#ifndef CATInterproxSur_H
#define CATInterproxSur_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "FrFOpeSur.h"
#include "CATIACGMLevel.h"

#include "CATMathDef.h"
#include "CreateInterproxSur.h"
#include "CATCGMVirtual.h"

class CATNurbsSurface;
class CATMathSetOfVectors;
class CATFrFNurbsMultiForm;

/**
 * Class representing the geometric operator that deforms surfaces on a set of points.
 * <br>Several parameters define this operator:
 * <ul><li>The tension parameter strengthens the shape: a higher tension gives a flatter shape.
 * <li>The curvature (or smoothness) parameter regularizes the surface curvature: 
 * a higher curvature coefficient gives a smoother surface.
 * </ul>
 * This operator projects the set of points on the surfaces and use a least squares method to deform the surfaces. 
 * <br>To use it in <tt>BASIC</tt> mode:
 * <ul><li>Create it with the <tt>CATCreateInterproxSur</tt> global method. The run is automatically done and the
 * input surfaces are directly deformed.
 * <li><tt>delete</tt> the operator with the usual C++ delete operator after use.
 * </ul>
 * <br>To use it in <tt>ADVANCED</tt> mode:
 * <ul><li>Create it with the <tt>CATCreateInterproxSur</tt> global method.
 * <li>Change the smoothness or tension parameters with the <tt>SetXxx</tt> methods.
 * <li>Run it. This step directly deforms the input surfaces, it is the reason why there is no <tt>GetResult</tt>
 * method. You can <tt>Run</tt> again the operator with different parameters, 
 * allowing you to iterate on the deformation.
 * <li><tt>delete</tt> the operator after use.
 * </ul>
 */
class ExportedByFrFOpeSur CATInterproxSur : public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATInterproxSur);
  public :

    virtual ~CATInterproxSur();

/**
 * Runs <tt>this</tt> operator (<tt>ADVANCED</tt> mode).
 * <br>The input surfaces are directly modified
 */
    virtual void Run()=0;

/**
 * Defines the tension parameter (<tt>ADVANCED</tt> mode).
 * @param iTension
 * The new value of the tension parameter.
 */
    virtual void SetTensionParameter(const double iTension)=0;

/**
 * Defines the smoothness parameter (<tt>ADVANCED</tt> mode).
 * @param iSmoothness
 * The new value of the smoothness parameter.
 */
    virtual void SetCurvatureParameter(const double iSmoothness)=0;

/**
 * @nodoc
 */
    virtual void SetApproachTolerance(const double tolapp)=0;
/**
 * Defines the continuity constraints.
 * @param iImposition
 * The array [4*Nbsur] defining the type of constraints at each extremities of the deformed surface.
 * The array is filled as follows, for the input surfaces from <tt>0 <= i < Nbsur</tt>:
 * <ul>
 * <li><tt>iImposition[0+4*i]</tt> for the iso-parametric boundary <tt>v=0</tt> of the <tt>i-</tt>th surface.
 * <li><tt>iImposition[1+4*i]</tt> for the iso-parametric boundary <tt>u=0</tt> of the <tt>i-</tt>th surface.
 * <li><tt>iImposition[2+4*i]</tt> for the iso-parametric boundary <tt>v=vmax</tt> of the <tt>i-</tt>th surface.
 * <li><tt>iImposition[3+4*i]</tt> for the iso-parametric boundary <tt>u=umax</tt> of the <tt>i-</tt>th surface.
 * </ul>
 * <br><b>Legal values</b>: <tt>0</tt> for a free boundary,
 * <tt>1</tt> for a C0 continuity with the input surface, 
 * <tt>2</tt> for a C1 continuity, <tt>3</tt> for a C2 continuity.
 */
     virtual void SetContinuity(const int* iImposition)=0;
     
/**
 * @nodoc
 * @nocgmitf Not implemented!
 * Other targetted boundary
 * @param iBord
 * Tne rank of the given boundary
 * <br><b>Legal values</b>:
 * - ibord = 0 -> boundary v = 0 
 * - ibord = 1 -> boundary u = 0 
 * - ibord = 2 -> boundary v = 1 
 * - ibord = 3 -> boundary u = 1 
 * @param iTarget  
 *  1 form if C0 , 2 if C1 , etc...
 * @para iCont
 * The number of forms ie desired continuities
 */

     void SetTargetBoundary(CATLONG32              ibord  ,
                            CATFrFNurbsMultiForm & iTarget,
                            CATLONG32              iCont  ) ;
};

#endif


