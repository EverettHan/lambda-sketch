//----------------------------------------------------------------------------
// CAT3DFilterBagRepWithToleranceScale.h
//----------------------------------------------------------------------------
// Usage : this CAT3DFilterBagRep contains the scale information.
//         It is use in extreme scale world or in small scale world.
//         The value of the scale used in the current world is set as parameter.
//----------------------------------------------------------------------------
// Inheritance :
//  CAT3DFilterBagRepWithToleranceScale
//    +CAT3DFilterBagRep
//----------------------------------------------------------------------------
// Copyright DASSAULT SYSTEMES 2007
//----------------------------------------------------------------------------
#ifndef CAT3DFilterBagRepWithToleranceScale_H
#define CAT3DFilterBagRepWithToleranceScale_H

#include "SGInfra.h"
#include "CAT3DPLMBagRep.h"
class CATRender;

class ExportedBySGInfra CAT3DFilterBagRepWithToleranceScale : public CAT3DPLMBagRep
{
	friend class CATDmuStream3DFilterBagRepWithToleranceScale;
	
	CATDeclareClass;
	
public:

  // Creation of a CAT3DFilterBagRep with the world scale information.
  // It is used for extreme scale world or for small scale world.
  // The value of the scale used in the classic world is set to 1.0f.
  static CAT3DFilterBagRepWithToleranceScale* CreateRep();

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
	CAT3DFilterBagRepWithToleranceScale();

  virtual ~CAT3DFilterBagRepWithToleranceScale();
	
public:
    // Scale Management
	inline HRESULT SetToleranceScale(float iToleranceScale);
	inline HRESULT GetToleranceScale(float & oToleranceScale) const;

    /** @nodoc */
    virtual void DrawShading   (CATRender & iRender, int iInside) override final;
    
    /** @nodoc */
    virtual void DrawPath      (CATRender & iRender, int iInside, CATRepPath & iRepPath) override final;

    /** @nodoc */
    virtual void Draw          (CATRender & iRender, int iInside) override final;

    /** @nodoc */
    virtual int IsOkToDraw     (CATRender& ioRender, int ioInside) override final;

private :
	float _ToleranceScale;
};

inline HRESULT CAT3DFilterBagRepWithToleranceScale::SetToleranceScale(float iToleranceScale)
{
    _ToleranceScale = iToleranceScale;
    return S_OK;
}

inline HRESULT CAT3DFilterBagRepWithToleranceScale::GetToleranceScale(float& oToleranceScale) const
{
    oToleranceScale = _ToleranceScale;
    return S_OK;
}

#endif // CAT3DFilterBagRepWithToleranceScale_H
