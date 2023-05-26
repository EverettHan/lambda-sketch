/**
@file

This file defines the character class.

@COPYRIGHT

@author Edwin Razafimahatratra
@author Gerald Guyomard
*/

#ifndef __vkCharacter_h
#define __vkCharacter_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkHeapObject_h)
	#include "vkHeapObject.h"
#endif

namespace VKernel 
{
	/**
	This the class encapsulating a character.
	
	A vkCharacter maps a char32 because the reference encoding is always UTF32
	(UTF32 can encode any characters).

	@ingroup grp_string
	*/
	class VKKERNEL_API vkCharacter : public vkHeapObject
	{
	public :

		/**
		List of the supported encodings.
		*/
		enum EEncoding
		{
			/** This represents an invalid encoding. */
			eInvalidEncoding	= -1,
			/**
			This is the regular ASCII Encoding.

			Extended ASCII (character > 0x7F) are not
			supported because it's platform dependent.
			When converting from Unicode to ASCII, non-supported
			characters are replaced by '?'.
			*/
			eASCIIEncoding	= 0,

		 // Unicode Encodings

			/**
			8-bit encoding.
			
			One logical character can take up to 4 bytes. On pure ascii characters (0-7F), UTF8 perfectly matches Platform.
			*/
			eUTF8Encoding		= 1,

			/**
			16-bit encoding.
			
			Most of logical character take 1 16-bit unit, but few characters are encoded with 2 units (called surrogates 1 & 2).
			*/
			eUTF16Encoding		= 2,

			/**
			32-bit encoding.
			
			All characters take 4 bytes. Memory consuming but very simple to handle.
			*/
			eUTF32Encoding		= 3,

			/** */
			eEncodingCount,

			/**
			UTF8 is the default encoding.
			
			It's recommended because it's safe for localization, optimized in memory (strings with pure ascii chars
			take the same space as regular ASCII strings), and backward compatible
			with ASCII strings.

			The main drawback is the difficulty to randomly address a character inside a string
			(a parsing from the beginning must be done).
			*/
			eDefaultEncoding = eUTF8Encoding,

		#if defined(VK_WCHAR_T_IS_UTF32)
			/**
			eWideCharEncoding depends on the platform !
			Use eWideCharEncoding if you deal with wchar_t characters.
			*/
			eWideCharEncoding = eUTF32Encoding
		#else
			eWideCharEncoding = eUTF16Encoding
		#endif
		};

		// a set of common characters (like '.', '+', '(', ...)
		/** Null character ('\\0'). */
		static const vkCharacter kNull;
		/** Life feed character ('\\n'). */
		static const vkCharacter kLineFeed;
		/** Carriage return character ('\\r'). */
		static const vkCharacter kCarriageReturn;
		/** The tabulation character ('\\t'). */
		static const vkCharacter kTab;
		/** The space character (' '). */
		static const vkCharacter kSpace;
		/** The signle quote character ('''). */
		static const vkCharacter kSingleQuote;
		/** The double quote character ('"'). */
		static const vkCharacter kDoubleQuote;
		/** The back quote character ('`'). */
		static const vkCharacter kBackQuote;
		/** The period character ('.'). */
		static const vkCharacter kPeriod;
		/** The colon character (':'). */
		static const vkCharacter kColon;
		/** The comma character (','). */
		static const vkCharacter kComma;
		/** The semicolon character (';'). */
		static const vkCharacter kSemiColon;
		/** The question mark character ('?'). */
		static const vkCharacter kQuestionMark;
		/** The exclation point character ('!'). */
		static const vkCharacter kExclamationPoint;
		/** The at character ('@'). */
		static const vkCharacter kAt;
		/** The tilde character ('~'). */
		static const vkCharacter kTilde;
		/** The sharp character ('#'). */
		static const vkCharacter kSharp;
		/** The underscore character ('_'). */
		static const vkCharacter kUnderscore;
		/** The vertical bar character ('|'). */
		static const vkCharacter kVerticalBar;
		/** The dollar character ('$'). */
		static const vkCharacter kDollar;
		/** The caret character ('^'). */
		static const vkCharacter kCaret;
		/** The backward slash character ('\\'). */
		static const vkCharacter kBackwardSlash;
		/** The slash character ('/'). */
		static const vkCharacter kSlash;
		/** The multiply character ('*'). */
		static const vkCharacter kMultiply;
		/** The percent character ('%'). */
		static const vkCharacter kPercent;
		/** The plus character ('+'). */
		static const vkCharacter kPlus;
		/** The minus character ('-'). */
		static const vkCharacter kMinus;
		/** The less than character ('<'). */
		static const vkCharacter kLessThan;
		/** The greater than character ('>'). */
		static const vkCharacter kGreaterThan;
		/** The equal character ('='). */
		static const vkCharacter kEqual;
		/** The ampersand character ('&'). */
		static const vkCharacter kAmpersand;
		/** The left parenthesis character ('('). */
		static const vkCharacter kLParenthesis;
		/** The right parenthesis character (')'). */
		static const vkCharacter kRParenthesis;
		/** The left brace character ('{'). */
		static const vkCharacter kLBrace;
		/** The right brace character ('}'). */
		static const vkCharacter kRBrace;
		/** The left bracket character ('['). */
		static const vkCharacter kLBracket;
		/** The right bracket character (']'). */
		static const vkCharacter kRBracket;
		/** Directory separator in a system path (depends on the platform). */
		static const vkCharacter kDirectorySeparator;
		/** Extension separator in a system path (depends on the platform). */
		static const vkCharacter kExtensionSeparator;

