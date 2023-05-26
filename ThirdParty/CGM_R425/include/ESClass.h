/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESClass_h
#define __ESClass_h

//ES
#include "ESKernelLib.h"
#include "ESSignature.h"
#include "ESProperty.h"
#include "ESType.h"
#include "ES_internals.h"
#include "ESNamespace.h"


namespace ES {
	
	/**
	Useful macro to declare constructor/destructor functions for classes
	*/
	
	/**
	Construct a function which operator new.
	Version up to to 6 parameters on a the class parameter.
	The function will be called __newT
	*/
	#define ES_DECLARE_CONSTRUCTOR(class)								class* __new##class(){ return new class;}
	#define ES_DECLARE_CONSTRUCTOR_1P(class, t1)						class* __new##class(t1 iP1){ return new class(iP1);}
	#define ES_DECLARE_CONSTRUCTOR_2P(class, t1, t2)					class* __new##class(t1 iP1, t2 iP2){ return new class(iP1, iP2);}
	#define ES_DECLARE_CONSTRUCTOR_3P(class, t1, t2, t3)				class* __new##class(t1 iP1, t2 iP2, t3 iP3){ return new class(iP1, iP2, iP3);}
	#define ES_DECLARE_CONSTRUCTOR_4P(class, t1, t2, t3, t4)			class* __new##class(t1 iP1, t2 iP2, t3 iP3, t4 iP4){ return new class(iP1, iP2, iP3, iP4);}
	#define ES_DECLARE_CONSTRUCTOR_5P(class, t1, t2, t3, t4, t5)		class* __new##class(t1 iP1, t2 iP2, t3 iP3, t4 iP4, t5 iP5){ return new class(iP1, iP2, iP3, iP4, iP5);}
	#define ES_DECLARE_CONSTRUCTOR_6P(class, t1, t2, t3, t4, t5, t6)	class* __new##class(t1 iP1, t2 iP2, t3 iP3, t4 iP4, t5 iP5, t6 iP6){ return new class(iP1, iP2, iP3, iP4, iP5, iP6);}

	/**
	Macro for inner classes T::U
	*/
	#define ES_DECLARE_INNERCONSTRUCTOR(class, classi)								class* __new##class##_##classi(){ return new class::classi;}
	#define ES_DECLARE_INNERCONSTRUCTOR_1P(class, classi, t1)						class* __new##class##_##classi(t1 iP1){ return new class::classi(iP1); }
	#define ES_DECLARE_INNERCONSTRUCTOR_2P(class, classi, t1, t2)					class* __new##class##_##classi(t1 iP1, t2 iP2){ return new class::classi(iP1, iP2);}
	#define ES_DECLARE_INNERCONSTRUCTOR_3P(class, classi, t1, t2, t3)				class* __new##class##_##classi(t1 iP1, t2 iP2, t3 iP3){ return new class::classi(iP1, iP2, iP3);}
	#define ES_DECLARE_INNERCONSTRUCTOR_4P(class, classi, t1, t2, t3, t4)			class* __new##class##_##classi(t1 iP1, t2 iP2, t3 iP3, t4 iP4){ return new class::classi(iP1, iP2, iP3, iP4);}
	#define ES_DECLARE_INNERCONSTRUCTOR_5P(class, classi, t1, t2, t3, t4, t5)		class* __new##class##_##classi(t1 iP1, t2 iP2, t3 iP3, t4 iP4, t5 iP5){ new class::classi(iP1, iP2, iP3, iP4, iP5);}
	#define ES_DECLARE_INNERCONSTRUCTOR_6P(class, classi, t1, t2, t3, t4, t5, t6)	class* __new##class##_##classi(t1 iP1, t2 iP2, t3 iP3, t4 iP4, t5 iP5, t6 iP6){ new class::classi(iP1, iP2, iP3, iP4, iP5, iP6);}

	/**
	Construct a function which call delete operator on the given class instance
	The function will be called __deleteT
	*/
	#define ES_DECLARE_DESTRUCTOR(class)	void __delete##class(class *iObj){if (iObj) delete iObj;}

	/**
	Class describing a ES Class
	*/
	class ESKERNEL_API Class : public Type {

		public:

			/**
			Copy constructor
			*/
			Class(const ES::Class& iType);

			/**
			Destructor
			*/
			virtual ~Class();
			
			/**
			Affect operator
			*/
			Class& operator=(const Class& iType);
			
			/**
			Cast given type to a class
			*/
			static ES::Class Cast(const ES::Type& iType);

		public:

			/**
			INTROSPECTION
			*/
			
			/**
			Get the owner namespace of this type.
			Returns a valued namespace if this type has been declared in a namespace.
			IE: A::B with 'A' being a Namespace.
			*/
			Namespace GetOwnerNamespace() const;
			
