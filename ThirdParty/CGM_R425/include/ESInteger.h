/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESInteger_h
#define __ESInteger_h

//ES
#include "ESKernelLib.h"
#include "ESNumber.h"


namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES object
	*/
	class ESKERNEL_API Integer : public ES::Number {

		public:
			
			/**
			*/
			Integer(ES::World* iWorld, unsigned int iValue);

			/**
			Copy constructor
			*/
			Integer(const ES::Integer& iInteger);

			/**
			Destructor
			*/
			virtual ~Integer() {}

			/**
			Cast given value to number
			*/
			static ES::Integer Cast(const ES::Value& iValue);
			
			/**
			Creates a new Integer
			*/
			static ES::Integer New(ES::World* iWorld, unsigned int iValue);
			static ES::Integer New(ES::World* iWorld, int iValue);

			/**
			Creates a pointer to a new Integer
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::Integer* NewPtr(ES::World* iWorld, unsigned int iValue);
			static ES::Integer* NewPtr(ES::World* iWorld, int iValue);

			/**
			Get integer value
			*/
			int Value() const;

			/**
			Get unsigned integer value
			*/
			unsigned int UnsignedValue() const;
			
			/**
			Affect operator
			*/
			ES::Integer& operator=(const ES::Integer& iValue);

		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Integer)
	};

}

#endif //__ESInteger_h
