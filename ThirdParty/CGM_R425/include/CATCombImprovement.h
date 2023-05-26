// COPYRIGHT DASSAULT SYSTEMES 2002
//==============================================================================
//
// CATCombImprovement:
// Nettoyage d'une liste de CATFrFGeneralComb: correction des discontinuites C0 et C1 
// du champ de vecteurs defini par la liste de CATFrFGeneralComb
//
// N.B
// - Les peignes utilisés doivent implémenter la méthode Duplicate()                   (1)
// - Ce nettoyage est sans changement de parametrage.
// - Ce nettoyage est basé séquentiellement
//     - 1) sur CATCombCleaner              pour nettoyage
//     - 2) sur CATFrFGeneralCombApprox     pour Approximation par zone C1             (1)
//     - 3) sur CATSmoothCurve              pour lissage       par zone C1             (3)
// - Le résultat est une CCV correspondant aux extremités nettoyées
//   et lissées du peigne                                                              (2)
// - La filière classique consiste à construire ensuite un CATFrFSmoothedComb          (2)
//
//   documentation: (1) NLD230519 (2) NLD290519 (3) NLD310519
//======================================================================
//
// 03-03-03 : NDN ; Creation
// 23/05/19 : NLD ; Documentation
//                  Mise au propre; smart indent
//======================================================================
#ifndef CATCombImprovement_H
#define CATCombImprovement_H

#include "FrFAdvancedOpeCrv.h"
#include "CATSkillValue.h"
#include "CATListOfCATFrFGeneralComb.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
class CATGeoFactory;
class CATFrFCompositeCurve;

//----------------------------------------------------------------------
class  ExportedByFrFAdvancedOpeCrv CATCombImprovement
 
{
  // This operator allows to make C1 the field of 3D vectors defining by the list of CATFrFGeneralComb.
  // C1 continuity means that the field is associated to a global parametrization.This parameter is managed 
  // inside the CATFrFGeneralComb, each end parameter of a CATFrFGeneralComb must correspond to the 
  // start parameter of the next CATFrFGeneralComb.
  //       Comb1             Comb2       Comb3         Comb4
  // T0 -------------T1 T1 --------T2 T2--------T3 T3----------T4
  //
  // Input vectors are normed.
  // C0 and C1 corrections are made according to the C0 and C1 Thresholds.
  // C0 tolerance and maximum deviation are in degrees
  //

  public:
   virtual     ~CATCombImprovement() {};

   // Threshold below C0 correction is applied. 
   //
   // Default value : 0.5 degree 
   //
   virtual void SetC0Threshold        (double         iMaxC0               )    = 0;

   // Threshold below C1 correction is applied. 
   // If ||FrstDer1-FrstDer2|| < iMaxG1, then C1 correction is applied
   // (FrstDer1, and FrstDer2 are first derivatives vectorsrespectively on end of i comb and
   //  start of (i+1) comb).
   //
   // Default value : 1.e-6
   //
   virtual void SetC1Threshold        (double         iMaxC1               )    = 0;

   // Maximum deviation for the correction law.
   // iMeasureType : 0 = global deviation is used during computation. Maximum deviation is
   //                    for fixed parameter.
   //                1 = deviation into normal plane to the tangent vector of the field is used.
   // GetMaxDeformation returns the corresponding measure.
   //
   // Default value : 0.5 degree
   //
   virtual void SetToleranceDeform    (double         iTolDeform           ,
                                       int            iMeasureType         = 0) = 0;

   // Option to keep vectors on extremities of each comb, but improving the first derivatives
   // 0 : OFF , 1 : ON
   //   Default value : OFF
   //
   virtual void SetToCleanC1Only      (int            iOnlyC1              )    = 0;


   // Define if the list of curve is closed
   // Default value : FALSE
   //
   virtual void SetClosure            (int            iClose               )    = 0;

    //
    // To change orientation of the input list of combs. Default value is 1 and other possible
    // value is -1.
    //
    virtual void SetOrientation       (int            iNewOrn              = -1) = 0;

   //  Result is added into each input CATFrFGeneralComb. Correction is a CATlaw. 
   //  The law is defined on the same interval than the comb. 
   //  Evaluators methods of CATFrFGeneralComb must take into account the added correcting law. 
   // Be careful : The correcting law doesn't guarantee that the corrected vector is normed. So, user must 
   // ==========   norm the corrected vector and compute its derivative 
   //              (in CATFrFGeneralComb evaluators for example) : 
   //              Let V the corrected vector, V' its derivative,
   //              Vn = V /||V|| and Vn' = V'/||V|| - ( ((V'.V).V)/||V||^3)

   virtual void SetRemoveSmoothOption (int            iNoSmooth            = 1) = 0;


   // Fix some connexions to be left unchanged (in Sweep operator, extrapolated vertices are given).
   // ListOfFixedConnexions[iConnect] contains ranks of vertices not to clean, first vertex is the
   // one between first and second comb. Rank "number of combs + 1" corresponds to closure connection.
   virtual void SetVerticesToBeFixed  (CATListOfInt & iListOfFixedConnexions)   = 0;


   // Force some connexions to be changed even in iOnlyC1 mode.
   // Used in cae of c1 curves
   virtual void SetVerticesToBeRemoved(CATListOfInt & iListOfRemovedConnexions) = 0;


   virtual void Run                   ()                                        = 0;

   // To get status of Run method : 0 : OK,
   //                               1 : global parametrization is not valid;
   //                               2 : Eval of comb returns error
   //                               3 : Vectors are not normed
   //                               4 : Wrong derivative
   //                               5 :
   virtual int  GetStatus             ()                                        = 0;

   //
   // To get the maximum deviation during correction computation and the corresponding parameter
   //
   virtual void GetMaxDeformation     (double       & HeldMax                 ,
                                       double       & ParameterLocation       ) = 0;

   //
   // To get C0 and C1 maximum discontinuities on the list of comb 
   //
   virtual void GetDiscontinuities    (double       & oC0Dis                  ,
                                       double       & oC1Dis                  ) = 0;

   //
   // To get the mapping between initial combs and final Approx.
   // ioCombToImprove[i]->Eval(t) correspond to oCCVClean->FastEvalPoint(ioMapInterval[i]-1, t + ioShiftInterval[i])
   //
   virtual void GetResultAndMapping(CATFrFCompositeCurve *& oCCVClean      ,
                                    CATListOfInt          & ioMapInterval  ,
                                    CATListOfDouble       & ioShiftInterval)    = 0;
};

// ==================================================================
// 
// WARNING ioCombToImprove is Input/Output
//  

ExportedByFrFAdvancedOpeCrv
CATCombImprovement* CreateCATCombImprovement(CATGeoFactory              *  iFactory       ,
                                             CATLISTP(CATFrFGeneralComb) & ioCombToImprove,
                                             int                           iCATCGMLevel   ,
                                             CATSkillValue                 iMode          = BASIC);


#endif

