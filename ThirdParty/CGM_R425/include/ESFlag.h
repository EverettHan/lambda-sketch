/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESFlag_h
#define __ESFlag_h

//ES
#include "ESKernelLib.h"
#include "ESType.h"
#include "ESNamespace.h"
#include "ES_internals.h"

//CAT
#include "DSYString.h"

namespace ES {

	/**
	Flag describing a ES Flag
	*/
	class ESKERNEL_API Flag : public Type {

	public:

		/**
		Copy constructor
		*/
		Flag(const ES::Flag& iType);

		/**
		Destructor
		*/
		virtual ~Flag();

		/**
		Affect operator
		*/
		Flag& operator=(const Flag& iType);

		/**
		Cast given type to a namespace
		*/
		static ES::Flag Cast(const ES::Type& iType);

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
		unsigned int GetMember(const CATUnicodeString& iName) const;
		
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
		*/
		bool AddMember(const char* iName, unsigned int iValue);

	public:
		
		/**
		*/
		void Dump(CATUnicodeString& out);

	private:

		/**
		Internal
		*/
		ESTYPE_INTERNAL_CONSTRUCTOR(Flag)
	};

}

#endif //__ESFlag_h

