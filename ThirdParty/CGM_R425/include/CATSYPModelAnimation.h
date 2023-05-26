#ifndef CATSYPModelAnimation_H
#define CATSYPModelAnimation_H
#include <CATStyleProcessor.h>
#include <CATSYPModelTag.h>
#include <CATSYPModelProperty.h>

/**
 * A special model tag describing a CATSYPAnimation.
 */
class ExportedByCATStyleProcessor CATSYPModelAnimation : public CATSYPModelTag
{
public:
  /**
  * Get animated property model tag class name
  */
  const CATUnicodeString& GetAnimationTarget() const
  {
    return _targetClassName;
  }

  /**
  * Get animated property
  */
  const CATUnicodeString& GetTargetProperty() const
  {
    return _targetProperty;
  }
 
  CATSYPModelAnimation(const CATUnicodeString& i_targetClassName,const CATUnicodeString& i_targetProperty,const CATUnicodeString& i_className, CATSYPModelTag::TagType i_classType):CATSYPModelTag("",i_className,i_classType)
  {
    _targetClassName = i_targetClassName;
    _targetProperty = i_targetProperty;
    CHECK_TRUE(i_classType==CATSYPModelTag::Animation);
  }
  virtual ~CATSYPModelAnimation()
  {
  }
private:
  /** Copy Constructor */
  CATSYPModelAnimation(const CATSYPModelAnimation &i_toCopy);
  /** Operator = */
  CATSYPModelAnimation& operator = (const CATSYPModelAnimation &i_toCopy);
private:
  CATUnicodeString _targetClassName;
  CATUnicodeString _targetProperty;

};
#endif