		/** Number of digits after decimal point used during the convertion from float/double to ascii str. */
		static int32			 kFloatPrecision;
		/** Number of digits after decimal point used when displaying a float/double in the interface. */
		static int32			 kAuthoringFloatPrecision;		
		/** Character used to represent the decimal point. */
		static vkCharacter		 kDecimalPoint;

		/**
		Size in bytes of the units per encoding :
		eUnknownEncoding	-> 0
		eASCIIEncoding		-> 1
		eUTF8Encoding		-> 1
		eUTF16Encoding		-> 2
		eUTF32Encoding		-> 4
		*/
		static const uint32		s_UnitSizes[eEncodingCount];

		/**
		Power of 2 of the unit size per encoding.

			- eUnknownEncoding	-> 0
			- eASCIIEncoding		-> 0
			- eUTF8Encoding		-> 0
			- eUTF16Encoding		-> 1
			- eUTF32Encoding		-> 2
		
		2 ^ s_UnitPow2s[encoding] == s_UnitSizes[encoding]

		This is recommended to use this table for performing fast multiplication
		or division with logical bit shifts.
		*/
		static const uint32		s_UnitPow2s[eEncodingCount];

		/**
		Default constructor
		*/
		vkCharacter();

		/**
		Copy constructor

		@param iOther the other character to create from.
		*/
		vkCharacter(const vkCharacter& iOther);

		/**
		Constructor from an utf32 character

		@param iUTF32Character the utf32 character to create from.
		*/
		explicit vkCharacter(const char32 iUTF32Character);

		/**
		Constructor from a ASCII character

		Only use characters <= 0x7F.

		@param iASCIICharacter the ASCII character to create from.
		*/
		vkCharacter(const char8 iASCIICharacter);

		/**
		Constructor from a UTF16 character without surrogate.

		@param iUTF16Character the utf16 character to create from.
		*/
		explicit  vkCharacter(const char16 iUTF16Character);

#if defined(VK_WCHAR_T_IS_BUILT_IN)
		/**
		Constructor from a wide character

		@param iWideCharacter the wide character to create from.

		@see wchar_t
		*/
		explicit vkCharacter(const wchar_t iWideCharacter);
#endif

		/**
		Tests if the character encodes the null char.
		@return true if the character is the null char
		*/
		bool			IsNull() const;

		/**
		Tests if the character is valid.

		This is equivalent to !IsNull()

		@return true if the character is valid.
		*/
		bool			IsValid() const;

		/**
		Gets the ASCII representation for this character.
		@return the converted ASCII code or '?' if there's no possible
		conversion to ASCII encoding.
		*/
		char8			GetASCIIChar() const;

		/**
		Gets the utf8 representation for this character.

		@param oChars a buffer storing the utf8 representation after conversion.
		Buffer's size must be at least 4 bytes to prevent memory overflow.

		@return the number of character units (=size in bytes) of the utf8 character.
		This values is comprised between 1 and 4.
		*/
		uint32			GetUTF8Char(char8* oChars) const;

