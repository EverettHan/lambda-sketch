/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESCallFrame_h
#define __ESCallFrame_h

//ES
#include "ESKernelLib.h"
#include "ESValue.h"

//CAT
#include "CATUnicodeString.h"


namespace ES {

	/**
	Describe a ES call stack entry. 
	*/
	class ESKERNEL_API CallFrame {
		

	public:

		/**
		*/
		CallFrame(CATUnicodeString iScriptName, CATUnicodeString iFuncName, int iLine, int iCol);
		CallFrame(const CallFrame& iToCopy);
		
		/**
		*/
		~CallFrame() {}

		/**
		Get the current frame source id.
		*/
		const CATUnicodeString& SourceName() const;

		/**
		Get the current frame line.
		*/
		unsigned int Line() const;

		/**
		Get the current frame column.
		*/
		unsigned int Column() const;

		/**
		Get the current frame function name.
		*/
		const CATUnicodeString& FunctionName() const;				

	private:
		
		CATUnicodeString m_FunctionName;
		CATUnicodeString m_ScriptName;
		unsigned int m_Line;
		unsigned int m_Column;

	};

}

#endif //__ESCallFrame_h
