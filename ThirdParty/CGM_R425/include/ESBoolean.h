/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESBoolean_h
#define __ESBoolean_h

//ES
#include "ESKernelLib.h"
#include "ESValue.h"


namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES object
	*/
	class ESKERNEL_API Boolean : public ES::Value {

		public:
			
			/**
			Copy constructor
			*/
			Boolean(const ES::Boolean& iBoolean);

			/**
			Destructor
			*/
			virtual ~Boolean() {}

			/**
			Cast given value to Boolean
			*/
			static ES::Boolean Cast(const ES::Value& iValue);
			
			/**
			Creates a new script Boolean
			*/
			static ES::Boolean New(ES::World* iWorld, bool iValue);
			
			/**
			Creates a pointer to a new script Booelean
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::Boolean* NewPtr(ES::World* iWorld, bool iValue);
			
			/**
			Get integer value
			*/
			bool Value() const;

			/**
			Affect operator
			*/
			ES::Boolean& operator=(const ES::Boolean& iValue);

		public:
			
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Boolean)

	};

}

#endif //__ESBoolean_h
