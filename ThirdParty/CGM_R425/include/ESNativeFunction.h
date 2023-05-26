/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESNativeFunction_h
#define __ESNativeFunction_h

//ES
#include "ESKernelLib.h"
#include "ESFunction.h"
#include "ESSignature.h"


namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES native function
	*/
	class ESKERNEL_API NativeFunction : public ES::Function {

		public:
			
			/**
			Copy constructor
			*/
			NativeFunction(const ES::NativeFunction& iFunction);

			/**
			Destructor
			*/
			virtual ~NativeFunction() {}
			
			/**
			*/
			virtual void Clear();

			/**
			Cast given value to Function
			*/
			static ES::NativeFunction Cast(const ES::Value& iValue);
			
			/**
			Affect operator
			*/
			ES::NativeFunction& operator=(const ES::NativeFunction& iValue);

			/**
			*/
			ES::Signature GetSignature();

		private:
		
			/**
			Internal
			*/
			ESNATIVEFUNCTION_INTERNAL_CONSTRUCTOR()
	};

}

#endif //__ESNativeFunction_h
