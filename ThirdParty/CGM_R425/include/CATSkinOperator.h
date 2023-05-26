#ifndef CATSkinOperator_h
#define CATSkinOperator_h

// COPYRIGHT DASSAULT SYSTEMES  1999


#include "CATTopSkin.h"
#include "CATMathDef.h"
#include "CATSurLimits.h"

class CATGeoFactory;
class CATBody;
class CATDomain;
class CATShell;
class CATLoop;
class CATFace;
class CATEdge;
class CATVertex;
class CATSurface;
class CATSimCurve;
class CATMacroPoint;
class CATPlane;
class CATPCurve;
class CATCrvParam;
class CATCrvLimits;
class CATMathLine;
class CATMathBox;
class CATCGMJournalList;
class CATWireOperatorExt;
class CATSkinOperatorExt;

/** 
 * Deprecated. Use now @href CATTopSkin .
 * Class representing the operator that creates a skin body from one surface. 
 * The resulting body has one face in a shell domain, and can be build from
 * <ul><li>the surface boundaries
 * <li>a list of curves defining a closed loop on the surface
 * <li>the intersection of a plane and a canonical box.
 * </ul>
 * Moreover, the operator allows the faces to have inside loops (holes).
 * <br>To use the CATSkinOperator:
 * <ul><li>Create it with one of the available constructors. 
 * <li>If needed, tune some parameters with the <tt>SetXxx</tt> methods. In particular, closure or internal
 * loops can be described at this time.
 * <li> <tt>Run</tt> the operator
 * <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
 * <li><tt>delete</tt> the operator after use.</ul>
 * If the surface is closed, the operator creates a shell with 2 or 4 faces.
 */
class ExportedByPrimitivesLight CATSkinOperator :public CATTopSkin
{
  CATCGMVirtualDeclareClass(CATSkinOperator);
public:

   /** @nodoc */
   CATSkinOperator(CATGeoFactory      * iFactory        ,
                   CATSurface         * iSurface        ,
                   CATBody            * iTargetBody     = NULL,
                   CATBodyFreezeMode    iBodyfreezemode = CATBodyFreezeOn,
                   CATCGMJournalList  * report          = NULL);

   /**
   * Deprecated.<br> Use CATCreateTopSkin.
   * Creates an operator to build a skin body on one surface.
   * The boundaries of the shell are the surface boundaries.
   * @param iFactory
   * The pointer to the factory of the geometry.
   * @param iSurface
   * The pointer to the surface used to define the shell.
   * @param iTargetBody
   * Must be kept to <tt>NULL</tt>.
   * @param iBodyfreezemode
   * The smart mode of the resulting body.
   * @param iReport
   * The pointer to the journal to fill with the operation report. If <tt>NULL</tt>, the 
   * journal is not written.
   */
   CATSkinOperator(CATGeoFactory      * iFactory        ,
                   CATTopData         * iTopData        ,
                   CATSurface         * iSurface        );

   /** @nodoc */
   CATSkinOperator(CATGeoFactory      * iFactory        ,
                   int                  iNbPcurves      ,
                   CATPCurve         ** iPcurves        ,
                   CATCrvLimits       * iLimits         ,
                   short              * iOrientations   ,
                   CATBody            * iTargetBody     = NULL,
                   CATBodyFreezeMode    iBodyfreezemode = CATBodyFreezeOn,
                   CATCGMJournalList  * iReport         = NULL);

   /**
   * Deprecated. <br>Use CATCreateTopSkin.
   * Creates an operator to build a skin body from several curves on the same surface.
   * @param iFactory
   * The pointer to the factory of the geometry.
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
   * @param iTargetBody
   * Must be kept to <tt>NULL</tt>.
   * @param iBodyfreezemode
   * The smart mode of the resulting body.
   * @param iReport
   * The pointer to the journal to fill with the operation report. If <tt>NULL</tt>, the 
   * journal is not written.
   */
   CATSkinOperator(CATGeoFactory      * iFactory        ,
                   CATTopData         * iTopData        ,
                   int                  iNbPcurves      ,
                   CATPCurve         ** iPcurves        ,
                   CATCrvLimits       * iLimits         ,
                   short              * iOrientations   );

   /** @nodoc */
   CATSkinOperator(CATGeoFactory      * iFactory        ,
                   CATPlane           * plane           ,
                   CATMathBox         & iBox            ,
                   CATBody            * iTargetBody     = NULL,
                   CATBodyFreezeMode    iBodyfreezemode = CATBodyFreezeOn,
                   CATCGMJournalList  * iReport         = NULL);
   /**
   * Creates an operator to build a skin body on a plane limited by a canonical box.
   * @param iFactory
   * The pointer to the factory of the geometry.
   * @param iPlane
   * The pointer to the plane used to define the shell.
   * @param iBox
   * The canonical box to define the limits of the plane.
   * @param iTargetBody
   * Must be kept to <tt>NULL</tt>.
   * @param iBodyfreezemode
   * The smart mode of the resulting body.
   * @param iReport
   * The pointer to the journal to fill with the operation report. If <tt>NULL</tt>, the 
   * journal is not written.
   */
   CATSkinOperator(CATGeoFactory      * iFactory,
                   CATTopData         * iTopData,
                   CATPlane           * plane   ,
                   CATMathBox         & iBox    );
   /**
   * @nodoc
   * DO NOT USE - SEE ABOVE
   */
   CATSkinOperator(CATGeoFactory      * iFactory       ,
                   int                  nbpcurves      ,
                   CATPCurve         ** pcurves        ,
                   CATCrvLimits       * limits         ,
                   CATBody            * targetBody     = NULL,
                   CATBodyFreezeMode    bodyfreezemode = CATBodyFreezeOn,
                   CATCGMJournalList  * report         = NULL);

