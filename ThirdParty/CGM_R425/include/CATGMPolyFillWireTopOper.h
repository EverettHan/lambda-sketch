//====================================================================
// Copyright Dassault Systemes 2018, all rights reserved 
//====================================================================
//
// CATGMPolyFillWireTopOper
//
// DESCRIPTION :
//
// Generate a polyhedral surface from one or several manifold 1D-Body PH defining its boundary,
//
//
//====================================================================
//  Mars 2018    : ANR : Creation
//  March  18    : DPS : change derivation from CATPolyhedralFillWire
//  Feb. 20      : DPS : new option AddInnerWireBodies
//====================================================================
#ifndef CATGMPolyFillWireTopOper_H
#define CATGMPolyFillWireTopOper_H

#include "GMPolyShapeOper.h"       // ExportedBy
#include "CATGMPolyTopOperator.h"  // derivation

#include "CATIPolyMesh.h"
#include "CATString.h"
#include "CATCGMVirtual.h"
#include "CATCollec.h"
#include "ListPOfCATBody.h"

class CATGeoFactory;
class CATBody;
class CATGeometry;
class CATGMPolyFillWireTopExt;
class CATTopData;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyShapeOper CATGMPolyFillWireTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyFillWireTopOper);

public:

  virtual ~CATGMPolyFillWireTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATGMPolyCreateFillWireTopOper() method to create an instance
  static CATGMPolyFillWireTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyFillWireTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
  
  /**
  * Sets additional bodies with wires defining 1 or several closed set of edges
  * as future inner loops of the result faces
  * @Param iInnerWireBodies
  * The list of pointers to wire bodies representing the inner wires.
  * returns S_FALSE if the list is empty, E_FAIL if at least one inner body is not polyhedral
  */
  HRESULT AddInnerWireBodies(const ListPOfCATBody & iInnerWirePHBodies);

  /**
  * Pilots the fill behavior giving a reference plane
  * @param iRefPlane
  * The mathematical plane given as reference to buils the fill surface
  */
  virtual void SetPlane(CATMathPlane &iPlane);

  /** 
  * Defines the maximal authorized distance between the input wire extremities
  * to connect to each other in order to fill a closed set of edges
  * @param iMaxDistanceValue
  * The tolerance value
  * <br>Very sensitive point. The default value is the factory resolution (0.001 mm in NormalScale context), 
  * This input value cannot be greater than LargeResolutionForLengthTest 
  * (100 times the resolution which is the threshold of CATBody invalidity for gaps & overlaps)
  */
  void SetMaxDistanceValue(double iMaxDistanceValue);

  /** 
  * Do not force to duplicate the original edges to new created edges.
  * If it's not possible to keep some initial edges untouched,
  * the new edges will be considered as modified (instead of created) by the journal if any.
  * This mode makes switch the default journal mode from NoCopy to Copy.
  * This mode is disabled by default if the option is not called explicitely
  */
  void EnableKeepEdges();


protected:
  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATGMPolyFillWireTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyFillWireTopExt & iExtensible);

};


/**
 * @nodoc @nocgmitf (do not create any specific interface)
 * Creates a CATGMPolyFillWireTopOper operator with one wire body
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyPH
 * The pointer to the polyhedral 1D body enclosing the mesh to build
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyShapeOper CATGMPolyFillWireTopOper * CATCreatePolyFillWireTopOper(CATGeoFactory * iFactory,
                                                                                  CATTopData    * iTopData,
                                                                                  CATBody       * iBodyPH);
/**
 * @nodoc @nocgmitf (do not create any specific interface)
 * Creates a CATGMPolyFillWireTopOper operator with one list of wire bodies
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iListOfBodiesPH
 * The list of pointers to the polyhedral 1D bodies enclosing the mesh to build
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyShapeOper CATGMPolyFillWireTopOper * CATCreatePolyFillWireTopOper(CATGeoFactory        * iFactory,
                                                                                  CATTopData           * iTopData,
                                                                                  const ListPOfCATBody & iListOfBodiesPH);
#endif
