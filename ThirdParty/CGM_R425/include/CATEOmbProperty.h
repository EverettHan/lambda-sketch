// COPYRIGHT Dassault Systemes 2002
//===============================================

#ifndef __CATEOmbProperty_h__
#define __CATEOmbProperty_h__
// ==============================================
// Implement CATIProperty
// ==============================================

// ==============================================
// import forward declarations for this FW
// ==============================================
/**
 * @level Protected 
 * @usage U1
 */

#include "ON0PROP.h"
// ==============================================
// import some  prereqs
// ==============================================
// ==============================================
// import super class
// ==============================================
#include "CATIProperty.h"

class CATOmbPropertiesItem;

// ==============================================
// definition of classCATEOmbProperty
// ==============================================

class ExportedByON0PROP CATEOmbProperty : public   CATIProperty
{
//EVN DONE
public:
      CATEOmbProperty();
//EVN DONE
      ~CATEOmbProperty();
private:
      CATEOmbProperty(const CATEOmbProperty& prop);
     CATEOmbProperty& operator=(const CATEOmbProperty& prop);
//
public:
    virtual void define_property(const PropertyName& property_name,const CORBAAny& property_value);
// simulated call
    virtual void define_properties(const Properties& nproperties);
//
    virtual CATULONG32  get_number_of_properties();
// simulated call
    virtual CORBAAny get_property_value(const PropertyName& property_name);
// EVN DONE
    virtual void delete_property(const PropertyName& property_name);
    virtual void delete_properties(const PropertyNames& property_names);
    virtual int delete_all_properties();
    virtual int is_property_defined(const PropertyName& iPropertyName);
    virtual Properties get_all_properties();
//EVN DONE
    virtual PropertyNames get_all_property_names();
// 
    virtual HRESULT get_all_property_names(PropertyNames& result);
// 
    virtual HRESULT get_property_value(const PropertyName& iPropertyName,CORBAAny& oValue);
// @deprecate use other
     Properties get_properties(const PropertyNames& iPropertyNames);
// EVN DONE
    virtual HRESULT get_properties(const PropertyNames& iPropertyNames,Properties& oProperties);
    virtual HRESULT get_all_properties(Properties& oProperties);
private:
     CATOmbPropertiesItem* shiftTo(const PropertyName& name);
public:
    virtual int SetBasicProperty(const PropertyName& name,const CORBAAny& value);
    virtual int GetBasicProperty(const PropertyName& name,CORBAAny& oValue);
    virtual void GetBasicPropertyNames(PropertyNames& out);
    virtual CATULONG32  GetBasicPropertyCount();
    virtual void ManageUndoForProperty(const PropertyName& name,const CORBAAny& old_value,const CORBAAny& new_value);
    virtual void ManageUndoForProperty();
private:
     CATOmbPropertiesItem* m_properties;
     unsigned int m_count;
};
#endif
