#ifndef CATSYPPixelImageBuilder_H
#define CATSYPPixelImageBuilder_H

#include <VisuDialog.h>
#include <CATSYPResourcesBuilder.h>
#include <CATBaseUnknown_var.h>
class CATUnicodeString;
class CATSYPInputStream;
/**
 * Class used to build CATPixelIlmage. Inherit this class to build a specific resource type.
 */
class ExportedByVisuDialog CATSYPPixelImageBuilder : public CATSYPResourcesBuilder
{
public:
  /** Constructor */
  CATSYPPixelImageBuilder();
  /**
   * @copydoc CATSYPResourcesBuilder#Build
   */
  virtual CATSYPFactoryResult Build(CATSYPInputStream& i_absolutePath, int i_size) const;
protected:
  /** Destructor*/
  virtual ~CATSYPPixelImageBuilder();
private:
};
#endif
