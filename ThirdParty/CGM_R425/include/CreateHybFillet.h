#ifndef CREATEHYBFILLET_H 
#define CREATEHYBFILLET_H 

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATTopDef.h"
#include "CATHybDef.h"
#include "CATSkillValue.h"
#include "HybFillet.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"

//========================================================================
// 
//  Fillet Operator For Shell and Wire : 
// 
//========================================================================
// 
// Usage notes:
// -------------
// 
//  Differents Createxxx methods are available Fillet
//  In case of the method using Body as operande, bodies must contain a 
//  unique domain of correct dimension.
//
//========================================================================


//========================================================================
//  Fillet Body (with ONE Domain) / Body (with ONE Domain)
//  Solutions between InitFaces1 and InitFaces2
//========================================================================
/**
 * Constructs a CATHybOperator that computes topological fillet between two CATShell domains.
 *<br>The two bodies must only contain one shell domain. The resulting body is either the topological
 * fillet (NO_TRIMMING), or the union of the topological fillet and the trimmed supports (TRIMMING).
 * The bodies can be the same, in that case the iOrientation and iOrientation2 parameters are
 * NOT taken into account.
 * <br><b>Orientation</b>: 
 * <ul><li>NO_TRIMMING: The orientation of the resulting body is the orientation
 * of the shell of the first body, corrected by the <tt>iOrientation1</tt> argument.
 * <li>TRIMMING: The resulting body is oriented to the center of the fillet surface.
 * </ul>
 * <br><b>Journal</b>:
 * @param iFactory
 * A pointer to the factory of the resulting body.
 * @param iOrientation1
 * The factor to apply for defining the orientation of the shell domain of <tt>iBody_Support1</tt>
 * @iInitFaces1
 * A list of faces of <tt>iBody_Support1</tt> on which the fillet ribbon is computed.
 * @param iOrientation2
 * The factor to apply for defining the orientation of the shell domain of <tt>iBody_Support2</tt>
 * @iInitFaces2
 * A list of faces of <tt>iBody_Support2</tt> on which the fillet ribbon is computed.
 */
ExportedByHybFillet CATHybOperator * CreateHybFillet(CATGeoFactory           * iFactory,
							                   const CATBody                 * iBody_Support1,
											         CATOrientation            iOrientation1,
											         ListPOfCATFace          * iInitFaces1,
							                   const CATBody                 * iBody_Support2,
							                         CATOrientation            iOrientation2,
											         ListPOfCATFace          * iInitFaces2,
							                         double                    iRadius,
							                         CATHybRelimitationMode    iRelimitationMode = SPLINE,
							                         CATHybSegmentationMode    iSegmentationMode = NO_TRIMMING,
							                         CATSkillValue             iMode = BASIC,
							                         CATCGMJournalList       * iReport = NULL);


//========================================================================
//  Fillet Domain / Domain
//  Solutions between InitFaces1 and InitFaces2
//========================================================================
ExportedByHybFillet CATHybOperator * CreateHybFillet(CATGeoFactory           * iFactory,
							                   const CATBody                 * iBody_Support1,
											   const CATDomain               * iDomain_Support1,
											         CATOrientation            iOrientation1,
											         ListPOfCATFace          * iInitFaces1,
							                   const CATBody                 * iBody_Support2,
											   const CATDomain               * iDomain_Support2,
							                         CATOrientation            iOrientation2,
											         ListPOfCATFace          * iInitFaces2,
							                         double                    iRadius,
							                         CATHybRelimitationMode    iRelimitationMode = SPLINE,
							                         CATHybSegmentationMode    iSegmentationMode = NO_TRIMMING,
							                         CATSkillValue             iMode = BASIC,
							                         CATCGMJournalList       * iReport = NULL);

//========================================================================
//  Fillet on ONE Body Containing ONE Domain
//  Solutions on InitEdges
//========================================================================

ExportedByHybFillet CATHybOperator * CreateHybFillet(CATGeoFactory           * iFactory,
							                   const CATBody                 * iBody,
											         ListPOfCATEdge            iInitEdges,
							                         double                    iRadius,
							                         CATHybRelimitationMode    iRelimitationMode = SPLINE,
							                         CATHybSegmentationMode    iSegmentationMode = NO_TRIMMING,
							                         CATSkillValue             iMode = BASIC,
							                         CATCGMJournalList       * iReport = NULL);

//========================================================================
//  Fillet on ONE Domain
//  Solutions on InitEdges
//========================================================================

ExportedByHybFillet CATHybOperator * CreateHybFillet(CATGeoFactory           * iFactory,
							                   const CATBody                 * iBody,
											   const CATDomain               * iDomain,
											         ListPOfCATEdge            iInitEdges,
							                         double                    iRadius,
							                         CATHybRelimitationMode    iRelimitationMode = SPLINE,
							                         CATHybSegmentationMode    iSegmentationMode = NO_TRIMMING,
							                         CATSkillValue             iMode = BASIC,
							                         CATCGMJournalList       * iReport = NULL);
#endif







