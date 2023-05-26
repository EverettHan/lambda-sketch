//===================================================================
// CAT3DAxisSystemRep.h
//===================================================================
#ifndef CAT3DAxisSystemRep_H
#define CAT3DAxisSystemRep_H

#include "SGInfra.h"
#include "CAT3DCustomRep.h"

#include "CATSysDataType.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"

class CAT3DMarkerGP;
class CAT3DFixedPlanGP;
class CAT3DFixedArrowGP;
class CAT3DLineGP;
class CAT3DArrowGP;
class CATRepPath;
class CATRender;
class CATMathPointf;
class CATMathDirectionf;

//-----------------------------------------------------------------------

/** @nodoc */
class ExportedBySGInfra CAT3DAxisSystemRep : public CAT3DCustomRep
{
	friend class CATDmuStream3DAxisSystemRep;
	friend class CAT3DCustomRep;

	CATDeclareClass;

public:

	enum SizeMode { FixedSize, Zoomable, FixedFromSettings };

	// Default constructor
	static CAT3DAxisSystemRep* CreateRep();

	// Fixed size mono-plane constructor.
	static CAT3DAxisSystemRep* CreateRep(
		const CATMathPointf &origin,
		const CATMathDirectionf &u,
		const CATMathDirectionf &v);

	// Zoomable mono-plane constructor.
	static CAT3DAxisSystemRep* CreateRep(
		const CATMathPointf &origin,
		const CATMathDirectionf &u,
		const CATMathDirectionf &v,
		float iLength);

	// Fixed size full axis system constructor
	static CAT3DAxisSystemRep* CreateRep(
		const CATMathPointf &origin,
		const CATMathDirectionf &u,
		const CATMathDirectionf &v,
		const CATMathDirectionf &w);

	// Zoomable full axis system constructor
	static CAT3DAxisSystemRep* CreateRep(
		const CATMathPointf &origin,
		const CATMathDirectionf &u,
		const CATMathDirectionf &v,
		const CATMathDirectionf &w,
		float iLength);
		
protected:

	/** @deprecated R417 : Use CreateRep instead.*/
	CAT3DAxisSystemRep();

	/** @deprecated R417 : Use CreateRep instead.*/
	CAT3DAxisSystemRep(const CATMathPointf &origin, const CATMathDirectionf &u, const CATMathDirectionf &v);

	/** @deprecated R417 : Use CreateRep instead.*/
	CAT3DAxisSystemRep(const CATMathPointf &origin, const CATMathDirectionf &u, const CATMathDirectionf &v, float iLength);

	/** @deprecated R417 : Use CreateRep instead.*/
	CAT3DAxisSystemRep(const CATMathPointf &origin, const CATMathDirectionf &u, const CATMathDirectionf &v, const CATMathDirectionf &w);

	/** @deprecated R417 : Use CreateRep instead.*/
	CAT3DAxisSystemRep(const CATMathPointf &origin, const CATMathDirectionf &u, const CATMathDirectionf &v, const CATMathDirectionf &w, float iLength);

	virtual ~CAT3DAxisSystemRep();

public:

	/** @deprecated R421. Use GetLength instead*/
	// Soon only a float value will be returned
	inline int GetAxisSystemLength();

	// Set the size mode and the dedicated length
	// NB : length is useless in case of FixedFromSettings mode
	HRESULT SetSizeModeAndLength(SizeMode iMode, float iLength);

	// Get the length according to the actual visual mode (zoomable or not)
	float GetLength() const;

	// Get the size mode
	SizeMode GetSizeMode() const;

	// ------------------------- //
	// ---- Mono plane APIs ---- //
	// ------------------------- //

	/** @nodoc */
	inline int IsMonoPlane();

	/** @nodoc */
	CAT3DFixedPlanGP * GetPlane();

	/** @nodoc */
	CAT3DLineGP * GetZoomablePlane() const;

	// ------------------------------- //
	// ---- Full axis system APIs ---- //
	// ------------------------------- //

	/** @nodoc */
	CAT3DMarkerGP * GetOrigin();

	/** @nodoc */
	CAT3DFixedArrowGP * GetXAxis();
	/** @nodoc */
	CAT3DFixedArrowGP * GetYAxis();
	/** @nodoc */
	CAT3DFixedArrowGP * GetZAxis();

	/** @nodoc */
	CAT3DFixedPlanGP * GetXYPlane();
	/** @nodoc */
	CAT3DFixedPlanGP * GetYZPlane();
	/** @nodoc */
	CAT3DFixedPlanGP * GetXZPlane();

