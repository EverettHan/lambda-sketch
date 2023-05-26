#ifndef CAT2DScissorBagRep_H
#define CAT2DScissorBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 2002



#include "SGInfra.h"
#include "CAT2DBagRep.h"


class ExportedBySGInfra CAT2DScissorBagRep : public CAT2DBagRep
{

  friend class CATDmuStream2DScissorBagRep;
  CATDeclareClass;


public:

  /**
  * Constructs a representation.
  */
  static CAT2DScissorBagRep* CreateRep(const int nbpoint = 0, const float* polygon = NULL, const int visible = 1);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
    /* @deprecated R425: Use CreateRep */
    CAT2DScissorBagRep(const int nbpoint = 0, const float* polygon = NULL, const int visible = 1);
  END_MIGRATE_REP_CTOR

  /**
  * Copys-Constructs a representation.
  */
  CAT2DScissorBagRep(CAT2DScissorBagRep&);

protected:

  /**
  * Destructor.
  */
  virtual ~CAT2DScissorBagRep(void);

public:

  /**
  * @nodoc
  */
  virtual void SetBorderVisible(const int visible = 1);

  /**
  * @nodoc
  */
  virtual void SetPolygon(const int, const float*, const int visible = 1);

  /**
  * @nodoc
  */
  virtual void ActivateScissor(const int);

  /**
  * @nodoc
  */
  virtual int IsAScissorRep(void) const;

  /**
  * @nodoc
  */
  virtual float* GetScissorPolygon() const;

  // AZX: (A2X migration) This rep is not derived thus making draw functions final 
  /**
  * @nodoc .
  */
  virtual void DrawPath(CATRender&, int, CATRepPath&) override final;
  /**
  * @nodoc .
  */
  virtual void DrawShading(CATRender&, int) override final;
  /**
  * @nodoc .
  */
  virtual void Draw(CATRender& iRender, int iInside) override final;
  /**
  * @nodoc .
  */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

private:

  float* _Polygon;
  int    _IsScissor;

};

#endif
