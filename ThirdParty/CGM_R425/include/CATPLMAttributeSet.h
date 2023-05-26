#ifndef CATPLMAttributeSet_h
#define CATPLMAttributeSet_h

// This class holds the attribute values
// it can be of different types (string, int, binary,...), but can not be multi valuated

#include "CATIPLMAttributeSet.h"
#include "CATListOfCATString.h"
#include "CATIPLMValueReader.h"
#include "CATPLMIntegrationBase.h"
#include "CATOmxKeyValueBlock.h"
#include "CATPLMTypeH.h"
#include "CATOmxList.h"
#include "CATOmxOHMap.h"
#include "CATUnicodeString.h"

class CATString;
class CATIPLMValueWriter;
class CATICkeParm_var;

class ExportedByCATPLMIntegrationBase CATPLMAttributeSet : public CATIPLMAttributeSet
{
  CATDeclareClass;

public:
  typedef CATOmxIter<CATOmxPair<CATPLMTypeH, CATOmxKeyValueBlock> > CATPLMTypeHKVBlockIter;

  CATPLMAttributeSet(void);
  //CATPLMAttributeSet(const CATPLMAttributeSet &);
  //CATPLMAttributeSet & operator=(const CATPLMAttributeSet &);
  virtual ~CATPLMAttributeSet(void);

  /**
   * @see CATIPLMAttributeSet#AddAttribute
   */
  HRESULT AddAttribute(const CATString & iAttributeId, CATIPLMValueWriter * iValue);

  /**
   * @see CATIPLMAttributeSet#NextAttribute
   */
  HRESULT NextAttribute(int & ioPosition, CATString & oAttributeId, CATIPLMValueReader *& oValue);

  /**
  * @see CATIPLMAttributeSet#AddCkeParm
  */
  HRESULT AddCkeParm(const CATICkeParm_var & ispCkeParm);

  /**
   * @see CATIPLMAttributeSet#GetPLMValueWriter
   */
  HRESULT GetPLMValueWriter(CATIPLMValueWriter *& oValueWriter);

  /**
 * @see CATIPLMAttributeSet#AddExtensionBlock
 */
  HRESULT AddExtension(const CATPLMTypeH &iExtensionType, const CATOmxKeyValueBlock &iValue);

  /**
  * @see CATIPLMAttributeSet#GetExtensionsIterator
  */
  HRESULT GetExtensionsIterator(CATPLMTypeHKVBlockIter &oIter);

  /**
  * @see CATIPLMAttributeSet#AddStringValue
  */
  HRESULT AddStringAttribute(const CATString & iAttributeId, const CATUnicodeString & iValue);

  CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock>::IteratorType AsKeyValueBlocksIterator() const
  {
    return _Attributes.Iterator();
  }

private:
  HRESULT Reset();

private:
  //CATLISTV(CATString) _AttributeIds;
  //CATOmxList<CATIPLMValueReader> _AttributeValues;
  CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock> _Attributes;
  CATOmxKeyValueBlock::ConstIteratorType _curIter; //compatibility with NextAttributes...
};
#endif
