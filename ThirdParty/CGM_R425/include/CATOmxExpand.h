#ifndef __CATOmxExpand_h__
#define __CATOmxExpand_h__

#include "CATOmxKernel.h"
#include "CATOmxVector.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"

class  CATOmxExpandContext;
class CATOmxExpandOperators;
class CATOmxTextStream;
class CATOmxKeyString;
class CATOmxUTF8String;
class CATOmxAny;
class CATOmxExpandContext_internal;
/**
 * define an expansion context.
 */
class ExportedByCATOmxKernel CATOmxExpandContext {
  CATOmxSR<CATOmxExpandContext_internal> m_internal;
  CATOmxExpandContext_internal &internal();
public:
  /**
   * Setup the context.
   */
  virtual CATOmxExpandContext &setup(const CATOmxKeyString &iKey);
  /**
   * Add a positionnal parameter.
   * @param
   */
  virtual CATOmxExpandContext &parm(const CATOmxAny &iParm);
  /**
   * Add a key parameter.
   * @param
   */
  virtual CATOmxExpandContext &parm(const CATOmxKeyString &iKey, const CATOmxAny &iParm);
   /**
   * Get data from context
   * @param iFrom is the source object (as an exemple a feature
   * @param iKey is the key as an example an attribute feature.
   * @param oObject the located object.
   */
  virtual HRESULT get(CATOmxAny &iFrom,CATOmxKeyString &iKey, CATOmxAny &oObject) ;
  /**
   * Return if a feature is enabled.
   */
  virtual CATBoolean is_feature_on(const CATOmxKeyString &iKey) const;
  /** @nodoc */
  unsigned int get_flags() const;
};

/**
 * Expand a compiled string according to a context.
 */
class ExportedByCATOmxKernel CATOmxExpand
{
  CATOmxVector<CATOmxExpandOperators> exp;
  HRESULT status;
public:
   CATOmxExpand(const CATOmxUTF8String &expand) ;
   /**
    * Expand the pattern according to context into text.
    */
   HRESULT Eval(CATOmxExpandContext &ctx, CATOmxTextStream &text);
   /**
    * Return the compilation status.
    */
   HRESULT GetStatus() const { return status; }
private:
   void addString(const char *&start,const char *stop) ;
   const char *parseTemplate(const char *cursor) ;
   const char *parserFilter(const char *cursor);
   const char *failure(const char *explaination);   
};

#endif
