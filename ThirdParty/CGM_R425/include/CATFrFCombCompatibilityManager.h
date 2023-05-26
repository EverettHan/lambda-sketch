// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// Objet de mise en compatibilite (normales et derivees croisees) entre 2 ou plus peigne.
// ATTENTION : - TOUS LES INDEX COMMENCENT A 1 !
//==========================================================================
// April 2000  Creation                          NDN
//==========================================================================
#ifndef CATFrFCombCompatibilityManager_H
#define CATFrFCombCompatibilityManager_H

#include "FrFTopologicalOpe.h"
class CATFrFEdgesComb;
class CATCrvParam;
class CATGeoFactory;
#include "CATMathDirection.h"

/**
 * Class defining the operator that modifies <tt>CATFrFEdgeComb</tt> to make them compatible.
 * <br>To use especially when the combs are intersecting.
 * <br>To use it:
 * <ul>
 * <li>Create it with the constructor
 * <li>Set some tuning parameters
 * <li>Run it
 * <li>Delete it.
 *</ul>
 */
class ExportedByFrFTopologicalOpe CATFrFCombCompatibilityManager
{
 public:
    /**
    * Creates an operator that modifies <tt>CATFrFEdgeComb</tt> to make them compatible.
    * @param iFactory
    * The pointer to the geometry factory.
    * @param iNbComb
    * The number of combs to make compatible.
    * @param iCombToUpdate
    * The array of pointers to the combs.
    * @param iRankOfEdgeInComb
    * The array of ranks (beginning at 1) of the edge of each comb where the combs are intersecting.
    * @param iParamOfEdgeInComb
    * The array of the corresponding intersection parameters.
    */
   CATFrFCombCompatibilityManager(CATGeoFactory     * iFactory,
                                  CATLONG32                iNbComb, 
                                  CATFrFEdgesComb  ** iCombToUpdate, 
                                  const CATLONG32        * iRankOfEdgeInComb, 
                                  const CATCrvParam * iParamOfEdgeInComb);
   
   virtual ~CATFrFCombCompatibilityManager();
   
   //--------------------
   // Set
   //--------------------
   //iPriority=0 -> lowest priority i.e. maximum deformation , iPriority=1 -> priority repect to combs with a iPriority=0 i.e.
   //minimum deformation . iPriority=-1 -> No deformation at all.
   /**
    * Defines the respective priority of deformation of each comb.
    * @param iCombRank
    * The rank (beginning at 1) of the comb.
    * @param iPriority
    * The priority of its deformation.
    * <br><b>Legal values</b>:
    * <tt>0</tt> for the maximum deformation, <tt>1</tt> for the minimum deformation, <tt>-1</tt> for no deformation.
    */ 
   void SetPriority(CATLONG32 iCombRank,CATLONG32 iPriority=1);

   /**
    * Sets the maximum angular deformation.
    * <br>If the computation implies a larger deformation, nothing is done.
    * @param iAngularTolerance
    * The maximum angular deformation expressed in radian
    */
   void SetTolerance(double iAngularTolerance);
   
   /**
    * Runs <tt>this</tt> operator.
    */
   void Run();

 protected:
   //Protected methods
   CATLONG32 ComputeTargetNormal();
   void InitializeCombs();
   void CrossDerivCompatibility();

   //To know if the considered border is free i.e nothing to do on it. Index start from 1.
   CATBoolean IsFreeBorder(CATLONG32 iIndexOfComb);
   //To know if there is a C0 Gap between two combs
   CATBoolean IsThereAGap(CATLONG32 iIndex1,CATLONG32 iIndex2);

   //Protected Data
   CATGeoFactory      *_Fact;
   CATLONG32                    _NbComb;
   CATFrFEdgesComb  **_EdgesComb;
   CATLONG32                   *_Prior;
   CATLONG32                   *_Config;
   const CATLONG32             *_IndexOfEdge;
   const CATCrvParam   *_ParamOfEdge;
   CATMathDirection     _TargetNormal;
   double                 _CosTol;
};
#endif
