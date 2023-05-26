/**
@file

This file defines the string Class.

@COPYRIGHT

@author Edwin, Gerald Guyomard
*/
VK_INLINE vkString::vkString(const char8* iASCIIString, uint16 iPrecomputedSize)
{
	m_Chars	= (char8*) iASCIIString;
	m_Pack	= (sizeof(char8) << 8 /*constant unit size*/) | (fIsStatic/*flags*/) | vkCharacter::eASCIIEncoding;
	m_.smallSize = iPrecomputedSize;
}

VK_INLINE vkString::vkString(uint32 iPack)
: m_Pack(iPack)
{

}

VK_INLINE void
vkString::_ConstructFromWideChar(const wchar_t* iString, uint32 iSizeInBytes, bool iIsStatic, vkCharacter::EEncoding iInternalEncoding, const EAllocatorID iAllocatorID)
{
#if defined(VK_WCHAR_T_IS_UTF32)
	_ConstructFromUTF32((const char32*) iString, iSizeInBytes, iIsStatic, iInternalEncoding, iAllocatorID);
#else
	_ConstructFromUTF16((const char16*) iString, iSizeInBytes, iIsStatic, iInternalEncoding, iAllocatorID);
#endif
}

VK_INLINE void
vkString::CreatePersistentFromString(const vkString& iString, vkCharacter::EEncoding iInternalEncoding, bool iFixedEncoding)
{
	CreateFromString(iString, iInternalEncoding, iFixedEncoding, eStdAllocator);
}

VK_INLINE void
vkString::CreatePersistentFromASCII(const char8* iString, vkCharacter::EEncoding iInternalEncoding, bool iFixedEncoding)
{
	CreateFromASCII(iString, 0 /*size In Bytes*/, false /*iIsStatic*/, iInternalEncoding, iFixedEncoding, eStdAllocator);
}

VK_INLINE void
vkString::CreatePersistentFromUTF8(const char8* iString, vkCharacter::EEncoding iInternalEncoding, bool iFixedEncoding)
{
	CreateFromUTF8(iString, 0 /*size In Bytes*/, false /*iIsStatic*/, iInternalEncoding, iFixedEncoding, eStdAllocator);
}

VK_INLINE void
vkString::CreatePersistentFromUTF16(const char16* iString, vkCharacter::EEncoding iInternalEncoding, bool iFixedEncoding)
{
	CreateFromUTF16(iString, 0 /*size In Bytes*/, false /*iIsStatic*/, iInternalEncoding, iFixedEncoding, eStdAllocator);
}

VK_INLINE void
vkString::CreatePersistentFromUTF32(const char32* iString, vkCharacter::EEncoding iInternalEncoding, bool iFixedEncoding)
{
	CreateFromUTF32(iString, 0 /*size In Bytes*/, false /*iIsStatic*/, iInternalEncoding, iFixedEncoding, eStdAllocator);
}

VK_INLINE void
vkString::CreatePersistentFromWideChar(const wchar_t* iString, vkCharacter::EEncoding iInternalEncoding, bool iFixedEncoding)
{
	CreateFromWideChar(iString, 0 /*size In Bytes*/, false /*iIsStatic*/, iInternalEncoding, iFixedEncoding, eStdAllocator);
}

#if defined(VK_WCHAR_T_IS_BUILT_IN)
VK_INLINE
vkString&
vkString::operator<<(const wchar_t* iWideCharString)
{
#if defined(VK_WCHAR_T_IS_UTF32)
	return operator<<((const char32*) iWideCharString);
#else
	return operator<<((const char16*) iWideCharString);
#endif
}
#endif

VK_INLINE
vkString::~vkString()
{
	_Destruct();
}

VK_INLINE uint32
vkString::Size() const
{
	if (m_.smallSize != 0)
	{
		return m_.smallSize;
	}
	else
	{
		VKASSERT(!IsStatic());
		return (((const LargeHeader*) m_Chars) - 1)->largeSize;
	}
}

VK_INLINE uint32
vkString::GetPackedData() const
{
	return m_Pack;
}

