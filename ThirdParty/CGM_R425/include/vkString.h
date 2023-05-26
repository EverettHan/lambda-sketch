/**
@file

This file defines the string Class.

@COPYRIGHT

@author Edwin Razafimahatratra
@author Gerald Guyomard
*/

#if !defined(__vkString_h)
#define __vkString_h

#if !defined(__vkKernelDefines_h)
#include "vkKernelDefines.h"
#endif
#if !defined(__vkKernelLib_h)
#include "vkKernelLib.h"
#endif
#if !defined(__vkUtil_h)
#include "vkUtil.h" // for hash functions
#endif
#if !defined(__vkStandardAllocator_h)
#include "vkStandardAllocator.h"
#endif
#if !defined(__vkCharacter_h)
#include "vkCharacter.h"
#endif
#if !defined(__vkCtxObject_h)
#include "vkCtxObject.h"
#endif
#if !defined(__vkArray_h)
#include "vkArray.h"
#endif
#if !defined(_CSTDIO_)
#include <cstdio> // va_list
#endif

namespace VKernel
{
	class vkStrMethods;
	class vkStringLockParams;
	class vkFourCC;
	struct vkStringAllocator;
	struct vkPoolAllocatorMethods;
	class vkType;

	/**
	This is the unique string class for @SDK_NAME.

	Main features are:
	- Full support of all encoded offered by vkCharacter (see vkCharacter::EEncoding) : ASCII & Unicode (UTF8, UTF16, UTF32).
	- Compatible with standard C Strings (null terminated strings).
	- Capable of storing its buffer in all the encodings. In most cases, you don't have to worry about it.
	- No memory allocation when referencing a static C String.
	- Sharing of buffers for string having the same content.
	- Minimal size occupation (8 bytes for an empty string).

	Note: there's no trivial operator [] available for directly accessing to a given character
	inside the string : for some encodings (UTF8 and UTF16), random access to characters
	can be very slow since it may contain characters with variable length that would cause
	a scan from the beginning.

	If you really want to access to a character via its position (logical position), use GetIterator.
	Iterators are the only way to access to characters or subparts of a string.

	@see vkCharacter

	@ingroup grp_string
	*/
	class VKKERNEL_API vkString : public vkHeapObject
	{
	public :
		static vkCtxTypePtr s_Type;

		/**
		String representing end of line characters depending on the platform.

		kEOL can be "\r\n" or "\r" or "\n".
		*/
		static const vkString	kEOL;

		/**
		String representing end of line characters depending on the platform.

		kEOLs contains "\r\n" or "\r" or "\n".
		*/
		static const vkString	kEOLs[3];

		/**
		The singleton null string.

		To test the emptiness of a string, better use IsEmpty()
		*/
		static const vkString	kNullString;

		/**
		The singleton NA string.
		*/
		static const vkString	kNA;


		/**
		ID of the allocators to use for
		managing internal buffers.
		@see vkString::Allocator, RegisterAllocator, UnregisterAllocator
		*/
		enum EAllocatorID
		{
			/** Standard allocation (via malloc & free). */
			eStdAllocator		= 0,
			/** Pooled allocation. You cannot use it for static vkString. */
			ePoolAllocator		= 1,

			/** Number of allocators */

			eAllocatorsCount,
			/** Default allocator. */
			eDefaultAllocator = ePoolAllocator
		};

		/**
		IDs of the type of EOL markers
		*/
		enum EEOLType {
			eDOS	= 0,
			eMac	= 1,
			eUnix	= 2
		};

		/**
		A const iterator is used to inspect the
		characters of the string (read-only).
		@see vkString::Iterator
		*/
		class VKKERNEL_API ConstIterator : public vkHeapObject
		{
			friend class vkString;

		public :

			/**
			Default Constructor

			When constructed via the default operator, the iterator is not valid.
			*/
			ConstIterator();

			/**
			Copy Constructor
			*/
			ConstIterator(const ConstIterator& iOther);

			/**
			Creates an iterator pointing to the character
			located at a particular character index.

			Index are logical position. Then you cannot assume
			that the index fits a physical byte offset.

			@param iString the string referenced by the iterator.
			@param iCharacterIndex  the index of the character [0; Length() - 1]
			*/
			ConstIterator(const vkString& iString, const uint32 iCharacterIndex = 0);

			/**
			Copy Operator

			@param iOther the iterator to copy

			@return a reference to the iterator
			*/
			ConstIterator&	operator=(const ConstIterator& iOther);

			/**
			Gets the string addressed by the iterator
			@return the pointed string.
			*/
			const vkString* GetString() const;

			/**
			Pre increment operator, goes to the next character.
			@return the modified iterator.
			*/
			ConstIterator&		operator++();

			/**
			Post increment operator, goes to the next character.
			@return a new iterator.
			*/
			ConstIterator		operator++(int);

			/**
			Pre decrement operator, goes to the previous character.
			@return the modified iterator.
			*/
			ConstIterator&		operator--();

			/**
			Post decrement operator, goes to the previous character.
			@return a new iterator.
			*/
			ConstIterator		operator--(int);

			/**
			Moves the iterator to a different position
			relative to the current one.

			@param iCharacterOffset > 0 : go 'iCharacterOffset' characters forward. < 0 : go 'iCharacterOffset' characters backward.

			@return the iterator pointing to the new position.
			*/
			ConstIterator&		operator+=(const int32 iCharacterOffset);

			/**
			Creates an iterator to a different position
			relative to the current one.

			@param iCharacterOffset > 0 : go 'iCharacterOffset' characters forward. < 0 : go 'iCharacterOffset' characters backward.

			@return a new iterator pointing to the new position.
			*/
			ConstIterator		operator+(const int32 iCharacterOffset) const;

			/**
			Moves the iterator to a different position
			relative to the current one.

			@param iCharacterOffset < 0 : go 'iCharacterOffset' characters forward. > 0 : go 'iCharacterOffset' characters backward.

			@return the iterator pointing to the new position.
			*/
			ConstIterator&		operator-=(const int32 iCharacterOffset);

			/**
			Creates an iterator to a different position
			relative to the current one.

			@param iCharacterOffset < 0 : go 'iCharacterOffset' characters forward. > 0 : go 'iCharacterOffset' characters backward.

			@return a new iterator pointing to the new position.
			*/
			ConstIterator		operator-(const int32 iLogicalOffset) const;

			/**
			Gets the distance (expressed in number of characters)
			between this iterator and another one.

			@param iOther the other iterator to measure the distance in characters

			@return the distance in characters between the current position
			and the position of the other iterator.
			*/
			int32	operator-(const ConstIterator& iOther) const;

			/**
			Compares the iterator with another one.

			@param iOther the other iterator to compare with.

			@return true if the 2 iterators point to the same location.
			*/
			bool	operator==(const ConstIterator& iOther) const;

			/**
			Compares the iterator with another one.

			@param iOther the other iterator to compare with.

			@return true if the 2 iterators do not point to the same location.
			*/
			bool	operator!=(const ConstIterator& iOther) const;

			/**
			Compares the position of the iterator with another one.

			@param iOther the other iterator to compare with.

			@return true if the position of the iterator is less than iOther.
			*/
			bool	operator<(const ConstIterator& iOther) const;

			/**
			Compares the position of the iterator with another one.

			@param iOther the other iterator to compare with.

			@return true if the position of the iterator is less than or equal to iOther.
			*/
			bool	operator<=(const ConstIterator& iOther) const;

			/**
			Compares the position of the iterator with another one.

			@param iOther the other iterator to compare with.

			@return true if the position of the iterator is greater than iOther.
			*/
			bool	operator>(const ConstIterator& iOther) const;

			/**
			Compares the position of the iterator with another one.

			@param iOther the other iterator to compare with.

			@return true if the position of the iterator is greater than or equal to iOther.
			*/
			bool	operator>=(const ConstIterator& iOther) const;

			/**
			Gets the character pointed by the iterator
			@return the pointed character.
			*/
			vkCharacter GetCharacter() const;

			/**
			Gets the character pointed by the iterator
			@return the pointed character.
			*/
			vkCharacter operator*() const;

			/**
			Gets the address of the current character
			@return the address of the pointed character.
			*/
			const char8* GetCharAddress() const;

			/**
			Gets the position in bytes of the current character
			relative to the start of the string.
			@return the position in bytes of the current character.
			*/
			uint32	GetBytePosition() const;

			/**
			Gets the number of characters between
			the start of the string and the current character.
			@return the number of characters between the current one
			and the start of the string.
			*/
			uint32	GetCharacterPosition() const;

			/**
			Tests the validity of the iterator for a given string

			@param iString the string referenced by the iterator.

			@return true if the iterator is valid (can be used for
			the string).
			*/
			bool	IsValid(const vkString& iString) const;

		protected :

#if !defined(VK_DOXYGEN)
			ConstIterator(const vkString* iString, char8* iCurrent);
			char8*				_GetCurrentChar() const;

			vkString*			m_String;
			char8*				m_Current;
#endif // VK_DOXYGEN
		};

		/**
		An iterator is used to inspect the
		the characters of the string. The iterator
		can modify the character pointed by it.
		@see vkString::ConstIterator
		*/
		class VKKERNEL_API Iterator : public ConstIterator
		{
			friend class vkString;
		public:

			/**
			Default Constructor

			When constructed via the default operator, the iterator is not valid.
			*/
			Iterator();

			/**
			Copy Constructor
			*/
			Iterator(const Iterator& iOther);

			/**
			Creates an iterator from a const iterator

			@param iConstIterator the iterator to construct from.
			*/
			explicit Iterator(const ConstIterator& iConstIterator);

			/**
			Creates an iterator pointing to the character
			located at a particular character index.

			index are logical position. Then you cannot assume
			that the index fits a physical byte offset.

			@param iString the string referenced by the iterator.
			@param iCharacterIndex the index of the character [0; Length() - 1]
			*/
			Iterator(vkString& iString, const uint32 iCharacterIndex = 0);

			/**
			Copy Operator

			@param iOther the iterator to copy

			@return a reference to the iterator
			*/
			Iterator& operator=(const Iterator& iOther);

			/**
			Gets the string addressed by the iterator
			@return the pointed string.
			*/
			vkString* GetString();

			/**
			Pre increment operator, goes to the next character.
			@return the modified iterator.
			*/
			Iterator&		operator++();

			/**
			Post increment operator, goes to the next character.
			@return a new iterator.
			*/
			Iterator		operator++(int);

			/**
			Pre decrement iterator, goes to the previous character.
			@return the modified iterator.
			*/
			Iterator&		operator--();

			/**
			Post decrement iterator, goes to the previous character.
			@return a new iterator.
			*/
			Iterator		operator--(int);

			/**
			Moves the iterator to a different position
			relative to the current one.

			@param iCharacterOffset > 0 : go 'iCharacterOffset' characters forward. < 0 : go 'iCharacterOffset' characters backward.

			@return the iterator pointing to the new position.
			*/
			Iterator&		operator+=(const int32 iCharacterOffset);

