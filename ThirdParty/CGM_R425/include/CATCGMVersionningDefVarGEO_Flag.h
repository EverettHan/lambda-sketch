// ---------------------------------------------------------------------------------------------------------------
// Q48 (08/07/19): Some simple mechanism to allow newly defined variables to be activated in
//                 the environment. To use it, please use this template:

// #ifndef CGM_Versionning_MyVersioningVariable
// GEO_FLAG_OBJ(CGM_Versionning_MyVersioningVariable, 32000)
// #endif
//
//
// Otherwise, to use the old mechanism, please copy the following
// #ifndef CGM_Versionning_MyVersioningVariable
// #define CGM_Versionning_MyVersioningVariable 32000 
// #endif 

// Note, there is deliberately no #ifndef/#define protection for this header file because we 
// need to be able to "include" this part of the file twice:
//   - in CATCGMVersioningDefVarGEO.h (to declare the flags) and
//   - in CATCGMVersioningDefVarGEO_Flag.cpp (to define the flags)

// To check the flag in the code use IsCGMVersioningActive(CGMLevel, CGM_Versionning_MyVersioningVariable)

// To activate the flag from the console please set both:
//    set GeopManualVersioning=1 
//    set CGM_Versionning=...

// ---------------------------------------------------------------------------------------------------------------

// To use the new mechanism, please use following macro in your code
//   if (IsCGMVersioningActive(CGMLevel, CGM_Versionning_MyVersioningVariable))
// this replaces
//   if (CGMLevel >= CGM_Versionning_MyVersioningVariable)

// ---------------------------------------------------------------------------------------------------------------
// The definition of the flags:
//     **** please keep this file tidy by removing variables once they have been offically declared ****
// ---------------------------------------------------------------------------------------------------------------

// R1Y 27/04: Treatment of short curves in the detection of thin loops.
#ifndef CGM_Versionning_ConfusionCrvCrv_CorrectionTest
GEO_FLAG_OBJ(CGM_Versionning_ConfusionCrvCrv_CorrectionTest, 32000)
#endif
