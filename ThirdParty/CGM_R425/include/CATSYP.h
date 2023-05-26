// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATSYP.h
// Header definition of CATSYPClock
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2009  Creation: jov
//===================================================================
#ifndef CATSYP_H
#define CATSYP_H

// IntrospectionInfrastructure framework
#include <IntroInfra.h>

// System framework
#include <CATBoolean.h>
#include <CATBaseUnknown.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATString.h>

// To be able to remove #include <CATSYPEnumFactory.h> to prevent include of <nlohmann/json.hpp>
// following include is mandatory else a lot of client fws do not compile...
#include <CATSYPCheck.h>

class CATISYPIntrospectable_var;
class CATUnicodeString;
class CATSYPMetaClass;

struct CATSYPNlsPath
{
  CATSYPNlsPath():catalogName(""), path(""){}
  CATSYPNlsPath(const CATString& i_catalogName, const CATString & i_NewCatalogName, const CATString& i_path): catalogName(i_catalogName), newCatalogName(i_NewCatalogName), path(i_path){}
  CATString catalogName;
  CATString newCatalogName;
  CATString path;
};

class ExportedByIntroInfra CATSYP
{
public:

  /**
   * Data binding OK if the returned string is empty
   */
  static CATUnicodeString CheckDataBinding(const CATSYPMetaClass& i_sourceMetaClass, const CATUnicodeString& i_sourceEntry, const CATSYPMetaClass& i_targetMetaClass, const CATUnicodeString& i_targetEntry);

  /**
   * Connects two introspectable compatible entries of 2 introspectable objects.
   * Note that an assertion will append if the extension implementing CATISYPIntrospectable 
   * don't inherit CATSYPIntrospectableAdapter.
   * The i_sourceIntroEntry must actually exist as an introspectable entry on the i_spSourceObject, and
   * the type of the entry must not be a method nor an event handler.
   * The i_targetIntroEntry must actually exist as an introspectable entry on the i_sTargetObject, and
   * the type of the entry must not be an event.
   * @code Example:
   * CATVidGPSquare* pSquare = new CATVidGPSquare();
   * CATVidCtlbutton* pButton = pButton::CreateButton();
   * // Connect the property ForegroundColor of the button to the property color of the square.
   * CATSYP::Connect(pButton, "ForegroundColor", pSquare, "Color");
   * @endcode
   */
  static void Connect(const CATISYPIntrospectable_var& i_spSourceObject, const CATUnicodeString& i_sourceIntroEntry, const CATISYPIntrospectable_var& i_spTargetObject, const CATUnicodeString& i_targetIntroEntry, CATBoolean i_applyPropertyFlag=TRUE);
  static void UnsafeConnect(const CATISYPIntrospectable_var& i_spSourceObject, const CATUnicodeString& i_sourceIntroEntry, const CATISYPIntrospectable_var& i_spTargetObject, const CATUnicodeString& i_targetIntroEntry, CATBoolean i_applyPropertyFlag=TRUE);
  static void ConnectAttachedProperty(const CATISYPIntrospectable_var& i_spSourceObject, const CATUnicodeString& i_sourceIntroEntry, const CATISYPIntrospectable_var& i_spSourceChildObject, const CATISYPIntrospectable_var& i_spTargetObject, const CATUnicodeString& i_targetIntroEntry, CATBoolean i_applyPropertyFlag=TRUE);
  static void ConnectPropertyToAttachedProperty(const CATISYPIntrospectable_var& i_spSourceObject, const CATUnicodeString& i_sourceIntroEntry, const CATISYPIntrospectable_var& i_spTargetObject, const CATUnicodeString& i_targetIntroEntry, const CATISYPIntrospectable_var& i_spTargetChildObject, CATBoolean i_applyPropertyFlag=TRUE);

  /**
  * Reverse methode of Connect; 
  * Remove binding between the source object i_sourceIntroEntry and target object i_targetIntroEntry
  * if no connection between them anything to do
  * 
  * @see Connect
  */
  static void Disconnect(const CATISYPIntrospectable_var& i_spSourceObject, const CATUnicodeString& i_sourceIntroEntry, const CATISYPIntrospectable_var& i_spTargetObject, const CATUnicodeString& i_targetIntroEntry);
  static void DisconnectAttachedProperty(const CATISYPIntrospectable_var& i_spSourceObject, const CATUnicodeString& i_sourceIntroEntry, const CATISYPIntrospectable_var& i_spSourceChildObject, const CATISYPIntrospectable_var& i_spTargetObject, const CATUnicodeString& i_targetIntroEntry);
  static void DisconnectPropertyToAttachedProperty(const CATISYPIntrospectable_var& i_spSourceObject, const CATUnicodeString& i_sourceIntroEntry, const CATISYPIntrospectable_var& i_spTargetObject, const CATUnicodeString& i_targetIntroEntry, const CATISYPIntrospectable_var& i_spTargetChildObject);

