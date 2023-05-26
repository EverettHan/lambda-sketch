#ifndef CATVidRectangle_h
#define CATVidRectangle_h

// COPYRIGHT DASSAULT SYSTEMES 2011

// Local framework
#include <VisuDialog.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

// System framework
#include <CATBoolean.h>

/**
 * Class representing a rectangle in float precision.
 */
class ExportedByVisuDialog CATVidRectangle
{
  public:
  
  float x;
  float y;
  float width;
  float height;

  /**
   * Default constructor.
   */
  CATVidRectangle();

  /**
   * Constructs a CATVidRectangle from the given coordinates and size.
   */
  CATVidRectangle(float i_x, float i_y, float i_width, float i_height);

  /**
   * Copy constructor.
   */
  CATVidRectangle(const CATVidRectangle& i_original);
  CATVidRectangle& operator=(const CATVidRectangle& i_original);

  CATBoolean operator==(const CATVidRectangle& i_right) const;
  CATBoolean operator!=(const CATVidRectangle& i_right) const;

  CATBoolean IsValid() const;

  inline float Left() const {return x;}
  inline float Right() const {return x + width;}
  inline float Top() const {return y;}
  inline float Bottom() const {return y + height;}

  inline void Translate(float i_x, float i_y) {x += i_x; y += i_y;}

  CATVidRectangle GetIntersection(const CATVidRectangle& i_rectangle)const;

  inline CATBoolean Intersects(const CATVidRectangle& i_rect) const {return ((i_rect.Left() <= Right()) && (i_rect.Right() >= Left()) &&
                                                                       (i_rect.Top() <= Bottom()) && (i_rect.Bottom() >= Top()));}

  inline CATBoolean Contains(const CATMathPoint2Df& i_point) const {return ((i_point.x >= Left()) && (i_point.x <= Right()) &&
                                                                      (i_point.y <= Bottom()) && (i_point.y >= Top()));}

  inline CATBoolean Contains(const CATVidRectangle& i_rect) const {return ((i_rect.Left() >= Left()) && (i_rect.Right() <= Right()) &&
                                                                      (i_rect.Bottom() <= Bottom()) && (i_rect.Top() >= Top()));}
};

#endif // CATVidRectangle_h
