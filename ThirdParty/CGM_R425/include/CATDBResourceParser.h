#ifndef _CATDBResourceParser_H
#define _CATDBResourceParser_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "DI0BUILD.h"
#include "CATDlgUtility.h"
#include <stdio.h>
#include <stdlib.h>

class CATString;
class CATDialog;
class CATDBDialog;
class CATDBDialogList;
class CATHashTabCATDBDialogList;
class CATHashTabCATKeyedDialog;

class ExportedByDI0BUILD CATDBResourceParser
{
  public :

  CATDBResourceParser();
  ~CATDBResourceParser();

  // load Dialog resources from a file
  int LoadDialogResources ( const CATString &name, char *path = NULL );

  CATDBDialog *GetDBDialog ();

  // get error in file : returns error line number.
  int GetError ( CATString &oError );
  
  // positionnement du mode de foonctionnement du parser
  enum CATDBParserMode 
    { RuntimeMode, BuildtimeMode };
  
  void SetMode ( CATDBResourceParser::CATDBParserMode iMode = BuildtimeMode );


  private :

  CATString _name; // nom du parser
  CATDBParserMode _mode; // mode de fonctionnement du parser : par defaut, positionnement des ressources NLS
                         // dans les objects CATDBDialog
  
  CATDBDialog *_DBObject;
  CATHashTabCATDBDialogList *_tableList;
  int _tableAlloc;
  CATDBDialogList *_parentList;

  int _currentType;
  char *_currentScan;
  char _currentError[256];
  char *_resources;
  int _resourceSize;
  int _lineNumber;

  void Clean();
  int isResizable ( int type );
  int CleanWhitesAndComments ();
  int ExpectDialogName ();
  int ExpectDialogType ();
  int ExpectOpenBrace ();
  int ExpectClosingBrace();
  int ExpectSemiColumn ();
  int ExpectComa();
  int ExpectResourceKeyword ( );
  int ExpectEqual ();
  int ExpectValue ( int *value );
  int ExpectValue ( float *value );
  CATDlgStyle ExpectStyle ();
  unsigned int ExpectJustification();
  int ExpectString( char * );
  int ExpectFormat( char * );
  int CreateDBObjectsTree ( CATDBDialog *father, char *path );
  void GetNLSResources ( CATDBDialog *elt, char *path );
};

#endif
