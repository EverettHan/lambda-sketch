#ifndef CATVidCtl_CATVidCtlTweakerGenericRepresentation_h
#define CATVidCtl_CATVidCtlTweakerGenericRepresentation_h

// COPYRIGHT Dassault Systemes 2014

// Local framework
#include <VisuDialog.h>
#include <CATVidCtlTweaker.h>

// IntrospectionInfrastructure
#include <CATSYPDataBlock.h>

// System framework
#include <CATUnicodeString.h>

class CATISYPIntrospectable_var;
class CATSYPPropertiesChangedEventArgs;

class ExportedByVisuDialog CATVidCtlTweakerGenericRepresentation : public CATVidCtlTweaker
{
  CATDeclareClass;
public:
  /** Constructor */
  CATVidCtlTweakerGenericRepresentation();
  /**
  * Configure the internal type of the tweaker.
  * @param i_valueType string representation of the type to configure
  * @param i_defaultStringValueType string representation of the type default value 
  */
  void SetValueType( const CATUnicodeString& i_valueType, const CATBaseUnknown_var& i_spDefaultValue);
  /**
  * @see SetValueType
  */
  const CATUnicodeString& GetValueType() const; 

  virtual CATUnicodeString GetType() const {return GetValueType();};

  virtual CATBaseUnknown_var GetData() const;
  virtual HRESULT SetData(const CATBaseUnknown_var& i_spData);

  void SetTweakerData(const CATBaseUnknown_var& i_spData);
  const CATBaseUnknown_var& GetTweakerData() const;

protected:
  /** Destructor */
  virtual ~CATVidCtlTweakerGenericRepresentation();

private:
  /** Copy constructor*/
  CATVidCtlTweakerGenericRepresentation (CATVidCtlTweakerGenericRepresentation &);
  /** operator = */
  CATVidCtlTweakerGenericRepresentation& operator=(CATVidCtlTweakerGenericRepresentation& original);
private:
  CATUnicodeString _valueType;
  CATBaseUnknown_var _spData;
};

#endif // CATVidCtl_CATVidCtlTweakerGenericRepresentation_h
