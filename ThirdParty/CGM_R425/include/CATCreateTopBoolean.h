#ifndef CATCreateTopBoolean_H 
#define CATCreateTopBoolean_H 

// COPYRIGHT DASSAULT SYSTEMES  2000
/**
* @level Protected
* @usage U1
*/

#include "CATHybDef.h"
#include "BOHYBOPELight.h"
#include "CATBoolean.h"
#include "CATIAV5Level.h"
#include "CATIACGMLevel.h"

/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain
* @param iSelectMode
* The selection of the resulting parts. Here are the legal values:
* <ul>
* <li><tt>BOTH_SIDES</tt>: Keeps all the domains
* <li><tt>POSITIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and the cutting body
* <li><tt>NEGATIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the right 
* of the cutting body 
* <li><tt>POSITIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and to the left 
* of the cutting body 
* <li><tt>NEGATIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the left 
* of the cutting body.
* </ul>
* <ul>
* <li>The right of a shell cut by another shell is the part of the cut shell that is
* pointed out by the orientation of the cutting shell.
* The left side is the other one.
* <li>The right of a shell cut by a wire is the part of the cut shell such that the 
* orientation of the shell, the orientation of the wire and the direction on the selected
* part is direct. 
* <li>The right of a wire cut by a shell, a wire or a vertex is the part of the wire 
* that is pointed out by the
* orientation of the wire.
* </ul>
* @param iExtrapolMode
* The extrapolation mode during a cutting operation.
* This is useful when the cutting body does not cut right along the body to cut, or
* vice versa in case of a trim operation. Here are the legal values:
* <ul>
* <li><tt>NO_EXTRAPOLATION</tt>: No extrapolation is performed. The operator cannot find a solution
* if the cutting body does not cut right along the body to cut.
* <li><tt>TANGENT_DIRECTION</tt>: If the cutting body does not cut right along the body to cut, the extrapolation is
* made tangentially to the scar at the last computed point.
* </ul>
* @return [out, delete]
* The pointer to the created operator. To be deleted after use.
*/
																						
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitShell(CATGeoFactory           *iFactory,
                                                        CATTopData              *iData,
                                                        CATBody                 *iBodyToCut,
                                                        CATBody                 *iCuttingBody,
                                                        CATHybSelectionMode      iSelectMode =  POSITIVE_POSITIVE_SIDE,
                                                        CATHybExtrapolationMode  iExtrapolMode = TANGENT_DIRECTION);


/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain
* @param iSelectMode
* The selection of the resulting parts. Here are the legal values:
* <ul>
* <li><tt>BOTH_SIDES</tt>: Keeps all the domains
* <li><tt>POSITIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and the cutting body. 
* <li><tt>NEGATIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the right 
* of the cutting body. 
* <li><tt>POSITIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and to the left 
* of the cutting body. 
* <li><tt>NEGATIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the left 
* of the cutting body.
* </ul>
* <ul>
* <li>The right of a shell cut by another shell is the part of the cut shell that is
* pointed out by the orientation of the cutting shell.
* The left side is the other one.
* <li>The right of a shell cut by a wire is the part of the cut shell such that the 
* orientation of the shell, the orientation of the wire and the direction on the selected
* part is direct. 
* <li>The right of a wire cut by a shell, a wire or a vertex is the part of the wire 
* that is pointed out by the
* orientation of the wire.
* </ul>
* @param iExtrapolMode
* The extrapolation mode during a cutting operation.
* This is useful when the cutting body does not cut right along the body to cut, or
* vice versa in case of a trim operation. Here are the legal values:
* <ul>
* <li><tt>NO_EXTRAPOLATION</tt>: No extrapolation is performed. The operator cannot find a solution
* if the cutting body does not cut right along the body to cut.
* <li><tt>TANGENT_DIRECTION</tt>: If the cutting body does not cut right along the body to cut, the extrapolation is
* made tangentially to the scar at the last computed point.
* </ul>
* @param iTol
* Defines the tolerance of the geometrically coincident elements to be taken 
* into acccount by <tt>this</tt> operator during the "LayDown" process.
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/

ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitShell(CATGeoFactory           *iFactory,
                                                        CATTopData              *iData,
                                                        CATBody                 *iBodyToCut,
                                                        CATBody                 *iCuttingBody,
                                                        CATHybSelectionMode      iSelectMode,
                                                        CATHybExtrapolationMode  iExtrapolMode,
                                                        double                   iTol);
