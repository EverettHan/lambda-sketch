//===================================================================
// CAT3DReferencePlaneRep.h
//===================================================================
#ifndef CAT3DReferencePlaneRep_H
#define CAT3DReferencePlaneRep_H

#include "SGInfra.h"
#include "CAT3DRep.h"
#include "CAT3DReferencePlaneSizeMode.h"

class CATRender;
class CATRepPath;
class CATUnicodeString;
class CAT3DReferencePlaneGP;
class CAT3DReferencePlaneProperties;

/** @nodoc */
class ExportedBySGInfra CAT3DReferencePlaneRep : public CAT3DRep
{
	friend class CATDmuStream3DReferencePlaneRep;
	CATDeclareClass;

public:

	/** @nodoc */
	static CAT3DReferencePlaneRep* CreateRep();

	/** @nodoc DEPRECATED */
	static CAT3DReferencePlaneRep* CreateRep(
		const CATMathPointf& iOrigin,
		const CATMathDirectionf& iDirectionU, float iLengthU,
		const CATMathDirectionf& iDirectionV, float iLenghtV,
		CAT3DReferencePlaneSizeMode iSizeMode = CAT3DReferencePlaneSizeMode::FromSettings);

	/** @nodoc */
	static CAT3DReferencePlaneRep* CreateRep(const CAT3DReferencePlaneProperties& iProperties);

protected:

	/** @nodoc */
	virtual ~CAT3DReferencePlaneRep();

public:
	/** @nodoc */
	void SetReferencePlaneProperties(const CAT3DReferencePlaneProperties& iProperties);

	/** @nodoc */
	void GetReferencePlaneProperties(CAT3DReferencePlaneProperties& oProperties) const;

	// AZX: (A2X migration) Making draw functions final 
	/** @nodoc */
	virtual void DrawShading(CATRender&, int) override final;
	/** @nodoc */
	virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
	/** @nodoc */
	virtual void Draw(CATRender& iRender, int iInside) override final;
	/** @nodoc */
	virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

	// DEPRECATED
	void SetSizeMode(CAT3DReferencePlaneSizeMode iSizeMode);
	// DEPRECATED
	void GetSizeMode(CAT3DReferencePlaneSizeMode& ioSizeMode) const;
	// DEPRECATED
	void SetLabel(const CATUnicodeString& iLabel);
	// DEPRECATED
	void GetLabel(CATUnicodeString& ioLabel) const;
	// DEPRECATED
	void SetDirections(const CATMathDirectionf& iDirectionU, const CATMathDirectionf& iDirectionV);
	// DEPRECATED
	void GetDirections(CATMathDirectionf& ioDirectionU, CATMathDirectionf& ioDirectionV) const;
	// DEPRECATED
	void SetDimensions(const CATMathPointf& iOrigin, float iLengthU, float iLenghtV);
	// DEPRECATED
	void GetDimensions(CATMathPointf& ioOrigin, float& ioLengthU, float& ioLenghtV) const;
	// DEPRECATED
	void ResetDimensions();

	/** @nodoc */
	virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

	/** @nodoc */
	virtual int GetGeomIndex(const CATGraphicPrimitive* gp);


protected:

	CAT3DReferencePlaneRep();
	CAT3DReferencePlaneRep(const CAT3DReferencePlaneProperties& iProperties);
  virtual const vDrawInformation* GetDrawInformation();

private:

	/** @nodoc */
	void UpdateBoundingElement();
	
	/** @nodoc <streaming purpose> */
	CATRep* GetFallbackRep() const;

	CAT3DReferencePlaneRep(CAT3DReferencePlaneRep&);
	CAT3DReferencePlaneRep& operator=(CAT3DReferencePlaneRep&);

	CAT3DReferencePlaneGP* _refPlane;
};

#endif
