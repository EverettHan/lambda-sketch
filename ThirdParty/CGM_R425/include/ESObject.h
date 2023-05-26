/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESObject_h
#define __ESObject_h

//ES
#include "ESKernelLib.h"
#include "ESValue.h"
#include "ESString.h"

//CAT
#include "DSYString.h"

namespace ES {

	//Forward declaration
	class World;
	 
	/**
	Class describing a ES object
	*/
	class ESKERNEL_API Object : public ES::Value {


		public:

			/**
			Copy constructor
			*/
			Object(const ES::Object& iObject);

			/**
			Destructor
			*/
			virtual ~Object() {}

			/**
			Cast given value to object
			@return an empty object (invalid) if given value is not an object
			*/
			static ES::Object Cast(const ES::Value& iValue);
			
			/**
			Creates a new script Object
			*/
			static ES::Object New(ES::World* iWorld);
			
			/**
			Creates a pointer to a new script Object
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::Object* NewPtr(ES::World* iWorld);

		public:

			enum EPropertyAttribute {
				eNone       = 0,
				eReadOnly   = 1 << 0,
				eDontEnum   = 1 << 1,
				eDontDelete = 1 << 2
			};

			/**
			Get the prototype object.  This does not skip objects marked to
			be skipped by __proto__ and it does not consult the security
			handler.
			*/
			ES::Value GetPrototype();
			
			/**
			Set the prototype object.  This does not skip objects marked to
			be skipped by __proto__ and it does not consult the security
			handler.
			*/
			bool SetPrototype(const ES::Value& iValue);

			/**
			Introspection
			*/

			/**
			Returns an array containing the names of the enumerable properties
			of this object, including properties from prototype objects.  The
			array returned by this method contains the same values as would
			be enumerated by a for-in statement over this object.
			*/
			ES::Value GetPropertyNames() const;

			/**
			This function has the same functionality as GetPropertyNames but
			the returned array doesn't contain the names of properties from
			prototype objects.
			*/
			ES::Value GetOwnPropertyNames() const;

			/**
			Returns the name of the function invoked as a constructor for this object.
			*/
			CATUnicodeString GetConstructorName();
			
			/**
			*/
			bool Has(const CATUnicodeString& iKeyName) const;
			
			/**
			*/
			bool Has(unsigned int iKeyIndex) const;

			/**
			*/
			bool HasOwnProperty(const CATUnicodeString& iKeyName) const;

		public:

			/**
			Named property
			*/
			
			/**
			*/
			EPropertyAttribute GetPropertyAttributes(const ES::Value& iPropertyName) const;
			
			/**
			*/
			EPropertyAttribute GetPropertyAttributes(const CATUnicodeString& iPropertyName) const;

			/**
			*/
			bool Set(const CATUnicodeString& iPropertyName, const ES::Value& iValue, EPropertyAttribute iFlag = eNone);
			
			/**
			*/
			bool Set(const CATUnicodeString& iPropertyName, long long iInt64, EPropertyAttribute iFlag = eNone);
			
			/**
			*/
			bool Set(const CATUnicodeString& iPropertyName, unsigned long long iUInt64, EPropertyAttribute iFlag = eNone);
		
			/**
			*/
			bool Set(const CATUnicodeString& iPropertyName, int iInt32, EPropertyAttribute iFlag = eNone);
			
			/**
			*/
			bool Set(const CATUnicodeString& iPropertyName, unsigned int iUint32, EPropertyAttribute iFlag = eNone);
		
			/**
			*/
			bool Set(const CATUnicodeString& iPropertyName, double iDouble, EPropertyAttribute iFlag = eNone);
			
			/**
			*/
			bool Set(const CATUnicodeString& iPropertyName, bool iBool, EPropertyAttribute iFlag = eNone);
		
			/**
			*/
			bool Set(const CATUnicodeString& iPropertyName, const CATUnicodeString& iString, EPropertyAttribute iFlag = eNone);
				
			/**
			*/
			bool Set(const ES::Value& iPropertyKey, const ES::Value& iPropertyValue, EPropertyAttribute iFlag = eNone);
						
			/**
			*/
			ES::Value Get(const CATUnicodeString& iPropertyName) const;
			
			/**
			*/
			ES::Value Get(const ES::Value& iPropertyKey) const;
			
			/**
			*/
			bool Remove(const CATUnicodeString& iPropertyName);

		public:

			/**
			Indexed property
			*/

			/**
			*/
			bool Set(unsigned int iIndex, const ES::Value& iValue);
			
			/**
			*/
			bool Set(unsigned int iIndex, long long iInt64);

			/**
			*/
			bool Set(unsigned int iIndex, unsigned long long iInt64);

			/**
			*/
			bool Set(unsigned int iIndex, int iInt32);

			/**
			*/
			bool Set(unsigned int iIndex, unsigned int iUint32);
			
			/**
			*/
			bool Set(unsigned int iIndex, double iDouble);
			
			/**
			*/
			bool Set(unsigned int iIndex, bool iBool);
			
			/**
			*/
			bool Set(unsigned int iIndex, const CATUnicodeString& iString);

			/**
			*/
			ES::Value Get(unsigned int iIndex) const;

			/**
			*/
			bool Remove(unsigned int iIndex);

			/**
			Affect operator
			*/
			ES::Object& operator=(const ES::Object& iValue);

		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Object)
	};

}

#endif //__ESObject_h
