/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESFunction_h
#define __ESFunction_h

//ES
#include "ESKernelLib.h"
#include "ESException.h"
#include "ESObject.h"

//CAT
#include "DSYString.h"

namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES object
	*/
	class ESKERNEL_API Function : public ES::Object {

		public:
			
			/**
			Copy constructor
			*/
			Function(const ES::Function& iFunction);

			/**
			Destructor
			*/
			virtual ~Function() {}

			/**
			Cast given value to Function
			*/
			static ES::Function Cast(const ES::Value& iValue);

			/**
			Create a function with a body and some arguments
			iBody is the javascript statements of the function, without any header 
			iParams are the name of the arguments (must be a valid JavaScript identifier)
			*/
			static ES::Function New(ES::World* iWorld, const ES::String& iBody);
			static ES::Function New(ES::World* iWorld, const ES::String& iBody, const ES::String& iParam1);
			static ES::Function New(ES::World* iWorld, const ES::String& iBody, const ES::String& iParam1, const ES::String& iParam2);
			static ES::Function New(ES::World* iWorld, const ES::String& iBody, const ES::String& iParam1, const ES::String& iParam2, const ES::String& iParam3);
			static ES::Function New(ES::World* iWorld, const ES::String& iBody, const ES::String& iParam1, const ES::String& iParam2, const ES::String& iParam3, const ES::String& iParam4);
			static ES::Function New(ES::World* iWorld, const ES::String& iBody, const std::vector<ES::String>& iArgs);

			/**
			Returns the function name
			*/
			CATUnicodeString GetName() const; 
			
			/**
			New API
			Set the function name
			*/
			void SetName(const CATUnicodeString& iName);

			/**
			Call method helper
			*/
			ES::Value Call(const ES::Object& iThis, ES::Exception* oException = nullptr) const;
			ES::Value Call(const ES::Object& iThis, const ES::Value& iParam1, ES::Exception* oException = nullptr) const;
			ES::Value Call(const ES::Object& iThis, const ES::Value& iParam1, const ES::Value& iParam2, ES::Exception* oException = nullptr) const;
			ES::Value Call(const ES::Object& iThis, const ES::Value& iParam1, const ES::Value& iParam2, const ES::Value& iParam3, ES::Exception* oException = nullptr) const;
			ES::Value Call(const ES::Object& iThis, const ES::Value& iParam1, const ES::Value& iParam2, const ES::Value& iParam3, const ES::Value& iParam4, ES::Exception* oException = nullptr) const;
			
			/**
			Call functions helper
			*/
			ES::Value Call(ES::Exception* oException = nullptr) const;
			ES::Value Call(const ES::Value& iParam1, ES::Exception* oException = nullptr) const;
			ES::Value Call(const ES::Value& iParam1, const ES::Value& iParam2, ES::Exception* oException = nullptr) const;
			ES::Value Call(const ES::Value& iParam1, const ES::Value& iParam2, const ES::Value& iParam3, ES::Exception* oException = nullptr) const;
			ES::Value Call(const ES::Value& iParam1, const ES::Value& iParam2, const ES::Value& iParam3, const ES::Value& iParam4, ES::Exception* oException = nullptr) const;
			ES::Value Call(const std::vector<ES::Value>& iArgs, ES::Exception* oException = nullptr) const;

			/**
			Call as constructor helper
			*/
			ES::Object CallAsConstructor(ES::Exception* oException = nullptr) const;
			ES::Object CallAsConstructor(const ES::Value& iParam1, ES::Exception* oException = nullptr) const;
			ES::Object CallAsConstructor(const ES::Value& iParam1, const ES::Value& iParam2, ES::Exception* oException = nullptr) const;
			ES::Object CallAsConstructor(const ES::Value& iParam1, const ES::Value& iParam2, const ES::Value& iParam3, ES::Exception* oException = nullptr) const;
			ES::Object CallAsConstructor(const ES::Value& iParam1, const ES::Value& iParam2, const ES::Value& iParam3, const ES::Value& iParam4, ES::Exception* oException = nullptr) const;

			/**
			Generic caller
			*/
			ES::Value Call(const ES::Object& iThis, const std::vector<ES::Value>& iArgs, ES::Exception* oException = nullptr) const;
			ES::Object CallAsConstructor(const std::vector<ES::Value>& iArgs, ES::Exception* oException = nullptr) const;
			
			/**
			Affect operator
			*/
			ES::Function& operator=(const ES::Function& iValue);

			

		private:


			static void s_JSFunctionCallback(const v8::FunctionCallbackInfo<v8::Value>& info);
			
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Function)
	};

}

#endif //__ESFunction_h
