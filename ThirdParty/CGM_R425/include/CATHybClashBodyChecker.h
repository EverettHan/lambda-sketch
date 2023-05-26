// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//______________________________________________________________________
//
// CATHybClashBodyChecker.h
//
// Checks a given Body for self intersections
//
//______________________________________________________________________
//
// Usage notes:
// Checks whether a Body self-intersects (Polyhedral check)
//
//______________________________________________________________________
//
// Dec 2011   Creation:  DPS for CATBodySelfIntersector WMN class access
//______________________________________________________________________

#ifndef CATHybClashBodyChecker_h
#define CATHybClashBodyChecker_h

#include "CATCGMOperator.h"
#include "Autocheck.h"          // ExportedBy

// System
#include "CATErrorDef.h"
#include "CATSysBoolean.h"

#include "CATListOfCATCells.h"

class CATBody;
class CATSoftwareConfiguration;
class CATHybClashCellCellIter;

/**
 * Checks a given Body for self intersections
 */

class ExportedByAutocheck CATHybClashBodyChecker : public CATCGMOperator
{
  CATCGMVirtualDeclareClass(CATHybClashBodyChecker);

public:

 /**
  * no public constructor
  * Please, call CATCreateHybClashBodyChecker global function
  * defined at the end of this header
  */

 /**
  * Destructor
  * Please, call delete function to remove the operatot instance
  */  
  virtual ~CATHybClashBodyChecker() {};

  /**
   * Checks whether the input Body has self-intersections.
   * If a SurfaceCellLayer is available, intersections with 
   * Neighborhood faces on edges are not reported. 
   * @param iContacts
   *        TRUE to enable contact mode in polyhedral check
   * @param oSelfIntersects
   *        TRUE if body self-intersects, FALSE otherwise.
   * @return
   *        S_OK if everything went fine
   */
  virtual HRESULT Run(CATBoolean iContacts,CATBoolean & oSelfIntersects)=0;

  /**
   * AddListOfFaces : To provide a list of faces to the polyhedral check operator.
   *
   * If 0 list is provided : a full check will be performed.
   *
   * If 1 list is provided : this list can be checked against itself,
   *                         this list will be checked against faces not present in the list.
   *
   * If N lists are provided : each list can be checked against itself,
   *                           each list will be checked against the other lists,
   *                           each list will be checked against faces not present in any list.
   *
   * iListOfFaces : the list of faces.
   * iCheckWithin : TRUE to check iListOfFaces against itself, FALSE otherwise.
   */
  virtual void AddListOfFaces(ListPOfCATCell & iListOfFaces,CATBoolean iCheckWithin)=0;

  /**
   * To disable checking of ALL lists against faces not present in any list.
   * This check is enabled by default.
   */
  virtual void CheckAgainstOtherFaces(CATBoolean iCheck)=0;

  /**
   * To remove all lists of faces from the polyhedral check operator.
   */
  virtual void RemoveListsOfFaces()=0;

  /**
   * Get an iterator on couples of faces that are intersecting each other.
   * Iterator must be released by caller.
   */
  virtual CATHybClashCellCellIter * GetCouples()=0;

  /**
   * Activate face self-intersection check.
   * Disabled by default.
   */
  virtual void CheckFacesAgainstThemselves(CATBoolean iCheck)=0;

  /**
   * Get Software Configuration of the operator
   */
  virtual CATSoftwareConfiguration * GetSoftwareConfiguration() const = 0;

protected:
  // DO NOT CALL, USE CREATE INSTEAD (de toute facon ca ne fera rien sans l'extension connue que du fwk d'implementation)
  CATHybClashBodyChecker(CATGeoFactory * iFactory, CATExtGeoOperator & iExtensible);
};


ExportedByAutocheck CATHybClashBodyChecker * CATCreateHybClashBodyChecker(CATBody * iBody, CATSoftwareConfiguration * iConfig);

#endif // CATHybClashBodyChecker_H

