//#define CATCGMDebugSwitchNLD_ForceShuntOldPerfo "POUR TEST SANS HashTable"

// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
//CATExtruderUtilities:
// Utilities for topology extruder 
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
//
//
//=============================================================================
// 15 01 99 NLD Creation
// 03 04 03 NLD Argument supplementaire dans StoreGeomSpec() pour mode hybride
// 18 10 10 NLD Ajout classe CATExtruderGeomSpecManager pour encapsulation des données
//              de gestion et switch perfos
//              Apres migration de tous les appelants, les methodes statiques originelles
//              StoreGeomSpec() et NumSpecCrvInGeom() ne sont plus accessibles depuis l'exterieur
//=============================================================================
#ifndef CATExtruderUtilities_H
#define CATExtruderUtilities_H

#include <CATCGMDebugSwitchNLD.h> // A faire avant toutes choses
#ifndef CATCGMDebugSwitchNLD_ForceShuntOldPerfo
#define CATExtruderUtilities_UseHashTable "Ok NLD191010 a priori pas d'occurence multiple"
#endif

// Module definition for Windows
// -----------------------------
#include <FrFTopologicalOpe.h>
//

// For interface and Data
// ----------------------
class CATEdgeCurve ;
class CATCurve ;
#include <CATListOfCATEdgeCurves.h>
#include <CATListOfCATCurves.h>
#include <CATMathDef.h>                       // Pour typedef CATBoolean
#ifndef NULL
#define NULL 0
#endif

#ifdef CATExtruderUtilities_UseHashTable

// New implementation with hashtable
#include <CATCGMHashTable.h>
class CATExtruderUtilities_HashTableWithSize
  {
   private:
   int             _Size;
   CATCGMHashTable _Table;
   public:
   CATExtruderUtilities_HashTableWithSize();
   int  Size();
   void RemoveAll();
   void* operator[] (int iPos);
   void Append(void* iGeom);
   int  Locate(void* iGeom);

  };
#define CATExtruderUtilities_ListOfCATCurve           CATExtruderUtilities_HashTableWithSize
#define CATExtruderUtilities_ListOfCATEdgeCurve       CATExtruderUtilities_HashTableWithSize

#else

// Old implementation with list
#define CATExtruderUtilities_ListOfCATCurve           CATLISTP(CATCurve)
#define CATExtruderUtilities_ListOfCATEdgeCurve       CATLISTP(CATEdgeCurve)

#endif
#define CATExtruderUtilities_AlwaysListOfCATCurve     CATLISTP(CATCurve)

class CATExtruderGeomSpecManager
  {
   private:
   CATExtruderUtilities_ListOfCATCurve     _Geom;      // Courbes stockées dans la geometrie
   CATExtruderUtilities_ListOfCATEdgeCurve _Specs;     // Liste des edge curves spécifiées par la topologie
   // Les representations geometriques, qui peuvent etre identiques pour plusieurs specifications,
   // sont representees par des listes; a la difference des autres donnees sur lesquelles il n'y a
   // pas de doublon possible; (necessaire pour Sweep100 Case1003 par exemple; NLD181010)
   CATExtruderUtilities_AlwaysListOfCATCurve _SpecReps;  // Représentations géométriques de ces edge curves

   public:
   CATExtruderGeomSpecManager();
   //-----------------------------------------------------------------------------
   // Stockage de geometries de specification
   // On stocke une liste de geometries dans une liste preexistante
   // de geometries, (sans stockage des doubles), et avec stockage
   // des representations geometriques dans une liste parallele
   // Si iHybridMode==1, on va stocker les MergedCurves et non les courbes sous-jacentes
   //-----------------------------------------------------------------------------
   void StoreGeomSpec       (const CATLISTP(CATEdgeCurve)& iSpecToStore,
                                   int                     iHybridMode=0);

   //-----------------------------------------------------------------------------
   // donne le numero d'une courbe specification dans la geometrie
   // Recherche la representation geometrique de iSpecCrv dans iAllGeomCrvs
   // etant donnees les correspondances courbe/representation 
   // donnees par les tableaux iAllSpecCrvs/iAllSpecCrvReps
   // LEVE UNE EXCEPTION EN CAS D'ECHEC
   //-----------------------------------------------------------------------------
   int NumSpecCrvInGeom     (const CATCurve*               iSpecCrv);

   // Accès aux geometries
   int       GetNumberOfGeom();
   CATCurve* GetGeom        (      int                     Num);
   void      AppendGeom     (      CATCurve*               iCurve);
   void      RemoveAllGeom  ();

   // Accès aux spécifications
   int GetNumberOfSpec      ();
   // rend la position d'une specification (0 si non trouvée)
   int PosSpec              (      CATEdgeCurve*           iSpec);
   void GetSpec             (      int                     iNumSpec,
                                   CATEdgeCurve*&          oSpec,
                                   CATCurve    *&          oSpecRep);
   //
   void RemoveAll();
  };
#endif