		/**
		Gets the utf16 representation for this character.

		The size in bytes taken by the utf16 representation
		is 'number of character units' * sizeof(char16)

		@param oChars a buffer storing the utf16 representation after conversion.
		Buffer's size must be at least 4 bytes to prevent memory overflow.
		@return the number of character units (1 character unit = 1 char16)
		of the utf16 character.
		This values is comprised between 1 and 2.
		*/
		uint32			GetUTF16Char(char16* oChars) const;

		/**
		Gets the utf32 representation for this character.
		
		There's no conversion made because vkCharacters are char32.
		@return the utf32 character.
		*/
		char32			GetUTF32Char() const;

		/**
		Copy operator from another character.
		*/
		vkCharacter&	operator=(const vkCharacter& iOther);

		/**
		Copy operator from an utf32 character
		*/
		vkCharacter&	operator=(const char32 iUTF32Character);

		/**
		Comparison operator with another character

		@param iOther the other character to compare with.

		@return true if this character equals the other one.
		*/
		bool			operator==(const vkCharacter& iOther) const;

		/**
		Difference operator with another character

		@param iOther the other character to compare with.

		@return true if this character is different from the other one.
		*/
		bool			operator!=(const vkCharacter& iOther) const;

		/**
		Comparison operator with an ASCII character

		@param iASCIICharacter the ASCII character to compare with.

		@return true/false if this character equals the ASCII one.
		*/
		bool			operator==(const char8 iASCIICharacter) const;

		/**
		Difference operator with another character

		@param iASCIICharacter the ASCII character to compare with.

		@return true if this character is different from the other one.
		*/
		bool			operator!=(const char8 iASCIICharacter) const;

		/**
		Comparison operator with an utf16 character (with no surrogate)

		@param iUTF16Character the utf16 character to compare with.

		@return true if this character equals the UTF16 one.
		*/
		bool			operator==(const char16 iUTF16Character) const;

		/**
		Difference operator with another character

		@param iUTF16Character the utf16 character to compare with.

		@return true if this character is different from the other one.
		*/
		bool			operator!=(const char16 iUTF16Character) const;

		/**
		Comparison operator with an utf32 character

		@param iUTF32Character the utf32 character to compare with.

		@return true if this character equals the UTF32 one.
		*/
		bool			operator==(const char32 iUTF32Character) const;

		/**
		Difference operator with another character

		@param iUTF32Character the utf32 character to compare with.

		@return true if this character is different from the other one.
		*/
		bool			operator!=(const char32 iUTF32Character) const;

		/**
		Compares this character with another one.

		This method is case sensitive.

		@param iOther the other character to compare with.

		@return 
			0	if *this == iOther
			< 0 if *this < iOther
			> 0 if *this > iOther
		*/
		int32			Compare(const vkCharacter& iOther) const;

		/**
		Compares this character with another one
		ignoring the case.

		@param iOther the other character to compare with.

		@return 	0	if *this == iOther
		< 0 if *this < iOther
		> 0 if *this > iOther
		*/
		int32			ICompare(const vkCharacter& iOther) const;

		/**
		Tests if this character is contained in the given set.

		This method is case sensitive.

		@param iSet array of characters
		@param iCount number of characters in the set.

		@return true if this character belongs to the set.
		*/
		bool			IsInSet(const vkCharacter* iSet, uint32 iCount) const;

		/**
		Tests if this character is contained in the given set.

		This method is case sensitive.

		@param iSet array of ASCII characters
		@param iCount number of characters in the set.

		@return true if this character belongs to the set.
		*/
		bool			IsInSet(const char8* iSet, uint32 iCount) const;

		/**
		Tests if this character is printable, ie.
		can be displayed on an output (screen, log).
		@return true if this character is printable.
		*/
		bool			IsPrintable() const;

		/**
		Tests if this character is an alpha character, ie.
		can be [a-z] or [A-Z]
		@return true if this character is Alpha.
		*/
		bool			IsAlpha() const;

		/**
		Tests if this character is ASCII
		(code between 0 and 0x7F)
		@return true if this character is ASCII.
		*/
		bool			IsAscii() const;

		/**
		Tests if this character is a digit
		([0-9])
		@return true if this character is a digit.
		*/
		bool			IsDigit() const;

		/**
		Tests if this character is an alpha character
		or a digit.
		@return true if this character is a digit or an
		alpha character.
		@see IsAlpha, IsDigit
		*/
		bool			IsAlphaNum() const;

