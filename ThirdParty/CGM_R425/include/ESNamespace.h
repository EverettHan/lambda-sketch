/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESNamespace_h
#define __ESNamespace_h

//ES
#include "ESKernelLib.h"
#include "ESSignature.h"
#include "ESType.h"
#include "ES_internals.h"

//CAT
#include "DSYString.h"

namespace ES {

	/**
	Namespace describing a ES Namespace
	*/
	class ESKERNEL_API Namespace {

		public:

			/**
			Copy constructor
			*/
			Namespace(const ES::Namespace& iType);

			/**
			Destructor
			*/
			virtual ~Namespace();
			
			/**
			Affect operator
			*/
			Namespace& operator=(const Namespace& iType);
			
			/**
			Clears the type
			*/
			void Clear();

			/**
			Get the world this value came from
			*/
			ES::World* GetWorld() const { return m_World; }

			/**
			Test weather the namespace points to a constructed namespace implementation. Namespaces can be seen as Ptr to a namespace implementation (ES Object)
			*/
			bool IsValued() const;
			
			/**
			Commits modifications done to the namespace. After the namespace hase been committed, all function added to the namespace will be available in scripting.
			It is allowed to commit same namespaces multiple times (on the contrary to types).
			*/
			bool Commit(ES::Object iRoot);
			bool Commit();

			/**
			Commits all modification done to the namespace AND recursively seal all not sealed classes.
			*/
			bool DeepSeal(ES::Object iRoot);
			bool DeepSeal();

		public:
			
			/**
			INTROSPECTION
			*/
			
			/**
			Get the type name
			*/
			CATUnicodeString GetName() const;
			
			/**
			Get the type complete name including NS
			*/
			CATUnicodeString GetCompleteName() const;
			
			/**
			Get the owner namespace
			*/
			Namespace GetOwnerNamespace() const;

			/**
			Get the number of type declared in this namespace
			*/
			unsigned int GetTypeCount() const;
			
			/**
			Get a type by index.
			@param iIndex the type index

			@see ES::Namespace::GetTypeCount
			*/
			Type GetTypeByIndex(unsigned int iIndex) const; 
				
			/**
			Get the number of NS declared in this namespace
			*/
			unsigned int GetNamespaceCount() const;
			
			/**
			Get a namespace by index.
			@param iIndex the namespace index

			@see ES::Namespace::GetNamespaceCount
			*/
			Namespace GetNamespaceByIndex(unsigned int iIndex) const; 
				
			/**
			Get the number of Functions declared in this namespace
			*/
			unsigned int GetFunctionCount() const ;

			/**
			Get a function by index.
			@param iIndex the function index
			
			@see ES::Namespace::GetFunctionCount
			*/
			Signature GetFunctionByIndex(unsigned int iIndex) const; 

			/**
			Get a function description by name
			@param the function name
			*/
			Signature GetFunction(const char* iName) const;
			
			/**
			Get an inner type description by name
			@param inner type name
			*/
			Type GetType(const char* iName) const;

		public:
			
			/**
			MODIFICATION
			*/
			
			/**
			Register a function in this namespace.
			
			@param iReturnType the function return type name
			@param iName the function name
			@param iPointer the function native pointer
			@param iParams a vector containing the type of the parameters the function expect 
			*/
			
			Signature AddFunction(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const std::vector<const char*>& iParams);
			Signature AddFunction(const char* iReturnType, const char* iName, const FunctionPtr& iPointer);
			Signature AddFunction(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const char* iParam1);
			Signature AddFunction(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const char* iParam1, const char* iParam2);
			Signature AddFunction(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const char* iParam1, const char* iParam2, const char* iParam3);
			Signature AddFunction(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const char* iParam1, const char* iParam2, const char* iParam3, const char* iParam4);

		public:
		
			/**
			New API
			Dumps the namespace to a string
			*/
			void Dump(CATUnicodeString& out);

		protected:

			/**
			Register a function that will receive as argument the list of argument given by ES as a ES::Array

			@param iName the function name
			@param iPointer the function native pointer. 
			
			The native function MUST have this prototype: 
			@code ES::Value* GenericFunction(const ES::Array& iParams) {...}
			*/
			Signature AddGenericFunction(const char* iName, const FunctionPtr& iPointer);
			
		protected:
			
			/**
			DELETION
			*/
			
			/**
			Removes a registered function
			*/
			bool RemoveFunction(const char* iName);
			
		private:
		
			/**
			*/
			ES::World* m_World;

			/**
			Internal
			*/
			ESNAMESPACE_INTERNAL_DEFINITION
	};

}

#endif //__ESNamespace_h

