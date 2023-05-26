//-*-C++-*-

#ifndef PLMIBaseWriter_H
#define PLMIBaseWriter_H

/**
  * @level Private
  * @Usage U6
  */

#include "CATBaseUnknown.h"

#include "PLMSCStreamerItf.h"  // NGS_SIMPLIFY_STREAMERS

class PLMIBaseWriter : public CATBaseUnknown
{
public:

  /**
   * Close the streamer.
   * This is the place to store any streamer-specific deallocation.
   */
  virtual void Close() =0;

};

#endif         // PLMIBaseWriter_H


