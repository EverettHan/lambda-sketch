// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATOMYStringHelper.h
//
//===================================================================

#ifndef CATOMYStringHelper_H
#define CATOMYStringHelper_H

#include "ObjectModelerSystem.h"
#include "DSYStringHelper.h"

class CATUnicodeString;
class CATString;

class ExportedByObjectModelerSystem CATOMYStringHelper
{
public:
  static CATString CUSToCS(const CATUnicodeString &iCUS);
  static CATUnicodeString CSToCUS(const CATString &iCS);
private:
  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATOMYStringHelper(CATOMYStringHelper &);
  CATOMYStringHelper& operator=(CATOMYStringHelper&);
};

#endif
