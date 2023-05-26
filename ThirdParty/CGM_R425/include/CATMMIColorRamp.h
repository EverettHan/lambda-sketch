//----------------------------------------------------------------------------
//	CATMMIColorRamp.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2002
//----------------------------------------------------------------------------
#ifndef CATMMIColorRamp_H
#define CATMMIColorRamp_H

//#include "CATMMediaRasterFormats.h"
#include "CATMMediaRasterProcessor_Base.h"

const float MMI_BrightnessMin		= -1.0f;
const float MMI_BrightnessDefault	= 0.0f;
const float MMI_BrightnessMax		= 1.0f;

const float MMI_ContrastMin			= -1.0f;
const float MMI_ContrastDefault		= 0.0f;
const float MMI_ContrastMax			= 1.0f;

const float MMI_GammaMin			= 0.0001f;
const float MMI_GammaDefault		= 1.0f;
const float MMI_GammaMax			= 3.0f;


/**
 * @ingroup groupPixelImageTransfo
 */
class ExportedByCATMMediaRasterProcessor_Base CATMMIColorRamp
{
public:
	CATMMIColorRamp();
	// --- don't derive this class ---
	~CATMMIColorRamp() {}

	void Reset();
	void ApplyBrightness(float iScalar);
	void ApplyContrast(float iScalar);
	void ApplyGamma(float iGamma);
	void ApplyNegative();
	void ApplySolarize(float iThreshold);
	void ApplyPosterize(unsigned int iLevels);
	void ApplyStretch(float iLow, float iHigh);

	unsigned char Pick(const unsigned char iIntensity) const  { return _Ramp[iIntensity]; }
	const unsigned char * GetRamp() const { return &_Ramp[0]; }

private:
	// note that this pointer can't be NULL, no need to check it !
	unsigned char * GetFirst() { return &_Ramp[0]; }

	unsigned char _Ramp[256];

	// useless default methods intentionally not accessible (and not generated)
    CATMMIColorRamp(const CATMMIColorRamp&);
    CATMMIColorRamp& operator=(const CATMMIColorRamp&);
};

#endif // CATMMIColorRamp_H
