/*==================================================
 * (c) 2001 Dassault Systemes. All rights reserved =
 *=================================================*/

/**
 * This module contains a set of functions which can be used to translate types from the C++
 * mapping of the Java Native Interface langage to the C++ mapping of the CNext-IDL language.
 * 
 * @author David Morisot (DMO)
 */

#ifndef CATJNIConversions_h
#define CATJNIConversions_h

// System framework
#include "CATSafeArray.h"
#include "CATBSTR.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATVariant.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"

// CATJavaBridge framework
#include "CATjni.h"

#define JNI_TYPE_NULL 0
#define JNI_TYPE_BOOLEAN 1
#define JNI_TYPE_CHAR 2
#define JNI_TYPE_SHORT 3
#define JNI_TYPE_INT 4
#define JNI_TYPE_FLOAT 5
#define JNI_TYPE_DOUBLE 6
#define JNI_TYPE_STRING 7
#define JNI_TYPE_OBJECT 8
#define JNI_TYPE_ENUM 9
#define JNI_TYPE_ARRAY 10


/*========================= java class utilities. =========================*/

/**
 * Retrieves the java class from the given fully qualified name.
 * Returns E_FAIL if the class could not be found and throws a JNI exception.
 */
JNIEXPORT HRESULT JNICALL GetJavaClass(JNIEnv *env, const CATUnicodeString& iClassName, jclass& oCls);

/**
 * Returns TRUE if the passed jobject is an instance of the java class retrieved
 * from the given fully qualified name.
 */
JNIEXPORT CATBoolean JNICALL IsJavaObjectInstanceOf(JNIEnv *env, jobject iObject, const CATUnicodeString& iClassName);

/**
 * Returns TRUE if the passed jobject is a kind of the java class retrieved
 * from the given fully qualified name.
 */
JNIEXPORT CATBoolean JNICALL IsJavaObjectAKindOf(JNIEnv *env, jobject iObject, const CATUnicodeString& iClassName);

/*========================= Getting CNext Interface pointer. =========================*/
/**
 * This method returns the CNext interface pointer of the object passed in parameter.
 */
JNIEXPORT CATBaseUnknown * JNICALL GetCNextItf(JNIEnv *env, jobject obj);

/**
 * This method returns the CNext interface pointer of the object passed in parameter
 * and specifies in the oRemote parameter if the object is accessible from RMI or not.
 */
JNIEXPORT CATBaseUnknown * JNICALL GetCNextItf(JNIEnv *env, jobject obj, CATBoolean& oRemote);

/**
 * This method returns the JNIBridge interface pointer of the object passed in parameter.
 */
#ifdef PLATEFORME_DS64
JNIEXPORT CATINTPTR JNICALL GetJNIBridgeItf(JNIEnv *env, jobject obj); 
#else
JNIEXPORT jint JNICALL GetJNIBridgeItf(JNIEnv *env, jobject obj); 
#endif

/*========================= Managing errors and exceptions. =========================*/
/**
 * This method checks for cnext errors and throws a JNI exception if any.
 */
JNIEXPORT HRESULT JNICALL CheckCNextError(JNIEnv *env, HRESULT hr, const CATUnicodeString& iMethodName);

/**
 * This method throws a JNI exception with the specified msgCatalog key and parameters.
 */
JNIEXPORT void JNICALL ThrowJNIException(JNIEnv *env, const CATString& iMessageKey,
				 CATUnicodeString *iMsgParameters = NULL, int iNbParams = 0, const CATUnicodeString &iDefaultMsg = "");

/**
 * This method returns the message stored in the specified JNI exception.
 */
JNIEXPORT HRESULT JNICALL GetJNIExceptionMessageAndLine(JNIEnv *env, jthrowable jniExc, CATUnicodeString& oMessage, int& oLine);


/*========================= Converting primitive types. =========================*/
/**
 * This method converts a JNI BooleanHolder to a CNext boolean.
 */
