#ifndef __CATOmxRegexFunctor_h___
#define __CATOmxRegexFunctor_h___

/*
* Substitution functor. To be used with CATOmxRegex::Substitute.
* You can derive this class in order to specialize the substitution in CATOmxRegex::Substitute.
*

Example: 
 
  Replaces uuids by tokens (e.g. "uuid1", "uuid2",...). 
  Each uuid has a unique token. Use same token if the uuid matched was already found in the input.


Expected results:
                                           Inputs                                                                           Outputs

   "Mon uuid est: 0uf19ba5d9-0000-0ff8-5135fe3100000001"                                                              "Mon uuid est: uuid1"
   "Mon 1er uuid est: 0uf19ba5d9-0000-0ff8-5135fe3100000001, mon 2nd est: 0uf19ba5d9-0000-0ff8-5135fe3100000002"      "Mon 1er uuid est: uuid1, mon 2nd est: uuid2"
   "f19ba5d9-0000-0ff8-5135fe3100000001"                                                                              "uuid1"
   "f19ba5d9-0000-0ff8-5135fe3100000001 f19ba5d9-0000-0ff8-5135fe3100000001"                                          "uuid1 uuid1"
   "f19ba5d9-0000-0ff8-5135fe3100000001 f19ba5d9-0000-0ff8-5135fe3100000002"                                          "uuid1 uuid2"
   "f19ba5d9-0000-0ff8-5135fe3100000001 f19ba5d9-0000-0ff8-5135fe3100000002 f19ba5d9-0000-0ff8-5135fe3100000003"      "uuid1 uuid2 uuid3"
   "f19ba5d9-0000-0ff8-5135fe3100000001 f19ba5d9-0000-0ff8-5135fe3100000001 f19ba5d9-0000-0ff8-5135fe3100000001"      "uuid1 uuid1 uuid1"
   "f19ba5d9-0000-0ff8-5135fe3100000001 f19ba5d9-0000-0ff8-5135fe3100000002 f19ba5d9-0000-0ff8-5135fe3100000001"      "uuid1 uuid2 uuid1"

Implementation:

    class UuidToTokenFunctor : public CATOmxRegexFunctor
    {
    public:
      UuidToTokenFunctor(): m_index(0) {}

      virtual void Substitute(CATOmxTextStream & ioTextStream, const CATOmxRegex & iRegex)
      {
        CATUnicodeString matchedUuid = iRegex.Group(1).asString();
        CATUnicodeString index;

        int * tokenIndex = m_uuidToTokenIndexMap.Locate(matchedUuid);                  // Looking for matched in uuid in uuid to token map.
        if (tokenIndex)
        { 
          CATAssert(index.BuildFromNum(*tokenIndex));                                  // If found, get corresponding token index 
        }
        else
        { 
          m_index++;                                                                  // If not found, increment token index ...
          CATAssert(index.BuildFromNum(m_index));
          CATAssert(m_uuidToTokenIndexMap.Insert(matchedUuid, m_index));              // ... and add uuid to the map
        }

        CATAssert(!index.IsNull());
        CATUnicodeString token = "uuid";
        token = token + index;
        ioTextStream << token;                                                        // add token (e.g. "uuid1", "uuid2", "uuid3", ...) instead of matched uuid.
      }

    private:
      CATOmxOMap<CATUnicodeString, int> m_uuidToTokenIndexMap;
      int m_index;
    };


    CATOmxUTF8String uuidRegexPattern = "(/x{8}-/x{4}-/x{4}-/x{16})";
    CATOmxRegex regex;
    UNIT_ASSERT(regex.Compile(uuidRegexPattern, OMXRE_USESLASH_FOR_ESCAPE));

    UuidToTokenFunctor uuidToTokenFunctor;
    CATOmxUTF8String output;
    CATOmxUTF8String input = ...;
    regex.Substitute(uuidToTokenFunctor,input,output);
  
*/

#include "CATOmxKernel.h"
class CATOmxTextStream;
class CATOmxRegex;

class ExportedByCATOmxKernel CATOmxRegexFunctor {
public:
  /**
  * Substitution function.
  * This function is called each time a match is found in CATOmxRegex::Substitute.
  * @param ioTextStream
  *   The text stream that you may modify according to the match groups provided by iRegex.
  * @param iRegex
  *   The structure allowing you to get the match groups (see CATOmxRegex::GroupCount and CATOmxRegex::Group).
  */
  virtual void Substitute(CATOmxTextStream & ioTextStream, const CATOmxRegex & iRegex) = 0;
};

#endif
