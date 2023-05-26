/**
@file

Wrapping of standard stdio/stdlib tools.

@COPYRIGHT

@author Aymeric Bard
*/

VK_INLINE char8
vkToLower(const char8 iCharacter)
{
	VKASSERT(iCharacter >= 0);
	return ((iCharacter >= 'A') && (iCharacter <= 'Z')) ? (iCharacter | 32) : iCharacter;
}

VK_INLINE char8
vkToUpper(const char8 iCharacter)
{
	VKASSERT(iCharacter >= 0);
	return ((iCharacter >= 'a') && (iCharacter <= 'z')) ? (iCharacter & ~32) : iCharacter;
}



