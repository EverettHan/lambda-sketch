/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeProtectedSpecificModelers_H
#define CATPLMTypeProtectedSpecificModelers_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeProtectedDescriptor.h"

 /**
  * @nodoc
  */
class CATPLMTypeProtectedSpecificModelers : public CATPLMTypeProtectedDescriptor
{
public:
  inline CATPLMTypeProtectedSpecificModelers(const CATPLMTypeH & iType) : CATPLMTypeProtectedDescriptor(iType) {}

  /**
   * Hardcodes on some modelers
   * usage is absolutely forbidden outside infrastructure (integration, identification etc...)
   */
  ExportedByCATPLMIdentificationAccess HRESULT IsConfigurationConnection() const;
  ExportedByCATPLMIdentificationAccess HRESULT IsPrivateRepresentation() const;
  ExportedByCATPLMIdentificationAccess HRESULT IsFromCatalogModeler() const;
  ExportedByCATPLMIdentificationAccess HRESULT IsFromFolderModeler() const;
  ExportedByCATPLMIdentificationAccess HRESULT IsFromDWSModeler() const;
  ExportedByCATPLMIdentificationAccess HRESULT IsFromTestModeler() const;
  ExportedByCATPLMIdentificationAccess HRESULT IsNotMigratedComponent() const;

  inline ~CATPLMTypeProtectedSpecificModelers() {}
private:
  CATPLMTypeProtectedSpecificModelers(const CATPLMTypeProtectedSpecificModelers &);
  CATPLMTypeProtectedSpecificModelers & operator =(const CATPLMTypeProtectedSpecificModelers &);
};
#endif
