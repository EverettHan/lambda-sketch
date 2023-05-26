#ifndef CATMeshRefiner_H
#define CATMeshRefiner_H

#include "SGInfra.h"
#include "CATErrorDef.h"
#include "CATVizPtrList.h"

class CATMeshFitter;

class CATRep;

class CATRefinementLevel;
class CATVizRefinementLevel;

class ExportedBySGInfra CATMeshRefiner
{
public:

   CATMeshRefiner();
   virtual ~CATMeshRefiner();

   virtual CATMeshFitter* CastToFitter();

   // Full to full
   virtual HRESULT RefineMesh(unsigned int iInputRefinementLevel,
                              unsigned int iTargetRefinementLevel,
                              const CATRefinementLevel & iRefinedLevel,
                              CATRefinementLevel & oRefinedLevel,
                              float & oQuality,
                              void   * & ioApplicativeData,
                              CATRep * & oDebugRep);

   // Light to full
   virtual HRESULT RefineMesh(unsigned int iInputRefinementLevel,
                              unsigned int iTargetRefinementLevel,
                              const CATVizRefinementLevel & iRefinedLevel,
                              CATRefinementLevel & oRefinedLevel,
                              float & oQuality,
                              void   * & ioApplicativeData,
                              CATRep * & oDebugRep);

   // Light to light
   virtual HRESULT RefineMesh(unsigned int iInputRefinementLevel,
                              unsigned int iTargetRefinementLevel,
                              const CATVizRefinementLevel & iRefinedLevel,
                              CATVizRefinementLevel & oRefinedLevel,
                              float & oQuality,
                              void   * & ioApplicativeData,
                              CATRep * & oDebugRep);

   // iActive : 1 => computing On
   // iActive : 0 => computing Off
   virtual HRESULT ActivateQualityCriterion(int iActive);

   // iQualityCriterion : 1 => MaxLiDNi
   // iQualityCriterion : 2 => MaxLiDEi
   // iQualityCriterion : 3 => Max(MaxLiDNi, MaxLiDEi)
   virtual HRESULT SelectQualityCriterion(unsigned int iQualityCriterion);

   // iActive : 1 => option On
   // iActive : 0 => option Off
   virtual HRESULT SetRefOption_UnflipControlPoints(int iActive);
   
   // iActive : 1 => option On
   // iActive : 0 => option Off
   //
   // Default value : Off
   virtual HRESULT SetRefOption_MemOptim_VizVertexBuffer(int iActive);

   // iActive : 1 => option On
   // iActive : 0 => option Off
   //
   // Default value : Off
   virtual HRESULT SetRefOption_MemOptim_NONUniformTess(int iActive);

   // FullSceneGraph
   virtual HRESULT ComputeQuality(unsigned int              iTargetRefinementLevel,
                                  const CATRefinementLevel& iRefinedLevel,
                                  float&                    oQuality);

   // LightSceneGraph
   virtual HRESULT ComputeQuality(unsigned int                 iTargetRefinementLevel,
                                  const CATVizRefinementLevel& iRefinedLevel,
                                  float&                       oQuality);

   virtual HRESULT SetOutputTraces(int iActive);

   virtual HRESULT ClearApplicativeData(void * iApplicativeData) = 0;

   static void             SetRefiner(CATMeshRefiner * iRefiner);
   static CATMeshRefiner * GetRefiner();
   static void             InitRefiner();

  /*
  //==============
  // Pour BuildRep
  //==============

  // iFittingMode : 1 => Iterative
  // iFittingMode : 2 => Bezier
  // iFittingMode : 3 => Iterative, try Bezier if Iterative KO
  // iFittingMode : 4 => Bezier, try Iterative if Bezier KO
  //
  // Default value : Iterative
  virtual HRESULT SetUVBaseMeshFittingMode(int iFittingMode);

	virtual HRESULT CreateUVBaseMesh(const CATRep* ipInRep,
                             			 float         iTargetSag,
												           int	         iTargetRefinementLevel,
												           CATRep*&      iopOutRep);
  */

protected :

   static CATMeshRefiner * sRefiner;

};

#endif