			/**
			Get the owner type of this type.
			Returns a valued type if this type is an inner type.
			IE: A::B with 'A' being a Type.
			*/
			Type GetOwnerType() const;
			
			/**
			Tells if objects of this type can not be instantiated
			*/
			bool IsAbstract() const;

			/**
			Get the number of type declared in this namespace
			*/
			unsigned int GetTypeCount() const;
			
			/**
			Get a type by index.
			*/
			Type GetTypeByIndex(unsigned int iIndex) const; 
			
			/**
			Get type by name
			*/
			Type GetType(const char* iName) const;

			/**
			Get the number of Functions declared in this namespace
			*/
			unsigned int GetMethodCount() const ;

			/**
			Get a function by index.
			*/
			Signature GetMethodByIndex(unsigned int iIndex) const; 

			/**
			Get the number of properties
			*/
			unsigned int GetPropertyCount() const; 
			
			/**
			Get the number of properties added to this type only.
			*/
			unsigned int GetSelfPropertyCount() const; 

			/**
			Get a property by index.
			*/
			Property GetPropertyByIndex(unsigned int iIndex) const; 
			
			/**
			Get a property by index (only on this level properties).
			*/
			Property GetSelfPropertyByIndex(unsigned int iIndex) const; 

			/**
			Get a property by index.
			*/
			Property GetPropertyByName(const char* iName) const; 

			/**
			Get parent class.
			*/
			Class GetParent() const; 

			/**
			Get the class size
			*/
			unsigned int GetSize() const;

			/**
			Get a method by name
			*/
			Signature GetMethod(const char* iName) const;

			/**
			Get the binded class constructor function description
			*/
			Signature GetConstructor() const;

			/**
			Get the binded class constructor function description
			*/
			Signature GetDestructor() const;

		public:
			
			/**
			MODIFICATION
			*/
			
			/**
			Function special
			*/
			enum EMethodKind {
				eMethod,					// Normal method
				eVirtualMethod,				// Method is virtual
				ePureVirtualMethod,			// Method is pure virtual
				eEmulatedMethod,			// Method is emulated (Global function called as method, 'this' parameter as T* MUST be first parameter)
				eStaticMethod				// Method is static (no this)
			};
			
			/**
			Declare a new property.
			A property myProperty is a virtual member that can be modified through a Set method, and read through a Get method.
			If no Set method is given, the property is read only.
			*/
			Property AddProperty(const char* iName, const char* iTypeName, const FunctionPtr& iGetter, const FunctionPtr& iSetter = ES::FunctionPtr(), EMethodKind iGetterQualifier = Class::eMethod, EMethodKind iSetterQualifier = Class::eMethod);
			
			/**
			Register a method.
			
			@param iQualifier the function special qualifers
			@param iReturnType the function return type name
			@param iName the function name
			@param iPointer the function native pointer
			@param iParams a vector containing the type of the parameters the function expect 
			*/			
			Signature AddMethod(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const std::vector<const char*>& iParams, EMethodKind iQualifier = Class::eMethod);
			Signature AddMethod(const char* iReturnType, const char* iName, const FunctionPtr& iPointer, EMethodKind iQualifier = Class::eMethod);
			Signature AddMethod(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const char* iParam1, EMethodKind iQualifier = Class::eMethod);
			Signature AddMethod(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const char* iParam1, const char* iParam2, EMethodKind iQualifier = Class::eMethod);
			Signature AddMethod(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const char* iParam1, const char* iParam2, const char* iParam3, EMethodKind iQualifier = Class::eMethod);
			Signature AddMethod(const char* iReturnType, const char* iName, const FunctionPtr& iPointer,  const char* iParam1, const char* iParam2, const char* iParam3, const char* iParam4, EMethodKind iQualifier = Class::eMethod);
			
			/**
			Register a global constructor (should be called after the type has been registered, ie after a EndClass).
			If no constructor is declared, this object can not be allocated in ES using the new operator.
			
			@param iPointer the constructor native pointer (use DECLARE_CONSTRUCTOR macro)
			@param iParams a vector containing the type of the parameters the function expect
			@see ES::Class::SetDestructor
			*/
			bool SetConstructor(const FunctionPtr& iPointer, const std::vector<const char*>& iParams);
			bool SetConstructor(const FunctionPtr& iPointer);			
			bool SetConstructor(const FunctionPtr& iPointer, const char* iParam1);
			bool SetConstructor(const FunctionPtr& iPointer, const char* iParam1, const char* iParam2);
			bool SetConstructor(const FunctionPtr& iPointer, const char* iParam1, const char* iParam2, const char* iParam3);
			bool SetConstructor(const FunctionPtr& iPointer, const char* iParam1, const char* iParam2, const char* iParam3, const char* iParam4);		
			
