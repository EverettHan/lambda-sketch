/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

#if !defined(__ESBinder_h)
#define __ESBinder_h


//ES
#include "ESKernelLib.h"
#include "ESNativeObject.h"
#include "ESClass.h"
#include "ESNamespace.h"
#include "ESEnum.h"
#include "ESFlag.h"
#include "ES_internals.h"


namespace ES {

	/**
	@code :
	namespace MATH {

		class Vec3 {

			public : 
				Vec3(float x, float y, float z);
				~Vec3();

				float GetX() const;
				float GetY() const;
				float GetZ() const;

				void SetX(float iX);
				void SetY(float iY);
				void SetZ(float iZ);

				float Magnitude() const; 
				Vec3& Normalize();
				bool IsNull() const;
				Vec3& Lerp(float iFactor, const Vec3& iV1, const Vec3& iV2)

			private : 
				float x;
				float y;
				float z;
		};

		DECLARE_CONSTRUCTOR_3P(Vec3, float, float, float)
		DECLARE_DESTRUCTOR(Vec3)
	}


	void 
	RegisterType(ES::Binder& oBinder) {

		ES::Namespace mathNS = oBinder.CreateNamespace("MATH");

		ES::Class vec3Class = oBinder.CreateClass(mathNS, "Vec3");
		vec3Class.AddMethod("float","Magnitude", FunctionPtr(&Vec3::Magnitude));
		vec3Class.AddMethod("Vec3&","Normalize", FunctionPtr(&Vec3::Normalize));
		vec3Class.AddMethod("bool","IsNull", FunctionPtr(&Vec3::IsNull));
		vec3Class.AddMethod("Vec3&","Lerp", FunctionPtr(&Vec3::Lerp), "float", "const Vec3&", "const Vec3&");
		vec3Class.AddProperty("x", "float", FunctionPtr(&Vec3::SetX),FunctionPtr(&Vec3::GetX));
		vec3Class.AddProperty("y", "float", FunctionPtr(&Vec3::SetY),FunctionPtr(&Vec3::GetY));
		vec3Class.AddProperty("z", "float", FunctionPtr(&Vec3::SetZ),FunctionPtr(&Vec3::GetZ));
		vec3Class.SetConstructor(FunctionPtr(&__newVec3), "float", "float", float");
		vec3Class.SetDestructor(FunctionPtr(&__deleteVec3));

		vec3Class.Seal();
		mathNS.Commit();
	}

	*/
	
	/**
	Class used to register C++ native types to ES.
	It allows construct new type from ES, call functions and manipulate members.
	*/
	class ESKERNEL_API Binder
	{
		public:
			
			/**
			INTROSPECTION
			*/

			/**
			Get the global namespace
			@return the global namespace
			*/
			virtual ES::Namespace GetGlobalNamespace() = 0;

			/**
			Get an existing namespace.
			@param iName the namespace name
			@return namespace description from namespace name
			*/
			virtual ES::Namespace GetNamespace(const char* iNamespaceName) = 0;

			/**
			Get an existing type.
			@param iName the type name
			@return type description from the type name
			*/
			virtual ES::Type GetType(const char* iTypeName) = 0;
			
			/**
			Return the world it belongs to
			*/
			virtual World* GetWorld() = 0;
			
		public: 
			
			/**
			MODIFICATION
			*/

			/**
			Helper that creates a new namespace in the global namespace.
			Equivalent to :
			@code binder.CreateClass(binder.GetGlobalNamespace(), "MyClass");
			*/
			virtual ES::Class CreateClass(const char* iClassName, const ES::Class& iParentClass = ES::Class()) = 0;
			
			/**
			Creates a new class in another class (inner class)
			@param iHost the name of the class owning this class
			@param iClassName the name of the class
			@param iParentClassName the name of the parent class
			@return a new Class
			*/
			virtual ES::Class CreateClass(const ES::Class& iHost, const char* iClassName, const ES::Class& iParentClass = ES::Class()) = 0;
			
			/**
			Creates a new class in another namespace (inner namespace)
			@param iHost the name of the namespace owning this class
			*/
			virtual ES::Class CreateClass(const ES::Namespace& iHost, const char* iClassName, const ES::Class& iParentClass = ES::Class()) = 0;