			/**
			Creates an iterator to a different position
			relative to the current one.

			@param iCharacterOffset > 0 : go 'iCharacterOffset' characters forward. < 0 : go 'iCharacterOffset' characters backward.

			@return the iterator pointing to the new position.
			*/
			Iterator		operator+(const int32 iCharacterOffset) const;

			/**
			Moves the iterator to a different position
			relative to the current one.

			@param iCharacterOffset < 0 : go 'iCharacterOffset' characters forward. > 0 : go 'iCharacterOffset' characters backward.

			@return the iterator pointing to the new position.
			*/
			Iterator&		operator-=(const int32 iCharacterOffset);

			/**
			Creates an iterator to a different position
			relative to the current one.

			@param iCharacterOffset < 0 : go 'iCharacterOffset' characters forward. > 0 : go 'iCharacterOffset' characters backward.

			@return the iterator pointing to the new position.
			*/
			Iterator		operator-(const int32 iLogicalOffset) const;

			/**
			Gets the distance (expressed in number of characters)
			between this iterator and another one.

			@param iOther the other iterator to measure the distance in characters

			@return the distance in characters between the current position
			and the position of the other iterator.
			*/
			int32	operator-(const Iterator& iOther) const;


			/**
			Changes the value of the current character

			@param iNewValue the new value of the current character.
			*/
			void				SetCharacter(const vkCharacter& iNewValue);

		protected:

			Iterator(const vkString* iString, char8* iCurrent);

		};

		/**
		Default value of the length.
		It means 'until of string'.
		@see RangeCompare
		*/
		enum { eDefaultLength = -1 };

		/**
		Default Constructor
		*/
		vkString();

		/**
		Copy Constructor
		*/
		vkString(const vkString& iOther);

		/**
		Constructs a string and reserves the buffer
		of characters.

		If iSizeInBytes = 0, then the string points to the "" string.

		@param iSizeInBytes the size to reserve for storing the characters.
		@param iInternalEncoding the encoding to use.
		@param iHasFixedEncoding if true then the encoding is fixed
		@param iAllocatorID the ID of the allocator to use.
		@param iHasFixedAllocator if true then the allocator is fixed
		*/
		vkString(vkCharacter::EEncoding iInternalEncoding, uint32 iSizeInBytes = 0, bool iHasFixedEncoding = true, EAllocatorID iAllocatorID = eDefaultAllocator, bool iHasFixedAllocator = true);

		/**
		Constructs a string which points to a C ASCII String.

		@param iASCIIString the C ASCII string.
		@param iInternalEncoding the encoding to use.
		@param iIsStatic if false, then an internal copy is done.
		@param iPrecomputedSize if != 0, then it's the size of the incoming string in bytes.
		@param iAllocatorID the ID of the allocator to use.
		@param iUTF8 if true the input string is in UTF8
		*/
		vkString(const char8* iASCIIString, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iIsStatic = true, uint32 iPrecomputedSize = 0, EAllocatorID iAllocatorID = eDefaultAllocator,bool iUTF8 = false);

		/**
		Constructs a string which points to a C ASCII String.

		@param iASCIIString the C ASCII string.
		@param iPrecomputedSize if != 0, then it's the size of the incoming string in bytes.
		*/
		vkString(const char8* iASCIIString, uint16 iPrecomputedSize);

		/**
		Constructs a string which points to a Widechar String.

		Depending on the platform, the internal encoding may be either UTF16 or UTF32

		@param iWideCharString the Wide char string.
		@param iPrecomputedSize if != 0, then it's the size of the incoming string in bytes.
		@param iIsStatic if false, then an internal copy is done
		*/
		vkString(const wchar_t* iWideCharString, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iIsStatic = true, uint32 iPrecomputedSize = 0, EAllocatorID iAllocatorID = eDefaultAllocator);

		/**
		Destructor
		*/
		~vkString();

		/**
		Copy Operator
		*/
		vkString&		operator=(const vkString& iOther);

		/**
		Makes the string points to a C string.

		If the string was owning a buffer, then
		this one is freed (unless the string has Fixed Encoding
		and internal encoding is different from the incoming C String).

		@param iString the source C String is an ASCII string
		*/
		vkString&		operator=(const char8* iString);

		/**
		Makes the string points to a C string.

		If the string was owning a buffer, then
		this one is freed (unless the string has Fixed Encoding
		and internal encoding is different from the incoming C String).

		@param iString the source C String is a wide char string
		*/
		vkString&		operator=(const wchar_t* iString);

		/**
		Initializes a string with another String
		encoded in various encoding.
		@param iString the string.
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		@param iAllocatorID the ID of the allocator used to allocate the copy.
		*/
		void CreateFromString(	const vkString& iOther,
			const vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding,
			bool iFixedEncoding = false,
			const EAllocatorID iAllocatorID = eDefaultAllocator);

		/**
		Initializes a string with a C String (w/ null terminated char)
		encoded in ASCII.
		@param iString the C string in ASCII.
		@param iSizeInBytes the size in bytes of the string.
		@param iIsStatic true if static (else make a local copy)
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		@param iAllocatorID the ID of the allocator used to allocate the copy.
		*/
		void CreateFromASCII(		const char8* iString,
			uint32 iSizeInBytes = 0,
			bool iIsStatic = false,
			const vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding,
			bool iFixedEncoding = false,
			const EAllocatorID iAllocatorID = eDefaultAllocator);

		/**
		Initializes a string with a C String (w/ null terminated char)
		encoded in UTF8.
		@param iString the C string in UTF8.
		@param iSizeInBytes the size in bytes of the string.
		@param iIsStatic true if static (else make a local copy)
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		@param iAllocatorID the ID of the allocator used to allocate the copy.
		*/
		void CreateFromUTF8(	const char8* iString,
			uint32 iSizeInBytes = 0,
			bool iIsStatic = false,
			const vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding,
			bool iFixedEncoding = false,
			const EAllocatorID iAllocatorID = eDefaultAllocator);

    /**
    Same as CreateFromUTF8 with default arguments, returning this.
    */
		vkString &AssignUTF8(const char8 *iString);

		/**
		Initializes a string with a C String (w/ null terminated char)
		encoded in UTF16.
		@param iString the C string in UTF16.
		@param iSizeInBytes the size in bytes of the string.
		@param iIsStatic true if static (else make a local copy)
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		@param iAllocatorID the ID of the allocator used to allocate the copy.
		*/
		void CreateFromUTF16(	const char16* iString,
			uint32 iSizeInBytes = 0,
			bool iIsStatic = false,
			const vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding,
			bool iFixedEncoding = false,
			const EAllocatorID iAllocatorID = eDefaultAllocator);

		/**
		Initializes a string with a C String (w/ null terminated char)
		encoded in UTF32.
		@param iString the C string in UTF32.
		@param iSizeInBytes the size in bytes of the string.
		@param iIsStatic true if static (else make a local copy)
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		@param iAllocatorID the ID of the allocator used to allocate the copy.
		*/
		void CreateFromUTF32(	const char32* iString,
			uint32 iSizeInBytes = 0,
			bool iIsStatic = false,
			const vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding,
			bool iFixedEncoding = false,
			const EAllocatorID iAllocatorID = eDefaultAllocator);

		/**
		Initializes a string with a C String (w/ null terminated char)
		encoded in wide char.
		@param iString the C string in wide char.
		@param iSizeInBytes the size in bytes of the string.
		@param iIsStatic true if static (else make a local copy)
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		@param iAllocatorID the ID of the allocator used to allocate the copy.
		*/
		void CreateFromWideChar(	const wchar_t* iString,
			uint32 iSizeInBytes = 0,
			bool iIsStatic = false,
			const vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding,
			bool iFixedEncoding = false,
			const EAllocatorID iAllocatorID = eDefaultAllocator);

		/**
		These are helpers to simplify call to CreateFrom...\ when
		the string is aimed to persist after Kernel engine (not recommended).

		@param iString the C string.
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		*/
		//@{
		void CreatePersistentFromString(const vkString& iOther, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iFixedEncoding = false);
		void CreatePersistentFromASCII(const char8* iString, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iFixedEncoding = false);
		void CreatePersistentFromUTF8(const char8* iString, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iFixedEncoding = false);
		void CreatePersistentFromUTF16(const char16* iString, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iFixedEncoding = false);
		void CreatePersistentFromUTF32(const char32* iString, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iFixedEncoding = false);
		void CreatePersistentFromWideChar(const wchar_t* iString, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iFixedEncoding = false);
		//@}

		/**
		Create from part of another string
		@param iStart start iterator on the source string
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		@param iAllocatorID the ID of the allocator used to allocate the copy.
		*/
		void CreateSubString(const ConstIterator& iStart, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iFixedEncoding = false, EAllocatorID iAllocatorID = eDefaultAllocator);

		/**
		Create from part of another string
		@param iStart start iterator on the source string
		@param iEnd end iterator on the source string
		@param iInternalEncoding the internal encoding in which the copy is stored.
		@param iFixedEncoding if true, then use fixed encoding.
		@param iAllocatorID the ID of the allocator used to allocate the copy.
		*/
		void CreateSubString(const ConstIterator& iStart, const ConstIterator& iEnd, vkCharacter::EEncoding iInternalEncoding = vkCharacter::eDefaultEncoding, bool iFixedEncoding = false, EAllocatorID iAllocatorID = eDefaultAllocator);

		/**
		Gets the internal encoding.
		@return the internal encoding.
		*/
		vkCharacter::EEncoding	GetEncoding() const;

		/**
		Sets a new internal encoding.

		The old content is preserved (but converted
		to match the new encoding).

		@param iEncoding the new encoding.
		@param iForce true to force the encoding even if fixed mode.
		This option is very dangerous. Make sure you really want to force encoding.
		@return errInvalidState if attempted to change the encoding in fixed mode.
		*/
		error SetEncoding(const vkCharacter::EEncoding iEncoding, bool iForce=false);

		/**
		Tests if fixed encoding is enabled.
		When enabled, the string will always keep the same
		encoding, unless an explicit call to SetEncoding
		is done.
		@return true if fixed encoding is enabled.
		@see EnableFixedEncoding, SetFixedEncoding
		*/
		bool HasFixedEncoding() const;

		/**
		Enables the fixed encoding.
		@see HasFixedEncoding, SetFixedEncoding
		*/
		void EnableFixedEncoding();

		/**
		Sets a new internal encoding and enables
		the fixed encoding.
		Note : You cannot change twice the fixed encoding of a string.
		This is due to a ensure the compatibility with future vkUTF8String
		class.
		@param iFixedEncoding the new encoding.
		@return errInvalidState if the string already has
		a fixed encoding different from the specified one

		@see EnableFixedEncoding, SetFixedEncoding
		*/
		error SetFixedEncoding(const vkCharacter::EEncoding iFixedEncoding);

		/**
		Gets the ID of the allocator used for
		memory management of the internal buffer.
		*/
		EAllocatorID	GetAllocatorID() const;

		/**
		Sets a new allocator for this string.
		If the new allocator is different and the string is not static,
		then a new buffer is allocated with this new allocator.
		@param iAllocatorID the ID of the allocator
		*/
		void SetAllocatorID(EAllocatorID iAllocatorID);

