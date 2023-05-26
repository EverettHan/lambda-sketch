#ifndef CATVisReframeHelper_H
#define CATVisReframeHelper_H

#include "CATVisFoundation.h"

class CATSupport;
class CAT3DViewpoint;
class CATVpReframeData;
class CAT3DBoundingBoxRender;
class CATMathPoint;
class CATVpBBoxReframeData;

class ExportedByCATVisFoundation CATVisReframeHelper
{
  //-------------------------------------------------------------------------------------------

public :

  //  Constructors/destructors
  //--------------------------

	CATVisReframeHelper(CATSupport* iSupport, CAT3DViewpoint* i3DViewPoint, bool bIsClipped = false);
  ~CATVisReframeHelper();

  bool CalculateReframeDetails();

	void DrawBBoxRenderForReframe(CAT3DBoundingBoxRender* render);

	void GetReframeDetails(CATMathPoint& oCenter, float& oFocus, const float width, const float height, 
		const float mmInSupportUnit, const float DimY, const float DimX);
	

private :

	CATVpReframeData* m_oReframeData;
	CATVpBBoxReframeData* m_oBoxReframeInfo;
	CATSupport* m_oSupport;
	CAT3DViewpoint* m_o3DViewpoint;
	bool m_isClipped;

};

#endif