//
#ifdef CATIACGMV5R19

/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain
* @param iSelectMode
* The selection of the resulting parts. Here are the legal values:
* <ul>
* <li><tt>BOTH_SIDES</tt>: Keeps all the domains
* <li><tt>POSITIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and the cutting body. 
* <li><tt>NEGATIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the right 
* of the cutting body. 
* <li><tt>POSITIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and to the left 
* of the cutting body. 
* <li><tt>NEGATIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the left 
* of the cutting body.
* </ul>
* <ul>
* <li>The right of a shell cut by another shell is the part of the cut shell that is
* pointed out by the orientation of the cutting shell.
* The left side is the other one.
* <li>The right of a shell cut by a wire is the part of the cut shell such that the 
* orientation of the shell, the orientation of the wire and the direction on the selected
* part is direct. 
* <li>The right of a wire cut by a shell, a wire or a vertex is the part of the wire 
* that is pointed out by the
* orientation of the wire.
* </ul>
* @param iExtrapolMode
* The extrapolation mode during a cutting operation.
* This is useful when the cutting body does not cut right along the body to cut, or
* vice versa in case of a trim operation. Here are the legal values:
* <ul>
* <li><tt>NO_EXTRAPOLATION</tt>: No extrapolation is performed. The operator cannot find a solution
* if the cutting body does not cut right along the body to cut.
* <li><tt>TANGENT_DIRECTION</tt>: If the cutting body does not cut right along the body to cut, the extrapolation is
* made tangentially to the scar at the last computed point.
* </ul>
* @param iTol
* Defines the tolerance of the geometrically coincident elements to be taken 
* into acccount by <tt>this</tt> operator during the LayDown process.
* @param iSingleExtrapolMode
* To keep only the no intersecting solutions of extrapolated cuttings mode.
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopNewSplitShell(CATGeoFactory        *iFactory,
                                                        CATTopData              *iData,
                                                        CATBody                 *iBodyToCut,
                                                        CATBody                 *iCuttingBody,
                                                        CATHybSelectionMode      iSelectMode,
                                                        CATHybExtrapolationMode  iExtrapolMode,
                                                        double                   iTol,
                                                        CATBoolean               iSingleExtrapolMode = FALSE );


#else
/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain
* @param iSelectMode
* The selection of the resulting parts. Here are the legal values:
* <ul>
* <li><tt>BOTH_SIDES</tt>: Keeps all the domains
* <li><tt>POSITIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and the cutting body. 
* <li><tt>NEGATIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the right 
* of the cutting body. 
* <li><tt>POSITIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and to the left 
* of the cutting body. 
* <li><tt>NEGATIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the left 
* of the cutting body.
* </ul>
* <ul>
* <li>The right of a shell cut by another shell is the part of the cut shell that is
* pointed out by the orientation of the cutting shell.
* The left side is the other one.
* <li>The right of a shell cut by a wire is the part of the cut shell such that the 
* orientation of the shell, the orientation of the wire and the direction on the selected
* part is direct. 
* <li>The right of a wire cut by a shell, a wire or a vertex is the part of the wire 
* that is pointed out by the
* orientation of the wire.
* </ul>
* @param iExtrapolMode
* The extrapolation mode during a cutting operation.
* This is useful when the cutting body does not cut right along the body to cut, or
* vice versa in case of a trim operation. Here are the legal values:
* <ul>
* <li><tt>NO_EXTRAPOLATION</tt>: No extrapolation is performed. The operator cannot find a solution
* if the cutting body does not cut right along the body to cut.
* <li><tt>TANGENT_DIRECTION</tt>: If the cutting body does not cut right along the body to cut, the extrapolation is
* made tangentially to the scar at the last computed point.
* </ul>
* @param iTol
* Defines the tolerance of the geometrically coincident elements to be taken 
* into acccount by <tt>this</tt> operator during the LayDown process.
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopNewSplitShell(CATGeoFactory           *iFactory,
                                                        CATTopData              *iData,
                                                        CATBody                 *iBodyToCut,
                                                        CATBody                 *iCuttingBody,
                                                        CATHybSelectionMode      iSelectMode,
                                                        CATHybExtrapolationMode  iExtrapolMode,
                                                        double                   iTol);

