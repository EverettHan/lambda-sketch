#ifndef CATMMCCONSTPROPERTIESPROTOTYPE_H
#define CATMMCCONSTPROPERTIESPROTOTYPE_H

#include "CATMMediaCore.h"
#include "CATMMCPropertyType.h"
#include "CATSysTSBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATMMCReturnCode.h"
//@MMNJNinf @QDesc: To consult Prototype of Properties
//@MMNJNinf @FDesc: Interface for consulting Prototype of Properties.

/**
 * @ingroup groupMMCProperties
 * Services to retrieve information on a prototype for CATMMCProperties.
 */
class ExportedByCATMMediaCore CATMMCConstPropertiesPrototype : public CATSysTSBaseUnknown
{
public:
  /**
   * Retrieves the name of all properties specified by the prototype.
   * @param oListProperties a list of all named properties specified by the prototype.
   */
  virtual CATMmRC                                   GetListProperties(CATListOfCATUnicodeString& oListProperties) const =0;

  /**
   * Answers if the prototype has specified a named property.
   * @param iPropertyName the name of the property to check if existing on prototype.
   * @return CATMmRcOK if prototype is specifying the named property, CATMmRcFailed otherwise.
   */
  virtual CATMmRC                                   HasProperty(const CATUnicodeString& iPropertyName)         const =0;

  /**
   * Retrieves the type of a property specified on the prototype.
   * @param iPropertyName the name of the property to retrieve its value type.
   * @return the string specifying the value type of the property.
   */
  virtual const CATUnicodeString                    GetPropertyType(const CATUnicodeString& iPropertyName)     const =0;

  /**
  * Retrieves the type of a property specified on the prototype.
  * @param iPropertyName the name of the property to retrieve its value type.
  * @return the value type of the property.
  */
  virtual CATMMCPropertyType                        GetPropertyAsType(const CATUnicodeString& iPropertyName)   const = 0;

  /**
   * Retrieves the prototype for the parameters of a property.
   * @param iPropertyName the of the property to retrieve the prototype of its parameters.
   * @return a pointer on the prototype of parameters on a property. Has to be released after use.
   */
  virtual CATMMCConstPropertiesPrototype*           GetPropertyPrototype(const CATUnicodeString& iPropertyName)const =0;

  /**
   * Service to convert a basic type into its string version.
   * @param iPropertyType the basic type to convert into its string version.
   * @return the string representing a type of property.
   */
  static CATUnicodeString                           GetPropertyTypeAsUnicode(CATMMCPropertyType iPropertyType);

protected:
  CATMMCConstPropertiesPrototype():CATSysTSBaseUnknown(true) {};
  CATMMCConstPropertiesPrototype(const CATMMCConstPropertiesPrototype&):CATSysTSBaseUnknown(true) {};

private:
  CATMMCConstPropertiesPrototype& operator=(const CATMMCConstPropertiesPrototype&);
};

#endif