		/**
		Tests if this character is a regular separator.
		A regular separator can be ' ', '\t', '\r' or '\n'.
		@return true if this character is a separator.
		*/
		bool			IsSeparator() const;

		/**
		Tests if this character is case sensitive.
		It means ToLower() != ToUpper().
		@return true if this character is case sensitive.
		@see ToLower, ToUpper
		*/
		bool			IsCaseSensitive() const;

		/**
		Converts the character to lower case.
		@return true if the character could be converted.
		False if the character is not case sensitive.
		*/
		bool			IsLower() const;

		/**
		Tests if the character is a lower letter.
		
		If the character is not case sensitive, false is returned.

		@return true if the the character is in lower case.
		*/
		bool			ToLower();

		/**
		Tests if the character is an upper letter.

		If the character is not case sensitive, false is returned.

		@return true if the the character is in upper case.
		*/
		bool			IsUpper() const;

		/**
		Converts the character to upper case.
		@return true if the character could be converted.
		False if the character is not case sensitive.
		*/
		bool			ToUpper();

		/**
		Static Helpers
		*/

		/**
		Gets the default encoding matching the size of a unit

		@param iUnitSize the size of the character unit.
		iUnitSize == 1 => eUTF8Encoding
		iUnitSize == 2 => eUTF16Encoding
		iUnitSize == 4 => eUTF32Encoding
		default : eInvalidEncoding.

		@return the matching encoding.
		*/
		static EEncoding GetDefaultEncoding(const uint32 iUnitSize);

		static uint32 GetFloatPrecision();
		static uint32 GetAuthoringFloatPrecision();
		static const vkCharacter& GetDecimalPoint();
		static void SetFloatPrecision(uint32 iPrecision);
		static void SetAuthoringFloatPrecision(uint32 iPrecision);
		static void SetDecimalPoint(const vkCharacter& iDecimalPoint);

		/**
		Formats the number to store it in the given buffer

		The buffer must be large enough to receive the formatted string.

		@param oString in return, this string contains the formatted value.
		@param iUint, iInt, iFloat, iHexa, iPointer the value to format.
		@param iSize size of the output buffer

		@return the number of written char8s.
		*/
		static uint32	UInt64ToASCIIStr(char8* oString, uint32 iSize, const uint64 iUInt);
		static uint32	Int64ToASCIIStr(char8* oString, uint32 iSize, const int64 iInt);
		static uint32	UInt32ToASCIIStr(char8* oString, uint32 iSize, const uint32 iUInt);
		static uint32	Int32ToASCIIStr(char8* oString, uint32 iSize, const int32 iInt);
		static uint32	FloatToASCIIStr(char8* oString, uint32 iSize, const float iFloat);
		static uint32	DoubleToASCIIStr(char8* oString, uint32 iSize, const double iDouble);
		static uint32	HexaToASCIIStr(char8* oString, uint32 iSize, const ptrdiff iHexa);
		static uint32	PointerToASCIIStr(char8* oString, uint32 iSize,const void* iPointer);

		/**
		Returns the size in bytes of the pointed utf8 character.

		@param iUTF8Char the utf8 character.

		@return the number of bytes taken by the utf8 character.
		*/
		static uint32	GetUTF8ChrSize(const char8* iUTF8Char);
		static uint32	GetUTF8ChrSizeInline(const char8* iUTF8Char);

		/**
		Returns the size in bytes of the pointed utf16 character.

		@param iUTF16Char the utf16 character.

		@return the number of bytes taken by the utf16 character.
		*/
		static uint32	GetUTF16ChrSize(const char16* iUTF16Char);
		static uint32	GetUTF16ChrSizeInline(const char16* iUTF16Char);

		/**
		Returns the size in bytes of the utf8 character located
		just before the given pointer.

		@param iUTF8Char pointer to the character following the character to compute the size.

		@return the number of bytes taken by the previous utf8 character.
		*/
		static uint32	GetPreviousUTF8ChrSize(const char8* iUTF8Char);
		static uint32	GetPreviousUTF8ChrSizeInline(const char8* iUTF8Char);

		/**
		Returns the size in bytes of the utf16 character located
		just before the given pointer.

		@param iUTF16Char pointer to the character following the character to compute the size.

		@return the number of bytes taken by the previous utf16 character.
		*/
		static uint32	GetPreviousUTF16ChrSize(const char16* iUTF16Char);
		static uint32	GetPreviousUTF16ChrSizeInline(const char16* iUTF16Char);

