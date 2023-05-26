/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

//ES
#include "ESFunctionPtr.h"


#ifndef __ES_internals_h
#define __ES_internals_h

namespace ES {
	
	/**
	*/
	#define ES_VERSION 0x0001
	
	/**
	*/
	#define V8_VERSION "8.1.307.32"
	
	/**
	*/
	#define ESNATIVEFUNCTION_INTERNAL_CONSTRUCTOR()  \
				VKernel::vkSignature* m_Signature; \
			public: \
				NativeFunction(ES::World* iWorld = nullptr, ES::Handler<v8::Function>::Persistent* iValue = nullptr);

	/**
	*/
	#define ESARRAYTEMPLATE_INTERNAL_CONSTRUCTOR(T)  \
		public: \
			T(ES::World* iWorld = nullptr, ES::Handler<v8::Object>::Persistent* iValue = nullptr);

	/**
	*/
	#define ESNATIVEOBJECT_INTERNAL_CONSTRUCTOR()  \
			public: \
				NativeObject(ES::World* iWorld = nullptr, ES::Handler<v8::Object>::Persistent* iValue = nullptr);

	/**
	*/
	#define ESVALUE_INTERNAL_CONSTRUCTOR(T)  \
			public: \
				T(ES::World* iWorld = nullptr, ES::Handler<v8::T>::Persistent* iValue = nullptr);

	/**
	*/
	#define ESPROMISERESOLVER_INTERNAL_CONSTRUCTOR()  \
			public: \
				Resolver(ES::World* iWorld = nullptr, ES::Handler<v8::Object>::Persistent* iValue = nullptr);

	/**
	*/		  	
	#define ESTYPE_INTERNAL_CONSTRUCTOR(T)  \
			public: \
				T(ES::World* iWorld = nullptr, VKernel::vkType* iType = nullptr);
	
	/**
	*/		
	#define ESSCRIPT_INTERNAL_DEFINITION  \
			public :\
				Script(ES::World* iWorld, ES::Handler<v8::Script>::Persistent* iScript, const CATUnicodeString& iKey);\
			private :\
				v8::Isolate* m_CreationIsolate; \
				Handler<v8::Script>::Persistent* m_Script;

	/**
	*/		
	#define ESVALUE_INTERNAL_DEFINITION  \
				ESVALUE_INTERNAL_CONSTRUCTOR(Value) \
			private: \
				Handler<v8::Value>::Persistent* m_Value; \
				v8::Isolate* m_CreationIsolate; \
				friend class Object; \
				friend class Array; \
				friend class Integer; \
				friend class Number; \
				friend class Script; \
				friend class String; \
				friend class Boolean; \
				friend class Date; \
				friend class RegExp; \
				friend class Function; \
				friend class NativeFunction; \
				friend class NativeObject; \
				friend class ArrayBuffer; \
				friend class ArrayBufferView; \
				friend class Int8Array; \
				friend class Int16Array; \
				friend class Int32Array; \
				friend class Uint8Array; \
				friend class Uint16Array; \
				friend class Uint32Array; \
				friend class Uint8ClampedArray; \
				friend class Float32Array; \
				friend class Float64Array; \
				friend class V8Binder; \
				friend class V8Binding; \
				friend class V8World; \
				friend class V8Template; \
				friend class V8Converter; \
				friend class HeapProfiler; \
				friend class Proxy; \
				friend class Promise; \
				friend class PromiseResolver; \
				friend class Map; \
				friend class Set; \
				friend class Symbol; \
			public: \
				Handler<v8::Value>::Persistent* GetInternalValue(){return m_Value;};
	/**
	*/	
	#define ESNAMESPACE_INTERNAL_DEFINITION  \
				ESTYPE_INTERNAL_CONSTRUCTOR(Namespace) \
			private: \
				VKernel::vkType* m_Type; \
				friend class V8Binder; \
				friend class V8World;

	/**
	*/
	#define ESTYPE_INTERNAL_DEFINITION  \
				ESTYPE_INTERNAL_CONSTRUCTOR(Type) \
			private: \
				VKernel::vkType* m_Type; \
				friend class Class; \
				friend class Enum; \
				friend class Flag; \
				friend class V8Binder; \
				friend class NativeObject; \
				friend class V8World;
	
	/**
	*/
	#define ESSIGNATURE_INTERNAL_DEFINITION  \
			public: \
				Signature(ES::World* iWorld = nullptr, VKernel::vkSignature* iSignature = nullptr); \
			private: \
				VKernel::vkSignature* m_Signature; \
				friend class Namespace; \
				friend class Class;\
				friend class V8Binder;
	/**
	*/
	#define ESPROPERTY_INTERNAL_DEFINITION  \
			public: \
				Property(ES::World* iWorld = nullptr, VKernel::vkClassType* iOwnerType = nullptr, const char* iMemberName = nullptr); \
			private: \
				const char* m_MemberName; \
				VKernel::vkClassType* m_Owner;


	/**
	*/
	#define ESEXCEPTION_INTERNAL_DEFINITION  \
			public: \
				Exception(ES::World* iWorld, ES::Handler<v8::Value>::Persistent* iValue = nullptr, ES::Handler<v8::Message>::Persistent* iMessage = nullptr); \
			private: \
				v8::Isolate* m_CreationIsolate; \
				Handler<v8::Value>::Persistent* m_Value; \
				Handler<v8::Message>::Persistent* m_Message;
	
	/**
	*/
	class World;

}

/**
Please Ignore.
This namespace exports functionality from within v8 that
is necessary to implement functions in the ES api. 
 */
namespace v8 {

	template <class T>
	class Local;

	template<class T>
	class FunctionCallbackInfo;

	template<class T> 
	struct CopyablePersistentTraits;
	
	template<class T, class M> 
	class Persistent;
	
	class Script;
	class String;
	class Object;
	class Value;
	class Number;
	class Integer;
	class Function;
	class Message;
	class Boolean;
	class Array;
	class Date;
	class RegExp;	
	class Context;
	class Isolate;
	class ArrayBuffer;
	class ArrayBufferView;
	class Int8Array;
	class Uint8Array;
	class Uint8ClampedArray;
	class Int16Array;
	class Uint16Array;
	class Int32Array;
	class Uint32Array;
	class Float32Array;
	class Float64Array;
	class Private;
	class Proxy;
	class Promise;
	class Map;
	class Set;
	class Symbol;
}

namespace VKernel {

	struct vkSignature;
	class vkType;
	class vkClassType;
}

namespace ES{

	template<class T>
	struct CopyablePersistentTraits {
	public: 
		typedef v8::Persistent<T, CopyablePersistentTraits<T> > CopyablePersistent;
		static const bool kResetInDestructor = true;
		template<class S, class M>
		static void Copy(const v8::Persistent<S, M>& source, CopyablePersistent* dest) {
			// do nothing, just allow copy
		}
	};

	template<class T>
	struct Handler
	{
		typedef v8::Persistent<T, CopyablePersistentTraits<T> > Persistent;
	};

}

#endif //__ES_internals_h

