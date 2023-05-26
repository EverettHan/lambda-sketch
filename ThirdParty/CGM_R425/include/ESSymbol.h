/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESSymbol_h
#define __ESSymbol_h

//ES
#include "ESKernelLib.h"
#include "ESValue.h"


//CAT
#include "DSYString.h"

namespace ES {

	//Forward declaration
	class World;
	class String;

	/**
	Class describing a ES string
	*/
	class ESKERNEL_API Symbol : public ES::Value {

		public:
			
			/**
			Copy constructor
			*/
			Symbol(const ES::Symbol& iValue);

			/**
			Destructor
			*/
			virtual ~Symbol() {}

			/**
			Cast given value to string
			*/
			static ES::Symbol Cast(const ES::Value& iValue);
			
			/**
			Creates a new Script String
			*/
			static ES::Symbol New(ES::World* iWorld, const CATUnicodeString& iValue);
			static ES::Symbol New(ES::World* iWorld, const ES::String& iValue);

			/**
			Creates a pointer to a new String
			WARNING:  Caller is responsible to call operator delete (except if this string is returned by a bound function) 
			*/
			static ES::Symbol* NewPtr(ES::World* iWorld, const CATUnicodeString& iValue);
			static ES::Symbol* NewPtr(ES::World* iWorld, const ES::String& iValue);

			/**
			Affect operator
			*/
			ES::Symbol& operator=(const ES::Symbol& iValue);

			ES::Value Description() const;

			ES_DEPRECATED("2022/04/05", "Please use ES::Symbol::Description()", ES::Value Name() const;)

			static ES::Symbol For(ES::World* iWorld, const ES::String& iName);

			// Retrieve a global symbol. Similar to |For|, but using a separate
			// registry that is not accessible by (and cannot clash with) JavaScript code.
			static ES::Symbol ForApi(ES::World* iWorld, const ES::String& iName);

			// Well-known symbols
			static ES::Symbol GetIterator(ES::World* iWorld);
			static ES::Symbol GetUnscopables(ES::World* iWorld);
			static ES::Symbol GetToStringTag(ES::World* iWorld);
			static ES::Symbol GetIsConcatSpreadable(ES::World* iWorld);

		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Symbol)
	};

}

#endif //__ESSymbol_h
