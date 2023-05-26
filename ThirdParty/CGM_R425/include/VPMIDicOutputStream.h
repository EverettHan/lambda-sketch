//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicOutputStream_h
#define VPMIDicOutputStream_h

class CATUnicodeString;
#include "VPMIDicInterfaces.h"

class ExportedByVPMIDicInterfaces VPMIDicOutputStream
{
        VPMIDicOutputStream(const VPMIDicOutputStream&);
        VPMIDicOutputStream& operator=(const VPMIDicOutputStream&);

    public:
                     VPMIDicOutputStream  ();
        virtual      ~VPMIDicOutputStream () = 0;


        /**
        * Write a string into the stream (append).
        * @param iPartialStream the string to be written at the end of the stream
        */
        virtual void Write ( const CATUnicodeString & iPartialStream ) = 0;


        /**
        * Close the stream.
        */
        virtual void Close () = 0;
};

#endif




