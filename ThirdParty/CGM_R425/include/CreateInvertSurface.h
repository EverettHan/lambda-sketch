#ifndef CreateInvertSurface_h
#define CreateInvertSurface_h

// 12/04/05 pkc Creation
// 30/01/12 NLD Merci de ne pas venir saloper FreeFormOperators, dont TOUS les Remove() sauf celui-ci, soit 46 sur 47,
//              fonctionnent avec des conventions, qui plus est des conventions intelligentes:
//              Les pointeurs sont passes a Remove() par adresse pour faciliter le travail de l'appelant
//              D'ou correction de la signature

#include "FrFAdvancedOpeSur.h"
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATSurface;
class CATInvertSurface;
class CATSurLimits;

//-----------------------------------------------------------------------------
ExportedByFrFAdvancedOpeSur CATInvertSurface * CreateInvertSurface(CATGeoFactory* iFactory, 
                                                                   CATSoftwareConfiguration* iConfig, 
                                                                   CATSurface* iSurfaceToInvert,
                                                                   CATSurLimits &iLimits);

//-----------------------------------------------------------------------------
ExportedByFrFAdvancedOpeSur void Remove(CATInvertSurface *& ioOp);
#endif