VK_INLINE
uint32
vkString::Hash() const
{
	switch(GetEncoding())
	{
		default:
		case vkCharacter::eUTF8Encoding:
		{
			if (!HasConstantCharSize())
			{
				return _HashUTF8();
			}
			// else let it go in the case ASCII
		}

		case vkCharacter::eASCIIEncoding:
		{
			return _HashASCII();
		}

		case vkCharacter::eUTF16Encoding:
		{
			return _HashUTF16();
		}

		case vkCharacter::eUTF32Encoding:
		{
			return _HashUTF32();
		}
	}
}

VK_INLINE vkString&
vkString::ToLower()
{
	switch(GetEncoding())
	{
		case vkCharacter::eUTF8Encoding:
		{
			return _ToLowerUTF8();
		}

		case vkCharacter::eASCIIEncoding:
		{
			return _ToLowerASCII();
		}

		default:
		{
			return _ToLowerGeneric();
		}
	}
}

VK_INLINE vkString&
vkString::ToUpper()
{
	switch(GetEncoding())
	{
		case vkCharacter::eUTF8Encoding:
		{
			return _ToUpperUTF8();
		}

		case vkCharacter::eASCIIEncoding:
		{
			return _ToUpperASCII();
		}

		default:
		{
			return _ToUpperGeneric();
		}
	}
}

VK_INLINE
bool
vkString::HasConstantCharSize() const
{
	return m_.constantCharSize != 0;
}

VK_INLINE bool
vkString::HasFixedEncoding() const
{
	return (m_.internalFlags & fHasFixedEncoding) != 0;
}

VK_INLINE bool
vkString::HasFixedAllocator() const
{
	return (m_.internalFlags & fHasFixedAllocator) != 0;
}

VK_INLINE void
vkString::EnableFixedEncoding()
{
	m_.internalFlags |= fHasFixedEncoding;
}

VK_INLINE vkString::ConstIterator
vkString::GetIterator(const uint32 iLogicalPos) const
{
	char8* current;
	if (HasConstantCharSize()) 	{ // Direct access to the character
		current = m_Chars + (iLogicalPos << UnitPow2());
	} else
		current = GetMethods()->GetCharAddress(m_Chars, iLogicalPos);

	VKASSERT(current <= _GetEndChars()); // "iterator pointing address after End()"
	return ConstIterator(this, current);
}

VK_INLINE vkString::Iterator
vkString::GetIterator(const uint32 iLogicalPos)
{
	char8* current;
	if (HasConstantCharSize()) 	{ // Direct access to the character
		current = m_Chars + (iLogicalPos << UnitPow2());
	} else
		current = GetMethods()->GetCharAddress(m_Chars, iLogicalPos);

	VKASSERT(current <= _GetEndChars()); // "iterator pointing address after End()"
	return Iterator(this, current);
}

VK_INLINE vkString
vkString::operator+(const vkString& iOther) const
{
	vkString tmp(*this);
	tmp << iOther;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const char8* iASCIIString) const
{
	vkString tmp(*this);
	tmp << iASCIIString;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const char16* iUTF16String) const
{
	vkString tmp(*this);
	tmp << iUTF16String;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const char32* iUTF32String) const
{
	vkString tmp(*this);
	tmp << iUTF32String;
	return tmp;
}

#if defined(VK_WCHAR_T_IS_BUILT_IN)
VK_INLINE vkString
vkString::operator+(const wchar_t* iWideCharString) const
{
	vkString tmp(*this);
	tmp << iWideCharString;
	return tmp;
}
#endif

VK_INLINE vkString
vkString::operator+(const vkCharacter& iChar) const
{
	vkString tmp(*this);
	tmp << iChar;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const uint64 iInt) const
{
	vkString tmp(*this);
	tmp << iInt;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const int64 iInt) const
{
	vkString tmp(*this);
	tmp << iInt;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const uint32 iInt) const
{
	vkString tmp(*this);
	tmp << iInt;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const int32 iInt) const
{
	vkString tmp(*this);
	tmp << iInt;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const float iFloat) const
{
	vkString tmp(*this);
	tmp << iFloat;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const double iDouble) const
{
	vkString tmp(*this);
	tmp << iDouble;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const void* iPointer) const
{
	vkString tmp(*this);
	tmp << iPointer;
	return tmp;
}

