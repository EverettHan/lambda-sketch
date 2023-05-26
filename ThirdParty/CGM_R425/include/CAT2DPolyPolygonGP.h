#ifndef CAT2DPolyPolygonGP_H
#define CAT2DPolyPolygonGP_H
//
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract: Graphic 2D polygons.
//
//           Example a CAT2DPolyPolygon with 4 points :
//
//             point 1 X--------------------X point 2
//                     |                    |
//                     |                    |
//             point 4 X--------------------X point 3
//
//------------------------------------------------------------------------------
// Usage: You can ALLOCATE or DONT_ALLOCATE your data.
//        ALLOCATE      : All data are duplicate into the graphic primitive
//        DONT_ALLOCATE : the graphic primitive have a pointer to your data
//------------------------------------------------------------------------------
// Inheritance: CAT2DPolyPolygonGP
//                 CATGraphicPrimitive
//                     CATExtend (SYSTEM framework)
//------------------------------------------------------------------------------
// Main Methods:
//
//           Draw 2D polygon with a associated CATRender
//
//              Draw
//             
//------------------------------------------------------------------------------
#include "SGInfra.h"

#include "CATDynamicGP.h"

#ifndef NOFILL
#define NOFILL 0
#define FILL   1
#endif

/**
* Class to create the graphic primitive of a 2D polygone.
* <b>Role</b>: <pre>
*          Example a CAT2DPolyPolygon with 4 points :
*
*             point 1 X--------------------X point 2
*                     |                    |
*                     |                    |
*             point 4 X--------------------X point 3
*              </pre>
*/
class ExportedBySGInfra CAT2DPolyPolygonGP : public CATDynamicGP
{
 CATDeclareClass;

 public :

/**
   * Constructs a 2D polygone graphic primitive from a list of points.
   * @param iPoints
   *   Array containing the x, y  coordinates for
   *   each point of the polygone. Its size is equal
   *   to two times the number of points. So, the coordinates
   *   x, y of the first point are respectively stored in iPoints[0], iPoints[1] and iPoints[2],
   *   the coordinates x, y of the second point, in iPoints[3], iPoints[4], iPoints[5], and so on...
   * @param iNbPoints
   *   The number of points used to define the polygone.
   *   <br><b>Legal values</b>: the default value is 2.
   * @param iAlloc
   *   Parameter used to specify whether to allocate or not the data.
   *    <br><b>Legal values</b>:
   *   <ul>
   *      <li>ALLOCATE :
   *        All data are duplicate into the graphic primitive</li>
   *      <li>DONT_ALLOCATEb :
   *        The graphic primitive has a pointer to the data given as parameter</li>
   *   </ul>
   *   
   */
   CAT2DPolyPolygonGP (const float points[], const int nb_outlines, const int *nb_points, const int = FILL, const int option = 0);

   void ImmediateDraw (CATRender &render, const CATViewpoint*, const CATViewport *viewport) override final;

   void Draw(CATRender& iRender) override final;
 
   inline void Get (float **points, int *nb_outlines, int **nb_point, int *fill,
                    int *, int **, int **, int **) const;

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

  virtual ~CAT2DPolyPolygonGP();
     
//--------------------------------------------------------------------------------

 private :

   float *_points;
   int   *_type, *_triangle, *_vertex;
   int   *_nb_points, _nb_triangle, _nb_outlines, _pts_total;
   int   _fill;
                   
};
    
//--------------------------------------------------------------------------------

inline void CAT2DPolyPolygonGP::Get(float **points, int *nb_outlines, int **nb_points, int *fill, int *nb_triangle, int **type, int **triangle, int **vertex) const
{
 *points    = _points;
 *nb_outlines = _nb_outlines; 
 *nb_points = _nb_points;
 *fill      = _fill;

 *nb_triangle = _nb_triangle;
 *type        = _type;
 *triangle    = _triangle;
 *vertex      = _vertex;
}

#endif
