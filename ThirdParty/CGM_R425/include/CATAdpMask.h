// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATAdpMask.h
// Header definition of  Mask enum
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  April 2012  Creation: ECN
//===================================================================
/**
* @level Protected
* @usage U2
*/
#ifndef CATAdpMask_H
#define CATAdpMask_H

/**
 * Defines the mask to access on attributes on a component.
 * <br><b>Role:</b>Description of the available mask defining a filter to query on database.  
 * <dt> <code><b>MASK_QUERY</b></code>     <dd> Query Mask.
 * <dt> <code><b>MASK_TREE</b></code>      <dd> Tree Mask.
 * <dt> <code><b>MASK_MINIMALID</b></code> <dd> Mask representing the minimal id attributes being most of the time PLM_ExternalID, V_version and minorrevision for IRPC types (when available) and name and revision for ER types (when available).
 */

namespace CATAdpMask {
	enum MaskValue { MASK_QUERY=0, MASK_TREE=1, MASK_MINIMALID=2};
}

#endif
