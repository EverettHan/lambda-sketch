/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESValue_h
#define __ESValue_h

//ES
#include "ESKernelLib.h"
#include "ES_internals.h"

//CAT
#include "DSYString.h"

namespace ES {
	class Exception;

	/**
	Class describing a ES value
	*/
	class ESKERNEL_API Value {

		public:
			
			/**
			Copy constructor
			*/
			Value(const ES::Value& iValue);

			/**
			Destructor
			*/
			virtual ~Value();
			
			/**
			Create a new Value of type Undefined
			*/
			static ES::Value NewUndefined(ES::World* iWorld);
			static ES::Value* NewUndefinedPtr(ES::World* iWorld);

			/**
			Creates a new value of type Null
			*/
			static ES::Value NewNull(ES::World* iWorld);

			/**
			Create a new Value from the JSON representation
			*/
			static ES::Value FromJSON(ES::World* iWorld, const CATUnicodeString& iJSON, ES::Exception* oException = nullptr);

			/**
			Get JSON representation of this Value
			*/
			CATUnicodeString ToJSON(ES::Exception* oException = nullptr) const;
			
			/**
			Test wether value is NUll
			*/
			bool IsNull() const;

			/**
			Test wether value is undefined
			*/
			bool IsUndefined() const;

			/**
			Test wether value is a number
			*/
			bool IsNumber() const;

			/**
			*/
			bool IsProxy() const;

			/**
			*/
			bool IsPromise() const;

			/**
			Test wether value is a int32
			*/
			bool IsInt32() const;

			/**
			Test wether value is a uint32
			*/
			bool IsUint32() const;

			/**
			Test wether value is a string
			*/
			bool IsString() const;

			/**
			Test wether value is an array
			*/
			bool IsArray() const;

			/**
			Test wether value is an object
			*/
			bool IsObject() const;
			
			/**
			Test wether value is an object or of a type derived from object (e.g. Array, Date, Function, NativeObject or RegExp )
			*/
			bool IsDerivedFromObject() const;

			/**
			Test whether this object wraps a native CPP instance (bound type)
			*/
			bool IsNativeObject() const; 
			
			/**
			Test whether this is a array buffer
			*/
			bool IsArrayBuffer() const; 

			bool IsInt8Array() const; 
			bool IsUint8Array() const; 
			bool IsInt16Array() const; 
			bool IsUint16Array() const; 
			bool IsInt32Array() const; 
			bool IsUint32Array() const; 
			bool IsFloat32Array() const; 
			bool IsFloat64Array() const; 
			bool IsUint8ClampedArray() const; 

			/**
			Test whether this is a array template
			*/
			bool IsArrayBufferView() const; 
			
			/**
			Test whether this function wraps a native CPP function (bound function)
			*/
			bool IsNativeFunction() const; 

			/**
			Test wether value is a function
			*/
			bool IsFunction() const;

			/**
			Test wether value is a date
			*/
			bool IsDate() const;

			/**
			Test wether value is a boolean
			*/
			bool IsBoolean() const;
			
			/**
			* Returns true if this value is true.
			*/
			bool IsTrue() const;

			/**
			* Returns true if this value is false.
			*/
			bool IsFalse() const;

			/**
			* Returns true if this value is a symbol or a string.
			*/
			bool IsName() const;

			/**
			* Returns true if this value is a symbol.
			*/
			bool IsSymbol() const;

			/**
			* Returns true if this value is an Arguments object.
			*/
			bool IsArgumentsObject() const;

			/**
			* Returns true if this value is an async function.
			*/
			bool IsAsyncFunction() const;

			/**
			* Returns true if this value is a Generator function.
			*/
			bool IsGeneratorFunction() const;

			/**
			* Returns true if this value is a Generator object (iterator).
			*/
			bool IsGeneratorObject() const;

			/**
			* Returns true if this value is a Map.
			*/
			bool IsMap() const;

			/**
			* Returns true if this value is a Set.
			*/
			bool IsSet() const;

			/**
			* Returns true if this value is a Map Iterator.
			*/
			bool IsMapIterator() const;

			/**
			* Returns true if this value is a Set Iterator.
			*/
			bool IsSetIterator() const;

			/**
			* Returns true if this value is a WeakMap.
			*/
			bool IsWeakMap() const;

			/**
			* Returns true if this value is a WeakSet.
			*/
			bool IsWeakSet() const;

			/**
			Test wether value is a external object
			*/
			bool IsNativeError() const;

			/**
			Test wether value is a external object
			*/
			bool IsRegExp() const;

			/**
			Get the string value of this value
			*/
			CATUnicodeString ToString() const;
			
			/**
			*/
			bool ToBoolean() const;
				
			/**
			*/
			double ToNumber() const;
				
			/**
			*/
			int ToInt32() const;
			
			/**
			*/
			unsigned int ToUint32() const;

			/**
			Clears the value
			*/
			virtual void Clear();

			/**
			Test weather the value object is constructed. The value is not constructed if it does not point to a script value instance.
			@return true if the value points to an instance of script value, false otherwise
			*/
			bool IsValued() const;

			/**
			*/
			bool Equals(const ES::Value& iValue) const;

			/**
			*/
			bool StrictEquals(const ES::Value& iValue) const;

			/**
			Get the world this value came from
			*/
			ESINLINE ES::World* GetWorld() const { return m_World; }

			/**
			Affect operator
			*/
			Value& operator=(const Value& iValue);

		protected:

			/**
			World as Ptr to prevent destroying a World before destroying ES::Value
			*/
			ES::World* m_World;

			/**
			Internal
			*/
			ESVALUE_INTERNAL_DEFINITION
	};

}

#endif //__ESValue_h