		/**
		Sets a new allocator for this string.
		If the new allocator is different and the string is not static,
		then a new buffer is allocated with this new allocator.
		When being assigned from another string, the allocator is not changed.
		A new call to SetFixedAllocatorID can only change the allocator
		@param iAllocatorID the ID of the allocator
		*/
		void SetFixedAllocatorID(EAllocatorID iAllocatorID);

		/**
		Tells if the allocator if this string is fixed.
		In this case, the allocator cannot be changed by an assignement.
		@return true if the allocator is fixed
		*/
		bool HasFixedAllocator() const;

		/**
		Enables of disables the fixed allocator.
		@param iEnable if true then the allocator cannot be implicitely changed
		by a future assignement
		*/
		void EnabledFixedAllocator(bool iEnable);

		/**
		Updates the internal flag indicating that
		all characters have the same byte size.
		*/
		void		UpdateConstantCharSizeFlag();

		/**
		Tests if the string points to a static string.
		@return true if the pointed buffer is static.
		*/
		bool			IsStatic() const;

		/**
		Gets a raw pointer to first character.

		Always keep in mind that the string is
		polymorphic and can store the characters in multiple
		encodings. To be safer, prefer using Lock scheme
		to access the characters in a particular format.

		@return the pointer to the first character.
		*/
		const char8* GetChars() const;

		/**
		Gets a raw pointer to the trailing null character.

		Always keep in mind that the string is
		polymorphic and can store the characters in multiple
		encodings. To be safer, prefer using Lock scheme
		to access the characters in a particular format.

		@return the pointer to the null character.
		*/
		const char8* GetEndChars() const;

		/**
		Gets a raw pointer to the buffer, assuming
		the internal encoding is ASCII.

		An assert is raised in debug if there's
		an encoding mismatch.

		@return the pointer to the internal ASCII string.
		*/
		const char8*	ASCIICStr() const;

		/**
		Gets a raw pointer to the buffer, assuming
		the internal encoding is UTF8.

		An assert is raised in debug if there's
		an encoding mismatch.

		@return the pointer to the internal UTF8 string.
		*/
		const char8*	UTF8CStr() const;

		/**
		Gets a raw pointer to the buffer, assuming
		the internal encoding is UTF16.

		An assert is raised in debug if there's
		an encoding mismatch.

		@return the pointer to the internal UTF16 string.
		*/
		const char16*	UTF16CStr() const;

		/**
		Gets a raw pointer to the buffer, assuming
		the internal encoding is wchar_t.

		An assert is raised in debug if there's
		an encoding mismatch.

		@return the pointer to the internal WideChar string.
		*/
		const wchar_t*	WideCharCStr() const;

		/**
		Gets a raw pointer to the buffer, assuming
		the internal encoding is UTF32.

		An assert is raised in debug if there's
		an encoding mismatch.

		@return the pointer to the internal UTF32 string.
		*/
		const char32*	UTF32CStr() const;

		/**
		Computes the hash key.

		The hash key is base upon the logical characters,
		then is not dependent on the internal encoding.

		@return the pointer to the internal UTF32 string.
		*/
		uint32			Hash() const;

		//@{
		/**
		Gets an iterator pointing to the first character
		@return an iterator on the first character.

		@code
		vkString s = "Hello World";
		for (vkString::ConstIterator it=s.Begin(); it != End(); ++it) {
		vkCharacter currentChar = *it;
		}
		@endcode
		@see End
		*/
		Iterator		Begin();
		ConstIterator	Begin() const;
		//@}

		//@{
		/**
		Gets an iterator pointing to the end of the string.
		This corresponds to the null character.
		@return an iterator on the end of the string.
		@see Begin
		*/
		Iterator		End();
		ConstIterator	End() const;
		//@}

		//@{
		/**
		Gets an iterator pointing to the last character.
		You can use RBegin and REnd to iterate backward
		on a string.
		@return an iterator on the last character.

		@code
		vkString s = "Hello World";
		for (vkString::ConstIterator it=s.RBegin(); it != REnd(); --it) {
		vkCharacter currentChar = *it;
		}
		@endcode
		@see REnd
		*/
		Iterator		RBegin();
		ConstIterator	RBegin() const;
		//@}

		//@{
		/**
		Gets an iterator pointing just before the first
		character of the string.
		This is used as the stopping iterator when iterating
		backward on a string.
		@return an iterator on the end of the string.
		@see RBegin
		*/
		Iterator	  REnd();
		ConstIterator REnd() const;
		//@}

		/**
		Gets the first character of the string.

		If the string is empty, then a null character
		is returned.

		@return the first character of the string.

		@see vkCharacter, IsEmpty, Back
		*/
		vkCharacter Front() const;

		/**
		Gets the last character of the string.

		If the string is empty, then a null character
		is returned.

		@return the last character of the string.

		@see vkCharacter, IsEmpty, Front
		*/
		vkCharacter Back() const;

		/**
		Empties the string.

		After call, IsEmpty() returns true.

		The internal buffer is not actually freed. It's kept
		for later reuse, and then avoid new reallocation.
		*/
		void			Empty();

		/**
		Clears the string.

		After call, IsEmpty() returns true.

		The main difference between Empty() and Clear()
		is that Clear actually free the internal buffer if possible.
		*/
		void			Clear();

		/**
		Makes the string unique.
		if the string points to a static string
		or its buffer of characters is shared by other string,
		then this method makes sure that the string is the only
		owner of the buffer after call.
		@return true if the string just turned unique or false if it was previously unique
		*/
		bool			Unique();

		/**
		Tests if the string is unique.
		*/
		bool				IsUnique() const;

		/**
		Swaps the content of two strings.

		No memory allocation nor characters copy are done.
		*/
		void			Swap(vkString& iOther);

		/**
		Tests if the string is empty
		@return true if the string is empty.
		*/
		bool IsEmpty() const;

		/**
		Gets the size in bytes taken by the characters
		(trailing null character included).
		@return the size in bytes of the characters.
		*/
		uint32 Size() const;

		/**
		Defines the maximum size of "small strings".
		Such strings are potentially must efficient
		than large ones.
		@see IsLarge
		@see IsSmall
		*/
		enum
		{
			kSmallStringMaxSize = 65535
		};

		/**
		Tells if this string has a small size.
		Small size is < kSmallStringMaxSize.
		@return true if the string is small
		*/
		bool IsSmall() const;

		/**
		Tells if this string has a large size.
		Large size is size > 65535 bytes.
		@return true if the string is large
		*/
		bool IsLarge() const;

		/**
		Gets the size in bytes taken by the characters
		(trailing null character NOT included).

		Never assume that ByteLength() == Length(). It may
		occur in particular case (encoding = ASCII
		or encoding=UTF8 and strict-Ascii characters), but i's not
		the common case.

		@return the size in bytes of the characters, trailing
		null char excluded.
		*/
		uint32 ByteLength() const;

		/**
		Gets the size in bytes taken by one character unit.

		A character unit is the smallest memory unit taken by a character
		inside the string.

		<TABLE>
		Encoding	Unit Size in bytes
		--------	------------------
		ASCII		1
		UTF8		1
		UTF16		2
		UTF32		4
		</TABLE>

		@return the size of one unit.
		*/
		uint32 UnitSize() const;

		/**
		Gets the power of 2 of one character unit.

		That is to say, UnitSize() == 1 << UnitPow2()

		<TABLE>
		Encoding	Power Of 2
		--------	------------------
		ASCII		0
		UTF8		0
		UTF16		1
		UTF32		2
		</TABLE>

		This data can be used to perform fast multiplication
		(using bit shift instead of regular MULs).

		@return the power of 2 of a character unit.
		*/
		uint32 UnitPow2() const;

		/**
		Gets the number of character units
		(trailing null unit NOT included).

		UnitLength() == ByteLength() / UnitSize();

		@return the number of character units, trailing
		null char excluded.
		*/
		uint32 UnitLength() const;

		/**
		Gets the number of characters in the string.
		(trailing null character NOT included).

		Try not using this method since it may
		occur performance penalty (if HasConstantCharSize() == false,
		then a complete scan of the internal buffer is done).

		@return the length.
		*/
		uint32 Length() const;

		/**
		Gets the reserved bytes in the buffer.

		@return the reserved bytes in the buffer.

		@see Reserve
		*/
		uint32 Capacity() const;

		/**
		Tests if all the characters have
		the same byte size.

		Some encodings may not have constant char size:
		- UTF8 : if there are some non-strict ANSI ASCII Characters (European
		or Eastern languages for instance).
		- UTF16: some languages use two surrogates for representing a character
		(Japanese for example).

		@return true if all the characters have
		the same byte size.
		*/
		bool HasConstantCharSize() const;

		/**
		Tests if all characters are non-Strict ANSI.

		Two cases :
		- ASCII : of course all ASCII strings return true for Ascii().
		- UTF8: only strings with strict-ansi chars return true for Ascii().

		@return true if the string is Ascii.
		*/
		bool			IsAscii() const;

		//@{
		/**
		Gets an iterator pointing to a character
		located at a desired index.

		This method is somewhat similar to regular
		operator[] from other String APIs. Nevertheless, be
		warned that using this method may be time consuming
		on strings that don't have constant size characters.

		@param iCharacterIndex the index of the pointed character.

		@return the iterator.
		*/
		Iterator		GetIterator(const uint32 iCharacterIndex = 0);
		ConstIterator	GetIterator(const uint32 iCharacterIndex = 0) const;
		//@}

		/**
		Sets the character pointed by an iterator.

		@param iIterator iterator pointing to the character to change.
		@param iNewValue the new character's value.

		@return returns true if the character replacement implied
		a reallocation or memory move, and then Begin() & End()
		have changed.
		*/
		bool			SetCharacter(Iterator& iIterator, const vkCharacter& iNewValue);

		//@{
		/**
		Compares the string with another one.
		For ICompare, the case is ignored.

		@param iOther the other string to compare with.

		@return
		<  0 : mySelf < iOther
		== 0 : mySelf == iOther.
		>  0 : mySelf > iOther.
		*/
		int32			Compare(const vkString& iOther) const;
		int32			ICompare(const vkString& iOther) const;
		int32			operator-(const vkString& iOther) const;
		//@}

		//@{
		/**
		Compares the string with a C String.

		Comparison is case sensitive.

		@param iString the other string to compare with.
		@param iIsASCII true if iString is ASCII, false if it's UTF8.

		@return
		<  0 : mySelf < iString
		== 0 : mySelf == iString.
		>  0 : mySelf > iString.
		*/
		int32			Compare(const char8* iString, bool iIsASCII = true) const;
		int32			Compare(const char16* iString) const;
		int32			Compare(const char32* iString) const;
		//@}

		//@{
		/**
		Compares the first 'iLength' characters of the string
		with the first 'iLength' characters of an another one.
		For IRangeCompare, case is ignored.

		@param iOther the other string to compare with.
		@param iLength the number of characters to compare. If iLength == eDefaultLength,
		then all the characters of iOther are taken into account.

		@return
		<  0 : mySelf < iOther
		== 0 : mySelf == iOther.
		>  0 : mySelf > iOther.
		*/
		int32 RangeCompare(const vkString& iOther, int32 iLength = eDefaultLength) const;
		int32 IRangeCompare(const vkString& iOther, int32 iLength = eDefaultLength) const;
		//@}

