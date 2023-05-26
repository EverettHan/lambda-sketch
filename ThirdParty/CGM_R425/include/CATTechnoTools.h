/**
 * @level Private
 * @usage U1
 */
#ifndef CATTechnoTools_H
#define CATTechnoTools_H

// COPYRIGHT DASSAULT SYSTEMES   1998
//=============================================================================
//
// Somes services for TechnoLinks parsing
//
//=============================================================================
// Usage Notes:
//
// 
//=============================================================================
// Sept. 98   Creation           RCI
// Jan.  99   Modification       OST                   
//=============================================================================

#include "TECHNLNK.h"

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATITechnoLinkable.h"

// --------------------------------------------------------------------------
// Service permettant de recuperer l'IID de l'interface
// correspondant a un nom de protocole
// --------------------------------------------------------------------------
HRESULT GetIidFromProt(const CATUnicodeString&       iprot,
		    IID&                    iid);

// --------------------------------------------------------------------------------
//   Service permettant d exploser un nom compose de lien technologique
//   si prot:A!B!C!prot2:C!D!   
//      A -> SplitName(B!C!prot2:C!D!) donnera Name = B, End = C!prot2:C!D!
//   si le lien ne commence pas par un nom, Name est vide et End vaut PathName
// --------------------------------------------------------------------------------
ExportedByTECHNLNK
void SplitName(const CATUnicodeString&         PathName,
	       CATUnicodeString&              Name,
	       CATUnicodeString&              End);

// -----------------------------------------------------------------------------------
//   Service permettant d extraire le protocole d un chemin recupere par SplitName
//   si prot:B
//      A -> SplitProt(prot:B!) donnera Protocol = prot, End = B!
// -----------------------------------------------------------------------------------
ExportedByTECHNLNK
void SplitProt(const CATUnicodeString&         PathName,
	       CATUnicodeString&               Protocl,
	       CATUnicodeString&              End);


#endif
