/* -*-C++-*-*/
#ifndef CATGMPolyBodyJoinWiresTopOper_H
#define CATGMPolyBodyJoinWiresTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyBodyJoinWiresTopOper
//
// DESCRIPTION :
// Join operation inside/between 1/n wireframe polyhedral bodies
//
//
// History
//
// December. 2019 CLO2 Creation
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
class CATGMPolyBodyJoinWiresTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyBodyJoinWiresTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBodyJoinWiresTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyJoinWiresTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyBodyJoinTopOper() method to create an instance
  static CATGMPolyBodyJoinWiresTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyJoinWiresTopExt & iExtension);


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
  * By default the Bodies to join are not duplicated. This setting can be used to duplicate all cells of the bodies
  * @param iDuplicateBodies
  */
  void SetDuplication(CATBoolean iDuplicateBodies);
    



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
  CATGMPolyBodyJoinWiresTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyJoinWiresTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyJoinWiresTopOper();
  CATGMPolyBodyJoinWiresTopOper(const CATGMPolyBodyJoinWiresTopOper& iOneOf); 
  CATGMPolyBodyJoinWiresTopOper& operator =(const CATGMPolyBodyJoinWiresTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyBodyJoinWiresTopOper operator.
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
ExportedByGMPolyBoolean CATGMPolyBodyJoinWiresTopOper * CATCreatePolyBodyJoinWiresTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, const ListPOfCATBody &iBodiesToJoin); 

#endif
