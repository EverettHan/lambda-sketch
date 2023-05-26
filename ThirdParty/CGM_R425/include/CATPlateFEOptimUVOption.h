// File : CATPlateFEOptimUVOption.h
// le 20/06/01 : aag

#include "PlateFE.h"

#include "CATBoolean.h"
class CATAllPinpointConstraintsUV;
class CATIMathPlatePPCArray;

class ExportedByPlateFE CATPlateFEOptimUVOption 
{
	public:

		CATPlateFEOptimUVOption(CATAllPinpointConstraintsUV* iAllPPC);
		~CATPlateFEOptimUVOption();

		void Set(CATAllPinpointConstraintsUV* iAllPPC);
		int SetSlideUV(CATIMathPlatePPCArray* iPPCArray, CATBoolean IsSliding);
		double GetExtendSurfInit();
		void SetExtendSurfInit(const double iExtend);

	private:

		CATAllPinpointConstraintsUV* _AllPPC;
		double _ExtendSurfInit;
};
