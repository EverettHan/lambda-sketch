#ifndef CATGMPolyCavityExtractTopOper_H
#define CATGMPolyCavityExtractTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2023
//
// CATGMPolyCavityExtractTopOper : partial polyhedral implementation of CATIPGMCavityExtractOperator
//
// DESCRIPTION :
// 
// Class defining the operator that uses a solid container bodies and lids
// to find the cavity or fluid region, i.e. the volumes enclosed by the solid bodies and lids.
//
//
// History
//
// 2023 Feb 14th DPS Creation
//
//=============================================================================

#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyAdvancedBool.h"   // ExportedBy


#include "ListPOfCATBody.h"
#include "ListPOfCATFace.h"


class CATGMPolyCavityExtractTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyAdvancedBool CATGMPolyCavityExtractTopOper: public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyCavityExtractTopOper);

public:

  /**
  * Destructor
  */
  virtual ~CATGMPolyCavityExtractTopOper();
  
  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyCavityExtractTopOper() method to create an instance
  static CATGMPolyCavityExtractTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyCavityExtractTopExt & iExtension);
  

  // -------------
  // Settings
  // -------------

  /**
  * Specify the leak by a maximal distance value
  * @param iMaxDistance
  * if we have leak we will try to fill them using this tolerance as maximum value.
  * default value is (100. X resolution) if not requested
  */
  void SetMaxDistanceForLeak(double iMaxDistance);



  // -----------------------------------
  // Additional Settings for the future (do not use)
  // -----------------------------------
  /**
  * Whether to find the Exterior Wrap, i.e. The combination of the cavity
  * and all the container bodies to produce a body with one volume for each 
  * set of containers and cavities that touch.
  * @param iExteriorWrap. By default, an Exterior Wrap is not done.
  */
  void SetExteriorWrap(CATBoolean iExteriorWrap);

  /**
  * Whether to keep in the result only the volumes in contact with lids and 
  * not those that are completely enclosed by the container bodies.
  * @param iKeepOnlyLidCavities. By default, this is false and we keep all volumes.
  */
  void SetKeepOnlyCavitiesTouchingLids(CATBoolean iKeepOnlyLidCavities);


  //=============================================================================
  // No outputs
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
  static const CATString * GetDefaultOperatorId();


protected:
  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyCavityExtractTopOper() method to create an instance
  CATGMPolyCavityExtractTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyCavityExtractTopExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyCavityExtractTopOper();
  CATGMPolyCavityExtractTopOper(const CATGMPolyCavityExtractTopOper& iOneOf); 
  CATGMPolyCavityExtractTopOper& operator =(const CATGMPolyCavityExtractTopOper& iOneOf);
};


/**
 * Creates a CATGMPolyCavityExtractTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iAllBodiesToAssemble
 * List of solid containers and solid/surfacic lids forming an assembly with cavities to extract
 * each CATBody may be continuous (exact geometry) or discrete (polyhedral geometry) but never mixed.
 * each CATBody may contain both containers and lids, and may be heterogeneous (volumes & surfaces)
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be deleted with the <tt>delete</tt> method after use.
 */
ExportedByGMPolyAdvancedBool CATGMPolyCavityExtractTopOper * 
  CATCreatePolyCavityExtractTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, const ListPOfCATBody & iAllBodiesToAssemble);


#endif /* CATGMPolyCavityExtractTopOper_H */ 
