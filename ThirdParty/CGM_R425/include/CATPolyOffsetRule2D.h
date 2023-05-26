/* -*-C++-*-*/
#ifndef CATPolyOffsetRule2D_H
#define CATPolyOffsetRule2D_H

// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyOffsetRule2D.h
// Interface defining custom rules to apply on vertices 2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// February 2016 Creation: dps
//===================================================================

#include "PolygonalOperators.h"        // ExportedBy

#include "CATMathInline.h"

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATMathConstant.h" // CATAngle


class CATPolyVertex2D;
class CATPolyBar2D;

//===================================================================
/**
* Interface defining custom rules to apply on vertices 2D
*/
class ExportedByPolygonalOperators CATPolyOffsetRule2D
{

public:

  /**
  * returns the constant offset information, to avoid to call ApplyLocalOffsetValue()
  * returns FALSE if the offset is variable
  * If the offset is not constant (returning FALSE), the method ApplyLocalOffsetValue will be called for each input vertex
  */
  virtual CATBoolean IsOffsetConstant() const;

  /**
  * Returns <tt>TRUE</tt> to apply locally a specific offset value on the current vertex 2D.
  * use oLocalOffsetValue only if the method returns TRUE
  */
  virtual CATBoolean ApplyLocalOffsetValue (const CATPolyVertex2D * iInitVertexToOffset, double &oLocalOffsetValue) const;


  // ====================
  // Minkowski management
  // ====================

  /**
  * Returns <tt>TRUE</tt> to enable locally the rounded behavior on the current vertex 2D.
  * If the option is enabled, it gives a circular arc result (according to the Minkowski offset specification),
  * else, it gives a sharp vertex computed by extrapolation (in this case, the offset distance is not respected).
  */
  virtual CATBoolean ApplyRoundedOffset (const CATPolyVertex2D * iInitVertexToOffset) const = 0;


  // ====================
  // Sharp management
  // ====================

  /**
  * Returns <tt>TRUE</tt> to enable locally the sharp behavior on the current vertex 2D.
  * If the option is disabled (FALSE), it gives a circular arc result (according to the Minkowski offset specification),
  * else, it gives a sharp vertex computed according to the specified mode oBisectorBehavior :
  * if TRUE  : offseting the vertex into one image in the bisector direction, with respect to the offset distance
  * if FALSE : by extrapolation (in this case, the offset distance is not respected).
  */
  virtual CATBoolean ApplySharpOffset (const CATPolyVertex2D * iInitVertexToOffset, CATBoolean & oBisectorBehavior) const;


  /**
  * This rule allows to force the number of bars to be even for a given Vertex2D to offet in Rounded mode.
  * a <tt>FALSE</tt> answer will lead to increment the number of bars
  * Default implementation returns always TRUE
  */
  virtual CATBoolean AuthorizeOddNumberOfBars(const CATPolyVertex2D * iInitVertexToRoundOffset) const;

  /**
  * This rule allows to force the number of bars to be odd for a given Vertex2D to offet in Rounded mode.
  * a <tt>FALSE</tt> answer will lead to increment the number of bars
  * Default implementation returns always TRUE
  */
  virtual CATBoolean AuthorizeEvenNumberOfBars(const CATPolyVertex2D * iInitVertexToRoundOffset) const;

  /**
  * Returns the accuracy value to drive the approximation of Minkowski circle offset into polylines
  * Usefull even if the Sharp behavior is required, to create for example an half of circle on a wire extremity 
  * (Rounded mode is forced in this type of configuration)
  */
  INLINE double GetSAG() const;

  
  // ====================
  // Advanced management
  // ====================


  /**
  * Returns the potential constant angular step to approximate Minkowski circle offset into polylines
  * This mode is usefull for contexts with angular constraints instead of distance constraints (SweepDraft)
  * The GetSAG will be ignored if GetMaxAngularStep returns TRUE 
  */
  virtual CATBoolean GetMaxAngularStep(double & oMaxAngleStepValue) const;


  /**
  * Returns the instruction to drive (or not) explicitly the direction to offset bars.
  * returns FALSE if the offset direction is explicit
  *
  * The implicit default behavior consists in offseting bars in a direction orthogonal to the target result.
  * If the offset is constant : this direction will be also orthogonal to the input bars.
  * In variable mode, the algorithm will compute the angle depending on the offset variation Vs the bar length, in order to apply a local rotation.
  *
  * This option allows the caller to pilot this behavior independently on the fact the offset value is constant or not.
  * If the direction is explicit (returning FALSE), the method ApplyLocalAngularDeviation will be called for each input bar
  */
  virtual CATBoolean IsOffsetDirectionImplicit() const;

  /**
  * Returns <tt>TRUE</tt> to apply locally a specific angular deviation value on the current bar 2D.
  * use oOffsetDirDeviation only if the method returns TRUE
  */
  virtual CATBoolean ApplyLocalAngularDeviation (const CATPolyBar2D * iInitBarToOffset, CATAngle & oOffsetDirDeviation) const;


protected:

  CATPolyOffsetRule2D(double iSAG);
  virtual ~CATPolyOffsetRule2D();


private:

  CATPolyOffsetRule2D(); // forbidden, no implementation
  CATPolyOffsetRule2D(const CATPolyOffsetRule2D&); // forbidden, no implementation


private:

  double _SAG;
};

// Methods inline
// --------------
INLINE double CATPolyOffsetRule2D::GetSAG() const {
  return _SAG; }



//===================================================================
/**
* Basic implementation of CATPolyOffsetRule2D enabling the Rounded behavior on all sharp vertices 2D
* In this case, the specified offset value will be respected as exact distance between each vertex image and its initial vertex2D
*/
class ExportedByPolygonalOperators CATPolyRoundedOffsetBehavior2D : public CATPolyOffsetRule2D
{

public:

  CATPolyRoundedOffsetBehavior2D(double iSAG);
  virtual ~CATPolyRoundedOffsetBehavior2D() {};

  virtual CATBoolean ApplyRoundedOffset (const CATPolyVertex2D * iInitVertexToOffset) const;
  virtual CATBoolean ApplySharpOffset (const CATPolyVertex2D * iInitVertexToOffset, CATBoolean & oBisectorBehavior) const;


private:

  CATPolyRoundedOffsetBehavior2D(); // forbidden : no implementation
  CATPolyRoundedOffsetBehavior2D(const CATPolyRoundedOffsetBehavior2D&); // forbidden, no implementation

};


//===================================================================

/**
* Basic implementation of CATPolyOffsetRule2D disabling the Rounded behavior on all sharp vertices 2D
* In this case, all convex sharp vertices will be built by intersection of extrapolated offset bars
* and all the distances between images and their initial sharp vertices will be greater than the specified offset value
*/  
class ExportedByPolygonalOperators CATPolySharpOffsetBehavior2D : public CATPolyOffsetRule2D
{

public:

  CATPolySharpOffsetBehavior2D(double iSAG, CATBoolean iBisectorMode=FALSE);
  virtual ~CATPolySharpOffsetBehavior2D() {};

  virtual CATBoolean ApplyRoundedOffset (const CATPolyVertex2D * iInitVertexToOffset) const;
  virtual CATBoolean ApplySharpOffset (const CATPolyVertex2D * iInitVertexToOffset, CATBoolean & oBisectorBehavior) const;


private:

  CATPolySharpOffsetBehavior2D(); // forbidden : no implementation
  CATPolySharpOffsetBehavior2D(const CATPolySharpOffsetBehavior2D&); // forbidden, no implementation


private:

  CATBoolean _BisectorMode;
};

#endif