VK_INLINE vkString
vkString::operator+(const vkFourCC& iFourCC) const
{
	vkString tmp(*this);
	tmp << iFourCC;
	return tmp;
}

VK_INLINE vkCharacter::EEncoding
vkString::GetEncoding() const
{
	return (vkCharacter::EEncoding) (m_.internalFlags & fEncodingMask);
}

VK_INLINE void
vkString::_SetEncoding(vkCharacter::EEncoding iEncoding)
{
	m_.internalFlags &= ~fEncodingMask;
	m_.internalFlags |= iEncoding;
}

VK_INLINE bool
vkString::IsStatic() const
{
	return (m_.internalFlags & fIsStatic) != 0;
}

VK_INLINE vkString::EAllocatorID
vkString::GetAllocatorID() const
{
	return (m_.internalFlags & fUseStandardAllocator) != 0 ? eStdAllocator : ePoolAllocator;
}

VK_INLINE
bool
vkString::operator!=(const vkString& iOther) const
{
	return !(*this == iOther);
}

VK_INLINE
bool
vkString::operator!=(const char8* iString) const
{
	return !(*this == iString);
}


VK_INLINE bool
vkString::IsLargeSize(const uint32 iSize)
{
	return (iSize >> 16) != 0;
}

VK_INLINE char8*
vkString::_GetChars(const void* iBuffer, const uint32 iAllocatedSize)
{
	if (IsLargeSize(iAllocatedSize))
	{
		return (char8*) (((LargeHeader*) iBuffer) + 1);
	}
	else
	{
		return (char8*) (((SmallHeader*) iBuffer) + 1);
	}
}


VK_INLINE void*
vkString::_GetBuffer(const char8* iChars)
{
	const SmallHeader* header = ((const SmallHeader*) iChars) - 1;
	if (header->allocatedSizeEx.hi == 0)
	{
		return (void*) header;
	}
	else
	{
		return (void*) (((const LargeHeader*) iChars) - 1);
	}
}

VK_INLINE const char8*
vkString::ASCIICStr() const
{
	VKASSERT(GetEncoding() == vkCharacter::eASCIIEncoding || HasConstantCharSize()); // "Wrong encoding"
	return m_Chars;
}

VK_INLINE const char8*
vkString::UTF8CStr() const
{
	VKASSERT(GetEncoding() == vkCharacter::eUTF8Encoding); // "Wrong encoding"
	return m_Chars;
}

VK_INLINE const char16*
vkString::UTF16CStr() const
{
	VKASSERT(GetEncoding() == vkCharacter::eUTF16Encoding); // "Wrong encoding"
	return (const char16*) m_Chars;
}

VK_INLINE const wchar_t*
vkString::WideCharCStr() const
{
	VKASSERT(GetEncoding() == vkCharacter::eWideCharEncoding); // "Wrong encoding"
	return (const wchar_t*)m_Chars;
}

VK_INLINE const char32*
vkString::UTF32CStr() const
{
	VKASSERT(GetEncoding() == vkCharacter::eUTF32Encoding); // "Wrong encoding"
	return (const char32*) m_Chars;
}

VK_INLINE const char8*
vkString::GetChars() const
{
	return m_Chars;
}

VK_INLINE const char8*
vkString::GetEndChars() const
{
	return _GetEndChars();
}

VK_INLINE uint32
vkString::UnitSize() const
{
	return vkCharacter::s_UnitSizes[GetEncoding()];
}

VK_INLINE bool
vkString::_CanFitEncodingWithoutConversion(vkCharacter::EEncoding iEncoding) const
{
	uint32 bit = ((GetEncoding() << 2) + iEncoding);
	if (HasConstantCharSize())
	{
		bit += (1 << 4);
	}

	const uint32 mask = 1 << bit;

	return (0x84338423 & mask) != 0;

	/*
	const vkCharacter::EEncoding myEncoding = GetEncoding();
	if (myEncoding == iEncoding)
	return true;

	if ((myEncoding == vkCharacter::eASCIIEncoding) && (iEncoding == vkCharacter::eUTF8Encoding))
	return true;

	if (((myEncoding == vkCharacter::eUTF8Encoding) && HasConstantCharSize()) && (iEncoding == vkCharacter::eASCIIEncoding))
	return true;

	return false;*/
}

