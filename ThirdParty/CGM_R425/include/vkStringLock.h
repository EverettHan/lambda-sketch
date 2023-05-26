/**
@file

A set of classes to access internal data on a string.

@COPYRIGHT

@author Gerald Guyomard
*/

#ifndef __vkStringLock_h
#define __vkStringLock_h

#if !defined(__vkString_h)
	#include "vkString.h"
#endif

namespace VKernel 
{
	/**
	vkStringLockParams is the struct used to retrieve
	the buffer of characters when using vkString's Lock/Unlock.

	@see Lock, Unlock

	@ingroup grp_string
	*/
	class vkStringLockParams : public vkHeapObject
	{
	public :

		/**
		Gets the encoding of the locked characters.
		@return the encoding of the locked characters.
		*/
		VKKERNEL_INL vkCharacter::EEncoding	GetEncoding() const;

		/**
		Gets the locked characters.

		To interpret the characters, rely on
		the encoding.

		@return the lock characters terminated by null char.
		*/
		VKKERNEL_INL const char8* GetChars() const;

		/**
		Gets the size in bytes used by the locked
		characters (null char included).
		@return the size in bytes.
		*/
		VKKERNEL_API uint32 Size() const;

		/**
		Tests if the lock buffer is a copy (with
		conversion or not) of the internal buffer of the
		string.
		@return true if the buffer is a copy.
		*/
		VKKERNEL_INL bool IsBufferCopied() const;

		/**
		Constructor
		@param iEncoding the encoding in which the locked characters must be.
		*/
		VKKERNEL_API vkStringLockParams(vkCharacter::EEncoding iEncoding);

	private :

		friend class vkString;

		char8*				m_LockedChars;
		uint32				m_LockedSize;
		uint16				m_Encoding;
		uint16				m_IsBufferCopied;
	};

	/**
	This is a helper class for locking the characters
	of a string in particular encoding.
	
	@code
	// Creates an UTF16 string
	vkString s("Hello world", vkCharacter::eUTF16Encoding);

	// Access to the character in ASCII Encoding.
	vkStringLock lock(s, vkCharacter::eASCIIEncoding);
	printf("%s\n", lock.ASCIICStr());
	// String unlocked at end of scope.
	@endcode

	@ingroup grp_string
	*/
	class vkStringLock : public vkHeapObject
	{
	public :

		/**
		Constructor locking the entire string.
		@param iString the string to lock.
		@param iEncoding the encoding of the locked characters.
		*/
		VKKERNEL_INL vkStringLock(const vkString& iString, const vkCharacter::EEncoding iEncoding = vkCharacter::eASCIIEncoding);

		/**
		Constructor locking the string starting
		at a particular position.
		@param iString the string to lock.
		@param iEncoding the encoding of the locked characters.
		@param iStart iterator on the first character to be locked.
		*/
		VKKERNEL_INL vkStringLock(const vkString& iString, const vkCharacter::EEncoding iEncoding, const vkString::ConstIterator& iStart);

		/**
		Constructor locking a part of a string.

		@param iString the string to lock.
		@param iEncoding the encoding of the locked characters.
		@param iStart iterator on the first character to be locked.
		@param iEnd end of the locked characters.
		*/
		VKKERNEL_INL vkStringLock(const vkString& iString, const vkCharacter::EEncoding iEncoding, const vkString::ConstIterator& iStart, const vkString::ConstIterator& iEnd);

		/**
		Constructor locking the string and using
		an encoding based on the size of a character unit.

		The rule to determine the encoding is :
			- 1 : UTF8 Encoding
			- 2 : UTF16 Encoding
			- 4 : UTF32 Encoding

		@param iString the string to lock.
		@param iUnitSize size of a character unit (1, 2, or 4).
		*/
		VKKERNEL_INL vkStringLock(const vkString& iString, const size_t iUnitSize);

		/**
		Destructor
		*/
		VKKERNEL_INL ~vkStringLock();

		/**
		Gets the pointer to the locked characters
		when encoding is ASCII or UTF8.
		@return the pointer to the locked char8 characters
		or 0 if the encoding is not ASCII nor UTF8.
		*/
		VKKERNEL_INL const char8*	CStr() const;

		/**
		Gets the pointer to the locked characters
		when encoding is ASCII.
		@return the pointer to the locked ASCII characters
		or 0 if the encoding is not ASCII.
		*/
		VKKERNEL_INL const char8*	ASCIICStr() const;

		/**
		Gets the pointer to the locked characters
		when encoding is UTF8.
		@return the pointer to the UTF8 characters
		or 0 if the encoding is not UTF8.
		*/
		VKKERNEL_INL const char8*	UTF8CStr() const;

		/**
		Gets the pointer to the locked characters
		when encoding is UTF16.
		@return the pointer to the UTF16 characters
		or 0 if the encoding is not UTF16.
		*/
		VKKERNEL_INL const char16*	UTF16CStr() const;

		/**
		Gets the pointer to the locked characters
		when encoding is UTF32.
		@return the pointer to the UTF32 characters
		or 0 if the encoding is not UTF32.
		*/
		VKKERNEL_INL const char32*	UTF32CStr() const;