		/**
		Get the pointer on the beginning of the UTF8 character.

		@param iUTF8CharUnit pointer on an UTF8 unit (may be one of the 4th possible
		bytes).

		@return the pointer on the beginning of the character
		*/
		static const char8* GetUTF8CharBegin(const char8* iUTF8CharUnit);

		/**
		Get the pointer on the beginning of the UTF16 character.

		@param iUTF16CharUnit pointer on an UTF16 unit (may be one of the 2 possible
		surrogates).

		@return the pointer on the beginning of the character
		*/
		static const char16* GetUTF16CharBegin(const char16* iUTF16CharUnit);

		/**
		Converts an utf8 character into an ASCII character.

		If (oUTF8Count > 1) then the conversion failed since no such UTF8 chars can be
		ASCII characters.

		@param iUTF8Char the utf8 character to convert in ASCII representation.
		@param oUTF8Count it stores after call the number of char8s taken by the utf8 character.

		@return the ASCII representation or '?' if conversion failed.
		*/
		static char8	GetASCIICharFromUTF8(const char8* iUTF8Char, uint32& oUTF8Count);
		
		/**
		Converts an utf8 character into an ASCII character.

		If (oUTF8Count > 1) then the conversion failed since no such UTF8 chars can be
		ASCII characters.

		@param iUTF8Char the utf8 character to convert in ASCII representation.
		@param oASCIIChar the converted ASCII char
		@param oUTF8Count it stores after call the number of char8s taken by the utf8 character.

		@return true if the conversion succeeded, false otherwise.
		*/
		static bool	GetASCIICharFromUTF8(const char8* iUTF8Char, char8& oASCIIChar, uint32& oUTF8Count);

		/**
		Converts an utf16 character into an ASCII character.

		If (oUTF16Count > 1) then the conversion failed since no such UTF16 chars can be
		ASCII characters.

		@param iUTF16Char the utf16 to convert in ASCII representation.
		@param it stores after call the number of char16s taken by the utf16 character.

		@return the ASCII representation or '?' if conversion failed.
		*/
		static char8	GetASCIICharFromUTF16(const char16* iUTF16Char, uint32& oUTF16Count);
		
		/**
		 Converts an utf16 character into an ASCII character.
		 
		 If (oUTF16Count > 1) then the conversion failed since no such UTF16 chars can be
		 ASCII characters.
		 
		 @param iUTF16Char the utf16 to convert in ASCII representation.
		 @param oASCIIChar the converted ASCII char
		 @param it stores after call the number of char16s taken by the utf16 character.
		 
		 @return true if the conversion succeeded, false otherwise.
		 */
		static bool	GetASCIICharFromUTF16(const char16* iUTF16Char, char8& oASCIIChar, uint32& oUTF16Count);

		/**
		Converts an utf32 character into an ASCII char.

		@param iUTF32Char the utf32 to convert in ASCII representation.

		@return the ASCII representation or '?' if conversion failed.
		*/
		static char8	GetASCIICharFromUTF32(const char32 iUTF32Char);	
		
		/**
		 Converts an utf32 character into an ASCII char.
		 
		 @param iUTF32Char the utf32 to convert in ASCII representation.
		 @param oASCIIChar the converted ASCII char
		 
		 @return true if the conversion succeeded, false otherwise.
		 */
		static bool	GetASCIICharFromUTF32(const char32 iUTF32Char, char8& oASCIIChar);	

		/**
		Converts an utf16 character into an utf8 character.

		@param oUTF8Char the buffer storing the utf8 character in result.
		@param iUTF16Char the utf16 character to convert in utf8.
		@param oUTF16Count in result, the number of char16s taken by the utf16 character.

		@return the number of char8s taken by the utf8 character.
		*/
		static uint32	GetUTF8CharFromUTF16(char8* oUTF8Char, const char16* iUTF16Char);
		static uint32	GetUTF8CharFromUTF16(char8* oUTF8Char, const char16* iUTF16Char, uint32& oUTF16Count);

		/**
		Converts an utf32 character into an utf8 character.

		@param oUTF8Char the buffer storing the utf8 character in result.
		@param iUTF32Char the utf32 character to convert in utf8.

		@return the number of char8s taken by the utf8 character.
		*/
		static uint32	GetUTF8CharFromUTF32(char8* oUTF8Char, const char32 iUTF32Char);

