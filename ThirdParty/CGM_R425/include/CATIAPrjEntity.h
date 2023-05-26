/* CATIAPrjEntity.h : COPYRIGHT DASSAULT SYSTEMES 1998 */
/**
* @level Protected
* @usage U1
*/
#ifndef CATIAPrjEntity_h
#define CATIAPrjEntity_h
#include "CATIAV5Level.h"
#include "CATBaseUnknown.h"

#ifdef	__CATIAPrjEntity
#define	ExportedByCATIAPrjEntity DSYExport
#else
#define	ExportedByCATIAPrjEntity DSYImport
#endif



class CATTrace;
class CATIAProject;
class CATUnicodeString;
class CATIAProjectTable;

class ExportedByCATIAPrjEntity CATIAPrjEntity : public CATBaseUnknown
{
public:
  //------------------------------------------------------------
  // Constructeurs
  //------------------------------------------------------------
  CATIAPrjEntity();
  CATIAPrjEntity(const CATUnicodeString iPathName);
  CATIAPrjEntity(const CATIAPrjEntity& iPrjEntityToCopy);

  //------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------
  ~CATIAPrjEntity();

  //------------------------------------------------------------
  // Methodes
  //------------------------------------------------------------
  /*----------------------------------------------------------------*/
  /* Pour le chargement en memoire d'une Table du PRJ               */
  /*----------------------------------------------------------------*/
  const CATIAProject* ReadPrjTable(const int iIndexTab);
  const CATIAProject* ReadPrjTable(const char* iTableName);

  /*----------------------------------------------------------------*/
  /* Pour le chargement en memoire de plusieurs Tables du PRJ       */
  /*----------------------------------------------------------------*/
  const CATIAProject* ReadPrjTables();
  const CATIAProject* ReadPrjTables(const unsigned short iMaskTab);
  const CATIAProject* ReadPrjTables(const char** iTableNames, const int iNbTab);

  /*----------------------------------------------------------------*/
  /* Pour recuperer le CATIAProject associe au CATIAPrjEntity       */
  /*----------------------------------------------------------------*/
  const CATIAProject* GetProject();

  /*----------------------------------------------------------------*/
  /* Pour la manipulation du soft de base relatif a un PRJ en cours */
  /*----------------------------------------------------------------*/
  void SetCurrent();                     // Mise en cours du PRJ associe
  static void SetNoCurrent();            // Mise a NULL du PRJ en cours
  static CATIAPrjEntity* GetCurrent();  // Recuperation du PRJ associe en cours

  //------------------------------------------------------------
  // Operateur
  //------------------------------------------------------------
  CATIAPrjEntity& operator = (const CATIAPrjEntity& iPrjEntityToCopy);

  //------------------------------------------------------------
  // Definition de tableaux pour faciliter la vie
  //------------------------------------------------------------
  //
  // Definition des noms des Tables de PRJ
  static const char* PrjTableNames[];

  //
  // Definition du tableau des masks
  static const unsigned short PrjTableMasks[];

private:
  //------------------------------------------------------------
  // Methodes private
  //------------------------------------------------------------
  /*----------------------------------------------------------------*/
  /* Soft generique Pour le chargement d'une Table du PRJ           */
  /*----------------------------------------------------------------*/
  void    InitPrjtTables();
  int     ReadATable(const int iIndexTab);

  char** GetBufferAddress(const int iIndex) const;

  //------------------------------------------------------------
  // CATIAPrjEntity courant
  //------------------------------------------------------------
  static CATIAPrjEntity* _CurPrjEntity;

  //------------------------------------------------------------
  // Donnees membres
  //------------------------------------------------------------
  CATIAProject* _PRJInstance;

  //
  // Definition des noms de fichiers sur disques
  static const char* PrjTableFileNames[][3];

  //
  // Definition des noms de classes
  static const char* PrjTableClassNames[];

  //
  // Pour faciliter la manipulation des donnees.
  static CATIAProjectTable* _PrjTablesDef[];
};


#endif





