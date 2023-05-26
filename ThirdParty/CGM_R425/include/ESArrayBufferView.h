/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESArrayBufferView_h
#define __ESArrayBufferView_h

//ES
#include "ESKernelLib.h"
#include "ESObject.h"
#include "ESArrayBuffer.h"
#include "ESArray.h"
#include "ESString.h"
#include "ESType.h"


namespace ES {

	//Forward delcation
	class World;
	class Class;

	/**
	Class describing a ES Array buffer object.
	This is the base class for buffers view like Int8Array, Uin8Array etc.
	This type do not exists in ES, it exists in C++ as helper to manipulates buffer views.
	It can not be instanciated, static New methods are in derived classes.
	*/
	class ESKERNEL_API ArrayBufferView : public ES::Object {

		public:
			
			/**
			Copy constructor
			*/
			ArrayBufferView(const ES::ArrayBufferView& iObject);
			
			/**
			Destructor
			*/
			virtual ~ArrayBufferView() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::ArrayBufferView Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::ArrayBufferView& operator=(const ES::ArrayBufferView& iValue);

		public:

			/**
			INTROSPECTION
			*/

			/**
			The length of the ArrayBufferView in bytes, as fixed at construction time.
			*/
			size_t GetByteLength();
			
			/**
			The offset of this ArrayBufferView from the start of its ArrayBuffer, in bytes, as fixed at construction time.
			*/
			size_t GetByteOffset();
			
			/**
			The length of the ArrayBufferView in elements, as fixed at construction time.
			*/
			size_t GetLength();
			
			/**
			The size in bytes of each element in the array.
			*/
			unsigned int GetBytesPerElement();
			
			/**
			The ArrayBuffer that this ArrayBufferView references.
			*/
			ES::ArrayBuffer GetBuffer();
			
			/**
			The BaseAddress of this View.
			*/
			//void* GetBaseAddress();
			
			/**
			Returns a new array template view of the ArrayBuffer store for this ArrayBufferView, referencing the elements at begin,
			inclusive, up to end, exclusive. If no end, end refers to an index from the end of the array, as opposed to from the beginning
			*/
			ES::ArrayBufferView SubArray(unsigned int iStart);
			ES::ArrayBufferView SubArray(unsigned int iStart, unsigned int iEnd);
			
			/**
			Set multiple values, reading input values from the array.
			@param iArray should be an ES::Array or ES::ArrayBufferView 
			@param iOffset optional offset value indicates the index in the current array where values are written. If omitted, it is assumed to be 0.
			*/
			//void Set(const ES::Object& iSource, unsigned int iOffset = 0);
		protected :
			
			unsigned int m_BytesPerElement;
		
		private:
			
			
			
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(ArrayBufferView)

	};
	

	/**
	*/
	class ESKERNEL_API Int8Array : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Int8Array(const ES::Int8Array& iObject);
			
			/**
			Destructor
			*/
			virtual ~Int8Array() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Int8Array Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Int8Array& operator=(const ES::Int8Array& iValue);
			
