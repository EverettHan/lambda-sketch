#ifndef CATFilletExportPiece_H
#define CATFilletExportPiece_H

//=============================================================================
// Copyright Dassault Systemes Provence 2010, all rights reserved
//=============================================================================
//
// CATFilletExportPiece: virtual class for plugging a specific surface into fillet
//
//=============================================================================
// Usage notes: fillet customization
//=============================================================================

#include "Fillet.h"
class CATConnectPiece;
class CATCrvParam;
#include "ListPOfCATFace.h"

class ExportedByFillet CATFilletExportPiece
{
public:

  virtual void GetConnectPiece(CATConnectPiece *&oConnectPiece) = 0;

  virtual void GetSupportFaces(ListPOfCATFace &oSupportFaces1, ListPOfCATFace &oSupportFaces2) = 0;

  virtual void GetLimitsForExport(CATCrvParam &oStaParOnGuide1, CATCrvParam &oEndParOnGuide1, int &oIndSupport1, 
                                  CATCrvParam &oStaParOnGuide2, CATCrvParam &oEndParOnGuide2, int &oIndSupport2) = 0;

  virtual ~CATFilletExportPiece();

};

#endif

