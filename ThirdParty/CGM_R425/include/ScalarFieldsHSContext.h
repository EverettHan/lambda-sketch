#ifndef __ScalarFieldsHSContext_h
#define __ScalarFieldsHSContext_h

#include "CATBaseUnknown.h"
#include "CATUuid.h"

#include <memory>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include <ostream>
#include <atomic>
#include <mutex>

#include "ScalarFieldsHSFunction.h"


namespace hs {

  /**
   * ScalarFieldsHSContext will manage loading and unloading of libraries and offer basic services to register
   * functions by their name.
   *
   * This is useful for example when you need to handle GPGPU code. Even CUDA tends to be tricky and you might end
   * up in situations in which you dynamic libraries relying on CUDA won't load. So in order to ensure that 
   * we don't break ever we do rely on loading the libraries dynamically and making those functionalities
   * available to operators only if they have loaded and registered correctly.
   *
   * This can be useful in other contexts to, for example if you want to be able to update code without
   * having to launch your test app (ex. PolyhedralVisuAppli) or the 3DExp each time you recompile.
   * (Obviously you should refrain to change anything else than operator code (ex. don't change data structures)
   * if you want to do that type of things check 3DVIA Studio Kernel manager which had a complete logic to update
   * these, at the cost of quite complex code that we don't need here).
   */
	ExportedByScalarFieldsHSFunctions class ScalarFieldsHSContext
	{
	public:
    ScalarFieldsHSContext()
      {
      }

		~ScalarFieldsHSContext()
      {
      }

    /**
     * Will load the library and call it's exported function attachFunctions passing
     * this as argument.
     */
    ExportedByScalarFieldsHSFunctions HRESULT AttachLibrary(const std::string& iPathName, const std::string& iLibName);

    /**
     * Will call the library exported function detachFunctions passing this as argument.
     */
    ExportedByScalarFieldsHSFunctions HRESULT DetachLibrary(const std::string& iPathName, const std::string& iLibName);

    /**
     * Call this method to register one of your library functions under a specific name.
     * Usually you will call this method in your library attachFunctions exported function.
     */
    ExportedByScalarFieldsHSFunctions HRESULT AttachFunction(const std::string& iFullName, std::unique_ptr<ScalarFieldsHSFunction>& iFunction);

    /**
     * Call this method to unregister one of your library functions that you have previously registered
     * under a specific name.
     * Usually you will call this method in your library detachFunctions exported function.
     */
    ExportedByScalarFieldsHSFunctions HRESULT DetachFunction(const std::string& iFullName);

    /**
     * Call this method to execute a function specified via text. The arguments
     * have to be provided too.
     * For example if you had attach a print function you could execute it by
     * passing 'print(text)'
     * You have to provide an activity even though it is a freshly created one
     */
    ExportedByScalarFieldsHSFunctions HRESULT Execute(const std::string& iCode, ScalarFieldsHSActivity& ioActivity);

    /**
     * Get a registered function by its name.
     */
    ExportedByScalarFieldsHSFunctions HRESULT GetFunction(const std::string& iFullName, void** oFunction);

	protected:
    std::map<std::string, std::unique_ptr<ScalarFieldsHSFunction>>      functions;
    std::vector<std::string>                                            libraries;
    std::recursive_mutex                                                functions_mutex;
	};
}

static std::atomic<hs::ScalarFieldsHSContext*> defaultContext = nullptr;

ExportedByScalarFieldsHSFunctions hs::ScalarFieldsHSContext* GetDefaultScalarFieldsHSContext();
ExportedByScalarFieldsHSFunctions void                       ReleaseDefaultScalarFieldsHSContext();


#endif __ScalarFieldsHSContext_h

