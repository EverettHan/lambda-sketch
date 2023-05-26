//===================================================================
// COPYRIGHT Dassault Systemes 2015/03/13
//===================================================================
// CATVidDeprecatedMap_RectangleList.cpp
// Header definition of class CATVidDeprecatedMap_RectangleList
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/03/13 Creation: Code generated by JRA1/AM2
//===================================================================

#ifndef CATVidDeprecatedMap_RectangleList_H
#define CATVidDeprecatedMap_RectangleList_H

#include "VisuDialog.h"
#include <CATVidDeprecatedMap.h>
#include <CATBoolean.h>
#include <CATVidRectangle.h>
#include "CATSetOfObject.h"
#include <CAT4x4Matrix.h>
#include <CATSYPArray.h>
#include <CATSYPCheck.h>
#include <CATSYPHashMap.h>
#include <CATMath.h>
#include "CATMathPoint2Df.h"
#include <CATPixelImage.h>

//-----------------------------------------------------------------------
/**
 * @c CATVidDeprecatedMap_RectangleList is an implementation of @ref CATVidDeprecatedMap 
 * using a list of rectangles. 
 *
 * Constraints:
 *  1)  There are no rectangles that include another rectangles in the list
 *  2)  Two rectangles can be side by side but not being joined
 *  3)  Two rectangles can be interseted but not being joined
 * @see CATVidDeprecatedMap
 * @see CATVidDeprecatedMapFactory
 */
class ExportedByVisuDialog CATVidDeprecatedMap_RectangleList: public CATVidDeprecatedMap
{
public:
// Standard constructors and destructors
// -------------------------------------
CATVidDeprecatedMap_RectangleList ();
virtual ~CATVidDeprecatedMap_RectangleList ();

/**
* One Zone is marked if there is a rectangle that contains the rectangle formed by the zone.
* @see CATVidDeprecatedMap#IsZoneMarked.
*/
CATBoolean IsZoneMarked(const CATMathPoint2Df &  i_position, const CATMathPoint2Df &  i_dimension, CATBoolean i_strictComparison = FALSE);

/**
* @see CATVidDeprecatedMap#IsIntersected
*/
CATBoolean IsIntersected(const CATMathPoint2Df &  i_position, const CATMathPoint2Df &  i_dimension);

/**
* Mark a new deprecated zone in the deprecated Map. @see CATVidDeprecatedMap#MarkZone
*/
CATBoolean MarkZone(const CATMathPoint2Df &  i_position, const CATMathPoint2Df &  i_dimension);

/**
* Retrieve the number of deprecated zones are in the deprecated map
*/
int GetNumberOfZones();

/**
*
*/
void FlushDeprecatedMap();

/**
* This method return a list of the deprecated zones that the deprecated map has
* @return a list of deprecated zones using rectangles
*/
CATSYPDynArray<CATVidRectangle*> GetList();

/**
* @see CATVidDeprecatedMap#CopyToImage
*/
//void CopyToImage(int i_widthViewer, int i_heightViewer, CATString imagePathDeprecatedMap);

/**
* @see CATVidDeprecatedMap#IsValid
*/
//CATBoolean IsValid();

/**
* If the rectangles i_rec1 and i_rec2 intersect each other, this method divide this intersection in
* order to create three rectangles without intersection. The return can be null if there is no neeed to
* split a third rectanngle
* @param i_rec1 this rectangle intersect the rectangle i_rec2
* @param i_rec2 this rectangle intersect the rectangle i_rec1
* @return a thrid rectangle resulted of the spliting process. it can be null if there is no need to have a third rectangle
*/
CATVidRectangle* DivideIntersection(CATVidRectangle *i_rec1, CATVidRectangle *i_rec2);

private:
  
  /** If this flag is null, everytime that one zone is marked, the deprecated map won't check that
   this is contained by another rectangle*/
  CATBoolean _bCheckingRectangleExistenceAtInsertion;
  /** List of rectangles that represents a deprecated zone  */
  CATSYPDynArray<CATVidRectangle*> rectangles; 

  CATVidDeprecatedMap_RectangleList (CATVidDeprecatedMap_RectangleList &);
  CATVidDeprecatedMap_RectangleList& operator=(CATVidDeprecatedMap_RectangleList&);
  
  /**
  * Add a rectangle to the list without checking if the rectangle already exists int the list
  */
  CATBoolean MarkZoneWithoutChecking(const CATMathPoint2Df &  i_position, const CATMathPoint2Df &  i_dimension);

  /**
  * Add a rectangle to the list checking if the rectangle already exists int the list
  */
  CATBoolean MarkZoneChecking(const CATMathPoint2Df &  i_position, const CATMathPoint2Df &  i_dimension);
  /**
  * Remove any rectangle redundant from the deprecated map
  */
  /*void Validate();*/

};

//-----------------------------------------------------------------------

#endif
