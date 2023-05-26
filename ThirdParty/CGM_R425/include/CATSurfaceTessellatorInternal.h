#ifndef CATSurfaceTessellatorInternal_h
#define CATSurfaceTessellatorInternal_h
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2020
//=============================================================================
//
// creator of a CATSurfaceTessellator object, with bypass of CAA rules
//
//=============================================================================
// 04/11/20 H7W Creation pour bypass contraintes CAA
//=============================================================================

#include "TessAPI.h"
class CATSurfaceTessellator;
class CATSoftwareConfiguration;

/*
// Une possibilité est d'avoir une classe de création
// avec dans CATSurfaceTessellator
// friend class CATSurfaceTessellatorCreator;
// 
class ExportedByTessAPI CATSurfaceTessellatorCreator
{
 public:
    virtual ~CATSurfaceTessellatorCreator();
    CATSurfaceTessellatorCreator(CATSoftwareConfiguration *  iConfig          ,
                               double                      iSag             ,
                               double                      iAngle           ,
                               CATSurfaceTessellator      *& oSurfaceTesselator);
};
*/

// Une autre possibilité est d'avoir une classe dérivée
class ExportedByTessAPI CATSurfaceTessellatorInternal : public CATSurfaceTessellator
{
  // CATCGMVirtualDeclareClass(CATSurfaceTessellatorInternal);

 public:
    virtual ~CATSurfaceTessellatorInternal();
             CATSurfaceTessellatorInternal(CATSoftwareConfiguration *  iConfig          ,
                                         double                      iSag             ,
                                         double                      iAngle = CATPI * .25);
};
#endif
