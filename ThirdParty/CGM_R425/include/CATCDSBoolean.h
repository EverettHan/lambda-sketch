#ifndef CATCDSBoolean_H
#define CATCDSBoolean_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

/**
 * Definition of a boolean type.
 */

typedef unsigned char CATCDSBoolean;

#ifndef FALSE
static const CATCDSBoolean FALSE = 0;
#define FALSE FALSE
#endif

#ifndef TRUE
static const CATCDSBoolean TRUE = 1;
#define TRUE TRUE
#endif

#endif
