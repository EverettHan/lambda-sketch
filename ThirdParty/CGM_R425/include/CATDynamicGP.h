#ifndef CATDynamiGP_H
#define CATDynamiGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//******************************************************************************
//  Inheritance:
//  ------------
//                CATDynamicGP
//                   CATGraphicPrimitive
//                      CATExtend (SYSTEM framework)
//
//******************************************************************************
//  Main Methods:
//  -------------
//  
//       ImmediateDraw  : 
//
//******************************************************************************

#include "SGInfra.h"
#include "CATGraphicPrimitive.h"

class CATViewpoint;
class CATViewport;

/**
 * Base class of dynamic graphic primitives. A graphic primitive is said dynamic when its representation, on the screen,
 * is viewpoint or viewport dependant.
 * You cannot delete a dynamic graphic primitive. You must use the 
 * CATGraphicPrimite::Destroy static method to delete a graphic primitive.
 * The differed destruction is activated between  the culling and the 
 * drawing processing. 
 * This class has a <tt>Draw</tt> method that must be called by a representation (CATRep)
 * in <tt>DrawShading</tt> method. It is not necessery to overload the <tt>Draw</tt>
 * method of the CATDynamicGP class.
 */
class ExportedBySGInfra CATDynamicGP : public CATGraphicPrimitive
{
  CATDeclareClass;
 
  friend class CAT2DNurbsGP;
  friend class CAT2DPolyBezierGP;
  friend class CAT2DPolyPolygonGP;
  friend class CAT3DImagePixelGP;
  friend class CATFreeTypeTextGP;
  friend class CAT2DAnnotationTextGP;
  friend class CAT2DArcEllipseGP;
  friend class CAT2DFixedArrowGP;
  friend class CAT2DImagePixelGP;
  friend class CAT2DSymbolGP;
  friend class CAT2DTextGP;
  friend class CAT3DAnnotationTextGP;
  friend class CAT3DArcEllipseGP;
  friend class CAT3DArrowGP;
  friend class CAT3DFixedArrowGP;
  friend class CAT3DFixedPlanGP;

 public:

BEGIN_MIGRATE_GP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Do not derive this class" )
#endif
     /**
   * Constructs a CATDynamicGP. 
   */
    CATDynamicGP ();
END_MIGRATE_GP_CTOR

  /**
   * Draws the dynamic graphic primitive.
   * @param iRender
   *   The render through which the primitive is drawn.
   */
    virtual void Draw (CATRender & iRender);

  /**
   * Draws the dynamic graphic primitive.<br>
   * <b>Role</b>:
   *  Every dynamic graphic primitive must overloaded the
   *  <tt>ImmediateDraw</tt> method. This method allows the immediate
   *  mode rendering. This method is called through the call to <tt>Draw</tt>
   * @param iRender
   *   The render through which the primitive is drawn.
   * @param iViewpoint
   *   The viewpoint through which the primitive is seen.
   * @param iViewport
   *   The viewport in which the primitive is located.
   */
    virtual void ImmediateDraw (CATRender &iRender, const CATViewpoint *iViewPoint, const CATViewport *iViewPort) = 0;    
    
  /**
   * @nodoc
   */
    void Visit(CATIGPVisitor& iVisitor) const override;

  protected :
    
    virtual ~CATDynamicGP();
    
};


#endif
