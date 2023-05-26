//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
// Création par Johann Chemin (JAC)
//------------------------------------------------------------------------------
//Pas exposée pour le moment
#ifndef CATIIniSearchTopologyCriterion_H
#define CATIIniSearchTopologyCriterion_H

#include "UIModelInterfaces.h"

#include "CATIIniSearchCriterion.h"
#include "CATIniSearchEnumeration.h"
#include "CATString.h"
#include "CATUnicodeString.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchTopologyCriterion;

/**
 * Interface to define a search criterion. 
 * <br><br>
 * <b>Role:</b> This interface enables the complete definition of
 * a search criterion of topological representations on objects.
 * <br><br>
 * @see CATIIniSearchCriterion
 */
class ExportedByUIModelInterfaces CATIIniSearchTopologyCriterion : public CATIIniSearchCriterion
{
  /**
   * @nodoc
   */
  CATDeclareInterface;

public:
  virtual HRESULT SetParameters(const CATString& iAliasName,
                                CATIniSearchEnumeration::Comparison iOperatingSign,
                                CATUnicodeString iNLSName="") = 0;
};
#endif
