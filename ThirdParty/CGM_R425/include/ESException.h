/**
@file

This file defines the Javascript exception class.

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

#ifndef __ESException_h
#define __ESException_h

//ES
#include "ESKernelLib.h"
#include "ES_internals.h"
#include "ESValue.h"

//CAT
#include "DSYString.h"

namespace ES {

	/**
	Describes an exception message. Thrown by the engine or from JS on compilation and execution errors.
	*/

	class CallFrame;

	class ESKERNEL_API Exception {


		public:

			/**
			Default constructor
			*/
			Exception();

			/**
			Copy constructor
			*/
			Exception(const Exception& iMessage);

			/**
			Destructor
			*/
			~Exception();

			/**
			Get the exception value
			*/
			Value GetValue() const;

			/**
			Get the exception message
			*/
			CATUnicodeString Get() const;
			
			/**
			Returns the key for the script from where the function causing the error originates.
			*/
			CATUnicodeString GetScriptKey() const;

			/**
			Get the ES source line that throws this exception
			*/
			CATUnicodeString GetSourceLine() const;
			
			/**
			Returns the number, 1-based, of the line where the error occurred.
			*/
			int GetLineNumber() const;

			/**
			Returns the index within the script of the first character where
			the error occurred.
			*/
			int GetStartPosition() const;

			/**
			Returns the index within the script of the last character where
			the error occurred.
			*/
			int GetEndPosition() const;

			/**
			Returns the index within the line of the first character where
			the error occurred.
			*/
			int GetStartColumn() const;

			/**
			Returns the index within the line of the last character where
			the error occurred.
			*/
			int GetEndColumn() const;

			/**
			Retrieve CallStack (if any) associated to this Exception object
			*/
			std::vector<CallFrame*>& GetExceptionCallStack();
			
			/**
			Retrieve CallStack (if any) associated to this Exception object
			*/
			std::vector<CallFrame> GetCallStack();
			
			/**
			Clears the exception
			*/
			void Clear();

			/**
			Test wether the Exception object is valid
			@return true if the excpetion points to an instance of script exception, false otherwise
			*/
			bool IsValued() const;

			/**
			Affect operator
			*/
			Exception& operator=(const Exception& iMessage);

		private:

			/**
			Empty ExceptionCallStack vector
			*/
			void _EmptyExceptionCallStack();
			
			/**
			*/
			ES::World* m_World;

			std::vector<CallFrame*> m_ExceptionCallStack;
			
			/**
			Internal
			*/
			ESEXCEPTION_INTERNAL_DEFINITION
	};

}

#endif //__ESException_h
