#ifndef CATDLGRESOURCE_H
#define CATDLGRESOURCE_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * Associates resource and message catalogs to the dialog object.
 * @param thisclass
 * The class of the dialog object.
 * @param baseclass
 * The base class of the dialog object.
 */
#define DeclareResource(thisclass, baseclass)                                        \
  public:                                                                            \
                                                                                     \
   virtual char* GetResourceFilename(int nDepth) const                               \
   {                                                                                 \
     return (char *)( nDepth <= 0 ? #thisclass : baseclass::GetResourceFilename(nDepth-1) ); \
   }
#endif
