/**
@file

This file defines a javascript v8 world 

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

#ifndef __ESWorld_h
#define __ESWorld_h

//ES
#include "ESKernelLib.h"
#include "ESBinder.h"
#include "ESScript.h"

//CAT
#include "DSYString.h"

namespace ES {

	/**
	Forward declaration
	*/
	class Universe;
	class Exception;
	
	/**
	A world represent one ES execution environment.
	A World can be entered by at most one thread at any	given time, since it is internally locked.
	*/
	class ESKERNEL_API World
	{
	 public:

			/**
			Retrieve the global ES object. 
			After compiling AND running script (or evaluating), it will declare functions and object in the current world's global object.
			@return the ES world global object
			*/
			virtual ES::Object GetGlobal() = 0;
		
			/**
			Creates a new script.
			@param iScriptKey the key (unique id) of the script. For instance, this id is used when adding breakpoints.
			@param iScriptSource the source of the script to compile
			@param oException optional exception that will be filled (if non null pointer) when an exception is raised during compilation.
			@return the compiled script if successful, empty script object in case of syntax errors.
			*/
			virtual ES::Script CreateScript(const CATUnicodeString& iScriptKey, const CATUnicodeString& iScriptSource, ES::Exception* oException = nullptr) = 0;

			/**
			Evaluates given source code. 
			@param iScriptSource the source of the script to compile
			@param oException optional exception that will be filled (if non null pointer) when an exception is raised during compilation.
			@param iLocal to true means the code will be executed in a scope
			*/
			virtual ES::Value Evaluate(const CATUnicodeString& iScriptSource, ES::Exception* oException = nullptr) = 0;

			/**
			Get the binder for this world.
			*/
			virtual Binder* GetBinder() const = 0;

			/**
			Get the universe this world belongs to.
			*/
			virtual Universe* GetUniverse() const = 0;
			
			/**
			Process pending debugger messages
			*/
			ES_DEPRECATED("2020/06/24", "Obsolete API with new debug mode", virtual void ProcessDebugMessages() = 0;)

			/**
			Get the world's name.
			*/
			CATUnicodeString GetName() const ; 

			/**
			Get the current world.
			@returns the world from the ES Caller, NULL otherwise
			*/
			static ES::World* GetCurrent();

			/**
			Wait for async jobs (created by async require for instance)
			*/
			virtual void WaitWorkers() = 0;

	protected:

			/**
			Only ES::Universe can construct World instances
			@see ES::Universe::GetWorld
			*/
			World(const CATUnicodeString& iName);

			/**
			Only ES::Universe can destruct World instances
			@see ES::Universe::DisposeWorld
			*/
			virtual ~World() {}

			/**
			*/
			virtual bool UnInitialize() = 0;
			
	protected:

			/**
			The world's name
			*/
			CATUnicodeString m_Name;
	};

}

#endif //__ESWorld_h
