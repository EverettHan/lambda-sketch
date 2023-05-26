/* -*-c++-*- */
#ifndef COS_PROPERTY_SERVICES_H
#define COS_PROPERTY_SERVICES_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
  * @CAA2Required
  * 
  */

#include "CATUnicodeString.h"
#include "CORBAAnyDef.h"

#include "sequence.h"
#include "AD0XXBAS.h"

/** Type to use with CATIProperty interface methods. 
  * @see CATIProperty
  */
typedef CATUnicodeString PropertyName;

/** 
  * Property.
  * @see CATIProperty
  * @param property_name
  *           the name of the property.
  * @param property_value
  *           the value of the property.
  */
struct Property {
	PropertyName property_name;
	CORBAAny property_value;
};

/** @nodoc */
enum PropertyModeType {
 	normal,
 	read_only,
 	fixed_normal,
 	fixed_readonly,
 	undefined
};
 
/** @nodoc */
struct PropertyDef {
	PropertyName property_name;
	CORBAAny property_value;
	PropertyModeType property_mode;
};

/** @nodoc */
struct PropertyMode {
	PropertyName property_name;
	PropertyModeType property_mode;
};

// 
// --> Definition des sequences
//
/** @nodoc */
DEF_SEQUENCE( PropertyName, AD0XXBAS)
/** @nodoc */
DEF_SEQUENCE( Property , AD0XXBAS)
/** @nodoc */
DEF_SEQUENCE( PropertyDef, AD0XXBAS)
/** @nodoc */
DEF_SEQUENCE( PropertyMode, AD0XXBAS)
 
/** @nodoc */
typedef SEQUENCE( PropertyDef )		PropertyDefs ;
/** @nodoc */
typedef SEQUENCE( PropertyMode )	PropertyModes ; 
/** Type to use with CATIProperty interface methods. */
typedef SEQUENCE( PropertyName )  	PropertyNames ;
/** Type to use with CATIProperty interface methods. */
typedef SEQUENCE( Property )		Properties ;


#endif