VK_INLINE bool
vkString::_CanBeFastCompared(vkCharacter::EEncoding iOtherEncoding) const
{
	return UnitSize() == vkCharacter::s_UnitSizes[iOtherEncoding];
}

VK_INLINE uint32
vkString::UnitPow2() const
{
	return vkCharacter::s_UnitPow2s[GetEncoding()];
}

VK_INLINE int32
vkString::_GetRefCount() const
{
	VKASSERT(!IsStatic()); // "Cannot get the refcount if the string is static"
	return (((SmallHeader*) m_Chars) - 1)->refCount;
}

VK_INLINE uint32&
vkString::_GetAllocatedSize(char8* iChars)
{
	return ((SmallHeader*)iChars - 1)->allocatedSize;
}

VK_INLINE uint32
vkString::_GetBufferAndHeaderSize(const uint32 iAllocatedSize, uint32& oHeaderSize)
{
	if (IsLargeSize(iAllocatedSize))
	{
		oHeaderSize = sizeof(LargeHeader);
		return sizeof(LargeHeader) + iAllocatedSize;
	}
	else
	{
		oHeaderSize = sizeof(SmallHeader);
		return sizeof(SmallHeader) + iAllocatedSize;
	}
}

VK_INLINE char8*
vkString::_GetEndChars()
{
	VKASSERT(m_Chars != 0); // "m_Chars is null"
	return m_Chars + Size() - UnitSize();
}

VK_INLINE const char8*
vkString::_GetEndChars() const
{
	VKASSERT(m_Chars != 0); // "m_Chars is null"
	return m_Chars + Size() - UnitSize();
}

template <typename TChar>
VK_INLINE char8*
vkString::_GetEndChars() const
{
	return m_Chars + Size() - sizeof(TChar);
}

template <typename TChar>
VK_INLINE void
vkString::_WriteTerminalNullChar(uint32 iSizeInBytes)
{
	VKASSERT(!IsStatic());
	*((TChar*)(m_Chars + iSizeInBytes - sizeof(TChar))) = 0;
}

VK_INLINE uint32&
vkString::_GetAllocatedSize()
{
	VKASSERT(!IsStatic()); // "Cannot get the allocated size if the string is static"
	return _GetAllocatedSize(m_Chars);
}

VK_INLINE uint32
vkString::_GetAllocatedSizeValue() const
{
	VKASSERT(!IsStatic()); // "Cannot get the allocated size if the string is static"
	return _GetAllocatedSize(m_Chars);
}

VK_INLINE void*
vkString::_Allocate(uint32& iSize) const
{
	return _Allocate(GetAllocatorID(), iSize);
}

VK_INLINE void*
vkString::_FitAllocate(const uint32 iSize) const
{
	return _FitAllocate(GetAllocatorID(), iSize);
}

VK_INLINE void
vkString::_Deallocate(void* iBuffer, uint32 iAllocatedSize) const
{
	_Deallocate(GetAllocatorID(), iBuffer, iAllocatedSize);
}

VK_INLINE bool
vkString::IsSmall() const
{
	return m_.smallSize != 0;
}

VK_INLINE bool
vkString::IsLarge() const
{
	return m_.smallSize == 0;
}

VK_INLINE uint32
vkString::Length() const
{
	if (HasConstantCharSize())
	{
		return (Size() >> UnitPow2()) - 1;
	}
	else // Needs to recompute length from scratch
		return vkCharacter::GetStrLength(GetEncoding(), m_Chars);
}

VK_INLINE uint32
vkString::Capacity() const
{
	return IsStatic() ? 0 : _GetAllocatedSizeValue();
}

VK_INLINE bool
vkString::IsEmpty() const
{
	return m_.smallSize == UnitSize();
}

VK_INLINE vkString::Iterator
vkString::Begin()
{
	return Iterator(this, m_Chars);
}

VK_INLINE vkString::Iterator
vkString::End()
{
	return Iterator(this, _GetEndChars());
}

VK_INLINE vkString::ConstIterator
vkString::Begin() const
{
	return ConstIterator(this, m_Chars);
}

VK_INLINE vkString::ConstIterator
vkString::End() const
{
	return ConstIterator(this, (char8*)_GetEndChars());
}

