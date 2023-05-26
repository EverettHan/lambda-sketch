/* -*-C++-*-*/
#ifndef CATGMPolyBodyJoinTopOper_H
#define CATGMPolyBodyJoinTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyBodyJoinTopOper
//
// DESCRIPTION :
// Join operation inside/between 1/n surfacic polyhedral bodies
//
//
// History
//
// June. 2015 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyBoolean.h"      // ExportedBy

#include "CATDataType.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods
#include "ListPOfCATBody.h"     // aggregation

#include "CATBoolean.h"
#include "CATSysBoolean.h"


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyBodyJoinTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyBodyJoinTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBodyJoinTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyJoinTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyBodyJoinTopOper() method to create an instance
  static CATGMPolyBodyJoinTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyJoinTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
    
  /** 
   * Defines the tolerance of the geometrically coincident elements to be taken 
   * into acccount by the Join operator.
   * <br>Very sensitive point. The default value is the factory resolution (0.001 mm in NormalScale context), 
   * and it is strongly recommended to not increase it above the LargeResolutionForLengthTest 
   * (100 times the resolution which is the threshold of CATBody invalidity for gaps & overlaps)
   * @param iJoinTol
   * The tolerance.
   */
  void SetTolerance(double iJoinTol);

  /**
  * Activates Volume creation mode: if the resulting skin is closed,
  * operator creates and returns the volume bounded by this skin.
  * @param iVolumeCreation
  * <br><b>Legal values</b>:
  * <dl><dt><tt>FALSE</tt><dd> No volume creation.
  *     <dt><tt>TRUE</tt><dd> Volume creation if result is closed.</dl>
  */
  void SetVolumeCreationMode(CATBoolean iVolumeCreation = FALSE);

  /**
  * Activates the check of connectivity between given operands - To be called before Run
  * Check contacts that exist ONLY between the operands in the list
  * @param iListOfOpds
  * <br><b>List of int - index in the list of input bodies to join - corresponding to the operands to check</b>
  */
  void CheckConnectivityBetweenOpds(CATListOfInt & iListOfOpds);

  /**
  * Before call : set CheckConnectivityBetweenOpds to TRUE - To be called after Run
  * Return the list of CATCell connection between the Opds given in CheckConnectivityBetweenOpds
  * @param oResultConnexionCells
  * <br><b>List of Cells from the Result corresponding to the contacts found between operands to check</b>
  * @param oSourceContactCells
  * <br><b>List of cells from Input bodies - source of connexion cells</b>
  */
  HRESULT GetListOfConnexionCells(ListPOfCATCell &oResultConnexionCells, ListPOfCATCell &oSourceContactCells);

  /**
* Activates Join of internal edges mode: not only boundaries of each bodies are joined - internal edges can be also joined
*/
  void EnableJoinInternalEdgesMode();


  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();
	

protected:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyBodyJoinTopOper() method to create an instance
  CATGMPolyBodyJoinTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyJoinTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyJoinTopOper();
  CATGMPolyBodyJoinTopOper(const CATGMPolyBodyJoinTopOper& iOneOf); 
  CATGMPolyBodyJoinTopOper& operator =(const CATGMPolyBodyJoinTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyBodyJoinTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodiesToJoin
 * The list of pointers to the bodies to join together
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyBodyJoinTopOper * CATCreatePolyBodyJoinTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, ListPOfCATBody &iBodiesToJoin); 

#endif
