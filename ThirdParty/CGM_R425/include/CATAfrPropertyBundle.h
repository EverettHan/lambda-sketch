//===================================================================
// COPYRIGHT Microsoft 2012/10/12
//===================================================================
// CATAfrPropertyBundle.cpp
// Header definition of class CATAfrPropertyBundle
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/10/12 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAfrPropertyBundle_H
#define CATAfrPropertyBundle_H
/**
 * @level Protected
 * @CAA2Usage U1
 */

#include "CATAfrItf.h"
//---------------------------------------------------------------- UIVCoreTools
#include "CATSYPHashMap.h"
//---------------------------------------------------------------------- System
#include "CATUnicodeString.h"
#include "CATString.h"

//-----------------------------------------------------------------------
/**
* Class provinding a mapping from string values to various properties values. 
* <b>Role</b>: It allows to set properties of an instrospectable object.
*
*/
class ExportedByCATAfrItf CATAfrPropertyBundle
{
public:
// Standard constructors and destructors
// -------------------------------------
CATAfrPropertyBundle ();
virtual ~CATAfrPropertyBundle ();


/**
* Inserts an object value.
* <br><b>Role</b>: Inserts an object value into the mapping of this Bundle, replacing any existing value for the given key.
* @param i_key 
*   A string, CANNOT be empty
* @param i_spObject
*   An Object, can be NULL_var
* 
*/
void PutObject(const CATUnicodeString & i_key, const CATBaseUnknown_var & i_spObject);


/**
* Inserts a CATString value.
* <br><b>Role</b>:Inserts a CATString value into the mapping of this Bundle, replacing any existing value for the given key.
* @param i_key 
*   A string, CANNOT be empty
* @param i_string
*   A CATString value, can be empty
* 
*/
void PutCATString(const CATUnicodeString & i_key, const CATString & i_string);


/**
* Inserts a CATUnicodeString value.
* <br><b>Role</b>:Inserts a CATUnicodeString value into the mapping of this Bundle, replacing any existing value for the given key.
* @param i_key
*   A string; CANNOT be empty
* @param i_string
*   A CATUnicodeString value, can be empty
* 
*/
void PutCATUnicodeString(const CATUnicodeString & i_key, const CATUnicodeString & i_string);


/**
* Inserts an integer value.
* <br><b>Role</b>:Inserts an integer value into the mapping of this Bundle, replacing any existing value for the given key.
* @param i_key 
*   A string, CANNOT be empty
* @param i_int
*   An integer value
*/
void PutInt(const CATUnicodeString & i_key, const int & i_int);



/**
* Sets a new object property.
* <br><b>Role</b>: Sets to the introspectable object a new property of CATBaseUnknown type (can be boxed) related to the property name.
* @param i_spIntropectableObject
*   The introspectable object that supports the property name in parameter, CANNOT Be NULL
* @param i_propName
*   The property name supported by the introspectable object
* @param i_spObject
*   The new value for this property
*/
static void SetObjectProperty(const CATBaseUnknown_var & i_spIntropectableObject,const CATUnicodeString & i_propName, const CATBaseUnknown_var & i_spObject);


/**
* Sets a new CATUnicodeString property.
* <br><b>Role</b>:Sets to the introspectable object a new property of CATUnicodeString type related to the property name.
* @param i_spIntropectableObject
*   The introspectable object that supports the property name in parameter, CANNOT Be NULL.
* @param i_propName
*   The property name supported by the introspectable object
* @param i_value
*    The new CATUnicodeString value
*/
static void SetCATUnicodeStringProperty(const CATBaseUnknown_var & i_spIntropectableObject,const CATUnicodeString & i_propName, const CATUnicodeString & i_value);


/**
* Sets a new CATString property.
* <br><b>Role</b>:Sets to the introspectable object a new property of CATString type related to the property name.
* @param i_spIntropectableObject
*   The introspectable object that supports the property name in parameter, CANNOT Be NULL.
* @param i_propName 
*   The property name supported by the introspectable object
* @param i_value
*   The new CATString value
* 
*/
static void SetCATStringProperty(const CATBaseUnknown_var & i_spIntropectableObject,const CATUnicodeString & i_propName, const CATString & i_value);


/**
* Sets a new int property.
* <br><b>Role</b>:Sets to the introspectable object a new property of int type related to the property name.
* @param i_spIntropectableObject
*   The introspectable object that supports the property name in parameter, CANNOT Be NULL.
* @param i_propName
*   The property name supported by the introspectable object.
* @param i_value
*   The new int value
*/
static void SetIntProperty(const CATBaseUnknown_var & i_spIntropectableObject,const CATUnicodeString & i_propName, const int & i_value);


/**
* Retrieves an object property value.
* <br><b>Role</b>:Gets the object value contained in the property of the introspectable object.
* @param i_spIntropectableObject
*   The introspectable object that supports the property name in parameter, CANNOT Be NULL.
* @param i_propName
*   The property name supported by the introspectable object
* 
* @return
*  The property value of CATBaseUnknown type.
* 
*/
static CATBaseUnknown_var GetObjectProperty(const CATBaseUnknown_var & i_spIntropectableObject,const CATUnicodeString & i_propName);


/**
* Retrieves a CATUnicodeString property value.
* <br><b>Role</b>:Gets the CATUnicodeString value containing in the property of the introspectable object.
* @param i_spIntropectableObject
*   The introspectable object that supports the property name in parameter, CANNOT Be NULL.
* @param i_propName
*   The property name supported by the introspectable object
* 
* @return 
*   The property CATUnicodeString value.
* 
*/
static CATUnicodeString GetCATUnicodeStringProperty(const CATBaseUnknown_var & i_spIntropectableObject,const CATUnicodeString & i_propName);


/**
* Retrieves a CATString property value.
* <br><b>Role</b>:Gets the CATString value containing in the property of the introspectable object.
* @param i_spIntropectableObject
*   The introspectable object that supports the property name in parameter, CANNOT Be NULL.
* @param i_propName
*   The property name supported by the introspectable object
* 
* @return
*  The property CATString value
* 
*/
static CATString GetCATStringProperty(const CATBaseUnknown_var & i_spIntropectableObject,const CATUnicodeString & i_propName);


/**
* Retrieves an int property value. 
* <br><b>Role</b>:Gets the int value containing in the property of the introspectable object.
* @param i_spIntropectableObject
*   The introspectable object that supports the property name in parameter, CANNOT Be NULL.
* @param i_propName
*   The property name supported by the introspectable object
*
* @return 
*   The property int value.
* 
*/
static int GetIntProperty(const CATBaseUnknown_var & i_spIntropectableObject,const CATUnicodeString & i_propName);

/**
* Sets the properties defined in the bundle.
* <br><b>Role</b>:Sets properties included in the mapping of this bundle into the introspectable object.
* @param i_spIntrospectableObject
*   The introspectable object.
*    <br><b>Legal value</b>: an object that implements @href CATISYPIntrospectable interface.
* 
*/
void FillProperties(const CATBaseUnknown_var & i_spIntrospectableObject);

/**
* Sets the properties defined on an object.
* <br><b>Role</b>:Sets properties of an introspectable object to another introspectable object.
* @param i_spIntrospectableObject
*   The introspectable object.
    <br><b>Legal value</b>: an object that implements @href CATISYPIntrospectable interface.
* @param i_spIntrospectableObjectToFill
*   The introspectable object to fill.
*    <br><b>Legal value</b>: an object that implements @href CATISYPIntrospectable interface. 
*/
void FillPropertiesFrom(const CATBaseUnknown_var & i_spIntrospectableObject, const CATBaseUnknown_var & i_spIntrospectableObjectToFill );


private:
// Copy constructor and equal operator
// -----------------------------------
CATAfrPropertyBundle (CATAfrPropertyBundle &);
CATAfrPropertyBundle& operator=(CATAfrPropertyBundle&);

CATSYPHashMap<CATUnicodeString,CATBaseUnknown_var> _hashMapProperties;


};

//-----------------------------------------------------------------------

#endif
