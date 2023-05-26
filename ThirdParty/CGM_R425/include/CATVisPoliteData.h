// COPYRIGHT Dassault Systemes 2012

#ifndef CATVisPoliteData_H
#define CATVisPoliteData_H

#include "SGInfra.h"
#include "CATVisColor.h"

//-----------------------------------------------------------------------

class ExportedBySGInfra CATVisPoliteData
{
public:
  CATVisPoliteData();
  ~CATVisPoliteData();

  bool operator==(const CATVisPoliteData& iData) const;
  bool operator!=(const CATVisPoliteData& iData) const;

  unsigned int	_meshAlpha;
  unsigned int	_occludedMeshAlpha;
  
	unsigned int	_edgeThicknessDeltaWhenEdgeSelected;	
  unsigned int	_edgeThicknessDeltaWhenFaceSelected;
	unsigned int	_occludedEdgeAlpha;
	unsigned int	_occludedEdgeDotted;

	unsigned int	_ptSize;
  unsigned int  _occludedPtAlpha;
};

class ExportedBySGInfra CATVisAdvancedPoliteData
{
public:

  CATVisAdvancedPoliteData();
  ~CATVisAdvancedPoliteData() {}

  bool operator==(const CATVisAdvancedPoliteData& iData) const;
  bool operator!=(const CATVisAdvancedPoliteData& iData) const;

  CATVisColor _politnessColor;
  CATVisColor _outlineColor;
  CATVisColor _haloColor;

  unsigned int _visibleFaceAlpha;
  unsigned int _occludedFaceAlpha;

  float _faceThickness;
  float _haloIntensity;

  bool  _edgeAndMarkerPolite;

  //----------------------------
  // OBSOLETE properties
  unsigned int _edgeThicknessDelta;
  unsigned int _prehighlightOutlineOnly; 
};

//-----------------------------------------------------------------------

#endif
