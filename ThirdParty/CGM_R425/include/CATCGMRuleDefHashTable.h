/* -*-c++-*- */
/**
 * @COPYRIGHT DASSAULT SYSTEMES 2003
 */

//=============================================================================
//
// DESCRIPTION : Class for managing sets of CATCGMRuleDef structs
//
// Jul. 03	Creation                                                      HCN
//=============================================================================

#ifndef CATCGMRuleDefHashTable_h
#define CATCGMRuleDefHashTable_h

#include "ExportedByCATCGMCleaner.h"
#include "CATCGMHashTable.h"
#include "CATCGMRuleDef.h"
#include "CATCGMNewArray.h"


class ExportedByCATCGMCleaner CATCGMRuleDefHashTable : public CATCGMHashTable
{

public:

  CATCGMRuleDefHashTable(int iEstimatedSize = 0);

  ~CATCGMRuleDefHashTable();

  //---------------------------------------------------------------------------
  // Surcharge new/delete ...
  //---------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;

  static unsigned int HashKeyFunction(CATCGMRuleDef* ipCGMRuleDef);
  
  static int CompareFunction(CATCGMRuleDef* ipCGMRuleDef1, CATCGMRuleDef* ipCGMRuleDef2);

  
  inline int            Insert(CATCGMRuleDef* ipCGMRuleDef);

  inline CATCGMRuleDef* Get(int iPos) const;

  inline void*          Locate(CATCGMRuleDef* ipCGMRuleDef) const;

  inline CATCGMRuleDef* KeyLocate(CATGeoClnIDs::RuleID iKey) const; 

  inline int            Remove(CATCGMRuleDef* ipCGMRuleDef);

  inline CATCGMRuleDef* Next(CATCGMRuleDef* ipCGMRuleDef) const;
};

//-----------------------------------------------------------------------------
// Insert
//-----------------------------------------------------------------------------
inline int CATCGMRuleDefHashTable::Insert(CATCGMRuleDef* ipCGMRuleDef)
{
  return (this->CATCGMHashTable::Insert((void*)ipCGMRuleDef));
}

//-----------------------------------------------------------------------------
// Get
//-----------------------------------------------------------------------------
inline CATCGMRuleDef* CATCGMRuleDefHashTable::Get(int iPos) const
{
  return ((CATCGMRuleDef*)this->CATCGMHashTable::Get(iPos));
}

//-----------------------------------------------------------------------------
// Locate
//-----------------------------------------------------------------------------
inline void* CATCGMRuleDefHashTable::Locate(CATCGMRuleDef* ipCGMRuleDef) const
{
  return (this->CATCGMHashTable::Locate((void*)ipCGMRuleDef));
}

//-----------------------------------------------------------------------------
// KeyLocate
//-----------------------------------------------------------------------------
inline CATCGMRuleDef* CATCGMRuleDefHashTable::KeyLocate(CATGeoClnIDs::RuleID iKey) const
{
  return ((CATCGMRuleDef*)this->CATCGMHashTable::KeyLocate((unsigned int)iKey));
}

//-----------------------------------------------------------------------------
// Remove
//-----------------------------------------------------------------------------
inline int CATCGMRuleDefHashTable::Remove(CATCGMRuleDef* ipCGMRuleDef)
{
  return (this->CATCGMHashTable::Remove((void*)ipCGMRuleDef));
}

//-----------------------------------------------------------------------------
// Next
//-----------------------------------------------------------------------------
inline CATCGMRuleDef* CATCGMRuleDefHashTable::Next(CATCGMRuleDef* ipCGMRuleDef) const
{
  return ((CATCGMRuleDef*)this->CATCGMHashTable::Next((void*)ipCGMRuleDef));
}



#endif

