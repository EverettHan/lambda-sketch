#ifndef CAT2DLineGeometryRep_H
#define CAT2DLineGeometryRep_H

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "SGInfra.h"
#include "CAT2DLineRep.h"

class CATMathPoint2Df;

class ExportedBySGInfra CAT2DLineGeometryRep : public CAT2DLineRep
{
  CATDeclareClass;

public:

  static CAT2DLineGeometryRep* CreateRep();
  static CAT2DLineGeometryRep* CreateRep(const float iPoints[], const int iNbPoints, const float iExtremityTangents[4],
    const int iAlloc = ALLOCATE, const int iLinetype = LINES, const TessFlag iTessFlag = LINE);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
    /* @deprecated R425: Use CreateRep*/
    CAT2DLineGeometryRep();
  /* @deprecated R425: Use CreateRep*/
  CAT2DLineGeometryRep(const float iPoints[], const int iNbPoints, const float iExtremityTangents[4],
    const int iAlloc = ALLOCATE, const int iLinetype = LINES, const TessFlag iTessFlag = LINE);
  END_MIGRATE_REP_CTOR


protected:

  virtual ~CAT2DLineGeometryRep();

public:

  /**
  * @nodoc
  * Note: line will not be reversed in case 'DONT_ALLOCATE' flag is used
  *       i.e. points are not duplicated in this class
  */
  virtual void ReverseLineRoute();

  // AZX: (A2X migration) This rep is not derived thus making draw functions final 
  virtual void DrawShading(CATRender&, int) override final;
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

};

#endif 









