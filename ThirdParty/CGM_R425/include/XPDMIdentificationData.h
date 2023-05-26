
#ifndef XPDMIdentificationData_H
#define XPDMIdentificationData_H

#include "CATIAV5Level.h"
#include "ExportedByXPDMServices.h"

#include "CATUnicodeString.h"

#include "CATPLMOmxCollections.h"




class ExportedByXPDMServices XPDMLegacyUniqueID
{
public:
  XPDMLegacyUniqueID();
  ~XPDMLegacyUniqueID();
  CATUnicodeString _LegacyExternal;
};
typedef CATOmxArray< XPDMLegacyUniqueID, CATOmxDefaultCollecManager< XPDMLegacyUniqueID >::manager > CATOmxArrayOfXPDMLegacyUniqueID;

class ExportedByXPDMServices XPDMLegacyUniqueIDs
{
public:
  XPDMLegacyUniqueIDs();
  ~XPDMLegacyUniqueIDs();
  CATOmxArrayOfXPDMLegacyUniqueID _ArrayOfXPDMLegacyUniqueID;
  CATBoolean _bReplace;
};

class ExportedByXPDMServices XPDMLegacyRevisionFamily
{
public:
  XPDMLegacyRevisionFamily();
  ~XPDMLegacyRevisionFamily();
  CATUnicodeString _LegacyRevisionFamily;
};
typedef CATOmxArray< XPDMLegacyRevisionFamily, CATOmxDefaultCollecManager< XPDMLegacyRevisionFamily >::manager > CATOmxArrayOfXPDMLegacyRevisionFamily;

class ExportedByXPDMServices XPDMLegacyRevisionFamilies
{
public:
  XPDMLegacyRevisionFamilies();
  ~XPDMLegacyRevisionFamilies();
  CATOmxArrayOfXPDMLegacyRevisionFamily _ArrayOfXPDMLegacyRevisionFamily;
  CATBoolean _bReplace;
};

class ExportedByXPDMServices XPDMLegacyData
{
public:
  XPDMLegacyData();
  ~XPDMLegacyData();

  XPDMLegacyUniqueIDs _LegacyUniqueIDs;
  XPDMLegacyRevisionFamilies _LegacyRevisionFamilies;
};

class ExportedByXPDMServices XPDMIdentificationDataInt
{
private:
  XPDMIdentificationDataInt();
  ~XPDMIdentificationDataInt();

  XPDMLegacyData _LegacyData;
  CATUnicodeString _External;
  CATUnicodeString _RevisionFamily;

  unsigned int _Count; //for sharing

  friend class XPDMIdentificationData;
  friend class XPDMEnricher;
};
// shared class in the maps
class  ExportedByXPDMServices XPDMIdentificationData
{
public:
  XPDMIdentificationData();
  ~XPDMIdentificationData();
  // copy constructor
  XPDMIdentificationData(const XPDMIdentificationData &iObj);
  // init
  XPDMIdentificationData& operator=(const XPDMIdentificationData &iObj);
  // compare
  int operator==(const XPDMIdentificationData &iObj) const;
private:
  XPDMIdentificationDataInt * _Internal;
  friend class XPDMEnricher;
};

typedef CATOmxOMap< CATUnicodeString , XPDMIdentificationData, CATOmxDefaultCollecManager< CATUnicodeString >::manager, CATOmxDefaultCollecManager< XPDMIdentificationData >::manager > CATOmOMapOfStringToXPDMIdentificationData;
#endif

