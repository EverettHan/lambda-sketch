#ifndef CATSYPResourcesBuilder_H
#define CATSYPResourcesBuilder_H

#include <CATStyleProcessor.h>
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_var.h>
#include <CATSYPFactoryResult.h>
class CATUnicodeString;
class CATSYPInputStream;
/**
 * Abstract class for ressource builder. Inherit this class to build a specific resource type.
 * A resources builder can be used directly, or can be added to a CATResourcesFinder.
 * @see CATResourcesFinder
 */
class ExportedByCATStyleProcessor CATSYPResourcesBuilder : public CATBaseUnknown
{
public:
  /** Constructor */
  CATSYPResourcesBuilder();
  /**
   * Builds a resource for a given stream.
   * @param the absolute path where the resource is located.
   */
  virtual CATSYPFactoryResult Build(CATSYPInputStream& i_stream, int i_size) const = 0;
protected:
  /** Destructor */
  ~CATSYPResourcesBuilder();
private:
};
#endif
