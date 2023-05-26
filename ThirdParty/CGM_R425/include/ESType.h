/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESType_h
#define __ESType_h

//ES
#include "ESKernelLib.h"
#include "ESFunction.h"
#include "ES_internals.h"

//CAT
#include "DSYString.h"

namespace ES {

	/**
	Class describing a ES type
	*/
	class ESKERNEL_API Type {

		public:

			/**
			*/
			enum ETypeKind {
				eClass,
				eEnum,
				eFlag,
				ePrimitive
			};
			
			/**
			Copy constructor
			*/
			Type(const Type& iType);

			/**
			Destructor
			*/
			virtual ~Type();
			
			/**
			Clears the type
			*/
			void Clear();

			/**
			Get the world this value came from
			*/
			ES::World* GetWorld() const { return m_World; }

			/**
			Affect operator
			*/
			Type& operator=(const Type& iType);
			
			/**
			Test weather the type points to a constructed type implementation. Type can be seen as Ptr to a type implementation
			*/
			bool IsValued() const;

		public:
			
			/**
			INTROSPECTION
			*/
			
			/**
			Test wether type is a class
			*/
			bool IsClass() const;

			/**
			Test wether type is a enum
			*/
			bool IsEnum() const;

			/**
			Test wether type is a flag
			*/
			bool IsFlag() const;
			
			/**
			Get the type size
			*/
			unsigned int GetSize() const;
			
			/**
			Test wether type is a primitive
			*/
			bool IsPrimitive() const;

			/**
			Return wether this type is a class, enum, flag or primitive type (base type or pointers/references)
			*/
			ETypeKind GetTypeKind() const;

			/**
			Get the type name.
			*/
			CATUnicodeString GetName() const;
			
			/**
			Get the type complete name.
			(includes namespace/owner type name)
			*/
			CATUnicodeString GetCompleteName() const;
			
			/**
			Tests whether the type has been sealed.
			*/
			bool IsSealed() const;
			 
			/**
			Get the Key from the signature, to retrieve a user defined description (via a CATCatalogMsg for example)
			Unstable API, may be redefined.
			*/
			CATUnicodeString GetNLSKey() const;
			 
			/**
			*/
			bool IsKindOf(ES::Type iType) const;
			 
			/**
			*/
			bool IsKindOf(const char* iTypeName) const;
			 
		public:
			
			/**
			MODIFICATION
			*/
			
			/**
			Seals the type. After the type has been sealed, it can not be modified anymore.
			*/
			bool Seal(ES::Object iRoot) const;
			bool Seal() const;

			/**
			*/
			ES::Function GetFunction();

			/**
			Set a Key to a signature, to match a user defined description (via a CATCatalogMsg for example)
			Unstable API, may be redefined.
			*/
			void SetNLSKey(const char* iKey);

			void SetEditFlags( unsigned int iFlags);

			unsigned int GetEditFlags();

		protected:

			/**
			*/
			ES::World* m_World;

			/**
			Internal
			*/
			ESTYPE_INTERNAL_DEFINITION
	};

}

#endif //__ESType_h
