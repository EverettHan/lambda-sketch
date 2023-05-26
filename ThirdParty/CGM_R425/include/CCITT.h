#ifndef CCITT_H
#define CCITT_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//
// PURPOSE: Support for bilevel bitmaps internal storage.
//
// Encoding scheme is CCITT Group 3 1-Dimensional no-EOLs Huffman RLE.
//

#include "CATDataType.h"
//#include "CATVisFoundation.h"
#include "CATMMediaPixelImage.h"

typedef unsigned char uchar;
typedef unsigned int uint;
#ifdef PLATEFORME_DS64
typedef CATULONG32 ccitt_ulong;
#else
typedef unsigned long ulong;
typedef ulong ccitt_ulong;
#endif

template<class T> class vector;


//class ExportedByCATVisFoundation CCITT {
class ExportedByCATMMediaPixelImage CCITT {

public:

    // --- ENCODING METHODS ---
    // The input data is assumed to be uncompressed, 8 pixels per byte,
    // photometric interpretation should be 'white is 0, black is 1'
    // Parameter 'raw_length' is the number of pixels in raw_data.
    // Returns the size in bytes of the CCITT data.
    static uint encode(uchar*& ccitt_data, const uchar* raw_data, uint raw_length);
    static uint encode(uchar*& ccitt_data, const vector<uint>& runs);
    // Input data should be uncompressed, 1 pixel per byte.
    // photometric interpretation should be 'black is 0, white is 255'
    static uint encode_from_grey(uchar*& ccitt_data, const uchar* raw_data, uint raw_length);

    // --- LOW LEVEL ENCODING METHODS ---
    static uint find_zero_run(const uchar* bp, uint bit_start, uint bit_end);
    static uint find_one_run(const uchar* bp, uint bit_start, uint bit_end);

    // --- DECODING STATES ---
    // These methods must be called before and after any decoding operation.
    static void build_decoding_states();
    static void destroy_decoding_states();

    // --- DECODING METHODS ---
    // Output is 'white is 0, black is 1'
    // Parameter 'ccitt_length' is the size in bytes of the CCITT data.
    // Parameter 'raw_length' is the number of pixels in raw_data
    // Parameter 'raw_data' must be allocated to at least (raw_length+7)/8 bytes and initialized with 0s.
    static void decode(uchar* raw_data, const uchar* ccitt_data, uint ccitt_length, uint raw_length);
    static vector<uint> decode(const uchar* ccitt_data, uint ccitt_length, uint raw_length);

    // --- LOW LEVEL DECODING METHODS ---
    // See below for a decoding example.
    inline static uint find_white_run(const uchar* ccitt_data, const uchar* ccitt_end, uint* bit_pos);
    inline static uint find_black_run(const uchar* ccitt_data, const uchar* ccitt_end, uint* bit_pos);

private:

    struct ccitt_code {
        uint length;    // code length
        uint value;     // code value
        uint run;       // encoded run length
    };

    static const ccitt_code _terminating_white[64];
    static const ccitt_code _make_up_white[40];
    static const ccitt_code _terminating_black[64];
    static const ccitt_code _make_up_black[40];

    static int _states_instances;
    static const ccitt_code **_white_states;
    static const ccitt_code **_black_states;

    static uint push_white_codes(uint run, vector<const ccitt_code*>& codes);
    static uint push_black_codes(uint run, vector<const ccitt_code*>& codes);
    static uint build_ccitt_data(const vector<const ccitt_code*>& codes, uint nbits,
                                 uchar*& ccitt_data);

    inline static uint get_bits(const uchar* bp, const uchar* bpend, uint bit_pos, uint nbits);
    static void add_node(const ccitt_code* code, uint max_code_length, const ccitt_code** tree);

    // useless default methods intentionally not accessible (and not generated):
    CCITT();
    CCITT(const CCITT&);
    ~CCITT();
    CCITT& operator=(const CCITT&);
    CCITT* operator&();
    const CCITT* operator&() const;
};


