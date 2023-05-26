/**
 * @level Protected
 * @usage U2
 */
//* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1998
//-----------------------------------------------------------------------------
//
// class CATIAProjectTable
//
//-----------------------------------------------------------------------------
// Usage Notes:
//   
//   This class has been created to represent a CATIA V4 Table contained in a
//   Project File (cf. CATIAProject).
//
//-----------------------------------------------------------------------------
// Creation by LJH - September 1998
// Upgrade  by JDY - November  1999 for the table alreadyloaded
//-----------------------------------------------------------------------------

#ifndef CATIAProjectTable_H
#define CATIAProjectTable_H

#include "ExportedByCATIAEntity.h"
#include "CATBooleanDef.h"
#include "CATDataType.h"
class CATTrace;

class ExportedByCATIAEntity CATIAProjectTable
{
public:
  // Constructeur par defaut.
  CATIAProjectTable();

  // Constructeur par copie.
  CATIAProjectTable( const CATIAProjectTable & iPrjTableToCopy );

  // Constructeur par defaut.
  ~CATIAProjectTable();

  // Operateur d'affectation.
  CATIAProjectTable& operator = ( const CATIAProjectTable & iPrjTableToCopy );

  // Donnees membres en public pour des raisons de perfos.
  char *  _Data;
  CATLONG32    _DataLength;
  boolean _AlreadyLoaded;

  //
  // Pour les traces
  //
  static CATTrace * TraceInstance;
};

#endif