  /**
   * Load internationalization resources on an introspectable object, and do it recursively, 
   * by checking if the object implements CATISYPPresenter or  CATISYPCollection.
   *
   * For each object with an attribute Name found, and for each property of this object those type is CATUnicodeString,
   * it constructs a path with all its father having an attribute Name (they do not need to have one).
   * If this path correspond to an entry in the resource file with the same name than the introspectable,
   * the property is valuated by the the value retrieved from the .CATNls file.
   *
   * Names starting with a @c '.' character are considered blanks and
   * won't be part of the path (for example a name like @c ".Content"
   * will be ignored). This can be used to give names to internal
   * objects that don't affect NLS paths.
   * 
   * @par Example
   * With a property Prop4 of introspectable class Class4, and the following hierarchy :
   * <code>
   * <Class1 Name="Name1">
   *   <Class2>
   *      <Class3/>
   *      <Class4 Name="Name4">/>
   *   </Class2>
   * </Class1>
   * </code>
   * It will look for an entry Name1.Name4.Prop4 ; if such an entry is found, with a line Name1.Name4.Prop4 = value4;
   * it will call Class4::SetProp4(value4);
   */
  static void LoadResources(const CATISYPIntrospectable_var& i_spIntrospectable);
  /** @deprecated */
  static void LoadResources(const CATISYPIntrospectable_var& i_spIntrospectable, int i_nbResourceFileFound);

  /**
   * Returns TRUE if the given value is of a type compatible with the given property type.
   * @param i_value the value to test
   * @param i_propertyType the property type
   * @param i_valueTypeFlag flag indicating if the property is a boxing value or a CATBaseUnknown
   */
  static CATBoolean IsValueCompatible(const CATBaseUnknown_var& i_value, const CATUnicodeString& i_propertyType, int i_valueTypeFlag);

  /**
   * Returns TRUE if the given value is of a type compatible with the property of the given meta class.
   * @param i_value the value to test
   * @param i_metaClass the given meta class
   * @param i_propertyName the property name
   */
  static CATBoolean IsValueCompatible(const CATBaseUnknown_var& i_value, const CATSYPMetaClass& i_metaClass, const CATUnicodeString& i_propertyName);

  /**
   * @return !=0 if the two given boxing objects are equal, 0 otherwise.
   *
   * i_value1 and i_value2 are considered equal if :
   *   - if i_value1 implements CATISYPValues inteface, then
   *     i_value1->Equals(i_value2) must return !=0.
   *   - else i_value1->GetImpl() must be equal to i_value2->GetImpl()
   * @see CATISYPValues
   */
  static int BoxingObjectsAreEqual(const CATBaseUnknown_var &i_value1, const CATBaseUnknown_var &i_value2);

  /**
   * @return !=0 if the two given lists are equal, i.e if each element of a list is equal to the 
   * element stored at the same index in the other list, 0 otherwise.
   * @see BoxingObjectsAreEqual
   * @see CATISYPValues
   */
  static int BoxingListAreEqual(const CATListValCATBaseUnknown_var &i_list1, const CATListValCATBaseUnknown_var &i_list2);

  /**
   * Indicates whether the given property exists or not into the given introspectable object.
   * @param i_spIntrospectable the given introspectable object.
   * @param i_propertyName the name of the property to look for.
   * @return 0 if the property does not exist for the given introspectable object, 1 otherwise.
   */
  static int ContainsProperty(const CATISYPIntrospectable_var& i_spIntrospectable, const CATUnicodeString & i_propertyName);

  /*
  * Load NLS resources for Data template which generated i_spIntrospectable view.
  */
  static void LoadDataTemplateResources(const CATISYPIntrospectable_var& i_spIntrospectable,  const CATUnicodeString & i_dataTemplate, const CATUnicodeString &  i_dataTemplateVariation);

  /*
  * Method to format resource found in CATNLS files. (Migration V6R2016x).
  */
  static void FormatNLSResource(CATUnicodeString & iotext);

};

#endif
