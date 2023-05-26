/**
@file

Inline implementation of the character class.

@COPYRIGHT

@author Edwin, Gerald Guyomard
*/

#if !defined(vkCharacter_hpp)
#define vkCharacter_hpp

namespace VKernel
{

VK_INLINE vkCharacter::vkCharacter()
: m_UTF32Char(0)
{}

VK_INLINE vkCharacter::vkCharacter(const vkCharacter& iOther) 
: m_UTF32Char(iOther.m_UTF32Char)
{}

VK_INLINE vkCharacter::vkCharacter(const char32 iUTF32Code)
{
	*this = iUTF32Code;
}

VK_INLINE
vkCharacter::vkCharacter(const char8 iASCIICode)
{
	VKASSERT(iASCIICode >= 0); // "Invalid ASCII character"
	m_UTF32Char = iASCIICode;
}

#if defined(VK_WCHAR_T_IS_BUILT_IN)
VK_INLINE
vkCharacter::vkCharacter(const wchar_t iWideCharCode)
{
#if defined(VK_WCHAR_T_IS_UTF32)
	m_UTF32Char = (char32) iWideCharCode;
#else
	// No Surrogate
	VKASSERT(!IsSurrogate((const char16) iWideCharCode)); // "wide char is surrogate"
	m_UTF32Char = (char32) iWideCharCode;
#endif
}
#endif

VK_INLINE
vkCharacter::vkCharacter(const char16 iChar16Code)
{
#if defined(VK_WCHAR_T_IS_UTF32)
	m_UTF32Char = (char32) iChar16Code;
#else
	// No Surrogate
	VKASSERT(!IsSurrogate((const char16) iChar16Code)); // "wide char is surrogate"
	m_UTF32Char = (char32) iChar16Code;
#endif
}

VK_INLINE bool
vkCharacter::IsNull() const
{
	return m_UTF32Char == 0;
}

VK_INLINE bool
vkCharacter::IsValid() const
{
	return m_UTF32Char != 0;
}

VK_INLINE char32
vkCharacter::GetUTF32Char() const
{
	return m_UTF32Char;
}

VK_INLINE char8			
vkCharacter::GetASCIIChar() const
{
	return GetASCIICharFromUTF32(m_UTF32Char);
}

VK_INLINE VKernel::uint32
vkCharacter::GetUTF8Char(char8* oChars) const
{
	return GetUTF8CharFromUTF32(oChars, m_UTF32Char);
}

VK_INLINE VKernel::uint32
vkCharacter::GetUTF16Char(char16* oChars) const
{
	return GetUTF16CharFromUTF32(oChars, m_UTF32Char);
}

VK_INLINE vkCharacter&
vkCharacter::operator=(const vkCharacter& iOther)
{
	*this = iOther.m_UTF32Char;
	return *this;
}

VK_INLINE bool
vkCharacter::operator==(const vkCharacter& iOther) const
{
	return m_UTF32Char == iOther.m_UTF32Char;
}

VK_INLINE bool
vkCharacter::operator!=(const vkCharacter& iOther) const
{
	return m_UTF32Char != iOther.m_UTF32Char;
}

VK_INLINE bool
vkCharacter::operator==(const char8 iOther) const
{
	return *this == vkCharacter(iOther);
}

VK_INLINE bool
vkCharacter::operator!=(const char8 iOther) const
{
	return *this != vkCharacter(iOther);
}

VK_INLINE bool
vkCharacter::operator==(const char16 iOther) const
{
	return *this == vkCharacter((const char32) iOther);
}

VK_INLINE bool
vkCharacter::operator!=(const char16 iOther) const
{
	return *this != vkCharacter((const char32) iOther);
}

VK_INLINE bool
vkCharacter::operator==(const char32 iOther) const
{
	return m_UTF32Char == iOther;
}

VK_INLINE bool
vkCharacter::operator!=(const char32 iOther) const
{
	return m_UTF32Char != iOther;
}

VK_INLINE bool
vkCharacter::IsSeparator() const
{
	return (m_UTF32Char == ' ') || (m_UTF32Char == '\t') || (m_UTF32Char == '\n') || (m_UTF32Char == '\r');
}

VK_INLINE bool
vkCharacter::IsAscii() const
{
	return m_UTF32Char <= 0x7F;
}

VK_INLINE bool
vkCharacter::IsDigit() const
{
	return ((m_UTF32Char >= '0') && (m_UTF32Char <= '9'));
}

VK_INLINE bool
vkCharacter::IsAlphaNum() const
{
	return IsDigit() || IsAlpha();
}

VK_INLINE VKernel::uint32
vkCharacter::GetStrSize(const VKernel::uint32 iUnitSize, const void* iString)
{
	switch(iUnitSize)
	{
	case 1: return GetASCIIStrSize((const char8*) iString);
	case 2: return GetUTF16StrSize((const char16*) iString);
	case 4: return GetUTF32StrSize((const char32*) iString);
	default : return 0;
	}
}

VK_INLINE vkCharacter::EEncoding
vkCharacter::GetDefaultEncoding(const VKernel::uint32 iUnitSize)
{
	switch(iUnitSize)
	{
	case 1 : return eUTF8Encoding; break;
	case 2 : return eUTF16Encoding; break;
	case 4 : return eUTF32Encoding; break;
	}

	return eInvalidEncoding;
}

VK_INLINE bool
vkCharacter::IsSurrogate(const char16 iChar16)
{
	return (iChar16 & 0xD800) == 0xD800;
}

VK_INLINE bool
vkCharacter::IsFirstSurrogate(const char16 iChar16)
{
	return (iChar16 & 0xDC00) == 0xD800;
}

VK_INLINE bool
vkCharacter::IsSecondSurrogate(const char16 iChar16)
{
	return (iChar16 & 0xDC00) == 0xDC00;
}

VK_INLINE VKernel::int32
vkCharacter::Compare(const vkCharacter& iOther) const
{
	return m_UTF32Char - iOther.m_UTF32Char;
}

VK_INLINE VKernel::int32
vkCharacter::ICompare(const vkCharacter& iOther) const
{
	vkCharacter c1 = *this;
	c1.ToLower();

	vkCharacter c2 = iOther;
	c2.ToLower();

	return c1.Compare(c2);
}

VK_INLINE bool
vkCharacter::IsInSet(const vkCharacter* iSet, VKernel::uint32 iCount) const
{
	const vkCharacter* setEnd = iSet + iCount;
	while (iSet != setEnd) {
		if (iSet->m_UTF32Char == m_UTF32Char)
			return true;
		++iSet;
	}
	return false;
}

VK_INLINE bool
vkCharacter::IsInSet(const char8* iSet, VKernel::uint32 iCount) const
{
	const char8* setEnd = iSet + iCount;
	while (iSet != setEnd) {
		if (char32(*iSet) == m_UTF32Char)
			return true;
		++iSet;
	}
	return false;
}

VK_INLINE VKernel::uint32
vkCharacter::GetFloatPrecision()
{
	return kFloatPrecision;
}

VK_INLINE VKernel::uint32
vkCharacter::GetAuthoringFloatPrecision()
{
	return kAuthoringFloatPrecision;
}

VK_INLINE const vkCharacter&
vkCharacter::GetDecimalPoint()
{
	return kDecimalPoint;
}

VK_INLINE void
vkCharacter::SetFloatPrecision(VKernel::uint32 iPrecision)
{
	kFloatPrecision = iPrecision;
}

VK_INLINE void
vkCharacter::SetAuthoringFloatPrecision(VKernel::uint32 iPrecision)
{
	kAuthoringFloatPrecision = iPrecision;
}

VK_INLINE void
vkCharacter::SetDecimalPoint(const vkCharacter& iDecimalPoint)
{
	kDecimalPoint = iDecimalPoint;
}

VK_INLINE uint32
vkCharacter::GetUTF8ChrSizeInline(const char8* iUnit)
{
	const uint32 c = *((const uint8*) iUnit);

	if (c <= 0x7F)
		return 1;
	else if (c <= 0xDF)
		return 2;
	else if (c <= 0xEF)
		return 3;
	else if (c <= 0xF7)
		return 4;
	else if(c == 0xFF){
		*((char8*) iUnit) = ' ';
		return 1;
	}
	else
	{
		VKUNSUPPORTEDEX("invalid utf8 code");
		return 1; // Returning 1 to continue reading?
	}
}

VK_INLINE uint32
vkCharacter::GetPreviousUTF8ChrSizeInline(const char8* iUnit)
{
	const int8* prevC = (const int8*) (iUnit - 1);
	// The secondary bytes follows 10xxxxxx
	while ((*prevC & 0xc0) == 0x80)
		--prevC;

	const uint32 charSize = uint32(iUnit - (const char8*) prevC);
	VKASSERT(charSize <= 4); // "UTF8 Char Size > 4"
	return charSize;
}

VK_INLINE uint32
vkCharacter::GetUTF16ChrSizeInline(const char16* iUnit)
{
	const uint32 firstSurrogate = (uint32) *iUnit;
	if (firstSurrogate <= 0x007F)
		return 2;
	else if ((firstSurrogate < 0xD800) || (firstSurrogate > 0xDFFF))
		return 2;
	else
		return 4;
}

VK_INLINE uint32
vkCharacter::GetPreviousUTF16ChrSizeInline(const char16* iUnit)
{
	const char16 prevC = *(iUnit - 1);
	VKASSERT(!IsFirstSurrogate(prevC)); // "previous char is first surrogate"
	if (IsSecondSurrogate(prevC))
	{
		return 2 * sizeof(char16);
	}
	else
	{
		return sizeof(char16);
	}
}

VK_INLINE char32
vkCharacter::GetUTF32CharFromUTF8Inline(const char8* iUTF8Char)
{
	if (*iUTF8Char >= 0)
	{
		return (char32) *iUTF8Char;
	}

	const uint8* src = (const uint8*) iUTF8Char;
	const uint32 c = *src;

	char32 c32;
	if (c <= 0xDF)
	{
		c32  = (c & 0x1F) << 6;
		c32 += (*(++src) & 0x3F);
	}
	else if (c <= 0xEF)
	{
		c32  = (c & 0x0F) << 12;
		c32 += (*(++src) & 0x3F) << 6;
		c32 += (*(++src) & 0x3F);
	}
	else if (c <= 0xF7)
	{
		c32  = (c & 0x07) << 18;
		c32 += (*(++src) & 0x3F) << 12;
		c32 += (*(++src) & 0x3F) << 6;
		c32 += (*(++src) & 0x3F);
	}
	else
	{
		c32 = 0xFFFD;
	}

	return c32;
}

VK_INLINE char32
vkCharacter::GetUTF32CharFromUTF8Inline(const char8* iUTF8Char, uint32& oUTF8CharSize)
{
	if (*iUTF8Char >= 0)
	{
		oUTF8CharSize = 1;
		return (char32) *iUTF8Char;
	}

	const uint8* src = (const uint8*) iUTF8Char;
	const uint32 c = *src;

	char32 c32;
	if (c <= 0xDF)
	{
		c32  = (c & 0x1F) << 6;
		c32 += (*(++src) & 0x3F);

		oUTF8CharSize = 2;
	}
	else if (c <= 0xEF)
	{
		c32  = (c & 0x0F) << 12;
		c32 += (*(++src) & 0x3F) << 6;
		c32 += (*(++src) & 0x3F);

		oUTF8CharSize = 3;
	}
	else if (c <= 0xF7)
	{
		c32  = (c & 0x07) << 18;
		c32 += (*(++src) & 0x3F) << 12;
		c32 += (*(++src) & 0x3F) << 6;
		c32 += (*(++src) & 0x3F);

		oUTF8CharSize = 4;
	}
	else
	{
		c32 = 0xFFFD;

		oUTF8CharSize = 1;
	}

	return c32;
}

VK_INLINE char32
vkCharacter::GetUTF32CharFromUTF16Inline(const char16* iUTF16Char)
{
	const uint32 firstSurrogate = (uint32) *iUTF16Char;
	if (firstSurrogate <= 0x007F)
	{
		return char32(firstSurrogate);
	}

	// UTF16 -> UTF32
	if ((firstSurrogate < 0xD800) || (firstSurrogate > 0xDFFF))
	{
		return char32(firstSurrogate);
	}
	else
	{
		char32 c32  = (firstSurrogate - 0xD7C0) << 10;
		const char32 secondSurrogate = *(++iUTF16Char);
		c32 +=  secondSurrogate & 0x03FF;
		return c32;
	}
}

VK_INLINE char32
vkCharacter::GetUTF32CharFromUTF16Inline(const char16* iUTF16Char, uint32& oUTF16Count)
{
	const uint32 firstSurrogate = (uint32) *iUTF16Char;
	if (firstSurrogate <= 0x007F)
	{
		oUTF16Count = 1;
		return char32(firstSurrogate);
	}

	// UTF16 -> UTF32
	if ((firstSurrogate < 0xD800) || (firstSurrogate > 0xDFFF))
	{
		oUTF16Count = 1;
		return char32(firstSurrogate);
	}
	else
	{
		oUTF16Count = 2;

		char32 c32  = (firstSurrogate - 0xD7C0) << 10;
		const char32 secondSurrogate = *(++iUTF16Char);
		c32 +=  secondSurrogate & 0x03FF;
		return c32;
	}
}

VK_INLINE vkASCIICharWrapper::vkASCIICharWrapper(const TUnit* iCharacter)
: m_Character(*iCharacter)
{}

VK_INLINE vkASCIICharWrapper::vkASCIICharWrapper(const vkCharacter& iCharacter)
{
	Create(iCharacter);
}

VK_INLINE void
vkASCIICharWrapper::Create(const TUnit* iCharacter)
{
	m_Character = *iCharacter;
}

VK_INLINE void
vkASCIICharWrapper::Create(const vkCharacter& iCharacter)
{
	m_Character = iCharacter.GetASCIIChar();
}

VK_INLINE vkASCIICharWrapper::operator vkCharacter() const
{
	return vkCharacter(m_Character);
}

VK_INLINE bool
vkASCIICharWrapper::Equals(const TUnit* iASCIICharacter) const
{
	return m_Character == *iASCIICharacter;
}

VK_INLINE VKernel::uint32
vkASCIICharWrapper::GetCharSize() const
{
	return sizeof(char8);
}

VK_INLINE vkUTF8CharWrapper::vkUTF8CharWrapper(const TUnit* iCharacter)
{
	Create(iCharacter);
}

VK_INLINE vkUTF8CharWrapper::vkUTF8CharWrapper(const vkCharacter& iCharacter)
{
	Create(iCharacter);
}

VK_INLINE void
vkUTF8CharWrapper::Create(const TUnit* iCharacter)
{
	m_CharSize = vkCharacter::GetUTF8ChrSize(iCharacter);
	vkMemCopy(m_Character, iCharacter, m_CharSize);
}

VK_INLINE void
vkUTF8CharWrapper::Create(const vkCharacter iCharacter)
{
	m_CharSize = iCharacter.GetUTF8Char(m_Character);
}

VK_INLINE vkUTF8CharWrapper::operator vkCharacter() const
{
	return vkCharacter(vkCharacter::GetUTF32CharFromUTF8(m_Character));
}

VK_INLINE
bool vkUTF8CharWrapper::Equals(const TUnit* iUTF8Character) const
{
	// Tests the four characters
	const char8* c1 = m_Character;
	const char8* c2 = iUTF8Character;

	for (VKernel::uint32 i=0; i < m_CharSize; ++i)
	{
		if (*(c1++) != *(c2++))
			return false;
	}

	return true;
}

VK_INLINE VKernel::uint32
vkUTF8CharWrapper::GetCharSize() const
{
	return m_CharSize;
}

VK_INLINE vkUTF16CharWrapper::vkUTF16CharWrapper(const TUnit* iCharacter)
{
	Create(iCharacter);
}

VK_INLINE vkUTF16CharWrapper::vkUTF16CharWrapper(const vkCharacter& iCharacter)
{
	Create(iCharacter);
}

VK_INLINE void
vkUTF16CharWrapper::Create(const TUnit* iCharacter)
{
	m_CharSize = vkCharacter::GetUTF16ChrSize(iCharacter);
	vkMemCopy(m_Character, iCharacter, m_CharSize);
}

VK_INLINE void
vkUTF16CharWrapper::Create(const vkCharacter iCharacter)
{
	m_CharSize = iCharacter.GetUTF16Char(m_Character);
}

VK_INLINE vkUTF16CharWrapper::operator vkCharacter() const
{
	return vkCharacter(vkCharacter::GetUTF32CharFromUTF16(m_Character));
}

VK_INLINE
bool vkUTF16CharWrapper::Equals(const TUnit* iUTF16Character) const
{
	for (VKernel::uint32 i=0; i < m_CharSize; ++i)
	{
		if (m_Character[i] != iUTF16Character[i])
			return false;
	}

	return true;
}

VK_INLINE VKernel::uint32
vkUTF16CharWrapper::GetCharSize() const
{
	return m_CharSize * sizeof(char16);
}

VK_INLINE vkUTF32CharWrapper::vkUTF32CharWrapper(const TUnit* iCharacter)
: m_Character(*iCharacter)
{}

VK_INLINE vkUTF32CharWrapper::vkUTF32CharWrapper(const vkCharacter& iCharacter)
{
	Create(iCharacter);
}

VK_INLINE void
vkUTF32CharWrapper::Create(const TUnit* iCharacter)
{
	m_Character = *iCharacter;
}

VK_INLINE void
vkUTF32CharWrapper::Create(const vkCharacter iCharacter)
{
	m_Character = iCharacter.GetUTF32Char();
}

VK_INLINE vkUTF32CharWrapper::operator vkCharacter() const
{
	return vkCharacter(m_Character);
}

VK_INLINE
bool vkUTF32CharWrapper::Equals(const TUnit* iUTF32Character) const
{
	return m_Character == *iUTF32Character;
}

VK_INLINE VKernel::uint32
vkUTF32CharWrapper::GetCharSize() const
{
	return sizeof(char32);
}

} // End of namespace VKernel

#endif // vkCharacter_hpp

