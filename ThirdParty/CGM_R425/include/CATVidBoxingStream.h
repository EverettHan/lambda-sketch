#ifndef CATVidBoxingStream_H
#define CATVidBoxingStream_H

#include <VisuDialog.h>
#include <CATBasicBoxingStream.h>

/** 
 * @file
 * @ingroup groupVidIOBoxingCode
 * This header groups the declarations of functions that can be used
 * with @ref CATSYPFunctionObjectEncoder or @ref
 * CATSYPFunctionObjectDecoder to encode/decode boxed value types (see
 * @ref CATSYP_DECLARE_BOXING).
 *
 * It also declares some functions that can return a @ref
 * CATSYPObjectEncoderProvider or @ref CATSYPObjectDecoderProvider
 * that contains encoders/decoders built using some of these functions
 * (see these functions documentation for details).
 *
 * @par No Modifications Guarantee
 * The encoding supported by encoding/decoding functions will never be
 * modified. This guarantee is mandatory to be able to use these
 * functions in stored streams.
 *
 * @see CATVidStdBoxingEncoders0
 * @see CATVidStdBoxingDecoders0
 */

class CATSYPObjectEncoderProvider;
class CATSYPObjectDecoderProvider;

/** @ingroup groupVidIOBoxingCode
 * Returns a provider of @ref CATSYPObjectEncoder for boxed value
 * types.
 *
 * The encoders are all @ref CATSYPFunctionObjectEncoder. The
 * following types are handled:
 * <table>
 * <tr><th>C++ Type</th><th>Streamed Type</th><th>Encoding Function</th></tr>
 * <tr><td>@ref CATBoxingOfint</td><td>@c "int"</td><td>@ref CATBasicBoxingStream_encode_int</td></tr>
 * <tr><td>@ref CATBoxingOfCATLONG64</td><td>@c "CATLONG64"</td><td>@ref CATBasicBoxingStream_encode_CATLONG64</td></tr>
 * <tr><td>@ref CATBoxingOfCATMathPoint2Df</td><td>@c "CATMathPoint2Df"</td><td>@ref CATBasicBoxingStream_encode_CATMathPoint2Df</td></tr>
 * <tr><td>@ref CATBoxingOfCATMathVector2Df</td><td>@c "CATMathVector2Df"</td><td>@ref CATBasicBoxingStream_encode_CATMathVector2Df</td></tr>
 * <tr><td>@ref CATBoxingOffloat</td><td>@c "float"</td><td>@ref CATBasicBoxingStream_encode_float</td></tr>
 * <tr><td>@ref CATBoxingOfdouble</td><td>@c "double"</td><td>@ref CATBasicBoxingStream_encode_double</td></tr>
 * <tr><td>@ref CATBoxingOfCATUnicodeString</td><td>@c "CATUnicodeString"</td><td>@ref CATBasicBoxingStream_encode_CATUnicodeString</td></tr>
 * <tr><td>@ref CATBoxingOfCATString</td><td>@c "CATString"</td><td>@ref CATBasicBoxingStream_encode_CATString</td></tr>
 * <tr><td>@ref CATBoxingOfCATMathPointf</td><td>@c "CATMathPointf"</td><td>@ref CATBasicBoxingStream_encode_CATMathPointf</td></tr>
 * <tr><td>@ref CATBoxingOfCATListValCATBaseUnknown_var</td><td>@c "CATListValCATBaseUnknown_var"</td><td>@ref CATBasicBoxingStream_encode_CATListValCATBaseUnknown_var</td></tr>
 * <tr><td>@ref CATBoxingOfCATSYPProperties</td><td><b>@c "CATSYPPropertiesDico"<sup>*</sup></b></td><td>@ref CATBasicBoxingStream_encode_CATSYPProperties</td></tr>
 * <tr><td>@ref CATBoxingOfCAT4x4Matrix</td><td>@c "CAT4x4Matrix"</td><td>@ref CATVidBoxingStream_encode_CAT4x4Matrix</td></tr>
 * <tr><td>@ref CATBoxingOfCATVidMinMax</td><td>@c "CATVidMinMax"</td><td>@ref CATVidBoxingStream_encode_CATVidMinMax</td></tr>
 * </table>
 * <i><sup>*</sup>@c "CATSYPPropertiesDico" is used as streamed type
 * for @ref CATSYPProperties since it was the old name of this
 * class.</i>
 *
 * @par No Modifications Guarantee
 * No new encoders will ever be added to or removed from the returned
 * provider. The streamed types will never be modified.
 *
 * @return [IUnknown#Release] the provider. @c AddRef has been called
 * on the returned pointer so the caller must @c Release it.
 */
ExportedByVisuDialog CATSYPObjectEncoderProvider *CATVidStdBoxingEncoders0();

