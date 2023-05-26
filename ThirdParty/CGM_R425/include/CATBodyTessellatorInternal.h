#ifndef CATBodyTessellatorInternal_h
#define CATBodyTessellatorInternal_h
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2020
//=============================================================================
//
// creator of a CATBodyTessellator object, with bypass of CAA rules
//
//=============================================================================
// 04/11/20 H7W Creation pour bypass contraintes CAA
//=============================================================================

#include "TessAPI.h"
class CATBodyTessellator;
class CATSoftwareConfiguration;

/*
// Une possibilit� est d'avoir une classe de cr�ation
// avec dans CATBodyTessellator
// friend class CATBodyTessellatorCreator;
// 
class ExportedByTessAPI CATBodyTessellatorCreator
{
 public:
    virtual ~CATCurveTessellatorCreator();
    CATBodyTessellatorCreator(CATSoftwareConfiguration *  iConfig          ,
                              CATBody *                   iBody            ,
                               double                      iSag             ,
                               double                      iAngle           ,
                               CATBodyTessellator      *& oBodyTesselator);
};
*/

// Une autre possibilit� est d'avoir une classe d�riv�e
class ExportedByTessAPI CATBodyTessellatorInternal : public CATBodyTessellator
{
  // CATCGMVirtualDeclareClass(CATBodyTessellatorInternal);

 public:
    virtual ~CATBodyTessellatorInternal();
             CATBodyTessellatorInternal(CATSoftwareConfiguration *   iConfig          ,
                                         CATBody *                   iBody            ,
                                         double                      iSag             ,
                                         double                      iAngle = CATPIBY4);
};
#endif
