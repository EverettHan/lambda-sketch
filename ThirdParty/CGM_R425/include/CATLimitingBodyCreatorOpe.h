/*
 * CATLimitingBodyCreatorOpe.h
 *
 *  Created on: Mar 5, 2021
 *      Author: NCA3
 * Responsible: NCA3
 * Description: CATLimitingBodyCreatorOpe
 *
 * COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
 */

#ifndef CATLimitingBodyCreatorOpe_H
#define CATLimitingBodyCreatorOpe_H

#include "Thick.h"
#include "CATDRepOperator.h"

class CATLimitingBodyCreatorImpl;
class CATFace;
class CATVertex;

/**
 * Class defining a topological operator which creates a limiting body in the context of fillet removal.<br>
 * This operator can be helpful when defining relimitations for e.g. <tt>RemoveFace</tt> operator.<br>
 * To use this operator, you must:
 * <ul>
 * <li>Create it with the <tt>CATCreateLimitingBodyCreatorOpe</tt> global function.
 * <li>Define the fillet face and an appropriate position for the resulting limiting body,
 *     using the <tt>SetXxx</tt> methods (three different types of inputs available).
 * <li><tt>Run</tt> it.
 * <li>Get the result with the <tt>GetResult</tt> method.
 * <li>Delete the operator after use.
 * <li>If you do not want to keep the resulting body,
 *     use the @href CATICGMContainer#Remove method to remove it from the geometric factory, after the operator deletion.
 * </ul>
 */
class ExportedByThick CATLimitingBodyCreatorOpe: public CATDRepOperator
{
  CATCGMVirtualDeclareClass(CATLimitingBodyCreatorOpe);

public:
  /**
   * Destructor
   */
  virtual ~CATLimitingBodyCreatorOpe();

  /**
   * Sets the input body.
   * @param iInputBody
   */
  void SetInputBody(CATBody * iInputBody) ;

  /**
   * Sets the fillet face to relimit.
   * @param iLimitedFace
   */
  void SetLimitedFace(CATFace * iLimitedFace);

  /**
   * 1st use case: input SurParam representing
   * the point on the fillet surface
   * where the limiting body will be created.
   * @param iSurParam
   */
  void SetSurParam(const CATSurParam & iSurParam);

  /**
   * 2nd use case: input curve and CrvParam representing
   * the point on the fillet surface
   * where the limiting body will be created.
   * Ignored in case of 1st use case input.
   * @param iCurve
   * @param iCrvParam
   */
  void SetCurve(CATCurve * iCurve, const CATCrvParam & iCrvParam);

  /**
   * 3rd use case: input vertex representing
   * the point on the fillet surface
   * where the limiting body will be created.
   * Ignored in case of 1st or 2nd use case.
   * @param iVertex
   */
  void SetVertex(CATVertex * iVertex);

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
  CATLimitingBodyCreatorImpl * _impl;

  /**
   * Run the operator.
   * @return
   * 0 if limiting body successfully created,
   * 1 if failure.
   */
  virtual int RunOperator();

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATLimitingBodyCreatorOpe ( const CATLimitingBodyCreatorOpe & );            // Not Implemented
  CATLimitingBodyCreatorOpe & operator=( const CATLimitingBodyCreatorOpe & ); // Not Implemented

  /**
   * Protected constructor.
   * Use CATCreateLimitingBodyCreatorOpe function instead.
   */
  CATLimitingBodyCreatorOpe(CATGeoFactory *iFactory, CATTopData *iTopData, CATLimitingBodyCreatorImpl * iImpl);

  friend ExportedByThick CATLimitingBodyCreatorOpe * CATCreateLimitingBodyCreatorOpe(CATGeoFactory * iFactory, CATTopData * iTopData,
                                                                                     CATBody * iInputBody, CATFace * iLimitedFace);
};

/**
* Creates a CATLimitingBodyCreator operator.
* @param iFactory
* A pointer to the factory.
* @param iTopData
* A pointer to the topological data.
* @param iInputBody
* A pointer to the input body.
* @return
* The operator.
*/
ExportedByThick CATLimitingBodyCreatorOpe * CATCreateLimitingBodyCreatorOpe( CATGeoFactory * iFactory,
                                                                             CATTopData * iTopData,
                                                                             CATBody * iInputBody = NULL,
                                                                             CATFace * iLimitedFace = NULL);

#endif /* CATLimitingBodyCreatorOpe_H */
