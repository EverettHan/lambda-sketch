#ifndef CATCurveTessellatorInternal_h
#define CATCurveTessellatorInternal_h
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2020
//=============================================================================
//
// creator of a CATCurveTessellator object, with bypass of CAA rules
//
//=============================================================================
// 19/10/20 NLD Creation pour bypass contraintes CAA
//=============================================================================

#include "TessAPI.h"
#include "CATCurveTessellator.h"
class CATCurveTessellator;
class CATSoftwareConfiguration;

/*
// Une possibilité est d'avoir une classe de création
// avec dans CATCurveTessellator
// friend class CATCurveTessellatorCreator;
// 
class ExportedByTessAPI CATCurveTessellatorCreator
{
 public:
    virtual ~CATCurveTessellatorCreator();
    CATCurveTessellatorCreator(CATSoftwareConfiguration *  iConfig          ,
                               double                      iSag             ,
                               double                      iAngle           ,
                               CATCurveTessellator      *& oCurveTesselator);
};
*/

// Une autre possibilité est d'avoir une classe dérivée
class ExportedByTessAPI CATCurveTessellatorInternal : public CATCurveTessellator
{
  // CATCGMVirtualDeclareClass(CATCurveTessellatorInternal);

 public:
    virtual ~CATCurveTessellatorInternal();
    CATCurveTessellatorInternal(CATSoftwareConfiguration *  iConfig          ,
                                double                      iSag             ,
                                double                      iAngle = CATPI*.25);
    /**
    * Runs <tt>this</tt> CATCurveTessellator.
    */
    void Run();

};
#endif
