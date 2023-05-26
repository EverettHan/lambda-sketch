#ifndef CATTopSweep_H
#define CATTopSweep_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */

#include "CATIAV5Level.h"
#include "CATIACGMLevel.h"

#include "CATMathDef.h"

#include "FrFTopologicalOpe.h"

#include "CATTopBooleanType.h"
#include "CATTopLimit.h"
#include "CATTopLimitType.h"
#include "CATTopPropagationType.h"
#include "CATTopExtrude.h"

class     CATBody;
class     CATCGMJournalList;
class     CATGeoFactory;
class     CATCGMActivateDebug;
class     CATGeometry;
class     CATMathVector ;
class     CATTopData;
class     CATExtTopSweep;


#ifndef NULL
#define NULL 0
#endif

/**
 * Class representing the topological operator that sweeps a profile. 
 * <br>The operator sweeps 
 * <ul><li>either a wire body, and creates a skin body
 * <li>or a skin body, and creates a volume body.
 * </ul>
 * <br> In addition to the sweep creation, this operator provides the capability
 * to use a Boolean operation between a body (called trimming body), and the 
 * created sweep. To obtain such result, use the @href CATTopExtrude#SetOperation
 * and @href CATTopExtrude#SetTrim mehods of the parent class.
 *<br>
 * The CATTopSweep operator follows the global frame of the topological operators 
 * and satisfies the smart mechanism: the
 * input body is not modified. A new resulting body is created, 
 * possibly sharing data with the input body. A CATTopPrism operator is not streamable.
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateTopSweep</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. In particular,
 * define the type of limitations, and, if needed, the Boolean operation.
 * <li>Run it
 * <li>Get the resulting extrusion with the @href CATTopExtrude#GetResult method, and the result
 * of the Boolean operation with the @href CATTopExtrude#GetBooleanResult method. If you do not want 
 * to keep these resulting bodies, use the @href CATICGMContainer#Remove method to remove them from the 
 * geometric factory, after the operator deletion.
 *<li>Delete with the usual C++ <tt>delete</tt> operator afer use..
 *</ul> 
 */  
class ExportedByFrFTopologicalOpe CATTopSweep : public CATTopExtrude
{
  CATCGMVirtualDeclareClass(CATTopSweep);
  public:

/**
 * @nodoc
 * Constructor. Do not use. Use the <tt>CATCreateTopSweep</tt> global function to create a
 * CATTopSweep operator.
 */
                 CATTopSweep              (CATGeoFactory          * iGeoFactory           ,
                                           CATTopData             * iData                 ,
                                           CATExtTopSweep         * iExtensible           = NULL);

/**
 * @nodoc
 * Constructor. Do not use. Use the <tt>CATCreateTopSweep</tt> global function to create a
 * CATTopSweep operator.
 */
                 CATTopSweep              (CATGeoFactory          * iGeoFactory           ,
                                           CATCGMJournalList      * iJournal              = NULL,
                                           CATExtTopSweep         * iExtensible           = NULL);
/**
 * Destructor.
 */
    virtual     ~CATTopSweep ();

/**
 * Defines the type of limitation of each extremity along the extrusion (center curve) direction.
 * <br>To be called for each extremity, if you do not want to keep
 * the default options of the global creation function.
 * @param iId
 * The first or last extremity.
 * @param iType
 * The type of limit on the extremity.
 * @param iIsAxisReverted
 * The orientation.
 * <br><b>Legal values</b>: <tt>TRUE</tt> for the same orientation as the direction defined at the operator
 * creation, <tt>FALSE</tt> for an opposite orientation. In general, use <tt>TRUE</tt> for the start limit,
 * and <tt>FALSE</tt> for the end limit.
 * @param iOffset
 * The value of the offset if <tt>iType</tt> has the value <tt>CatLimOffsetFromProfile</tt>.
 * @param iLimit
 * The pointer to the geometry or the topology that stops the extrusion.
 * @param iPropagationBody
 * The pointer to the body which contains <tt>iLimit</tt>, thus allowing the
 * propagation of the trimming specification. To use if <tt>iType = CatLimUntil</tt> and
 * <tt>iPropagationFlag = CatPropagClosing</tt>  or if <tt>iType = CatLimNextAlongAxis</tt>
 * or <tt>iType = CatLimLastAlongAxis</tt> 
 * @param iPropagationFlag
 * The management of the propagation.  
 * @param iThickness
 * defines the value of any thickness which must be applied to the considering relimitation
 */

    virtual void SetExtrudeLimit          (CATTopLimit              iId                   ,
                                           CATTopLimitType          iType                 ,
                                           CATBoolean               iIsAxisReverted       ,
                                           CATLength                iOffset               ,
                                           CATGeometry           *  iLimit                ,
                                           CATBody               *  iPropagationBody      ,
                                           CATTopPropagationType    iPropagationFlag      ,
                                           CATLength                iThickness            = CATLength (0.0)) = 0;