/** @ingroup groupVidIOBoxingCode
 * Returns a provider of @ref CATSYPObjectDecoder for boxed value
 * types.
 *
 * The decoders are all @ref CATSYPFunctionObjectDecoder. The
 * following types are handled:
 * <table>
 * <tr><th>Streamed Type</th><th>Encoding Function</th><th>C++ Type</th></tr>
 * <tr><td>@c "int"</td><td>@ref CATBasicBoxingStream_decode_int</td><td>@ref CATBoxingOfint</td></tr>
 * <tr><td>@c "CATLONG64"</td><td>@ref CATBasicBoxingStream_decode_CATLONG64</td><td>@ref CATBoxingOfCATLONG64</td></tr>
 * <tr><td>@c "CATMathPoint2Df"</td><td>@ref CATBasicBoxingStream_decode_CATMathPoint2Df</td><td>@ref CATBoxingOfCATMathPoint2Df</td></tr>
 * <tr><td>@c "CATMathVector2Df"</td><td>@ref CATBasicBoxingStream_decode_CATMathVector2Df</td><td>@ref CATBoxingOfCATMathVector2Df</td></tr>
 * <tr><td>@c "float"</td><td>@ref CATBasicBoxingStream_decode_float</td><td>@ref CATBoxingOffloat</td></tr>
 * <tr><td>@c "double"</td><td>@ref CATBasicBoxingStream_decode_double</td><td>@ref CATBoxingOfdouble</td></tr>
 * <tr><td>@c "CATUnicodeString"</td><td>@ref CATBasicBoxingStream_decode_CATUnicodeString</td><td>@ref CATBoxingOfCATUnicodeString</td></tr>
 * <tr><td>@c "CATString"</td><td>@ref CATBasicBoxingStream_decode_CATString</td><td>@ref CATBoxingOfCATString</td></tr>
 * <tr><td>@c "CATMathPointf"</td><td>@ref CATBasicBoxingStream_decode_CATMathPointf</td><td>@ref CATBoxingOfCATMathPointf</td></tr>
 * <tr><td>@c "CATListValCATBaseUnknown_var"</td><td>@ref CATBasicBoxingStream_decode_CATListValCATBaseUnknown_var</td><td>@ref CATBoxingOfCATListValCATBaseUnknown_var</td></tr>
 * <tr><td><b>@c "CATSYPPropertiesDico"<sup>*</sup></b></td><td>@ref CATBasicBoxingStream_decode_CATSYPProperties</td><td>@ref CATBoxingOfCATSYPProperties</td></tr>
 * <tr><td>@c "CAT4x4Matrix"</td><td>@ref CATVidBoxingStream_decode_CAT4x4Matrix</td><td>@ref CATBoxingOfCAT4x4Matrix</td></tr>
 * <tr><td>@c "CATVidMinMax"</td><td>@ref CATVidBoxingStream_decode_CATVidMinMax</td><td>@ref CATBoxingOfCATVidMinMax</td></tr>
 * </table>
 * <i><sup>*</sup>@c "CATSYPPropertiesDico" is used as streamed type
 * for @ref CATSYPProperties since it was the old name of this
 * class.</i>
 *
 * @par No Modifications Guarantee
 * No new decoders will ever be added to or removed from the returned
 * provider. The streamed types will never be modified.
 *
 * @return [IUnknown#Release] the provider. @c AddRef has been called
 * on the returned pointer so the caller must @c Release it.
 */
ExportedByVisuDialog CATSYPObjectDecoderProvider *CATVidStdBoxingDecoders0();




/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCAT4x4Matrix. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 * 
 * @see CATVidBoxingStream_decode_CAT4x4Matrix
 */
ExportedByVisuDialog int CATVidBoxingStream_encode_CAT4x4Matrix(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCAT4x4Matrix. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATVidBoxingStream_encode_CAT4x4Matrix
 */
ExportedByVisuDialog int CATVidBoxingStream_decode_CAT4x4Matrix(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectEncoder to encode a @ref CATBoxingOfCATVidMinMax. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATVidBoxingStream_decode_CATVidMinMax
 */
ExportedByVisuDialog int CATVidBoxingStream_encode_CATVidMinMax(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

/** @ingroup groupVidIOBoxingCode
 * Function to be used with a @ref CATSYPFunctionObjectDecoder to decode a @ref CATBoxingOfCATVidMinMax. 
 *
 * @par Encoding
 * <b>TODO</b>
 *
 * @par No Modifications Guarantee
 * The encoding supported by this function will never be
 * modified. This guarantee is mandatory to be able to use this
 * function in stored streams.
 *
 * @see CATVidBoxingStream_encode_CATVidMinMax
 */
ExportedByVisuDialog int CATVidBoxingStream_decode_CATVidMinMax(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);


#endif // CATVidBoxingStream_H
