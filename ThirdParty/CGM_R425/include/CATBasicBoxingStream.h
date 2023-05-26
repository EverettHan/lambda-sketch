#ifndef CATBasicBoxingStream_H
#define CATBasicBoxingStream_H

#include <IntroInfra.h>

/** @ingroup groupVidIO
 * @defgroup groupVidIOBoxingCode Encoders/Decoders for Boxed Value Types
 * The <b>Encoders/Decoders for Boxed Value Types</b> module groups
 * @ref CATSYPObjectEncoder and @ref CATSYPObjectDecoder
 * implementations for boxed value types (i.e. for object created by
 * macro @ref CATDeclareBox)
 */

/** 
 * @file
 * @ingroup groupVidIOBoxingCode
 * This header groups the declarations of functions that can be used
 * with @ref CATSYPFunctionObjectEncoder or @ref
 * CATSYPFunctionObjectDecoder to encode/decode boxed value types (see
 * @ref CATDeclareBox).
 *
 * @par No Modifications Guarantee
 * The encoding supported by encoding/decoding functions will never be
 * modified. This guarantee is mandatory to be able to use these
 * functions in stored streams.
 *
 * @see CATVidStdBoxingEncoders0
 * @see CATVidStdBoxingDecoders0
 */


class CATSYPObjectOutputStream;
class CATSYPObjectInputStream;
class CATBaseUnknown;
class CATBaseUnknown_var;

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfint. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_int
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_int(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfint. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_int
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_int(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATLONG64. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_CATLONG64
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_CATLONG64(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATLONG64. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_CATLONG64
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_CATLONG64(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATMathPoint2Df. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_CATMathPoint2Df
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_CATMathPoint2Df(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATMathPoint2Df. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_CATMathPoint2Df
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_CATMathPoint2Df(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATMathVector2Df. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_CATMathVector2Df
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_CATMathVector2Df(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATMathVector2Df. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_CATMathVector2Df
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_CATMathVector2Df(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOffloat. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_float
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_float(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOffloat. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_float
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_float(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfdouble. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_double
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_double(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfdouble. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_double
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_double(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATUnicodeString. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_CATUnicodeString
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_CATUnicodeString(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATUnicodeString. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_CATUnicodeString
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_CATUnicodeString(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATString. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_CATString
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_CATString(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATString. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_CATString
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_CATString(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATMathPointf. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_CATMathPointf
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_CATMathPointf(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATMathPointf. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_CATMathPointf
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_CATMathPointf(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATListValCATBaseUnknown_var. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_CATListValCATBaseUnknown_var
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_CATListValCATBaseUnknown_var(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATListValCATBaseUnknown_var. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_CATListValCATBaseUnknown_var
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_CATListValCATBaseUnknown_var(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATSYPProperties. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_decode_CATSYPProperties
 */
ExportedByIntroInfra int CATBasicBoxingStream_encode_CATSYPProperties(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATSYPProperties. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATBasicBoxingStream_encode_CATSYPProperties
 */
ExportedByIntroInfra int CATBasicBoxingStream_decode_CATSYPProperties(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);



#endif // CATBasicBoxingStream_H
