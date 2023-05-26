#ifndef CreateHybSegmentation_H 
#define CreateHybSegmentation_H 

// COPYRIGHT DASSAULT SYSTEMES 1999

//=============================================================================
// CreateHybSegmentation:
// Creation of a CATHybOperator that inserts input vertices in input wire.
//
// Usage Notes:
// -----------
//             iBodyToCut should contain one CATWire, iCuttingBody should contain
//             CATVertex only. 2 modes are available : NO_TRIMMING, TRIMMING.
//             TRIMMING cuts the portion of the input wire outside portion of wire
//             limited by the input vertices.
//          LMH Creation
// 16/11/00 NLD Ajout iTopData
// 30/05/01 NLD Ajout CATHybSegmentation_ActivePreciseDegeneratedEdgesReport
// 01/03/04 NLD Suppression définitive de l'ancienne interface: on est desormais
//              toujours un CATTopOperator
// 17/07/17 NLD Smart indent
//              Numerotation des createurs en coherence avec implementation
//=============================================================================

#include <CATHybDef.h>
#include <CATSkillValue.h>
#include <HybBoolean.h>
#include <ListPOfCATBody.h>

class CATTopOperator;
class CATTopData ;

// options de travail de l'operateur; peuvent s'ajouter
// utiliser les valeurs 1, 10, 100, ...
typedef enum { CATHybSegmentation_ActiveReportOnInternalVertices     =    1,
              // les vertex de relimitation heritent des vertex les plus proches 
              // dans la partie eliminee et non des edges
              CATHybSegmentation_ActiveLimitVerticesInheritance      =   10,
              CATHybSegmentation_InactiveFreezeMode                  =  100,
              // le suivi des edges degenerees devient precis, avec 
              // - respect de l'ordre des vertex confondus recus lors
              // de la depose d'information, en cas de pointe multiple
              // - heritage des 2 edges encadrant, ou de l'edge et du vertex si on
              // est en limite
              CATHybSegmentation_ActivePreciseDegeneratedEdgesReport = 1000 }
              CATHybSegmentation_Options ;

//-----------------------------------------------------------------------------CreateHybSegmentation_1_CATBody
// Creation operator with only CATBody as input.
// iOptions is a combination of options, 
// example: iOptions=CATHybSegmentation_ActiveReportOnInternalVertices
//                 + CATHybSegmentation_ActiveLimitVerticesInheritance
//-----------------------------------------------------------------------------
/**
 * Internal Use
 */
ExportedByHybBoolean CATTopOperator *CreateHybSegmentation(
                                           CATGeoFactory           * iFactory           ,
                                           CATTopData              * iTopData           ,
                                     const CATBody                 * iBodyToSegment     ,
                                     const CATBody                 * iSegmentingBody    ,
                                           CATBody                 * iBodyUser          = NULL,
                                           CATHybSegmentationMode    iSegmentMode       = NO_TRIMMING,
                                           int                       iOptions           = 0,
                                           short                     iReportInfo        = 0);

//-----------------------------------------------------------------------------CreateHybSegmentation_2_CATWire
// Creation operator with only CATWire and list of CATVertex as input.
//-----------------------------------------------------------------------------
// NON COVERED. NLD170717
/**
 * Internal Use
 */
ExportedByHybBoolean CATTopOperator *CreateHybSegmentation(
                                           CATGeoFactory           * iFactory           ,
                                           CATTopData              * iTopData           ,
                                     const CATBody                 * iBodyToSegment     ,
                                     const CATBody                 * iSegmentingBody    ,
                                     const CATWire                 * iWireToSegment     ,
                                           CATVertex              ** iSegmentingVertices,
                                           int                       iNbVertices        ,
                                           CATBody                 * iBodyUser          = NULL,
                                           CATHybSegmentationMode    iSegmentMode       = NO_TRIMMING,
                                           int                       iOptions           = 0);

//-----------------------------------------------------------------------------CreateHybSegmentation_3_FreeForm
// Creation operator with only CATBody as input
// segmenting body                                     in (*iSegmentingBodies)[1]
// and specific CATBody designating multiple vertices  in (*iSegmentingBodies)[2]
// (for FreeFrom only).
//-----------------------------------------------------------------------------
/**
 * Internal Use
 */
ExportedByHybBoolean CATTopOperator *CreateHybSegmentation(
                                           CATGeoFactory           * iFactory           ,
                                           CATTopData              * iTopData           ,
                                     const CATBody                 * iBodyToSegment     ,
                                           ListPOfCATBody          * iSegmentingBodies  ,
                                           CATBody                 * iBodyUser          = NULL,
                                           CATHybSegmentationMode    iSegmentMode       = NO_TRIMMING,
                                           int                       iOptions           = 0,
                                           short                     iReportInfo        = 0);
#endif
