/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESDate_h
#define __ESDate_h

//ES
#include "ESKernelLib.h"
#include "ESObject.h"


namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES date
	*/
	class ESKERNEL_API Date : public ES::Object {

		public:
			
			/**
			Copy constructor
			*/
			Date(const ES::Date& iValue);

			/**
			Destructor
			*/
			virtual ~Date() {}

			/**
			Cast given value to date
			*/
			static ES::Date Cast(const ES::Value& iValue);
			
			/**
			Creates a new script Date
			*/
			static ES::Date New(ES::World* iWorld, double iValue);

			/**
			Creates a pointer to a new script Date
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::Date* NewPtr(ES::World* iWorld, double iValue);

			/**
			Affect operator
			*/
			ES::Date& operator=(const ES::Date& iValue);

			/**
			*/
			double NumberValue() const;

		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Date)
	};

}

#endif //__ESDate_h
