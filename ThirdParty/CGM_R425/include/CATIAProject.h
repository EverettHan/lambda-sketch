/**
 * @level Protected
 * @usage U2
 */
//* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1998
//-----------------------------------------------------------------------------
//
// class CATIAProject
//
//-----------------------------------------------------------------------------
// Usage Notes:
//   
//   This class has been created to represent a CATIA V4 Project file and
//   to give access to the different tables of the Project File.
//
//   Notice : A Project File is in fact a directory which contains the files 
//            of the tables of the Project.
//
//-----------------------------------------------------------------------------
// Creation by CCN - November  1997
// Upgrade  by LJH - September 1998
//-----------------------------------------------------------------------------

#ifndef CATIAProject_H
#define CATIAProject_H

#include "ExportedByCATIAEntity.h"

#include "CATIAProjectTable.h"
#include "CATIAProjectCommon.h"


class CATTrace;

class ExportedByCATIAEntity CATIAProject 
{
public :
  //------------------------------------------------------------
  // Constructeurs
  //------------------------------------------------------------
  // Permet de creer une instance de CATIAProject.
  // Cependant, ne permet pas d'exploiter les donnees du PRJ.
  // Tout les variables sont initialisees a NULL.
  CATIAProject();

  // Initialise le chemin d'acces au PRJ.
  CATIAProject( const char * iPathName );

  // Constructeur par copie : permet de creer facilement une instance
  // de CATIAProject a partir d'un PRJ existant deja initialise.
  // En particulier, il permet de travailler en securite sur un PRJ
  // sans modifier le PRJ d'origine.
  CATIAProject( const CATIAProject & iPrjToCopy );

  //------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------
  ~CATIAProject();

  //------------------------------------------------------------
  // Methodes de Gestion du PRJ courant
  //------------------------------------------------------------
  // Obtention d'un pointeur sur le PRJ en cours.
  static CATIAProject * GetCurrent();

  // Aucun PRJ en cours
  static void SetNoCurrent();

  // Mise en cours du PRJ
  void SetCurrent();

  //------------------------------------------------------------
  // Methodes de Gestion de la liste de CATIAProject
  //------------------------------------------------------------
  // Ajoute d'un PRJ dans la liste
  // ATTENTION ! Cette methode fait un AddRef.
  // Il faut utiliser IsExist (cf. ci-dessous) AVANT.
  // Car cette methode ne fonctionne que si le PRJ n'existait pas deja
  // dans la liste.
  void AddPrjToList();

  // Supprime d'un PRJ dans la liste
  // ATTENTION ! Cette methode ne fonctionne que s'il n'y a plus
  // qu'une seule reference sur l'objet.
  // Retourne : 1 si c'est OK, 0 sinon.
  int RemovePrjFromList();

  // Ajoute d'une reference sur un PRJ
  void AddRef();

  // Supprime une reference sur un PRJ et detruit l'objet s'il n'est plus reference.
  void Release();

  // Verification de l'existence dans la liste d'un PRJ
  // par son chemin d'acces aux tables.
  // Retourne l'adresse du CATIAProject si le PRJ existait deja dans la liste
  // NULL sinon.
  static CATIAProject * IsExist( const char * iPathName );

  //------------------------------------------------------------
  // Operateurs
  //------------------------------------------------------------
  // Operateur d'affectation : permet de copier facilement
  // les donnees d'un PRJ existant deja initialise.
  // En particulier, il permet de travailler en securite sur un PRJ
  // sans modifier le PRJ d'origine.
  CATIAProject& operator = ( const CATIAProject & iPrjToCopy );

  //------------------------------------------------------------
  // Methodes de gestion de la table d'attributs
  //------------------------------------------------------------
  typedef unsigned char ident17[ 17 ];
  typedef unsigned char ident71[ 71 ];

  int GetNbrAttributes( int *& inbatt );
  int GetIdAttributes( int & itypatt, int & size, ident17 *& listeId );
  int GetDiscreteValues( ident17 idatt, int & size, ident71 *& listeVal );

  //------------------------------------------------------------
  // Variables contenant les informations sur le PRJ
  //
  // - En public pour optimiser et faciliter les acces au PRJ -
  // - ATTENTION !! NE PAS EN ABUSER ! En particulier NE PAS  -
  // - MODIFIER DES DONNEES sans etre sur du resultat         -
  //------------------------------------------------------------
  char * _pathname; // Repertoire associe au fichier PRJ

  CATIAProjectTable _tabatt; 
  CATIAProjectTable _tabcla;
  CATIAProjectTable _tabtcdes;
  CATIAProjectTable _tabtcstd;
  CATIAProjectTable _tabpatdes;
  CATIAProjectTable _tabpatid;
  CATIAProjectTable _tabpatmot;

private:
  //
  // Methodes pour faciliter la manipulation des donnees
  //
  void ResetTables();
  void CopyAllTables( const CATIAProject & iPrjSrc );

  //
  // Pour la gestion de la liste des fichiers Projet
  // Liste doublement chainee.
  // L'origine definit le debut et la fin de la liste.
  //
  int _refcount; // Nombre de references sur le PRJ

  CATIAProject * _PrevProject;
  CATIAProject * _NextProject;
  
  static CATIAProject * _OriginProject;  // Pointeur sur le debut de la liste des CATIAProject
  static CATIAProject * _currentPrj;     // Pointeur sur le PRJ courant

  //
  // Pour les traces
  //
  static CATTrace * TraceInstance;
};

#endif