		/**
		Converts an utf32 character into an utf16 character.

		@param oUTF16Char the buffer storing the utf16 character in result.
		@param iUTF32Char the utf32 character to convert in utf16.

		@return the number of char16s taken by the utf16 character.
		*/
		static uint32	GetUTF16CharFromUTF32	(char16* oUTF16Char, const char32 iUTF32Char);

		/**
		Converts an utf8 character into an utf16 character.

		@param oUTF16Char the buffer storing the utf16 character in result.
		@param iUTF8Char the utf8 character to convert in utf16.
		@param oUTF8Count in result, the number of char8s taken by the utf8 character.

		@return the number of char16s taken by the utf16 character.
		*/
		static uint32	GetUTF16CharFromUTF8(char16* oUTF16Char, const char8* iUTF8Char, uint32& oUTF8Count);

		/**
		Converts an utf8 character into an utf32 character.

		@param iUTF8Char the utf8 character to convert in utf32.
		@param oUTF8Count iin result, the number of char8s taken by the utf8 character.

		@return the converted utf32 character.
		*/
		static char32	GetUTF32CharFromUTF8(const char8* iUTF8Char);
		static char32	GetUTF32CharFromUTF8(const char8* iUTF8Char, uint32& oUTF8Count);
		static char32	GetUTF32CharFromUTF8Inline(const char8* iUTF8Char);
		static char32	GetUTF32CharFromUTF8Inline(const char8* iUTF8Char, uint32& oUTF8Count);

		/**
		Converts an utf16 character into an utf32 character.

		@param iUTF16Char the utf16 character to convert in utf32.
		@param oUTF16Count if not null, in result, the number of char16s taken by the utf16 character.

		@return the converted utf32 character.
		*/
		static char32	GetUTF32CharFromUTF16(const char16* iUTF16Char);
		static char32	GetUTF32CharFromUTF16(const char16* iUTF16Char, uint32& oUTF16Count);
		static char32	GetUTF32CharFromUTF16Inline(const char16* iUTF16Char);
		static char32	GetUTF32CharFromUTF16Inline(const char16* iUTF16Char, uint32& oUTF16Count);

		/**
		Verifies the string only contains ASCII characters
		(strict-ANSI characters 0-7F).

		@param iString the string.

		@return true if all characters are ASCII
		*/
		static bool	IsASCII(const char8* iString, int32 iLength = -1);

		/**
		Gets the number of bytes (trailing null char included)
		taken by a pure ascii string.

		No check are performed to verify that the string only contains pure ascii characters.

		@param iASCIIString the ascii string.
		@param iStopIndex if >= 0, the returned length is clamped with this value. (max(size) = iStopIndex + 1)

		@return the number of  bytes taken by the string.
		*/
		static uint32	GetASCIIStrSize(const char8* iASCIIString, const int32 iStopIndex = -1);

		/**
		Gets the number of bytes (trailing null char included)
		taken by an utf8 string.

		@param iUTF8String the UTF8 string.
		@param iStopIndex if >= 0, the returned length is clamped with this value. (max(size) = iStopIndex + 1)

		@return the number of  bytes taken by the string.
		*/
		static uint32	GetUTF8StrSize(const char8* iUTF8String, const int32 iStopIndex = -1);

		/**
		Gets the number of bytes (trailing null char included)
		taken by an utf16 string.

		@param iUTF16String the utf16 string.
		@param iStopIndex if >= 0, the returned length is clamped with this value. (max(size) = (iStopIndex + 1) * sizeof(char16))

		@return the number of  bytes taken by the string.
		*/
		static uint32	GetUTF16StrSize(const char16* iString, const int32 iStopIndex = -1);

		/**
		Gets the number of bytes (trailing null char included)
		taken by an utf32 string.

		@param iUTF32String the utf32 string.
		@param iStopIndex if >= 0, the returned length is clamped with this value. (max(size) = (iStopIndex + 1) * sizeof(char32))

		@return the number of  bytes taken by the string.
		*/
		static uint32	GetUTF32StrSize(const char32* iString, const int32 iStopIndex = -1);

		/**
		Gets the number of bytes (trailing null char included)
		taken by a string.

		@param iEncoding the encoding of the string.
		@param iString the string to compute its size in bytes.
		@param iStopIndex if >= 0, the returned length is clamped with this value.

		@return the number of  bytes taken by the string.
		*/
		static uint32	GetStrSize(EEncoding iEncoding, const void* iString, const int32 iStopIndex = -1);

