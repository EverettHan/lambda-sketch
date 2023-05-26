// COPYRIGHT DASSAULT SYSTEMES   2001
//=============================================================================
//
// class CATTreeRepository :
//	Gestion des settings de l'arbre
//
//=============================================================================
// Usage Notes:
//
// a include dans les .cpp pour utiliser les services.
//
//=============================================================================
// Jan. 01   Creation                                           
//=============================================================================
#ifndef CATTreeRepository_h
#define CATTreeRepository_h

/**
 * @level Private
 * @usage U1
 */

#include "CATOmnMain.h"

class CATTreeRepository;
class CATSettingRepository;

class ExportedByCATOmnMain CATTreeRepository 
{  
public:
 
  CATTreeRepository();
  ~CATTreeRepository();
  
  static CATSettingRepository* GetTreeRepository(); 

private :
  
};

#endif
