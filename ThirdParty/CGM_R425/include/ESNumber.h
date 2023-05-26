/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESNumber_h
#define __ESNumber_h

//ES
#include "ESKernelLib.h"
#include "ESValue.h"


namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES object
	*/
	class ESKERNEL_API Number : public ES::Value {

		public:
			
			/**
			Copy constructor
			*/
			Number(const ES::Number& iNumber);

			/**
			Destructor
			*/
			virtual ~Number() {}

			/**
			Cast given value to number
			*/
			static ES::Number Cast(const ES::Value& iValue);
			
			/**
			Creates a new number value
			*/
			static ES::Number New(ES::World* iWorld, double iValue);
			
			/**
			Creates a new number value
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::Number* NewPtr(ES::World* iWorld, double iValue);

			/**
			Get double value
			*/
			double Value() const ;
	
      /**
			Affect operator
			*/
			ES::Number& operator=(const ES::Number& iValue);

			/**
			Check if NaN
			*/
      bool IsNotANumber() const ;

		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Number)
	};

}

#endif //__ESNumber_h
