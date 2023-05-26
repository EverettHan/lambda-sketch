#ifndef CAT2DPerforatedPolygonRep_H
#define CAT2DPerforatedPolygonRep_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "SGInfra.h"
#include "CAT2DRep.h"

class CAT2DPerforatedFillPolygonRep;
class CAT2DPolygonGP;
class CATStreamer;

class ExportedBySGInfra CAT2DPerforatedPolygonRep : public CAT2DRep
{
  friend class CATDmuStream2DPerforatedPolygonRep;
  friend class vImplDrawable_CAT2DPerforatedPolygonRep;
  CATDeclareClass;

public:

  /** Constructs a CAT2DPerforatedPolygonRep */
  static CAT2DPerforatedPolygonRep* CreateRep(const int nbContour, const int* NbOfPtPerContour, const float* Coord, const int iFill);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
    /** @deprecated R422 CAT2DPerforatedPolygonRep::CreateRep */
    CAT2DPerforatedPolygonRep(const int nbContour, const int* NbOfPtPerContour, const float* Coord, const int iFill);
  END_MIGRATE_REP_CTOR

protected:

  virtual ~CAT2DPerforatedPolygonRep();

public:

  virtual HRESULT __stdcall QueryInterface(const IID& iIID, void** oPPV);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  virtual void DrawShading(CATRender& iRemder, int iInside) FUNC_OVERRIDE_FINAL;
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) FUNC_OVERRIDE_FINAL;
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;

  virtual void SetGraphicMaterial(CATGraphicMaterial* iMaterial);

  virtual void StreamPerforatedPolygon(CATStreamer& oStr);
  virtual void UnStreamPerforatedPolygon(CATStreamer& iStr);

  CATGraphicMaterial* GetPloygonMaterial() const;
  CATGraphicMaterial* GetGraphicMaterial() const;

  CAT2DPolygonGP* GetPolygonGP();
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);
  virtual int GetGeomIndex(const CATGraphicPrimitive* gp);


protected:
  virtual const vDrawInformation* GetDrawInformation();

private:

  CAT2DPerforatedFillPolygonRep* _polygon;
  CAT2DPolygonGP** _outlines;
  int							_nb_outline;
};

#endif









