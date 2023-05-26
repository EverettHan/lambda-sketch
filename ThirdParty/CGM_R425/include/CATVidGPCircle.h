// COPYRIGHT Dassault Systemes 2019
//===================================================================
#ifndef CATVidGPCircle_H
#define CATVidGPCircle_H

#include <VisuDialog.h>
#include <CATVidGP.h>
class CATVidColor;
class CATVidBorder;
/**
 * Colored circle
 * @ingroup VIDGP
 */
class ExportedByVisuDialog CATVidGPCircle : public CATVidGP
{
  CATDeclareClass;

public:
  /**
  * Default constructor
  */
  CATVidGPCircle ();
    /** 
   * Sets the margins used around the layout.
   * By default, these margins are null.
   */
  void SetContentsMargins(const CATVidBorder& i_contentsMargins);

  /**
   * @return the margins used around the layout.
   */
  const CATVidBorder& GetContentsMargins() const;
  void SetRadius(int i_radius);
  int GetRadius() const {return _radius;}

  void SetBorderWidth(int i_borderWidth);
  int GetBorderWidth() const { return _borderWidth;}

  void SetDashedFlag(int i_dashedFlag);
  int GetDashedFlag() const { return _dashedFlag; }

void SetColor(const CATVidColor & i_color);
const CATVidColor &GetColor() const;

protected:
	virtual ~CATVidGPCircle ();

	virtual void UpdateComputedMinimumDimension();


  // Copy constructor and equal operator
  // -----------------------------------
  CATVidGPCircle (CATVidGPCircle &);
  CATVidGPCircle& operator=(CATVidGPCircle&);
  private:
  void UpdateCircleTexture();
private:
  int _borderWidth;
  int _radius; 
  CATBoolean _dashedFlag;
};

//-----------------------------------------------------------------------

#endif
