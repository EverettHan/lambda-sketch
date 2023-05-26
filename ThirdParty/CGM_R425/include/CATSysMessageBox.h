#ifndef CATSysMessageBox_H
#define CATSysMessageBox_H
// COPYRIGHT DASSAULT SYSTEMES 2001

#include "IUnknown.h"
#include "CATUnicodeString.h"
// valeurs possibles de iFlags

// boutons disponibles
#define CATSysMB_OK            0x00000001
#define CATSysMB_OKCANCEL      0x00000002
#define CATSysMB_YESNO         0x00000004
#define CATSysMB_RETRYCANCEL 0x00000008

// icons 
#define CATSysMB_ICONQUESTION  0x00000010
#define CATSysMB_ICONWARNING   0x00000020
#define CATSysMB_ICONEXCLAM    0x00000040

// to wait even without getting return value
#define CATSysMB_WAIT          0x00000100

#define CATSysMBChoice_OK     1
#define CATSysMBChoice_YES    1
#define CATSysMBChoice_CANCEL 2
#define CATSysMBChoice_NO     2
#define CATSysMBChoice_RETRY  3

// usage interne system
// les autres fw peuvent tirer sur dialog

// ==================================================
// Cree une boite modale avec un message
//  ( avec 1 ou plusieurs boutons)
// METTRE DES MESSAGES NLS SI POSSIBLE ( LES SEULS CAS
// OU CE N EST PAS POSSIBLE DOIVENT ETRE APPROUVES 
// PAR SGT)
// ==================================================
// arguments 
// iBoxTitle      : titre de la boite
// iMessage       : message dans la boite
// iFlags         : utiliser un masque combinant les constante CATSysMBXXXX
//                   ci dessus
// iDefaultChoice : choix automatique a preferer en mode ODT ou BATCH        
//                   ( si utile)
//                   a choisir parmi les constantes CATSysMBChoiceXXXX
// oReturn        : valeur de retour correspondant au bouton clique         
//                  par l utilisateur  (iDefaultChoice en odt ou batch)
//
// ==================================================
HRESULT CATSysMessageBox( const char *iBoxTitle, const char *iMessage, int iFlags=CATSysMB_OK, int iDefaultChoice=CATSysMBChoice_OK,int *oReturn=NULL);

HRESULT CATSysMessageBox( const CATUnicodeString *iBoxTitle, const CATUnicodeString *iMessage, int iFlags=CATSysMB_OK, int iDefaultChoice=CATSysMBChoice_OK, int *oReturn=NULL);


#endif
