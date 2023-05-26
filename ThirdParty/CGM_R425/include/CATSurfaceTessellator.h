#ifndef CATSurfaceTessellator_h
#define CATSurfaceTessellator_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "TessAPI.h"
#include "CATMathConstant.h"
#include "CATCGMVirtual.h"

class CATSurface;
class CATSurLimits;

class CATTessPointIter;
class CATTessStripeIter;
class CATTessFanIter;
class CATTessPolyIter;
class CATTessTrianIter;
/**
 * Class defining a tessellation operator on surfaces.
 * <br> This operator computes a discretized geometry on the surfaces as triangles.
 * The corner of the triangles are called points. Three parameters tune the tessellation result:
 * <dl>
 * <dt> Sag </dt><dd> Defines the maximum distance between a bar and the object to tessellate
 * <dt> Step </dt><dd> Defines the maximum length of a bar. If not defined, the step is infinite 
 * (this parameter is unused)
 * <dt> Angle </dt><dd> Defines the maximum angle between the normals at each bar end. 
 * </dl>
 * The tessellation operator follows the scheme of all CGM operator:
 * <ul>
 * <li> Create an operator instance,
 * <li> Run,
 * <li> Optionally, adds other curves to tessellate in the same operation,
 * <li> Recover the results by the means of iterators,
 * <li> Delete the operator instance. The deletion of the operator leads to the deletion
 * of the iterators and the arrays of results.
 * </ul>
 */

class ExportedByTessAPI CATSurfaceTessellator: public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATSurfaceTessellator);
public:
   /**
   * Constructs a CATSurfaceTessellator with an infinite step.
   * @param iSag
   * The Sag value.
   * @param iAngle
   * The Angle value.
   */
  CATSurfaceTessellator(double iSag,
                        double iAngle=CATPI*.25);
  ~CATSurfaceTessellator();
 
   /**
   * Adds an other surface to <tt>this</tt> CATSurfaceTessellator.
   * @param iSurface
   * The other surface to tessellate in the same operation.
   * @param iSurfaceLimits
   * The part of the surface to take into account.
   */
  void AddSurface(CATSurface *iSurface, const CATSurLimits& iSurfaceLimits);

   /**
   * Defines a finite step for <tt>this</tt> CATCurveTessellator.
   * @param iStep
   * The Step value.
   */ 
  void SetStep(double iStep);

   /**
   * Runs <tt>this</tt> CATSurfaceTessellator.
   */
  void Run();

    /**
   * Retrieves the results associated with a surface.
   * <br> All the output iterators are allocated by the <tt>GetSurface</tt> method,
   * and are deleted when the operator is deleted.
   * @param iSurface
   * A surface among the input surfaces.
   * @param ioPlane
   * Retrieves <tt>1</tt> if the surface is planar, <tt>0</tt> otherwise.
   * @param oPoints
   * A pointer to a CATTessPointIterator, to retrieve the computed points. 
   * @param oStrips
   * A pointer to a CATTessStripIterator, to retrieve the computed triangle strips. 
   * @param oStrips
   * A pointer to a CATTessFanIterator, to retrieve the computed triangle fans. 
   * @param oStrips
   * A pointer to a CATTessPolygonIterator, to retrieve the computed polygons.
   */
  void GetSurface(CATSurface         * iSurface,
                  CATBoolean         & ioPlane,
                  CATTessPointIter  ** oPoints,
                  CATTessStripeIter ** oStrips,
                  CATTessFanIter    ** oFans,
                  CATTessPolyIter   ** oPolygons,
                  CATTessTrianIter  ** oTriangles);
  
protected:  
  void * _Tessellator;
};

#endif
