

#ifndef CATOmbStreamDescriptorProperties_H
#define CATOmbStreamDescriptorProperties_H

#include "CATOmbStreamDescriptorFormat.h"
#include "CATUnicodeString.h"
#include "CATOmbSelectiveLoading.h"
// COPYRIGHT Dassault Systemes 2012

/**
* @level  Protected
* @usage   U1
*/

//-----------------------------------------------------------------------
/**
* Set of qualifiers for a stream descriptor definition.
*/
class ExportedByCATOmbSelectiveLoading CATOmbStreamDescriptorProperties
{
public:
  CATOmbStreamDescriptorProperties(CATOmbStreamDescriptorFormat iFormat, const CATUnicodeString& iRole, const CATUnicodeString& iLateType,const CATUnicodeString& iPersistencyType);
	     
  /*
    return the Format of the SD
    see enum CATOmbStreamDescriptorFormat in CATOmbStreamDescriptorFormat.h
  */
  const CATOmbStreamDescriptorFormat GetFormat(){return _Format;}
  /*
    return the Role of the SD
    can be : "" , "CATIAV5", "EXTENDED", "DefaultVisuRep", "DefaultNavRep"...
  */
  const CATUnicodeString GetRole(){return _Role;}
  /*
    return the LateType of the SD
  */
  const CATUnicodeString GetLateType(){return _LateType;}
  /*
    return the PersistencyType of the SD
  */
  const CATUnicodeString GetPersistencyType(){return _PersistencyType;}

  CATBoolean IsSet()const;
  
  CATOmbStreamDescriptorProperties();
  ~CATOmbStreamDescriptorProperties();
  CATOmbStreamDescriptorProperties(const CATOmbStreamDescriptorProperties&);
  CATOmbStreamDescriptorProperties& operator=(const CATOmbStreamDescriptorProperties&);  
private:

  CATOmbStreamDescriptorFormat _Format;
  CATUnicodeString  _Role;
  CATUnicodeString	_LateType;
  CATUnicodeString	_PersistencyType;

};

//-----------------------------------------------------------------------

#endif
