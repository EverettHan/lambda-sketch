#ifndef SweepSetSoftwareConfiguration_H
#define SweepSetSoftwareConfiguration_H

// COPYRIGHT DASSAULT SYSTEMES 2002

//-----------------------------------------------------------------------------
//-- debut SweepSetSoftwareConfiguration.h: deploiement controlé de SoftwareConfiguration
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// NLD 24 04 02 Creation
// NLD 10 09 03 Ajout SweepSetSoftwareConfigurationV4
// NLD 02 03 07 Ajout SweepSetSoftwareConfigurationV5 et SweepSetSoftwareConfigurationV6
// NLD 28 01 09 Ajout GetControlledSoftwareConfiguration()
//----------------------------------------------------------------------------
// Macros de passage de configuration a un objet avec controle
// de niveau minimal dans cette configuration elle-meme
// Cette macro permet de mettre en place le passage de configuration, 
// avant le deploiement centralise dans la macro elle-meme
// par une variable de versionning
//----------------------------------------------------------------------------
// Exemple d'utilisation
//----------------------------------------------------------------------------
// !---------------------------------------------------------------------------
// ! CATFrFMovingFrame* MF=CreateMovingFrame()
// ! CATSoftwareConfiguration* Config* =  ... ;
// ! SweepSetSoftwareConfigurationV1 (MF, Config)
// !---------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Attention
// lorsque j'aurais active la variable CGM_Versionning_Sweep_DeploySoftwareConfigurationV1
// plus aucun nouvel appel a SweepSetSoftwareConfigurationV1 ne sera possible,
// il faudra appeler SweepSetSoftwareConfigurationV2 (meme syntaxe)
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Prerequis 
//----------------------------------------------------------------------------
#include <CATSoftwareConfiguration.h>
#include <CATCGMVersionningDef110.h>
#include <CATCGMModif.h>
//----------------------------------------------------------------------------
inline CATSoftwareConfiguration* GetControlledSoftwareConfiguration(CATSoftwareConfiguration* iConfig,
                                                                    int                       iCGMVersionningLevelForDeploying)
{
 CATSoftwareConfiguration* Result = NULL ;
 if (iConfig)
   {
    int CGMLevel = GetCGMLevel(iConfig, "") ;
    if (CGMLevel >= iCGMVersionningLevelForDeploying)
       Result = iConfig ;
   }
 return Result ;
}
//----------------------------------------------------------------------------
// Passage de la SoftwareConfiguration a un objet quelconque disposant
// d'une methode SetSoftwareConfiguration
// SweepSetSoftwareConfigurationV1(Object, Config)
//----------------------------------------------------------------------------
#define SweepSetSoftwareConfigurationV1(Object, Config)                            \
 {if (Object && Config)                                                            \
   {CATLONG32 CGMLevel = ::GetCGMLevel(Config, "SweepSetSoftwareConfiguration") ;  \
    CATLONG32 ExpectedLevel = CGM_Versionning_Sweep_DeploySoftwareConfigurationV1 ;\
    if (CGMLevel >= ExpectedLevel)                                                 \
      Object->SetSoftwareConfiguration(Config);}}                                  //

#define SweepSetSoftwareConfigurationV2(Object, Config)\
 {if (Object && Config)                                                            \
   {CATLONG32 CGMLevel = ::GetCGMLevel(Config, "SweepSetSoftwareConfiguration") ;  \
    CATLONG32 ExpectedLevel = CGM_Versionning_Sweep_DeploySoftwareConfigurationV2 ;\
    if (CGMLevel >= ExpectedLevel)                                                 \
      Object->SetSoftwareConfiguration(Config);}}                                  //

#define SweepSetSoftwareConfigurationV3(Object, Config)\
 {if (Object && Config)                                                            \
   {CATLONG32 CGMLevel = ::GetCGMLevel(Config, "SweepSetSoftwareConfiguration") ;  \
    CATLONG32 ExpectedLevel = CGM_Versionning_Sweep_DeploySoftwareConfigurationV3 ;\
    if (CGMLevel >= ExpectedLevel)                                                 \
      Object->SetSoftwareConfiguration(Config);}}                                  //

#define SweepSetSoftwareConfigurationV4(Object, Config)\
 {if (Object && Config)                                                            \
   {CATLONG32 CGMLevel = ::GetCGMLevel(Config, "SweepSetSoftwareConfiguration") ;  \
    CATLONG32 ExpectedLevel = CGM_Versionning_Sweep_DeploySoftwareConfigurationV4 ;\
    if (CGMLevel >= ExpectedLevel)                                                 \
      Object->SetSoftwareConfiguration(Config);}}                                  //

#define SweepSetSoftwareConfigurationV5(Object, Config)\
 {if (Object && Config)                                                            \
   {CATLONG32 CGMLevel = ::GetCGMLevel(Config, "SweepSetSoftwareConfiguration") ;  \
    CATLONG32 ExpectedLevel = CGM_Versionning_Sweep_DeploySoftwareConfigurationV5 ;\
    if (CGMLevel >= ExpectedLevel)                                                 \
      Object->SetSoftwareConfiguration(Config);}}                                  //

#define SweepSetSoftwareConfigurationV6(Object, Config)\
 {if (Object && Config)                                                            \
   {CATLONG32 CGMLevel = ::GetCGMLevel(Config, "SweepSetSoftwareConfiguration") ;  \
    CATLONG32 ExpectedLevel = CGM_Versionning_Sweep_DeploySoftwareConfigurationV6 ;\
    if (CGMLevel >= ExpectedLevel)                                                 \
      Object->SetSoftwareConfiguration(Config);}}                                  //

//----------------------------------------------------------------------------
//-- fin SweepSetSoftwareConfiguration.h: deploiement controlé de SoftwareConfiguration
//-----------------------------------------------------------------------------
#endif