///////////////////////////////////////////////////////////////////////////////

inline uint CCITT::get_bits(const uchar* bp, const uchar* bpend, uint bit_pos, uint nbits)
{
    bp += bit_pos >> 3;
    uint v = uint(*bp) << (8*sizeof(uint)-8);
    if (++bp != bpend) {
        v |= uint(*bp) << (8*sizeof(uint)-16);
        if (++bp != bpend) {
            v |= uint(*bp) << (8*sizeof(uint)-24);
        }
    }
    // Reading the 4th byte is useless since 13 bits (max. CCITT code length)
    // overlap at most 3 bytes.
    v <<= bit_pos & 7;              // get rid of leading bits.
    v >>= 8*sizeof(uint) - nbits;   // make these nbits an uint.
    return v;
}


inline uint CCITT::find_white_run(const uchar* ccitt_data, const uchar* ccitt_end, uint* bit_pos)
{
    const ccitt_code* code;
    uint run = 0;

    do {
        uint v = get_bits(ccitt_data, ccitt_end, *bit_pos, 12);
        code = _white_states[v];
        *bit_pos += code->length;
        run += code->run;
    } while (code->run >= 64);  // until we reach the terminating code.

    return run;
}


inline uint CCITT::find_black_run(const uchar* ccitt_data, const uchar* ccitt_end, uint* bit_pos)
{
    const ccitt_code* code;
    uint run = 0;

    do {
        uint v = get_bits(ccitt_data, ccitt_end, *bit_pos, 13);
        code = _black_states[v];
        *bit_pos += code->length;
        run += code->run;
    } while (code->run >= 64);  // until we reach the terminating code.

    return run;
}


///////////////////////////////////////////////////////////////////////////////
//
// Decoding example:
//
/*
    {
        CCITT::build_decoding_states();

        for (size_t i = 0; i < height; ++i) {

            uint run, total_count = 0, bit_pos = 0;
            const uchar* ccitt_data = ccitt_row[i];
            const uchar* ccitt_end = ccitt_data + ccitt_length[i];

            for (;;) {

                run = CCITT::find_white_run(ccitt_data, ccitt_end, &bit_pos);
                // ...
                total_count += run;
                if (total_count == width)
                    break;

                run = CCITT::find_black_run(ccitt_data, ccitt_end, &bit_pos);
                // ...
                total_count += run;
                if (total_count == width)
                    break;
            }
        }

        CCITT::destroy_decoding_states();
    }
*/


///////////////////////////////////////////////////////////////////////////////
// Converts uncompressed bilevel data from/to BlackIsZero/WhiteIsZero
// Fill bits are always set to zero.

inline void InvertPhoto(uchar* bp, uint nbits)
{
    // align to an ulong boundary...
//  while ((CATULONGPTR(bp) & (sizeof(ccitt_ulong)-1)) && nbits >= 8) { // i.e. ulong(bp) % sizeof(ulong) && ...
    while ((CATPtrToULONG32(bp) & (sizeof(ccitt_ulong)-1)) && nbits >= 8) { // i.e. ulong(bp) % sizeof(ulong) && ...
        *bp = ~*bp;
        ++bp;
        nbits -= 8;
    }

    // ... and run through ulongs
    ccitt_ulong* lp = (ccitt_ulong*)bp; // reinterpret_cast<>()
    while (nbits >= 8*sizeof(ccitt_ulong)) {
        *lp = ~*lp;
        ++lp;
        nbits -= 8*sizeof(ccitt_ulong);
    }
    bp = (uchar*)lp;    // reinterpret_cast<>()

    // invert remaining bytes
    while (nbits >= 8) {
        *bp = ~*bp;
        ++bp;
        nbits -= 8;
    }

    // invert final bits
    if (nbits > 0) {
        *bp = ~*bp;
        *bp &= 0xFF00 >> nbits;
    }
}


#endif // CCITT_H
