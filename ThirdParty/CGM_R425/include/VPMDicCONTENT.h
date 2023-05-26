//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMDicCONTENT_h
#define _VPMDicCONTENT_h

#include "VPMIDicInterfaces.h"

/**
 * ENOVIA Dictionary file extensions.
 * @param VPMDicMETADATA
 *   The Dictionary file contains Metadata descriptions
 */

//-- [chd:27.05.2014] nettoyage: il ne reste plus que .metadata comme extension de fichier valide (exit tuning, securable, rbodef, rbomap) 
enum VPMDicCONTENT
    { VPMDicMETADATA  = 0
    };

static const int _ContentLabelSize = 1;
static const char * _ContentLabel[] =
    { "metadata"
    };

#endif
