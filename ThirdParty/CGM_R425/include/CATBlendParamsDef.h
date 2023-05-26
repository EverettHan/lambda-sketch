//
// Copyright Dassault Systemes 1998-2009, all rights reserved
//
//=============================================================================
//
// CATBlendParamsDef :
//
//=============================================================================
// Usage notes:
//=============================================================================
//      1998     Creation
// Sep. 2009     CATBlendG2Section                            H. Leban
//=============================================================================
#ifndef CATBlendParamsDef_h
#define CATBlendParamsDef_h

// valeurs du SegmentationMode
#define CATBlendTRIM   1
#define CATBlendNOTRIM 2
#define CATBlendWithTraceOnSupport 3

// valeurs du RelimitationMode
#define CATBlendMAX    1
#define CATBlendMIN    2

// valeurs du MaxOption
#define CATBlendNONE   1
#define CATBlendPLINE  2
#define CATBlendSPLINE 4
#define CATBlendSBDY   6

// valeurs du MinOption
#define CATBlendMinNONE   1
#define CATBlendMinPUNCH  2

// valeurs du SewingOption
#define CATBlendSewingDefault 0
#define CATBlendSewingReverse 1

// valeurs du EdgeReporting
#define CATBlendDefaultEReporting  0
#define CATBlendInternalEReporting 1

// valeurs du EdgeReporting
#define CATBlendSphereTool  0
#define CATBlendCircleTool  1

// valeurs du PropagAutoMode
#define CATBlendDefaultPropagAutoMode      0
#define CATBlendStopOnFilletPropagAutoMode 1

// valeurs du KeepEdgeMode
#define CATBlendDefaultKeepEdgeMode  0
#define CATBlendImplicitKeepEdgeMode 1

// valeurs du CornerMode
#define CATBlendCornerStandard  0
#define CATBlendCornerCap       1

// valeurs du KeepEdgeConvexityMode
#define CATBlendDefaultKeepEdgeConvexityMode  0
#define CATBlendEveryKeepEdgeConvexityMode 1

// valeurs du FaceFaceInitMode
#define CATBlendDefaultNoMultiSolutionAllowed  0
#define CATBlendMultiSolutionAllowed 1 

// valeurs du ContinuityMode
#define CATBlendG0Continuity 0
#define CATBlendG1Continuity 1

// valeurs du SectionType
#define CATBlendCircularSection 0
#define CATBlendConicalSection  1
#define CATBlendG2Section       2
#define CATBlendIsoparCircularSection       3

#endif