			/**
			Register a global destructor (should be called after the type has been registered, ie after a EndClass).
			If no destructor is declared, this object can not be allocated in ES using the new operator (because can not be destructed).

			@param iPointer the destructor native pointer (use DECLARE_DESTRUCTOR macro)
			@see ES::Class::SetConstructor
			*/
			bool SetDestructor(const FunctionPtr& iPointer);
			
			/**
			Set the class size. May be used by the garbage collector when allocating new object.
			Informs the scripting engine that an object of this size has been allocated/desalocated.
			*/
			bool SetSize(unsigned int iSize);
			
		public:
		
			/**
			Dump the class to a string
			*/
			void Dump(CATUnicodeString& out);

		protected:

			/**
			Register a method that will receive as argument the list of argument given by ES as a ES::Array

			@param iName the function name
			@param iPointer the function native pointer. 
			
			The native function MUST have this prototype: 
			@code ES::Value* GenericFunction(const ES::Array& iParams) {...}
			*/
			Signature AddGenericMethod(const char* iName, const FunctionPtr& iPointer);
			
		protected:
			
			/**
			DELETION
			*/
			
			/**
			Removes a registered method
			*/
			bool RemoveMethod(const char* iName);
			
			/**
			Removes a registered property
			*/
			bool RemoveProperty(const char* iName);
			
		private:
		
			/**
			Internal
			*/
			ESTYPE_INTERNAL_CONSTRUCTOR(Class)
	};
	
	/**
	DEPRECATED
	*/
	#define DECLARE_CONSTRUCTOR(class)								class* __new##class(){ return new class;}
	#define DECLARE_CONSTRUCTOR_1P(class, t1)						class* __new##class(t1 iP1){ return new class(iP1);}
	#define DECLARE_CONSTRUCTOR_2P(class, t1, t2)					class* __new##class(t1 iP1, t2 iP2){ return new class(iP1, iP2);}
	#define DECLARE_CONSTRUCTOR_3P(class, t1, t2, t3)				class* __new##class(t1 iP1, t2 iP2, t3 iP3){ return new class(iP1, iP2, iP3);}
	#define DECLARE_CONSTRUCTOR_4P(class, t1, t2, t3, t4)			class* __new##class(t1 iP1, t2 iP2, t3 iP3, t4 iP4){ return new class(iP1, iP2, iP3, iP4);}
	#define DECLARE_CONSTRUCTOR_5P(class, t1, t2, t3, t4, t5)		class* __new##class(t1 iP1, t2 iP2, t3 iP3, t4 iP4, t5 iP5){ return new class(iP1, iP2, iP3, iP4, iP5);}
	#define DECLARE_CONSTRUCTOR_6P(class, t1, t2, t3, t4, t5, t6)	class* __new##class(t1 iP1, t2 iP2, t3 iP3, t4 iP4, t5 iP5, t6 iP6){ return new class(iP1, iP2, iP3, iP4, iP5, iP6);}
	
	/**
	DEPRECATED
	*/
	#define DECLARE_INNERCONSTRUCTOR(class, classi)								class* __new##class##_##classi(){ return new class::classi;}
	#define DECLARE_INNERCONSTRUCTOR_1P(class, classi, t1)						class* __new##class##_##classi(t1 iP1){ return new class::classi(iP1); }
	#define DECLARE_INNERCONSTRUCTOR_2P(class, classi, t1, t2)					class* __new##class##_##classi(t1 iP1, t2 iP2){ return new class::classi(iP1, iP2);}
	#define DECLARE_INNERCONSTRUCTOR_3P(class, classi, t1, t2, t3)				class* __new##class##_##classi(t1 iP1, t2 iP2, t3 iP3){ return new class::classi(iP1, iP2, iP3);}
	#define DECLARE_INNERCONSTRUCTOR_4P(class, classi, t1, t2, t3, t4)			class* __new##class##_##classi(t1 iP1, t2 iP2, t3 iP3, t4 iP4){ return new class::classi(iP1, iP2, iP3, iP4);}
	#define DECLARE_INNERCONSTRUCTOR_5P(class, classi, t1, t2, t3, t4, t5)		class* __new##class##_##classi(t1 iP1, t2 iP2, t3 iP3, t4 iP4, t5 iP5){ new class::classi(iP1, iP2, iP3, iP4, iP5);}
	#define DECLARE_INNERCONSTRUCTOR_6P(class, classi, t1, t2, t3, t4, t5, t6)	class* __new##class##_##classi(t1 iP1, t2 iP2, t3 iP3, t4 iP4, t5 iP5, t6 iP6){ new class::classi(iP1, iP2, iP3, iP4, iP5, iP6);}
	
	/**
	DEPRECATED
	*/
	#define DECLARE_DESTRUCTOR(class)	void __delete##class(class *iObj){delete iObj;}
}

#endif //__ESClass_h
