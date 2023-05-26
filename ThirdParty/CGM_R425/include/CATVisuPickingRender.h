#ifndef CATVisuPickingRender_H
#define CATVisuPickingRender_H

#include "SGInfra.h"
#include "CATPickingRender.h"
#include <stack>

class CATSupport;
class CATPickPathList;
class CATRep;

// This class is currently used for GPU Picking
// It can be used for visu specific picking things in future
class ExportedBySGInfra CATVisuPickingRender : public CATPickingRender
{
  using parent = CATPickingRender;
  CATDeclareClass_Deprec;

public:
  CATVisuPickingRender(const CATSupport &support, const float x, const float y, const float dx, const float dy, CATPickPathList &pickPathList);
  virtual ~CATVisuPickingRender();

  CATVisuPickingRender(const CATVisuPickingRender &) = delete;
  CATVisuPickingRender& operator = (const CATVisuPickingRender &) = delete;

protected:

  // Overrides from CATPickingRender
  int DrawRepresentation(CATRep &iRep, int iInside, void* &iData) override;
  int EndDrawRepresentation(CATRep &iRep, void* &iData) override;

  void BeginDraw(CATViewpoint &viewpoint) override;

protected:

  bool m_ShouldProcessVp;
};

#endif
