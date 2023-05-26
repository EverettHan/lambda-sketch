// COPYRIGHT DASSAULT SYSTEMES 2003
//==========================================================================
//
// CATFrFObjectVirtual:
// "Mother" virtual Class for FreeFormOperators 
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// 10/10/03 JSX Creation de CATFrFObjectVirtual
//   /07/06 CPT migration sur CATCGMVirtualDeclareClass
// 25/07/06 NLD Tentative de debug des objets non effaces par generation de code77
//              en utilisant CATCGMNewArray. Pas actif
//              Ajout Init()
// 04/08/06 NLD Ajout de _DebugKeepDummyObject
//              Ajout de _Count
// 06/12/06 jsx Ajout _Factory et SetFactory() et acces aux tolerances
//              de _Factory via CATFrFTolerance
// 27/02/07 NLD Ajout de GetFactory() 
//              pour securisation des acces aux factorys non initialisees
//              et passage de _Factory en private
// 27/02/07 NLD Separation en CATFrFObjectVirtual et CATFrFObject
//              pour permettre de deriver seulement de CATFrFObjectVirtual
//              avec mecanismes de debug des references, sans
//              gestion des donnees de CATFrFObject (configuration, factory)
//              et pour bien distinguer un vrai objet d'un objet virtuel
//              ### Ensuite il faudra forcer le passage par un constructeur
//              ### explicite avec configuration
// 21/03/07 NLD Ajout ForceDebugCode77OnFrFVirtualObject()
// 02/10/20 NLD Suppression extern "C" inutile
//==========================================================================
//
#ifndef CATFrFObjectVirtual_H
#define CATFrFObjectVirtual_H
//
#include "FrFObjects.h"
#include "CATCGMVirtual.h"
#include "CATDataType.h"

// pour generer du code77 si objet non detruit (debug aise des MLKs)
// mais pour activer en officiel sans MLK je me demande si tout l'arbre de derivation ne 
// doit pas utiliser aussi CATCGMNewClassArray
// voir aussi la compatibilite avec CATCGMVirtualDeclareClass
//#define TestNLDCATFrFObjectVirtualUnderNewClassArray 
#ifdef TestNLDCATFrFObjectVirtualUnderNewClassArray
#include <CATCGMNewArray.h>
#endif


//--------------------------------------------------------------------------------
// (Debug purpose only)
// Force l'activation ou la desactivation du debug des CATFrFVirtualObject par des codes 77
//--------------------------------------------------------------------------------
// Non necessaire ici NLD021020 extern "C"
ExportedByFrFObjects void ForceDebugCode77OnFrFVirtualObject(int iActive=1) ;


class ExportedByFrFObjects CATFrFObjectVirtual : public CATCGMVirtual

  {
//#ifndef TestNLDCATFrFObjectVirtualUnderNewClassArray
  CATCGMVirtualDeclareClass(CATFrFObjectVirtual);
//#endif
   public :
      CATFrFObjectVirtual() ;
    virtual ~CATFrFObjectVirtual();


#ifdef TestNLDCATFrFObjectVirtualUnderNewClassArray
CATCGMNewClassArrayDeclare;
#endif

  protected : 
    int  _DebugKeepDummyObject;
    int _Count;

  private:

  public :
  };
#endif

