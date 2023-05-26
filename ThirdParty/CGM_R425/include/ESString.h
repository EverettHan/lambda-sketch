/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESString_h
#define __ESString_h

//ES
#include "ESKernelLib.h"
#include "ESValue.h"

//CAT
#include "DSYString.h"

namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES string
	*/
	class ESKERNEL_API String : public ES::Value {

		public:
			
			/**
			Copy constructor
			*/
			String(const ES::String& iValue);

			/**
			Destructor
			*/
			virtual ~String() {}

			/**
			Cast given value to string
			*/
			static ES::String Cast(const ES::Value& iValue);
			
			/**
			Creates a new Script String
			*/
			static ES::String New(ES::World* iWorld, const CATUnicodeString& iValue);

			/**
			Creates a pointer to a new String
			WARNING:  Caller is responsible to call operator delete (except if this string is returned by a bound function) 
			*/
			static ES::String* NewPtr(ES::World* iWorld, const CATUnicodeString& iValue);

			/**
			Get string value
			*/
			CATUnicodeString Value() const;

			/**
			Affect operator
			*/
			ES::String& operator=(const ES::String& iValue);
		
		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(String)
	};

}

#endif //__ESString_h
