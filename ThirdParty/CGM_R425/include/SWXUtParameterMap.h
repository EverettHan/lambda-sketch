#ifndef SWXUtParameterMap_H
#define SWXUtParameterMap_H

#include "CATUnicodeString.h"
#include "SWXUtMap.h"
#include "SWXUtHashedUnicodeString.h"

class SWXUtPacketParameter;

class SWXUtParameterMap : public SWXUtMap<SWXUtHashedUnicodeString, SWXUtPacketParameter*, SWXUtHashedUnicodeString::SWXUtHashedUnicodeStringComparer>
{
public:
};

typedef SWXUtParameterMap::Iterator SWXUtParameterIterator_t;
typedef SWXUtParameterMap::ConstIterator SWXUtParameterConstIterator_t;

#endif
