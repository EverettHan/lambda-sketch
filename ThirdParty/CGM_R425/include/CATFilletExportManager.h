#ifndef CATFilletExportManager_H
#define CATFilletExportManager_H

//=============================================================================
// Copyright Dassault Systemes Provence 2011-2015, all rights reserved
//=============================================================================
//
// CATFilletExportManager: virtual class for plugging a specific surface into fillet
//
//=============================================================================
// Usage notes: fillet customization
//=============================================================================
// 10/03/2015 : HLN ; Add CATCGMProgressBar + Interruption management
// 21/04/2011 : RR  : Creation
//=============================================================================
#include "Fillet.h"
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATTopData;
class CATShell;
class CATFace;
class CATEdge;
class CATBody;
class CATCrvParam;
class CATConnectPiece;
class CATFilletExportPiece;
class CATCGMProgressBar;

#include "ListPOfCATFace.h"
#include "CATFrFImproveFilletSurfaces.h"
#include "CATTopDefine.h"

class ExportedByFillet CATFilletExportManager
{
  public:

  virtual void SetInitialSkinBlend(CATShell *iSkinBlendInit, CATBody *iBodyBlendInit = NULL) = 0;

  virtual void SetConnectionData(int iDirection, CATFace *iConnectionFace,
                                 CATEdge *iConnectionEdge, CATConnectPiece *iConnectionConnectPieces = NULL) = 0;

  virtual void Run() = 0;

  virtual ~CATFilletExportManager();
   
  virtual void CreateFilletExportPiece(CATConnectPiece *iConnectPiece, 
                                       ListPOfCATFace  &iSupportFaces1,
                                       CATCrvParam     &iExportStaParOnGuide1,
                                       CATCrvParam     &iExportEndParOnGuide1,
                                       int              iIndSupp1,
                                       ListPOfCATFace  &iSupportFaces2,
                                       CATCrvParam     &iExportStaParOnGuide2,
                                       CATCrvParam     &iExportEndParOnGuide2,
                                       int              iIndSupp2,
                                       CATOrientation  *iCommonTrackOrientation = NULL) = 0;

  virtual CATFrFImproveFilletSurfacesCreate GetImproveFct() = 0;

  virtual void SetParentProgressBar(CATCGMProgressBar *iParentProgressBar) = 0;

  virtual void SetParentProgressBar(CATCGMProgressBar *iParentProgressBar, 
                                    const double iStartPercentage, const double iEndPercentage) = 0;
};

// iFilletExportPieces: donnees pour le calcul du ruban G2 correspondant à un unique ruban, les elements de la liste sont ordonnés
typedef CATFilletExportManager* (*CATFilletExportManagerCreate) (CATGeoFactory *iFactory, CATSoftwareConfiguration *iSoftwareConfiguration);    

#endif
