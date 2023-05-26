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
// Une possibilit� est d'avoir une classe de cr�ation
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

// Une autre possibilit� est d'avoir une classe d�riv�e
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
