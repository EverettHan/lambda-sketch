/**
@file

@COPYRIGHT

@author Frederic Guignard
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESProxy_h
#define __ESProxy_h

//ES
#include "ESKernelLib.h"
#include "ESObject.h"

namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES Proxy
	*/
	class ESKERNEL_API Proxy : public ES::Object {

	public:

		/**
		Copy constructor
		*/
		Proxy(const ES::Proxy& iValue);

		/**
		Destructor
		*/
		virtual ~Proxy() {}

		/**
		Cast given value to string
		*/
		static ES::Proxy Cast(const ES::Value& iValue);

		/**
		Creates a new Script String
		*/
		static ES::Proxy New(ES::World* iWorld, const ES::Object& iTarget, const ES::Object& iHandler);

		/**
		Creates a pointer to a new String
		WARNING:  Caller is responsible to call operator delete (except if this string is returned by a bound function)
		*/
		static ES::Proxy* NewPtr(ES::World* iWorld, const ES::Object& iLocalTarget, const ES::Object& iLocalHandler);

		/**
		Get Target
		*/
		ES::Object GetTarget() const;

		/**
		Get Handler
		*/
		ES::Value GetHandler() const;

		/**
		
		*/
		bool IsRevoked() const;

		/**
		
		*/
		void Revoke() const;

		/**
		Affect operator
		*/
		ES::Proxy& operator=(const ES::Proxy& iProxy);

	private:

		/**
		Internal
		*/
		ESVALUE_INTERNAL_CONSTRUCTOR(Proxy)
	};

}

#endif //__ESProxy_h