		//@{
		/**
		Compares the 'iLength' characters of the string
		starting at iThisStart with the first 'iLength' characters
		of an another string.
		For IRangeCompare, case is ignored.

		@param iOther the other string to compare with.
		@param iThisStart the position in the string to start the comparison.
		@param iLength the number of characters to compare. If iLength == eDefaultLength,
		then all the characters of iOther are taken into account.

		@return
		<  0 : mySelf < iOther
		== 0 : mySelf == iOther.
		>  0 : mySelf > iOther.
		*/
		int32 RangeCompare(const vkString& iOther, const ConstIterator& iThisStart, int32 iLength = eDefaultLength) const;
		int32 IRangeCompare(const vkString& iOther, const ConstIterator& iThisStart, int32 iLength = eDefaultLength) const;
		//@}

		//@{
		/**
		Compares the 'iLength' characters of the string
		starting at iThisStart with the 'iLength' characters
		of an another string starting at iOtherStart.
		For IRangeCompare, case is ignored.

		@param iOther the other string to compare with.
		@param iThisStart the position in the string to start comparison.
		@param iOtherStart the position in the other string to start comparison.
		@param iLength the number of characters to compare. If iLength == eDefaultLength,
		then the comparison is done until the end of iOther.

		@return
		<  0 : mySelf < iOther
		== 0 : mySelf == iOther.
		>  0 : mySelf > iOther.
		*/
		int32			RangeCompare(const vkString& iOther, const ConstIterator& iThisStart, const ConstIterator& iOtherStart, int32 iLength = eDefaultLength) const;
		int32			IRangeCompare(const vkString& iOther, const ConstIterator& iThisStart, const ConstIterator& iOtherStart, int32 iLength = eDefaultLength) const;
		//@}

		//@{
		/**
		Tests if this strings equals another one in the given range.
		@param iStart iterator in this string defining the beginning of the comparison
		@param iPattern sub string to compare with
		@param oItAfterPattern if not null, then this iterator points to the character following the pattern in the string if matching. Otherwise
		the iterator is not modified.
		@return true if the sub string defined either by iPattern or by [iPatternStart, iPatternEnd] equals the sub string starting at iStart
		in this string.
		*/
		bool RangeEquals(const vkString::ConstIterator& iStart, const vkString& iPattern, vkString::ConstIterator* oItAfterPattern = 0) const;
		bool RangeEquals(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iPatternStart, const vkString::ConstIterator& iPatternEnd, vkString::ConstIterator* oItAfterPattern = 0) const;
		//@}

		//@{
		/**
		Tests if this string starts with the characters
		contained in another string.
		For IStartsWith, case is ignored.

		@param iOther the other string to compare with.

		@return true if this string starts with the other one.

		@code
		vkString s1 = "Hello world";
		VKASSERT(s1.StartsWith("Hello")); // "s1 should start with Hello"
		VKASSERT(s1.StartsWith("Hello world !!!")); // "s1 should not start with Hello world !!!"
		VKASSERT(s1.IStartsWith("Hello")); // "s1 should start with Hello"
		VKASSERT(s1.IStartsWith("HeLLo")); // "s1 should start with HeLLo"
		@endcode
		*/
		bool			StartsWith(const vkString& iOther) const;
		bool			IStartsWith(const vkString& iOther) const;
		//@}

		//@{
		/**
		Tests if this string ends with the characters
		contained in another string.
		For IEndsWith, case is ignored.

		@param iOther the other string to compare with.

		@return true if this string ends with the other one.

		@code
		vkString s1 = "Hello world";
		VKASSERT(s1.EndsWith("world")); // "s1 should end with world"
		VKASSERT(s1.IEndsWith("WORLD")); // "s1 should end with world"
		@endcode
		*/
		bool			EndsWith(const vkString& iOther) const;
		bool			IEndsWith(const vkString& iOther) const;
		//@}

		//@{
		/**
		Tests if this string match a pattern contained in another string.


		The pattern can contains wildcards as '*' and '?'.
		- '*' means any sequence of 0 or more characters
		- '?' means any single character

		For example:
		- "*.*" matches "test.jpg", ".dir", "info.", etc.
		- "test0??" matches "test091", "test0ab", "test000", etc.

		For IMatch, case is ignored.

		@param iPattern the pattern to match.
		@param iThisStart starting iterator in iPattern
		@param iThisEnd

		@return true if this string matchs the regular expression.
		*/
		bool			Match(const vkString& iPattern) const;
		bool			Match(const vkString& iPattern, const ConstIterator& iThisStart, const ConstIterator& iThisEnd) const;
		bool			IMatch(const vkString& iPattern) const;
		bool			IMatch(const vkString& iPattern, const ConstIterator& iThisStart, const ConstIterator& iThisEnd) const;
		//@}

		/**
		Tests if the string equals another one
		(case sensitive).

		@param iOther the string to compare with.

		@return true if the 2 strings are equal.
		*/
		bool			operator==(const vkString& iOther) const;
		//bool			operator==(const vkCharacter& iCharacter) const;

		//@{
		/**
		Tests if the string equals a C String.
		(case sensitive).

		ASCII encoding is assumed for the char8 C String.

		@param iString the C string to compare with.

		@return true if the 2 strings are equal.
		*/
		bool			operator==(const char8* iString) const;
		bool			operator==(const char16* iString) const;
		bool			operator==(const char32* iString) const;
		//@}

    /**
    Explicit overload for comparing to UTF8
    */
    bool      EqualsUTF8(const char8* iUTF8String) const;

		//@{
		/**
		Tests if the string is different from a C String.
		(case sensitive).

		ASCII encoding is assumed for the char8 C String.

		@param iString the C string to compare with.

		@return true if the 2 strings are equal.
		*/
		bool operator!=(const vkString& iOther) const;
		bool operator!=(const char8* iString) const;
		//@}

    /**
    Explicit overload for differing to UTF8
    */
    bool DiffersUTF8(const char8* iUTF8String) const;

		//@{
		/**
		Lexicographic String Comparison
		(case sensitive).

		@param iOther the string to compare with.

		@return true if the comparison succeeded.
		*/
		bool			operator<(const vkString& iOther) const;
		bool			operator<=(const vkString& iOther) const;
		bool			operator>(const vkString& iOther) const;
		bool			operator>=(const vkString& iOther) const;
		//@}

		//@{
		/**
		Finds the first occurrence of a character
		inside the string.
		For IFind, case is ignored.

		@param iCharacter the character to find.

		@return an iterator pointing on the first occurrence
		of iCharacter. If Find failed, then the returned iterator == End()
		*/
		ConstIterator Find(const vkCharacter& iCharacter) const;
		ConstIterator IFind(const vkCharacter& iChar) const;
		//@}

		//@{
		/**
		Finds the first occurrence of a character
		inside the string starting at a particular position.
		For IFind, case is ignored.

		@param iCharacter the character to find.
		@param iStart the start position.

		@return an iterator pointing on the first occurrence
		of iCharacter. If Find failed, then the returned iterator == End()
		*/
		ConstIterator Find(const vkCharacter& iChar, const ConstIterator& iStart) const;
		ConstIterator IFind(const vkCharacter& iChar, const ConstIterator& iStart) const;
		//@}

