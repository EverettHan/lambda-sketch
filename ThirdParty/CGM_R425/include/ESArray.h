/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/



#ifndef __ESArray_h
#define __ESArray_h

//ES
#include "ESKernelLib.h"

#include "ESObject.h"

namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES array
	*/


	class ESKERNEL_API Array : public ES::Object {

		public:
			
			/**
			Copy constructor
			*/
			Array(const ES::Array& iValue);

			/**
			Destructor
			*/
			virtual ~Array() {}

			/**
			Cast given value to array
			*/
			static ES::Array Cast(const ES::Value& iValue);
			
			/**
			Creates a new script Array
			*/
			static ES::Array New(ES::World* iWorld);

			/**
			Creates a pointer to a new script Array
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::Array* NewPtr(ES::World* iWorld);

			/**
			*/
			unsigned int Length() const;
			
			/**
			Affect operator
			*/
			ES::Array& operator=(const ES::Array& iValue);

		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Array)
	};

}

#endif //__ESArray_h
