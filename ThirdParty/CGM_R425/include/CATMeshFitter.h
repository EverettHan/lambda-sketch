#ifndef CATMeshFitter_H
#define CATMeshFitter_H
// COPYRIGHT DASSAULT SYSTEMES 2006
//=============================================================================
// Oct. 06 Creation                                                       HCN
//=============================================================================

#include "CATMeshRefiner.h"

class ExportedBySGInfra CATMeshFitter : public CATMeshRefiner
{
public:

   CATMeshFitter();
   virtual ~CATMeshFitter();

   virtual CATMeshFitter* CastToFitter();

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
		            										int	          iTargetRefinementLevel,
                                    CATRep*&      iopOutRep);

   static void            SetFitter(CATMeshFitter * iFitter);
   static CATMeshFitter * GetFitter();
};

#endif
