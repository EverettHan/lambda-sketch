#ifndef CATSYPModelProperty_H
#define CATSYPModelProperty_H

#include <CATStyleProcessor.h>
#include <CATSYPModelPropertyBase.h>
#include <CATSYPStyleProcessor.h>
#include <CATUnicodeString.h>
#include <CATSYPModelTag.h>
#include <CATSYPEventDescriptor.h>
#include <UIVCoreToolsInline.h>
class CATSYPModelBinding;
/**
 * Describes a property. Built by CATSYPStyleProcessor when building templates.
 * And used by CATSYPModelTagVisitor, by parsing the model tree describing the view of
 * an introspectable object.
 * A property must have a name, and a value or a binding object.
 */
class ExportedByCATStyleProcessor CATSYPModelProperty : public CATSYPModelPropertyBase
{
public:
  /** Constructor*/
  CATSYPModelProperty();
  /** Constructor of a property in case of simple property with value*/
  CATSYPModelProperty(const CATSYPPropertyDescriptor& i_propertyDescriptor, const CATUnicodeString& i_propertyName, const CATBaseUnknown_var& i_spValue);
  /** Constructor of a property in case of simple property with value set as text (TemplateStyle)*/
  CATSYPModelProperty(const CATSYPPropertyDescriptor& i_propertyDescriptor, const CATUnicodeString& i_propertyName, const CATUnicodeString& i_spValueAsText);
  /** Constructor of a bound property*/
  CATSYPModelProperty(const CATSYPPropertyDescriptor& i_propertyDescriptor, const CATUnicodeString& i_propertyName, CATSYPModelBinding* i_pBinding);
  /** Constructor of a bound property*/
  CATSYPModelProperty(const CATSYPEvent* i_pEvent, const CATUnicodeString& i_propertyName, CATSYPModelBinding* i_pBinding);
  /** Constructor of a bound command notification property*/
  CATSYPModelProperty(const CATUnicodeString& i_propertyName, CATSYPModelBinding* i_pBinding, CATNotification* i_pCommandNotification=NULL);

  INLINE const CATSYPPropertyDescriptor& GetPropertyDescriptor(){return _propertyDescriptor;}
  INLINE const CATSYPEvent* GetEvent(){return _pEvent;}
  INLINE const CATNotification* GetCommandNotification(){return _pCommandNotification;}
  INLINE CATSYPDescriptorBase::IntrospectableEntryType GetEntryType() const{return _entryType;}

protected:
  /** Destructor */
  ~CATSYPModelProperty();
private:
  /** Copy Constructor */
  CATSYPModelProperty(const CATSYPModelProperty &i_toCopy);
  /** Operator = */
  CATSYPModelProperty& operator = (const CATSYPModelProperty &i_toCopy);
private:
  CATSYPDescriptorBase::IntrospectableEntryType _entryType;
  CATSYPPropertyDescriptor _propertyDescriptor;
  const CATSYPEvent* _pEvent;
  const CATNotification* _pCommandNotification;
};

#endif