		/**
		Gets the pointer to the locked characters
		whatever the encoding used.
		@return the pointer to the raw characters.
		*/
		VKKERNEL_INL const char8*	GetChars() const;

		/**
		Gets the size in bytes of the locked characters
		(trailing null character INCLUDED).
		@return the size of the locked characters.
		*/
		VKKERNEL_INL uint32 Size() const;

		/**
		Gets the size in bytes of the locked characters
		(trailing null character EXCLUDED).
		@return the size of the locked characters.
		*/
		VKKERNEL_INL uint32 ByteLength() const;

		/**
		Gets the number of locked units (trailing null
		unit excluded).
		@return the number of locked units.
		*/
		VKKERNEL_INL uint32 UnitLength() const;

		/**
		Tests if a copy of the original characters
		have been made when locking.
		@return true if the characters have been copied.
		*/
		VKKERNEL_INL bool IsBufferCopied() const;

		/**
		Tests if all the characters have the same
		size.
		@return true if all the characters have the 
		same size.
		*/
		VKKERNEL_API bool HasConstantCharSize() const;

		#if !defined(VK_DOXYGEN)
	protected:

		vkStringLock operator= (vkStringLock&)
		{
			return *this;
		}

		// Copies the string to avoid its premature deletion.
		// Make no mistake : it's not a brute copy of the buffer, only a copy of the wrapper.
		// 2 cases:
		// 1. the string is static : straightforward
		// 2. the string is not static : a simple addref is done on the buffer (for that,
		// m_String must NOT be fixed encoding !)
		vkString				m_String;
		vkStringLockParams		m_LockParams;
		#endif // VK_DOXYGEN
	};

	/**
	This is a helper class for locking the characters
	of a string in ASCII Encoding.

	@ingroup grp_string
	*/
	class vkASCIILock : public vkStringLock
	{
	public :
		/**
		Constructor

		@param iString the string to lock in ASCII Encoding.
		*/
		VKKERNEL_INL vkASCIILock(const vkString& iString);

		/**
		Gets a pointer to the locked characters
		in ASCII Encoding.
		@return the locked characters.
		*/
		VKKERNEL_INL const char8*	CStr() const; 
	};

	/**
	This is a helper class for locking the characters
	of a string in UTF8 Encoding.

	@ingroup grp_string
	*/
	class vkUTF8Lock : public vkStringLock
	{
	public :
		/**
		Constructor

		@param iString the string to lock in UTF8 Encoding.
		*/
		VKKERNEL_INL vkUTF8Lock(const vkString& iString);

		/**
		Gets a pointer to the locked characters
		in UTF8 Encoding.
		@return the locked characters.
		*/
		VKKERNEL_INL const char8*	CStr() const; 
	};

	/**
	This is a helper class for locking the characters
	of a string in UTF16 Encoding.

	@ingroup grp_string
	*/
	class vkUTF16Lock : public vkStringLock
	{
	public :
		/**
		Constructor

		@param iString the string to lock in UTF16 Encoding.
		*/
		VKKERNEL_INL vkUTF16Lock(const vkString& iString);

		/**
		Gets a pointer to the locked characters
		in UTF16 Encoding.
		@return the locked characters.
		*/
		VKKERNEL_INL const char16*	CStr() const; 
	};

	/**
	This is a helper class for locking the characters
	of a string in UTF32 Encoding.

	@ingroup grp_string
	*/
	class vkUTF32Lock : public vkStringLock
	{
	public :

		/**
		Constructor

		@param iString the string to lock in UTF32 Encoding.
		*/
		VKKERNEL_INL vkUTF32Lock(const vkString& iString);

		/**
		Gets a pointer to the locked characters
		in UTF32 Encoding.
		@return the locked characters.
		*/
		VKKERNEL_INL const char32*	CStr() const; 
	};

	/**
	This is a helper class for locking the characters
	of a string in WideChar Encoding.

	@ingroup grp_string
	*/
	class vkWideCharLock : public vkStringLock
	{
	public :
		
		/**
		Constructor

		@param iString the string to lock in UTF32 Encoding.
		*/
		VKKERNEL_INL vkWideCharLock(const vkString& iString);
		
		/**
		Gets a pointer to the locked characters
		in UTF32 Encoding.
		@return the locked characters.
		*/
		VKKERNEL_INL const wchar_t*	CStr() const; 
	};
	

	#include "vkStringLock.hpp"

}

/**
		Gets a pointer to the locked characters
		in UTF32 Encoding.
		@return the locked characters.
		*/

/**
This macro is a helper to get a locked const 
string buffer in the correct encoding.

Warning: Beware that the buffer in only valid in
the scope where the macro is called !
*/
#define VK_ASCII_CSTR(s) VKernel::vkASCIILock(s).CStr()
#define VK_UTF8_CSTR(s) VKernel::vkUTF8Lock(s).CStr()
#define VK_UTF16_CSTR(s) VKernel::vkUTF16Lock(s).CStr()
#define VK_UTF32_CSTR(s) VKernel::vkUTF32Lock(s).CStr()
#define VK_WCHAR_CSTR(s) VKernel::vkWideCharLock(s).CStr()

#endif // __vkStringLock_h



