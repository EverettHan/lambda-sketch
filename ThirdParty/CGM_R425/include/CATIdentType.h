#ifndef CATIdentType_H
#define CATIdentType_H

// COPYRIGHT DASSAULT SYSTEMES 2005

#define NbIdentType   13
#define NB_IDENT_TYPE 13

enum CATIdentType
{
  CATFaceIdent,
  CATBoundaryEdgeIdent,
  CATInternalSharpeEdgeIdent,
  CATInternalSmoothEdgeIdent,
  CATBoundaryPointIdent,
  CATInternalSharpePointIdent,
  CATInternalSmoothPointIdent,
  CATSurfacicPointIdent,
  CATFreePointIdent,
  CATWireEdgeIdent,
  CATInfiniteFaceIdent,
  CATVisVolumeIdent,
  CATIsoIdent,
  CATIdentTypeUnknown
};

#endif
