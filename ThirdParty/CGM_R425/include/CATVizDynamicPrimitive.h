#ifndef CATVizDynamicPrimitive_H
#define CATVizDynamicPrimitive_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//******************************************************************************
//  Inheritance:
//  ------------
//                CATVizDynamicPrimitive
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
#include "CATVizPrimitive.h"
#include "CATVisMacroForInterfaces.h"

class CATViewpoint;
class CATViewport;

class IVisSGPrimitive;
class CATVizDynamicPrimitiveIVisSGPrimitiveBOAImpl;

/**
 * Base class of dynamic graphic primitives. A graphic primitive is said dynamic when its representation, on the screen,
 * is viewpoint or viewport dependant.
 * You cannot delete a dynamic graphic primitive. You must use the 
 * CATGraphicPrimite::Destroy static method to delete a graphic primitive.
 * The differed destruction is activated between  the culling and the 
 * drawing processing. 
 * This class has a <tt>Draw</tt> method that must be called by a representation (CATRep)
 * in <tt>DrawShading</tt> method. It is not necessery to overload the <tt>Draw</tt>
 * method of the CATVizDynamicPrimitive class.
 */
class ExportedBySGInfra CATVizDynamicPrimitive : public CATVizPrimitive
{
 
 public:

  CATVisDeclarePublicInterfaceAdhesion(CATVizDynamicPrimitive, IVisSGPrimitive, CATVizDynamicPrimitiveIVisSGPrimitiveBOAImpl);

  /**
   * Constructs a CATVizDynamicPrimitive. 
   */
    CATVizDynamicPrimitive ();
    
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
    
  protected :
    
    virtual ~CATVizDynamicPrimitive();
    
};


#endif
