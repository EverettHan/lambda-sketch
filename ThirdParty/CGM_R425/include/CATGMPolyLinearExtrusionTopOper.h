/* -*-C++-*-*/
#ifndef CATGMPolyLinearExtrusionTopOper_H
#define CATGMPolyLinearExtrusionTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyLinearExtrusionTopOper
//
// DESCRIPTION :
// Extrude a polyhedral wire or point along a direction
//
//
// History
//
// March. 2016 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyShapeOper.h"      // ExportedBy

#include "CATDataType.h"          // HRESULT
#include "CATTopDefine.h"         // CATSide
#include "CATMathInline.h"        // inline Methods

#include "CATBoolean.h"
#include "CATSysBoolean.h"


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyLinearExtrusionTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyShapeOper CATGMPolyLinearExtrusionTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyLinearExtrusionTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyLinearExtrusionTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyLinearExtrusionTopOper() method to create an instance
  static CATGMPolyLinearExtrusionTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyLinearExtrusionTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
    

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
  // Please, call CATCreatePolyLinearExtrusionTopOper() method to create an instance
  CATGMPolyLinearExtrusionTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyLinearExtrusionTopExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyLinearExtrusionTopOper();
  CATGMPolyLinearExtrusionTopOper(const CATGMPolyLinearExtrusionTopOper& iOneOf); 
  CATGMPolyLinearExtrusionTopOper& operator =(const CATGMPolyLinearExtrusionTopOper& iOneOf);

};

/**
 * Creates a CATGMPolyLinearExtrusionTopOper operator.
 * @nodoc @nocgmitf (do not create any interface)
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToExtrude
 * The pointer to the body (wire of point) to extrude
 * @param iDirection
 * The mathematical direction to apply the extrusion
 * @param iOffsetVal[2]
 * The 2 lengths limiting the extrusion
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyShapeOper CATGMPolyLinearExtrusionTopOper * CATCreatePolyLinearExtrusionTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyToExtrude, 
                                                                                                CATMathDirection &iDirection, double iOffsetVal[2]); 

/**
 * @nodoc @nocgmitf (do not create any interface)
 * Creates a CATGMPolyLinearExtrusionTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iPlanarBodyToExtrude
 * The pointer to the body (wire of point contained in a plane) to extrude
 * @param iInputBodyPlane
 * The mathematical definition of the plane containing the Body to extrude and defining the direction by its normal vector
 * @param iOffsetVal[2]
 * The 2 lengths limiting the extrusion
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyShapeOper CATGMPolyLinearExtrusionTopOper * CATCreatePolyLinearExtrusionTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iPlanarBodyToExtrude, 
                                                                                                CATMathPlane &iInputBodyPlane, double iOffsetVal[2]); 


#endif