JNIEXPORT HRESULT JNICALL JNIBooleanHolderToCNextBoolean(JNIEnv *env, jobject jniBooleanHolder, boolean& oDsBoolean);

/**
 * This method converts a CNext boolean to a JNI BooleanHolder.
 */
JNIEXPORT HRESULT JNICALL CNextBooleanToJNIBooleanHolder(JNIEnv *env, boolean dsBoolean, jobject& ioJniBooleanHolder);


/**
 * This method converts a JNI CharHolder to a CNext char.
 */
JNIEXPORT HRESULT JNICALL JNICharHolderToCNextChar(JNIEnv *env, jobject jniCharHolder, char& oDsChar);

/**
 * This method converts a CNext char to a JNI CharHolder.
 */
JNIEXPORT HRESULT JNICALL CNextCharToJNICharHolder(JNIEnv *env, char dsChar, jobject& ioJniCharHolder);



/**
 * This method converts a JNI ShortHolder to a CNext short.
 */
JNIEXPORT HRESULT JNICALL JNIShortHolderToCNextShort(JNIEnv *env, jobject jniShortHolder, short& oDsShort);

/**
 * This method converts a CNext short to a JNI ShortHolder.
 */
JNIEXPORT HRESULT JNICALL CNextShortToJNIShortHolder(JNIEnv *env, short dsShort, jobject& ioJniShortHolder);



/**
 * This method converts a JNI IntHolder to a CNext CATLONG.
 */
JNIEXPORT HRESULT JNICALL JNIIntHolderToCNextLong(JNIEnv *env, jobject jniLongHolder, CATLONG& oDsLong);

/**
 * This method converts a CNext CATLONG to a JNI IntHolder.
 */
JNIEXPORT HRESULT JNICALL CNextLongToJNIIntHolder(JNIEnv *env, CATLONG dsLong, jobject& ioJniLongHolder);



/**
 * This method converts a JNI FloatHolder to a CNext float.
 */
JNIEXPORT HRESULT JNICALL JNIFloatHolderToCNextFloat(JNIEnv *env, jobject jniFloatHolder, float& oDsFloat);

/**
 * This method converts a CNext float to a JNI FloatHolder.
 */
JNIEXPORT HRESULT JNICALL CNextFloatToJNIFloatHolder(JNIEnv *env, float dsFloat, jobject& ioJniFloatHolder);



/**
 * This method converts a JNI DoubleHolder to a CNext double.
 */
JNIEXPORT HRESULT JNICALL JNIDoubleHolderToCNextDouble(JNIEnv *env, jobject jniDoubleHolder, double& oDsDouble);

/**
 * This method converts a CNext double to a JNI DoubleHolder.
 */
JNIEXPORT HRESULT JNICALL CNextDoubleToJNIDoubleHolder(JNIEnv *env, double dsDouble, jobject& ioJniDoubleHolder);




/*========================= Converting strings. =========================*/
/**
 * This method converts a JNI string to a CNext CATBSTR.
 */
JNIEXPORT HRESULT JNICALL JNIStringToCATBSTR(JNIEnv *env, jstring jniString, CATBSTR * oDsString);

/**
 * This method converts a CNext CATBSTR to a JNI string.
 */
JNIEXPORT HRESULT JNICALL CATBSTRToJNIString(JNIEnv *env, CATBSTR dsString, jstring& oJniString);



/**
 * This method converts a JNI String to a JNI StringHolder.
 */
JNIEXPORT HRESULT JNICALL JNIStringToJNIStringHolder(JNIEnv *env, jstring iJniString, jobject& ioJniStringHolder);

/**
 * This method converts a JNI StringHolder to a CNext CATBSTR.
 */
JNIEXPORT HRESULT JNICALL JNIStringHolderToCATBSTR(JNIEnv *env, jobject jniStringHolder, CATBSTR* dsString);

/**
 * This method converts a CNext CATBSTR to a JNI StringHolder.
 */
