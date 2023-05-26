// COPYRIGHT DASSAULT SYSTEMES 2002
//==============================================================================
//
// CATCombCleaner:
// Nettoyage d'une liste de CATFrFGeneralComb: correction des discontinuites C0 et C1 
// du champ de vecteurs defini par la liste de CATFrFGeneralComb
//
// Ce nettoyage est sans changement de parametrage.
//
// Remarque importante: la filière d'appel classique et unique (hors atelier de test et programme de test)
// est d'utiliser CATCombCleaner via CATCombImprovement et CreateCATCombImprovement()
//    NLD290519
//
// XScaleRules:
// voir CATFrFGeneralComb pour les conventions relatives au Scale
// et la définition de ScaleOption
//    NLD100619
//
//======================================================================
// 13-01-03 : MWE ; Creation
// 23-05-19 : NLD ; Documentation du CreateCATCombCleaner()
// 28-05-19 : NLD ; Recommandation d'appel via CreateCATCombImprovement()
// 13-06-19 : NLD ; Ajout (provisoire?) SetTolForVVPrimXS1()
//======================================================================
#ifndef CATCombCleaner_H
#define CATCombCleaner_H

#include "FrFAdvancedOpeCrv.h"
#include "CATSkillValue.h"
#include "CATListOfCATFrFGeneralComb.h"
#include "CATListOfInt.h"

class CATGeoFactory;
class CATLaw;

//----------------------------------------------------------------------
class  ExportedByFrFAdvancedOpeCrv CATCombCleaner
 
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
   virtual      ~CATCombCleaner     ()
   {
   };

   // Threshold below C0 correction is applied. 
   //
   // Default value : 0.5 degree 
   //
   virtual void SetC0Threshold      (double        iMaxC0                 )    = 0;

   //
   // Threshold above C1 correction is applied. It is a percent (in [0,1]). 
   // If ||FrstDer1-FrstDer2||/MAX(||FrstDer1||,||FrstDer2||) < (1-iMaxC1)/iMaxC1, then C1 correction is applied
   // (FrstDer1, and FrstDer2 are first derivatives vectors respectively on end of i comb and
   //  start of (i+1) comb).
   //
   // Default value : 0.98
   //
   virtual void SetC1Threshold      (double        iMaxC1                 )    = 0;

   // Maximum deviation for the correction law.
   // iMeasureType : 0 = global deviation is used during computation. Maximum deviation is
   //                    for fixed parameter.
   //                1 = deviation into normal plane to the tangent vector of the field is used.
   // GetMaxDeformation returns the corresponding measure.
   //
   // Default value : 0.5 degree
   //
   virtual void SetToleranceDeform  (double        iTolDeform             ,
                                     int           iMeasureType           = 0) = 0;

   // Tolerance redefinition for dot product V*VPrim (V*V')
   // (default value is 1E-11)
   // Caution
   // - tolerance must be given for scale 1 factory
   //   it will be internally scaled according to ScaleOption defined internally (or externally) through SetScaleBehavior()
   // - RESTRICTED USE
   virtual void SetTolForVVPrimXS1  (double         iTolForVVPrimXS1      )    = 0;

   // Option to keep vectors on extremities of each comb, but improving the first derivatives
   // 0 : OFF , 1 : ON
   //   Default value : OFF
   //
   virtual void SetToCleanC1Only    (int            iOnlyC1               )    = 0;

   //  Result is added into each input CATFrFGeneralComb. Correction is a CATlaw. 
   //  The law is defined on the same interval than the comb. 
   //  Evaluators methods of CATFrFGeneralComb must take into account the added correcting law. 
   // Be careful : The correcting law doesn't guarantee that the corrected vector is normed. So, user must 
   // ==========   norm the corrected vector and compute its derivative 
   //              (in CATFrFGeneralComb evaluators for example) : 
   //              Let V the corrected vector, V' its derivative,
   //              Vn = V /||V|| and Vn' = V'/||V|| - ( ((V'.V).V)/||V||^3)


   // Fix some connexions to be left unchanged (in Sweep operator, extrapolated vertices are given).
   // If for a given connection rank iConnect, iListOfFixedConnexions[iConnect] is equal to 1 then this
   // connection will not be cleaned.

   // Also usable to impose connection clean, whatever its continuity may be,
   // if iListOfFixedConnexions[iConnect] is equal to 2 (NLD02/04/15 (NLD23/11/11 in CATCombCleanerCx2), documentation of evolution JSX24/09/04)
   virtual void SetVerticesToBeFixed(CATListOfInt & iListOfFixedConnexions)    = 0;


   virtual void Run                 ()                                         = 0;

   // To get status of Run method : 0 : OK,
   //                               1 : global parametrization is not valid;
   //                               2 : Eval of comb returns error
   //                               3 : Vectors are not normed
   //                               4 : Wrong derivative
   //                               5 :
   virtual int  GetStatus           ()                                         = 0;
   //
   // To get the maximum deviation (in degree) during correction computation and the corresponding parameter
   //
   virtual void GetMaxDeformation   (double       & HeldMax               ,
                                     double       & ParameterLocation     )    = 0;

   // To get C0 and C1 maximum discontinuities on the list of comb (C0 in degree, C1 is a percent)

   virtual void GetDiscontinuities  (double       & oC0Dis                ,
                                     double       & oC1PercentDis         )    = 0;
};

// ==================================================================
//
// WARNING ioCombToImprove is Input/Output
//
// N.B
// - la SoftwareConfiguration est recupérée sous le premier peigne de la liste
// - l'argument iCATCGMLevel n'a jamais été utilisé
// - Utilisation directe non recommandée: passer par CreateCATCombImprovement()
//    NLD290519 NLD230519
// ==================================================================
ExportedByFrFAdvancedOpeCrv
CATCombCleaner* CreateCATCombCleaner(      CATGeoFactory              *  iFactory       ,
                                           CATLISTP(CATFrFGeneralComb) & ioCombToImprove,
                                           int                           iCATCGMLevel   ,
                                           CATSkillValue                 iMode          = BASIC);

// ==================================================================

ExportedByFrFAdvancedOpeCrv
void Remove(CATCombCleaner *&iCombCleaner);


#endif