#endif
//
/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain
* @param iSelectMode
* The selection of the resulting parts. Here are the legal values:
* <ul>
* <li><tt>BOTH_SIDES</tt>: Keeps all the domains
* <li><tt>POSITIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and the cutting body. 
* <li><tt>NEGATIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the right 
* of the cutting body. 
* <li><tt>POSITIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and to the left 
* of the cutting body. 
* <li><tt>NEGATIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the left 
* of the cutting body.
* </ul>
* <ul>
* <li>The right of a shell cut by another shell is the part of the cut shell that is
* pointed out by the orientation of the cutting shell.
* The left side is the other one.
* <li>The right of a shell cut by a wire is the part of the cut shell such that the 
* orientation of the shell, the orientation of the wire and the direction on the selected
* part is direct. 
* <li>The right of a wire cut by a shell, a wire or a vertex is the part of the wire 
* that is pointed out by the
* orientation of the wire.
* </ul>
* @param iExtrapolMode
* The extrapolation mode during a cutting operation.
* This is useful when the cutting body does not cut right along the body to cut, or
* vice versa in case of a trim operation. Here are the legal values:
* <ul>
* <li><tt>NO_EXTRAPOLATION</tt>: No extrapolation is performed. The operator cannot find a solution
* if the cutting body does not cut right along the body to cut.
* <li><tt>TANGENT_DIRECTION</tt>: If the cutting body does not cut right along the body to cut, the extrapolation is
* made tangentially to the scar at the last computed point.
* </ul>
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/	

ExportedByBOHYBOPELight CATHybTrim * CATCreateTopTrimShell(CATGeoFactory           *iFactory,
                                                      CATTopData              *iData,
                                                      CATBody                 *iBodyToTrim,
                                                      CATBody                 *iTrimmingBody,
                                                      CATHybSelectionMode      iSelectMode = POSITIVE_POSITIVE_SIDE,
                                                      CATHybExtrapolationMode  iExtrapolMode = TANGENT_DIRECTION);

/** @nodoc */
ExportedByBOHYBOPELight CATHybTrim * CATCreateTopTrimShellWithWirePositionning
                                                     (CATGeoFactory           *iFactory,
                                                      CATTopData              *iData,
                                                      CATBody                 *iBodyToTrim,
                                                      CATBody                 *iTrimmingBody,
                                                      CATBody                 *iCuttingBody,
                                                      CATHybSelectionMode      iSelectMode = POSITIVE_POSITIVE_SIDE);


