/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESEnum_h
#define __ESEnum_h

//ES
#include "ESKernelLib.h"
#include "ESType.h"
#include "ESNamespace.h"
#include "ES_internals.h"

namespace ES {

	/**
	Enum describing a ES Enum
	*/
	class ESKERNEL_API Enum : public Type {

		public:

			/**
			Copy constructor
			*/
			Enum(const ES::Enum& iType);

			/**
			Destructor
			*/
			virtual ~Enum();
			
			/**
			Affect operator
			*/
			Enum& operator=(const Enum& iType);
			
			/**
			Cast given type to a namespace
			*/
			static ES::Enum Cast(const ES::Type& iType);

		public:

			/**
			INTROSPECTION
			*/

			/**
			Get the number of member declared in this enumeration
			*/
			unsigned int GetMemberCount() const;

			/**
			Get a value name by index
			*/
			CATUnicodeString GetMemberName(unsigned int iIndex) const;

			/**
			New API
			Get an enum value by name
			*/
			int	GetMember(const CATUnicodeString& iName) const;
			
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
			
		public:
			
			/**
			MODIFICATION
			*/
			
			/**
			Adds an enumeration value
			*/
			bool AddMember(const char* iName, int iValue);
	
		public:

			/**
			*/
			void Dump(CATUnicodeString& out);

		private:
		
			/**
			Internal
			*/
			ESTYPE_INTERNAL_CONSTRUCTOR(Enum)
	};

}

#endif //__ESEnum_h

