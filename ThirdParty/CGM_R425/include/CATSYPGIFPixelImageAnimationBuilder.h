#ifndef CATSYPGIFPixelImageAnimationBuilder_H
#define CATSYPGIFPixelImageAnimationBuilder_H

#include <VisuDialog.h>
#include <CATSYPResourcesBuilder.h>
#include <CATBaseUnknown_var.h>
#include <CATSYPFactoryResult.h>
class CATUnicodeString;
class CATSYPInputStream;
/**
 * Class used to build CATPixelIlmage. Inherit this class to build a specific resource type.
 */
class ExportedByVisuDialog CATSYPGIFPixelImageAnimationBuilder : public CATSYPResourcesBuilder
{
public:
  /** Constructor */
  CATSYPGIFPixelImageAnimationBuilder();
  /**
   * @copydoc CATSYPResourcesBuilder#Build
   */
  virtual CATSYPFactoryResult Build(CATSYPInputStream& i_absolutePath, int i_size) const;
protected:
  /** Destructor*/
  virtual ~CATSYPGIFPixelImageAnimationBuilder();
private:
};
#endif
