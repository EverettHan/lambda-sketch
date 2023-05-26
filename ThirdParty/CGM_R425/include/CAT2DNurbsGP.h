#ifndef CAT2DNurbsGP_H
#define CAT2DNurbsGP_H
//
// CATIA Version 5 Release 1 Frameworks VISUALIZATION and PRINT
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract: Graphic 2D Nurbs
//
//------------------------------------------------------------------------------
// Usage: You can ALLOCATE or DONT_ALLOCATE your data.
//        ALLOCATE      : All data are duplicate into the graphic primitive
//        DONT_ALLOCATE : the graphic primitive have a pointer to your data  
//------------------------------------------------------------------------------
// Inheritance: CAT2DNurbsGP
//                 CATDynamicGP
//                    CATGraphicPrimitive
//                       CATExtend (SYSTEM framework)
//------------------------------------------------------------------------------
// Main Methods:
//
//           Draw 2D nurbs with a associated CATRender
//
//              Draw
//              ImmediateDraw
//
//           Access Data
//
//              Get
//              SetBezierKnots
//
//              
//------------------------------------------------------------------------------

#include "CATDynamicGP.h"
#include "SGInfra.h"
#include "CATVisMacroForInterfaces.h"

class IVisSG2DPrimitive;
class CAT2DNurbsGPIVisSG2DPrimitiveBOAImpl;

class CATMathPoint2Df;

class ExportedBySGInfra CAT2DNurbsGP : public CATDynamicGP
{
 CATDeclareClass;

 public :

  CATVisDeclarePublicInterfaceAdhesion(CAT2DNurbsGP, IVisSG2DPrimitive, CAT2DNurbsGPIVisSG2DPrimitiveBOAImpl);

   CAT2DNurbsGP ();

   CAT2DNurbsGP (const int order, const float controls[], const int nb_controls, const float nodes[], const int nb_nodes, const float start_param, const float end_param, const float weights[], const int alloc=ALLOCATE);

   CAT2DNurbsGP (const int order, const CATMathPoint2Df controls[], const int nb_controls, const float nodes[], const int nb_nodes, const float start_param, const float end_param, const float weights[], const int alloc=ALLOCATE);  
  
   inline void Get (float *order, float **controls, int *nb_controls, float **nodes, int *nb_nodes, float *start_param, float *end_param, float **weights) const;
 
   void SetBezierKnots(const float bezierKnots[], const int nb_bezierKnots);
   void SetVisuPoints(const float coord[], const int nbPts);

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

   virtual ~CAT2DNurbsGP();
   float ComputeBSplineBase(const int i, const int k, const float t, const float ToleranceScale);
  
//--------------------------------------------------------------------------------

 private :

   float *_controls;
   float *_nodes;
   int   _nb_controls; /** @win64 fbq : 64-bit structure padding **/
   int   _nb_nodes;
   float *_weights;
   float *_newpoints;
   int   _nb_newpoints;
   int   _order;
   float _start_param;
   float _end_param;
   int   _alloc;
   float _radius;
   int   _nb_bezierKnots;
   int   _nb_visuPoints;
   float *_bezierKnots;
   float *_visuPoints;
};
    
//--------------------------------------------------------------------------------

inline void CAT2DNurbsGP::Get(float *order, float **controls, int *nb_controls, float **nodes, int *nb_nodes, float *start_param, float *end_param, float **weights) const
{
   *order       = _order;
   *controls    = _controls;
   *nb_controls = _nb_controls;
   *nodes       = _nodes;
   *nb_nodes    = _nb_nodes;
   *start_param = _start_param;
   *end_param   = _end_param;
   *weights     = _weights;
}

#endif









