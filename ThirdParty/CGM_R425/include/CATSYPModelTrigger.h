#ifndef CATSYPModelTrigger_H
#define CATSYPModelTrigger_H
#include <CATStyleProcessor.h>
#include <CATSYPModelTag.h>
#include <CATSYPModelProperty.h>
#include <CATBasicBoxing.h>
#include <CATUnicodeString.h>

/**
 * A special model tag describing a CATSYPTrigger.
 */
class ExportedByCATStyleProcessor CATSYPModelTrigger : public CATSYPModelTag
{
public:
  CATSYPModelTag* GetTriggerSource() const
  {
    return _pTriggerSource;
  }
  const CATUnicodeString & GetTriggerValue() const
  {
    return _triggerValue;
  }
  void SetTriggerValue(const CATUnicodeString & i_triggerValue)
  {
    _triggerValue = i_triggerValue;
  }
  int GetTriggeringValueInitFlag() const {return _tringgeringValueIntFlag;}
private:
  void SetTriggeringValueInitFlag()
  {
    _tringgeringValueIntFlag=1;
  }
  CATSYPModelTrigger(CATSYPModelTag* i_pTriggerSource, CATSYPModelTag::TagType i_classType):CATSYPModelTag("",i_classType)
  {
    _tringgeringValueIntFlag=0;
    _pTriggerSource = i_pTriggerSource;
    CHECK_TRUE(i_classType==CATSYPModelTag::EventTrigger || i_classType==CATSYPModelTag::Trigger);
  }
  virtual ~CATSYPModelTrigger()
  {
    _pTriggerSource = NULL;
  }
  /** Copy Constructor */
  CATSYPModelTrigger(const CATSYPModelTrigger &i_toCopy);
  /** Operator = */
  CATSYPModelTrigger& operator = (const CATSYPModelTrigger &i_toCopy);
private:
  CATSYPModelTag* _pTriggerSource;
  // The triggerValue data member is used by the StyleProcessor when a data template
  // is parsed. The raw value of the trigger is stored in this data member to be
  // processed later when the StyleProcessor will build the view.
  CATUnicodeString _triggerValue;
  int _tringgeringValueIntFlag;
  friend class CATSYPStyleProcessor;
  friend class CATSYPSaxModelBuilder;
  friend class CATSYPModelTagVisitorBuilder;
  friend class CATSYPDynamicTreeVisitor;
};
#endif
