#ifndef _CATVizUV3DLine_
#define _CATVizUV3DLine_

#include "SGInfra.h"
#include "CATViz3DLine.h"

#include "CATVisMacroForInterfaces.h"
#include "IVisSG3DPolyline.h"
class CATVizUV3DLineIVisSG3DPolylineBOAImpl;

class ExportedBySGInfra CATVizUV3DLine : public CATViz3DLine
{
public:
   CATVisDeclarePublicInterfaceAdhesion(CATVizUV3DLine, IVisSG3DPolyline, CATVizUV3DLineIVisSG3DPolylineBOAImpl);

   CATVizUV3DLine();
   CATVizUV3DLine(const float iPoints[], const unsigned int iNbPoints=2, const unsigned int iLineType = LINES, const CATVizAllocMode iAllocMode = CATVizAllocModeAllocate, CATBoolean poolAllocated = FALSE);

   /** @nodoc */
   virtual unsigned int GetId();
   
   /** @nodoc */
   virtual void SetId(unsigned int id);

   /** @nodoc */
	virtual void Draw(CATRender &iRender);

   /** @nodoc */
   virtual void Draw(CATRender &iRender, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);

   /** @nodoc */
   virtual CATUVGeometry * GetGeometry();

   inline void SetRefinementLevel(unsigned int refinementLevel);
   inline unsigned int GetRefinementLevel();

protected:
  virtual ~CATVizUV3DLine() = default;

protected:
   unsigned int _id;
};

inline void CATVizUV3DLine::SetRefinementLevel(unsigned int refinementLevel)
{
  _refinementLevel = refinementLevel;
}

inline unsigned int CATVizUV3DLine::GetRefinementLevel()
{
  return _refinementLevel;
}

#endif