	/** @nodoc */
	CAT3DArrowGP * GetZoomableXAxis() const;
	/** @nodoc */
	CAT3DArrowGP * GetZoomableYAxis() const;
	/** @nodoc */
	CAT3DArrowGP * GetZoomableZAxis() const;

	/** @nodoc */
	CAT3DLineGP * GetZoomableXYPlane() const;
	/** @nodoc */
	CAT3DLineGP * GetZoomableYZPlane() const;
	/** @nodoc */
	CAT3DLineGP * GetZoomableXZPlane() const;

private:
	/** @nodoc */
	virtual void InternalDrawShading(CATRender& iRender, int iInside);

	CAT3DAxisSystemRep(CAT3DAxisSystemRep &);
	CAT3DAxisSystemRep& operator=(CAT3DAxisSystemRep&);

	/** @nodoc */
	HRESULT TurnFixedIntoZoomable();

	/** @nodoc */
	HRESULT TurnZoomableIntoFixed();

	/** @nodoc */
	HRESULT TurnFixedArrowIntoZoomableArrow(CAT3DFixedArrowGP* iArrow, CATMathPointf& oOrigin, CATMathDirectionf& oDirection);

	/** @nodoc */
	HRESULT TurnZoomableArrowIntoFixedArrow(CAT3DArrowGP* iArrow, CATMathPointf& oOrigin, CATMathDirectionf& oDirection);

	/** @nodoc */
	HRESULT TurnFixedPlaneIntoZoomablePlane(CAT3DFixedPlanGP* iPlan, const CATMathPointf& iOrigin, const CATMathDirectionf& iDirection1, const CATMathDirectionf& iDirection2);

	/** @nodoc */
	HRESULT TurnZoomablePlaneIntoFixedPlane(CAT3DLineGP* iPlan, int VisuMode, const CATMathPointf& iOrigin, const CATMathDirectionf& iDirection1, const CATMathDirectionf& iDirection2);

	/** @nodoc */
	HRESULT ResizePrimitives();

	/** @nodoc */
	HRESULT ResizeFixedPlane(CAT3DFixedPlanGP* iPlan);

	/** @nodoc */
	HRESULT ResizeZoomablePlane(CAT3DLineGP* iPlan, int VisuMode, const CATMathPointf& iOrigin, const CATMathDirectionf& iDirection1, const CATMathDirectionf& iDirection2);

	/** @nodoc */
	HRESULT ResizeFixedArrow(CAT3DFixedArrowGP* iArrow);

	/** @nodoc */
	HRESULT ResizeZoomableArrow(CAT3DArrowGP* iArrow, CATMathPointf& oOrigin, CATMathDirectionf& oDirection);

	/** @nodoc */
	HRESULT GenerateAndReplaceZoomableArrow(CATGraphicPrimitive* iArrow, const CATMathPointf& iOrigin, const CATMathDirectionf& iDirection, char* iText);

	/** @nodoc */
	HRESULT GenerateAndReplaceZoomablePlane(CATGraphicPrimitive* iPlan, int VisuMode, const CATMathPointf& iOrigin, const CATMathDirectionf& iDirection1, const CATMathDirectionf& iDirection2);

	/** @nodoc */
	CAT3DLineGP* CreateZoomableHalfPlane(const CATMathPointf& iO, const CATMathDirectionf& iU, const CATMathDirectionf& iV);

	/** @nodoc */
	CAT3DLineGP* CreateZoomableFullPlane(const CATMathPointf& iO, const CATMathDirectionf& iU, const CATMathDirectionf& iV);

	/** @nodoc */
	static HRESULT ComputeOriginAndDirections(CAT3DLineGP* iMonoPlane, CATMathPointf& oOrigin, CATMathDirectionf& oU, CATMathDirectionf& oV);

	/** @nodoc */
	CAT3DFixedPlanGP* InternalGetAxisSystemPlane(unsigned int index) const;

	/** @nodoc */
	CAT3DFixedArrowGP* InternalGetAxisSystemArrow(unsigned int index) const;

	/** @nodoc */
	CAT3DLineGP* InternalGetAxisSystemZoomablePlane(unsigned int index) const;

	/** @nodoc */
	CAT3DArrowGP* InternalGetAxisSystemZoomableArrow(unsigned int index) const;

	/** @nodoc <streaming purpose> */
	CAT3DAxisSystemRep* GetFallbackRep(CATBoolean& oToBeDestroyed);

	int _lengthByScreen;
	float _lengthByModel;
	int _isMonoPlane;
	SizeMode _sizeMode;
};

//-----------------------------------------------------------------------

inline int CAT3DAxisSystemRep::IsMonoPlane()
{
	return _isMonoPlane;
}

inline int CAT3DAxisSystemRep::GetAxisSystemLength()
{
	return _lengthByScreen;
}

#endif