			/**
			*/
			static ES::Int8Array New(ES::World* iWorld, unsigned int iLength);
			static ES::Int8Array New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Int8Array New(ES::World* iWorld, const ES::Int8Array& iArray);
			static ES::Int8Array New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			

		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Int8Array)
	};
	
	/**
	*/
	class ESKERNEL_API Uint8Array : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Uint8Array(const ES::Uint8Array& iObject);
			
			/**
			Destructor
			*/
			virtual ~Uint8Array() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Uint8Array Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Uint8Array& operator=(const ES::Uint8Array& iValue);
			
			/**
			*/
			static ES::Uint8Array New(ES::World* iWorld, unsigned int iLength);
			static ES::Uint8Array New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Uint8Array New(ES::World* iWorld, const ES::Uint8Array& iArray);
			static ES::Uint8Array New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			
		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Uint8Array)
	};
	
	/**
	*/
	class ESKERNEL_API Int16Array : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Int16Array(const ES::Int16Array& iObject);
			
			/**
			Destructor
			*/
			virtual ~Int16Array() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Int16Array Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Int16Array& operator=(const ES::Int16Array& iValue);
			
			/**
			*/
			static ES::Int16Array New(ES::World* iWorld, unsigned int iLength);
			static ES::Int16Array New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Int16Array New(ES::World* iWorld, const ES::Int16Array& iArray);
			static ES::Int16Array New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			
		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Int16Array)
	};
	
	/**
	*/
	class ESKERNEL_API Uint16Array : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Uint16Array(const ES::Uint16Array& iObject);
			
			/**
			Destructor
			*/
			virtual ~Uint16Array() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Uint16Array Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Uint16Array& operator=(const ES::Uint16Array& iValue);
			
			/**
			*/
			static ES::Uint16Array New(ES::World* iWorld, unsigned int iLength);
			static ES::Uint16Array New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Uint16Array New(ES::World* iWorld, const ES::Uint16Array& iArray);
			static ES::Uint16Array New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			
		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Uint16Array)
	};
	
	/**
	*/
	class ESKERNEL_API Int32Array : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Int32Array(const ES::Int32Array& iObject);
			
			/**
			Destructor
			*/
			virtual ~Int32Array() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Int32Array Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Int32Array& operator=(const ES::Int32Array& iValue);
			
			/**
			*/
			static ES::Int32Array New(ES::World* iWorld, unsigned int iLength);
			static ES::Int32Array New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Int32Array New(ES::World* iWorld, const ES::Int32Array& iArray);
			static ES::Int32Array New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			
		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Int32Array)
	};
	
	/**
	*/
	class ESKERNEL_API Uint32Array : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Uint32Array(const ES::Uint32Array& iObject);
			
			/**
			Destructor
			*/
			virtual ~Uint32Array() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Uint32Array Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Uint32Array& operator=(const ES::Uint32Array& iValue);
			
			/**
			*/
			static ES::Uint32Array New(ES::World* iWorld, unsigned int iLength);
			static ES::Uint32Array New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Uint32Array New(ES::World* iWorld, const ES::Uint32Array& iArray);
			static ES::Uint32Array New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			
		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Uint32Array)
	};

	/**
	*/
	class ESKERNEL_API Float32Array : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Float32Array(const ES::Float32Array& iObject);
			
			/**
			Destructor
			*/
			virtual ~Float32Array() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Float32Array Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Float32Array& operator=(const ES::Float32Array& iValue);
			
			/**
			*/
			static ES::Float32Array New(ES::World* iWorld, unsigned int iLength);
			static ES::Float32Array New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Float32Array New(ES::World* iWorld, const ES::Float32Array& iArray);
			static ES::Float32Array New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			
		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Float32Array)
	};
	
	/**
	*/
	class ESKERNEL_API Float64Array : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Float64Array(const ES::Float64Array& iObject);
			
			/**
			Destructor
			*/
			virtual ~Float64Array() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Float64Array Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Float64Array& operator=(const ES::Float64Array& iValue);
			
			/**
			*/
			static ES::Float64Array New(ES::World* iWorld, unsigned int iLength);
			static ES::Float64Array New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Float64Array New(ES::World* iWorld, const ES::Float64Array& iArray);
			static ES::Float64Array New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			
		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Float64Array)
	};
	
	/**
	*/
	class ESKERNEL_API Uint8ClampedArray : public ES::ArrayBufferView {
		public:
			
			/**
			Copy constructor
			*/
			Uint8ClampedArray(const Uint8ClampedArray& iObject);
			
			/**
			Destructor
			*/
			virtual ~Uint8ClampedArray() {}
			
			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Uint8ClampedArray Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Uint8ClampedArray& operator=(const ES::Uint8ClampedArray& iValue);
				
			/**
			*/
			static ES::Uint8ClampedArray New(ES::World* iWorld, unsigned int iLength);
			static ES::Uint8ClampedArray New(ES::World* iWorld, const ES::Array& iArray);
			static ES::Uint8ClampedArray New(ES::World* iWorld, const ES::Uint8ClampedArray& iArray);
			static ES::Uint8ClampedArray New(ES::World* iWorld, const ES::ArrayBuffer& iBuffer, unsigned int iByteOffset = 0, unsigned int iLength = 0);
			
		private:
		
			/**
			Internal
			*/
			ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(Uint8ClampedArray)
	};
}

#endif //__ESArrayBufferView_h
