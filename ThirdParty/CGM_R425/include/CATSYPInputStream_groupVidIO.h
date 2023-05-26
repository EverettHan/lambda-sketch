/*
 * This header file is not meant to be included by any code.
 *
 * It is only there to be parsed by Doxygen tool to generate the
 * documentation group groupVidIO.
 */

#error this file must never be included; doxygen file only.

/**
 * @defgroup groupVidIO VID Input/Output
 * The <b>VID Input/Output</b> module groups the classes used 
 * to handle binary input and output.
 *
 * @par Stream classes
 * There are some stream based classes that can be used
 * to manipulates bytes. They all implement one of these
 * interfaces:
 *   - @ref CATSYPInputStream for reading
 *   - @ref CATSYPOutputStream for writing
 * 
 * @par Coded stream classes
 * To simplify input and output in binary, there are 
 * some classes that can encode or decode simple types
 * in or from binary streams:
 *   - @ref CATSYPCodedInputStream can read binary data
 *     from a CATSYPInputStream
 *   - @ref CATSYPCodedOutputStream can write binary data
 *     to a CATSYPOutputStream
 *
 * @par Object stream classes
 * To stream @ref CATBaseUnknown objects, two base interfaces are
 * defined:
 *   - @ref CATSYPObjectInputStream to read objects from a
 *     @ref CATSYPInputStream
 *   - @ref CATSYPObjectOutputStream to write objects to a
 *     @ref CATSYPOutputStream
 *
 * @par
 * These two interfaces both inherits from @ref CATSYPCodedInputStream
 * and @ref CATSYPCodedOutputStream to implement the streaming of
 * basic data types but do not specify how the stream of objects is
 * implemented. It's up to the implementation of those interfaces to
 * specify it.
 *
 * @par
 * To simplify these implementations, two intefaces are defined for
 * the stream of specific object classes:
 *   - @ref CATSYPObjectDecoder to unstream a class of object from 
 *     a @ref CATSYPObjectInputStream
 *   - @ref CATSYPObjectEncoder to stream a class of object to a
 *     @ref CATSYPObjectOutputStream
 *
 * @par
 * A decoder is specific to a streamed type of object (i.e. to a
 * string that identifies the type of object in the stream). An
 * encoder is specific to a class of object (i.e. to the @ref
 * CATMetaClass of this object).
 *
 * @par
 * To simplify the implementation of decoders/encoders that don't need
 * to keep a state and can be implemented as a static function the
 * classes @ref CATSYPFunctionObjectDecoder and @ref
 * CATSYPFunctionObjectEncoder can be used.<br/>
 * Some functions to stream/unstream basic boxed data type can be
 * found in @ref groupVidIOBoxingCode module.
 *
 * @par
 * Implementations of @ref CATSYPObjectInputStream and @ref
 * CATSYPObjectOutputStream that use decoders/encoders need a way to
 * find the correct decoder/encoder to use. To support this discovery
 * process, two interfaces are defined:
 *   - @ref CATSYPObjectDecoderProvider to find a decoder when the
 *     streamed type of the object is known
 *   - @ref CATSYPObjectEncoderProvider to find an encoder for a 
 *     given class of object
 *
 * @par
 * Basic implementations of those interfaces based on static
 * dictionaries are provided: @ref CATSYPStaticDecoderProvider and
 * @ref CATSYPStaticEncoderProvider.<br/>
 * Some functions that returns providers of decoders/encoders for
 * basic boxed data types can be found in @ref groupVidIOBoxingCode.
 * 
 * @par
 * Implementations of @ref CATSYPObjectInputStream and @ref
 * CATSYPObjectOutputStream based on @ref CATSYPObjectDecoder/@ref
 * CATSYPObjectDecoder provided by @ref
 * CATSYPObjectDecoderProvider/@ref CATSYPObjectEncoderProvider
 * already exists: @ref CATSYPSHdrObjInputStream and @ref
 * CATSYPSHdrObjOutputStream. Those two stream classes are based on a
 * header written before the object data to stream the object streamed
 * type and the size of the associated data.
 */
