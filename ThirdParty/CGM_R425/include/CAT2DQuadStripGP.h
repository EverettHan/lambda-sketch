#ifndef CAT2DQuadStripGP_H
#define CAT2DQuadStripGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"
#include "CATGraphicPrimitive.h"
#include "CATBoolean.h"
#include "CATVisMacroForInterfaces.h"

class IVisSG2DPrimitive;
class CAT2DQuadStripGPIVisSG2DPrimitiveBOAImpl;


/**
* Class to create a dynamic graphic primitive of a 2D strip.
* <b>Role</b>: Each vertices of the 2D strip may each have a different color.
*/ 
class ExportedBySGInfra CAT2DQuadStripGP : public CATGraphicPrimitive
{
 CATDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT2DQuadStripGP, IVisSG2DPrimitive, CAT2DQuadStripGPIVisSG2DPrimitiveBOAImpl);
  
  public:

/**
* Constructs a 2D quadstrip dynamic graphic primitive.
* @param iPoints
*    Array of point coordinates: XYXYXY...
*    Its size is equal to two times the number of points.
* @param iNb_points
*	total number of points of the 2D quadstrip.
* @param iVertexcolors
*	Array of vertex colors : RGBRGBRGB....
*	Its size is equal to three times the number of points.
*/
    CAT2DQuadStripGP (const float iPoints[],
		      const int iNb_points,
		      const float iVertexcolors[], const CATBoolean& i_formatRGBAFlag = FALSE);
    
    
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
/**
* Draws the dynamic graphic primitive with a render.
* @param iRender
*	the render used to draw the dynamic graphic primitive.
*/
    virtual void Draw (CATRender & iRender) GP_FUNC_OVERRIDE_FINAL;
    
    
/**
* Retrieves data about the 2D Marker.
* @param oPoints
*    Array of point coordinates: XYXYXY...
*    Its size is equal to two times the number of points.
* @param oNb_point
*	total number of points of the 2D quadstrip.
* @param oVertexcolors
*	Array of vertex colors : RGBRGBRGB....
*	Its size is equal to three times the number of points.
*/
    inline void Get (float **oPoints, int *oNb_point, float **oVertexcolors) const;

    inline void Get (float **o_ppPoints, int *o_pNb_point, float **o_ppVertexcolors, CATBoolean& o_formatRGBAFlag) const;
    
/**
* @nodoc
*/
    virtual void Visit(CATIGPVisitor& iVisitor) const final;

  protected:
    
    virtual ~CAT2DQuadStripGP();
    
    
  private:
    
    float *_points;
    float *_vertexcolors;
    int   _nb_points;
    CATBoolean _formatRGBAFlag;
};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************

    
inline void CAT2DQuadStripGP::Get (float **points,
				   int *nb_points,
				   float **vertexcolors) const
{
  CATBoolean formatRGBAFlag;
  Get(points, nb_points, vertexcolors, formatRGBAFlag);
}

inline void CAT2DQuadStripGP::Get (float **o_ppPoints, int *o_pNb_point, float **o_ppVertexcolors, CATBoolean& o_formatRGBAFlag) const
{
  *o_ppPoints       = _points;
  *o_pNb_point    = _nb_points;
  *o_ppVertexcolors = _vertexcolors;
  o_formatRGBAFlag = _formatRGBAFlag;
}


#endif
