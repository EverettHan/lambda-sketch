//---------------------------------------------------------------------  
//                                                                      
// ADMSI (c) Copyright Dassault Systemes 1995                          
//                                                                      
//---------------------------------------------------------------------
// Responsable : AHC                                                     
//--------------------------------------------------------------------- 
// Source : CATSiList.h                                                  
//--------------------------------------------------------------------- 
// CATSiList :  
//   Classe definissant un type de donnee 'Liste' simplifie          
//--------------------------------------------------------------------- 
// Historique:                                                          
// 95/12/27  Creation                             AHC
// 96/06/06  Modification                         ADH 
//   . Ajout des methodes
//       - Remove
//         => suppression de l'article place a la position n
//       - Reset
//         => vide l'objet liste de tous ses articles
//       - Operateur d'affectation
//       - Constructeur de copie
//       - Constructeur par defaut
//
//   . Mise en confirmite de la nomenclature des identificateurs
//
//   . Correction bug sur la taille de ObjName 
//    (CATObjNameLength -> CATObjNameLength + 1)
//
// 97/01/21 Modfication
//   . Ajout de la methode
//       - ApplyFree
//
// Jun 98   Modification     ADH
//   . Changement de l'implementation des services
//       [ - utilisation d'une donnee membre CATListPV 
//           a la place d'un tableau de void* (void**)
//         - la taille occupee par les donnees membres
//           change - la compatibilite run-time des 
//           cartes d'identite reste assuree : les CIs
//           ne contiennent que des pointeurs sur des objets CATSiList ]
//
//---------------------------------------------------------------------
//
#ifndef CATSiList_H
#define CATSiList_H

//
// --> Parametres de WINDOWS_NT
//

#if defined(__COMPONENTV2)
#define ExportedByCOMPONENTV2 DSYExport
#else
#define ExportedByCOMPONENTV2 DSYImport
#endif
#include "DSYExport.h"

//===================================================================
//                          IMPORTATION
//===================================================================

#include "CATListPV.h"

//===================================================================
//                          EXPORTATION
//===================================================================

class CATSiList ;

//////////////////////////////////////////////
// CONSTANTES
//////////////////////////////////////////////


//
// --> Longueur du nom de la classe d'objets 
//
#define CATObjNameLength 256 


//////////////////////////////////////////////
// CLASSES
//////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATSiList  
{
 //------------------ 
 // PARTIE PUBLIC 
 //------------------ 

 public:

   //------------------------ 
   // Methodes
   //------------------------

   // 
   // --> Constructeur par defaut 
   // 
   CATSiList ( void );
   
   // 
   // --> Constructeur  
   // 
   CATSiList ( char* ipObjName, const int iInitAlloc = 10, const int iExtendAlloc = 20 );

   // 
   // --> Copie Constructeur 
   // 
   CATSiList ( const CATSiList& iList_o );

   // 
   // --> Operateur d'affectation 
   // 
   CATSiList& operator = ( const CATSiList& iList_o );

   // 
   // --> Destructeur 
   // 
   ~CATSiList ( );

   // 
   // --> Ajout d'un objet dans la liste  
   // 
   void Append ( void* ipObject ); 

   // 
   // --> Taille de la liste d'un objet dans la liste  
   // 
   int Size ( void ); 

   // 
   // --> Obtention d'un objet de la liste   
   // 
   void*  GetpObject ( const int iObjPosition = 0 ); 

   //
   // --> Enlevement de l'objet situe a la place iObjPosition
   //
   int Remove ( const int iObjPosition ); 

   //
   // --> Enlevement de tous les objets de l'objet CATSiList
   //
   int Reset ( void );

   //
   // --> Liberation memoire de tous les objets 
   //           (allocation par malloc /calloc -> liberation par free)
   // --> Enlevement de tous les objets
   //
   int ApplyFree ( void );   

 //----------------------------------------------- 
 // PARTIE PRIVATE
 //----------------------------------------------- 

 private:

   //------------------------ 
   // Donnees
   //------------------------

      //=====================
      //     N'EST PLUS UTILISE
      //=====================


     // Taille de la liste allouee 
//   int             _AllocatedSize ;
     // Taille de la rellocation  
//   int             _ExtendedSize  ;
     // Taille de la liste utilisee 
//   int             _UsedSize      ;
   // pointeur sur la liste allouee  
//   void**           _apListObj     ;
     // Nom de la Liste  
   char            _ObjName[CATObjNameLength + 1] ; 


      //=====================
      //     EST REMPLACE PAR
      //=====================

 
      // objet liste de pointeurs void*
    CATRawCollPV      _ListPV;
};

#endif

