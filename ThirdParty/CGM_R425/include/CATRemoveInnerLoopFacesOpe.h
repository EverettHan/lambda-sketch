/*
 * CATRemoveInnerLoopFacesOpe.h
 *
 *  Created on: Feb 6, 2020
 *      Author: NCA3
 * Responsible: NCA3
 * Description: Class defining a topological operator which removes groups of connected faces
 *              when they form inner loops in a "bounding" face.
 *
 * COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
 */

#ifndef CATRemoveInnerLoopFacesOpe_H
#define CATRemoveInnerLoopFacesOpe_H

#include "Thick.h"
#include "CATTopOperator.h"
#include "ListPOfCATFace.h"

class CATRemoveInnerLoopFacesImpl;

/**
 * Class defining a topological operator which removes groups of connected faces
 * when they form inner loops in one or several "background face(s)",
 * e.g. logos, protrusions, holes, etc.<br>
 * This operator serves as an optimization to the usual <tt>RemoveFace</tt> operators in this special use case.<br>
 * In typical use cases, you would not use this operator directly,
 * but use CATAdvancedRemoveFaceOpe (which calls it when needed) with <tt>CATPGMCreateAdvancedRemoveFaceOpe</tt>.
 * Nevertheless, to use this operator as a standalone, you must:
 * <ul>
 * <li>Create it with the <tt>CATCreateRemoveInnerLoopFacesOpe</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> or <tt>Append</tt> methods.
 * <li><tt>Run</tt> it.
 * <li>Get the result with the <tt>GetResult</tt> method.
 * <li>Recover the list of remaining faces (not detected as inner loops) with the <tt>GetFacesNotRemoved</tt> method.
 * <li>Delete the operator after use.
 * <li>If you do not want to keep the resulting body,
 *     use the @href CATICGMContainer#Remove method to remove it from the geometric factory, after the operator deletion.
 * </ul>
 */
class ExportedByThick CATRemoveInnerLoopFacesOpe: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATRemoveInnerLoopFacesOpe);

public:
  /**
   * Destructor
   */
  virtual ~CATRemoveInnerLoopFacesOpe();

  /**
   * Sets the input body.
   * @param iInputBody
   */
  void SetInputBody(CATBody * iInputBody) ;

  /**
   * Sets the list of faces to remove.
   * @param iFacesToRemove
   * The list of faces to remove.
   */
  void SetFacesToRemove(const CATLISTP(CATFace) & iFacesToRemove) ;

  /**
   * Appends a list of faces to remove.
   * @param iFacesToRemove
   * The list of faces to remove.
   */
  void Append(const CATLISTP(CATFace) & iFacesToRemove) ;

  /**
   * Appends a face to remove.
   * @param iFaceToRemove
   * The face to remove.
   */
  void Append(CATFace * iFaceToRemove) ;

  /**
  * Partial result allowed.
  * @param iPartialResultAllowed
  * If 1 (default), partial result allowed.
  * In this case, if only some groups of connected faces are recognized as inner loops,
  * they are removed and a partial result is returned where the remaining faces are left untouched.
  * If 0, the operator fails if not all the faces can be removed.
  */
  void SetPartialResultAllowed(short iPartialResultAllowed = 1);

  /**
   * Returns the remaining faces to remove after the run.
   * @param oFacesNotRemoved
   * List of remaining faces not detected in an inner loop.
   */
  void GetFacesNotRemoved(CATLISTP(CATFace) & oFacesNotRemoved);

  /**
   * Returns the number of faces removed after the run (for checks or status).
   * @return
   * Number of removed faces.
   */
  int GetNbFacesRemoved();

  //-------------------------------------------------------------------------------//
  // CGMREPLAY METHODS                                                             //
  //-------------------------------------------------------------------------------//
  /** @nocgmitf */
  CATExtCGMReplay * IsRecordable(short & oLevelOfRuntime, short & oVersionOfStream);
  /** @nocgmitf ID */
  static const CATString * GetDefaultOperatorId();
  /** @nocgmitf */
  const CATString * GetOperatorId();
  /** @nocgmitf */
  void WriteInput(CATCGMStream & oStr);
  /** @nocgmitf */
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nocgmitf */
  void ReadInput(CATCGMStream  & iStr);
  /** @nocgmitf */
  void Dump(CATCGMOutput & oStr);
  /** @nocgmitf */
  void DumpOutput(CATCGMOutput & oStr);
  /** @nocgmitf */
  void SetCGMMode(short iCGMMode);

protected:
  /** @nodoc */
  CATRemoveInnerLoopFacesImpl * _implementation;

  /**
   * Run the operator.
   * @return
   * 0 if all faces were removed,
   * or at least one connected group is removed if partial result allowed.
   * 1 if failure, i.e. no face removed,
   * or not all of them can be removed if partial result not allowed.
   */
  virtual int RunOperator();

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATRemoveInnerLoopFacesOpe ( const CATRemoveInnerLoopFacesOpe & );            // Not Implemented
  CATRemoveInnerLoopFacesOpe & operator=( const CATRemoveInnerLoopFacesOpe & ); // Not Implemented

  /**
   * Protected constructor.
   * Use CATCreateRemoveInnerLoopFacesOpe function instead.
   */
  CATRemoveInnerLoopFacesOpe(CATGeoFactory *iFactory, CATTopData *iTopData, CATRemoveInnerLoopFacesImpl * iImplem);

  friend ExportedByThick CATRemoveInnerLoopFacesOpe * CATCreateRemoveInnerLoopFacesOpe( CATGeoFactory *iFactory, CATTopData *iTopData, CATBody *iInputBody, const CATLISTP(CATFace) &iFacesToRemove);
};

/**
* Creates a CATRemoveInnerLoopFaces operator.
* @param iFactory
* A pointer to the factory.
* @param iTopData
* A pointer to the topological data.
* @param iInputBody
* A pointer to the input body.
* @param iFacesToRemove
* The list of faces to be removed.
* @return
* The operator.
*/
ExportedByThick CATRemoveInnerLoopFacesOpe * CATCreateRemoveInnerLoopFacesOpe( CATGeoFactory *iFactory,
                                                                               CATTopData *iTopData,
                                                                               CATBody *iInputBody = NULL,
                                                                         const CATLISTP(CATFace) &iFacesToRemove = CATLISTP(CATFace)() );

#endif /* CATRemoveInnerLoopFacesOpe_H */
