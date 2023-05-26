/**
* @level Private 
* @usage U1
*/
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//								   
// CATV4CSStructDefinition.h :
//  Definition des structures pour la definition des tableaux de
//  correspondance pour les fichiers de description et les code sets V4.
//
//=============================================================================
//
// Considerations of usage:								   
//								   
//=============================================================================
//								   
// September 1998                                                  Creation LJH
//								   
//=============================================================================
#ifndef CATV4CSStructDefinition_H
#define CATV4CSStructDefinition_H

//
// Includes
#ifdef _WINDOWS_SOURCE
#include <windows.h>
#else
#define LPCTSTR const char *
#endif


struct CATV4CSFileDefStruct
{
  char * _CSFileName;
  int    _CSFileType;
  int    _CSFileBase;
};


struct CATV4CSDefinitionStruct
{
  char          * _CSName;
  int             _CSType;
  int             _CSBase;
  int             _CSSBCS;
  char          * _CSFile;
};


struct CATV5CSDefinitionStruct
{
  LPCTSTR _CSName;
  int     _CSV4Num;
  int     _CSType;
  int     _CSLang;
  int     _CSKeepKATAKANA;
};


struct CATV4CSTransTableStruct
{
  unsigned short * _V4CSTransTable;
  int              _V4CSTransTableSize;
  unsigned char  * _V4CSTransTableInvers;
  int              _V4CSTransTableInversSize;
  char *           _V4CSTransTableFileName;
  char *           _V4CSTransTableFileNameSecond; // the SBCS table name
};

#endif
