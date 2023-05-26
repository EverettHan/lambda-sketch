
/**
 * @level Protected
 * @usage U1
 */

#ifndef CATOmyCioTypeOfCaches_H
#define CATOmyCioTypeOfCaches_H

/**
 * Type of CuteIO cache.<BR>
 * <UL>
 *    <LI>XM: eXtended Memory.</LI>
 *    <LI>SL: Selective Loading.</LI>
 *    <LI>PC: Persistent Cache.</LI>
 *    <LI>U:  Upload Cache.</LI>
 *    <LI>Vault: Enovia Vault Cache.</LI>
 * </UL>
 */
enum  CATOmyCioTypeOfCache { CuteIOCache_None = 0x00,                              
                             CuteIOCache_SL = 0x01,
                             CuteIOCache_XM = 0x02,
                             CuteIOCache_U  = 0x04,
                             CuteIOCache_PC = 0x08,
                             CuteIOCache_Vault = 0x10,
							 CuteIOCache_LV = 0x20,
							 CuteIOCache_AsyncIO = 0x40,
                             CuteIOCache_All = 0xFFFFFFFF} ;

#endif


