#ifndef CATTopDevelop_H
#define CATTopDevelop_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "BODYNOPE.h"
#include "CATMathDef.h"
#include "CATTopOperator.h"
//
class CATBody;
class CATFace;
class CATSurTo2DGlobalMapping;
class CATGeoFactory;
class CATICGMSurTo2DGlobalMapping;

/**
 * Class defining the operator that maps a wire on a shell onto another shell.
 *<ul>
 *<li>The CATTopDevelop operator is created with the <tt>CATCreateTopDevelop</tt> method and 
 * directly <tt>delete</tt>d.
 * It is is not streamable. 
 *<li>Options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>The result is accessed with the <tt>GetResult</tt> method.
 *</ul> 
 */
class ExportedByBODYNOPE CATTopDevelop : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopDevelop);
  public :
  /** @nodoc */
  CATTopDevelop (CATGeoFactory*     iContainer,
                 CATTopData*        iData);
   /** @nodoc */
  CATTopDevelop (CATGeoFactory*     iContainer,
                 CATCGMJournalList* iJournal=NULL);

  virtual      ~CATTopDevelop();

/**
 * Proposes a face of the target body on which the computed wire might pass. 
 * @param iInitialFace
 * The pointer to the face.
 */
    virtual void         SetTargetInitialFace(CATFace* iInitialFace)=0        ; 
};

/** 
* Creates an operator that maps a wire on a shell onto a wire on another shell.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled.
* @param iWire
* The pointer to the wire body to map. 
* The body only contains one wire, that must be lying on <tt>iWireSupport</tt>..
* @param iWireSupport
* The pointer to the shell body, that only contains one shell on which <tt>iWire</tt> is lying on.
* @param iTargetSupport
* The pointer to the shell body, that only contains one shell on which <tt>iWire</tt> must be mapped.
* @param iMappingIn
* The mapping from <tt>iWireSupport</tt> onto the 2D space. To create with the <tt>CreateXxxMapping</tt>
* global functions and to <tt>delete</tt> after use.
* @param iMappingOut
* The mapping from the 2D space onto <tt>iTargetSupport</tt>. To create with the <tt>CreateXxxMapping</tt>
* global functions and to <tt>delete</tt> after use.
* @return
* The pointer to the created operator. To delete after use with the usual <tt>C++</tt> operator.
*/
ExportedByBODYNOPE
CATTopDevelop * CATCreateTopDevelop(CATGeoFactory           *iFactory,
                                    CATTopData              *iData,
                                    CATBody                 *iWire,        
                                    CATBody                 *iWireSupport,
                                    CATBody                 *iTargetSupport,
                                    CATSurTo2DGlobalMapping *iMappingIn,
                                    CATSurTo2DGlobalMapping *iMappingOut);

/** 
* Creates an operator that maps a wire on a shell onto a wire on another shell.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled.
* @param iWire
* The pointer to the wire body to map. 
* The body only contains one wire, that must be lying on <tt>iWireSupport</tt>..
* @param iWireSupport
* The pointer to the shell body, that only contains one shell on which <tt>iWire</tt> is lying on.
* @param iTargetSupport
* The pointer to the shell body, that only contains one shell on which <tt>iWire</tt> must be mapped.
* @param iMappingIn
* The mapping from <tt>iWireSupport</tt> onto the 2D space. To create with the <tt>CreateXxxMapping</tt>
* global functions and to <tt>delete</tt> after use.
* @param iMappingOut
* The mapping from the 2D space onto <tt>iTargetSupport</tt>. To create with the <tt>CreateXxxMapping</tt>
* global functions and to <tt>delete</tt> after use.
* @return
* The pointer to the created operator. To delete after use with the usual <tt>C++</tt> operator.
*/
ExportedByBODYNOPE
CATTopDevelop * CATCreateTopDevelop(CATGeoFactory           *iFactory,
                                    CATTopData              *iData,
                                    CATBody                 *iWire,        
                                    CATBody                 *iWireSupport,
                                    CATBody                 *iTargetSupport,
                                    CATICGMSurTo2DGlobalMapping *iIMappingIn,
                                    CATICGMSurTo2DGlobalMapping *iIMappingOut);

#endif
