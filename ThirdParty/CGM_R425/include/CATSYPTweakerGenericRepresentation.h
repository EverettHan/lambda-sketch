//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/08/13
//===================================================================

#ifndef CATSYPTweakerGenericRepresentation_H
#define CATSYPTweakerGenericRepresentation_H

#include <IntroInfra.h>
#include <CATSYPTweaker.h>
#include <CATUnicodeString.h>
#include <CATISYPIntrospectable.h>

class CATSYPDataBlock;
class CATSYPPropertiesChangedEventArgs;
/**
 *
 */
class ExportedByIntroInfra CATSYPTweakerGenericRepresentation : public CATSYPTweaker
{
  CATDeclareClass;

public:
  /** Default Constructor */
  CATSYPTweakerGenericRepresentation();
  /** Destructor */
  virtual ~CATSYPTweakerGenericRepresentation();

  void SetValueType( const CATUnicodeString& i_valueType, const CATBaseUnknown_var& i_spDefaultValue);

private:
  // Copy constructor and assignement operator are not implemented
  CATSYPTweakerGenericRepresentation(const CATSYPTweakerGenericRepresentation &);
  CATSYPTweakerGenericRepresentation& operator= (const CATSYPTweakerGenericRepresentation &);
};

#endif
