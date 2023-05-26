#ifndef CAT2DPolyBezierGP_H
#define CAT2DPolyBezierGP_H
//
// CATIA Version 5 Release 1 Frameworks VISUALIZATION and PRINT
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract: Graphic 2D PolyBezier
//
//------------------------------------------------------------------------------
// Usage: You can ALLOCATE or DONT_ALLOCATE your data.
//        ALLOCATE      : All data are duplicate into the graphic primitive
//        DONT_ALLOCATE : the graphic primitive have a pointer to your data  
//------------------------------------------------------------------------------
// Inheritance: CAT2DPolyBezierGP
//                 CATDynamicGP
//                    CATGraphicPrimitive
//                       CATExtend (SYSTEM framework)
//------------------------------------------------------------------------------
// Main Methods:
//
//           Draw 2D polybezier with a associated CATRender
//
//              Draw
//              ImmediateDraw
//
//           Access Data
//
//              Get
//              
//------------------------------------------------------------------------------

#include "CATDynamicGP.h"
#include "SGInfra.h"
#include "CATVisMacroForInterfaces.h"

class IVisSG2DPrimitive;
class CAT2DPolyBezierGPIVisSG2DPrimitiveBOAImpl;

class CATMathPoint2Df;

class ExportedBySGInfra CAT2DPolyBezierGP : public CATDynamicGP
{
 CATDeclareClass;

 public :

    CATVisDeclarePublicInterfaceAdhesion(CAT2DPolyBezierGP, IVisSG2DPrimitive, CAT2DPolyBezierGPIVisSG2DPrimitiveBOAImpl);

   CAT2DPolyBezierGP ();
	 
   CAT2DPolyBezierGP (const float points[], const int nbPoints=4,
                      const int alloc=ALLOCATE);
   CAT2DPolyBezierGP (const CATMathPoint2Df points[], const int nbPoints=4,
                      const int alloc=ALLOCATE);  
  
   inline void Get (float **points, int *nb_points) const;
   virtual void ImmediateDraw (CATRender &, const CATViewpoint *, const CATViewport *) override final;
   virtual void Draw(CATRender& iRender) override final;

/**
 * @nodoc
 * Streaming
 */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   
/**
 * @nodoc
 * Unstreaming
 */  
   virtual void UnStream(CATStreamer& iStr);
 
//--------------------------------------------------------------------------------
 
 protected :

   virtual ~CAT2DPolyBezierGP();
     
//--------------------------------------------------------------------------------

 private :

   float *_points;
   float *_newpoints;
   int   _nb_points;
   int   _alloc;
};
    
//--------------------------------------------------------------------------------

inline void CAT2DPolyBezierGP::Get(float **points, 
                                   int *nb_points) const
{
   *points      = _points;
   *nb_points   = _nb_points;
}

#endif








