/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpComponentInfosDumper_H
#define CATAdpComponentInfosDumper_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
class CATAdpComponentInfos;
class CATPLMTypeH;
class CATOmxKeyValueBlock;

/*
* @nodoc
*/
class ExportedByCATPLMIntegrationAccess CATAdpComponentInfosDumper
{
public:
  CATAdpComponentInfosDumper( const CATAdpComponentInfos & iInfos ) : _Infos(iInfos) {}
  ~CATAdpComponentInfosDumper() {}
  
  CATUnicodeString Dump();
  
private:
  CATAdpComponentInfosDumper(const CATAdpComponentInfosDumper &);
  CATAdpComponentInfosDumper & operator=(const CATAdpComponentInfosDumper &);

  CATUnicodeString ComputeSetDisplay( const CATPLMTypeH & iType, const CATOmxKeyValueBlock & iAttributes, CATBoolean iExtension ) const;
  CATUnicodeString ComputeAttributesDisplay( const CATOmxKeyValueBlock & iAttributes ) const;

private:
  const CATAdpComponentInfos & _Infos;
};
#endif