JNIEXPORT HRESULT JNICALL CATBSTRToJNIStringHolder(JNIEnv *env, CATBSTR dsString, jobject& ioJniStringHolder);


/**
 * This method converts a JNI String to a CATUnicodeString.
 */
JNIEXPORT HRESULT JNICALL JNIStringToCATUnicodeString(JNIEnv *env, jstring iJniString, CATUnicodeString& oString);

/**
 * This method converts a CATUnicodeString to a JNI String.
 */
JNIEXPORT HRESULT JNICALL CATUnicodeStringToJNIString(JNIEnv *env, const CATUnicodeString& iString, jstring& oJniString);


/*========================= Converting variants. =========================*/
/**
 * This method converts a JNI Variant to a CNext CATVariant.
 */
JNIEXPORT HRESULT JNICALL JNIVariantToCATVariant(JNIEnv *env, jobject jniVariant, CATVariant& oDsVariant); 

/**
 * This method converts a CNext CATVariant to a JNI Variant.
 */
JNIEXPORT HRESULT JNICALL CATVariantToJNIVariant(JNIEnv *env, const CATVariant& dsVariant, jobject& oJniVariant, CATBoolean isRemote=FALSE);


/**
 * This method converts a java VariantHolder to a CNext CATVariant.
 */
JNIEXPORT HRESULT JNICALL JNIVariantHolderToCATVariant(JNIEnv *env, jobject jniVariant, CATVariant& oDsVariant); 

/**
 * This method converts a CNext CATVariant to a java VariantHolder.
 */
JNIEXPORT HRESULT JNICALL CATVariantToJNIVariantHolder(JNIEnv *env, const CATVariant& dsVariant, jobject& ioJniVariantHolder, CATBoolean isRemote=FALSE); 


/*========================= Converting arrays. =========================*/
/**
 * This method converts a JNI ObjectArray to a CNext CATSafeArrayVariant.
 */
JNIEXPORT HRESULT JNICALL JNIObjectArrayToCATSafeArrayVariant(JNIEnv *env, jobjectArray jniObjectArray, CATSafeArrayVariant*& oDsSafeArray);

/**
 * This method converts a CNext CATSafeArrayVariant to a JNI ObjectArray.
 */
JNIEXPORT HRESULT JNICALL CATSafeArrayVariantToJNIObjectArray(JNIEnv *env, CATSafeArrayVariant* dsSafeArray, jobjectArray& oJniObjectArray, CATBoolean isRemote=FALSE);


/**
 * This method converts a JNI ObjectArrayHolder to a CNext CATSafeArrayVariant.
 */
JNIEXPORT HRESULT JNICALL JNIObjectArrayHolderToCATSafeArrayVariant(JNIEnv *env, jobject jniObjectArrayHolder, CATSafeArrayVariant*& oDsSafeArray);

/**
 * This method converts a CNext CATSafeArrayVariant to a JNI ObjectArrayHolder.
 */
JNIEXPORT HRESULT JNICALL CATSafeArrayVariantToJNIObjectArrayHolder(JNIEnv *env, CATSafeArrayVariant* dsSafeArray, jobject& oJniObjectArrayHolder, CATBoolean isRemote=FALSE);



/*======================= Converting interfaces. =======================*/
/**
 * This method converts a JNI interface to its equivalent CNext C++ interface.
 */
JNIEXPORT HRESULT JNICALL JNIItfToCNextItf(JNIEnv *env, jobject jniItf, CATBaseUnknown *& oCnextItf, IID iidCNext);

/**
 * This method converts a JNI Holder of interface to its equivalent CNext C++ interface.
 */
JNIEXPORT HRESULT JNICALL JNIItfHolderToCNextItf(JNIEnv *env, jobject jniItfHolder, char * jniItfClass, CATBaseUnknown *& oCnextItf, IID iidCNext);


