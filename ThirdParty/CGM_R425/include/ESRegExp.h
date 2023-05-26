/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESRegExp_h
#define __ESRegExp_h

//ES
#include "ESKernelLib.h"
#include "ESObject.h"


namespace ES {

	//Forward declaration
	class World;

	/**
	Class describing a ES date
	*/
	class ESKERNEL_API RegExp : public ES::Object {

		public:

			/**
			*/
			enum Flags {
				kNone = 0,
				kGlobal = 1,
				kIgnoreCase = 2,
				kMultiline = 4
			};

			/**
			Copy constructor
			*/
			RegExp(const ES::RegExp& iValue);

			/**
			Destructor
			*/
			virtual ~RegExp() {}

			/**
			Cast given value to date
			*/
			static ES::RegExp Cast(const ES::Value& iValue);
			
			/**
			Creates a new script RegExp
			*/
			static ES::RegExp New(ES::World* iWorld, const CATUnicodeString& iPattern, ES::RegExp::Flags iFlags = kNone);

			/**
			Creates a pointer to a new script RegExp
			WARNING: Caller is responsible to call operator delete on the allocated returned value
			*/
			static ES::RegExp* NewPtr(ES::World* iWorld, const CATUnicodeString& iPattern, ES::RegExp::Flags iFlags = kNone);

			/**
			Affect operator
			*/
			ES::RegExp& operator=(const ES::RegExp& iValue);

			/**
			*/
			CATUnicodeString GetSource() const;
			
			/**
			*/
			ES::RegExp::Flags GetFlags() const;

		private:
		
			/**
			Internal
			*/
			ESVALUE_INTERNAL_CONSTRUCTOR(RegExp)
	};

}

#endif //__ESRegExp_h
