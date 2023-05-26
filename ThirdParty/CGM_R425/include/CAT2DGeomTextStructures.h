#ifndef CAT2DGeomTextStructures_H
#define CAT2DGeomTextStructures_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// CATIA Version CXR1 Framework VFW2
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : Different structures for the visualization of
//            2D geometric texts
//              - CAT2DGeomTextAttributeSet
//                     Attribute set for 2D geometric text.
//                     This structure is used to transmit attributes
//                     between:
//                         . CAT2DGeometricTextGP, CAT3DGeometricTextGP
//                         . CATRender
//                         . CATStrokeFont,CATType1Font
//              - CAT2DGeomTextBoundingBox
//                     Bounding box for 2D geometric text.
//                     This structure is used to transmit bounding box
//                     between:
//                         . CAT2DGeometricTextGP, CAT3DGeometricTextGP
//                         . CATRender
//                         . CATStrokeFont,CATType1Font
//              - CAT2DGeomTextPolylineList
//                     Polyline list describing a stroke geometric text
//                     to visualize.
//                     This structure is used to transmit the stroke
//                     geometric text to visualize between:
//                         . CATStrokeFont,CATType1Font
//                         . CATRender
//              - CAT2DGeomTextTriPrimitiveList
//                     Triangle primitive list describing a filled geometric
//                     text to visualize.
//                     This structure is used to transmit the filled
//                     geometric text to visualize between:
//                         . CATType1Font
//                         . CATRender
// ----------------------------------------------------------------
//  Usage : use of 2D geometric text attributes
// ----------------------------------------------------------------
//       
#include "CAT2DBoundingBox.h"

class CATPixelImage;

//--------------------------------------------------------------------------
/**
 * Attribute set for 2D geometric text.
 */
struct CAT2DGeomTextAttributeSet
{
   //  Hanging point
   /**
   * @param _Point[2] 
   *   Hanging point.
   */
   float _Point[2] ;

   //  Height
   /**
   * @param _Height 
   *   Height of the text.
   */
   float _Height ;

   //  Justification
   /**
   * @param _HorJustification 
   *   Horizontal justification.
   *   <br><b> Legal values</b>:
   *   <li><tt>0</tt> align left</li>
   *   <li><tt>1</tt> center</li>
   *   <li><tt>2</tt> align right</li>
   */
   short int _HorJustification ; /* 0:left, 1:center, 2:right */
                                 /**
                                 * @param _VerJustification 
                                 *   Vertical justification.
                                 *   <br><b> Legal values</b>:
                                 *   <li><tt>0</tt> top</li>
                                 *   <li><tt>1</tt> cap</li>
                                 *   <li><tt>2</tt> half</li>
                                 *   <li><tt>3</tt> base</li>
                                 *   <li><tt>4</tt> bottom</li>
                                 */

   short int _VerJustification ; /* 0:top, 1:cap, 2:half, 3:base, 4:bottom */

   //  Pitch
   /**
   * @param _Pitch 
   *   Font pitch.
   *   <br><b> Legal values</b>:
   *   <li><tt>0</tt> fixed pitch</li>
   *   <li><tt>1</tt> variable pitch</li>
   */
   short int _Pitch ; /* 0:fixed, 1:variable */

   //  Path
   /**
   * @param _Path 
   *   Text path: direction of writing.
   *   <br><b> Legal values</b>:
   *   <li><tt>0</tt> normal (commonly left to right)</li>
   *   <li><tt>1</tt> top to bottom</li>
   *   <li><tt>2</tt> inverse (commonly right to left)</li>
   *   <li><tt>3</tt> bottom to top</li>
   */
   short int _Path ; /* 0:normal, 1:top to bottom, 2:inverse, 3:bottom to top */

   //  Orientation angle
   /**
   * @param _OrientationAngle 
   *   Text orientation (in degrees).
   */
   float _OrientationAngle ; /* in degrees */

   //  Spacing factor
   /** @nodoc */
   float _SpacingFactor ;

   //  Compression/extension coefficient
   /** @nodoc */
   float _CompFactor ;

   //  Slant angle
   /**
   * @param _SlantAngle 
   *   Slant angle (in degrees).
   */
   float _SlantAngle ; /* in degrees */

   //  base and up angles
   /** @nodoc */
   float _BaseAngle; /* in radians */
   float _UpAngle;   /* in radians */

   //  Affinity coefficients
   /** @nodoc */
   float _VerAffinity,_HorAffinity,_HorSpaceAffinity;
   /* the horizontal space affinity coefficient is used for the spaces between characters */

