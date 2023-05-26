// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYPDeclareBoxing.h
// Header definition of CATSYPDeclareBoxing
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: qf1
//===================================================================
#ifndef CATSYP_Declare_Boxing_H
#define CATSYP_Declare_Boxing_H

#include <CATISYPValues.h>
#include <UIVCoreToolsPreventImplementation.h>
#include <UIVCoreToolsCATDeclareClass_withexport.h>
/**
 * Macro defining a class that will box a typed value in a CATBaseUnknown.
 * This class implement interface to @href CATISYPValues, and provides two methods
 * static CATBaseUnknown_var Box( const I_TYPE &iValue );
 *   Allows to create a CATBaseUnknown_var from a given typed value.
 * static HRESULT Unbox( const CATBaseUnknown_var &i_spReference, I_TYPE &oValue );
 *   Allows to recover a typed value from a CATBaseUnknown. If i_spReference is 
 *   not an appropriate box, it will return E_FAIL, S_OK otherwise.
 * Note that the @href Equals function will be implemented using 
 * @href CATSYPHashMapComparator template. That means that template specialization
 * for some types will be used. For example, CATBoxingOffloat will use the template
 * specialization for float that makes any Not A Number equals to other Not A Number
 * (see CATSYPHashMapComparator documentation for details).
 */
#define CATSYP_DECLARE_BOXING(I_EXPORTED_BY, I_TYPE)                      \
  class CATBoxingOf##I_TYPE : public CATISYPValues           \
  {                                                                     \
    CATDeclareClass_withexport(I_EXPORTED_BY);                          \
  public:                                                               \
    I_EXPORTED_BY ~CATBoxingOf##I_TYPE();                                               \
    const I_TYPE _value;                                                        \
    I_EXPORTED_BY static CATBaseUnknown_var Box(const I_TYPE &iValue);                  \
    I_EXPORTED_BY static HRESULT Unbox(const CATBaseUnknown_var &i_spReference, I_TYPE &oValue); \
    /** See CATISYPValues#Equals */                                     \
    I_EXPORTED_BY int Equals(const CATBaseUnknown_var& i_spCBU);                      \
    I_EXPORTED_BY const char* GetType()                                               \
    {                                                                   \
      return #I_TYPE;                                                     \
    }                                                                   \
    /** See CATISYPValues#BinaryStream */                               \
    I_EXPORTED_BY int BinaryStream(CATSYPCodedOutputStream &i_outputStream);          \
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
     I_EXPORTED_BY static CATBoxingOf##I_TYPE *BinaryUnstream(CATSYPCodedInputStream &i_inputStream); \
private:                                                                \
    CATBoxingOf##I_TYPE(const I_TYPE &iValue);                          \
    CATBoxingOf##I_TYPE(const CATBoxingOf##I_TYPE &iValue) PREVENT_IMPLEMENTATION; \
  };                                                                    \
                                                                        \
  /** The unstream function */                                          \
  extern "C" I_EXPORTED_BY CATISYPValues * CATSYP##I_TYPE##BinaryUnstreamer(CATSYPCodedInputStream &i_inputStream);


#include <vector>
#define CATSYP_DECLARE_BOXING_WITH_ALIAS(I_EXPORTED_BY, I_TYPEALIAS, I_TYPE)                              \
  class CATBoxingOf##I_TYPEALIAS : public CATISYPValues                                                   \
  {                                                                                                       \
    CATDeclareClass_withexport(I_EXPORTED_BY);                                                            \
                                                                                                          \
  public:                                                                                                 \
    I_EXPORTED_BY ~CATBoxingOf##I_TYPEALIAS();                                                            \
    const I_TYPE _value;                                                                                  \
    I_EXPORTED_BY static CATBaseUnknown_var Box(const I_TYPE &iValue);                                    \
    I_EXPORTED_BY static HRESULT Unbox(const CATBaseUnknown_var &i_spReference, I_TYPE &oValue);          \
    /** See CATISYPValues#Equals */                                                                       \
    I_EXPORTED_BY int Equals(const CATBaseUnknown_var &i_spCBU);                                          \
    I_EXPORTED_BY const char *GetType()                                                                   \
    {                                                                                                     \
      return #I_TYPEALIAS;                                                                                \
    }                                                                                                     \
    /** See CATISYPValues#BinaryStream */                                                                 \
    I_EXPORTED_BY int BinaryStream(CATSYPCodedOutputStream &i_outputStream);                              \
    /**                                                                                                   \
     * Unstream this object from the given stream.                                                        \
     * @param i_inputStream the input stream to read from                                                 \
     * @return the unstreamed object, NULL in case of error. Note that                                    \
     * if an error occured due to the i_inputStream, it can be queried                                    \
     * using CATSYPCodedInputStream#GetLastErrorKind. If an error                                         \
     * occured, a FAILURE should be raised except if it is a IOError                                      \
     * on the i_inputStream. In that case this function must simply                                       \
     * return NULL without any FAILURE.                                                                   \
     */                                                                                                   \
    I_EXPORTED_BY static CATBoxingOf##I_TYPEALIAS *BinaryUnstream(CATSYPCodedInputStream &i_inputStream); \
                                                                                                          \
  private:                                                                                                \
    CATBoxingOf##I_TYPEALIAS(const I_TYPE &iValue);                                                       \
    CATBoxingOf##I_TYPEALIAS(const CATBoxingOf##I_TYPEALIAS &iValue) PREVENT_IMPLEMENTATION;              \
  };                                                                                                      \
                                                                                                          \
/** The unstream function */                                                                              \
extern "C" I_EXPORTED_BY CATISYPValues *CATSYP##I_TYPEALIAS##BinaryUnstreamer(CATSYPCodedInputStream &i_inputStream);

#endif