/**
 * This method converts a CNext C++ interface to its equivalent JNI interface.
 * The implementation object can be accessed by RMI if the isRemote flag is set
 * to TRUE.
 */
JNIEXPORT HRESULT JNICALL CNextItfToJNIItf(JNIEnv *env, CATBaseUnknown *cnextItf, jobject& oJniItf,	char * jniDefaultItfClass, CATBoolean isRemote=FALSE);

/**
 * This method converts a CNext C++ interface to its equivalent JNI Holder of interface.
 */
JNIEXPORT HRESULT JNICALL CNextItfToJNIItfHolder(JNIEnv *env, CATBaseUnknown *cnextItf, jobject& oJniItfHolder, char * jniItfClass, CATBoolean isRemote=FALSE);

/**
 * This method returns the full name of the corresponding java class from the specified CNext interface.
 */
JNIEXPORT CATString JNICALL GetJNIFullClassName(CATBaseUnknown * cnextItf);

/**
 * Returns the java interface name (without package qualification) which corresponds
 * to the supplied CNEXT interface.
 */
JNIEXPORT CATString JNICALL CNextItfNameToJavaItfName(CATBaseUnknown * cnextItf);

/*======================= Converting enumerations. =======================*/
/**
 * This method converts a JNI enumeration to its equivalent CNext C++ enumeration.
 */
JNIEXPORT HRESULT JNICALL JNIEnumToCNextEnum(JNIEnv *env, jobject jniEnum, CATLONG& oDsEnum);


/**
 * This method converts a JNI Holder of enumeration to its equivalent CNext C++ enumeration.
 */
JNIEXPORT HRESULT JNICALL JNIEnumHolderToCNextEnum(JNIEnv *env, jobject jniEnumHolder, CATLONG& oDsEnum, char * jniEnumClass);



/**
 * This method converts a CNext C++ enumeration to its equivalent JNI enumeration.
 */
JNIEXPORT HRESULT JNICALL CNextEnumToJNIEnum(JNIEnv *env, CATLONG cnextEnum, jobject& oJniEnum, char * jniEnumClass);


/**
 * This method converts a CNext C++ enumeration to its equivalent JNI Holder of enumeration.
 */
JNIEXPORT HRESULT JNICALL CNextEnumToJNIEnumHolder(JNIEnv *env, CATLONG cnextEnum, jobject& ioJniEnumHolder, char * jniEnumClass);


/*======================= Converting GUID. =======================*/

/**
 * This method converts a string representing a GUID into a CNext GUID structure.
 */
JNIEXPORT HRESULT JNICALL JNIGUIDToCNextGUID(JNIEnv *env, const char *jniGUID,  IID* dsGUID);

/*======================= Managing event listeners. =======================*/

/**
 * This method registers a CNext event listener.
 */
JNIEXPORT HRESULT JNICALL RegisterEventListener(JNIEnv *env, jobject iListenerManager, CATBaseUnknown *listenerAdaptor, IID iidEvents, jobject iListener);

/**
 * This method unregisters a CNext event listener.
 */
JNIEXPORT HRESULT JNICALL UnRegisterEventListener(JNIEnv *env, jobject iListenerManager, IID iidEvents, jobject iListener);

/**
 * This method stores the connection identifier and the subscriber inside Lists managed by the JNI object.
 */
JNIEXPORT HRESULT JNICALL StoreEventConnection(JNIEnv *env, jobject iListenerManager, jobject iListener, unsigned long connectionID);

/**
 * This method removes the event connection stored by the JNI object from the connection ID.
 */
JNIEXPORT HRESULT JNICALL RemoveEventConnection(JNIEnv *env, jobject iListenerManager, unsigned long connectionID);

/**
 * This method stores the connection identifier and the subscriber inside Lists managed by the JNI object.
 */
JNIEXPORT HRESULT JNICALL RetrieveEventConnection(JNIEnv *env, jobject iListenerManager, jobject iListener, unsigned long &connectionID);


#endif // CATJNIConversions_h
