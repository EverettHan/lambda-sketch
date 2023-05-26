#ifndef CATTopologicalFilletBlend_H
#define CATTopologicalFilletBlend_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATIACGMLevel.h"

#define CATCGM_FILLETBLEND_DELETED


#ifndef CATCGM_FILLETBLEND_DELETED

#include "CATBlendValue.h"
#include "CATTopOperator.h"
#include "CreateTopologicalFilletBlend.h"
#include "CATBlendBuildMode.h"

#include "CATFrFCCvParam.h"
class CATFrFCompositeCurve;
class CATLaw;

/**
* @deprecated V5R17
*
* THIS CLASS HAS BEEN REMOVED IN V5R19 - DO NOT USE IT 
*
* Use CATDynFillet and CATTopBlend instead.
* Class defining the topological operator that creates the connecting surface between two skin bodies
*  using a bitangency algorithm.
* <br>The goal of the CATTopologicalFilletBlend operator is to create a class A fillet surface.
* To compute it, new surfaces are created, corresponding to the input supporting surfaces that are limited by the
* bitangency paths. Then, the fillet surface is computed and returned as a new body. 
*<ul>
* <li>A CATTopologicalFilletBlend operator is created with the <tt>CATCreateTopologicalFilletBlend</tt> global function.
* It must be directly deleted with the usual C++ <tt>delete</tt> operator after use. It is is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method. 
*<li>The resulting class A skin body is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. It is also
* possible to retrieve the created supporting surface (that was relimited on the fillet paths) 
* with the <tt>GetSplitSupport</tt> methods.
* <li>The journal corresponding to the blend operation is not yet implemented.
*</ul>
*/
class ExportedByPowerTopologicalOpe CATTopologicalFilletBlend : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopologicalFilletBlend);
public :

        /** 
         * @nodoc 
         */
                                 CATTopologicalFilletBlend(      CATGeoFactory    * iFactory  ,
                                                                 CATTopData       * iTopData  );
        /** 
         * @nodoc 
         */
                                 CATTopologicalFilletBlend(      CATGeoFactory    * iFactory  ,
                                                                 CATCGMJournalList* iJournal);

  virtual                       ~CATTopologicalFilletBlend();
  /**
   * Returns two CATBody containing the bitangencies curves.
   * @return
   * The array of the pointers to the two bodies representing the bitangency paths. This array is allocated
         * by the method and must be deallocated by the caller.
   */
  virtual CATBody              ** GetPreviewResult        ()=0;

        /** 
         * @nodoc 
         */
  virtual CATFrFCompositeCurve ** GetPreviewResultNew     () =0;

  /**
         * Runs <tt>this</tt> operator (<tt>ADVANCED</tt> mode).
         */
  virtual int                     Run                     () =0;

  /**
  * Returns the result of <tt>this</tt> operator.
        * @return
  * The pointer to the created skin body, defining the bitangent fillet surface.
        * You must delete it with the @href CATICGMContainer#Remove 
        * method if you do not want to keep it.
        */
  virtual CATBody               * GetResult               () = 0;

  /**
         * Returns the created split surface.
   * @return  
         * The pointer to the skin body containing the limited first surface.
         * You must delete it with the @href CATICGMContainer#Remove 
         * method if you do not want to keep it.
   */
  virtual CATBody               * GetSplitSupport1        () const = 0;

  /**
         * Returns the created split surface.
   * @return  
         * The pointer to the skin body containing the limited second surface.
         * You must delete it with the @href CATICGMContainer#Remove 
         * method if you do not want to keep it.
   */
  virtual CATBody               * GetSplitSupport2        () const = 0;
   
 /**
  * Returns the orientation of the skin bodies used to define the center of the fillet.
        * @param iWhichSkin
        * The first(1) or second (2) input skin body.
  * @return
        * The orientation.
        * <br><b>Legal values</b>: <tt>1</tt> for the natural orientation of the skin body,
        * <tt>-1</tt> for the opposite orientation.
  */        
  virtual CATLONG32               GetOrientation          (const CATLONG32          iWhichSkin) = 0;

        /**
  * Defines the orientation of the skin bodies used to define the center of the fillet.
        * @param iWhichSkin
        * The first(1) or second (2) input skin body.
  * @param iOrientation
        * The orientation.
        * <br><b>Legal values</b>: <tt>1</tt> for the natural orientation of the skin body (default value),
        * <tt>-1</tt> for the opposite orientation.
  */        
  virtual void                    SetOrientation          (const CATLONG32          iWhichWire,
                                                           const CATLONG32          iOrientation) = 0;

  /**
         * Defines the input value of the fillet blend surface. 
   * @param iRadius
         * The input radius value. 
   */
  virtual void                    SetRadius               (const double             iRadius) = 0;
 
  /** 
         * @nodoc 
         */
  virtual double                  GetMinRadius            () const = 0;

        /**
         * Defines the mode of creation of the blend surface.
         * @param iBuildMode
         * The mode of the blend surface.
         */
  virtual void                    SetBuildMode            (const CATBlendBuildMode  iBuildMode) = 0;
 
        /**
         * Defines the continuity criteria to take into account for a given skin body.
         * @param iWhichSkin
         * The first (1) or the second (2) input skin body.
         * @param iTransitionContinuity
         * The continuity criteria
         * <br><b>Legal values</b>: <tt>0</tt> for G0 continuity, <tt>1</tt> for G1 continuity (default value), 
         * <tt>2</tt> for G2 continuity.
         */ 
  virtual void                    SetTransitionContinuity (const CATLONG32          iWhichSkin, 
                                                           const CATLONG32          iTransitionContinuity) = 0;
 
        /**
         * Defines the way of construction of the second rank of control points of the blend surface.
         * <br>In case of <tt>CATBlendBuildMode::AnalyticBlendMode</tt> and G1 or G2 continuity.
         * @param iBlendTgContMode
         * The way of construction. 
         */
    virtual void                  SetTangencyContinuityMode(const CATBlendTgContMode iBlendTgContMode) = 0;

 /**
        * Defines the minimum length of a valid edge along the bitangency path.
        * <br>If an edge less than this value is computed, it is merged with an adjacent edge lying
        * on the same surface.
        * @param iMaxLengthOfMerge
        * The length.
        */
    virtual void                  SetMaxLengthOfMerge      (      double             iMaxLengthOfMerge) = 0;
 
  /** 
         * @nodoc 
         */
  virtual void                    SetRminMode              () =0;

  /** 
         * @nodoc 
         */
  virtual void                    SetParam                 (      double             iRmin1           ,
                                                                  double             iRmin2           ,
                                                                  double             iTtg1            ,
                                                                  double             iTtg2            ,
                                                                  double             iTc1             ,
                                                                  double             iTc2             ) = 0;

        /** 
         * @nodoc 
         */
  virtual void                    SetRminLaw               (      CATLaw           * iMinRadiusLaw    ) = 0;

        /** 
         * @nodoc 
         */
  virtual void                    SetStretchLaw            (      CATLaw           * iStretchLaw      ) = 0;
        
  /** 
         * @nodoc 
         */
  virtual void                    SetLimits                (const CATLONG32          iSide            ,
                                                                  CATFrFCCvParam   * iCCvParam        ) = 0;
        /** 
         * @nodoc 
         */
  virtual void                    RemoveLimits             (const CATLONG32          iSide            ,
                                                            const CATLONG32          iExt             ) = 0;
