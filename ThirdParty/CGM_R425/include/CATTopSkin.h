#ifndef CATTopSkin_h
#define CATTopSkin_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
*/ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATGeoToTopOperator.h"
#include "CATMathDef.h"

class CATGeoFactory;
class CATBody;
class CATDomain;
class CATShell;
class CATLoop;
class CATFace;
class CATEdge;
class CATVertex;
class CATSurface;
class CATPlane;
class CATPCurve;
class CATCrvParam;
class CATCrvLimits;
class CATSurLimits;
class CATMathLine;
class CATMathBox;
class CATCGMJournalList;

/** 
 * Class representing the operator that creates a skin body from one surface. 
 * The resulting body has one face in a shell domain, and can be build from
 * <ul><li>the surface boundaries
 * <li>a list of curves defining a closed loop on the surface
 * <li>the intersection of a plane and a canonical box.
 * </ul>
 * Moreover, the operator allows the faces to have inside loops (holes).
 * <br>To use the CATTopSkin:
 * <ul><li>Create it the <tt>CATCreateTopSkin</tt> global function. 
 * <li>If needed, tune some parameters with the <tt>SetXxx</tt> methods. In particular, closure or internal
 * loops can be described at this time.
 * <li> <tt>Run</tt> the operator
 * <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.</ul>
 * If the surface is closed, the operator creates a shell with 2 or 4 faces.
 */
class ExportedByPrimitivesLight CATTopSkin :public CATGeoToTopOperator
{
  CATCGMVirtualDeclareClass(CATTopSkin);
public:
	
/**
 * @nodoc
 */
	CATTopSkin(CATGeoFactory      *iFactory,
		CATTopData         * iData
#ifdef CATIACGMR214CAA
    , CATExtTopOperator *iExtensible = NULL
#endif    
    );

/**
 * @nodoc
 */	
	CATTopSkin(CATGeoFactory      *iFactory, 
		CATBody            *iBodyForCellCreation,
		CATBodyFreezeMode   iBodyFreezeMode=CATBodyFreezeOn,
		CATCGMJournalList  *iReport=NULL
#ifdef CATIACGMR214CAA
    , CATExtTopOperator *iExtensible = NULL
#endif    
    );
	