VK_INLINE vkString::Iterator
vkString::RBegin()
{
	return --End();
}

VK_INLINE vkString::Iterator
vkString::REnd()
{
	return --Begin();
}

VK_INLINE vkCharacter
vkString::Front() const
{
	return *Begin();
}

VK_INLINE vkCharacter
vkString::Back() const
{
	return *RBegin();
}

VK_INLINE vkString::ConstIterator
vkString::RBegin() const
{
	return --End();
}

VK_INLINE vkString::ConstIterator
vkString::REnd() const
{
	return --Begin();
}

VK_INLINE bool
vkString::RangeEquals(const vkString::ConstIterator& iStart, const vkString& iPattern, vkString::ConstIterator* oItAfterPattern) const
{
	return RangeEquals(iStart, iPattern.Begin(), iPattern.End(), oItAfterPattern);
}

VK_INLINE int32
vkString::RangeCompare(const vkString& iOther, int32 iLength) const
{
	return RangeCompare(iOther, Begin(), iOther.Begin(), iLength);
}

VK_INLINE int32
vkString::RangeCompare(const vkString& iOther, const ConstIterator& iThisStart, int32 iLength) const
{
	return RangeCompare(iOther, iThisStart, iOther.Begin(), iLength);
}

VK_INLINE int32
vkString::IRangeCompare(const vkString& iOther, int32 iLength) const
{
	return IRangeCompare(iOther, Begin(), iOther.Begin(), iLength);
}

VK_INLINE int32
vkString::IRangeCompare(const vkString& iOther, const ConstIterator& iThisStart, int32 iLength) const
{
	return IRangeCompare(iOther, iThisStart, iOther.Begin(), iLength);
}

VK_INLINE vkString::ConstIterator
vkString::Find(const vkCharacter& iChar) const
{
	return ConstIterator(this, _Find(iChar, m_Chars, _GetEndChars()));
}

VK_INLINE vkString::ConstIterator
vkString::Find(const vkCharacter& iChar, const ConstIterator& iStart) const
{
	VKASSERT(iStart.IsValid(*this));
	return ConstIterator(this, _Find(iChar, iStart.m_Current, _GetEndChars()));
}

VK_INLINE vkString::ConstIterator
vkString::Find(const vkCharacter& iChar, const ConstIterator& iStart, const ConstIterator& iEnd) const
{
	VKASSERT(iStart.IsValid(*this));
	VKASSERT(iEnd.IsValid(*this));
	return ConstIterator(this, _Find(iChar, iStart.m_Current, iEnd.m_Current));
}

VK_INLINE vkString::ConstIterator
vkString::Find(const vkString& iOther) const
{
	return ConstIterator(this, _Find(iOther, m_Chars, _GetEndChars()));
}

VK_INLINE vkString::ConstIterator
vkString::Find(const vkString& iOther, const ConstIterator& iStart) const
{
	VKASSERT(iStart.IsValid(*this));
	return ConstIterator(this, _Find(iOther, iStart.m_Current, _GetEndChars()));
}

VK_INLINE vkString::ConstIterator
vkString::Find(const vkString& iOther, const ConstIterator& iStart, const ConstIterator& iEnd) const
{
	VKASSERT(iStart.IsValid(*this));
	VKASSERT(iEnd.IsValid(*this));
	return ConstIterator(this, _Find(iOther, iStart.m_Current, iEnd.m_Current));
}


