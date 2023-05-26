#ifndef CATPolyTessellator_h
#define CATPolyTessellator_h

// COPYRIGHT DASSAULT SYSTEMES  2001


#include "TessAPI.h"
#include "CATMathConstant.h"

//class CATFace;
//class CATMathPoint;
//class CATMathSetOfPointsND;

class CATTessFanIter;
class CATTessInFaceSurfacePoly;
class CATTessPointIter;
class CATTessPolyIter;
class CATTessStripeIter;
class CATTessTrianIter;


#ifndef CATTessFrameworkCaller
#define CATTessFrameworkCallerExpansed(x) #x
#define CATTessFrameworkCaller(x)  CATTessFrameworkCallerExpansed(x)
#endif

/**
 * Class defining a Tessellation operator on a polyedron.
 * <br> This operator computes a discretized geometry on the skin of a polyedron, as triangles and bars.
 * The extremities of the bars are called points. Three parameters tune the tessellation result:
 * <dl>
 * <dt> Step </dt><dd> Defines the maximum length of a bar. If not defined, the step is infinite 
 * (this parameter is unused)
 * </dl>
 * The Tessellation operator follows the scheme of all the CGM operators:
 * <ul>
 * <li> Create an operator instance,
 * <li> Run,
 * <li> Recover the results by the means of iterators,
 * <li> Delete the operator instance. The deletion of the operator leads to the deletion
 * of the iterators and the arrays of results.
 * </ul>
 */

class ExportedByTessAPI CATPolyTessellator
{
public:
  /**
   * Constructs a CATPolyTessellator with an infinite step.
   * @param iPolyedron
   *   The polyedron to tessellate.
   * @param iFwCaller
   *   For quick analysis of numerous genuine tessellate callers.
   */
  CATPolyTessellator(CATTessInFaceSurfacePoly * iPoly,
                     const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_));

  ~CATPolyTessellator();

  /**
   * Defines a finite step for <tt>this</tt> CATPolyTessellator.
   * @param iStep
   * The Step value.
   */
  void SetStep(double iStep);

  /**
   * Runs <tt>this</tt> CATPolyTessellator.
   */
  void Run();

   /**
   * Retrieves the results associated with a polyedron.
   * <br> All the output iterators are allocated by the <tt>GetFace</tt> method,
   * and are deleted when the operator is deleted.
   * @param iFace
   * The pointer to a face of the input polyedron.
   * @param oPlane
   * Retrieves <tt>1</tt> if the face is planar, <tt>0</tt> otherwise.
   * @param oPoints
   * The pointer to the created CATTessPointIterator, to retrieve the computed points. 
   * @param oStrips
   * The pointer to the created CATTessStripIterator, to retrieve the computed triangle strips. 
   * @param oStrips
   * The pointer to the created CATTessFanIterator, to retrieve the computed triangle fans. 
   * @param oStrips
   * The pointer to the created CATTessPolygonIterator, to retrieve the computed polygons. 
   * @param oSide
   * The face orientation.
	 * <br><b>Legal values</b>: <tt>1</tt> if the face orientation is outwards, <tt>-1</tt> if it is inwards.
   */
  void GetFace(CATTessInFaceSurfacePoly *  iPoly,
               CATBoolean                & oPlane,
               CATTessPointIter         ** oPoints,
               CATTessStripeIter        ** oStrips,
               CATTessFanIter           ** oFans,
               CATTessPolyIter          ** oPolygons,
               CATTessTrianIter         ** oTriangles,
               short                    *  oSide = (short *) 0);

protected:  
  void * _Tessellator;
};

#endif
