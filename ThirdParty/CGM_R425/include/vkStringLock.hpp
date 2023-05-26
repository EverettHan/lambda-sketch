/**
@file

A set of classes to access internal data on a string.

@COPYRIGHT

@author Gerald Guyomard

*/

// Inlined implementatiosn
VK_INLINE vkCharacter::EEncoding
vkStringLockParams::GetEncoding() const
{
	return (vkCharacter::EEncoding) m_Encoding;
}

VK_INLINE const char8*
vkStringLockParams::GetChars() const
{
	return m_LockedChars;
}

VK_INLINE bool
vkStringLockParams::IsBufferCopied() const
{
	return m_IsBufferCopied != 0;
}

VK_INLINE uint32
vkStringLockParams::Size() const
{
	return m_LockedSize;
}

VK_INLINE
vkStringLock::vkStringLock(const vkString& iString, const vkCharacter::EEncoding iEncoding)
:  m_String(iString), m_LockParams(iEncoding)
{
	m_String.Lock(m_LockParams);
}

VK_INLINE
vkStringLock::vkStringLock(const vkString& iString, const vkCharacter::EEncoding iEncoding, const vkString::ConstIterator& iStart)
: m_String(iString), m_LockParams(iEncoding)
{
	m_String.Lock(m_LockParams, m_String.Begin() + iStart.GetCharacterPosition());
}

VK_INLINE
vkStringLock::vkStringLock(const vkString& iString, const vkCharacter::EEncoding iEncoding, const vkString::ConstIterator& iStart, const vkString::ConstIterator& iEnd)
: m_String(iString), m_LockParams(iEncoding)
{
	m_String.Lock(m_LockParams, m_String.Begin() + iStart.GetCharacterPosition(), m_String.Begin() + iEnd.GetCharacterPosition());
}

VK_INLINE
vkStringLock::vkStringLock(const vkString& iString, const size_t iUnitSize)
: m_String(iString), m_LockParams(vkCharacter::GetDefaultEncoding((uint32) iUnitSize))
{
	m_String.Lock(m_LockParams);
}

VK_INLINE bool
vkStringLock::IsBufferCopied() const
{
	return m_LockParams.IsBufferCopied();
}

VK_INLINE
vkStringLock::~vkStringLock()
{
	m_String.Unlock(m_LockParams);
}

VK_INLINE
const char8*
vkStringLock::GetChars() const
{
	return m_LockParams.GetChars();
}

VK_INLINE
uint32
vkStringLock::Size() const
{
	return m_LockParams.Size();
}

VK_INLINE
uint32
vkStringLock::ByteLength() const
{
	return m_LockParams.Size() - vkCharacter::s_UnitSizes[m_LockParams.GetEncoding()];
}

VK_INLINE
uint32
vkStringLock::UnitLength() const
{
	const uint32 unitSize	= vkCharacter::s_UnitSizes[m_LockParams.GetEncoding()];
	VKASSERT((m_LockParams.Size() % unitSize) == 0); // "sizeInBytes % unitSize != 0"
	return (m_LockParams.Size() / unitSize) - 1;
}

VK_INLINE
const char8*
vkStringLock::CStr() const
{
	// (eASCIIEncoding or eUTF8Encoding)
	const vkCharacter::EEncoding encoding = m_LockParams.GetEncoding();
	return (encoding == vkCharacter::eASCIIEncoding) || (encoding == vkCharacter::eUTF8Encoding) ? (const char8*) m_LockParams.GetChars() : 0;
}

VK_INLINE
const char8*
vkStringLock::ASCIICStr() const
{
	return (m_LockParams.GetEncoding() == vkCharacter::eASCIIEncoding) ? (const char8*) m_LockParams.GetChars() : 0;
}

VK_INLINE
const char8*
vkStringLock::UTF8CStr() const
{
	return (m_LockParams.GetEncoding() == vkCharacter::eUTF8Encoding) ? (const char8*) m_LockParams.GetChars() : 0;
}

VK_INLINE
const char16*
vkStringLock::UTF16CStr() const
{
	return (m_LockParams.GetEncoding() == vkCharacter::eUTF16Encoding) ? (const char16*) m_LockParams.GetChars() : 0;
}

VK_INLINE
const char32*
vkStringLock::UTF32CStr() const
{
	return (m_LockParams.GetEncoding() == vkCharacter::eUTF32Encoding) ? (const char32*) m_LockParams.GetChars() : 0;
}

VK_INLINE vkASCIILock::vkASCIILock(const vkString& iString):vkStringLock(iString, vkCharacter::eASCIIEncoding)
{}

VK_INLINE const char8*	
vkASCIILock::CStr() const
{
	return (const char8*)m_LockParams.GetChars();
}

VK_INLINE vkUTF8Lock::vkUTF8Lock(const vkString& iString):vkStringLock(iString, vkCharacter::eUTF8Encoding)
{}

VK_INLINE const char8*	
vkUTF8Lock::CStr() const
{
	return (const char8*)m_LockParams.GetChars();
}

VK_INLINE vkUTF16Lock::vkUTF16Lock(const vkString& iString):vkStringLock(iString, vkCharacter::eUTF16Encoding)
{}

VK_INLINE const char16*	
vkUTF16Lock::CStr() const
{
	return (const char16*)m_LockParams.GetChars();
}

VK_INLINE vkUTF32Lock::vkUTF32Lock(const vkString& iString):vkStringLock(iString, vkCharacter::eUTF32Encoding)
{}

VK_INLINE const char32*	
vkUTF32Lock::CStr() const
{
	return (const char32*)m_LockParams.GetChars();
}

VK_INLINE vkWideCharLock::vkWideCharLock(const vkString& iString):vkStringLock(iString, vkCharacter::eWideCharEncoding)
{}

VK_INLINE const wchar_t*	
vkWideCharLock::CStr() const
{
	return (const wchar_t*) m_LockParams.GetChars();
}



