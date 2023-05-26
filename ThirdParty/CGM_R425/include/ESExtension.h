/**
@file

This file defines a javascript v8 world 

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

#ifndef __ESExtension_h
#define __ESExtension_h

//ES
#include "ESKernelLib.h"
#include "ESObject.h"

//ES
#include "ES_internals.h"


namespace ES {
	
	/**
	DLL entry point called when loading ES extensions from scripting
	*/
	typedef bool (*RegisterFunc)(ES::World* iWorld, ES::Value& oExports, ES::Value& oModule);
	
	/**
	Structure defining a user ES extension
	*/
	class ESKERNEL_API Extension {
	public:
		int version;
		RegisterFunc initFunc;
		const char *name;
		const char *filename;
	};

	/**
	*/
#define ES_EXT_EXPORT DSYExport
#include "DSYExport.h"

	/**
	*/
	#define ES_EXT_DECL(modname) \
		extern "C" ES::Extension modname ## _module;

	/**
	Implement extension 
	@param modname is the DLL name
	@param regfunc the initialisation function 
		bool REGFUNC(ES::Object& oExports)
	*/
	#define ES_EXT_IMPL(modname, regfunc)               \
	  extern "C" {                                        \
		ES_EXT_EXPORT ES::Extension modname ## _module =  \
		{                                                 \
		  ES_VERSION,                                     \
		  (ES::RegisterFunc)regfunc,                      \
		  #modname                                        \
		  __FILE__                                        \
		};                                                \
		ES_EXT_EXPORT ES::Extension* modname ## _get()    \
		{                                                 \
			return & modname ## _module;                  \
		};                                                \
	  }
}

#endif //__ESExtension_h