//
        };


/**
 * Creates a topological operator that computes the connecting surface between two skin bodies,
 * using a bi-tangency algorithm.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * <br>The journal is not yet implemented.
 * @param iBodySupport1
 * The pointer to the first skin body: it contains only one face, that covers the whole surface.
 * @param iBodySupport2
 * The pointer to the second skin body: it contains only one face, that covers the whole surface.
 * @param iOrientation1
 * The orientation of <tt>iBodySupport1</tt>, to define the center of the fillet.
 * @param iOrientation2
 * The orientation of <tt>iBodySupport2</tt>, to define the center of the fillet. 
 * @param iRadius
 * The constant radius value.
 * @param iDomainSupport1
 * To keep to <tt>0</tt>.
 * @param iDomainSupport2
 * To keep to <tt>0</tt>.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator afer use.
 * @see CATTopologicalFilletBlend
 */
ExportedByPowerTopologicalOpe
CATTopologicalFilletBlend *        CATCreateTopologicalFilletBlend 
                                                                (     CATGeoFactory * iFactory,
                                                                      CATTopData    * iTopData,
                                                                const CATBody       * iBodySupport1,
                                                                const CATBody       * iBodySupport2,
                                                                      CATLONG32       iOrientation1,
                                                                      CATLONG32       iOrientation2,
                                                                      double          iRadius,
                                                                const CATDomain     * iDomainSupport1 = 0,
                                                                const CATDomain     * iDomainSupport2 = 0 );

#endif
#endif








