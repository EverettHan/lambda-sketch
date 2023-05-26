//----------------------------------------------------------------------------
// CAT2DBagRepWithToleranceScale.h
//----------------------------------------------------------------------------
// Usage : this CAT2DBagRep contains the scale information.
//         It is use in extreme scale world or in small scale world.
//         The value of the scale used in the current world is set as parameter.
//----------------------------------------------------------------------------
// Inheritance :
//  CAT2DBagRepWithToleranceScale
//    +CAT2DBagRep
//----------------------------------------------------------------------------
// Copyright DASSAULT SYSTEMES 2006
//----------------------------------------------------------------------------
#ifndef CAT2DBagRepWithToleranceScale_H
#define CAT2DBagRepWithToleranceScale_H

#include "SGInfra.h"
#include "CAT2DBagRep.h"
class CATRender;

class ExportedBySGInfra CAT2DBagRepWithToleranceScale : public CAT2DBagRep
{
  friend class CATDmuStream3DBagRepWithToleranceScale;
  CATDeclareClass;

public:
  // Creation of a CAT2DBagRep with the world scale information.
  // It is used for extreme scale world or for small scale world.
  // The value of the scale used in the classic world is set to 1.0f.
  static CAT2DBagRepWithToleranceScale* CreateRep();

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
    /* @deprecated R425: Use CreateRep  */
    CAT2DBagRepWithToleranceScale();
  END_MIGRATE_REP_CTOR

protected:
  
  virtual ~CAT2DBagRepWithToleranceScale();

public:

  // Scale Management
  inline HRESULT SetToleranceScale(float iToleranceScale);
  inline HRESULT GetToleranceScale(float& oToleranceScale) const;

  // AZX: (A2X migration) Making draw functions final 
  /** @nodoc */
  virtual void DrawShading(CATRender& iRender, int iInside)  override final;

  /** @nodoc */
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath)  override final;

  /** @nodoc */
  virtual void Draw(CATRender& iRender, int iInside)  override final;

  /** @nodoc */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

private:
  float _ToleranceScale;
};

inline HRESULT CAT2DBagRepWithToleranceScale::SetToleranceScale(float iToleranceScale)
{
  _ToleranceScale = iToleranceScale;
  return S_OK;
}

inline HRESULT CAT2DBagRepWithToleranceScale::GetToleranceScale(float& oToleranceScale) const
{
  oToleranceScale = _ToleranceScale;
  return S_OK;
}

#endif // CAT2DBagRepWithToleranceScale_H
