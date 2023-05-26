/**
@file

This file defines the Javascript script class.

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

#ifndef __ESScript_h
#define __ESScript_h

//ES
#include "ESKernelLib.h"
#include "ESException.h"
#include "ESValue.h"

//CAT
#include "DSYString.h"

namespace ES {

	/**
	*/
	class World;

	/**
	*/
	class ESKERNEL_API Script {

		public:

			/**
			Default constructor
			*/
			Script(ES::World* iWorld = nullptr);

			/**
			Copy constructor
			*/
			Script(const ES::Script& iScript);

			/**
			Destructor
			*/
			~Script();

			/**
			Returns the key for the script
			*/
			CATUnicodeString GetKey() const;
			
			/**
			Runs the Script
			*/
			ES::Value Run(ES::Exception* oException = nullptr) const;

			/**
			Clears the Script
			*/
			void Clear();

			/**
			Test whether the Script object is valid
			*/
			bool IsValued() const;

			/**
			Affect operator
			*/
			ES::Script& operator=(const ES::Script& iScript);

		private:

			/**
			*/
			CATUnicodeString m_Key;

			/**
			*/
			ES::World* m_World;
			
		ESSCRIPT_INTERNAL_DEFINITION
	};
}

#endif //__ESScript_h
