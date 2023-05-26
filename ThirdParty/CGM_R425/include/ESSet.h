/**
@file

@COPYRIGHT

@author Julien Vouillaume
@author Frederic Guignard
*/


#ifndef __ESSet_h
#define __ESSet_h

//ES
#include "ESKernelLib.h"
#include "ESArray.h"
#include "ESObject.h"


namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES object
	*/
	class ESKERNEL_API Set : public ES::Object {

		public:
			
			/**
			Copy constructor
			*/
			Set(const ES::Set& iSet);

			/**
			Destructor
			*/
			virtual ~Set() {}

			/**
			Cast given value to a map
			*/
			static ES::Set Cast(const ES::Value& iValue);
			
			/**
			Creates a new Map
			*/
			static ES::Set New(ES::World* iWorld);
			
			/**
			Creates a pointer to a new Integer
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::Set* NewPtr(ES::World* iWorld);
			
			ES::Set& operator=(const ES::Set& iValue);

			void Clear();

			unsigned int Size() const;

			ES::Array AsArray() const;

			ES::Set Add(const ES::Value& iValue);
			bool Has(const ES::Value& iKey);
			bool Delete(const ES::Value& iKey);


		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Set)
	};

}

#endif //__ESSet_h
