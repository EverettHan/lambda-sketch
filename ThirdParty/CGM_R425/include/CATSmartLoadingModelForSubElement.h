#ifndef CATSmartLoadingModelForSubElement_H
#define CATSmartLoadingModelForSubElement_H

//
//  copyright dassault systemes 2004
//  --------------------------------
//
//  FrameWork Visualization :
//  -------------------------
//
//          author : Sebastien VIDECOQ
//                    
//  ---------------------------------------------------------------------------
//

#include "SGInfra.h"
#include "CATLightModelForSubElement.h"
#include "CAT3DViewpoint.h"
#include "CATMathPointf.h"


class CATGraphicPrimitive;
class CATRepWeakRef;

class  ExportedBySGInfra CATSmartLoadingModelForSubElement : public CATLightModelForSubElement 
{
public :
  CATDeclareClass;

  CATSmartLoadingModelForSubElement();
  ~CATSmartLoadingModelForSubElement();

   virtual CATGraphicPrimitive * GetGraphicalObject();
   inline void Set3DViewpoint(CAT3DViewpoint *iViewpoint);
   
   inline CAT3DViewpoint *Get3DViewpoint();
   inline void SetSupportWidthAndHeight(const float iWidth, const float iHeigth);
   inline void SetSupportRatioWH(const float iRatioWH);
   inline void SetPickingWindowSize(const int iPickingWindowSize);
   inline void SetMMInSupportUnit(const float iMMInSupportUnit);

private:
   CAT3DViewpoint *_smartLoadingViewpoint;
   float _supportHeight;
   float _supportWidth;
   float _ratioWH;
   float _mmInSupportUnit;
   int   _pickingWindowSize;
};

inline void CATSmartLoadingModelForSubElement::Set3DViewpoint(CAT3DViewpoint *iViewpoint)
{
  if (!iViewpoint)
	  return;
  
  if (_smartLoadingViewpoint)
	  _smartLoadingViewpoint->Release();
  _smartLoadingViewpoint=new CAT3DViewpoint(*iViewpoint);
}


inline CAT3DViewpoint *CATSmartLoadingModelForSubElement::Get3DViewpoint()
{
   return _smartLoadingViewpoint;
}

inline void CATSmartLoadingModelForSubElement::SetSupportWidthAndHeight(const float iWidth, const float iHeigth)
{
	_supportHeight = iHeigth;
	_supportWidth  = iWidth;
}

inline void CATSmartLoadingModelForSubElement::SetSupportRatioWH(const float iRatioWH)
{
	_ratioWH = iRatioWH;
}

inline void CATSmartLoadingModelForSubElement::SetPickingWindowSize(const int iPickingWindowSize)
{
	_pickingWindowSize = iPickingWindowSize;
}

inline void  CATSmartLoadingModelForSubElement::SetMMInSupportUnit(const float iMMInSupportUnit)
{
	_mmInSupportUnit = iMMInSupportUnit;
}

#endif

