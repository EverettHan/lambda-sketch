#ifndef CATConcatenationSurface_H
#define CATConcatenationSurface_H
//
// COPYRIGHT DASSAULT SYSTEMES 2000
//
#include "FrFOpeSur.h"
#include "CATGeoFactory.h"
#include "CATCGMOperator.h"
class CATSurface;
class CATGEoFactory;
class CATSurLimits;
//-----------------------------------------------------------------------------

/**
 * Class representing the geometric operator to concatenate two surfaces in one single surface.
 * <br>The junction between the initial surfaces must be C2 continuous. If not, the operator tries
 * to deform the surfaces in order to make them C2. If the deformation is not inside a given
 * tolerance (by default the factory resolution), the <tt>Run</tt> method returns a failure.
 *<br>
 * The CATConcatenationSurface operator follows the global frame of the geometric operators. 
 *<ul>
 * <li>A CATConcatenationSurface operator is created with the <tt>CATCreateConcatenationSurface</tt> global method:
 * It must be directly <tt>delete</tt>d after use. It is not streamable. 
 *<li>Options can be precised (such as the limits of the input surfaces) with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting surface, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometry factory.
 *</ul>
 */
class ExportedByFrFOpeSur CATConcatenationSurface : public CATCGMOperator
   {
   public:
/**
   * Constructor. Cannot be called. Use the <tt>CATCreateConcatenationSurface</tt> global function
   * to create a CATConcatenationSurface operator.
   */
  CATConcatenationSurface (CATGeoFactory * iFactoryForCreation) ;

   virtual ~CATConcatenationSurface();

   /**
   * Defines the maximum deformation to make the surfaces being C2 continuous.
   * @param iTol
   * The tolerance value.
   */
   virtual void SetTolerance(double iTol) = 0;

  /**
   * Defines the limits to take into account to compute the concatenated surface.
   * @param iSurfaceRank
   * The rank (1 or 2) of the surface on which the limits are defined.
   * @param iSurLimits
   * The limits to take into account for the <tt>iSurfaceRank</tt>-th surface.
   */
   virtual void SetSurLimits(int iSurfaceRank, const CATSurLimits& iSurLimits) = 0;

  /**
   * @nodoc
   */ 
   virtual void SetEdgeCurves(const CATLISTP(CATCurve)& iEdgeCurves) = 0;

  /**
   * Runs <tt>this</tt> operator.
   */
   virtual int Run() = 0;

  /**
   * Returns the surface resulting of the concatenation of the input surfaces.
   * @return
   * The pointer to the created surface. If you do not want 
   * to keep the resulting surface, use the @href CATICGMContainer#Remove method to remove it from the 
   * geometric factory.
   */
  virtual CATSurface * GetResult() = 0;

  /**
   * Retrieves the curve on the resulting surface corresponding to a given curve on one of the initial surfaces.
   * @param iListOfPCurve
   * The list of pointers to the initial curves.
   * @param iListOfCrvLimits
   * The list of pointers to the limits of initial curves.
   * @param ioListOfEquivalentPCurve
   * The list of pointers to the corresponding curves on the resulting surface. 
   * @param ioListOfEquivalentCrvLimits
   * The list of pointers to the limits of curves on the resulting surface. 
   * @param ioListOfRelativeOrientation
   * The list of pointers to the relative orientation of equivalent curves. 
   * <br><b>Legal values</b>:
   * <tt>1</tt> for the same orientation, <tt>-1</tt> for the opposite orientation.
    */
   virtual void GetEquivalentPCurve(CATLISTP(CATCurve)     & iListOfPCurve              ,
                                    CATLISTP(CATCrvLimits) & iListOfCrvLimits           ,
                                    CATLISTP(CATCurve)     & ioListOfEquivalentPCurve   ,
                                    CATLISTP(CATCrvLimits) & ioListOfEquivalentCrvLimits,
                                    CATListOfInt           & ioListOfRelativeOrientation) = 0;

   /**
   * Returns the relative orientation of the resulting surface with regards to an initial surface.
   * @param iSurfaceRank
   * The rank (1 or 2) of the initial surface.
   * @param ioOrient
   * The relative orientation of the </tt>iSurfaceRank</tt>-th surface with regardsto the resulting surface.
   * <br><b>Legal values</b>:
   * <tt>1</tt> for the same orientation, <tt>-1</tt> for the opposite orientation.
   */
   virtual void GetOrientation(int iSurfaceRank, int & ioOrient) = 0;
   //
   };

/**
 * Creates the operator to concatenate two surfaces.
 * @param iFactory
 * The pointer to the geometry factory.
 * @param iSurf1
 * The pointer to the first surface to concatenate.
 * @param iSurf2
 * The pointer to the second surface to concatenate.
 * @return
 * The pointer to the created operator.
 */
ExportedByFrFOpeSur
CATConcatenationSurface*  CATCreateConcatenationSurface(      CATGeoFactory  * iFactory,
                                                        const CATSurface     * iSurf1  ,
                                                        const CATSurface     * iSurf2  );



#endif
