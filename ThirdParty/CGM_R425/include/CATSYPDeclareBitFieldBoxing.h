// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYPDeclareBitFieldFactory.h
// Header definition of CATSYPDeclareBitFieldFactory
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2012  Creation: qf1
//===================================================================
#ifndef CATSYP_Declare_BitFieldFactory_H
#define CATSYP_Declare_BitFieldFactory_H

#include <CATISYPValues.h>

#define CATSYP_DECLARE_UINT32_BITFIELDBOXING(I_EXPORTED_BY, I_CLASS, I_BITFIELD)\
  CATSYP_DECLARE_BITFIELDBOXING(I_EXPORTED_BY, I_CLASS, I_BITFIELD, CATUINT32)
    
#define CATSYP_DECLARE_ULONG64_BITFIELDBOXING(I_EXPORTED_BY, I_CLASS, I_BITFIELD)  \
  CATSYP_DECLARE_BITFIELDBOXING(I_EXPORTED_BY, I_CLASS, I_BITFIELD, CATULONG64)

#define CATSYP_DECLARE_BITFIELDBOXING(I_EXPORTED_BY, I_CLASS, I_BITFIELD, TYPE)                      \
  class I_EXPORTED_BY CATBoxingOf##I_CLASS##__##I_BITFIELD : public CATISYPValues           \
  {                                                                     \
    CATDeclareClass;                                                    \
  public:                                                               \
    CATBoxingOf##I_CLASS##__##I_BITFIELD( const I_CLASS::I_BITFIELD &iValue );                            \
    ~CATBoxingOf##I_CLASS##__##I_BITFIELD();                            \
    const I_CLASS::I_BITFIELD _value;                                   \
    static CATBaseUnknown_var Box(const I_CLASS::I_BITFIELD &iValue);   \
    static HRESULT Unbox(const CATBaseUnknown_var &i_spReference, I_CLASS::I_BITFIELD &oValue); \
    /** See CATISYPValues#Equals */                                     \
    int Equals(const CATBaseUnknown_var& i_spCBU);                      \
    const char* GetType()                                               \
    {                                                                   \
    return #I_CLASS "__" #I_BITFIELD;                                   \
    }                                                                   \
    /** See CATISYPValues#BinaryStream */                               \
    int BinaryStream(CATSYPCodedOutputStream &i_outputStream);          \
    /**                                                                 \
     * Unstream this object from the given stream.                      \
     * @param i_inputStream the input stream to read from               \
     * @return the unstreamed object, NULL in case of error. Note that  \
     * if an error occured due to the i_inputStream, it can be queried  \
     * using CATSYPCodedInputStream#GetLastErrorKind. If an error       \
     * occured, a FAILURE should be raised except if it is a IOError    \
     * on the i_inputStream. In that case this function must simply     \
     * return NULL without any FAILURE.                                 \
     */                                                                 \
    static CATBoxingOf##I_CLASS##__##I_BITFIELD *BinaryUnstream(CATSYPCodedInputStream &i_inputStream); \
  };                                                                    \
                                                                        \
  /** The unstream function */                                          \
  extern "C" I_EXPORTED_BY                                              \
  CATISYPValues * CATSYP##I_CLASS##__##I_BITFIELD##BinaryUnstreamer(CATSYPCodedInputStream &i_inputStream);\
  /** A function that returns a boxing object */                        \
  /*extern "C" I_EXPORTED_BY                                              \
  CATBaseUnknown_var CreateBoxingOf##I_CLASS##__##I_BITFIELD(const int &iValue);*/

#endif
