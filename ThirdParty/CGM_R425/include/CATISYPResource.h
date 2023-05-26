#ifndef CATISYPResource_H
#define CATISYPResource_H

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
class CATString;

extern ExportedByIntroInfra IID IID_CATISYPResource;

/**
 * Interface allowing to declare resource file, for internationalization.
 **/
class ExportedByIntroInfra CATISYPResource : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * @return the resource filename used by the object. 
   * This method has to overloaded by the implmentation of the interface
   * by using the macro CAT_DECLARE_RESOURCE
	 **/
  virtual char* GetResourceFilename(int i_depth) const = 0;
  /**
   * @return a resource ID, used to build unique object path, associated 
   * to string in the resource files. Used by internationalization algorithm.
   */
  virtual CATString& GetResourceID() = 0;
};

CATDeclareHandler( CATISYPResource, CATBaseUnknown );

#endif

