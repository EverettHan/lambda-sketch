#ifndef CATRegulMode_h
#define CATRegulMode_h

// COPYRIGHT DASSAULT SYSTEMES 2012



/**
* Defines the diagnosis of CATRegul entry.
* @param CATRegulDiagNone
* default mode.
* @param CATRegulDiagModeNonOffsetable
* local curvature problem mode.
* @param CATRegulDiagModeTwistedSurface
* twisted surface problem mode.
* @param CATRegulDiagModePeakedSurface
* peaked surface mode.
* @param CATRegulDiagModeParallelTuTvSurface
* parallel TuTv surface mode.
*/

enum CATRegulDiagnosisMode 
{
     CATRegulDiagModeNone                   = 0x0, 
     CATRegulDiagModeNonOffsetable          = 0x1, 
     CATRegulDiagModeTwistedSurface         = 0x2,
     CATRegulDiagModePeakedSurface          = 0x4,
     CATRegulDiagModeParallelTuTvSurface    = 0x8
};

/**
* Defines the level of compute of CATRegul entry.
* @param CATRegulLevelDefault
* default mode, normal compute
* @param CATRegulLevelOnlyDiagnosis
* compute only diagnosis of each face of input body.
*/

enum CATRegulLevelOfCompute 
{
     CATRegulLevelDefault                   = 0x0, 
     CATRegulLevelOnlyDiagnosis             = 0x1,
     CATRegulLevelAutoDiagnosis             = 0x2
};



#endif // CATRegulMode_h















