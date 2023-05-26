// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATBlendSurfaceResult:
// Abstract class of the result of the blend surface operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as it or derived in order to implement 
// specific management of results. 
//
//==========================================================================
// May.  97 TPG Creation                                          Tuan Phung
// 05/06/19 NLD Le constructeur par copie, non couvert et à l'implémentation
//              douteuse, passe en privé
//              Mise au propre
//==========================================================================

#ifndef CATBlendSurfaceResult_H
#define CATBlendSurfaceResult_H

#include "FrFOpeSur.h"

#include "CATFrFOperatorResult.h"
#include "CATNurbsSurface.h"
//--------------------------------------------------------------------------
class ExportedByFrFOpeSur CATBlendSurfaceResult : public CATFrFOperatorResult
{
    public :
    
    virtual               ~CATBlendSurfaceResult   ();

                           CATBlendSurfaceResult   (      CATNurbsSurface       *  surface        );
                           CATBlendSurfaceResult   (      CATNurbsSurface       *  surface        ,
                                                          CATNurbsSurface       *  trimmedsurface );
                           CATBlendSurfaceResult   (      CATNurbsSurface       *  surface        ,
                                                          CATNurbsSurface       *  trimmedsurface1,
                                                          CATNurbsSurface       *  trimmedsurface2);
  
    CATBlendSurfaceResult * Add                    (      CATBlendSurfaceResult *& res);


    CATNurbsSurface       * GetSurface             (      ) const;
    CATNurbsSurface       * GetFirstTrimmedSurface (      ) const;
    CATNurbsSurface       * GetSecondTrimmedSurface(      ) const;

    void                    SetFirstTrimmedSurface (      CATNurbsSurface       * trimmedsurface1);
    void                    SetSecondTrimmedSurface(      CATNurbsSurface       * trimmedsurface2);

    friend ExportedByFrFOpeSur
    void                    Destroy                (      CATBlendSurfaceResult * bye);

    private:
                            CATBlendSurfaceResult  (const CATBlendSurfaceResult & res);

    private :

    CATNurbsSurface  * _BlendResult;
    CATNurbsSurface  * _FirstTrimmedSurface;
    CATNurbsSurface  * _SecondTrimmedSurface;
    
};

#endif