		//@{
		/**
		Finds the first occurrence of a character
		inside the string in a particular range.
		For IFind, case is ignored.

		@param iCharacter the character to find.
		@param iStart the start position of the range.
		@param iEnd the start position of the range.

		@return an iterator pointing on the first occurrence
		of iCharacter. If Find failed, then the returned iterator == End()
		*/
		ConstIterator	Find(const vkCharacter& iChar, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		ConstIterator	IFind(const vkCharacter& iChar, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		//@}

		//@{
		/**
		Finds the first occurrence of another string
		inside the string.
		For IFind, case is ignored.

		@param iOther the other string to find inside this string.

		@return an iterator pointing on the first character
		of the first occurrence of iOther.
		If Find failed, then the returned iterator == End()
		*/
		ConstIterator	Find(const vkString& iOther) const;
		ConstIterator	IFind(const vkString& iOther) const;
		//@}

		//@{
		/**
		Finds the first occurrence of another string
		inside the string starting at a particular position.
		For IFind, case is ignored.

		@param iOther the other string to find.
		@param iThisStart the start position inside this string.

		@return an iterator pointing on the first character of the
		first occurrence of iOther.
		If Find failed, then the returned iterator == End()
		*/
		ConstIterator	Find(const vkString& iOther, const ConstIterator& iThisStart) const;
		ConstIterator	IFind(const vkString& iOther, const ConstIterator& iThisStart) const;
		//@}

		//@{
		/**
		Finds the first occurrence of another string
		inside the string in a particular range.
		For IFind, case is ignored.

		@param iOther the string to find.
		@param iStart the start position of the range inside this string.
		@param iEnd the start position of the range inside this string.

		@return an iterator pointing on the first character of the first
		occurrence of iOther.
		If Find failed, then the returned iterator == End()
		*/
		ConstIterator	Find(const vkString& iOther, const ConstIterator& iThisStart, const ConstIterator& iThisEnd) const;
		ConstIterator	IFind(const vkString& iOther, const ConstIterator& iThisStart, const ConstIterator& iThisEnd) const;
		//@}

		//@{
		/**
		Finds the last occurrence of a character
		inside the string.
		For IFindLast, case is ignored.

		@param iCharacter the character to find.

		@return an iterator pointing on the last occurrence
		of iCharacter. If FindLast failed, then the returned iterator == End()
		*/
		ConstIterator	FindLast(const vkCharacter& iChar) const;
		ConstIterator	IFindLast(const vkCharacter& iChar) const;
		//@}

		//@{
		/**
		Finds the last occurrence of a character
		inside the string starting at a particular position.
		For IFindLast, case is ignored.

		@param iCharacter the character to find.
		@param iStart the start position.

		@return an iterator pointing on the last occurrence
		of iCharacter. If FindLast failed, then the returned iterator == End()
		*/
		ConstIterator	FindLast(const vkCharacter& iChar, const ConstIterator& iStart) const;
		ConstIterator	IFindLast(const vkCharacter& iChar, const ConstIterator& iStart) const;
		//@}

		//@{
		/**
		Finds the last occurrence of a character
		inside the string in a particular range.
		For IFindLast, case is ignored.

		@param iCharacter the character to find.
		@param iStart the start position of the range.
		@param iEnd the start position of the range.

		@return an iterator pointing on the last occurrence
		of iCharacter. If FindLast failed, then the returned iterator == End()
		*/
		ConstIterator	FindLast(const vkCharacter& iChar, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		ConstIterator	IFindLast(const vkCharacter& iChar, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		//@}

		//@{
		/**
		Finds the last occurrence of another string
		inside the string.
		For IFindLast, case is ignored.

		@param iOther the other string to find inside this string.

		@return an iterator pointing on the first character
		of the last occurrence of iOther.
		If FindLast failed, then the returned iterator == End()
		*/
		ConstIterator	FindLast(const vkString& iOther) const;
		ConstIterator	IFindLast(const vkString& iOther) const;
		//@}

		//@{
		/**
		Finds the last occurrence of another string
		inside the string starting at a particular position.
		For IFindLast, case is ignored.

		@param iOther the other string to find.
		@param iThisStart the start position inside this string.

		@return an iterator pointing on the first character of the
		last occurrence of iOther.
		If FindLast failed, then the returned iterator == End()
		*/
		ConstIterator	FindLast(const vkString& iOther, const ConstIterator& iThisStart) const;
		ConstIterator	IFindLast(const vkString& iOther, const ConstIterator& iThisStart) const;
		//@}

		//@{
		/**
		Finds the last occurrence of another string
		inside the string in a particular range.
		For IFindLast, case is ignored.

		@param iOther the string to find.
		@param iStart the start position of the range inside this string.
		@param iEnd the start position of the range inside this string.

		@return an iterator pointing on the first character of the last
		occurrence of iOther.
		If FindLast failed, then the returned iterator == End()
		*/
		ConstIterator	FindLast(const vkString& iOther, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		ConstIterator	IFindLast(const vkString& iOther, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		//@}

		//@{
		/**
		Tests if a the string contains a particular character.
		For IContains, case is ignored.

		@param iCharacter the character to find

		@return true if the string contains the character.
		*/
		bool Contains(const vkCharacter& iCharacter) const;
		bool IContains(const vkCharacter& iCharacter) const;
		bool Contains(const vkCharacter* iCharacter, uint32 iSeparatorCount) const;
		//@}

		//@{
		/**
		Tests if a the string contains a particular character
		in a given range.
		For IContains, case is ignored.

		@param iCharacter the character to find.
		@param iStart start of the search range.
		@param iEnd end of the search range.

		@return true if the string contains the character.
		*/
		bool			Contains(const vkCharacter& iCharacter, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		bool			IContains(const vkCharacter& iCharacter, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		bool			Contains(const vkCharacter* iCharacter, uint32 iSeparatorCount, const ConstIterator& iStart, const ConstIterator& iEnd) const;
		//@}

		//@{
		/**
		Tests if a the string contains another string.
		For IContains, case is ignored.

		@param iOther the other string to find.

		@return true if the string contains the other string.
		*/
		bool Contains(const vkString& iOther) const;
		bool IContains(const vkString& iOther) const;
		//@}

		//@{
		/**
		Tests if a the string contains a particular character
		in a given range.
		For IContains, case is ignored.

		@param iOther the other string to find.
		@param iStart start of the search range inside the string.
		@param iEnd end of the search range inside the string.

		@return true if the string contains the other string.
		*/
		bool			Contains(const vkString& iOther, const ConstIterator& iThisStart, const ConstIterator& iThisEnd) const;
		bool			IContains(const vkString& iOther, const ConstIterator& iThisStart, const ConstIterator& iThisEnd) const;
		//@}

		/**
		Gets the substring starting at position iStart.

		The substring uses the same encoding and allocator than this string.

		@param iStart position defining the start of the substring.

		@return the sub string.
		*/
		vkString		SubString(const ConstIterator& iStart) const;

		/**
		Gets the substring defined by the range [iStart, iEnd[.

		The substring uses the same encoding and allocator than this string.

		@param iStart position defining the start of the substring.
		@param iEnd position defining the end of the substring.

		@return the sub string.
		*/
		vkString		SubString(const ConstIterator& iStart, const ConstIterator& iEnd) const;

		/**
		Removes all the characters located BEFORE iStart
		and keeps those after iStart (the one pointed by iStart included).

		Iterator iStart is invalid after call.

		@param iStart start position of the crop.

		@return a reference to this string.
		*/
		vkString& Crop(const ConstIterator& iStart);

		/**
		Removes all the characters located BEFORE iStart and
		those located after iEnd.

		It only keeps the characters between iStart & iEnd.
		Iterators iStart & iEnd are invalid after call.

		@param iStart start position of the crop.
		@param iEnd end position of the crop.

		@return a reference to this string.
		*/
		vkString&		Crop(const ConstIterator& iStart, const ConstIterator& iEnd);

		/**
		Removes all the characters located AFTER iStart
		(the one pointed by iStart included) and keeps those
		BEFORE iStart.

		Iterator iStart is invalid after call.

		@param iStart start position of the cut.

		@return a reference to this string.
		*/
		vkString& Cut(const ConstIterator& iStart);

		/**
		Removes all the characters located BETWEEN
		iStart (included) and iEnd(excluded).

		Iterators iStart & iEnd are invalid after call.

		@param iStart start position of the cut.
		@param iEnd end position of the cut.

		@return a reference to this string.
		*/
		vkString&		Cut(const ConstIterator& iStart, const ConstIterator& iEnd);

		//@{
		/**
		Replaces all the occurences of a particular
		character by a new value.
		For IReplace, case is ignored.

		@param iCharacterToReplace the character to replace.
		@param iNewValue the new value of the character.

		@return the number of replaced characters.
		*/
		uint32 Replace(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue);
		uint32 IReplace(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue);
		//@}

		//@{
		/**
		Replaces all the occurences of a particular
		character by a new value in a given range [iStart, iEnd[.

		Iterator iStart & iEnd are invalid after call.

		@param iCharacterToReplace the character to replace.
		@param iNewValue the new value of the character.
		@param itart: start of the range.
		@param iEnd end of the range.

		@return the number of replaced characters.
		*/
		uint32			Replace(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32			IReplace(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		//@}

		//@{
		/**
		Replaces all the occurrences of a collection of ASCII characters.
		This method is much faster than calling in a row Replace(one char) multiple times.

		@param iCharactersToReplace the characters to replace.
		@param iNewValue the new value of the character.
		@param iCount the number of elements in array iCharactersToReplace
		@param iStart start of the range.
		@param iEnd end of the range.
		@return the number of replacements.
		*/
		uint32			Replace(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue);
		uint32			Replace(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		//@}

		//@{
		/**
		Replaces all the occurences of a particular
		sub string by a new value.
		For IReplace, case is ignored.

		@param iSubStringToReplace the sub string to replace.
		@param iNewValue the new value of the sub string.

		@return the number of replacements.
		*/
		uint32 Replace(const vkString& iSubStringToReplace, const vkString& iNewValue);
		uint32 IReplace(const vkString& iSubStringToReplace, const vkString& iNewValue);
		//@}

		//@{
		/**
		Replaces all the occurences of a particular
		sub string, which lie in a given range, by a new value.
		For IReplace, case is ignored.

		@param iSubStringToReplace the sub string to replace.
		@param iNewValue the new value of the sub string.
		@param iStart start of the range.
		@param iEnd end of the range.

		@return the number of replacements.
		*/
		uint32 Replace(const vkString& iSubStringToReplace, const vkString& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 IReplace(const vkString& iSubStringToReplace, const vkString& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		//@}

		/**
		Inserts a character at a particular position.

		@param iPosition location of the insertion.
		@param iCharacter the character to insert.
		*/
		void Insert(const ConstIterator& iPosition, const vkCharacter& iCharacter);

		/**
		Inserts a string at a particular position.

		@param iPosition location of the insertion.
		@param iOther the string to insert.
		*/
		void Insert(const ConstIterator& iPosition, const vkString& iOther);

		/**
		Inserts the end of another string at a particular position.

		@param iPosition location of the insertion.
		@param iOther the string to insert.
		@param iOtherStart the iterator pointing to the first character of iOther to insert.
		*/
		void Insert(const ConstIterator& iPosition, const vkString& iOther, const ConstIterator& iOtherStart);

		/**
		Inserts a part of another string at a particular position.

		@param iPosition location of the insertion.
		@param iOther the string to insert.
		@param iOtherStart this defines the start of the substring to insert.
		@param iOtherEnd this defines the end of the substring to insert.
		*/
		void Insert(const ConstIterator& iPosition, const vkString& iOther, const ConstIterator& iOtherStart, const ConstIterator& iOtherEnd);

		/**
		Removes all the heading and trailing separators.
		@return a reference to this string.
		@see vkCharacter::IsSeparator
		*/
		vkString& Trim();

		/**
		Splits a string using a provided separator string.
		@param iSeparator the separator to use for splitting
		@return the list of splitted strings
		*/
		vkArray<vkString> Split(const vkString& iSeparator) const;

		/**
		Appends another string.

		@param iOther the string to append.

		@return a reference to this string.
		*/
		vkString& operator<<(const vkString& iOther);

		//@{
		/**
		Appends a C String.

		The internal encoding is not modified.

		@param iASCIIString the ASCII C String to append.
		@param iUTF16String the UTF16 C String to append.
		@param iUTF32String the UTF32 C String to append.

		@return a reference to this string.
		*/
		vkString&		operator<<(const char8* iASCIIString);
		vkString&		operator<<(const char16* iUTF16String);
		vkString&		operator<<(const char32* iUTF32String);

#if defined(VK_WCHAR_T_IS_BUILT_IN)
		vkString&		operator<<(const wchar_t* iWideCharString);
#endif
		//@}

    /**
    Explicit overload for appending UTF8
    */
    // bool AppendUTF8(const char8* iUTF8String) const;

		//@{
		/**
		Appends a character.

		The internal encoding is not modified.

		@param iCharacter the logical character to append.
		@param iASCIICharacter the ASCII character to append.
		@param iWideCharacter the wide character to append.

		@return a reference to this string.
		*/
		vkString&		operator<<(const vkCharacter& iCharacter);
		vkString&		operator<<(const char8 iASCIICharacter);
		vkString&		operator<<(const char16 iASCIICharacter);
#if defined(VK_WCHAR_T_IS_BUILT_IN)
		vkString&		operator<<(const wchar_t iWideCharacter);
#endif
		//@}

		//@{
		/**
		Formats a numerical value and appends the
		result to the string.

		The internal encoding is not modified.

		@param iNumber the number to format and append.

		@return a reference to this string.
		*/
		vkString&		operator<<(const uint64 iNumber);
		vkString&		operator<<(const int64 iNumber);
		vkString&		operator<<(const uint32 iNumber);
		vkString&		operator<<(const int32 iNumber);
		vkString&		operator<<(const float iNumber);
		vkString&		operator<<(const double iNumber);
		vkString&		operator<<(const void* iPointer);
		vkString&		operator<<(const vkFourCC& iValue);
		vkString&		operator<<(const bool iValue);
		//@}

		//@{
		/**
		Appends a character unit.

		Make sure the internal encoding match the char unit
		you want to append (uint8 : ASCII or UTF8, int16 : UTF16, uint32 : UTF32).
		If not, some unpredictable results may occur (malformed logical characters).
		This method reserves some extra space to optimize successive call
		of this method.

		@param iUnit the unit to append
		*/
		void			AppendCharacterUnit(const char8 iUnit);
		void			AppendCharacterUnit(const char16 iUnit);
		void			AppendCharacterUnit(const char32 iUnit);
		//@}

		//@{
		/**
		Appends some character units.

		Make sure the internal encoding match the char units
		you want to append (uint8 : ASCII or UTF8, int16 : UTF16, uint32 : UTF32).
		If not, some unpredictable results may occur (malformed logical characters).

		@param iUnits the units to append
		@param iUnitsCount the number of units to append.
		*/
		void			AppendCharacterUnits(const char8* iUnits, const uint32 iUnitsCount);
		void			AppendCharacterUnits(const char16* iUnits, const uint32 iUnitsCount);
		void			AppendCharacterUnits(const char32* iUnits, const uint32 iUnitsCount);
		//@}

		/**
		Appends some character units.

		Make sure the internal encoding match the char units
		you want to append.
		If not, some unpredictable results may occur (malformed logical characters).

		@param iUnits the units to append
		@param iUnitsCount the number of units to append.
		*/
		void			AppendUnits(const char8* iUnits, const uint32 iSizeInBytes);

		/**
		Creates a new string which is the concatenation
		between this string and another one.

		@param iOther the othet string to concatenate with.

		@return the concatenated string.
		*/
		vkString operator+(const vkString& iOther) const;

		//@{
		/**
		Creates a new string which is the concatenation
		between this string and a C String

		@param iASCIIString an ASCII C String.
		@param iUTF16String an UTF16 C String.
		@param iUTF32String an UTF32 C String.

		@return the concatenated string.
		*/
		vkString operator+(const char8* iASCIIString) const;
		vkString operator+(const char16* iUTF16String) const;
		vkString operator+(const char32* iUTF32String) const;

#if defined(VK_WCHAR_T_IS_BUILT_IN)
		vkString operator+(const wchar_t* iWideCharString) const;
#endif
		//@}

    /**
    Explicit overload for creating with UTF8
    */
    // vkString MakeWithUTF8(const char8* iUTF8String) const;

		/**
		Creates a new string which is the concatenation
		between this string and a single character.

		@param iCharacter a logical character.

		@return the concatenated string.
		*/
		vkString operator+(const vkCharacter& iCharacter) const;

		//@{
		/**
		Creates a new string which is the concatenation
		between this string and a formatted number.

		@param iNumber a number.

		@return the concatenated string.
		*/
		vkString operator+(const uint64 iNumber) const;
		vkString operator+(const int64 iNumber) const;
		vkString operator+(const uint32 iNumber) const;
		vkString operator+(const int32 iNumber) const;
		vkString operator+(const float iNumber) const;
		vkString operator+(const double iNumber) const;
		//@}

		/**
		Creates a new string which is the concatenation
		between this string and a formatted pointer.
		The formatted pointer follows 0xYYYYYYYY where Y is the hexa
		representation of the pointer.

		@param iPointer a pointer.

		@return the concatenated string.
		*/
		vkString operator+(const void* iPointer) const;

		/**
		Creates a new string which is the concatenation
		between this string and a formatted fourCC.
		The format is the four char representation.

		@param iFourCC a four CC.

		@return the concatenated string.

		@see vkFourCC
		*/
		vkString operator+(const vkFourCC& iFourCC) const;

		/**
		Resizes the string.

		The null trailing character is reset but
		the extra bytes are garbage.

		@param iSizeInBytes the new size in bytes of the string.
		*/
		void			Resize(const uint32 iSizeInBytes);

		/**
		Reserves some memory for the string.

		Nothing is done if the new size is lower
		than the actual size.

		@param iSizeInBytes the new size in bytes of the string.
		*/
		void			Reserve(const uint32 iSizeInBytes);

		/**
		Reallocates the internal buffer if needed
		to fit the exact size taken by the characters.
		@return true if the fit occurred.
		*/
		bool			Fit();

		/**
		Converts all the characters of the string
		in lower case.

		@return a reference to this string.
		*/
		vkString&		ToLower();

		/**
		Converts all the characters of the string
		in upper case.

		@return a reference to this string.
		*/
		vkString&		ToUpper();

		/**
		Converts all the separators series in
		one space.

		@return a reference to this string.
		*/
		vkString&		Strip();

		/**
		Counts the number of hits when searching for every separator in iSeparators
		between iStart and iEnd

		@param iSeparators array of separators.
		@param iSeparatorCount number of separators.
		@param iStart start of the scan.
		@param iEnd end of the scan.
		*/
		uint32			Count(const vkCharacter* iSeparators, uint32 iSeparatorCount, const ConstIterator& iStart, const ConstIterator& iEnd) const;

		/**
		Same as above. Implicit iStart and iEnd are respectively Begin() and End()

		@param iSeparators array of separators.
		@param iSeparatorCount number of separators.
		*/
		uint32			Count(const vkCharacter* iSeparators, uint32 iSeparatorCount) const;

		//@{
		/**
		Formats a set of arguments following
		a format string and stores the result in this string.
		The format follows the ANSI printf format system.

		@param iUTF8Format the format encoded in UTF8
		@param ..., iList : variable list of arguments.

		@return a reference to this string.
		*/
		vkString&		Format(const char8* iUTF8Format, ...);
		vkString&		Format(const char8* iFormat, va_list& iList);
		//@}

		//@{
		/**
		Formats a set of arguments following
		a format string and appends the result to this string.
		The format follows the ANSI printf format system.

		@param iUTF8Format the format encoded in UTF8
		@param ..., iList variable list of arguments.

		@return a reference to this string.
		*/
		void			Append(const char8* iFormat, ...);
		void			Append(const char8* iFormat, va_list& iList);
		//@}


		//@{
		/**
		Formats a numerical value and stores the
		result in the string.

		@param iNumber the number to format and store.

		@return a reference to this string.
		*/
		void From(const int8 iNumber);
		void From(const uint8 iNumber);
		void From(const int16 iNumber);
		void From(const uint16 iNumber);
		void From(const int32 iNumber);
		void From(const uint32 iNumber);
		void From(const int64 iNumber);
		void From(const uint64 iNumber);
		void From(const float iNumber);
		void From(const double iNumber);
		void From(const vkFourCC& iValue);
		void From(const bool iValue);
		void From(const void* iPointer);

#if defined(VK_TARGET_MACOSX)
        void From(const long int oNumber);
		void From(const unsigned long int oNumber);
#endif
		//@}

		/**
		Formats a numerical value and stores the
		result in the string in an hexadecimal representation.
		@param iNumber the number to format in hexa and store.
		*/
		void FromHexa(const uint32 iValue);

		//@{
		/**
		Interprets the characters in the string
		as a formatted number and store the result in
		the number.

		@param oNumber : n result, the interpreted number.

		@return error errOk if the operation succeeded, errSyntaxError
		if the string could not be interpreted.
		*/
		error			To(vkString& oString) const;
		error			To(int8& oNumber) const;
		error			To(uint8& oNumber) const;
		error			To(int16& oNumber) const;
		error			To(uint16& oNumber) const;
		error			To(int32& oNumber) const;
		error			To(uint32& oNumber) const;
		error			To(int64& oNumber) const;
		error			To(uint64& oNumber) const;
		error			To(float& oNumber) const;
		error			To(double& oNumber) const;
		error			To(bool& oNumber) const;
		error			To(vkFourCC& oFourCC) const;
		error			To(void*& oPointer) const;

#if defined(VK_TARGET_MACOSX)
        error			To(long int& oNumber) const;
		error			To(unsigned long int& oNumber) const;
#endif
		//@}

		/**
		Locks the entire string in particular encoding
		specified by the lock params.

		If the encoding fits the internal encoding, then no recopy
		is done. You are also always ensured that the buffer ends with a null character.

		@param ioParams : he params specifying the desired encoding and in result,
		stores all the data for directly addressing the characters.

		@see vkStringLockParams
		*/
		void			Lock(vkStringLockParams& ioParams) const;

		/**
		Locks the characters of the  string starting
		at a position and by using particular encoding
		specified by the lock params.

		If the encoding fits the internal encoding, then no recopy
		is done. You are also always ensured that the buffer ends with a null character.

		@param ioParams the params specifying the desired encoding and in result,
		stores all the data for directly addressing the characters.
		@param iStart iterator pointing to the first character to lock.

		@see vkStringLock
		*/
		void			Lock(vkStringLockParams& ioParams, ConstIterator iStart) const;

		/**
		Locks the characters of the string defined in a range
		and using a particular encoding specified by the lock params.

		You are always ensured that the buffer ends with a null character.

		@param ioParams : he params specifying the desired encoding and in result,
		stores all the data for directly addressing the characters.
		@param iStart it defines the start of the range.
		@param iEnd it defines the end of the range.

		@see vkStringLock
		*/
		void			Lock(vkStringLockParams& ioParams, ConstIterator iStart, ConstIterator iEnd) const;

		/**
		Unlocks a set of characters that was previously
		locked.

		Lock/Unlock work as a pair and Unlock must never be
		forgotten to avoid memory leak.

		@param ioParams the lock params defining the locked characters.

		@see vkStringLock
		*/
		void			Unlock(vkStringLockParams& ioParams) const;

		/**
		Initializes this string with a string encoded in the extended ASCII of the platform
		(ie Codepage 1252 on Windows, Mac Roman on Mac...)
		@param iPlatformString the string to convert
		@return error code
		*/
		error			FromPlatformASCII(const char8* iPlatformString);

		/**
		Convert this string to the platform ASCII.
		@param oPlatformString in output a buffer to the converted string.
		This buffer must be deallocated by vkDeallocate.
		@return error code
		*/
		error			ToPlatformASCII(char8*& oPlatformString) const;

#if !defined(VK_DOXYGEN)
		static const vkStrMethods*	GetMethods(const vkCharacter::EEncoding iEncoding);
		const vkStrMethods*			GetMethods() const;

		/**
		Gets the packed data.
		Should be used for internal use only.
		@return the packed data
		*/
		uint32 GetPackedData() const;

		/**
		Tells if the specified size is for large strings.
		Large size is size > 65535 bytes.
		@return true if the size is large
		*/
		static bool	IsLargeSize(const uint32 iSize);

#endif // VK_DOXYGEN


	protected:
		explicit vkString(uint32 iPack);

		/************************************************************************/
		/* Hash                                                  */
		/************************************************************************/
		uint32 _HashASCII() const;
		uint32 _HashUTF8() const;
		uint32 _HashUTF16() const;
		uint32 _HashUTF32() const;

		/************************************************************************/
		/* Range Equals                                                  */
		/************************************************************************/
		bool _RangeEqualsASCIIWithUTF16(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		bool _RangeEqualsASCIIWithUTF32(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		bool _RangeEqualsUTF8WithUTF16(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		bool _RangeEqualsUTF8WithUTF32(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		bool _RangeEqualsUTF16WithUTF32(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;

		bool _RangeEqualsUTF16WithASCII(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		bool _RangeEqualsUTF32WithASCII(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		bool _RangeEqualsUTF16WithUTF8(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		bool _RangeEqualsUTF32WithUTF8(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		bool _RangeEqualsUTF32WithUTF16(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;

		typedef bool (vkString::*TRangeEquals)(const vkString::ConstIterator& iStart, const vkString::ConstIterator& iOtherStart, const vkString::ConstIterator& iOtherEnd, vkString::ConstIterator* oItAfterPattern, vkString::ConstIterator* oOtherItAfterPattern) const;
		static TRangeEquals s_RangeEquals[vkCharacter::eEncodingCount][vkCharacter::eEncodingCount];

		/************************************************************************/
		/* Equals                                                  */
		/************************************************************************/
		bool _EqualsASCIIWithUTF16(const vkString& iOther) const;
		bool _EqualsASCIIWithUTF32(const vkString& iOther) const;
		bool _EqualsUTF8WithUTF16(const vkString& iOther) const;
		bool _EqualsUTF8WithUTF32(const vkString& iOther) const;
		bool _EqualsUTF16WithUTF32(const vkString& iOther) const;

		typedef bool (vkString::*TEquals)(const vkString& iOther) const;
		static TEquals s_Equals[vkCharacter::eEncodingCount][vkCharacter::eEncodingCount];

		/************************************************************************/
		/* ToLower / ToUpper                                                    */
		/************************************************************************/
		struct ToLowerManipulator
		{
			enum
			{
				kA = 'A',
				kZ = 'Z'
			};

			static bool ChangeCase(vkCharacter& ioChar);
			static char8 ChangeCase(char8 iChar);
		};

		struct ToUpperManipulator
		{
			enum
			{
				kA = 'a',
				kZ = 'z'
			};

			static bool ChangeCase(vkCharacter& ioChar);
			static char8 ChangeCase(char8 iChar);
		};

		template <class TCaseManipulator>
		vkString& _ChangeCaseASCII();

		template <class TCaseManipulator>
		vkString& _ChangeCaseUTF8();

		template <class TCaseManipulator>
		vkString& _ChangeCaseGeneric();

		vkString& _ToLowerASCII();
		vkString& _ToLowerUTF8();
		vkString& _ToLowerGeneric();

		vkString& _ToUpperASCII();
		vkString& _ToUpperUTF8();
		vkString& _ToUpperGeneric();

		/************************************************************************/
		/* Find                                                   */
		/************************************************************************/
		char8* _FindASCII(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const;
		char8* _FindUTF8(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const;
		char8* _FindGeneric(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const;
		char8* _Find(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const;

		char8* _FindLastASCII(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const;
		char8* _FindLastUTF8(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const;
		char8* _FindLastGeneric(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const;
		char8* _FindLast(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const;

		template <typename TChar, vkCharacter::EEncoding iEncoding>
		char8* _TFind(const vkString& iOther, const char8* iStart, const char8* iEnd) const;

		char8* _FindASCII(const vkString& iOther, const char8* iStart, const char8* iEnd) const;
		char8* _FindUTF8(const vkString& iOther, const char8* iStart, const char8* iEnd) const;
		char8* _FindUTF16(const vkString& iOther, const char8* iStart, const char8* iEnd) const;
		char8* _FindUTF32(const vkString& iOther, const char8* iStart, const char8* iEnd) const;
		char8* _Find(const vkString& iOther, const char8* iStart, const char8* iEnd) const;

		template <typename TChar, vkCharacter::EEncoding iEncoding>
		char8* _TFindLast(const vkString& iOther, const char8* iStart, const char8* iEnd) const;

		char8* _FindLastASCII(const vkString& iOther, const char8* iStart, const char8* iEnd) const;
		char8* _FindLastUTF8(const vkString& iOther, const char8* iStart, const char8* iEnd) const;
		char8* _FindLastUTF16(const vkString& iOther, const char8* iStart, const char8* iEnd) const;
		char8* _FindLastUTF32(const vkString& iOther, const char8* iStart, const char8* iEnd) const;
		char8* _FindLast(const vkString& iOther, const char8* iStart, const char8* iEnd) const;

		/************************************************************************/
		/* Replace																*/
		/************************************************************************/
		template <typename TChar> uint32 _TReplace(TChar iCharacterToReplace, TChar iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceASCII(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceUTF8(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceUTF16(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceUTF32(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceGeneric(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);

		template <typename TChar> uint32 _TReplace(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceASCII(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceUTF16(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceUTF32(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);
		uint32 _ReplaceGeneric(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd);

	protected:

		enum
		{
			kMaxCharSize = 5
		};

		static const char32				s_NullChar;

		friend class vkKernelModule;
		friend class vkMainParameters;
		friend struct vkPoolAllocatorMethods;
		friend struct vkStdAllocatorMethods;

		static error _Initialize();
		static error _Terminate();

		struct AllocatedSize
		{
#if defined(VK_BIG_ENDIAN)
			uint16 hi;
			uint16 lo;
#else
			uint16 lo;
			uint16 hi;
#endif
		};

		struct SmallHeader
		{
			int32	refCount;

			union
			{
				uint32			allocatedSize;
				AllocatedSize	allocatedSizeEx;
			};
		};

		struct LargeHeader
		{
			uint32	largeSize;
			int32	refCount;

			union
			{
				uint32			allocatedSize;
				AllocatedSize	allocatedSizeEx;
			};
		};

		// Static version
		static void*	_GetBuffer(const char8* iChars);

		static char8*	_GetChars(const void* iBuffer, const uint32 iAllocatedSize);

		static uint32&	_GetAllocatedSize(char8* iChars); // (space taken by characters)
		static uint32	_GetBufferAndHeaderSize(const uint32 iAllocatedSize, uint32& oHeaderSize);

		// Instance Version
		char8*			_GetEndChars();
		const char8*	_GetEndChars() const;
		template <typename TChar> char8* _GetEndChars() const;

		static void		_InitBufferHeader(void* iBuffer, uint32 iAllocatedSize, uint32 iSizeInBytes);

		int32			_GetRefCount() const;

		uint32&			_GetAllocatedSize(); // (space taken by characters)
		uint32			_GetAllocatedSizeValue() const; // (space taken by characters)

		void			_SetSize(uint32 iSize);

		void*			_Allocate(uint32& ioSize) const;
		void*			_FitAllocate(const uint32 iSize) const;
		void			_Deallocate(void* iBuffer, uint32 iAllocatedSize) const;
		void			_DeallocateChars(char8* iChars) const;

		static void*	_Allocate(EAllocatorID iAllocatorID, uint32& ioSize);
		static void*	_FitAllocate(EAllocatorID iAllocatorID, const uint32 iSize);
		static void*	_Reallocate(EAllocatorID iAllocatorID, void* iBuffer, const uint32 iOldSize, uint32& iSize);
		static void		_Deallocate(EAllocatorID iAllocatorID, void* iBuffer, uint32 iAllocatedSize);

		void			_AllocateBuffer(const uint32 iSize);
		static char8*	_AllocateBufferAndConvert(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, vkCharacter::EEncoding iDstEncoding, vkCharacter::EEncoding iSrcEncoding, const char8* iSrcChars, const int32 iByteLength = -1 /*recompute bytelength*/);

		static void		_CopyBuffers(void* iOldBuffer, uint32 iOldSize, void* iNewBuffer, uint32 iNewSize);

		bool			_IsBufferEditable() const;

		// Write null character at the end of the string
		void			_WriteTerminalNullChar();
		template <typename TChar> void _WriteTerminalNullChar(uint32 iSizeInBytes);
		static void		_WriteTerminalNullChar(const vkCharacter::EEncoding iEncoding, char8* iDstCharacter);

		bool			_CanFitEncodingWithoutConversion(vkCharacter::EEncoding iEncoding) const;

		bool			_CanBeFastCompared(vkCharacter::EEncoding iEncoding) const;
		void			_Reserve(const uint32 iSizeInBytes);

		void			_SetEncoding(vkCharacter::EEncoding iEncoding);

		template <class TUnit>
		void
		_AppendCharacterUnit(const TUnit iUnit);

		template <class TUnit>
		void
		_AppendCharacterUnits(const TUnit* iUnits, const uint32 iUnitsCount);

		template <class TUnit, class TConstantUnitFlagUpdater>
		void _AppendCharacterUnitsAndUpdateFlag(const TUnit* iUnits, const uint32 iUnitsCount, bool iUnitsHaveConstantCharSize);

		void			_SetCharacter(const uint32 iCharSize, char8* iDstChar, const char8* iSrcChar);

		// Construct/Destruct methods : both used in constructor/dtor and operator =
		void			_Construct();
		void			_Construct(const vkCharacter::EEncoding iEncoding, const EAllocatorID iAllocatorID);
		void			_Construct(const vkString& iOther);
		void			_Construct(const vkString& iOther, const vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID);
		void			_Construct(const ConstIterator& iStart, const ConstIterator& iEnd);
		void			_Construct(const ConstIterator& iStart, const ConstIterator& iEnd, const vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID);
		void			_ConstructAndReserve(const uint32 iSizeInBytes, const vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID);

		void			_ConstructFromASCII(const char8* iString, uint32 iSizeInBytes, bool iIsStatic, vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID);
		void			_ConstructFromUTF8(const char8* iString, uint32 iSizeInBytes, bool iIsStatic, vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID);
		void			_ConstructFromUTF16(const char16* iString, uint32 iSizeInBytes, bool iIsStatic, vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID);
		void			_ConstructFromUTF32(const char32* iString, uint32 iSizeInBytes, bool iIsStatic, vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID);
		void			_ConstructFromWideChar(const wchar_t* iString, uint32 iSizeInBytes, bool iIsStatic, vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID);

		void			_Destruct();

		void			_UpdateConstantCharSizeFlagAfterInsert(const vkCharacter& iCharacter);
		void			_UpdateConstantCharSizeFlagAfterReplace(const uint32 iReplaceCount, const vkCharacter& iCharacter);

		void			_ReallocateBufferForReplacement(char8*& ioCurrentIt, uint32 iOldCount, uint32 iNewCount, char8*& ioEnd, uint32 iTotalSize);

		uint32			_NoConstReplaceChar(const vkCharacter& iOld, ConstIterator& iStart, ConstIterator& iEnd, const char8* iChar, uint32 iSize, uint32 iDelta);
		uint32			_NoConstReplaceChar2(const vkCharacter& iOld, ConstIterator& iStart, ConstIterator& iEnd, const char8* iChar, uint32 iSize, uint32 iDelta);

		static uint32	_ConstReplaceChar1x8Bytes(const vkCharacter& iOld, ConstIterator& iStart, const ConstIterator& iEnd, const char8* iChar);
		static uint32	_ConstReplaceChar2x8Bytes(const vkCharacter& iOld, ConstIterator& iStart, const ConstIterator& iEnd, const char8* iChar);
		static uint32	_ConstReplaceChar3x8Bytes(const vkCharacter& iOld, ConstIterator& iStart, const ConstIterator& iEnd, const char8* iChar);
		static uint32	_ConstReplaceChar4x8Bytes(const vkCharacter& iOld, ConstIterator& iStart, const ConstIterator& iEnd, const char8* iChar);
		static uint32	_ConstReplaceChar5x8Bytes(const vkCharacter& iOld, ConstIterator& iStart, const ConstIterator& iEnd, const char8* iChar);

		typedef ConstIterator (vkString::*TFindFunction)(const vkString& iOther, const ConstIterator& iStart, const ConstIterator& iEnd) const;

		uint32			_Replace(const vkString& iOld, const vkString& iNew, const ConstIterator& iStart, const ConstIterator& iEnd, TFindFunction iFindFunction);
		uint32			_NoConstReplaceString(const vkString& iOld, ConstIterator& iStart, ConstIterator& iEnd, const char8* iChar, uint32 iSize, uint32 iDelta, TFindFunction iFindFunction);
		uint32			_NoConstReplaceString2(const vkString& iOld, ConstIterator& iStart, ConstIterator& iEnd, const char8* iChar, uint32 iSize, uint32 iDelta, TFindFunction iFindFunction);
		uint32			_ConstReplaceString(const vkString& iOld, ConstIterator& iStart, ConstIterator& iEnd, const char8* iChar, uint32 iSize, TFindFunction iFindFunction);

		void			_Strip(char8* iChars, ConstIterator* iIterators, uint32 iCount);

		typedef bool (*THasConstantCharSize)(const char8* iChars, uint32 iByteLength);
		static bool		_ASCIIHasConstantCharSize(const char8* iChars, uint32 iByteLength);
		static bool		_UTF8HasConstantCharSize(const char8* iChars, uint32 iByteLength);
		static bool		_UTF16HasConstantCharSize(const char8* iChars, uint32 iByteLength);
		static bool		_UTF32HasConstantCharSize(const char8* iChars, uint32 iByteLength);
		static THasConstantCharSize s_HasConstantCharSize[vkCharacter::eEncodingCount];

		// Append Units functions table
		typedef void (vkString::*appendCharacterUnits)(const char8* iUnits, const uint32 iByteLength, bool iUnitsHaveConstantCharSize);
		void			_ASCIIAppendCharacterUnits(const char8* iUnits, const uint32 iByteLength, bool iUnitsHaveConstantCharSize);
		void			_UTF8AppendCharacterUnits(const char8* iUnits, const uint32 iByteLength, bool iUnitsHaveConstantCharSize);
		void			_UTF16AppendCharacterUnits(const char8* iUnits, const uint32 iByteLength, bool iUnitsHaveConstantCharSize);
		void			_UTF32AppendCharacterUnits(const char8* iUnits, const uint32 iByteLength, bool iUnitsHaveConstantCharSize);
		static appendCharacterUnits s_AppendCharacterUnits[vkCharacter::eEncodingCount];

		// Append Characters functions table
		typedef vkString& (vkString::*appendCharacter)(const vkCharacter& iCharacter);
		vkString&		_ASCIIAppendCharacter(const vkCharacter& iCharacter);
		vkString&		_UTF8AppendCharacter(const vkCharacter& iCharacter);
		vkString&		_UTF16AppendCharacter(const vkCharacter& iCharacter);
		vkString&		_UTF32AppendCharacter(const vkCharacter& iCharacter);
		static appendCharacter s_AppendCharacter[vkCharacter::eEncodingCount];

		// Append ASCII Character functions table
		typedef vkString& (vkString::*appendASCIICharacter)(const char8 iASCIICharacter);
		vkString&		_ASCIIAppendASCIICharacter(const char8 iASCIICharacter);
		vkString&		_UTF8AppendASCIICharacter(const char8 iASCIICharacter);
		vkString&		_UTF16AppendASCIICharacter(const char8 iASCIICharacter);
		vkString&		_UTF32AppendASCIICharacter(const char8 iASCIICharacter);
		static appendASCIICharacter s_AppendASCIICharacter[vkCharacter::eEncodingCount];

		typedef char8*	(*TConverter)(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);

		static void		_CopyAppend(void *iDest, const char8* iSrc1, const char8* iSrc2, const uint32 iSize1, const uint32 iSize2);

		// List of all the converters
		static char8*	_DirectCopy			(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);

		static char8*	_ASCIIFromUTF8		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);
		static char8*	_ASCIIFromUTF16		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);
		static char8*	_ASCIIFromUTF32		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);

		static char8*	_UTF8FromASCII		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);
		static char8*	_UTF8FromUTF16		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);
		static char8*	_UTF8FromUTF32		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);

		static char8*	_UTF16FromUTF8		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);
		static char8*	_UTF16FromASCII		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);
		static char8*	_UTF16FromUTF32		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);

		static char8*	_UTF32FromUTF8		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);
		static char8*	_UTF32FromASCII		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);
		static char8*	_UTF32FromUTF16		(uint32& oSizeInBytes, const EAllocatorID iAllocatorID, const vkCharacter::EEncoding iDstEncoding, const char8* iSrcChars, const vkCharacter::EEncoding iSrcEncoding, const int32 iSrcByteLength);

		static TConverter		s_Converters[vkCharacter::eEncodingCount][vkCharacter::eEncodingCount];

		// Methods Table (indexed by encoding)
		static vkStrMethods*	s_Methods[vkCharacter::eEncodingCount];

		// Constant size replace character functions table
		typedef uint32 (*constReplaceChar)(const vkCharacter&, ConstIterator&, const ConstIterator&, const char8*);
		static constReplaceChar s_ConstReplaceCharFunc[kMaxCharSize];

		// Non Constant size replace character functions table
		typedef uint32 (vkString::*noConstReplaceChar)(const vkCharacter&, ConstIterator&, ConstIterator&, const char8*, uint32, uint32);
		static noConstReplaceChar s_NoConstReplaceCharFunc[2];

		// Non Constant size replace string table
		typedef uint32 (vkString::*noConstReplaceString)(const vkString&, ConstIterator&, ConstIterator&, const char8*, uint32, uint32, TFindFunction);
		static noConstReplaceString s_NoConstReplaceStringFunc[2];

		// Instance Data
		union
		{
			mutable char8*	m_Chars; // Pointer on the characters (char8, char16 or char32)
			mutable char16*	m_UTF16Chars; // Pointer on UTF16 Chars
			mutable char32*	m_UTF32Chars; // Pointer on UTF32 Chars
		};

		enum FInternalFlags
		{
			fEncodingMask	= 0x3,

			fHasFixedEncoding		= 1 << 2,
			fUseStandardAllocator	= 1 << 3,
			fHasFixedAllocator		= 1 << 4,
			fIsStatic				= 1 << 5
		};

		struct PackedData
		{
#if defined(VK_BIG_ENDIAN)
			/************************************************************************/
			/* != 0 : the size in bytes of the string								*/
			/* == 0 : actual size is > 65535 and stored in the shared buffer		*/
			/************************************************************************/
			uint16			smallSize;

			/************************************************************************/
			/* != 0 : the size in bytes of one logical character.                   */
			/* == 0 : the string has variable length encoding						*/
			/************************************************************************/
			uint8			constantCharSize;

			/************************************************************************/
			/* Low bits : encoding                                                  */
			/* High bits : flags													*/
			/************************************************************************/
			uint8			internalFlags;

#else
			// Little Endian
			uint8			internalFlags;
			uint8			constantCharSize;
			uint16			smallSize;
#endif
		};

		union
		{
			uint32		m_Pack;
			PackedData	m_;
		};
	};

	/**
	This macro creates a new string based on a static ASCII string.

	@ingroup grp_string
	*/
#define VK_AS(str)		VKernel::vkString((const VKernel::char8*) (str), VKernel::uint16(sizeof(str)))

	/**
	This macro creates a new string based on a static WideChar string.

	@ingroup grp_string
	*/
#define VK_WS(str)		VKernel::vkString((const wchar_t*) (str), VKernel::vkCharacter::eWideCharEncoding, true /*isStatic*/, VKernel::int32(sizeof(str)))

	/**
	These macros create a new string based on a static string and using ASCII/WideChar Encoding.

	The allocator is the standard one (malloc/free) to allow use of the macro in the static data initialization.
	This macro is used to easily track all the hard coded
	strings that must be later replaced in the dev process.

	@ingroup grp_string
	*/
	//@{
#define VK_AS_HARDCODED(str) VK_AS(str)
#define VK_WS_HARDCODED(str) VK_WS(str)
	//@}

	/**
	This macro declares a shortcut for using the global empty string.

	@ingroup grp_string
	*/
#define VK_NS			vkString::kNullString

	/**
	This function checks that a string
	has a unit size of a particular size.

	@param TChar the type of unit (char8, char16, char32)
	@param iString the string to check.

	@ingroup grp_string
	*/
	template <typename TChar> void CheckString(const vkString& iString)
	{
		VKASSERT(iString.UnitSize() == sizeof(TChar)); // "Wrong string encoding"
	}

#if !defined(VK_DOXYGEN)
	class vkStrMethods : public vkStdHeapObject
	{
	public :

		virtual ~vkStrMethods() {}
		virtual vkCharacter::EEncoding	GetEncoding() const = 0;

		virtual char32	GetUTF32Char(const char8* iChar) const = 0;
		virtual char32	GetUTF32Char(const char8* iChar, uint32& oCharSize) const = 0;
		virtual uint32	GetPreviousCharSize(const char8* iChar) const = 0;
		virtual bool	HasConstantCharSize(const char8* iChars, uint32 iByteLength) const = 0;

		virtual uint32	GetCharSize(const char8* iChar) const ;
		virtual uint32	GetCharSize(const vkCharacter& iChar, char8* oChar = 0) const = 0;
		virtual char8*	GetCharAddress(const char8* iChars, const uint32 iLogicalIndex) const = 0;
		virtual const char8*	Advance(const char8* iChars, const int32 iLogicalStepCount) const = 0;

		virtual uint32	WriteChar(const vkCharacter& iCharacter, char8* oEncodedChar) const = 0;

		virtual int32	CompareChar(const char8* iChar1, const char8* iChar2) const;
	};

#endif // VK_DOXYGEN

	/**
	Pattern matching functor.

	This functor must return true if the string iT1 "matches" the string iT2.

	@ingroup grp_string
	*/
	struct vkMatch
	{
		bool operator()(const vkString& iT1,const vkString& iT2) const;
	};

	struct vkIMatch
	{
		bool operator()(const vkString& iT1,const vkString& iT2) const;
	};

	//////////////////////////////////////////////////////////////////////////
	// Strings template specialization

#if !defined(VK_DOXYGEN)
	template <>
	struct vkHashFunction<const vkString>
	{
		uint32 operator()(const vkString& iS) const
		{
			return iS.Hash();
		}
	};

	template <>
	struct vkHashFunction<vkString>
	{
		uint32 operator()(const vkString& iS) const
		{
			return iS.Hash();
		}
	};
#endif // VK_DOXYGEN

	//////////////////////////////////////////////////////////////////////////

#if !defined(VK_DOXYGEN)
	template <>
	struct vkContains<vkString>
	{
		bool operator()(const vkString& iS1, const vkString& iS2) const
		{
			return (iS1.Find(iS2) != iS1.End());
		}
	};

	template <bool iCaseSensitive>
	struct vkStringContains
	{
	};

	template <>
	struct vkStringContains<true>
	{
		bool operator()(const vkString& iS1, const vkString& iS2) const
		{
			return vkContains<vkString>()(iS1,iS2);
		}
	};

	template <>
	struct vkStringContains<false>
	{
		bool operator()(const vkString& iS1, const vkString& iS2) const
		{
			return (iS1.IFind(iS2) != iS1.End());
		}
	};
#endif // VK_DOXYGEN

#include "vkStringIterator.hpp"
#include "vkString.hpp"

}

#endif // __vkString_h

