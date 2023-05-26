#ifndef CATTopFacReplSurfDef_H
#define CATTopFacReplSurfDef_H

// COPYRIGHT DASSAULT SYSTEMES 2011


//------------------------------------------------------------------------------
// Configuration for FaceReplaceSurface
//------------------------------------------------------------------------------
enum CATFacReplSurfConfigType
{
  CATFacReplSurfStandard,
  CATFacReplSurfIsoTopological
};

//------------------------------------------------------------------------------
// Error diagnosis level for FaceReplaceSurface
//------------------------------------------------------------------------------
enum CATFacReplSurfDiagLevel
{
  CATFacReplSurfNone,           // No diagnostic (standard mode)
  CATFacReplSurfFirstError,     // First cell producing an error is stored, then operator throws an error
  CATFacReplSurfSameFamily,     // All cells producing the first family of error are stored, then operator throws an error
  CATFacReplSurfAllErrors       // All cells producing an error are stored, algorithm tries to get through leaking elements
                                //  then operator throws a final error
};

#endif
