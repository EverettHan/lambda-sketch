/* -*-c++-*- */
#ifndef CATIPROPERTYEXT_H
#define CATIPROPERTYEXT_H

// COPYRIGHT DASSAULT SYSTEMES 2016


#include "CosPropertyServices.h"
#include "CATBaseUnknown.h"


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIPropertyExt ;


/**Flag to use in define_property_ext and the following APIs, the modification will not cause data to be seen as \"dirty\" (ie. do not impact the IsModified status), TO USE WITH EXTREME CAUTION*/
#define CATIPROPERTYEXT_NODIRTY 0x1
/**Flag to use in define_property_ext and the following APIs, the modification will cause data to be seen as \"dirty\"*/
#define CATIPROPERTYEXT_DIRTY 0x2

/**
* Interface to specify properties on an object. Internal extension of CATIProperty interface.
* @see CORBAAny 
*/
class ExportedByAD0XXBAS CATIPropertyExt : public CATBaseUnknown
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
   * @param iDirtyMode
   *      CATIPROPERTYEXT_NODIRTY or CATIPROPERTYEXT_DIRTY
   */
  virtual void define_property_ext(const PropertyName& iPropertyName, const CORBAAny& iPropertyValue, unsigned int iDirtyMode) = 0 ;
  /**
   * Defines several properties.
   * <br><b> Role: </b> used to assign values to several properties, specified by their names.
   * This method can also be used to modify several properties by changing their values.
   * @param iNproperties
   *     the number of properties.
   * @param iDirtyMode
   *     CATIPROPERTYEXT_NODIRTY or CATIPROPERTYEXT_DIRTY
   */

  virtual void define_properties_ext(const Properties& iNproperties, unsigned int iDirtyMode) = 0 ;
  /**
   * Deletes a property.
   * @param iPropertyName
   *        the name of the concerned property.
   * @param iDirtyMode
   *     CATIPROPERTYEXT_NODIRTY or CATIPROPERTYEXT_DIRTY
   */
  virtual void delete_property_ext(const PropertyName& iPropertyName, unsigned int iDirtyMode) = 0 ;

  /**
   * Deletes several  properties.
   * @param iPropertyNames
   *        the names of the concerned properties.
   * @param iDirtyMode
   *     CATIPROPERTYEXT_NODIRTY or CATIPROPERTYEXT_DIRTY
   */
  virtual void delete_properties_ext(const PropertyNames& iPropertyNames, unsigned int iDirtyMode) = 0 ;
	
  /**
   * Deletes all properties.
   * @param iDirtyMode
   *     CATIPROPERTYEXT_NODIRTY or CATIPROPERTYEXT_DIRTY
   * @return the number of properties deleted.
  */
  virtual int delete_all_properties_ext(unsigned int iDirtyMode) = 0;	
} ; 


CATDeclareHandler( CATIPropertyExt, CATBaseUnknown ) ;

#endif


