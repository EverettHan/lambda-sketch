/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESNativeObject_h
#define __ESNativeObject_h

//ES
#include "ESKernelLib.h"
#include "ESObject.h"
#include "ESString.h"
#include "ESType.h"


namespace ES {

	//Forward delcation
	class World;
	class Class;

	/**
	Abstract class describing a ES native object
	*/
	class ESKERNEL_API NativeObject : public ES::Object {

		public:

			/**
			Callback used to get informed when the instance is no more references by ES (ie call a destructor on the instance)
			*/
			typedef void (*DestructorCallBack)(void* instance);

			/**
			Copy constructor
			*/
			NativeObject(const ES::NativeObject& iObject);
			
			/**
			Destructor
			*/
			virtual ~NativeObject() {}
			
			/**
			Create a javascript object wrapping this native cpp class instance (T*). 
			This kind of object could be given to a native function waiting for a T& or a T* as parameter.
			@param iWorld the world owning this native object
			@param iType the native object class type
			@param iInstance the native cpp instance
			@param iDestructorCallback an optional callback that will be triggered when the object is no more referenced by ES
			*/
			static ES::NativeObject New(ES::World* iWorld, const ES::Class& iType, void* iInstance, DestructorCallBack iDestructorCallback = nullptr);
			
			/**
			Create a pointer to a javascript object wrapping this native cpp class instance (T*). 
			This kind of object could be given to a native function waiting for a T& or a T* as parameter.
			@param iWorld the world owning this native object
			@param iType the native object class type
			@param iInstance the native cpp instance
			@param iDestructorCallback an optional callback that will be triggered when the object is no more referenced by ES

			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::NativeObject* NewPtr(ES::World* iWorld, const ES::Class& iType, void* iInstance, DestructorCallBack iDestructorCallback = nullptr);

			/**
			Create a javascript object wrapping this native cpp class instance (T*). 
			This kind of object could be given to a native function waiting for a T& or a T* as parameter.
			@param iTypeName the native object class type (without qualifiers)
			*/
			static ES::NativeObject New(ES::World* iWorld, const char* iTypeName, void* iInstance, DestructorCallBack iDestructorCallback = nullptr);

			/**
			Create a pointer to a javascript object wrapping this native cpp class instance (T*). 
			This kind of object could be given to a native function waiting for a T& or a T* as parameter.
			@param iTypeName the native object class type (without qualifiers)

			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::NativeObject* NewPtr(ES::World* iWorld, const char* iTypeName, void* iInstance, DestructorCallBack iDestructorCallback = nullptr);

			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::NativeObject Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::NativeObject& operator=(const ES::NativeObject& iValue);
			
		public:

			/**
			INTROSPECTION
			*/

			/**
			Get the native CPP instance
			*/
			void* GetInstance();

			/**
			Get the type of the instance
			*/
			ES::Type GetType();
			
		private:
		
			/**
			Internal
			*/
			ESNATIVEOBJECT_INTERNAL_CONSTRUCTOR()
	};

}

#endif //__ESNativeObject_h
