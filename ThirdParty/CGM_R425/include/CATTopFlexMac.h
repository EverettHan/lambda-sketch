/* -*-C++-*- */

#ifndef CATTopFlexMac_H
#define CATTopFlexMac_H

// COPYRIGHT DASSAULT SYSTEMES 2010

//=============================================================================
//=============================================================================
//
// CATTopFlexMac : contient les constantes pour le flexible
//                 ainsi que les definitions de macro
//
//=============================================================================

//=============================================================================
// Mar  2010  Creation                                   PRL
//=============================================================================
//=============================================================================



//------------------------------------------------------------------------------
//
// Definition des macros, pour activation de code "alterne"
//
//   CATFRS_OneBody
//      Pour travailler dans un seul body de travail (reduction des activations
//      pour les liens remontants)
//
//------------------------------------------------------------------------------

#define CATFRS_OneBody


//------------------------------------------------------------------------------
//
// Definition du type de "lien" parametrique entre la surface d'origine et
// sa remplacante.
//
//
//   CATFlxLinkUnknown
//      Pas encore defini
//
//   CATFlxLinkNothing
//      Pas de lien (ex : subdiv)
//
//   CATFlxLinkTransfo
//      La surface remplacante est issue d'une transfo lineaire appliquee a
//      la surface d'origine
//
//   CATFlxLinkSamePar
//      La surface remplacante a le meme parametrage que la surface d'origine
//
//------------------------------------------------------------------------------  

typedef short CATFlxLinkLevel;
#define CATFlxLinkNothing  0
#define CATFlxLinkTransfo  1    
#define CATFlxLinkSamePar  2
#define CATFlxLinkUnknown -1

//------------------------------------------------------------------------------
//
// Definition du type de diagnostic d'erreur
//
//
//   CATFlxDiagNone
//      Pas de diagnostic - mode standard
//
//   CATFlxDiagFirstError
//      La premiere cellule sur laquelle survient l'erreur est stockee, 
//      rendue accessible, puis on lance un Throw comme d'habitude
//
//   CATFlxDiagSameFamily
//      On stocke toutes les erreurs liees a une meme passe algorithmique,
//      puis on lance un Throw comme d'habitude
//
//   CATFlxDiagAllErrors
//      On stocke les erreurs comme dans le cas "CATFlxDiagSameFamily", 
//      et on poursuit le calcul lorsque cela est possible
//  
//
//------------------------------------------------------------------------------  
typedef short CATFlxDiagLevel;
#define CATFlxDiagNone         0
#define CATFlxDiagFirstError   1    
#define CATFlxDiagSameFamily   2   
#define CATFlxDiagAllErrors    3   

//------------------------------------------------------------------------------
//
// Definition du mode de diagnostic d'erreur
//
//
//   CATFlxBodyErrorNone
//      Pas de body attache a l'erreur - mode standard
//
//   CATFlxBodyErrorAutoX
//      On attache un body d'erreur ssi autocheck a trouve une auto-intersection
//
//------------------------------------------------------------------------------  
typedef short CATFlxErrorBody;
#define CATFlxBodyErrorNone    0
#define CATFlxBodyErrorAutoX   1    

//------------------------------------------------------------------------------
//
// Definition du type de transformation associee a une face/une edge
//
//
//   CATFlxTransSpec
//      La T3D est une specification - mode standard
//
//   CATFlxTransInv
//      La face/l'edge a ete ajoutee aux specs utilsateur par invariance
//
//   CATFlxTransAdd
//      Cas des edges : une transfo est associee aux bord libres d'une face
//                      avec T3D, mais ce n'est pas une spec user
//
//------------------------------------------------------------------------------  
typedef short CATFlxTransType;
#define CATFlxTransSpec        0
#define CATFlxTransInv         1    
#define CATFlxTransAdd         2   

//------------------------------------------------------------------------------
//
// Definition du type de gestion des invariants
//
//
//   CATFlxInvarNo
//      On n'ajoute pas les invariants
//
//   CATFlxInvarRestr
//      Ajout restreint
//
//   CATFlxInvarCano
//      Ajout de tous les invariants canoniques
//
//------------------------------------------------------------------------------  
typedef short CATFlxInvarMode;
#define CATFlxInvarNo          0
#define CATFlxInvarRestr       1
#define CATFlxInvarCano        2   

//------------------------------------------------------------------------------
//
// Definition du type de gestion du run local de FlexiblePlusImp
//
//
//   CATFlxLR_NotRun
//      Operateur non encore lance
//
//   CATFlxLR_OK
//      Le run local est correct
//
//   CATFlxLR_AutoX
//      Le run local donne un body resultat en auto-intersection
//
//   CATFlxLR_KO_NoInv
//      Le run local est KO avant d'arriver a l'auto-check et 
//      il n'y a pas de faces invariantes candidates
//
//   CATFlxLR_KO_Inv
//      Le run local est KO avant d'arriver a l'auto-check et 
//      il y a des faces invariantes candidates
//
//------------------------------------------------------------------------------  
typedef short CATFlxLocalResult;
#define CATFlxLR_NotRun     -1
#define CATFlxLR_OK          0
#define CATFlxLR_AutoX       1
#define CATFlxLR_KO_NoInv    2   
#define CATFlxLR_KO_Inv      3

//------------------------------------------------------------------------------
//
// Definition du type de listes d'edges associee a une T3D
//
//
//   CATFlxEdgLst_Unk
//      Type indefini
//
//   CATFlxEdgLst_Non
//      Pas d'aretes
//
//   CATFlxEdgLst_Sol
//      Aretes donnees a l'unite
//
//   CATFlxEdgLst_Lst
//      Aretes donnees par liste - entrees non encore traitees
//
//   CATFlxEdgLst_Mix
//      Aretes donnees par liste et a l'unite - mode mixte
//
//   CATFlxEdgLst_Flt
//      Aretes donnees par liste - mais mise a plat
//
//   CATFlxEdgLst_Cnx
//      Aretes donnees par liste - connexite verifiee (evt, creation de nelles listes par split)
//
//   CATFlxEdgLst_Lim
//      Aretes donnees par liste - cas non traite (limitation) - temporaire?
//
//
//------------------------------------------------------------------------------  
typedef short CATFlxEdgLstType;
#define CATFlxEdgLst_Unk        -1
#define CATFlxEdgLst_Non         0
#define CATFlxEdgLst_Sol         1
#define CATFlxEdgLst_Lst         2
#define CATFlxEdgLst_Mix         3
#define CATFlxEdgLst_Flt         4
#define CATFlxEdgLst_Cnx         5
#define CATFlxEdgLst_Lim         6


#endif
// Ne rien ecrire sous cette ligne
//==============================================================================
