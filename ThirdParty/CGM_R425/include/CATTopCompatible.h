/**
 * @COPYRIGHT DASSAULT SYSTEMES 2007
 */

/* -*-C++-*- */

#ifndef __CATTopCompatible_H__
#define __CATTopCompatible_H__

// COPYRIGHT DASSAULT SYSTEMES 2007

//===========================================================================
// Operator for compatible boolean union of two bodies.
//===========================================================================

#include "ExportedByPBELight.h"
#include "CATTopCompatible2.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATTopCompatibleCGM;

/**
 * Class representing the topological operator which performs a compatible Boolean union of bodies.
 * <ul>
 * <li>Create it with the <tt>CATCreateTopCompatibleForCGM</tt> or <tt>CATCreateTopCompatibleForCVM</tt> global function.
 * <li>Run it ( only one time ).
 * <li>Get the resulting body with the <tt>GetResult</tt> method. 
 * If you do not want to keep this resulting body, 
 * use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 * <li>Delete it after use with the usual C++ delete operator. 
 * </ul>
*/
class ExportedByPBELight CATTopCompatible: public CATTopCompatible2
{
  CATCGMVirtualDeclareClass(CATTopCompatible);
protected:

  /**
  * @nodoc
  * Constructor. Do not use. Use <tt>CATCreateTopCompatibleForCGM</tt>  or <tt>CATCreateTopCompatibleForCVM</tt> to create a
  * <tt>CATTopCompatible</tt>.
  */
  CATTopCompatible(CATGeoFactory * iFactory, 
									 CATTopData    * iTopData,
                   CATTopCompatibleCGM * iExtensible);

public:
  /**
  * Destructor.
  */
  virtual ~CATTopCompatible();

};
/**
* Creates the manifold body resulting from the compatible boolean union of two bodies.
* @param iFactory
* A pointer to the factory of the resulting body. 
* @param iTopData
* A pointer to the topological data.
* @param iBody1
* A pointer to the first body.
* @param iBody2
* A pointer to the second body.
*/
ExportedByPBELight CATTopCompatible *
CATCreateCompatibleForCGM(CATGeoFactory * iFactory, 
									        CATTopData    * iTopData,
									        CATBody       * iBody1,
								          CATBody       * iBody2);
/**
* @nodoc
* Creates the manifold body resulting from the compatible boolean union of a list of bodies.
* @param iFactory
* A pointer to the factory of the resulting body. 
* @param iTopData
* A pointer to the topological data.
* @param iBodyList
* A pointer to the list of body to union
*/
ExportedByPBELight CATTopCompatible *
CATCreateCompatibleForCGM(CATGeoFactory * iFactory, 
									        CATTopData    * iTopData,
									        CATLISTP(CATBody) * iBodyList);

//******************************************************************
// DEPRECATED, PLEASE DO NOT USE !!!
//******************************************************************
/**
* @nodoc
* Creates a body, which may be non-manifold, resulting from the compatible boolean union of two bodies.
* @param iFactory
* A pointer to the factory of the resulting body. 
* @param iTopData
* A pointer to the topological data.
* @param iBody1
* A pointer to the first body.
* @param iBody2
* A pointer to the second body.
*/
ExportedByPBELight CATTopCompatible *
CATCreateCompatibleForCVM(CATGeoFactory * iFactory, 
									        CATTopData    * iTopData,
									        CATBody       * iBody1,
								          CATBody       * iBody2);

//******************************************************************
// DEPRECATED, PLEASE DO NOT USE !!!
//******************************************************************
/**
* @nodoc
* Creates a body, which may be non-manifold, resulting from the compatible boolean union of a list of bodies.
* @param iFactory
* A pointer to the factory of the resulting body. 
* @param iTopData
* A pointer to the topological data.
* @param iBody1
* A pointer to the first body.
* @param iBody2
* A pointer to the second body.
*/
ExportedByPBELight CATTopCompatible *
CATCreateCompatibleForCVM(CATGeoFactory * iFactory, 
									        CATTopData    * iTopData,
									        CATLISTP(CATBody) * iBodyList);
//******************************************************************
// DEPRECATED, PLEASE DO NOT USE !!!
//******************************************************************
/** (ld2)
* @nodoc
* Creates a body, which may be non-manifold, resulting from the compatible boolean union of two bodies.
* @param iFactory
* A pointer to the factory of the resulting body. 
* @param iTopData
* A pointer to the topological data.
* @param iBody1
* A pointer to the first body.
* @param iBody2
* A pointer to the second body.
*/
ExportedByPBELight CATTopCompatible *
CATCreateCompatibleFull(CATGeoFactory * iFactory, 
									        CATTopData    * iTopData,
									        CATBody       * iBody1,
								          CATBody       * iBody2);

//******************************************************************
// DEPRECATED, PLEASE DO NOT USE !!!
//******************************************************************
/** (U29)
* @nodoc
* Creates a body resulting from the compatible boolean union of two bodies.
*  @param ipFactory
*    A pointer to the factory of the resulting body. 
*  @param ipTopData
*    A pointer to the topological data.
*  @param iBodyList
*    A pointer to the list of body to union.
*  @param iNonManifoldAuthorized
*    Flag to authorize full elements.
*  @param iJournalFull
*    Flag to specify if all the cells of the journal are expected.
*    
*/
ExportedByPBELight CATTopCompatible *
  CATCreateCompatible_Kernel(CATGeoFactory * ipFactory, 
  CATTopData    * ipTopData,						        
  CATLISTP(CATBody) * ipBodyList,
  CATBoolean iNonManifoldAuthorized=FALSE,
  CATBoolean iFullJournal=FALSE);

#endif