	~CATTopSkin();

#ifdef CATIACGMV5R20
  /**
 * Defines an internal loop in the face of a skin body. To be called before <tt>Run</tt>.
 * @param iNbPcurves
 * The number of curves to build the internal loop.
 * @param iPcurves
 * The array <tt>[iNbPcurves]</tt> of pointers to the curves on the surface used to define the skin.
 * @param iLimits
 * The array <tt>[iNbPcurves]</tt> of the limits for each curve.
 * @param iOrientations
 * The array <tt>[iNbPcurves]</tt> of the relative orientation for each curve.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>1</tt></dt><dd>The curve is used in is original orientation.
 * <dt><tt>-1</tt></dt><dd>The curve is used with an opposite orientation.
 * </dl>
 * Combine with <tt>iLimits</tt>, these specifications must insure that the end of
 * one curve (possibly reversed) is the beginning of the following.
 * Every created edge is positively oriented in the loop.
 */
  virtual void  SetInternalLoop(int iNbPcurves, CATPCurve **iPcurves, CATCrvLimits *iLimits, short *iOrientations)=0;

#endif
	
/**
 * @deprecated V5R20
 * Use @href SetInternalLoop instead
 * Defines an internal loop in the face of a skin body.
 * @param iNbPcurves
 * The number of curves to build the internal loop.
 * @param iPcurves
 * The array <tt>[iNbPcurves]</tt> of pointers to the curves on the surface used to define the skin.
 * @param iLimits
 * The array <tt>[iNbPcurves]</tt> of the limits for each curve.
 * @param iOrientations
 * The array <tt>[iNbPcurves]</tt> of the relative orientation for each curve.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>1</tt></dt><dd>The curve is used in is original orientation.
 * <dt><tt>-1</tt></dt><dd>The curve is used with an opposite orientation.
 * </dl>
 * Combine with <tt>iLimits</tt>, these specifications must insure that the end of
 * one curve (possibly reversed) is the beginning of the following.
 * Every created edge is positively oriented in the loop.
 */
	virtual void  AddInternalLoop(int iNbPcurves, CATPCurve **iPcurves,
		CATCrvLimits *iLimits, short *iOrientations)=0;
	
/**
 * @deprecated V5R20
 * Use @href SetInternalLoop instead
 * Defines an internal loop in the face of a skin body.
 * @param iNbPcurves
 * The number of curves to build the internal loop.
 * @param iPcurves
 * The array <tt>[iNbPcurves]</tt> of pointers to the curves on the surface used to define the skin.
 * @param iLimits
 * The array <tt>[iNbPcurves]</tt> of the limits for each curve.
 * These specifications must insure that the end of
 * one curve is the beginning of the following.
 * Every created edge is positively oriented in the loop.
 */
	virtual void  AddInternalLoop(int iNbPcurves, CATPCurve **iPcurves, CATCrvLimits *iLimits)=0;
	
/** 
 * Runs <tt>this</tt> operator.
 */
	virtual int   Run()=0;
	
/**
 * Asks for the closure of the skin in the first surface direction.
 * <br> The geometry must be compatible with this closure.
 */
	virtual void  ForceSkinClosureInU()=0;
	
/**
 * Asks for the closure of the skin in the second surface direction.
 * <br> The geometry must be compatible with this closure.
 */
	virtual void  ForceSkinClosureInV()=0;
	
/**
 * Returns the pointer to the shell of the resulting skin body.
 * @return
 * The pointer to the shell of the resulting skin body. Remember that the whole body is retrieved with
 * the <tt>GetResult</tt> method, and you must manage its deletion if you do not want to keep it.
 */
	virtual CATShell* GetShell() const=0;
	
/** 
 * Retrieves the limits on the surface taken into account by <tt>this</tt> operator. 
 * @param ioSurLim
 * The surface limits taken into account.
 */
	virtual void GetLimits(CATSurLimits & iSurLim)=0;

/** 
 * Defines limits on the surface to be taken into account by <tt>this</tt> operator. 
 * @param iSurLim
 * The surface limits to take into account.
 */
	virtual void SetLimits(const CATSurLimits & ioSurLim)=0;

/**
 * @nodoc
 * DO NOT USE - SEE ABOVE
 */
	virtual void GetCheck(int & oChecking)=0;

/**
 * @nodoc
 * DO NOT USE - SEE ABOVE
 * 0 no check
 * 1 with check
 */
	virtual void SetCheck(int iChecking)=0;

};

/**
 * Creates an operator to build a skin body on one surface.
 * The boundaries of the shell are the surface boundaries.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside the
 * configuration is <tt>NULL</tt>, it is not filled. 
 * @param iSurface
 * The pointer to the surface used to define the shell.
 * @param iLims
 * The limits to apply to the surface.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */
ExportedByPrimitivesLight CATTopSkin * CATCreateTopSkin (CATGeoFactory      *iFactory, CATTopData * iData,
		CATSurface         *iSurface,
		const CATSurLimits * iLims);
	/** @nodoc */
ExportedByPrimitivesLight CATBody * CATCreateSkin (CATGeoFactory      *iFactory, CATTopData * iData,
		CATSurface         *iSurface,
		const CATSurLimits * iLims);

/**
 * Creates an operator to build a skin body from several curves on the same surface.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iNbPcurves
 * The number of curves to build the external loop.
 * @param iPcurves
 * The array <tt>[iNbPcurves]</tt> of pointers to the curves on the surface used to define the skin.
 * @param iLimits
 * The array <tt>[iNbPcurves]</tt> of the limits for each curve.
 * @param iOrientations
 * The array <tt>[iNbPcurves]</tt> of the relative orientation for each curve.
 * <br><b>Legal values</b>:
 * <dl><dt><tt>1</tt></dt><dd>The curve is used in is original orientation.
 * <dt><tt>-1</tt></dt><dd>The curve is used with an opposite orientation.
 * </dl>
 * Combine with <tt>iLimits</tt>, these specifications must insure that the end of
 * one curve (possibly reversed) is the beginning of the following.
 * Every created edge is positively oriented in the loop.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */
ExportedByPrimitivesLight CATTopSkin * CATCreateTopSkin (CATGeoFactory      *iFactory, CATTopData * iData,
		CATSurface         *iSurface,
		int                 iNbPcurves,
		CATPCurve         **iPcurves,
		CATCrvLimits       *iLimits,
		short              *iOrientations);

#endif