/**
* Constructs an operator that splits a CATWire domain by a CATShell,a CATWire or a
* CATVertexInVolume domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell, wire or vertexInVolume) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The edges that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The edges that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new vertices are written as <tt>CATCGMJournal::Creation</tt>
* <li>The edges that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one wire
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire, shell or vertexInVolume)
* domain
* @param iSelectMode
* The selection of the resulting parts. Here are the legal values:
* <ul>
* <li><tt>BOTH_SIDES</tt>: Keeps all the domains
* <li><tt>POSITIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and the cutting body. 
* <li><tt>NEGATIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the right 
* of the cutting body. 
* <li><tt>POSITIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and to the left 
* of the cutting body. 
* <li><tt>NEGATIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the left 
* of the cutting body.
* </ul>
* <ul>
* <li>The right of a shell cut by another shell is the part of the cut shell that is
* pointed out by the orientation of the cutting shell.
* The left side is the other one.
* <li>The right of a shell cut by a wire is the part of the cut shell such that the 
* orientation of the shell, the orientation of the wire and the direction on the selected
* part is direct. 
* <li>The right of a wire cut by a shell, a wire or a vertex is the part of the wire 
* that is pointed out by the
* orientation of the wire.
* </ul>
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitWire(CATGeoFactory           *iFactory,
                                                       CATTopData              *iData,
                                                       CATBody                 *iBodyToCut,
                                                       CATBody                 *iCuttingBody,
                                                       CATHybSelectionMode      iSelectMode =  POSITIVE_POSITIVE_SIDE);

/**
* Constructs an operator that splits a CATWire domain by a CATShell,a CATWire or a
* CATVertexInVolume domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell, wire or vertexInVolume) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The edges that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The edges that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new vertices are written as <tt>CATCGMJournal::Creation</tt>
* <li>The edges that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one wire
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire, shell or vertexInVolume)
* domain.
* @param iSelectMode
* The selection of the resulting parts. Here are the legal values:
* <ul>
* <li><tt>BOTH_SIDES</tt>: Keeps all the domains
* <li><tt>POSITIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and the cutting body. 
* <li><tt>NEGATIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the right 
* of the cutting body. 
* <li><tt>POSITIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and to the left 
* of the cutting body. 
* <li><tt>NEGATIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the left 
* of the cutting body.
* </ul>
* <ul>
* <li>The right of a shell cut by another shell is the part of the cut shell that is
* pointed out by the orientation of the cutting shell.
* The left side is the other one.
* <li>The right of a shell cut by a wire is the part of the cut shell such that the 
* orientation of the shell, the orientation of the wire and the direction on the selected
* part is direct. 
* <li>The right of a wire cut by a shell, a wire or a vertex is the part of the wire 
* that is pointed out by the
* orientation of the wire.
* </ul>
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopNewSplitWire(CATGeoFactory           *iFactory,
                                                       CATTopData              *iData,
                                                       CATBody                 *iBodyToCut,
                                                       CATBody                 *iCuttingBody,
                                                       CATHybSelectionMode      iSelectMode =  POSITIVE_POSITIVE_SIDE);

/**
* Constructs an operator that trims two CATWire domains.
* <br>Each body is split by the other one. Each body must only contain 
* one domain.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the first body.
* <br><b>Journal</b>:
* <ul>
* <li>The edges that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The edges that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new vertices are written as <tt>CATCGMJournal::Creation</tt>
* <li>The edges that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToTrim
* A pointer to the body to be trimmed. It must only contain one wire
* domain.
* @param iTrimmingBody
* A pointer to the trimming body. It must only contain one (wire, shell or vertexInVolume)
* domain.
* @param iSelectMode
* The selection of the resulting parts. Here are the legal values:
* <ul>
* <li><tt>BOTH_SIDES</tt>: Keeps all the domains
* <li><tt>POSITIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and the cutting body. 
* <li><tt>NEGATIVE_POSITIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the right 
* of the cutting body. 
* <li><tt>POSITIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the right of the cut body and to the left 
* of the cutting body. 
* <li><tt>NEGATIVE_NEGATIVE_SIDE</tt>: Keeps the domains that are to the left of the cut body and to the left 
* of the cutting body.
* </ul>
* <ul>
* <li>The right of a shell cut by another shell is the part of the cut shell that is
* pointed out by the orientation of the cutting shell.
* The left side is the other one.
* <li>The right of a shell cut by a wire is the part of the cut shell such that the 
* orientation of the shell, the orientation of the wire and the direction on the selected
* part is direct. 
* <li>The right of a wire cut by a shell, a wire or a vertex is the part of the wire 
* that is pointed out by the
* orientation of the wire.
* </ul>
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybTrim * CATCreateTopTrimWire(CATGeoFactory           *iFactory,
                                                     CATTopData              *iData,
                                                     CATBody                 *iBodyToTrim,
                                                     CATBody                 *iTrimmingBody,
                                                     CATHybSelectionMode      iSelectMode = POSITIVE_POSITIVE_SIDE);


/**
* Constructs an operator that disconnects a CATWire.
* <br>Each body is split by the other one. Each body must only contain 
* one domain.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the first body.
* <br><b>Journal</b>:
* <ul>
* <li>The edges that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The edges that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new vertices are written as <tt>CATCGMJournal::Creation</tt>
* <li>The edges that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToDisconnect
* A pointer to the wire to be disconnected.
* @param iDisconnectingBody
* A pointer to the disconnecting body.
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/	
ExportedByBOHYBOPELight CATHybDisconnect * CATCreateTopDisconnectWire(CATGeoFactory           *iFactory,
                                                                 CATTopData              *iData,
                                                                 CATBody                 *iBodyToDisconnect,
                                                                 CATBody                 *iDisconnectingBody);


/**
* Constructs an operator that disconnects a CATShell.
* <br>Each body is split by the other one. Each body must only contain 
* one domain.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the first body.
* <br><b>Journal</b>:
* <ul>
* <li>The edges that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The edges that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new vertices are written as <tt>CATCGMJournal::Creation</tt>
* <li>The edges that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToDisconnect
* A pointer to the shell to be disconnected.
* @param iDisconnectingBody
* A pointer to the disconnecting body.
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/	
ExportedByBOHYBOPELight CATHybDisconnect * CATCreateTopDisconnectShell(CATGeoFactory           *iFactory,
                                                                  CATTopData              *iData,
                                                                  CATBody                 *iBodyToDisconnect,
                                                                  CATBody                 *iDisconnectingBody);


/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain.
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitShellWithKeepRemove(CATGeoFactory           *iFactory,
                                                                      CATTopData              *iData,
                                                                      CATBody                 *iBodyToCut,
                                                                      CATBody                 *iCuttingBody);

/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain.
* @param iExtrapolMode
* The extrapolation mode during a cutting operation.
* This is useful when the cutting body does not cut right along the body to cut, or
* vice versa in case of a trim operation. Here are the legal values:
* <ul>
* <li><tt>NO_EXTRAPOLATION</tt>: No extrapolation is performed. The operator cannot find a solution
* if the cutting body does not cut right along the body to cut.
* <li><tt>TANGENT_DIRECTION</tt>: If the cutting body does not cut right along the body to cut, the extrapolation is
* made tangentially to the scar at the last computed point.
* </ul>
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitShellWithKeepRemove(CATGeoFactory           *iFactory,
                                                                      CATTopData              *iData,
                                                                      CATBody                 *iBodyToCut,
                                                                      CATBody                 *iCuttingBody,
                                                                      CATHybExtrapolationMode  iExtrapolMode);

/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain.
* @param iExtrapolMode
* The extrapolation mode during a cutting operation.
* This is useful when the cutting body does not cut right along the body to cut, or
* vice versa in case of a trim operation. Here are the legal values:
* <ul>
* <li><tt>NO_EXTRAPOLATION</tt>: No extrapolation is performed. The operator cannot find a solution
* if the cutting body does not cut right along the body to cut.
* <li><tt>TANGENT_DIRECTION</tt>: If the cutting body does not cut right along the body to cut, the extrapolation is
* made tangentially to the scar at the last computed point.
* </ul>
* @param iTol
* Defines the tolerance of the geometrically coincident elements to be taken 
* into acccount by <tt>this</tt> operator during the LayDown process.
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitShellWithKeepRemove(CATGeoFactory           *iFactory,
                                                                      CATTopData              *iData,
                                                                      CATBody                 *iBodyToCut,
                                                                      CATBody                 *iCuttingBody,
                                                                      CATHybExtrapolationMode  iExtrapolMode,
                                                                      double                   iTol);



/**
* Constructs an operator that trims two CATShell domains.
* <br>Each body is split by the other one. Each body must only contain 
* one domain.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the first body.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToTrim
* A pointer to the first body to cut. It must contain only one shell domain.
* @param iTrimmingBody
* A pointer to the second body. It must contain only one shell domain.
* @return [out, delete]
* The pointer to the created operator.  To be deleted after use.
*/				

