/**
@file

@COPYRIGHT

@author Julien Vouillaume
@author Frederic Guignard
*/


#ifndef __ESMap_h
#define __ESMap_h

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
	class ESKERNEL_API Map : public ES::Object {

		public:
			
			/**
			Copy constructor
			*/
			Map(const ES::Map& iMap);

			/**
			Destructor
			*/
			virtual ~Map() {}

			/**
			Cast given value to a map
			*/
			static ES::Map Cast(const ES::Value& iValue);
			
			/**
			Creates a new Map
			*/
			static ES::Map New(ES::World* iWorld);
			
			/**
			Creates a pointer to a new Integer
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::Map* NewPtr(ES::World* iWorld);
			

			ES::Array AsArray() const;

			ES::Map& operator=(const ES::Map& iValue);

			void Clear();

			unsigned int Size() const;

			ES::Value Get(const ES::Value& iKey);
			ES::Map Set(const ES::Value& iKey, const ES::Value& iValue);
			bool Has(const ES::Value& iKey);
			bool Delete(const ES::Value& iKey);


		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(Map)
	};

}

#endif //__ESMap_h
