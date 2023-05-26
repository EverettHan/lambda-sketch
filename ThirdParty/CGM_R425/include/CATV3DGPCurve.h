//===================================================================
// COPYRIGHT Dassault Systemes 2013/06/07
//===================================================================
#ifndef CATV3DGPCurve_H
#define CATV3DGPCurve_H

#include "CATV3DGraphicPrimitive.h"
#include <VisuImmersive3D.h>

#include "CATVidColor.h"
#include "CATLISTV_CATMathPoint.h"
//-----------------------------------------------------------------------
/**
 * Base class for V3D graphic primitive curve widget. 
 * 
 * @par Role
 * The representation of this GP is the representation of all V3D curve in the 3D.
 * Vertices may be doubled to keep the proper thickness.
 * Lines will be displayed parallel to the screen.
 *
 * @ingroup V3DGP
 */
class ExportedByVisuImmersive3D CATV3DGPCurve: public CATV3DGraphicPrimitive
{
  CATDeclareClass;
public:
  
  /** Constructor */
  CATV3DGPCurve ();
  /** Destructor */
  virtual ~CATV3DGPCurve ();

  /**
   * Gets the list of vertices
   * @return the list of vertices used to represent the curve
   */
  CATLISTV(CATMathPoint) & GetListVertices();
  /**
   * Sets the list of vertices
   * @param iListVertices the vertices that represent the curve (the drawing may imply to doubled the number of point to keep a proper thickness).
   */
  void SetListVertices(const CATLISTV(CATMathPoint) & iListVertices);

  /**
   * Gets the color of the line
   * @return the color of the line
   */
  const CATVidColor & GetColor() const;
  /**
   * Sets the color of the line
   * @param iColor color to apply
   */
  void SetColor(const CATVidColor & iColor);

  /**
   * Gets the thickness of the line
   * @return the thickness of the curve
   */
  int GetThickness() const;
  /**
   * Sets the thicknesss of the line
   * If the thickness is lower than 4, borderFlag and smoothEdge information will be ignored !
   * @param iThickness thickness to apply
   */
  void SetThickness(int iThickness);
  
  /** 
   * Gets the pickability of the GP
   * @return the pickability of the Rep that represent the curve
   */
  CATBoolean GetPickFlag() const;
  /**
   * Sets the pickability of the GP
   * @param iPickFlag the pickability of the Rep that represent the curve
   */
  void SetPickFlag(const CATBoolean &iPickFlag);
  
  /** 
   * Gets the borderFlag of the GP.
   * @return the borderFlag of the GP, indicating if a border has to be drawn or not
   */
  CATBoolean GetBorderFlag() const;
  /** 
   * Sets the borderFlag of the GP.
   * If thickness has been set with a value lower than 4, this flag will be ignored
   * @param the borderFlag of the GP, 1 if a border has to be drawn, 0 otherwise
   */
  void SetBorderFlag(const CATBoolean &iBorderFlag);
  
  /** 
   * Gets the smoothEdgeFlag of the GP. The value to decide if an edge is smooth enough is smoothEdgeRadius
   * @return the smoothEdgeFlag of the GP, indicating if the edges should be smooth.
   */
  CATBoolean GetSmoothEdgeFlag() const;
  /** 
   * Sets the smoothEdgeFlag of the GP. The value to decide if an edge is smooth enough is smoothEdgeRadius
   * If thickness has been set with a value lower than 4, this flag will be ignored
   * This method only works if fullBufferedDraw is active
   * @param the smoothEdgeFlag of the GP,  1 if edges have to be smooth, 0 otherwise
   */
  void SetSmoothEdgeFlag(const CATBoolean &iSmoothEdgeFlag);
  
  /** 
   * Gets the smoothEdgeRadius of the GP. This value is used to determine if an edge has to be modify to become smooth. 
   * @return the smoothEdgeRadius of the GP
   */
  int GetSmoothEdgeRadius() const;
   /** 
   * Sets the smoothEdgeRadius of the GP. This value is used to determine if an edge has to be modify to become smooth. 
   * This value is ignored if smoothEdgeFlag is false or if thickness has been set with a value lower than 4.
   * This method only works if fullBufferedDraw is active
   * @param the smoothEdgeRadius of the GP
   */
  void SetSmoothEdgeRadius(int iRadius);

private:
  CATV3DGPCurve (CATV3DGPCurve &);
  CATV3DGPCurve& operator=(CATV3DGPCurve&);
};

//-----------------------------------------------------------------------

#endif