		/**
		Gets the number of bytes (trailing null char included)
		taken by a string.

		@param iUnitSize the size of the unit which implies the encoding (unit size can be 1, 2 or 4).
		@param iString the string to compute its size in bytes.
		@param iStopIndex if >= 0, the returned length is clamped with this value.

		@return the number of  bytes taken by the string.

		@see GetDefaultEncoding to know the guessed encoding from the unit size
		*/
		static uint32	GetStrSize(const uint32 iUnitSize, const void* iString);

		/**
		Gets the logical length (expressed in logical characters)
		taken by the string. The trailing null character is excluded.
		The encoding of the string is resolved by the function name
		(ASCII, UTF8, UTF16 or UTF32).

		@param iString the string to compute the length.
		@param oIsASCII if not null, then in result, it contains true if the string is only
		made of Strict-Ansi characters (0-7F).
		@param oByteLength if not null, the size of bytes taken by the characters (trailing null char excluded).

		@return the length of the string.
		*/
		static uint32	GetASCIIStrLength(const char8* iString);
		static uint32	GetUTF8StrLength(const char8* iString, bool* oIsASCII = 0, uint32* oByteLength = 0);
		static uint32	GetUTF16StrLength(const char16* iString, uint32* oByteLength = 0);
		static uint32	GetUTF32StrLength(const char32* iString);

		/**
		Gets the logical length (expressed in logical characters)
		taken by the string. The trailing null character is excluded.

		@param iEncoding the encoding of the string.
		@param iString the string to compute the length.
		@param oByteLength if not null, the size of bytes taken by the characters (trailing null char excluded).
		
		@return the length of the string.
		*/
		static uint32	GetStrLength(EEncoding iEncoding, const void* iString, uint32* oByteLength = 0);

		/**
		Gets the logical length (expressed in logical characters)
		taken by the sub string defined by the 'iByteLength' first bytes of iString.

		@param iString the string to compute the length.
		@param oIsASCII if not null, then in result, it contains true if the string is only
		made of Strict-Ansi characters (0-7F).
		@param iByteLength the number of bytes taken by the string (then, the trailing null char is not
		the stopping criteria anymore).

		@return the length of the sub string.
		*/
		static uint32	GetASCIIStrLength(const char8* iString, const uint32 iByteLength);
		static uint32	GetUTF8StrLength(const char8* iString, bool* oIsASCII, const uint32 iByteLength);
		static uint32	GetUTF16StrLength(const char16* iString, const uint32 iByteLength);
		static uint32	GetUTF32StrLength(const char32* iString, const uint32 iByteLength);

		/**
		Helpers to interpret a char8 string (ASCII or UTF8) in a number
		*/
		static error	Interpret(const char8* iString, uint8& oNumber);
		static error	Interpret(const char8* iString, int8& oNumber);
		static error	Interpret(const char8* iString, uint16& oNumber);
		static error	Interpret(const char8* iString, int16& oNumber);
		static error	Interpret(const char8* iString, uint32& oNumber);
		static error	Interpret(const char8* iString, int32& oNumber);
		static error	Interpret(const char8* iString, uint64& oNumber);
		static error	Interpret(const char8* iString, int64& oNumber);
		static error	Interpret(const char8* iString, float& oNumber);
		static error	Interpret(const char8* iString, double& oNumber);
		static error	Interpret(const char8* iString, bool& oValue);
		static error	Interpret(const char8* iString, void*& oValue);

#if defined(VK_TARGET_MACOSX)
		static error	Interpret(const char8* iString, long int& oValue);
		static error	Interpret(const char8* iString, unsigned long int& oValue);
#endif

		/**
		Tests if a UTF16 unit is a surrogate (part
		of a pair of char16s making a logical character).

		@param iUTF16Unit the UTF16 Unit.

		@return true if the unit is a surrogate.
		*/
		static bool		IsSurrogate(const char16 iUTFUnit);

		/**
		Tests if a UTF16 unit is the first surrogate
		of a UTF16 pair.

		@param iUTF16Unit the UTF16 Unit.

		@return true if the unit is a first surrogate.
		*/
		static bool		IsFirstSurrogate(const char16 iChar16);

