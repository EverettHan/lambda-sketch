/**
@file

This file defines the string iterator.

@COPYRIGHT

@author Edwin, Gerald Guyomard
*/

#if !defined(vkStringIterator_hpp)
#define vkStringIterator_hpp

VK_INLINE vkString::ConstIterator::ConstIterator() :
m_String(0),
m_Current(0)
{
}

VK_INLINE vkString::ConstIterator::ConstIterator(const ConstIterator& iOther) :
m_String((vkString*)iOther.m_String),
m_Current(iOther.m_Current)
{
}

VK_INLINE vkString::ConstIterator::ConstIterator(const vkString& iString, const uint32 iLogicPos)
{
	*this = iString.GetIterator(iLogicPos);
}

VK_INLINE vkString::ConstIterator::ConstIterator(const vkString* iString, char8* iCurrent) :
m_String((vkString*)iString),
m_Current(iCurrent)
{
}

VK_INLINE vkString::ConstIterator&
vkString::ConstIterator::operator=(const ConstIterator& iOther)
{
	m_String = (vkString*)iOther.m_String;
	m_Current = iOther.m_Current;
	return *this;
}

VK_INLINE bool
vkString::ConstIterator::operator==(const ConstIterator& iOther) const
{
	return m_Current == iOther.m_Current;
}

VK_INLINE bool
vkString::ConstIterator::operator!=(const ConstIterator& iOther) const
{
	return m_Current != iOther.m_Current;
}

VK_INLINE bool
vkString::ConstIterator::operator<(const ConstIterator& iOther) const
{
	VKASSERT(m_String == iOther.m_String); // "strings are not the same"
	return m_Current < iOther.m_Current;
}

VK_INLINE bool
vkString::ConstIterator::operator<=(const ConstIterator& iOther) const
{
	VKASSERT(m_String == iOther.m_String); // "strings are not the same"
	return m_Current <= iOther.m_Current;
}

VK_INLINE bool
vkString::ConstIterator::operator>(const ConstIterator& iOther) const
{
	VKASSERT(m_String == iOther.m_String); // "strings are not the same"
	return m_Current > iOther.m_Current;
}

VK_INLINE bool
vkString::ConstIterator::operator>=(const ConstIterator& iOther) const
{
	VKASSERT(m_String == iOther.m_String); // "strings are not the same"
	return m_Current >= iOther.m_Current;
}

VK_INLINE const vkString*
vkString::ConstIterator::GetString() const
{
	return m_String;
}

VK_INLINE vkString*
vkString::Iterator::GetString()
{
	return m_String;
}

VK_INLINE const char8*
vkString::ConstIterator::GetCharAddress() const
{
	return m_Current;
}

VK_INLINE uint32
vkString::ConstIterator::GetBytePosition() const
{
	return (uint32)VK_POINTER_TO_PTRDIFF(m_Current - m_String->m_Chars);
}

VK_INLINE vkCharacter
vkString::ConstIterator::GetCharacter() const
{
	char32 c32 = 0;
	if (m_Current)
	{
		c32 = m_String->GetMethods()->GetUTF32Char(m_Current);
	}
	return vkCharacter(c32);
}

VK_INLINE uint32
vkString::ConstIterator::GetCharacterPosition() const
{
	return *this-m_String->Begin();
}

VK_INLINE bool
vkString::ConstIterator::IsValid(const vkString& iString) const
{
	return m_String == &iString;
}

VK_INLINE vkString::Iterator::Iterator() :
ConstIterator()
{
}

VK_INLINE vkString::Iterator::Iterator(const Iterator& iOther) :
ConstIterator(iOther)
{
}

VK_INLINE vkString::Iterator::Iterator(const ConstIterator& iOther) :
ConstIterator(iOther)
{
}

VK_INLINE vkString::Iterator::Iterator(vkString& iString, const uint32 iLogicPos) :
ConstIterator(iString, iLogicPos)
{
}

VK_INLINE vkString::Iterator::Iterator(const vkString* iString, char8* iCurrent) :
ConstIterator(iString, iCurrent)
{
}

VK_INLINE vkString::Iterator&
vkString::Iterator::operator=(const Iterator& iOther)
{
	ConstIterator::operator=(iOther);
	return *this;
}

VK_INLINE vkCharacter
vkString::ConstIterator::operator*() const
{
	VKASSERT(m_Current); // "The iterator is null"
	VKASSERT(m_String); // "The string is null"
	return vkCharacter(m_String->GetMethods()->GetUTF32Char(m_Current));
}

VK_INLINE vkString::ConstIterator&
vkString::ConstIterator::operator++()
{
	if (uint32 charSize = m_String->m_.constantCharSize)
	{
		VKASSERT(charSize == m_String->UnitSize());
		m_Current += charSize;
	}
	else
	{
		m_Current += m_String->GetMethods()->GetCharSize(m_Current);
	}	
	return *this;
}