ExportedByBOHYBOPELight CATHybTrim * CATCreateTopTrimShellWithKeepRemove(CATGeoFactory           *iFactory,
                                                                    CATTopData              *iData,
                                                                    CATBody                 *iBodyToTrim,
                                                                    CATBody                 *iTrimmingBody);



/**
* Constructs an operator that trims two CATShell domains.
* <br>Each body is split by the other one. Each body must only contain 
* one domain.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the first body.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToTrim
* A pointer to the first body to cut. It must contain only one shell domain.
* @param iTrimmingBody
* A pointer to the second body. It must contain only one shell domain.
* @param iExtrapolMode
* The extrapolation mode during a cutting operation.
* This is useful when the cutting body does not cut right along the body to cut, or
* vice versa in case of a trim operation. Here are the legal values:
* <ul>
* <li><tt>NO_EXTRAPOLATION</tt>: No extrapolation is performed. The operator cannot find a solution
* if the cutting body does not cut right along the body to cut.
* <li><tt>TANGENT_DIRECTION</tt>: If the cutting body does not cut right along the body to cut, the extrapolation is
* made tangentially to the scar at the last computed point.
* </ul>
* @return [out, delete]
* The pointer to the created operator. To be deleted after use.

*/
ExportedByBOHYBOPELight CATHybTrim * CATCreateTopTrimShellWithKeepRemove(CATGeoFactory           *iFactory,
                                                                    CATTopData              *iData,
                                                                    CATBody                 *iBodyToTrim,
                                                                    CATBody                 *iTrimmingBody,
                                                                    CATHybExtrapolationMode  iExtrapolMode);


