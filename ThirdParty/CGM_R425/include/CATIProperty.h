/* -*-c++-*- */
#ifndef CATI_PROPERTY_H
#define CATI_PROPERTY_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Required
  * 
  */


#include "CosPropertyServices.h"
#include "CATBaseUnknown.h"


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIProperty ;

/**
* Interface to specify properties on an object.
* @see CORBAAny 
*/

class ExportedByAD0XXBAS CATIProperty : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  /**
   * Defines a property.
   * <br><b> Role: </b> used to assign a value to a property, specified by its name.
   * This method can also be used to modify a property with the same name by changing
   * its value.
   * @param iPropertyName
   *      the name of the property to set.
   * @param iPropertyValue
   *      the value of the property.
   */
  virtual void define_property(const PropertyName& iPropertyName,
			       const CORBAAny&     iPropertyValue) = 0 ;
  /**
   * Defines several properties.
   * <br><b> Role: </b> used to assign values to several properties, specified by their names.
   * This method can also be used to modify several properties by changing their values.
   * @param iNproperties
   *     the number of properties.
   */
  virtual void define_properties(const Properties& iNproperties) = 0 ;
	
  //  
  // --> Listing and getting properties
  //	

  /**
   * Returns the total number of properties.
   */
  virtual CATULONG32  get_number_of_properties() = 0 ;

  /**
   * Returns the name of all properties.
   */
  virtual PropertyNames get_all_property_names() = 0 ;
    
  /**
   * Returns the value of a given property.
   * @param iPropertyName
   *        the name of the concerned property.
   */
  virtual CORBAAny get_property_value(const PropertyName& iPropertyName) = 0 ;
  
  /**
   * Returns several properties.
   * @param iPropertyNames
   *        the names of concerned properties.
   */
  virtual Properties get_properties(const PropertyNames& iPropertyNames) = 0 ;
	
  /**
   * Returns all properties.
   */
  virtual Properties get_all_properties() = 0 ;
	
  /**
   * Deletes a property.
   * @param iPropertyName
   *        the name of the concerned property.
   */
  virtual void delete_property(const PropertyName& iPropertyName) = 0 ;

  /**
   * Deletes several  properties.
   * @param iPropertyNames
   *        the names of the concerned properties.
   */
  virtual void delete_properties(const PropertyNames& iPropertyNames) = 0 ;
	
  /**
   * Deletes all properties.
   * @return the number of properties deleted.
  */
  virtual int delete_all_properties() = 0;
	
  /**
   * Tests whether a property is defined on this object.
   * @param iPropertyName
   *        the name of concerned property.
   * @return 1 if is defined.
   *         0 otherwise.
   */  
  virtual int is_property_defined(const PropertyName& iPropertyName) = 0 ;
  
  /** @nodoc */  
  virtual HRESULT get_all_property_names(PropertyNames& oPropertyNames) = 0 ;
  /** @nodoc */  
  virtual HRESULT get_property_value(const PropertyName& iPropertyName, CORBAAny& oValue) = 0 ;
  /** @nodoc */  
  virtual HRESULT get_properties(const PropertyNames& iPropertyNames, Properties& oProperties) = 0 ;
  /** @nodoc */  
  virtual HRESULT get_all_properties(Properties& oProperties) = 0 ;

} ; 


CATDeclareHandler( CATIProperty, CATBaseUnknown ) ;

#endif


