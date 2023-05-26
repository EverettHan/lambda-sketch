/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATTopExtractFace:
// Class for the operator that clones the geometry of input CATFace (PCurve and
// Surface) and creates a new CATFace on the brand new geometry. Operator clones
// only the necessary PCurve.
//
//=============================================================================
// Usage Notes:
//
// If list of CATFace refers to more than one element, user can make an
// assembly of the cloned CATFace with DoFaceAssembly() method.
//=============================================================================
// Jun. 99   Creation                                   L. Mahe
//=============================================================================
#ifndef CATTopExtractFace_h
#define CATTopExtractFace_h

#include "BasicTopology.h"
#include "CATTopOperator.h"
#include "CATTopSkin.h"
#include "CATHybAssemble.h"
#include "CATGeoToTopOperator.h"
#include "CATListOfCATCells.h"
#include "CATTopDef.h"
#include "CATString.h"

class CATPCurve;
class CATCrvLimits;
class CATSkinOperator;
class CATCloneManager;
class CATTopologicalOperator;
class CATHybOperator;
class CATBody;
class CATFace;
class CATLoop;


/**
 * Class representing the operator that rebuilds a body from a set of faces on an input body.
 * The new faces keep only data necessary to them. Adjacency information has disappeared.
 * If <tt>DoFaceAssembly</tt> is called before running the operator and there are two or more
 * input faces, the operator assembles the output faces. 
 * <br>To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateTopExtractFace</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. 
 * <li>Run it
 * <li>Get the result using the GetResult method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 *<li><tt>delete</tt> it after use with the usual C++ delete operator.
 *</ul> 
 */
class ExportedByBasicTopology CATTopExtractFace : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopExtractFace);
  public :
    //-------------------------------------------------------------------------
    // Constructor/Destructor
    //-------------------------------------------------------------------------
/** @nodoc */
    CATTopExtractFace(CATGeoFactory     * iFactory,
                      CATTopData        * iTopData,
                      CATFace           * iFace,
                      CATBodyFreezeMode   iMode = CATBodyFreezeOff);

/** @nodoc */
    CATTopExtractFace(CATGeoFactory     * iFactory,
                      CATTopData        * iTopData,
                      CATLISTP(CATCell) * iFaces,
                      CATBodyFreezeMode   iMode = CATBodyFreezeOff);

/**
 * Destructor.
 */
    virtual ~CATTopExtractFace();

    //-------------------------------------------------------------------------
    // Operator management
    //-------------------------------------------------------------------------
   /**
    * Runs the operator.
    * @return
    * <br><b>Legal values</b>: <tt>0</tt> if ok, <tt>1</tt> if failed
    */
    int  Run();

	/**
	 * @nodoc
	 * Causes multiple result faces to be assembled by the operator.
	 */
    void DoFaceAssembly();

  /** @nodoc @nocgmitf */
    static const CATString *GetDefaultOperatorId() { return &_OperatorId; }
  
  protected :

    // CGM Replay
    static CATString  _OperatorId;
    const  CATString *GetOperatorId();
    CATExtCGMReplay  *IsRecordable( short &LevelOfRuntime, short &VersionOfStream );
    void              WriteInput( CATCGMStream  &ioStream );
    void              Dump( CATCGMOutput &os ) ;
    int               RunOperator();
    void              RequireDefinitionOfInputAndOutputObjects();    
};
#endif
