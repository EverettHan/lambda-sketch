// COPYRIGHT DASSAULT SYSTEMES 2015
/**
* quickreview FDN 22:04:25 R424AssessedForLinux (ExportedBy managed by itself)
*/
#ifndef CATCefPlugin_H
#define CATCefPlugin_H

// COPYRIGHT DASSAULT SYSTEMES 2019
#ifdef	_WINDOWS_SOURCE
#ifdef	__CATCefPluginC
#define	ExportedByCATCefPlugin	__declspec(dllexport)
#else
#define	ExportedByCATCefPlugin	__declspec(dllimport)
#endif
#else
#define	ExportedByCATCefPlugin  __attribute__ ((visibility("default")))
#endif

// Plugin versions

// A plugin is not compatible with installs built on a different major version. 
// Inside a same major version, it's only possible to add new optional type 
// definition. Already existing ones cannot be modified.
#define PLUGIN_CEF_VERSION_MAJ 3

// A plugin is compatible with installs built with a lower minor version. 
//
// If a new type is added to the plugin APIs set, its minor version must be increased. 
// Warning, calling this new type must be optional instead of this plugin wont be compatible
// with lower minor version installs
//
// But the plugin is not compatible with installs built with a upper minor version.
// This guarantees an optional type present when the installs has been built will be
// still present in the next minor version plugins
#define PLUGIN_CEF_VERSION_MIN 0

// Calling convention : Pascal mode on windows
#ifdef _WINDOWS_SOURCE
#define CONV_CALL __stdcall
#else
#define CONV_CALL
#endif

extern "C" {

  // The only method exported by the plugin. 
  // It's the general factory method 
  // Mainly used to create a catcefglobal_c object but also for other types in the future ...
  // iComponentName is the name of the expected structure that will be returned by the method
  // for example : 
  //   catcefglobal_c * sGlobal = catcef_pluginfactory(PLUGIN_CEF_VERSION_MAJ,PLUGIN_CEF_VERSION_MIN,"catcefglobal_c");
  ExportedByCATCefPlugin void * CONV_CALL catcef_pluginfactory(int iClientMajorVersion, int iClientMinorVersion, const char * iComponentName); 
}

#endif
