#ifndef CATSYPModelSetter_H
#define CATSYPModelSetter_H

#include <CATStyleProcessor.h>
#include <CATBaseUnknown_var.h>
#include <CATUnicodeString.h>
#include <CATSYPModelTag.h>

/**
 * A special model tag describing a CATSYPSetter.
 */
class ExportedByCATStyleProcessor CATSYPModelSetter:public CATSYPModelTag
{
public:
  /** @return the target model tag */
  CATSYPModelTag* GetTarget() const
  {
    return _pSetterTarget;
  }
  /** @return the attached target model tag, in case of attached property*/
  CATSYPModelTag* GetAttachedTarget() const
  {
    return _pAttachedTarget;
  }
  /** @return the syp:name of the target when CATSYPModelTag of target is not available.*/
  const CATUnicodeString& GetTargetName()const { return _setterTargetName; }
  /** @return the syp:name of the attached target when CATSYPModelTag of target is not available.*/
  const CATUnicodeString& GetAttachedTargetName()const { return _attachedTargetName; }

private:
  /**
   * Constructor with two args.
   * @param i_pSetterTarget [mandatory] the target model tag of the setter.
   * @param i_pAttachedTarget [optional] the attached model tag of the setter in case of attached property.
   */
  CATSYPModelSetter(CATSYPModelTag* i_pSetterTarget, CATSYPModelTag* i_pAttachedTarget):CATSYPModelTag("", CATSYPModelTag::Setter)
  {
    CHECK_POINTER(i_pSetterTarget);
    _pSetterTarget = i_pSetterTarget;
    _pAttachedTarget = i_pAttachedTarget;
  }
  CATSYPModelSetter(const CATUnicodeString& i_setterTargetName, const CATUnicodeString& i_attachedTargetName):CATSYPModelTag("", CATSYPModelTag::Setter)
  {
    _pSetterTarget = NULL;
    _pAttachedTarget = NULL;
    _setterTargetName = i_setterTargetName;
    _attachedTargetName = i_attachedTargetName;
  }  
  virtual ~CATSYPModelSetter()
  {
    _pSetterTarget = NULL;
    _pAttachedTarget = NULL;
  }
private:
  CATSYPModelTag* _pSetterTarget;
  CATSYPModelTag* _pAttachedTarget;
  CATUnicodeString _setterTargetName;
  CATUnicodeString _attachedTargetName;
  friend class CATSYPStyleProcessor;
  friend class CATSYPSaxModelBuilder;
  friend class CATSYPDynamicTreeVisitor;
};
#endif