 /**
 * @deprecated V5R21 SetExtrudeLimit
 * Defines the type of limitation of each extremity along the extrusion (center curve) direction.
 * <br>To be called for each extremity, if you do not want to keep
 * the default options of the global creation function.
 * @param iId
 * The first or last extremity.
 * @param iType
 * The type of limit on the extremity.
 * @param iIsAxisReverted
 * The orientation.
 * <br><b>Legal values</b>: <tt>TRUE</tt> for the same orientation as the direction defined at the operator
 * creation, <tt>FALSE</tt> for an opposite orientation. In general, use <tt>TRUE</tt> for the start limit,
 * and <tt>FALSE</tt> for the end limit.
 * @param iOffset
 * Either the value of the offset if <tt>iType</tt> is valued to <tt>CatLimOffsetFromProfile</tt>, 
 * or the value of the thickness if <tt>iIsThickness</tt> is valued to <tt>CATBoolean(1)</tt> 
 * @param iLimit
 * The pointer to the geometry or the topology that stops the extrusion.
 * @param iPropagationBody
 * The pointer to the body which contains <tt>iLimit</tt>, thus allowing the
 * propagation of the trimming specification. To use if <tt>iType = CatLimUntil</tt> and
 * <tt>iPropagationFlag = CatPropagClosing</tt>  or if <tt>iType = CatLimNextAlongAxis</tt>
 * or <tt>iType = CatLimLastAlongAxis</tt> 
 * @param iPropagationFlag
 * The management of the propagation.  
 * @param iIsThickness
 * Defines whether a thickness is applied from the body <tt>iPropagationBody</tt> to define the relimitation. 
 * In this case, the value of the the thickness is <tt>iOffset</tt>
 */
    virtual void SetLimit                 (CATTopLimit              iId                   ,
                                           CATTopLimitType          iType                 ,
                                           CATBoolean               iIsAxisReverted       ,
                                           CATLength                iOffset               ,
                                           CATGeometry           *  iLimit                ,
                                           CATBody               *  iPropagationBody      ,
                                           CATTopPropagationType    iPropagationFlag      ,
                                           CATBoolean               iIsThickness          = CATBoolean (0)) = 0;

/**
 * Defines the pulling direction to replace the previously specified spine.
 * @param iPullingDirection
 * The direction defining an implicit spine to be the projection of the guide onto a plane
 * normal to this direction.
 */
    virtual void SetPullingDirection      (CATMathVector         *  iPullingDirection     = 0) = 0 ;

/**
 * @nodoc
 */
    virtual void SetDiscontinuityTreatment(CATLONG32                iMode                 = 0) = 0 ;

/**
 * @nodoc
 */ 
    virtual void SetCuspTreatment         (CATLONG32                iMode                 = 0) = 0;

/**
 * @nodoc
 */
    virtual void SetTwistDetection        (CATBoolean               iTwistDetection       = TRUE) = 0 ;
/**
 * @nodoc
 * do not use with SetLimit() and SetResultMode()
 * Eliminates twisted areas, using iRecoilDistance to eliminate a larger area at both ends
 * for each twisted area
 */
    virtual void SetTwistReduction        (CATBoolean               iTwistReduction       ,
                                           double                   iRecoilDistance       = 0.0) = 0 ;
/**
 * @nodoc
 * Forces the multiple viewing direction mode
 */
    virtual void ForceMultipleViewingDirMode() = 0 ;
};


/**
 * Creates a CATTopSweep operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iCenterBody
 * The pointer to the wire body defining the center curve of the sweep: this center curve is the 
 * curve along which the profile is swept.
 * @param iCenterSupport
 * The pointer to the body (containing a shell or a lump domain) or the surface 
 * on which the center curve is laying on.
 * @param iSpineBody
 * The pointer to the wire body defining the spine curve of the sweep: 
 * this spine curve handles the normal to the profile plane.
 * @param iProfile
 * The pointer to the wire or the skin body defining the profile of the prism. 
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator afer use.
 * @see CATTopSweep
 */
ExportedByFrFTopologicalOpe  CATTopSweep * CATCreateTopSweep (CATGeoFactory     * iGeoFactory   ,
                                                              CATTopData        * iData         ,
                                                              CATBody           * iCenterBody   ,
                                                              CATGeometry       * iCenterSupport,
                                                              CATBody           * iSpineBody    ,
                                                              CATBody           * iProfile      );
/**
 * @nodoc
 * Deprecated. Use CATCreateTopSweep (and not CATTopCreateSweep anymore).
 * Creates a CATTopSweep operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iCenterBody
 * The pointer to the wire body defining the center curve of the sweep: this center curve is the 
 * curve along which the profile is swept.
 * @param iCenterSupport
 * The pointer to the body (containing a shell or a lump domain) or the surface 
 * on which the center curve is laying on.
 * @param iSpineBody
 * The pointer to the wire body defining the spine curve of the sweep: 
 * this spine curve handles the normal to the profile plane.
 * @param iProfile
 * The pointer to the wire or the skin body defining the profile of the prism. 
 * @param iReport
 * The pointer to the journal. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> the usual C++ delete operator afer use.
 * @see CATTopSweep
 */
ExportedByFrFTopologicalOpe  CATTopSweep * CATTopCreateSweep (CATGeoFactory     * iGeoFactory   ,
                                                              CATBody           * iCenterBody   ,
                                                              CATGeometry       * iCenterSupport,
                                                              CATBody           * iSpineBody    ,
                                                              CATBody           * iProfile      ,
                                                              CATCGMJournalList * iJournal      = NULL);
#endif
