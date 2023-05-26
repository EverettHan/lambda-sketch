/* -*-C++-*-*/
#ifndef CATGMPolyCompatibleTopOper_H
#define CATGMPolyCompatibleTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2022
//
// CATGMPolyCompatibleTopOper : polyhedral implementation of CATIPGMTopCompatible
//
// DESCRIPTION :
// 
// Class defining the operator which  performs a compatible Boolean union of bodies.
//
//
// History
//
// 2022 March CLO2 Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyBoolean.h"      // ExportedBy

#include "CATMapOfPtrToPtr.h"

#include "CATTopDefine.h"

#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyCompatibleTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyCompatibleTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyCompatibleTopOper);

public:

  /**
  * Destructor
  */
  virtual ~CATGMPolyCompatibleTopOper();

  /** @nodoc
  * cannot be called
  */
  // Please, call CATCreatePolyPartitioningTopOper() method to create an instance
  static CATGMPolyCompatibleTopOper* New(CATGeoFactory& iFactory, const CATTopData& iTopData, CATGMPolyCompatibleTopExt& iExtension);

  //=============================================================================
  // Settings
  //=============================================================================

  void EnableVolumicSimplifMode();

  /**
   * Defines the tolerance of the geometrically coincident elements to be taken
   * into acccount by the Compatible operator.
   * <br>Very sensitive point. The default value is the factory resolution (0.001 mm in NormalScale context),
   * and it is strongly recommended to not increase it above the LargeResolutionForLengthTest
   * (100 times the resolution which is the threshold of CATBody invalidity for gaps & overlaps)
   * @param iJoinTol
   * The tolerance.
   */
  void SetTolerance(double iJoinTol);

  /**
* @nodoc
* Activate or deactivate the volume journal mode.
*/
  void SetVolumeJournalMode(CATBoolean iVolumeJournalMode);

  /**
  * @nodoc
  * Activate or deactivate the cells journal mode.
  */
  void SetCellsJournalExpected(CATBoolean iVolExpected, CATBoolean iEdgeExpected, CATBoolean iVtxExpected);

  /**
  * @nodoc
  * Check if the volume journal mode is active or not.
  */
  CATBoolean GetVolumeJournalMode() const;
 
  //=============================================================================
  // Inputs
  //=============================================================================


  //=============================================================================
  // CGMReplay
  //=============================================================================

  // ------------------
  // CGMReplay Methods => currently in CATGMPolyTopOperator and calling the extensions' methods.
  // Soon, only the extensions will implement the <MethodName>Ext versions for lighter CGMReplay impl.
  // Beware, CATGMPolyTopOperator::DumpOutput seems to handle stuff like tass & dump of journal.
  // Has to be moved over to the mother extension DumpOutputExt.
  // ------------------

  /** @nodoc
   * @nocgmitf
  */
  static const CATString* GetDefaultOperatorId();

protected:
  /** @nodoc
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyPartitioningTopOper() method to create an instance
  CATGMPolyCompatibleTopOper(CATGeoFactory& iFactory, const CATTopData& iTopData, CATGMPolyCompatibleTopExt& iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================

  CATGMPolyCompatibleTopOper();
  CATGMPolyCompatibleTopOper(const CATGMPolyCompatibleTopOper& iOneOf);
  CATGMPolyCompatibleTopOper& operator =(const CATGMPolyCompatibleTopOper& iOneOf);

};


/**
 * Creates a CATGMPolyCompatibleTopOper operator.
 * @param iFactory
 * The factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iBodiesToUnion
 * The list of bodies to union
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be deleted with the <tt>delete</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyCompatibleTopOper* CATCreatePolyCompatibleTopOper(CATGeoFactory* iFactory, CATTopData* iTopData, ListPOfCATBody& iBodiesToUnion, CATBody * iContextBodyForInfiniteGeom = NULL);

#endif
