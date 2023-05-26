// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisAdvancedHighlightData_H
#define CATVisAdvancedHighlightData_H

#include "SGInfra.h"
#include "CATVisHighlightRenderingData.h"

//-----------------------------------------------------------------------
class ExportedBySGInfra CATVisAdvancedHighlightData : public CATVisHighlightRenderingData
{
public:
  CATVisAdvancedHighlightData();
  ~CATVisAdvancedHighlightData();

  unsigned int  _standardHighlightActivation : 1;
  unsigned int  _advancedHighlightActivation : 1;
};

//-----------------------------------------------------------------------

#endif
