/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeHDumper_H
#define CATPLMTypeHDumper_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeH.h"
class CATUnicodeString;

/**
 * Class enabling to dump debug informations for a PLM type definition.
 * <br><b>Role</b>: Given a PLM type, this class enables to dump debug information about it.
 */
class CATPLMTypeHDumper
{
public:
  inline CATPLMTypeHDumper(const CATPLMTypeH & iType) :_TypeHandle(iType) {}

  /**
   * Dumps useful information for identification of a PLM Type.
   * <br><b>Role:</b>This method enables to dump useful information for identification of a PLM Type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the PLM type is part of a packaged Modeler.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess CATUnicodeString Dump() const;

private:
  const CATPLMTypeH _TypeHandle;
};
#endif
