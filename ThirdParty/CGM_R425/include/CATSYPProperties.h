//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/05/06
//===================================================================
// CATSYPArray.cpp
// Header definition of class CATSYPProperties
//===================================================================
//
//
//===================================================================
//  2010/05/06 Creation: jov
//===================================================================

#ifndef CATSYPProperties_H
#define CATSYPProperties_H

#include <IntroInfra.h>
#include <CATNotification.h>
#include <CATBoolean.h>
#include <CATListOfCATUnicodeString.h>
#include <CATSYPMacros.h>
#include <CATSYPArray.h>

class CATHashDico;
class CATUnicodeString;
class CATSYPProperties_data;

/**
 * Class to define properties dictionary.
 * <b>Role</b>: A property dictionary associate property name to a CATBaseUnknown_var
 * Create this class only on the stack. It uses internally copy-on-write pattern
 */
class ExportedByIntroInfra CATSYPProperties
{
public:
  /** Constructor*/
  CATSYPProperties();
  /** Desctructor */
  virtual ~CATSYPProperties();
  /** Copy constructor */
  CATSYPProperties(const CATSYPProperties& i_object);
  /** Operator = */
  CATSYPProperties& operator=(const CATSYPProperties& i_object);
  /**
   * Compare two dictionaries.
   * Two dictionaries are equal if:
   *   1. they contains the same properties
   *   2. for each property, the values are equal.
   *      Let's call value1 and value2 the respective values for the
   *      same property in i_dico1 and i_dico2.
   *      value1 and value2 are considered equal if:
   *        - if value1 implements CATISYPValues inteface, then
   *          value1->Equals(value2) must return !=0.
   *        - else value1->GetImpl() must be equal to value2->GetImpl()
   *      Note that due to its specifications value1->Equals(value2) should
   *      return the same thing as value2->Equals(value1) when value2 is 
   *      not NULL_var. Consequently this implementation of == is commutative.
   * @return !=0 if the dictionaries are equal, else 0.
   */
  ExportedByIntroInfra friend int operator==(const CATSYPProperties &i_dico1, const CATSYPProperties &i_dico2);
  /**
   * Compare difference of two dictionaries.
   *
   * Implemented as the opposite of @c operator==.
   *
   * @return the opposite of the return of @c operator==.
   */
  ExportedByIntroInfra friend int operator!=(const CATSYPProperties &i_dico1, const CATSYPProperties &i_dico2);
  /**
   * Set a property in the dictionary.
   * Note that if the property is already set, then its previous value is replaced
   * by the new one.
   * Note that it's correct to replace with the same value as the one already in
   * this dictionary. 
   * @param i_name the name of the property. Can't be an empty string 
   * @param i_spProperty the property to add to the dico. Can't be
   * NULL_var.
   * This property could be boxed (@see CATDeclareBox), or directly a CATBaseUnknown
   */
  void SetProperty(const CATUnicodeString& i_name, const CATBaseUnknown_var& i_spProperty);
  /**
   * Get a property from its name.
   * @param i_name the name of the wished property. Can't be an empty string.
   * @return the property if it is found, NULL_var otherwise.
   */
  CATBaseUnknown_var GetProperty(const CATUnicodeString& i_name) const;
  /**
   * Remove a property from the dictionary.
   * @param i_name the name of the property. Can't be an empty string.
   * @return @c !=0 if the property existed and has been removed, else @c 0.
   */
  int RemoveProperty(const CATUnicodeString &i_name);
  /**
   * Get a list of the properties contained b the dico.
   * @param io_propertiesList [out] a list of the name of the properties contained by the list.
   */
  void GetPropertiesList(CATSYPArray<CATUnicodeString>& io_propertiesList) const;

private:
  FORCE_STACK_ALLOCATION();
  void CloneDataIfShared();
private:
   CATSYPProperties_data* _pData;
};


#endif
