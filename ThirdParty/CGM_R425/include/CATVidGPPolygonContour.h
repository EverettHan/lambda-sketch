//===================================================================
// COPYRIGHT Dassault Systemes 2012
//===================================================================
#ifndef CATVidGPPolygonContour_H
#define CATVidGPPolygonContour_H
#include <VisuDialog.h>
#include <CATBoolean.h>
//-----------------------------------------------------------------------
/**
 * Valur class that define a contour, used by the widgget CATVidGPPolygon.
 */
class CATMathPoint2Df;
class ExportedByVisuDialog CATVidGPPolygonContour
{
public:
  /** Constructor */
  CATVidGPPolygonContour ();
  /** Constructor */
  CATVidGPPolygonContour (int i_nbPoints, float* i_pPoints);
  /** Destructor */
  ~CATVidGPPolygonContour ();
  /** Copy constructor */
  CATVidGPPolygonContour (const CATVidGPPolygonContour &i_contour);
  /** operator= */
  CATVidGPPolygonContour& operator=(const CATVidGPPolygonContour& i_contour);
  /** friend operator == */
  friend inline int operator == (const CATVidGPPolygonContour &i_poly1, const CATVidGPPolygonContour &i_poly2);
  /** @return the number of points of the contour */
  int GetNbPoints() const;
  /** @return the points of the contour */
  float* GetPoints() const;
  /** Builds a circle */
  static CATVidGPPolygonContour CreateCircleContour(float i_radius, float i_sag=0.1f);
  /** Builds a star */
  static CATVidGPPolygonContour CreateStarContour(float i_bigRadius, float i_littleRadius, int i_nbBranch);
  /** Builds a pie */ 
  static CATVidGPPolygonContour CreatePieContour(float i_radius, int i_startAngleInDegree, int i_pieAngleInDegree, float i_sag=0.1f);
  /** Builds a donut */ 
  static CATVidGPPolygonContour CreateDonutContour(float i_bigradius, float i_littleRadius, int i_startAngleInDegree, int i_pieAngleInDegree, float i_sag=0.1f);
  /** Builds a rounded square */
  static CATVidGPPolygonContour CreateRoundedSquareContour(CATMathPoint2Df& i_dimension, int corners, float i_cornerRadius, int i_BorderThickness = 0, float i_sag = 0.1f);

private:
  int _nbPoints;
  float* _pPoints;
};

int operator == (const CATVidGPPolygonContour &i_poly1, const CATVidGPPolygonContour& i_poly2)
{
  if (i_poly1._nbPoints!=i_poly2._nbPoints)
    return 0;
  for (int i =0; i<(i_poly1._nbPoints*2); i++)
    if (i_poly1._pPoints[i]!=i_poly2._pPoints[i])
      return 0;
  return 1;
}
//-----------------------------------------------------------------------
#include <CATSYPDeclareBoxing.h>
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidGPPolygonContour );
//-----------------------------------------------------------------------
#include <CATSYPFactoryResult.h>
extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidGPPolygonContourFactory(const CATUnicodeString& i_string);
extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidGPPolygonContourSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);
//-----------------------------------------------------------------------
#endif
