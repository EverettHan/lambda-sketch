//* -*-c++-*- */
//---------------------------------------------------------------------
// MCAD/SDS(c) Copyright Dassault Systemes 2004
//---------------------------------------------------------------------
// Responsable: CQK
//---------------------------------------------------------------------
// Source:  CATCkeCommandsMacros.h
//---------------------------------------------------------------------
// 
//  Fichier de macros pour les commandes de CKE
//
//---------------------------------------------------------------------
// Historique:
// Creation     : 04/11/15 CQK
//---------------------------------------------------------------------
#ifndef CATCkeCommandsMacros_H
#define CATCkeCommandsMacros_H

#include "CATNotification.h"


//---------------------------------------------------------------------
//   Declaration d'un evenement
//---------------------------------------------------------------------
#define DEFINE_CKE_NOTIF(name)                                   \
class name: public CATNotification                               \
{                                                                \
public:                                                          \
	CATDeclareClass;                                              \
   name();                                                       \
   virtual ~name();                                              \
};


//---------------------------------------------------------------------
//   Implementation d'un evenement
//---------------------------------------------------------------------
#define DEFINE_CKE_NOTIF_IMPL(name)                              \
CATImplementClass(name,Implementation,CATNotification,CATNull);  \
name::name()                                                     \
{}                                                               \
name::~name()                                                    \
{}

//---------------------------------------------------------------------
//   Ajout/Suppression des Callbacks
//---------------------------------------------------------------------
#define AddCB AddAnalyseNotificationCB
#define RemCB RemoveAnalyseNotificationCB

#endif
