//----------------------------------------------------------------------------
// CAT3DBagRepWithToleranceScale.h
//----------------------------------------------------------------------------
// Usage : this CAT3DBagRep contains the scale information.
//         It is use in extreme scale world or in small scale world.
//         The value of the scale used in the current world is set as parameter.
//----------------------------------------------------------------------------
// Inheritance :
//  CAT3DBagRepWithToleranceScale
//    +CAT3DBagRep
//----------------------------------------------------------------------------
// Copyright DASSAULT SYSTEMES 2006
//----------------------------------------------------------------------------
#ifndef CAT3DBagRepWithToleranceScale_H
#define CAT3DBagRepWithToleranceScale_H

#include "SGInfra.h"
#include "CAT3DBagRep.h"
class CATRender;

class ExportedBySGInfra CAT3DBagRepWithToleranceScale : public CAT3DBagRep
{
	friend class CATDmuStream3DBagRepWithToleranceScale;
	CATDeclareClass;
	
public:

  // Creation of a CAT3DBagRep with the world scale information.
  // It is used for extreme scale world or for small scale world.
  // The value of the scale used in the classic world is set to 1.0f.
  static CAT3DBagRepWithToleranceScale* CreateRep();

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
	CAT3DBagRepWithToleranceScale();
  
  virtual ~CAT3DBagRepWithToleranceScale();
	
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
    virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

    /** @nodoc*/
    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

private :
	float _ToleranceScale;
};

inline HRESULT CAT3DBagRepWithToleranceScale::SetToleranceScale(float iToleranceScale)
{
    _ToleranceScale = iToleranceScale;
    return S_OK;
}

inline HRESULT CAT3DBagRepWithToleranceScale::GetToleranceScale(float& oToleranceScale) const
{
    oToleranceScale = _ToleranceScale;
    return S_OK;
}

#endif // CAT3DBagRepWithToleranceScale_H
