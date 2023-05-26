#ifndef CATTosDumpOptions_H
#define CATTosDumpOptions_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Private
 * @usage U3
 */

 /**
 * Definition of dump display options.
 *
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATTosDumpOptions_NONE</tt>            <dd>Empty dump.
 * @param <tt>CATTosDumpOptions_ALL</tt>             <dd>All options.
 * @param <tt>CATTosDumpOptions_SPACES</tt>          <dd>Dump with spaces, components, Relations, Bags.
 * @param <tt>CATTosDumpOptions_CONCURRENCIES</tt>   <dd>Concurrencies informations.
 * @param <tt>CATTosDumpOptions_VERSIONING</tt>      <dd>versioning informations.
 * @param <tt>CATTosDumpOptions_STATISTICS</tt>      <dd>Statistics informations.
 * </dl>
 */
typedef unsigned int CATTosDumpOptions;

#define CATTosDumpOptions_NONE                       0x00000000
#define CATTosDumpOptions_ALL                        0xFFFFFFFF
#define CATTosDumpOptions_SPACES                     0x00000001
#define CATTosDumpOptions_CONCURRENCIES              0x00000002
#define CATTosDumpOptions_STATISTICS                 0x00000004
#define CATTosDumpOptions_VERSIONS                   0x00000008
#define CATTosDumpOptions_ATTRIBUTES                 0x00000010
#define CATTosDumpOptions_REPOSITORIES               0x00000020

#endif