			/**
			Helper that creates a new enumeration in the global namespace.
			Equivalent to :
			@code binder.CreateEnum(binder.GetGlobalNamespace(), "MyEnum");
			*/
			virtual ES::Enum CreateEnum(const char* iEnumName) = 0;
				
			/**
			Create a new enumeration in another class (inner enum)
			@param iHost the name of the class owning this enum
			@param iEnumName the enumeration name
			@return a new Enum
			*/
			virtual ES::Enum CreateEnum(const ES::Class& iHost, const char* iEnumName) = 0;
			
			/**
			Create a new enumeration in another namespace (inner enum)
			@param iHost the name of the namespace owning this enum
			*/
			virtual ES::Enum CreateEnum(const ES::Namespace& iHost, const char* iEnumName) = 0;

			/**
			Helper that creates a new flag in the global namespace.
			Equivalent to :
			@code binder.CreateFlag(binder.GetGlobalNamespace(), "MyFlag");
			*/
			virtual ES::Flag CreateFlag(const char* iEnumName) = 0;
			
			/**
			Create a new flag in another class (inner enum)
			@param iHost the name of the class owning this flag
			@param iEnumName the flag name
			@return a new Enum
			*/
			virtual ES::Flag CreateFlag(const ES::Class& iHost, const char* iEnumName) = 0;
			
			/**
			Create a new enumeration in another namespace (inner flag)
			@param iHost the name of the namespace owning this flag
			*/
			virtual ES::Flag CreateFlag(const ES::Namespace& iHost, const char* iEnumName) = 0;

			/**
			Creates a new namespace.
			@param iHost the owner namespace
			@param iNamespaceName the name of the namespace
			@return a new Namespace
			*/
			virtual ES::Namespace CreateNamespace(const ES::Namespace& iHost, const char* iNamespaceName) = 0;
			
			/**
			Helper that creates a new namespace in the global namespace.
			Equivalent to :
			@code binder.CreateNamespace(binder.GetGlobalNamespace(), "NS");
			*/
			virtual ES::Namespace CreateNamespace(const char* iNamespaceName) = 0;
			
			/**
			Add an alias to an existing/already bound type

			@param iName the alias name
			@param iExistingTypeName the existing type name
			*/
			virtual bool AddNameAlias(const char* iName,const char* iExistingTypeName) = 0;
			
			/**
			Get the real type name from the given alias

			@param iName the alias name
			@return real type name
			*/
			virtual CATUnicodeString ResolveAliases(const char* iName) = 0;

		public:

			/** 
			Listener used to be notified about type creation and deletion
			*/
			class Listener {
				
				public:
					
					/**
					Callback called when a type has been sealed
					*/
					virtual void OnTypeSealed(const ES::Type& iType) = 0;
						
					/**
					Callback called when a namespace has been sealed
					*/
					virtual void OnNamespaceCommited(const ES::Namespace& iNS) = 0;
			};

			/**
			Register a new listener. Developper is responsible to call UnregisterListener
			@param iListener an instance of ES::Binder::Listener
			*/
			virtual void RegisterListener(ES::Binder::Listener* iListener) = 0;

			/**
			Unregister an existing listener
			@param iListener a registered instance of ES::Binder::Listener
			*/
			virtual void UnregisterListener(ES::Binder::Listener* iListener) = 0;

		protected: 
			 
			/**
			DELETION
			*/
			
			/**
			Remove a created type. After deleting a type, all ES::Type of this typename MUST not be used anymore.
					
			@param iName the type name
			*/
			virtual bool RemoveType(const char* iName) = 0;
			
			/**
			Remove a created namespace. After deleting a namespace, all ES::Namespace of this name MUST not be used anymore.
			
			@param iName the type name
			*/
			virtual bool RemoveNamespace(const char* iName) = 0;

	protected:

			/**
			Only ES::World can construct ES::Binder instances
			*/
			Binder() {}
			
			/**
			Only ES::World can destruct ES::Binder instances
			*/
			virtual ~Binder() {}
	};
}

#endif // __ESBinder_h



