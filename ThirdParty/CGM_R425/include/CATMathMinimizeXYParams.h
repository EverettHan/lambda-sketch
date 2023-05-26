#ifndef CATMathMinimizeXYParams_H
#define CATMathMinimizeXYParams_H

// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// External and internal parameters description for CATMathFunctionXY minimizers
//
//=============================================================================
// 21/07/11 NLD Cr�ation
//              - les options internes additives pour CATMathMinimizeXY et ses classes deriv�es
//                proviennent de l'impl�mentation de cette classe
//              - la liste des attributs et de leur utilisation
//                provient des impl�mentations de CATMathFunctionXY CATMathMinimizeXY et CATMathDirectMinimizeXY
//=============================================================================

// Additive option for minimizing (internal use: reserved for this class and its super classes)
// ------------------------------
//   **** A renommer et prefixer par CATMathMinimizeXY_     NLD200711
//    absolute minimum              0
//    all minima                   +1 (actif par d�faut dans CATMathMinimizeXY, pas dans CATMathDirectMinimizerXY)
//    interior minima              +2
//    image lower than M           +4
//    interval method              +8
#define CATMathALLEXTREMA       1
#define CATMathINTERIOREXT      2
#define CATMathIMAGECOMPAREDEXT 4
#define CATMathINTERVALMETHOD   8
#define CATMathRELENTLESSLY    16

//-------------------------------------------------------------------
// gestion des attributs du Minimize de CATMathFunctionXY: (bilan au 21/07/11) NLD
//-------------------------------------------------------------------
#define CATMathMinimizeXYParams_ISwearToAlwaysKeepConsistencyWithDoc(subscriber) // tous les abonn�s doivent maintenir cette documentation
//
// 1) attributs geres par CATMathFunctionXY::Minimize()
//    -------------------------------------------------
//    directement:
// "CATMathAttrTolObject" "CATMathAttrScaleOption"  "DirectMethod"
//    et indirectement via CATMathFunctionXY_DirtyAttributeScaling
// "TolForCst"  "AbsoluteTolerance"  "Tolerance"  "LimitValue"  "EpsRoot"

// 2) attributs geres par CATMathMinimizeXY::Minimize()
//    -------------------------------------------------
// "AbsoluteExtremum"  "InteriorExtremum"  "LimitValue"  "TolForCst"  "IntervalMethod"  "Relentlessly"
// "LocalMin_BugCorrected" "SpecialPoints"  "Tolerance"  "CATMathAttrScaleOption"
// "SamplingPointsX"  "SamplingPointsY"  "GridGlobalOptimum"  "GridLocalOptimum"

// 3) attributs geres par CATMathDirectMinimizeXY::Minimize()
//    -------------------------------------------------------
// "LimitValue"  "TolForCst"  "SamplingPointsX"  "SamplingPointsY"  "CATMathAttrTolObject"
// "CATMathAttrScaleOption"
// "AllExtrema" (new 21/07/11)
// (utilis�s en interne mais non lus "AbsoluteExtremum" "BrentMethod" "BrentMethodTrueSampling" "SamplingPoints")
//
// 4) synth�se des utilisations (X si utilisation, O sinon)
//    -------------------------
//
//                              CATMathFunctionXY
//                              ! CATMathMinimizeXY
//                              ! ! CATMathDirectMinimizeXY
//                              ! ! !
// "CATMathAttrTolObject"       X O X (CATTolerance recu en argument par CATMathMinimizeXY)
//                                    (CATTolerance recu en argument par CATMathDirectMinimizerXY
//                                     dont l'interrogation de l'attribut "CATMathAttrTolObject" ne vient qu'en
//                                     suppl�ment (historique) redefinir le cas �ch�ant l'objet CATTolerance)
//                                    (cependant revoir certains constructeurs de classes deriv�es) ********
// "CATMathAttrScaleOption"     X X X (CATMathFunctionXY fait un rescaling d'apres cet attribut
//                                     CATMathMinimizeXY et CATMathDirectMinimizeXY interrogent seulement
//                                     le champ _OKReviewed)
// "DirectMethod"               X O O (CATMathFunctionXY active le switch vers CATMathDirectMinimizeXY)
// "TolForCst"                  X X X
// "Tolerance"                  X X O
// "LimitValue"                 X X X
// "AbsoluteExtremum"           O X O
// "InteriorExtremum"           O X O
// "IntervalMethod"             O X O
// "LocalMin_BugCorrected"      O X O (pertinent seulement pour CATMathMinimizeXY: bug sp�cifique)
// "SpecialPoints"              O X O (N.B voir leur re-scaling?)
// "SamplingPointsX"            O X X
// "SamplingPointsY"            O X X
// "GridGlobalOptimum"          O X O
// "GridLocalOptimum"           O X O
// "Relentlessly"               O X O (d�clenche un rattrapage surdiscretis� en l'absence de solution)
//                                    (incompatible avec "GridGlobalOptimum" et "GridLocalOptimum")
// "AllExtrema"                 O O X (CATMathMinimizeXY:       non necessaire car c'est le d�faut)
//                                    (CATMathDirectMinimizeXY: necessaire car le d�faut utilise la meilleure init seulement) 
// non pertinents
// "EpsRoot"                    X O O (non utilise par les minimiseurs)
// "AbsoluteTolerance"          X O O (non utilise par les minimiseurs)
// "BrentMethod"                O O O
// "BrentMethodTrueSampling"    O O O
// "SamplingPoints              O O O
//
// 5) remarques:
//    ---------
//  Ensemble de param�tres incompatibles et priorit�s de ces param�tres:
//  A) 1) "GridGlobalOptimum" 2) "GridLocalOptimum" 3) "Relentlessly"

#endif