   //  Matrix to apply to the descriptions
   /**
   * @param _Matrix[4] 
   *   Transformation matrix.
   */
   float _Matrix[4];  /* a11, a12, a21, a22. aij: i=line, j=column in
                      matrix european notation. This is a linear application
                      matrix. European notation means that the application of
                      this matrix to a vector will be the following:
                      +-      -+ +- -+   +-           -+
                      !a11  a12! ! x !   !a11*x + a12*y!
                      !a21  a22!*! y ! = !a21*x + a22*y!
                      +-      -+ +- -+   +-           -+
                      */

   // 0: kerning table is not applied to text. 1: kerning table is applied to text.
   /**
   * @param _KerningEnable 
   *   Enable / disable kerning value application to OpenType font.
   *   <br><b> Legal values</b>:
   *   <li><tt>0</tt> kerning table is not applied to text</li>
   *   <li><tt>1</tt> kerning table is applied to text/li>
   */
   int _KerningEnable;

   //  Text version number
   /**
   * @param _TextVersion 
   *   Text version number.
   */
   unsigned int _TextVersion;

   // Default constructor for initialization (see the constructor of CAT2DGeometricTextGP)
   /** @nodoc */
   CAT2DGeomTextAttributeSet()
   {
      _Point[0] = 0.f; _Point[1] = 0.f;
      _Height = 10.f;
      _HorJustification = 1;
      _VerJustification = 3;
      _Pitch = 0;
      _Path = 0;
      _OrientationAngle = 0.f;
      _SpacingFactor = -10000.f;
      _CompFactor = 1.f;
      _SlantAngle = 0.f;
      _BaseAngle = 0.f;
      _UpAngle = 0.f;
      _VerAffinity = 1.f; _HorAffinity = 1.f; _HorSpaceAffinity = 1.f;
      _Matrix[0] = 1.f; _Matrix[1] = 0.f; _Matrix[2] = 0.f; _Matrix[3] = 1.f;
      _KerningEnable = 0;
      _TextVersion = 0xFFFFFFFF;
   }
};

//--------------------------------------------------------------------------

/**
* Bounding box for 2D geometric text.
*/
struct CAT2DGeomTextBoundingBox
{
   //  Bounding horizontal/vertical rectangle
   /**
   * @param _BoundingHorVerRectangle
   *   Bounding box of text ( see also @href CAT2DBoundingBox ).
   */
   CAT2DBoundingBox _BoundingHorVerRectangle;
   //  Base/Cap box (to use in rendering, as a fast rendering, when the text 
   //  count to display is too much important)

   float _BaseCapBox[10]; /* X and Y alternatively. The first and last vertices are the same */

   //  Normal hanging point
   /** @nodoc */
   float _NormalPoint[2] ; /* path right: left-base
                              path down:  center-top
                              path left:  right-base
                              path up:    center-base */

   //  Application hanging point
   /**
   * @param _ApplicationPoint[2]
   *   Application hanging point for the text.
   */
   float _ApplicationPoint[2] ; // the application point is:            
                                //   .stroke font, right or left path:     
                                //       It is the xxx-base of the first character,      
                                //       where xxx is computed so that the left (case of 
                                //       a right path) of the first character box sticks 
                                //       effectively to the left of the text bounding    
                                //       box given by the text coordinates and the       
                                //       alignment specified. In the case where the pitch
                                //       is proportional, it may not be the center-base  
                                //       of the first character, depending of the way the
                                //       first character description is positioned       
                                //       compartively to the first character center line.
                                //   .stroke font, down or up path:                      
                                //       In this case, it is not a real                  
                                //       "application point". It is the center-base of   
                                //       the first character. It is not a real           
                                //       "application point" because it requires that    
                                //       the first character be centered before to apply 
                                //       its description                                 
                                //   .outline font, down or up path:                     
                                //       center-base of the first character              
                                //   .outline font, left or right path:                  
                                //       left-base of the first character                 
   
   //  Base and up angles
   /** @nodoc */
   float _BaseAngle ;
   /** @nodoc */
   float _UpAngle ;
   //  Width (base vector)
   /** @nodoc */
   float _Width ;
   //  Values along the up vector
   /** @nodoc */
   float _UpValues[5] ; /* 0: base -> bottom
                        1: base -> half
                        2: base -> cap
                        3: base -> top
                        4: bottom -> top */

   // Constructeur pour eviter les UMRs
   /** @nodoc */
   CAT2DGeomTextBoundingBox()
   {
      int i;
      for (i = 0; i < 10; i++) _BaseCapBox[i] = 0.f;
      
      _NormalPoint[0] = _NormalPoint[1] = 0.f;
      _ApplicationPoint[0] = _ApplicationPoint[1] = 0.f;
      _BaseAngle = 0.f;
      _UpAngle = 0.f;
      
      for (i = 0; i < 5; i++) _UpValues[i] = 0.f;
      
   };
};

//--------------------------------------------------------------------------

/** @nodoc */
struct CAT2DGeomTextPolylineList
{
   //  Count allocated for the polylines (regarding the _PolylineLength table)
   int _PolylineAllocatedCount ;

