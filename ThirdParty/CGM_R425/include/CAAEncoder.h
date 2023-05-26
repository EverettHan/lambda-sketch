#ifndef CAAENCODER_INCLUDE
#define CAAENCODER_INCLUDE

// Copyright DASSAULT SYSTEMES 2001
//-----------------------------------------------------------------------------

#include <stdio.h>

class CAAEncoder {

public:

    typedef unsigned int  uint32;
    typedef unsigned char uint8;

    typedef enum {
        success = 0,
        invalidLength = -1,
        invalidInput = -2,
        invalidVersion = -3
    } Status;

    typedef struct {
        uint32 targetType; 
        uint32 targetId;
        uint32 licType;
        uint32 productId;
        uint32 expDate;
        uint32 timeStamp;
    } LicInfo;

    CAAEncoder ();
    ~CAAEncoder ();

    const char *Encode (const LicInfo& lic);
    int         Decode (const char *buffer, LicInfo *lic = NULL);

private:

    int  BinToString (char *buffer, int bufsiz, const uint8 *ptr, int size);
    int  StringToBin (uint8 *ptr, int size, const char *buffer);
    void Scramble (const uint8 *seed, int seedsize, uint8 *ptr, int size);
    void BitCopy (uint8*& dst, const void *src, int size, int big2l);
    void BitCopy1 (uint8*& src, void *dst, int size, int big2l);
};

#endif
