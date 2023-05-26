/**
@file

This file defines a javascript v8 isolated Universe 

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

#ifndef __ESUniverse_h
#define __ESUniverse_h

//ES
#include "ESKernelLib.h"
#include "ESWorld.h"

//CAT
#include "DSYString.h"

namespace ES {

	/**
	Forward declaration
	*/
	class Binder;
	class Universe;
	//class CpuProfiler;
	//class HeapProfiler;

	/**
	The different mode for debuggers 
		eNoDebug                   : no debugger
		eDebugAndBreakOnFirstEnter : The debugger is activated ; it will wait for user action the first time it enters in a JS statement
		eDebugAndBreakOnAllEnters  : The debugger is activated ; it will wait for user action each time the scenario enter in a JS statement
 	*/ 
	enum class EDebugMode
	{	
		eNoDebug,
		eDebugAndBreakOnFirstEnter,
		eDebugAndBreakOnAllEnters
	} ;
	
	/**
	Universe represents a sandboxed instance of the ES engine. It is used as a ES::World factory to create/destroy worlds instances.
	ES universes have completely separate states. Objects from one Universe	MUST not be used in other Universes. 
	The embedder can create additional universes and use them in simultaneously in parallel in multiple threads. 
	*/
	class ESKERNEL_API Universe
	{
	 public:
			
			/**
			This function allows to enable/disable showing dialogs on ES api and internal errors.
			It must be called before Unviverse and world creation to be taken in account.
			*/
			static void ShowErrorDialogs(bool iShow = true);
			
			/**
			Set the port of the communication channel that will used between V8 sessions and the attached debuggers 
			Usefull when the default port is already in used (e.g. port 9229 already used by a node debugging session)
			Warning, the call will fail if there is a session waiting for a debug communication channel
			Returns the port in used.
			*/
			static int SetPortForDebugCommunications(int iPort );

			/**
			Get a description of the engine (name, version)
			@return the engine description (hidden implementation engine)
			*/
			static CATUnicodeString Description();

			/**
			This function allows to enable/disable showing debug logs.
			*/
			static void ShowDebugLogs(bool iShow);
			static bool s_DebugLogs;
			
			/**
			Create a world. The world is the entrypoint for ES execution.
			@param iName the world name
			@param if iDebugMode is specified, it overwrites the universe debug mode for this specific world.				 
			@return NULL if iName was the name of an already existing world else the new created world.
			*/
			virtual World* CreateWorld(const CATUnicodeString& iName, EDebugMode * iDebugMode=nullptr, ES::Binder * iBinder=nullptr) = 0;
			
			/**
			Get or create a world. The world is the entrypoint for ES execution.
			@param iName the world name
			@return the created world if no world with this names exists, or an existing world otherwise
			*/
			virtual World* GetWorld(const CATUnicodeString& iName) = 0;
			
			/**
			Check if a world already exists in this universe
			@param iWorldName the world name
			@return true if the given world is already defined in the universe
			*/
			virtual bool Has(const CATUnicodeString& iWorldName) = 0;

			/**
			Delete a world.
			After calling DeleteWorld, the world should not be used anymore.
			*/
			virtual bool DeleteWorld(const CATUnicodeString& iName) = 0;

			/**
			Deprecated please use ES::EDebugMode at universe or world creation
			*/
			ES_DEPRECATED("2020/06/24", "Please use ES::Universe::Factory::New with EDebugMode", virtual bool StartEKDebuggerServer(const CATUnicodeString& iName , bool iWaitForConnection = false, int iWebPort = 2099, int iPort = -1) = 0;)
			ES_DEPRECATED("2020/06/24", "Please use ES::Universe::Factory::New with EDebugMode", virtual bool StartEKDebuggerServer(int iPort = -1 ,bool iWaitForConnection = false ) = 0;)
			ES_DEPRECATED("2020/06/24", "Obsolete API with new debug mode", virtual int  GetEKDebuggerPort() = 0;)
			ES_DEPRECATED("2020/06/24", "Obsolete API with new debug mode", virtual bool StopEKDebuggerServer() = 0;)
			ES_DEPRECATED("2020/06/24", "Please use ES::Universe::Factory::New with EDebugMode", virtual bool StartDebuggerServer(const CATUnicodeString& iName = "127.0.0.1", unsigned short iPort = 9222, bool iWaitForConnection = false ) = 0;)
			ES_DEPRECATED("2020/06/24", "Obsolete API with new debug mode", virtual bool StopDebuggerServer() = 0;)
			ES_DEPRECATED("2020/06/24", "Obsolete API with new debug mode", virtual void DebugBreak() = 0;)
			ES_DEPRECATED("2020/06/24", "Obsolete API with new debug mode", virtual void CancelDebugBreak() = 0;)

			/**
			Force ES garbage collection.
			Gargabe callection will clear ES values that are still alive but that are no more referenced within ES.
			*/
			virtual void CollectGarbage() = 0;

			/**
			Forcefully terminate the current world of ES execution.
			*/
			virtual void TerminateExecution() = 0;

			/**
			Returns true if ES execution is currently terminating because of a call to TerminateExecution. 
			*/
			virtual bool IsExecutionTerminating() = 0;
			
			/**
			Returns true if ES is running in another thread. If ES is running in the 
			current thread it will return false, it can only happens with reentrant calls
			(which is bad and should not happen)
			*/
			virtual bool IsRunning() = 0;

			virtual void RunMicroTasks() = 0;
			
			/**
			*/
			typedef void (*CallCompletedCallback)();
			
			/**
			Adds a callback to notify the host application when a script finished
			running.	If a script re-enters the runtime during executing, the
			CallCompletedCallback is only invoked when the outer-most script
			execution ends.	Executing scripts inside the callback do not trigger
			further callbacks.
			*/
			//virtual void AddCallCompletedCallback(CallCompletedCallback callback) = 0;

			/**
			Removes callback that was installed by AddCallCompletedCallback.
			*/
			//virtual void RemoveCallCompletedCallback(CallCompletedCallback callback) = 0;

			/**
			This class defines a universe factory.
			Create a factory instance, and use it to create/destroy universe instances.
			*/
			class ESKERNEL_API Factory {
			
				public:

					/**
					Factory constructor
					*/
					Factory();

					/**
					Factory destructor
					*/
					~Factory();

					/**
					Creates a new Universe
					@param iDebugMode speficies the default debugmode for each world the universe will create.						 
					*/
					ES::Universe* New(EDebugMode iDebugMode=EDebugMode::eNoDebug);

					/**
					Deletes a universe. 
					After calling this method, the universe may have been deleted (in case no one uses it anymore),
					and should not be used anymore.
					*/
					bool Delete(ES::Universe* oUniverse);
					
				private:

					/**
					Created universes 
					*/
					std::vector<ES::Universe*> m_Universes;
			};
			
	protected:

			/**
			Only ES::Universe can construct Universe instances
			@see New
			*/
			Universe();
	
			/**
			Only ES::Universe can destruct Universe instances
			@see Dispose
			*/
			virtual ~Universe() {}

			/**
			*/
			virtual void UnInitialize() = 0;
	};
}

#endif //__ESUniverse_h
