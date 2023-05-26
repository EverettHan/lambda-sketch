// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSEntity.h
// Header definition of CATCSEntity
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSEntity_H
#define CATCSEntity_H

#include "CATCDS.h"
#include "CATCDSEnums.h"
#include "CATCDSListP.h"
#include "CATCDSString.h"
#include "CATCDSMutable.h"

class CATCSNEntity;
class CATCDSString;
class CATCSExtendedType;

//-----------------------------------------------------------------------

/**
 * A basic class for all entities.
 */
class ExportedBySolverInterface CATCSEntity
{
public:
  /**
   * Constructs an instance of the entity.
   */
  CATCSEntity();

  virtual ~CATCSEntity();

  /**
   * Retrieves type of the entity.
   * @return
   *   Type of the entity.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const = 0;

  /**
   * Checks whether the entity is matched to a specific type. The entity can
   * be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const;

  /**
   * Sets a user object.
   * @param iPtr
   *   Pointer to the object.
   * @see #GetUserObj
   */
  void SetUserObj(void *iPtr);

  /**
   * Retrieves a user object.
   * @return
   *   Pointer to the object.
   * @see #SetUserObj
   */
  void *GetUserObj() const;

  /**
   * Sets node of the entity.
   * @param ipNode
   *   Pointer to the node.
   * @see #GetNode
   */
  void SetNode(CATCSNEntity *ipNode);

  /**
   * Retrieves node of the entity.
   * @return
   *   Pointer to the node.
   * @see #SetNode
   */
  CATCSNEntity *GetNode() const;

  /**
   * Sets user name of the entity.
   * @param iName
   *   Name of the entity.
   * @see #GetUserName
   */
  void SetUserName(const CATCDSString &iName) const;

  /**
   * Retrieves user name of the entity.
   * @return
   *   Name of the entity.
   * @see #SetUserName
   */
  CATCDSString const & GetUserName() const;

  // DO NOT USE (internal use only)
  void SetName(const CATCDSString &iName) const;
  void GetName(CATCDSString &oName) const;
  CATCDSString const & GetName() const;
  CATCDSBoolean IsModified() const;
  void SetModified(CATCDSBoolean iModified = TRUE);
  CATCDSBoolean IsModifiedFlagSupported() const;

  /**
   * Retrieves an extended type. The method is used for internal purpose. Do
   * not override it.
   * @return
   *   Pointer to an extended type.
   */
  virtual const CATCSExtendedType *GetExtendedType() const;

protected:
  void *_pUserObj;
  CATCDSMutable CATCDSString _name;
  CATCDSMutable CATCDSBoolean _nameSet;
  CATCSNEntity *_pNode;
  CATCDSBoolean _Modified;
  CATCDSBoolean _ModifiedFlagSupported;
  CATCDSMutable CATCDSString _userName;
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSEntity, ExportedBySolverInterface);
CATCDSARRAY_DECLARE(CATCDSListPCATCSEntity);

//-----------------------------------------------------------------------

#endif
