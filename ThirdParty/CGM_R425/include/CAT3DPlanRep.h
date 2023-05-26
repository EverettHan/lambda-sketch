#ifndef CAT3DPlanRep_H
#define CAT3DPlanRep_H

/* COPYRIGHT DASSAULT SYSTEMES 2000 */

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"

#include "CAT3DRep.h"
#include "CATVisMacroForInterfaces.h"

class CAT3DFixedPlanGP;
class CATMathPointf;
class CATMathDirectionf;
class CATGraphicAttributeSet;
class CATVisuController;
class CATGraphicPrimitive;

class IVisSG3DPrimitiveIterator;
class CAT3DPlanRepIVisSG3DPrimitiveIteratorBOAImpl;

/**
* Class to create a graphic representation with a plane.
*/
class ExportedBySGInfra CAT3DPlanRep : public CAT3DRep
{
 friend class CATMarshallable3DPlaneRep;
 friend class CATDmuStream3DPlanRep;
 friend class SGCGRStreamerForPlanRep;
 friend class SGCGRNodesFactoryA;
 CATDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT3DPlanRep, IVisSG3DPrimitiveIterator, CAT3DPlanRepIVisSG3DPrimitiveIteratorBOAImpl);

 public :

	/**
	* Default constructor.
	*/
  static CAT3DPlanRep* CreateRep();

     /**
   * Constructs a graphic representation from an origin, two directions,
   * and a lenght expressed in millimeters.
   * <pre>
   *
   *                         -----------------------------      ^
   *                        |                             |     |
   *                        |          iDirection1        |     |     
   *                        |              ^              |     |
   *                        |              |              |     |
   *                        |              |  iDirection2 |     |
   *                        |              x --->         |     | iLenghtInMM
   *                        |           iOrigin           |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                         -----------------------------      v
   *
   *                         <--------------------------->
   *                                  iLenghtInMM
   *       
   *
   * </pre>
   * @param iOrigin
   *   The square center. 
   * @param iDirection1
   *   The first direction which
   *   is parallel to two of the edges.
   * @param iDirection2
   *   The second direction which is parallel
   *   to the two other edges.
   * @param iLengthInMM
   *   The square length expressed in millimeters.
   */
   static CAT3DPlanRep* CreateRep(const CATMathPointf & iOrigin,  
                                 const CATMathDirectionf & iDirection1,
                                 const CATMathDirectionf & iDirection2, 
                                 float iLengthInMM);
protected:

   /** @nodoc : deprecated R417 : Use CreateRep instead.*/
   CAT3DPlanRep ();

   /** @nodoc : deprecated R417 : Use CreateRep instead.*/
   CAT3DPlanRep ( const CATMathPointf & iOrigin,  
                  const CATMathDirectionf & iDirection1,
                  const CATMathDirectionf & iDirection2, 
                  float iLengthInMM);

public:

   	/**
	* @nodoc 
	*/
   virtual ~CAT3DPlanRep();

   /** @nodoc */
   CAT3DPlanRep (CATModelIdentificator & one_ident, CATVisuController *iCntl);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
   /**
   * @nodoc 
   */
   virtual void DrawShading    (CATRender &, int) FUNC_OVERRIDE_FINAL;

#ifdef CATIAR426
   /**
   * @nodoc
   */
   virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) FUNC_OVERRIDE_FINAL;
   /**
   * @nodoc
   */
   virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
   /**
   * @nodoc
   */
   virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

   /**
   * Retrieves information about the plane.
   * @param ioOrigin
   *   The square center. 
   * @param ioDirection1
   *   The first direction which
   *   is parallel to two of the edges.
   * @param ioDirection2
   *   The second direction which is parallel
   *   to the two other edges.
   */
   void Get(CATMathPointf & ioOrigin, 
            CATMathDirectionf & ioDirection1, 
            CATMathDirectionf & ioDirection2);

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);


  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

 protected :

   CAT3DFixedPlanGP *_planGeometry; 
};

#endif 









