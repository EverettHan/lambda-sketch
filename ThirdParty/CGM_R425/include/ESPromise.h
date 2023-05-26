/**
@file

@COPYRIGHT

@author Frederic Guignard
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESPromise_h
#define __ESPromise_h

//ES
#include "ESKernelLib.h"
#include "ESObject.h"
#include "ESFunction.h"

namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES Promise
	*/
	class ESKERNEL_API Promise : public ES::Object {

		public:

			enum PromiseState { kPending, kFulfilled, kRejected };

			class ESKERNEL_API Resolver : public ES::Object {

				public:

					static Resolver New(ES::World* iWorld);
					static Resolver* NewPtr(ES::World* iWorld);
					virtual ~Resolver() {}

					ES::Promise GetPromise();
					bool Resolve(const ES::Value& iValue);
					bool Reject(const ES::Value& iValue);

					static Resolver Cast(ES::Value* obj);

				private:

					ESPROMISERESOLVER_INTERNAL_CONSTRUCTOR()

			};

			/**
			Copy constructor
			*/
			Promise(const ES::Promise& iValue);

			/**
			Destructor
			*/
			virtual ~Promise() {}

			/**
			Cast given value to string
			*/
			static ES::Promise Cast(const ES::Value& iValue);

			/**
			Affect operator
			*/
			ES::Promise& operator=(const ES::Promise& iPromise);

			ES::Promise Catch(const ES::Function& iHandler);

			ES::Promise Then(const ES::Function& iHandler);

			bool HasHandler();

			ES::Value Result();

			PromiseState State();


		private:

			ESVALUE_INTERNAL_CONSTRUCTOR(Promise)
	};

}

#endif //__ESPromise_h
