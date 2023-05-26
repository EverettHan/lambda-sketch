#ifndef CATSYPEnumBitField_H
#define CATSYPEnumBitField_H

class CATSYPBitFieldElem
{
    int i;
public:
    inline CATSYPBitFieldElem(int i);
    inline operator int() const { return i; }
};
inline CATSYPBitFieldElem::CATSYPBitFieldElem(int ai) : i(ai) {}



template<typename Enum>
class CATSYPEnumBitField
{
    typedef void **Zero;
    int i;
public:
    typedef Enum enum_type;
    inline CATSYPEnumBitField(const CATSYPEnumBitField &f) : i(f.i) {}
    inline CATSYPEnumBitField(Enum f) : i(f) {}
    inline CATSYPEnumBitField(Zero = 0) : i(0) {}
    inline CATSYPEnumBitField(CATSYPBitFieldElem f) : i(f) {}

    inline CATSYPEnumBitField &operator=(const CATSYPEnumBitField &f) { i = f.i; return *this; }
    inline CATSYPEnumBitField &operator&=(int mask) {  i &= mask; return *this; }
    inline CATSYPEnumBitField &operator&=(unsigned int mask) {  i &= mask; return *this; }
    inline CATSYPEnumBitField &operator|=(CATSYPEnumBitField f) {  i |= f.i; return *this; }
    inline CATSYPEnumBitField &operator|=(Enum f) {  i |= f; return *this; }
    inline CATSYPEnumBitField &operator^=(CATSYPEnumBitField f) {  i ^= f.i; return *this; }
    inline CATSYPEnumBitField &operator^=(Enum f) {  i ^= f; return *this; }

    inline operator int() const { return i;}

    inline CATSYPEnumBitField operator|(CATSYPEnumBitField f) const { CATSYPEnumBitField g; g.i = i | f.i; return g; }
    inline CATSYPEnumBitField operator|(Enum f) const { CATSYPEnumBitField g; g.i = i | f; return g; }
    inline CATSYPEnumBitField operator^(CATSYPEnumBitField f) const { CATSYPEnumBitField g; g.i = i ^ f.i; return g; }
    inline CATSYPEnumBitField operator^(Enum f) const { CATSYPEnumBitField g; g.i = i ^ f; return g; }/*
    inline CATSYPEnumBitField operator&(int mask) const { CATSYPEnumBitField g; g.i = i & mask; return g; }
    inline CATSYPEnumBitField operator&(unsigned int mask) const { CATSYPEnumBitField g; g.i = i & mask; return g; }*/
    inline CATSYPEnumBitField operator&(Enum f) const { CATSYPEnumBitField g; g.i = i & f; return g; }
    inline CATSYPEnumBitField operator~() const { CATSYPEnumBitField g; g.i = ~i; return g; }

    inline bool operator!() const { return !i; }
};

#define CATSYP_DECLARE_ENUM_BIT_FIELD(BitField, Enum)\
typedef CATSYPEnumBitField<Enum> BitField;
#define CATSYP_DECLARE_OPERATORS_FOR_ENUM_BIT_FIELD(BitField) \
inline CATSYPEnumBitField<BitField::enum_type> operator|(BitField::enum_type f1, BitField::enum_type f2) \
{ return CATSYPEnumBitField<BitField::enum_type>(f1) | f2; } \
inline CATSYPEnumBitField<BitField::enum_type> operator|(BitField::enum_type f1, CATSYPEnumBitField<BitField::enum_type> f2) \
{ return f2 | f1; }

#endif

