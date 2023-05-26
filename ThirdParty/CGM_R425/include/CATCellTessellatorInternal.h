#ifndef CATCellTessellatorInternal_h
#define CATCellTessellatorInternal_h
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2020
//=============================================================================
//
// creator of a CATCellTessellator object, with bypass of CAA rules
//
//=============================================================================
// 04/11/20 H7W Creation pour bypass contraintes CAA
//=============================================================================

#include "TessAPI.h"
class CATCellTessellator;
class CATSoftwareConfiguration;
class CATBody;
class CATCell;

/*
// Une possibilité est d'avoir une classe de création
// avec dans CATCellTessellator
// friend class CATCellTessellatorCreator;
// 
class ExportedByTessAPI CATCellTessellatorCreator
{
 public:
    virtual ~CATCellTessellatorCreator();
    CATCellTessellatorCreator(CATSoftwareConfiguration *  iConfig          ,
                              CATBody *                   iReferenceBody   ,
                               double                      iSag             ,
                               double                      iAngle           ,
                               CATCellTessellator      *& oCellTesselator);
    CATCellTessellatorCreator(CATSoftwareConfiguration *  iConfig          ,
                              CATBody *                   iReferenceBody    ,
                              CATCell *                   iCell,
                               double                      iSag             ,
                               double                      iAngle           ,
                               CATCellTessellator      *& oCellTesselator);
    CATCellTessellatorCreator(CATSoftwareConfiguration *  iConfig          ,
                               double                      iSag             ,
                               double                      iAngle           ,
                               CATCellTessellator      *& oCellTesselator);
    CATCellTessellatorCreator(CATSoftwareConfiguration *  iConfig          ,
                              CATCell *                   iCell,
                               double                      iSag             ,
                               double                      iAngle           ,
                               CATCellTessellator      *& oCellTesselator);
};
*/

// Une autre possibilité est d'avoir une classe dérivée
class ExportedByTessAPI CATCellTessellatorInternal : public CATCellTessellator
{
  // CATCGMVirtualDeclareClass(CATCellTessellatorInternal);

 public:
    virtual ~CATCellTessellatorInternal();

            CATCellTessellatorInternal(CATSoftwareConfiguration *   iConfig,
                                        CATBody * iReferenceBody,
                                        double    iSag,
                                        double    iAngle = CATPIBY4);

            CATCellTessellatorInternal(CATSoftwareConfiguration *   iConfig,
                                        CATBody * iReferenceBody,
                                        CATCell * iCell,
                                        double    iSag,
                                        double    iAngle = CATPIBY4);

            CATCellTessellatorInternal(CATSoftwareConfiguration *   iConfig,
                                        double iSag,
                                        double iAngle = CATPIBY4);

            CATCellTessellatorInternal(CATSoftwareConfiguration *   iConfig,
                                        CATCell * iCell,
                                        double    iSag,
                                        double    iAngle = CATPIBY4);
};
#endif
