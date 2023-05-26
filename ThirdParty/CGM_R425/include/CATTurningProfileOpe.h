// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : YSY2 
//
// DESCRIPTION  : Given a volumic body and a rotation axis, computes the profile
//                which defines the shape of input body when turning around axis.
//
//=============================================================================
// Creation YSY2 February 2020
//
//=============================================================================
#ifndef CATTurningProfileOpe_H
#define CATTurningProfileOpe_H

#include "CATPersistentOperator.h"   // derivation
#include "AdvThickness.h"         // exportation

#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATTurningProfileImpl;
class CATMathPoint;
class CATMathDirection;
class CATMathPlane;
class CATBody;
class CATDomain;
class CATMathAxis;
class CATTopData;


/**
* Class defining the operator that computes the turning profile for a given (volumic) body.
*<br>
* It follows the general frame of all operators and satisfies the smart mechanism: the
* input bodies are not modified. A new wire body is created,
* possibly sharing data with the input bodies.
*<ul>
* <li>CATTurningProfileOpe is created with the CATCreateTurningProfileOpe global function.
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable.
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the
* geometric factory.
*</ul>
* 
* 
* Example: 
* 
*          Axis
*           :
*           |
*          .-.                    |
*         (   )                 --:
*         |~-~|                 | |
*         |   |                 | :
*        .|   |.              --| |
*       |._____.'            |    :
*       |       |    -->     |    |
*       |       |            |    :
*       |       |            |    |
*       |       |            |----:
*       `._ : _.'                 |
*  cylinder |
*           :                Profile
*           |
*/
class ExportedByAdvThickness CATTurningProfileOpe: public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATTurningProfileOpe);

public:

  /** @nodoc
  * cannot be called
  */
  // Constructor
  // Please, call CATCreateTurningProfileOpe() method to create an instance
  CATTurningProfileOpe(CATGeoFactory        * iFactory,
                       CATTopData           * iTopData,
                       CATTurningProfileImpl * iImpl);


  // Destructor
  virtual ~CATTurningProfileOpe();

  // ----------------------------------------------------------------------------
    /**
   * Sets the profile axis.
   * @param iAxis
   *  Axis of input model
   */
   // @nodoc @nocgmitf
  void SetProfileAxis(const CATMathAxis &iAxis);

  //// ----------------------------------------------------------------------------
  //// Runs the operator
  ///** @nodoc
  // * @nocgmitf
  //*/
  //virtual int RunOperator();




  // ------------------
  // CGMReplay Methodes
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString *GetDefaultOperatorId();
  /** @nodoc
   * @nocgmitf
  */
  const CATString * GetOperatorId();
  /** @nodoc
   * @nocgmitf
  */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc
   * @nocgmitf
  */
  void WriteInput(CATCGMStream  & Str);
  /** @nodoc 
   * @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream, int VersionOfStream, short iNumReplayVersion = 1);
  /** @nodoc
   * @nocgmitf
  */
  void Dump(CATCGMOutput& os);
  /** @nodoc
 * @nocgmitf
*/
  void DumpOutput(CATCGMOutput& os);
  /** @nodoc
   * @nocgmitf
  */
  void RequireDefinitionOfInputAndOutputObjects();


protected:


  /** @nodoc
  * cannot be called
  */
  // Internal implementation
  CATTurningProfileImpl * GetTurningProfileImpl() const;
};

/**
 * Creates a CATTurningProfileOpe operator.
 * @param iFactory
 * The factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iBody
 * The pointer to the body whose turning profile needs to be computed.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByAdvThickness
CATTurningProfileOpe * CATCreateTurningProfileOpe(CATGeoFactory  * iFactory,
                                                  CATTopData     * iTopData,
                                                  CATBody        * iBody);


/**
 * Creates a CATTurningProfileOpe operator.
 * @param iFactory
 * The factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iBody
 * The pointer to the body whose turning profile needs to be computed.
 * @param iAxis
 * The axis which the input body is revolving around.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByAdvThickness
CATTurningProfileOpe * CATCreateTurningProfileOpe(CATGeoFactory     * iFactory,
                                                  CATTopData        * iTopData,
                                                  CATBody           * iBody,
                                                  const CATMathAxis & iAxis);
#endif
