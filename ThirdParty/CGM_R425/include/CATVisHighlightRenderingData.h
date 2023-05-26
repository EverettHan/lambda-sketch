// COPYRIGHT Dassault Systemes 2012

#ifndef CATVisHighlightRenderingData_H
#define CATVisHighlightRenderingData_H

#include "SGInfra.h"
#include "CATVisColor.h"
#include "CATVisPoliteData.h"
#include "CATColorPathElement.h"

//-----------------------------------------------------------------------

class ExportedBySGInfra CATVisHighlightRenderingData
{
public:
  CATVisHighlightRenderingData();
  ~CATVisHighlightRenderingData();

  bool operator==(const CATVisHighlightRenderingData& iData) const;
  bool operator!=(const CATVisHighlightRenderingData& iData) const;

  enum EMode
  {
    eBasic,
    eAdvanced,
    ePolite,
    eAdvancedPolite
  };

  enum EContextMode
  {
    eHighlight,
    ePreHighlight
  };

  void ComputeFromMode(EMode iMode, EContextMode iContextMode);

  void ComputeAutomaticColor    (const CATVisColor& iColor, const CATVisColor& iAdvancedColor = CATVisColor(), EContextMode iMode = ePreHighlight);
  void ComputeHighlightColor    ();
  void ComputePreHighlightColor ();

  int  IsActivated() const;

  unsigned int  _standardActivation;

  // outline
  unsigned int  _oulineActivation;
  CATVisColor   _outlineColor;

  // Halo
  unsigned int  _haloActivation;
  CATVisColor   _haloColor;
  unsigned int  _haloLevel;
  float         _haloSize;
  float         _haloIntensity;

  // scan effect
  unsigned int  _scanActivation;
  CATVisColor   _scanColor;
  float         _scanIntensity;

  // politness
  unsigned int      _politnessActivation;
  CATVisColor       _politnessColor;
  CATVisPoliteData  _politenessData;

  //+++ Multicolor Highlight
  
  /** 
  If multicolor highlight is enabled, it will be uses as : 
	.) basic highlight  : face color
	.) halo highlight   : scanColor
	.) politness		: politnessColor 
  */
  unsigned int	_multiColorActivation;
  CATVisColor	_multiColorHighlightSlot[CATColorPathElement::eSlotCount]; 
  //--- Multicolor Highlight

  // Advanced Polite
  unsigned int _advancedPolitnessActivation;
  CATVisAdvancedPoliteData _advancedPolitnessData;

};

//-----------------------------------------------------------------------

#endif
