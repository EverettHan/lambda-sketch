#ifndef CAT3DReferencePlaneProperties_h
#define CAT3DReferencePlaneProperties_h

#include "CATVisItf.h"

#include "CATSysErrorDef.h"
#include "CATSysDataType.h"
#include "CATSysBoolean.h"
#include "CATUnicodeString.h"

#include "CATMathPointf.h"
#include "CATMathDirectionf.h"

#include "CAT3DReferencePlaneRenderingProperties.h"

#include <cstdint>

/** @nodoc */
class ExportedByCATVisItf CAT3DReferencePlaneProperties
{
public:

    /** @nodoc */
    CAT3DReferencePlaneProperties();

    /** @nodoc */
    /*
    *    -------------------------------------     ^
    *    |                                   |     |
    *    |             iDirectionV           |     |
    *    |                 ^                 |     |
    *    |                 |                 |     |
    *    |                 |    iDirectionU  |     |
    *    |                 x  ----->         |     | iLengthV
    *    |             iOrigin               |     |
    *    |                                   |     |
    *    |                                   |     |
    *    |                                   |     |
    *    |                                   |     |
    *    -------------------------------------     v
    *
    *    <----------------------------------->
    *                  iLengthU
    *
    */
    CAT3DReferencePlaneProperties(
        const CATMathPointf& iOrigin,
        const CATMathDirectionf& iDirectionU, float iLengthU,
        const CATMathDirectionf& iDirectionV, float iLenghtV,
        CATBoolean iZoomable);

    /** @nodoc */
    CAT3DReferencePlaneProperties(const CAT3DReferencePlaneProperties& iProperties);

    /** @nodoc */
    CAT3DReferencePlaneProperties& operator=(const CAT3DReferencePlaneProperties& iProperties);

    /** @nodoc */
    ~CAT3DReferencePlaneProperties();

    /** @nodoc */
    bool operator == (const CAT3DReferencePlaneProperties& iProperties) const;

    /** @nodoc */
    bool operator != (const CAT3DReferencePlaneProperties& iProperties) const;

    /** @nodoc */
    void SetZoomable(CATBoolean iZoomable);

    /** @nodoc */
    CATBoolean IsZoomable() const;

    /** @nodoc */
    void SetAutoSize(CATBoolean iAutoSize);

    /** @nodoc */
    CATBoolean IsAutoSize() const;

    /** @nodoc */
    void SetLabel(const CATUnicodeString& iLabel);

    /** @nodoc */
    void GetLabel(CATUnicodeString& ioLabel) const;

    /** @nodoc */
    void SetDirections(const CATMathDirectionf& iDirectionU, const CATMathDirectionf& iDirectionV);

    /** @nodoc */
    void GetDirections(CATMathDirectionf& oDirectionU, CATMathDirectionf& oDirectionV) const;

    /** @nodoc */
    void SetDimensions(const CATMathPointf& iOrigin, float iLengthU, float iLenghtV);

    /** @nodoc */
    void GetDimensions(CATMathPointf& oOrigin, float& oLengthU, float& oLenghtV) const;

    /**
    * @nodoc
    * Based on KnowledgeInterfaces/PublicInterfaces/CATCkeScale.h
    */
    enum CATRangeScale
    {
        CATNormalScale = 1,
        CATLargeScale = 2,
        CATExtraLargeScale = 3,
        CATSmallScale = 4,
        CATExtraSmallScale = 5,
        CATNanometricScale = 6

    };

    /** @nodoc */
    void SetRangeScale(CATRangeScale iRangeScale);

    /** @nodoc */
    void GetRangeScale(CATRangeScale& oRangeScale) const;

    /* @nodoc Helper functions */
    float GetRangeScaleFactor() const;

    /** @nodoc */
    void SetRenderingProperties(const CAT3DReferencePlaneRenderingProperties& iRenderingProperties);

    /** @nodoc */
    void GetRenderingProperties(CAT3DReferencePlaneRenderingProperties& oRenderingProperties) const;

private:

    float _lengthU, _lengthV;
    CATUnicodeString _label;
    CATMathPointf _origin;
    CATMathDirectionf _dirU, _dirV;
    std::uint8_t _zoomable   : 1;
    std::uint8_t _autoSize   : 1;
    std::uint8_t _rangeScale : 3;
    //std::uint8_t _padding  : 3;

    CAT3DReferencePlaneRenderingProperties _renderingProperties;
};

#endif
