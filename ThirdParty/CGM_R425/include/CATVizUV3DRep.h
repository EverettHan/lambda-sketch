#ifndef CATVizUV3DRep_H
#define CATVizUV3DRep_H

#include "SGInfra.h"
#include "CATVizVertexBufferRep.h"
#include "CATVizRefinementLevel.h"
#include "CATBoolean.h"

class CAT3DFaceGP;
class CATRender;
class CATRep;
class CATRepPath;

#define MAX_REFINEMENTS 1

// SGCAAPlan



class ExportedBySGInfra CATVizUV3DRep : public CATVizVertexBufferRep
{
   CATDeclareClass;

public:
   // SGCAAPlan

   static CATVizUV3DRep* CreateRep();
   static CATVizUV3DRep* CreateRep(CATVizVertexBuffer *vertexBuffer, unsigned int nbSets = 0, CATVizPrimitiveSet **sets = NULL);

protected:

   /** @deprecated R417 : Use CreateRep instead.*/
   CATVizUV3DRep();
   /** @deprecated R417 : Use CreateRep instead.*/
   CATVizUV3DRep(CATVizVertexBuffer *vertexBuffer, unsigned int nbSets = 0, CATVizPrimitiveSet **sets = NULL);

public:

   virtual ~CATVizUV3DRep();

   // AZX: (A2X migration) Making draw functions final 
   virtual void DrawShading(CATRender&, int) override final;
   virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
   virtual void Draw(CATRender& iRender, int iInside) override final;
   virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

   // Update texture coordinates
   virtual void UpdateTextureCoordinates (CATMappingOperator* iOperator = NULL);

   void         SetMesh0Quality(float iQuality);
   float        GetMesh0Quality();
   void         SetQualities(unsigned int nbLevels, const float * qualities);

   HRESULT      SetRefinedLevel(unsigned int iRefinementLevel, CATVizRefinementLevel & iLevel, float iQuality);
   HRESULT      GetRefinedLevel(unsigned int iRefinementLevel, CATVizRefinementLevel & oLevel, float & oQuality);
   CATBoolean   NeedsRefinement(unsigned int iRefinementLevel);
   HRESULT      ClearRefinement(unsigned int iRefinementLevel);
   HRESULT      ClearAllRefinements();
   unsigned int GetNbRefinementLevel();
   unsigned int GetRefinementLevel();
   HRESULT      GetNeededLevel(float iScaledDistanceToEye, float iTargetQuality, unsigned int & oNeededLevel, float & oQuality);

   inline void   SetApplicativeData(void * iData);
   inline void * GetApplicativeData();

   inline void SetDebugRep(CATRep * iDebugRep);

   virtual HRESULT GetIndex(unsigned long iId, unsigned int & oIndex);

   virtual HRESULT RealExplode();

protected:

   virtual HRESULT ActivateRefinement(CATRender & iRender, int inside);
   virtual HRESULT Explode();

   HRESULT DrawRefinementLevel (CATRender & iRender, unsigned int offset, CATBoolean isPathIndex = FALSE);
   HRESULT DrawFaces (CATRender & iRender, unsigned int offset, CATBoolean isPathIndex = FALSE);
   HRESULT DrawEdges (CATRender & iRender, unsigned int offset, CATBoolean isPathIndex = FALSE);

#if BUFFERED
   CATVizRefinementLevel _refinements[MAX_REFINEMENTS];
   float                 _qualities[MAX_REFINEMENTS];
   CATBoolean            _hasRefinedLevel[MAX_REFINEMENTS];
#else
//   CATVizRefinementLevel _refinement;
   float _qualities[MAX_REFINEMENTS];
//   unsigned int _refinedLevel;
#endif
private:
  // Copy constructor and equal operator
// -----------------------------------
  CATVizUV3DRep(CATVizUV3DRep&);
  CATVizUV3DRep& operator=(CATVizUV3DRep&);

};

inline void CATVizUV3DRep::SetApplicativeData(void * iData)
{
}

inline void * CATVizUV3DRep::GetApplicativeData()
{
   return NULL;
}

inline void CATVizUV3DRep::SetDebugRep(CATRep * iDebugRep)
{
}

#endif