		/**
		Tests if a UTF16 unit is the second surrogate
		of a UTF16 pair.

		@param iUTF16Unit the UTF16 Unit.

		@return true if the unit is a second surrogate.
		*/
		static bool		IsSecondSurrogate(const char16 iChar16);

	private :


		// a vkCharacter matches an utf32 character.
		// That means sizeof(vkCharacter) == 4 and then
		// vkCharacter can be passed by copy in function arguments.
		char32					m_UTF32Char;

		// Static Data & Methods

		static uint32	_GetASCIIStrLength(const void* iString, uint32* oByteSize);
		static uint32	_GetUTF8StrLength(const void* iString, uint32* oByteSize);
		static uint32	_GetUTF16StrLength(const void* iString, uint32* oByteSize);
		static uint32	_GetUTF32StrLength(const void* iString, uint32* oByteSize);

		static uint32	_GetASCIIStrSize(const void* iString, const int32 iStopIndex);
		static uint32	_GetUTF8StrSize(const void* iString, const int32 iStopIndex);
		static uint32	_GetUTF16StrSize(const void* iString, const int32 iStopIndex);
		static uint32	_GetUTF32StrSize(const void* iString, const int32 iStopIndex);

		// Length Calculator
		typedef uint32			(*TGetStrLength)(const void* iString, uint32* oByteSize);
		static TGetStrLength	s_GetStrLengthMethods[eEncodingCount];

		// Size Calculator
		typedef uint32			(*TGetStrSize)(const void* iString, const int32 iStopIndex);
		static TGetStrSize		s_GetStrSizeMethods[eEncodingCount];

		static const char* s_NaN;
		static const char* s_InfPlus;
		static const char* s_InfMinus;

	};

#if !defined(VK_DOXYGEN)
	/**
	Helpers classes you can use as template arguments
	to retrieve a vkCharacter from an encoded character

	@ingroup grp_string
	*/
	class vkASCIICharWrapper : public vkHeapObject
	{
	public :

		typedef char8 TUnit;
		TUnit	m_Character;

		vkASCIICharWrapper(const vkCharacter& iCharacter = vkCharacter());
		vkASCIICharWrapper(const TUnit* iASCIICharacter);
		
		void Create(const vkCharacter& iCharacter);
		void Create(const TUnit* iASCIICharacter);

		operator	vkCharacter() const;
		bool		Equals(const TUnit* iASCIICharacter) const;
		uint32		GetCharSize() const;
	};

	/**
	@ingroup grp_string
	*/
	class vkUTF8CharWrapper : public vkHeapObject
	{
	public :

		typedef char8 TUnit;
		TUnit m_Character[4];
		uint32 m_CharSize;

		vkUTF8CharWrapper(const vkCharacter& iCharacter = vkCharacter());
		vkUTF8CharWrapper(const TUnit* iUTF8Character);
		
		void Create(const vkCharacter iCharacter);
		void Create(const TUnit* iUTF8Character);

		operator	vkCharacter() const;
		bool		Equals(const TUnit* iUTF8Character) const;
		uint32		GetCharSize() const;
	};

	/**
	@ingroup grp_string
	*/
	class vkUTF16CharWrapper : public vkHeapObject
	{
	public :

		typedef char16 TUnit;
		TUnit m_Character[2];
		uint32 m_CharSize;

		vkUTF16CharWrapper(const vkCharacter& iCharacter = vkCharacter());
		vkUTF16CharWrapper(const TUnit* iUTF16Character);
		
		void Create(const vkCharacter iCharacter);
		void Create(const TUnit* iUTF16Character);

		operator	vkCharacter() const;
		bool		Equals(const TUnit* iUTF16Character) const;
		uint32		GetCharSize() const;
	};

	/**
	@ingroup grp_string
	*/
	class vkUTF32CharWrapper : public vkHeapObject
	{
	public :

		typedef char32 TUnit;
		TUnit m_Character;

		vkUTF32CharWrapper(const vkCharacter& iCharacter = vkCharacter());
		vkUTF32CharWrapper(const TUnit* iUTF32Character);

		void Create(const vkCharacter iCharacter);
		void Create(const TUnit* iUTF32Character);

		operator	vkCharacter() const;
		bool		Equals(const TUnit* iUTF32Character) const;
		uint32		GetCharSize() const;
	};
#endif // VK_DOXYGEN

}

#include "vkCharacter.hpp"

#endif // __vkCharacter_h

