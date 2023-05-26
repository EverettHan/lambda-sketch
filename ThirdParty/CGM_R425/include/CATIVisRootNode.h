//===================================================================
// COPYRIGHT DS 2010/09/03
//===================================================================
// CATIVisRootNode.cpp
// Header definition of class CATIVisRootNode
//===================================================================
#ifndef CATIVisRootNode_H
#define CATIVisRootNode_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATVisRepresentationRole.h"

class CATRep;

extern ExportedByCATVisItf  IID IID_CATIVisRootNode ;

/**
 * <b>Role</b>: A %CATIVisRootNode aggregates some representations to 
 * a root node that will be displayed in a component that implements %CATIVisRootNode.
 */
class ExportedByCATVisItf CATIVisRootNode: public CATBaseUnknown
{
CATDeclareInterface;

public:
  /**
   * Adds a representation to the root node.
   * @param i_rep the representation to add
   * @param i_repType the type of the representation to add, that will influence
   * the way the representation is displayed.
   * @return a HRESULT value
   * <br><b>Legal values</b>:
   * <ul>
   * <li>S_OK if the operation succeeds </li>
   * <li>E_FAIL if a 3D rep is tried to be added to a %CATIVisRootNode with Is3D false or 
   if a 2D rep is tried to be added to a %CATIVisRootNode with Is3D true</li>
   * </ul>
   */
  virtual HRESULT AddRep (CATRep& i_rep, CATVisRepresentationRole i_repType) = 0;
  /**
   * Removes a representation from the root node.
   * @param i_rep the representation to remove
   * @param i_repType the type of the representation, given to facilitate  its lookup.
   * @param i_invalidateBEFlags a flag determining if the bounding element 
   * must be invalidated or not. Used only for performance purpose. 
   * Should be used if many reps have to be removed at a time, 
   * and must be followed by a call to ForceUpdateBE.
   * @return a HRESULT value
   * <br><b>Legal values</b>:
   * <ul>
   * <li>S_OK if the operation succeeds </li>
   * <li>E_FAIL if a 3D rep is tried to be removed from a CATIVisView with Is3D false or 
   if a 2D rep is tried to be removed from a CATIVisView with Is3D true</li>
   * </ul>
   */
  virtual HRESULT RemoveRep (CATRep& i_rep, CATVisRepresentationRole i_repType, int i_invalidateBEFlag=TRUE) = 0;
  /**
   * Removes all representation of a given type from the root node.
   * @param i_repType the type of the representation.
   * @return a HRESULT value
   * <br><b>Legal values</b>:
   * <ul>
   * <li>S_OK if the operation succeeds.</li>
   * <li>E_FAIL if the operation failed.</li>
   * </ul>
   */
  virtual HRESULT RemoveAll (CATVisRepresentationRole i_repType) = 0;
  /**
   * @return 1 if root node aggregates 3D representations, 0 otherwise. 
   */
  virtual int Is3D()const = 0;
  /**
   * Compute bounding element of the root node, for a given representation role.
   * It will involve some updates that will be done asynchronously most of the time.
   * @param i_repType the type of rep from wich the algo is invalidated. 
   * @return a HRESULT value
   * <br><b>Legal values</b>:
   * <ul>
   * <li>S_OK if the operation succeeds.</li>
   * <li>E_FAIL if the operation failed.</li>
   * </ul>
   */
  virtual HRESULT ComputeBoundingElement( CATVisRepresentationRole i_repType=AllRoles) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIVisRootNode, CATBaseUnknown );

#endif