   //  Count allocated for vertices (regarding the _Vertex table) 
   int _VertexAllocatedCount ;

   //  polylines count
   int _PolylineCount ;

   //  Total vertices (all polylines included) count
   int _VertexCount ;

   //  table of polylines length (the addition of all these length is equal to _VertexCount)
   int *_PolylineLength ;

   //  Vertices (X and Y alternatively)
   float *_Vertex ;
};

//--------------------------------------------------------------------------

/** @nodoc */
struct CAT2DGeomTextTriPrimitiveList
{
   //  Count allocated for the triangle primitives
   int _PrimitiveAllocatedCount;

   //  Count allocated for the vertex index (regarding the _VertexIndex table) 
   int _VertexIndexAllocatedDimension ;

   //  Count allocated for the vertex coordinates (regarding the _Vertex table)
   int _VertexAllocatedCount ;

   //  triangle primitives count
   int _PrimitiveCount ;

   //  Dimension for the Vertex index
   int _VertexIndexDimension ;

   //  Vertex coordinates count
   int _VertexCount ;

   //  table of primitive type (_PrimitiveCount)
   //  4: triangles (GL_TRIANGLES),
   //  5: triangle strip (GL_TRIANGLE_STRIP),
   //  6: triangle fan (GL_TRIANGLE_FAN), 
   int* _PrimitiveType ;

   //  table of primitive length (_PrimitiveCount), the addition of all these length is equal to _VertexIndexDimension
   int *_PrimitiveLength ;

   //  Index of vertices (_VertexIndexDimension), an element in this index is a subscript into the _Vertex table
   int* _VertexIndex ;

   //  Coordinates of vertices (X and Y alternatively, dimension _VertexCount)
   float *_Vertex ;
};

//--------------------------------------------------------------------------

/** @nodoc */
struct CAT2DGeomTextPixmap
{
   // Position
   float _Position[2]; /* model coordinates */

   // Origin
   float _Origin[2];/* location of the origin (first glyph left base point) in the
                    bitmap image, in pixel coordinates.
                    This is the bitmap point to map on the _Position 
                    model position */

   // Pixmap
   CATPixelImage* _Pixmap; /* RGBA, 4 byte per pixel */
};

//--------------------------------------------------------------------------

/** @nodoc */
struct CAT2DGeomGlyphPixmap
{
   // Origin
   float _Origin[2];// location of the origin (glyph left base point) in the bitmap image, in pixel coordinates.
                    // This is the bitmap point to map on the ( _Position + preceeding _Move(s) ) model position

   // Move 
   float _Move[2];  // offset to be added to the current model position after the bitmap is drawn. In model coordinates.
   
   // Pixmap
   CATPixelImage* _Pixmap; // RGBA, 4 byte per pixel 
};

//--------------------------------------------------------------------------

/** @nodoc */
struct CAT2DGeomTextPixmapList
{
   // Position
   float _Position[2]; // model coordinates 

   // Allocated glyph table
   int _GlyphAllocatedCount ;

   // Glyph count
   int _GlyphCount ;

   // Glyphs
   CAT2DGeomGlyphPixmap* _Glyph;
};

//--------------------------------------------------------------------------

/** @nodoc */
struct CAT2DGeomGlyphBitmap
{
   // Origin
   float _Origin[2];// location of the origin in the bitmap image. This is the bitmap point to map on the _Position model position */
   
   // Move 
   float _Move[2];  // offset to be added to the current raster position after the bitmap is drawn. In raster coordinates. */
   
   // Bitmap
   unsigned char* _Bitmap; // 1 bit per pixel, row after row, 1-byte alignement at the end of each row */
};

//--------------------------------------------------------------------------

/** @nodoc */
struct CAT2DGeomTextBitmapList
{
   // Position
   float _Position[2]; // model coordinates 

   // Width of each bitmap (pixel count)
   int _Width;

   // Height of each bitmap 
   int _Height;

   // Allocated glyph table
   int _GlyphAllocatedCount ;

   // Glyph count
   int _GlyphCount ;

   // Glyphs
   CAT2DGeomGlyphBitmap* _Glyph;
};

//--------------------------------------------------------------------------

/** @nodoc */
struct CATFont2DMapping
{
   double _SourcePoint[2];
   double _DestinationPoint[2];
   double _Factor;
   short _ImageDimension[2]; // dimensions of the image in bitmap coordinates, all contours tesselated segments will have their
                             // abscissa comprised between 0 and ImageDimension[0], and their ordinate comprised between 0 and ImageDimension[1]
};

//--------------------------------------------------------------------------

/** @nodoc */
struct FloatVertex
{
   float X;
   float Y;
};

//--------------------------------------------------------------------------

#endif 