VK_INLINE char8*
vkString::_Find(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const
{
	switch(GetEncoding())
	{
		case vkCharacter::eASCIIEncoding:
		{
			return _FindASCII(iChar, iStart, iEnd);
		}

		case vkCharacter::eUTF8Encoding:
		{
			return _FindUTF8(iChar, iStart, iEnd);
		}

		default:
		{
			return _FindGeneric(iChar, iStart, iEnd);
		}
	}
}


VK_INLINE char8*
vkString::_FindLast(const vkCharacter& iChar, const char8* iStart, const char8* iEnd) const
{
	switch(GetEncoding())
	{
		case vkCharacter::eASCIIEncoding:
		{
			return _FindLastASCII(iChar, iStart, iEnd);
		}

		case vkCharacter::eUTF8Encoding:
		{
			return _FindLastUTF8(iChar, iStart, iEnd);
		}

		default:
		{
			return _FindLastGeneric(iChar, iStart, iEnd);
		}
	}
}

VK_INLINE char8*
vkString::_Find(const vkString& iOther, const char8* iStart, const char8* iEnd) const
{
	switch(GetEncoding())
	{
		default:
		case vkCharacter::eASCIIEncoding:
		{
			return _FindASCII(iOther, iStart, iEnd);
		}

		case vkCharacter::eUTF8Encoding:
		{
			return _FindUTF8(iOther, iStart, iEnd);
		}

		case vkCharacter::eUTF16Encoding:
		{
			return _FindUTF16(iOther, iStart, iEnd);
		}

		case vkCharacter::eUTF32Encoding:
		{
			return _FindUTF32(iOther, iStart, iEnd);
		}
	}
}

VK_INLINE char8*
vkString::_FindLast(const vkString& iOther, const char8* iStart, const char8* iEnd) const
{
	switch(GetEncoding())
	{
		default:
		case vkCharacter::eASCIIEncoding:
		{
			return _FindLastASCII(iOther, iStart, iEnd);
		}

		case vkCharacter::eUTF8Encoding:
		{
			return _FindLastUTF8(iOther, iStart, iEnd);
		}

		case vkCharacter::eUTF16Encoding:
		{
			return _FindLastUTF16(iOther, iStart, iEnd);
		}

		case vkCharacter::eUTF32Encoding:
		{
			return _FindLastUTF32(iOther, iStart, iEnd);
		}
	}
}

VK_INLINE vkString::ConstIterator
vkString::IFind(const vkCharacter& iChar) const
{
	return IFind(iChar, Begin(), End());
}

VK_INLINE vkString::ConstIterator
vkString::IFind(const vkCharacter& iChar, const ConstIterator& iStart) const
{
	return IFind(iChar, iStart, End());
}

VK_INLINE vkString::ConstIterator
vkString::IFind(const vkString& iOther) const
{
	return IFind(iOther, Begin(), End());
}

VK_INLINE vkString::ConstIterator
vkString::IFind(const vkString& iOther, const ConstIterator& iStart) const
{
	return IFind(iOther, iStart, End());
}

VK_INLINE vkString::ConstIterator
vkString::FindLast(const vkCharacter& iChar) const
{
	return ConstIterator(this, _FindLast(iChar, m_Chars, _GetEndChars()));
}

VK_INLINE vkString::ConstIterator
vkString::FindLast(const vkCharacter& iChar, const ConstIterator& iStart) const
{
	VKASSERT(iStart.IsValid(*this));
	return ConstIterator(this, _FindLast(iChar, iStart.m_Current, _GetEndChars()));
}

VK_INLINE vkString::ConstIterator
vkString::FindLast(const vkCharacter& iChar, const ConstIterator& iStart, const ConstIterator& iEnd) const
{
	VKASSERT(iStart.IsValid(*this));
	VKASSERT(iEnd.IsValid(*this));
	return ConstIterator(this, _FindLast(iChar, iStart.m_Current, iEnd.m_Current));
}

VK_INLINE vkString::ConstIterator
vkString::FindLast(const vkString& iOther) const
{
	return ConstIterator(this, _FindLast(iOther, m_Chars, _GetEndChars()));
}

VK_INLINE vkString::ConstIterator
vkString::FindLast(const vkString& iOther, const ConstIterator& iStart) const
{
	VKASSERT(iStart.IsValid(*this));
	return ConstIterator(this, _FindLast(iOther, iStart.m_Current, _GetEndChars()));
}

VK_INLINE vkString::ConstIterator
vkString::FindLast(const vkString& iOther, const ConstIterator& iStart, const ConstIterator& iEnd) const
{
	VKASSERT(iStart.IsValid(*this));
	VKASSERT(iEnd.IsValid(*this));
	return ConstIterator(this, _FindLast(iOther, iStart.m_Current, iEnd.m_Current));
}

VK_INLINE vkString::ConstIterator
vkString::IFindLast(const vkCharacter& iChar) const
{
	return IFindLast(iChar, Begin(), End());
}

VK_INLINE vkString::ConstIterator
vkString::IFindLast(const vkCharacter& iChar, const ConstIterator& iStart) const
{
	return IFindLast(iChar, iStart, End());
}

VK_INLINE vkString::ConstIterator
vkString::IFindLast(const vkString& iOther) const
{
	return IFindLast(iOther, Begin(), End());
}

VK_INLINE vkString::ConstIterator
vkString::IFindLast(const vkString& iOther, const ConstIterator& iStart) const
{
	return IFindLast(iOther, iStart, End());
}

VK_INLINE bool
vkString::Contains(const vkCharacter& iChar) const
{
	const char8* endChars = _GetEndChars();
	return _Find(iChar, m_Chars, endChars) != endChars;
}

VK_INLINE bool
vkString::Contains(const vkCharacter& iChar, const ConstIterator& iThisStart, const ConstIterator& iThisEnd) const
{
	VKASSERT(iThisStart.IsValid(*this));
	VKASSERT(iThisEnd.IsValid(*this));
	return _Find(iChar, iThisStart.m_Current, iThisEnd.m_Current) != _GetEndChars();
}

VK_INLINE bool
vkString::Contains(const vkString& iOther) const
{
	const char8* endChars = _GetEndChars();
	return _Find(iOther, m_Chars, endChars) != endChars;
}

VK_INLINE bool
vkString::Contains(const vkString& iOther, const ConstIterator& iThisStart, const ConstIterator& iThisEnd) const
{
	VKASSERT(iThisStart.IsValid(*this));
	VKASSERT(iThisEnd.IsValid(*this));
	return _Find(iOther, iThisStart.m_Current, iThisEnd.m_Current) != _GetEndChars();
}

VK_INLINE bool
vkString::IContains(const vkCharacter& iChar) const
{
	return IContains(iChar, Begin(), End());
}

VK_INLINE bool
vkString::IContains(const vkString& iOther) const
{
	return IContains(iOther, Begin(), End());
}

VK_INLINE vkString&
vkString::Crop(const ConstIterator& iStart)
{
	return Crop(iStart, End());
}

VK_INLINE vkString&
vkString::Cut(const ConstIterator& iStart)
{
	return Cut(iStart, End());
}

VK_INLINE uint32
vkString::Replace(const vkCharacter& iOld, const vkCharacter& iNew)
{
	return Replace(iOld, iNew, Begin(), End());
}

VK_INLINE uint32
vkString::Replace(const vkCharacter& iCharacterToReplace, const vkCharacter& iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd)
{
	switch(GetEncoding())
	{
		default:
		case vkCharacter::eASCIIEncoding : return _ReplaceASCII(iCharacterToReplace, iNewValue, iStart, iEnd);
		case vkCharacter::eUTF8Encoding : return _ReplaceUTF8(iCharacterToReplace, iNewValue, iStart, iEnd);
		case vkCharacter::eUTF16Encoding : return _ReplaceUTF16(iCharacterToReplace, iNewValue, iStart, iEnd);
		case vkCharacter::eUTF32Encoding : return _ReplaceUTF32(iCharacterToReplace, iNewValue, iStart, iEnd);
	}
}

VK_INLINE uint32
vkString::Replace(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue, const ConstIterator& iStart, const ConstIterator& iEnd)
{
	switch(GetEncoding())
	{
	default:
	case vkCharacter::eASCIIEncoding :
	case vkCharacter::eUTF8Encoding : return _ReplaceASCII(iCharactersToReplace, iCount, iNewValue, iStart, iEnd);
	case vkCharacter::eUTF16Encoding : return _ReplaceUTF16(iCharactersToReplace, iCount, iNewValue, iStart, iEnd);
	case vkCharacter::eUTF32Encoding : return _ReplaceUTF32(iCharactersToReplace, iCount, iNewValue, iStart, iEnd);
	}
}

VK_INLINE uint32
vkString::Replace(const char8* iCharactersToReplace, uint32 iCount, char8 iNewValue)
{
	return Replace(iCharactersToReplace, iCount, iNewValue, Begin(), End());
}

VK_INLINE uint32
vkString::Replace(const vkString& iOld, const vkString& iNew)
{
	TFindFunction fct = &vkString::Find;
	return _Replace(iOld, iNew, Begin(), End(), fct);
}

VK_INLINE uint32
vkString::Replace(const vkString& iOld, const vkString& iNew, const ConstIterator& iStart, const ConstIterator& iEnd)
{
	TFindFunction fct = &vkString::Find;
	return _Replace(iOld, iNew, iStart, iEnd, fct);
}

VK_INLINE uint32
vkString::IReplace(const vkCharacter& iOld, const vkCharacter& iNew)
{
	return IReplace(iOld, iNew, Begin(), End());
}

VK_INLINE uint32
vkString::IReplace(const vkString& iOld, const vkString& iNew)
{
	TFindFunction fct = &vkString::IFind;
	return _Replace(iOld, iNew, Begin(), End(), fct);
}

VK_INLINE uint32
vkString::IReplace(const vkString& iOld, const vkString& iNew, const ConstIterator& iStart, const ConstIterator& iEnd)
{
	TFindFunction fct = &vkString::IFind;
	return _Replace(iOld, iNew, iStart, iEnd, fct);
}

VK_INLINE void
vkString::Insert(const ConstIterator& iPos, const vkString& iOther)
{
	Insert(iPos, iOther, iOther.Begin(), iOther.End());
}

VK_INLINE void
vkString::Insert(const ConstIterator& iPos, const vkString& iOther, const ConstIterator& iStart)
{
	Insert(iPos, iOther, iStart, iOther.End());
}

VK_INLINE const vkStrMethods*
vkString::GetMethods() const
{
	return s_Methods[GetEncoding()];
}

VK_INLINE const vkStrMethods*
vkString::GetMethods(const vkCharacter::EEncoding iEncoding)
{
	return s_Methods[iEncoding];
}

VK_INLINE bool
vkString::IsUnique() const
{
	return _IsBufferEditable();
}

VK_INLINE bool
vkString::_IsBufferEditable() const
{
	return !(IsStatic() || _GetRefCount() > 1);
}

VK_INLINE
void
vkString::From(const int8 iValue)
{
	Empty();
	*this << int32(iValue);
}

VK_INLINE
void
vkString::From(const uint8 iValue)
{
	Empty();
	*this << uint32(iValue);
}

VK_INLINE
void
vkString::From(const int16 iValue)
{
	Empty();
	*this << int32(iValue);
}

VK_INLINE
void
vkString::From(const uint16 iValue)
{
	Empty();
	*this << uint32(iValue);
}

VK_INLINE
void
vkString::From(const int32 iValue)
{
	Empty();
	*this << iValue;
}

VK_INLINE
void
vkString::From(const uint32 iValue)
{
	Empty();
	*this << iValue;
}

VK_INLINE
void
vkString::From(const int64 iValue)
{
	Empty();
	*this << iValue;
}

VK_INLINE
void
vkString::From(const uint64 iValue)
{
	Empty();
	*this << iValue;
}

VK_INLINE
void
vkString::From(const float iValue)
{
	Empty();
	*this << iValue;
}

VK_INLINE
void
vkString::From(const double iValue)
{
	Empty();
	*this << iValue;
}

VK_INLINE
void
vkString::From(const vkFourCC& iValue)
{
	Empty();
	*this << iValue;
}

VK_INLINE
void
vkString::From(const bool iValue)
{
	Empty();
	*this << iValue;
}

VK_INLINE
void
vkString::From(const void* iPointer)
{
	Empty();
	*this << iPointer;
}

#if defined(VK_TARGET_MACOSX)
VK_INLINE
void
vkString::From(const long int iNumber)
{
    Empty();
    *this<< *(int64*)iNumber;
}

VK_INLINE
void
vkString::From(const unsigned long int iNumber)
{
    Empty();
    *this<< *(uint64*)iNumber;
}
#endif

VK_INLINE
uint32
vkString::ByteLength() const
{
	return Size() - UnitSize();
}

//////////////////////////////////////////////////////////////////////////

VK_INLINE bool
vkMatch::operator()(const vkString& iT1,const vkString& iT2) const
{
	return iT1.Match(iT2);
}

VK_INLINE bool
vkIMatch::operator()(const vkString& iT1,const vkString& iT2) const
{
	return iT1.IMatch(iT2);
}

//////////////////////////////////////////////////////////////////////////