/**
* Constructs an operator that splits a CATWire domain by a CATShell,a CATWire or a
* CATVertexInVolume domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell, wire or vertexInVolume) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The edges that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The edges that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new vertices are written as <tt>CATCGMJournal::Creation</tt>
* <li>The edges that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one wire
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire, shell or vertexInVolume)
* domain.
* @return [out, delete]
* The pointer to the created operator. To be deleted after use.
*/
ExportedByBOHYBOPELight CATHybSplit * CATCreateTopSplitWireWithKeepRemove(CATGeoFactory           *iFactory,
                                                                     CATTopData              *iData,
                                                                     CATBody                 *iBodyToCut,
                                                                     CATBody                 *iCuttingBody);


/**
* Constructs an operator that trims two CATWire domains.
* <br>Each body is split by the other one. Each body must only contain 
* one domain.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the first body.
* <br><b>Journal</b>:
* <ul>
* <li>The edges that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The edges that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new vertices are written as <tt>CATCGMJournal::Creation</tt>
* <li>The edges that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToTrim
* A pointer to the first body to cut.
* @param iTrimmingBody
* A pointer to the second body.
* @return [out, delete]
* The pointer to the created operator. To be deleted after use.
*/	

ExportedByBOHYBOPELight CATHybTrim * CATCreateTopTrimWireWithKeepRemove(CATGeoFactory           *iFactory,
                                                                   CATTopData              *iData,
                                                                   CATBody                 *iBodyToTrim,
                                                                   CATBody                 *iTrimmingBody);


#endif
