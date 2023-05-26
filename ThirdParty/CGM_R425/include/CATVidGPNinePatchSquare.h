// COPYRIGHT Dassault Systemes 2013
//===================================================================
#ifndef CATVidGPNinePatchSquare_H
#define CATVidGPNinePatchSquare_H
#include <VisuDialog.h>
#include <CATVidGPTexturedWidget.h>
#include <CATVidBorder.h>
/**
 * This textured widget allows to define efficiently a 9 patch square, that
 * is a square that is associated to a border defining a stretchable central zone.
 * If the customer need to use a more specific stretching configuration, it can use the class #CATVidGPSmartSquare
 * @par sypstyle sample
 * @code
 * <CATVidGPNinePatchSquare ScalableAreaBorder="5" Texture="squareWith5pxBorderAround.png"/>
 * @endcode 
 */
class ExportedByVisuDialog CATVidGPNinePatchSquare: public CATVidGPTexturedWidget
{
  CATDeclareClass;
public:
  /** Constructor */
  CATVidGPNinePatchSquare ();
  /** Sets a border defining the central stretchable area*/
  void SetScalableAreaBorder(const CATVidBorder& i_scalableAreaBorder);
  /** @return the stretchable central area.*/
  const CATVidBorder& GetScalableAreaBorder() const;
  /**
  * Sets a angle of rotation in degree of the texture coordinates (not on the vertices!).
  * Working values are 0, 90, 180, 270. Default value is 0.
  */
  void SetTextureCoordinatesRotation(float i_angle);
  /** @return the angle of rotation in degree of the texture coordinates*/
  float GetTextureCoordinatesRotation()const;
protected:
  virtual ~CATVidGPNinePatchSquare ();
  /** Copy constructor*/
  CATVidGPNinePatchSquare (CATVidGPNinePatchSquare &);
  /** operator =*/
  CATVidGPNinePatchSquare& operator=(CATVidGPNinePatchSquare&);
};

//-----------------------------------------------------------------------

#endif
