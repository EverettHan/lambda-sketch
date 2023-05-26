/* -*-C++-*-*/
#ifndef CATGMPolyBoundaryTopOper_H
#define CATGMPolyBoundaryTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyBoundaryTopOper
// idem CATHybBoundary/CATCreateTopBoundary but dedicated to polyhedral implementation of CATBody
//
// DESCRIPTION :
// Class defining the operator that computes the boundary of a wire or a shell.
// This operator follows the general frame of all operators and satisfies to the smart mechanism: 
// the input bodies are not modified. A new resulting body is created, possibly sharing data with the input bodies.
//
//
// History
//
// Dec. 2015 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyBasicOper.h"      // ExportedBy

#include "CATDataType.h"          // HRESULT
#include "CATMathInline.h"        // inline Methods
#include "CATHybDef.h"            // define CATHybPropagateMode


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATDomain;
class CATCell;
class CATGMPolyBoundaryTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBasicOper CATGMPolyBoundaryTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBoundaryTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyBoundaryTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyBoundaryTopOper() method to create an instance
  static CATGMPolyBoundaryTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBoundaryTopExt & iExtension);


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
  // Please, call CATCreatePolyBoundaryTopOper() method to create an instance
  CATGMPolyBoundaryTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBoundaryTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBoundaryTopOper();
  CATGMPolyBoundaryTopOper(const CATGMPolyBoundaryTopOper& iOneOf); 
  CATGMPolyBoundaryTopOper& operator =(const CATGMPolyBoundaryTopOper& iOneOf);

};


/**
 * @nodoc @nocgmitf (do not create any interface)
 * Constructs an operator that creates a piece of boundary of a
 * CATShell or a CATWire.
 * <br>By default, all the boundaries are computed (two vertices for a wire,
 * one or more wire(s) for the shell). To get a partial boundary solution, use an
 * <tt>iInitialCell</tt>.
 * <br><b>Orientation</b>: The orientation of <tt>initialCell</tt>. If <tt>initialCell=null</tt>,
 * the orientation of the loop of the first face of the shell.
 * <br><b>Journal</b>: 
 * <dl><dt>Shell</dt><dd>
 * The edges are written as <tt>CATCGMJournal::Keep</tt>. The first and last vertex of
 * the boundary are written 
 * as <tt>CATCGMJournal::Creation</tt>.
 * <dt>Wire</dt>
 * <dd>The two vertices are written as <tt>CATCGMJournal::Keep</tt>.
 *</dl>
 * @param iFactory
 * A pointer to the factory of the resulting body.
 * @param iData
 * A pointer to the topological data.
 * @param inputBody
 * A pointer to the body for which the boundary is asked for. If it contains several
 * domains, use <tt>inputDomain</tt> to specify which one is to be taken into account.
 * @param inputDomain
 * The domain on which the boundary is computed. To use if <tt>inputBody</tt> contains several
 * domains.
 * @param iInitialCell
 * The initial cell from which the boundary is computed.
 * <ul>
 *     <li>for a CATWire: <tt>iInitialCell</tt> is a CATVertex. The boundary begins
 * at <tt>iInitialCell</tt> and ends at the nearest extremity of the CATWire
 *     <li>for a CATShell: <tt>iInitialCell</tt> is a CATEdge. The boundary is
 * propagated according to <tt>CATHybPropagateMode</tt>. The boundary is retrieved
 * as one or more CATWire.
 * </ul>
 * @param iPropagateMode
 * The rule of propagation of a piece of the boundary of a shell domain.
 * <dl><dt>NO_CONTINUITY</dt>
 * <dd>No restriction is made on the definition of the boundary. In particular, this boundary
 * can be made of several domains (case of inner loops of a shell).
 * <dt> POINT_CONTINUITY</dt>
 * <dd>The boundary stops at the last cell of the bounding domain.
 * <dt> TANGENT_CONTINUITY</dt>
 * <dd>The boundary stops at the first vertex where the boundary is not continuous in tangent.
 * </dl>
 */
ExportedByGMPolyBasicOper CATGMPolyBoundaryTopOper * CATCreatePolyBoundaryTopOper(CATGeoFactory*         iFactory,
                                                                                  CATTopData*            iTopData,
                                                                                  CATBody*               iBody,
                                                                                  CATDomain*             iDomain=NULL,
                                                                                  CATCell*               iCell=NULL,
                                                                                  CATHybPropagateMode    iPropagateMode=NO_CONTINUITY);
#endif





