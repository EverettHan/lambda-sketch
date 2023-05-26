//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/08/13
//===================================================================
// CATSYPTweaker.h
// Header definition of class CATSYPTweaker
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/08/13 Creation: Code generated by the 3DS wizard  VV6
//===================================================================

#ifndef CATSYPTweaker_H
#define CATSYPTweaker_H

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>

/**
 *
 */
class ExportedByIntroInfra CATSYPTweaker : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** Default Constructor */
  CATSYPTweaker();
  /**
   * Constructor
   *
   * @param the stylesheet in which the data template to build the read-only
   * view is defined.
   */
  CATSYPTweaker(const CATUnicodeString & i_readOnlyStyleSheet);

  /** Destructor */
  virtual ~CATSYPTweaker();

  /**
   * Get the stylesheet in which the data template to build the read-only view
   * is defined.
   *
   * @return the stylesheet in which the data template to build the read-only
   * view is defined.
   */
  const CATUnicodeString & GetReadOnlyViewStyleSheet() const;

  void SetPropertyLabel(const CATUnicodeString& i_valueName);
  const CATUnicodeString& GetPropertyLabel() const;

  void SetBoxedValue(const CATBaseUnknown_var& _spBoxedValue);
  const CATBaseUnknown_var& GetBoxedValue() const;

  CATUnicodeString GetRODisplayedValue(){return GetValueAsString();}

  /**
  * Set the internal data block typed property from a string.
  * @param i_stringValue string value representation 
  */
  void SetValueAsString(CATUnicodeString i_stringValue);
/**
  * @see SetValueAsString
  */
  CATUnicodeString GetValueAsString();

  const CATUnicodeString& GetValueType(){return _valueType;}


protected:
  void _SetValueType( const CATUnicodeString& i_valueType, const CATBaseUnknown_var& i_spDefaultValue);
private:
  // Copy constructor and assignement operator are not implemented
  CATSYPTweaker(const CATSYPTweaker &);
  CATSYPTweaker& operator= (const CATSYPTweaker &);
private:
  // The StyleSheet in which the read-only data template is defined for this
  // tweaker
  CATUnicodeString _readOnlyViewStyleSheet;
  int _valueAsStringDeprecatedFlag;
  CATUnicodeString _valueAsString;
  CATBaseUnknown_var _spBoxedValue;
  CATUnicodeString _valueType;
  CATUnicodeString _valueName;
};

#endif
