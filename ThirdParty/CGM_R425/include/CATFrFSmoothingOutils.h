//====================================================================
// Copyright Dassault Systemes Provence 2006, all rights reserved 
//====================================================================
//
//
//
//=============================================================================
// 18/04/18 NLD Reception de la SoftwareConfiguration dans
//              CouplingsForASetOfCCVsBis() et DescribeCCVContinuityBis()
// Avril 2006 : exm : Creation (d'apres CATCbgSmoothingOutils)
//=============================================================================

#ifndef CATFrFSmoothingOutils_H
#define CATFrFSmoothingOutils_H

#include "CATFrFSmoothing.h"

#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATFrFCompositeCurve;
class CATFrFCoupling;
class CATFrFCouplingVectors;
class CATFrFNurbsMultiForm;
class CATFrFCCvParam;
class CATMathSetOfPoints;
class CATMathVector;
class CATSoftwareConfiguration;

// fonction utilisee dans le coupling type 2
ExportedByCATFrFSmoothing
void CouplingsForASetOfCCVsBis(CATGeoFactory              *  ifactory            ,
                               CATSoftwareConfiguration   *  iconfig             ,
                               CATLONG32                     inbOfCCVs           ,
                               CATFrFCompositeCurve      **  iCCVs               ,
                               CATLONG32                   & onbOfImposedPoints  ,
                               CATFrFCCvParam            **& oimposedPtsCCVParams,
                               CATFrFCouplingVectors      *& ocouplingVectors    ,
                               CATFrFCoupling             *& ocoupling           );

// anlyser les knoeuds d'une CCvs et enregistrer les infos
// dans le coupling telle que : la bonne continuite, ...
ExportedByCATFrFSmoothing
void DescribeCCVContinuityBis (CATGeoFactory              *  ifactory            ,
                               CATSoftwareConfiguration   *  iconfig             ,
                               CATLONG32                     inbOfCCVs           ,
                               CATFrFCompositeCurve      **  iCCVs               ,
                               CATLONG32                     iNumCCV             ,
                               CATLONG32                     iOpt                ,
                               CATFrFCouplingVectors      *  iocouplingVectors   ,
                               CATFrFCoupling             *  iocoupling          );

// Report du coupling sur toutes les CCVs
ExportedByCATFrFSmoothing
void ReportOnAllCCVsBis(CATLONG32                            inbOfCCVs           ,
                        CATFrFCouplingVectors             *  iocouplingVectors   ,
                        CATFrFCoupling                    *  iocoupling          );

// Fonction pour simplifier les delete

ExportedByCATFrFSmoothing
void DeleteOfCcvsBis     (CATGeoFactory                   *  ifactory            ,
                          CATFrFCompositeCurve            *& ioCCVs              );

ExportedByCATFrFSmoothing
void DeleteOfCcvsParamBis(CATLONG32                          inbOfParams         ,
                          CATFrFCCvParam                 **& ioCcvsParam         );

#endif
