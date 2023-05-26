#ifndef CATMMCPROPERTIES_H
#define CATMMCPROPERTIES_H

#include "CATMMediaCore.h"
#include "CATMMCReturnCode.h"
#include "CATSysTSBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATSysTSListOfUnicodeString.h"
#include "CATMMCPropertyValue.h"

/**
 * @ingroup groupMMC
 * @defgroup groupMMCProperties Multimedia Properties
 * This module contains the objects that take part to Multimedia Properties Infrastructure.
 * Supported Properties types are (see source CATMMCPropertyValue.h ):
 *   - CATUnicodeString
 *   - CATBoolean
 *   - BYTE
 *   - CATUInt32
 *   - CATInt32
 *   - float
 *   - CATListOfFloat
 *   - CATSysTSBaseUnknown
 * @brief Properties used by Filter objects in @ref groupMultimediaEngines and CATMMMetadataXMP.
 */

class CATMMCConstPropertiesPrototype;
class CATMMCProperties_data;
class CATMMCPropertyValueBase;
//@MMNJNinf @QDesc: Properties handler
//@MMNJNinf @FDesc: Properties handler, supporting Prototypes.

/**
 * @ingroup groupMMCProperties
 * Implementation of list of introspectable properties.
 */
class ExportedByCATMMediaCore CATMMCProperties
{
  friend class CATMMediaFilterImpl;//Only the core engine is allowed to modify the the prototype of Properties.
public:
  /**
   * Constructor
   * @param ipPrototype the optional prototype to reference listing all available properties with their names, types.
   */
  CATMMCProperties(CATMMCConstPropertiesPrototype*ipPrototype=NULL);

  /**
   * Copy constructor
   */
  CATMMCProperties(const CATMMCProperties&);

  /**
   * Destructor.
   */
  virtual ~CATMMCProperties();

  /**
   * If so, retrieves the PropertiesPrototype referenced by the list.
   * @param ioPrototype if so, the prototype referenced by the list of properties. Returned pointer has to be released after use.
   */
  virtual CATMmRC               GetPrototype(CATMMCConstPropertiesPrototype* &ioPrototype)        const;

  /**
   * Answers if a property has been specified.
   * @param iPropertyName the name of the property to check if has been defined.
   * @return CATMmRcOK if prototype is specifying the named property, CATMmRcFailed otherwise.
   */
  virtual int                   HasProperty(const CATUnicodeString& iPropertyName)           const;

  /**
   * Retrieves the names of all properties.
   * @param oListProperties the list of properties names.
   */
  virtual int                   GetListProperties(CATListOfCATUnicodeString& oListProperties)   const;
  virtual int                   GetListProperties(CATSysTSListOfUnicodeString& oListProperties)   const;

  /**
   * Availability 
   */
  enum PropertyAvailability {
    mmcPA_Unavailable,
    mmcPA_Available,
    mmcPA_Defined
  };
  /**
   * Retrieves availability of a property.
   * @param iPropertyName the name of the property to get its availability on properties handler.
   * @return its availability.
   */
  virtual PropertyAvailability  GetAvailability(const CATUnicodeString& iPropertyName)       const;

  /**
   * Returns the type of value of a property.
   * @param iPropertyName the name of the property to get its type.
   * @return the type of the property. If not defined, returns empty string.
   */
  virtual CATUnicodeString GetPropertyType(const CATUnicodeString& iPropertyName)       const;

  /**
   * Adds a new property in the list. In this case, the list of properties has to reference a PropertiesPrototype.
   * @param iPropertyName the name of the property to add referenced in the PropertiesPrototype.
   */
  virtual CATMmRC               AddProperty(const CATUnicodeString& iPropertyName);

  /**
   * Adds a new property in the list. In case, the list of properties does not reference a PropertiesPrototype.
   * @param iPropertyName the name of the property to add referenced in the PropertiesPrototype.
   * @param iPropertyType the type of value of the property to add referenced in the PropertiesPrototype.
   * @param ipPrototype the prototype for  to add referenced in the PropertiesPrototype.
   */
  virtual CATMmRC               AddProperty(const CATUnicodeString& iPropertyName, const CATUnicodeString& iPropertyType, CATMMCConstPropertiesPrototype* ipPrototype=NULL);

  /**
   * Returns a copy of the parameters of a property, if so.
   * @param iPropertyName the name of the property to retrieve its parameters.
   * @return A copy of the parameters of the property.
   */
  virtual CATMMCProperties*     GetPropertyParameters(const CATUnicodeString& iPropertyName) const;

  /**
   * Reporting properties from another set of properties, either both properties referenced the same prototye or both referenced none.
   * @param iPropertiesValues the list of properties and values .
   * @return A copy of the parameters of the property.
   */
  virtual CATMmRC               SetFromProperties(const CATMMCProperties& iPropertiesValues);

  /** @name Accesssing properties*/
  /**@{*/ 
  /**
   * Sets the value of a property.
   * @param iPropertyName the name of the property for which the value has to be changed.
   * @param iValue the new value for this property.
   */
  CATMmRC                       SetProperty(const CATUnicodeString& iPropertyName, const CATMMCPropertyValueBase& iValue);
  /**
   * Returns the value of a property.
   * @param iProperty the name of the property on which to get the string value.
   * @return the value for this property. If not NULL, pointer has to be deleted. If property does not exist or if is not a string value, a empty string is returned.
   */
  const CATMMCPropertyValueBase* GetProperty(const CATUnicodeString& iPropertyName)           const;

  template<class T>
  CATMmRC QuickGetProperty(const CATUnicodeString& iName, T& oValue) const;
  template<class T>
  CATMmRC QuickSetProperty(const CATUnicodeString& iName, const T& iValue);

  /**@}*/
  CATMMCProperties&             operator=(const CATMMCProperties&);

private:  
  CATMMCProperties_data             *m_PropertiesData;
};

template<class T>
CATMmRC  CATMMCProperties::QuickGetProperty(const CATUnicodeString& iName, T& oValue) const
{
  const CATMMCPropertyValueBase* propBVal=GetProperty(iName);
  if(!propBVal)
    return CATMmRcFailed;
  if( !(GetPropertyValue(*propBVal,oValue)) )
    return CATMmRcFailed;
  return CATMmRcOK;
}
template<class T>
CATMmRC CATMMCProperties::QuickSetProperty(const CATUnicodeString& iName, const T& iValue)
{
  CATMMCPropertyValueReal<T> lPropertyValueToSet(iValue);
  CATUnicodeString us(iName.ConvertToChar());
  return SetProperty(us,lPropertyValueToSet);
}

#endif
