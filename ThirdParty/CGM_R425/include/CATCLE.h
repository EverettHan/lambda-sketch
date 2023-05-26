// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATCLE_H
#define CATCLE_H
///////////////////////////////////////////////////////////////////////////////////
//
// Gestion du server de donnee: la CLE (CATIA LOG FOR EXCHANGE)
//
////////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// Implementation du mecanisme de CLE (CATia Log for Exchange)
// 23/02/97
//
// 10/11/97
// Gestion de l'abonnement aux modifications: migration CATBaseUnknown -> CATCallbackManager
//
////////////////////////////////////////////////////////////////////////////////////
// Gestion de la structure des objects X formats imposes
// on suppose que l'on a au moins autant de formats que de object presents
// on peut n'avoir qu'un seul object et plusieurs formats...
// on peut avoir plusieurs fois le meme object pour des formats imposes differents
////////////////////////////////////////////////////////////////////////////////////

/**
* @level Private 
* @usage U1
*/

#include "CP0CLIP.h"
#include "CATBaseUnknown.h"
#include "CATCallbackManager.h"
#include "CATBaseUnknowns.h"
#include "CATFormats.h"
#include "CATIAV5Level.h"
class CATDocument;

class ExportedByCP0CLIP CATCLE: public CATCallbackManager
{
public:
  CATListPtrCATFormat GetFormats() const;

  // Notifications 
  CATCallbackEvent IsModifiedEvent() const;
  CATCallbackEvent GetEmptyClipEvent() const;    
  void DispatchIsModified(); // simultate a modification and dispatch it
  void DispatchIsEmpty();

};


#endif