VK_INLINE vkString::ConstIterator
vkString::ConstIterator::operator++(int)
{
	ConstIterator it(*this);

	if (uint32 charSize = m_String->m_.constantCharSize)
	{
		VKASSERT(charSize == m_String->UnitSize());
		m_Current += charSize;
	}
	else
	{
		m_Current += m_String->GetMethods()->GetCharSize(m_Current);
	}

	return it;
}

VK_INLINE vkString::ConstIterator&
vkString::ConstIterator::operator--()
{
	if (uint32 charSize = m_String->m_.constantCharSize)
	{
		VKASSERT(charSize == m_String->UnitSize());
		m_Current -= charSize;
	}
	else
	{
		m_Current -= m_String->GetMethods()->GetPreviousCharSize(m_Current);
	}

	return *this;
}

VK_INLINE vkString::ConstIterator
vkString::ConstIterator::operator--(int)
{
	ConstIterator it(*this);
	if (uint32 charSize = m_String->m_.constantCharSize)
	{
		VKASSERT(charSize == m_String->UnitSize());
		m_Current -= charSize;
	}
	else
	{
		m_Current -= m_String->GetMethods()->GetPreviousCharSize(m_Current);
	}

	return it;
}

VK_INLINE vkString::ConstIterator&
vkString::ConstIterator::operator+=(const int32 iNbLogicalPos)
{
	VKASSERT(m_String); // "string is null"
	if (uint32 charSize = m_String->m_.constantCharSize)
	{
		VKASSERT(charSize == m_String->UnitSize());
		// Direct offset
		m_Current += iNbLogicalPos * charSize;
	}
	else
	{
		m_Current = (char8*) m_String->GetMethods()->Advance(m_Current, iNbLogicalPos);
	}

	return *this;
}

VK_INLINE vkString::ConstIterator&
vkString::ConstIterator::operator-=(const int32 iNbLogicalPos)
{
	VKASSERT(m_String); // "string is null"
	if (uint32 charSize = m_String->m_.constantCharSize)
	{
		VKASSERT(charSize == m_String->UnitSize());
		// Direct offset
		m_Current -= iNbLogicalPos * charSize;
	}
	else
	{
		m_Current = (char8*) m_String->GetMethods()->Advance(m_Current, -iNbLogicalPos);
	}

	return *this;
}

VK_INLINE vkString::ConstIterator
vkString::ConstIterator::operator+(const int32 iNbLogicalPos) const
{
	ConstIterator it(*this);
	return it += iNbLogicalPos;
}

VK_INLINE vkString::ConstIterator
vkString::ConstIterator::operator-(const int32 iNbLogicalPos) const
{
	ConstIterator it(*this);
	return it -= iNbLogicalPos;
}

VK_INLINE char8*
vkString::ConstIterator::_GetCurrentChar() const
{
	return m_Current;
}

VK_INLINE vkString::Iterator&
vkString::Iterator::operator++()
{
	ConstIterator::operator++();
	return *this;
}

VK_INLINE vkString::Iterator
vkString::Iterator::operator++(int)
{
	Iterator it(*this);
	ConstIterator::operator++();
	return it;
}

VK_INLINE vkString::Iterator&
vkString::Iterator::operator--()
{
	ConstIterator::operator--();
	return *this;
}

VK_INLINE vkString::Iterator
vkString::Iterator::operator--(int)
{
	Iterator it(*this);
	ConstIterator::operator--();
	return it;
}

VK_INLINE vkString::Iterator&
vkString::Iterator::operator+=(const int32 iNbLogicalPos)
{
	ConstIterator::operator+=(iNbLogicalPos);
	return *this;
}

VK_INLINE vkString::Iterator&
vkString::Iterator::operator-=(const int32 iNbLogicalPos)
{
	ConstIterator::operator-=(iNbLogicalPos);
	return *this;
}

VK_INLINE vkString::Iterator
vkString::Iterator::operator+(const int32 iNbLogicalPos) const
{
	Iterator it(*this);
	return it += iNbLogicalPos;
}

VK_INLINE vkString::Iterator
vkString::Iterator::operator-(const int32 iNbLogicalPos) const
{
	Iterator it(*this);
	return it -= iNbLogicalPos;
}

VK_INLINE int32
vkString::Iterator::operator-(const Iterator& iOther) const
{
	return ConstIterator::operator-((ConstIterator&)iOther);
}

VK_INLINE void
vkString::Iterator::SetCharacter(const vkCharacter& iOther)
{
	// Just rebranch on the string's routine
	VKASSERT(m_String != 0); // "string referenced by iterator is null"
	m_String->SetCharacter(*this, iOther);
}

#endif // vkStringIterator_hpp


