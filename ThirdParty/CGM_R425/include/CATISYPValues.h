//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/05/06
//===================================================================
// CATSYPArray.cpp
// Header definition of class CATISYPValues
//===================================================================
//
// Usage notes: 
//
//===================================================================
//  2010/05/06 Creation: jov
//===================================================================
#ifndef CATISYPValues_H
#define CATISYPValues_H

#include "IntroInfra.h"
#include "CATBaseUnknown.h"

class CATBaseUnknown_var;
class CATSYPCodedOutputStream;
class CATSYPCodedInputStream;

extern ExportedByIntroInfra  IID IID_CATISYPValues ;

/**
 * Interface implemented by components used by introspection that have a value semantic.
 * A value like semantic means that it is not the instance of the object that make
 * sense, but only the value it represents through its internal state. For example
 * two instances of CATMathPointf may represents the same point if they have the
 * same x, y and z; the CATMathPointf class has a value semantic. But two instances
 * of CATVidCtlButton may be at the same position and have the exact same internal
 * state (same name, etc...); even though we don't consider them to represent the
 * same button; the CATVidCtlButton has a reference semantic.
 */
class ExportedByIntroInfra CATISYPValues: public CATBaseUnknown
{
CATDeclareInterface;

public:
  /**
   * Test equality of values.
   * This value is considered equal to other object if:
   *  - i_spCBU is not NULL_var
   *  - i_spCBU represents the same value
   * Note that this function must be:
   *  - commutative, i.e. if sp1 and sp2 are two non-null handler 
   *    objects, then sp1->Equals(sp2) and sp2->Equals(sp1) must 
   *    have the same result.
   *  - reflexive, i.e. if sp is a non-null handler, then 
   *    sp1->Equals(sp1) must return !=0.
   *  - transitive, i.e. if sp1, sp2 and sp3 are three non-null
   *    handler objects, then if sp1->Equals(sp2) and sp2->Equals(sp3),
   *    we must have sp1->Equals(sp3).
   *  - consistent, i.e. multiple invocations of this function must
   *    return the same result (unless the internal state representing
   *    the value has been modified).
   * @param i_spCBU an object to compare to. If NULL_var, then this
   * function must return 0.
   * @return !=0 if it is equals to the given object 0 otherwise.
   */
  virtual int Equals(const CATBaseUnknown_var& i_spCBU) =0;
  /**
   * @return the type of the value. It must NOT be NULL. The returned
   * value must be a static string (it implies that the caller must not
   * delete this value). All characters must be in the range [0-9A-Za-z_]
   * expect the first one that must be in range [A-Za-z_]. The string
   * must not be Empty.
   */
  virtual const char* GetType() =0;
  /**
   * Stream this value to the given stream. 
   * Note that the value does not have to stream its type to
   * the stream; it's the caller that will write the header
   * identifying the type of data before calling this function
   * (see @href CATSYPStream::BinaryValueStreamWithHeader).
   * Note also that if the value may be changed in the future (for
   * example if new data members may be added) it it a good idea to
   * store a version number in the stream, for example by starting
   * to write a VarUInt32 at the start of the stream.
   * Note that an unstream function must be defined. The unstreamer
   * must be an exported extern "C" function that can be casted to 
   * the @href CATISYPValuesBinaryUnstreamer type. Its name must be 
   * CATSYP##type##BinaryUnstreamer, where "type" is the value 
   * returned by @href #GetType. The shared library that contains 
   * this function must be referenced in a .CATFactory file.
   * @param i_outputStream the coded stream to use to stream the
   * value.
   * @return !=0 if the stream succeeded, else 0. Note that this
   * function should exit as soon as an error occured in the output
   * stream, consequently each line of the stream calling a Write*
   * function must contains a test and returns if the Write* failed.
   * Since the Write* may fail for an IOError, it may not be a good
   * idea to use an assertion. On the other hand, the Write* may also
   * fail due to invalid input values; and in this case, it would be
   * a good idea to have an assertion. Consequently, the macro
   * CHECK_WRITE_RETV should be used to test each Write* call.
   * @see CATSYPStream::BinaryValueUnstream
   * @see CATSYPStream::BinaryValueStreamWithHeader
   */
  virtual int BinaryStream(CATSYPCodedOutputStream &i_outputStream) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATISYPValues, CATBaseUnknown );

/**
 * Signature that the binary unstream function must respect.
 * @see CATISYPValues#BinaryStream for details.
 */
typedef CATISYPValues * (*CATISYPValuesBinaryUnstreamer)(CATSYPCodedInputStream &i_inputStream);



#endif