   CATSkinOperator(CATGeoFactory      * iFactory   ,
                   CATTopData         * iTopData   ,
                   int                  nbpcurves  ,
                   CATPCurve         ** pcurves    ,
                   CATCrvLimits       * limits     );
   /**
   * @nodoc
   * DO NOT USE - SEE ABOVE
   */
   CATSkinOperator(CATGeoFactory      * iFactory       ,
                   int                  nbpcurves      ,
                   CATPCurve         ** pcurves        ,
                   CATBody            * targetBody     = NULL,
                   CATBodyFreezeMode    bodyfreezemode = CATBodyFreezeOn,
                   CATCGMJournalList  * report         = NULL);
   /**
   * @nodoc
   * DO NOT USE - SEE ABOVE
   */
   CATSkinOperator(CATGeoFactory      * iFactory       ,
                   int                  nbpcurves      ,
                   CATPCurve         ** pcurves        ,
                   short              * orientations   ,
                   CATBody            * targetBody     = NULL,
                   CATBodyFreezeMode    bodyfreezemode = CATBodyFreezeOn,
                   CATCGMJournalList  * report         = NULL);

   ~CATSkinOperator();

   /**
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
   void  SetInternalLoop(int iNbPcurves, CATPCurve ** iPcurves, CATCrvLimits * iLimits, short * iOrientations);

   void  AddInternalLoop(int iNbPcurves, CATPCurve ** iPcurves,
                         CATCrvLimits * iLimits, short * iOrientations);
   /** @nodoc  */
   void  AddInternalLoop(int nbpcurves, CATPCurve **pcurves);

   /**
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
   void  AddInternalLoop(int iNbPcurves, CATPCurve ** iPcurves, CATCrvLimits * iLimits);

   /** 
   * Runs <tt>this</tt> operator.
   */
   int   Run();

   /* @nodoc @nocgmitf */
   int   RunOperator();

   /**
   * Asks for the closure of the skin in the first surface direction.
   * <br> The geometry must be compatible with this closure.
   */
   void  ForceSkinClosureInU(); 

   /**
   * Asks for the closure of the skin in the second surface direction.
   * <br> The geometry must be compatible with this closure.
   */
   void  ForceSkinClosureInV(); 

   /**
   * Returns the pointer to the shell of the resulting skin body.
   * @return
   * The pointer to the shell of the resulting skin body. Remember that the whole body is retrieved with
   * the <tt>GetResult</tt> method, and you must manage its deletion if you do not want to keep it.
   */
   CATShell* GetShell() const;

   /** 
   * Defines limits on the surface to be taken into account by <tt>this</tt> operator. 
   * @param iSurLim
   * The surface limits to take into account.
   */
   void GetLimits(CATSurLimits & iSurLim);

   /** 
   * Retrieves the limits on the surface taken into account by <tt>this</tt> operator. 
   * @param ioSurLim
   * The surface limits taken into account.
   */
   void SetLimits(const CATSurLimits & ioSurLim);

   /**
   * @nodoc
   * DO NOT USE - SEE ABOVE
   */
   void GetCheck(int & oChecking);

   /**
   * @nodoc
   * DO NOT USE - SEE ABOVE
   * 0 no check
   * 1 with check
   */
   void SetCheck(int iChecking);

   /**
   * @nodoc
   * DO NOT USE - SEE ABOVE
   */
   void GetUseLims(int & oChecking);

   /**
   * @nodoc
   * DO NOT USE - SEE ABOVE
   * 0 no limitation authorized
   * 1 limitation required (default)
   */
   void SetUseLims(int iChecking);
   /**
   * @nodoc
   * DO NOT USE - SEE ABOVE
   * 0 no limitation authorized
   * 1 limitation required (default)
   */
   void SetResultInTargetBody(CATBody * iTB);
private:

   /**  @nodoc @nocgmitf */
   CATSkinOperatorExt & GetSkinOperatorExt() const;

   //***************************************************************************************
   // CGMReplay
   //***************************************************************************************

public:

   /* @nodoc @nocgmitf */
   static const CATString *GetDefaultOperatorId() { return &_OperatorId; }

   /* @nodoc @nocgmitf */
   void SetConstructorType(short iConstructorType);

protected:

   const  CATString  *GetOperatorId();
   CATExtCGMReplay   *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);
   void               RequireDefinitionOfInputAndOutputObjects();

   static CATString   _OperatorId;
};
#endif
