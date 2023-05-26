#ifndef CATMMEDIARESOLUTIONROUNDSPEC_H
#define CATMMEDIARESOLUTIONROUNDSPEC_H

#include "CATMMediaPixelImage.h"

#include "CATBoolean.h"


class ExportedByCATMMediaPixelImage CATMMediaResolutionRoundSpec
{
public:
  virtual CATBoolean    SetResolutionExtremums(int *ipResolHWMinMax)     = 0;
  virtual CATBoolean    AdjustVideoResolution(int &grabW, int &grabH)    ;
  virtual ~CATMMediaResolutionRoundSpec();

  // Position ioPos in order rectangle to fit in display rectangle
  static CATBoolean     PositionRectangle(int ioPos[2], const int iWidth, const int iHeight, const int iDispWidth, const int iDispHeight);
protected:
  CATMMediaResolutionRoundSpec();
private:
  CATMMediaResolutionRoundSpec(const CATMMediaResolutionRoundSpec&);
  CATMMediaResolutionRoundSpec& operator=(const CATMMediaResolutionRoundSpec&);
};

#endif
