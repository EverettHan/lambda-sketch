#ifndef CAT3DReferencePlaneRenderingProperties_h
#define CAT3DReferencePlaneRenderingProperties_h

#include "CATVisItf.h"

#include "CATSysErrorDef.h"
#include "CATSysDataType.h"
#include "CATSysBoolean.h"

/** @nodoc */
class ExportedByCATVisItf CAT3DReferencePlaneRenderingProperties
{
public:

	/** @nodoc */
	CAT3DReferencePlaneRenderingProperties();

	/** @nodoc */
	CAT3DReferencePlaneRenderingProperties(CATBoolean iWireframeMode);

	/** @nodoc */
	CAT3DReferencePlaneRenderingProperties(const CAT3DReferencePlaneRenderingProperties& iProperties);

	/** @nodoc */
	CAT3DReferencePlaneRenderingProperties& operator=(const CAT3DReferencePlaneRenderingProperties& iProperties);

	/** @nodoc */
	~CAT3DReferencePlaneRenderingProperties();

	/** @nodoc */
	bool operator == (const CAT3DReferencePlaneRenderingProperties& iProperties) const;

	/** @nodoc */
	bool operator != (const CAT3DReferencePlaneRenderingProperties& iProperties) const;

	/** @nodoc */
	void SetWireframeMode(CATBoolean iWireframeMode);

	/** @nodoc */
	CATBoolean GetWireframeMode() const;

	/** @nodoc */
	void SetLabelVisibility(CATBoolean iLabelVisibility);

	/** @nodoc */
	CATBoolean GetLabelVisibility() const;

	/** @nodoc */
	void SetOrientationVisibility(CATBoolean iOrientationVisibility);

	/** @nodoc */
	CATBoolean GetOrientationVisibility() const;

	/** @nodoc */
	void SetFrontColorRGB(unsigned char iRed, unsigned char iGreen, unsigned char iBlue);

	/** @nodoc */
	void GetFrontColorRGB(unsigned char& oRed, unsigned char& oGreen, unsigned char& oBlue) const;

	/** @nodoc */
	void SetBackColorRGB(unsigned char iRed, unsigned char iGreen, unsigned char iBlue);

	/** @nodoc */
	void GetBackColorRGB(unsigned char& oRed, unsigned char& oGreen, unsigned char& oBlue) const;

	/** @nodoc */
	void SetOpacity(unsigned char iOpacity);

	/** @nodoc */
	unsigned char GetOpacity() const;

	/** @nodoc */
	// WARNING : oBuffer must be released by caller using 'free' method.
	HRESULT Marshal(unsigned char*& oBuffer, unsigned int& oLength) const;

	/** @nodoc */
	HRESULT UnMarshal(unsigned char* iBuffer, unsigned int iLength);

	/** @nodoc. DO NOT CALL. Internal use only */
	void SetForceWireframeMode(CATBoolean iFlag);
	CATBoolean GetForceWireframeMode() const;

private:

	CATBoolean _wireframeMode					: 1;
	CATBoolean _labelVisibility				: 1;
	CATBoolean _orientationVisibility : 1;
	CATBoolean _forceWireframeMode    : 1;

	unsigned char _frontColorR, _frontColorG, _frontColorB;
	unsigned char _backColorR, _backColorG, _backColorB;
	unsigned char _opacity;
};

#endif
