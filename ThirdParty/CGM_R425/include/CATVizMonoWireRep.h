#ifndef _CATVizMonoWireRep_
#define _CATVizMonoWireRep_

#include "CAT3DRep.h"
#include "CATGraphicAttributeSet.h"
#include "CATVizAllocator.h"
#include "SGInfra.h"
class CATVizPrimitive;
#include "CATVisMacroForInterfaces.h"
//class CATRepIVisSG3DBodyBOAImpl;
class IVisSG3DBody;

class CATViz3DMarker;
class CATViz3DLine;

class ExportedBySGInfra CATVizMonoWireRep : public CAT3DRep
{
  CATDeclareClass;

public:
  CATVisDeclarePublicInterfaceAdhesion(CATVizMonoWireRep, IVisSG3DBody, CATVizMonoWireRepIVisSG3DBodyBOAImpl);

  static CATVizMonoWireRep* CreateRep();

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CATVizMonoWireRep();

public:

  ~CATVizMonoWireRep();
  void SetMesh0Quality(float quality);
  HRESULT ActivateRefinement(CATRender& iRender, int inside);
  void SetWireEdge(CATViz3DLine* wireEdge, CATGraphicAttributeSet wireEdgeGas);
  void SetWirePoints(CATViz3DMarker* point1, CATViz3DMarker* point2, CATGraphicAttributeSet pointsGas);

  // AZX: (A2X migration) Making draw functions final 
  virtual void DrawShading(CATRender&, int) override final;
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  CATViz3DLine* GetWireEdge();
  CATViz3DMarker* GetFirstPoint();
  CATViz3DMarker* GetLastPoint();
  const CATGraphicAttributeSet& GetWireEdgeAttributes();
  const CATGraphicAttributeSet& GetWirePointsAttributes();
  inline float GetSag();
  inline void SetSag(float sag);
  // index decoding
  CATVizPrimitive* RetrievePrimitiveFromDrawingIndex(unsigned int index);

protected:
  virtual const vDrawInformation* GetDrawInformation();

  CATViz3DLine* _wireEdge;
  CATViz3DMarker* _point1;
  CATViz3DMarker* _point2;
  CATGraphicAttributeSet _wireEdgeGas;
  CATGraphicAttributeSet _pointsGas;
  float _quality;
  float _sag;

  friend class CATVizMonoWireRepIVisREDrawableBOAImpl;
};

inline float CATVizMonoWireRep::GetSag()
{
  return _sag;
}

inline void CATVizMonoWireRep::SetSag(float sag)
{
  _sag = sag;
}


#endif
