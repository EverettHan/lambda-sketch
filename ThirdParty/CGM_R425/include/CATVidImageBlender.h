// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATVidImageBlender.h
// Header definition of CATVidImageBlender
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  2009 Creation: jov
//===================================================================
#ifndef CATVidImageBlender_H
#define CATVidImageBlender_H

#include <VisuDialog.h>
#include <CATBoolean.h>
#include <CATVidImageProcessing.h>
//-----------------------------------------------------------------------

/*
 *
 * Class CATVidImageBlender
 *
 */

class ExportedByVisuDialog CATVidImageBlender
{
public:
  // Standard constructors
  // ---------------------
  CATVidImageBlender ();
  virtual ~CATVidImageBlender ();
  CATVidImageBlender (const CATVidImageBlender &i_original);

  CATVidImageBlender& operator=(const CATVidImageBlender& i_original);
  CATBoolean operator==(const CATVidImageBlender& i_right) const;
  CATBoolean operator!=(const CATVidImageBlender& i_right) const;

  void SetBlendingMode(CATVidImageProcessing::BlendingMode i_blendingMode);
  CATVidImageProcessing::BlendingMode GetBlendingMode() const;

  void SetColor(const CATVidColor& i_color);
  const CATVidColor& GetColor() const;

protected : 
private:
  CATVidImageProcessing::BlendingMode _blendingMode;
  CATVidColor _blendingColor;
};
//-----------------------------------------------------------------------

#endif
