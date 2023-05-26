#ifndef SFExportContext_h
#define SFExportContext_h

// Mathematics
#include "CATMathPoint.h"
#include "CATMathTransformation.h"

// ScalarFields
#include "ScalarFields.h"
#include "ScalarFieldUtils.h"
#include "SFEvaluationContext.h"

// STD
#include <iostream>
#include <memory>
#include <vector>

namespace SF
{
  /**
   * @brief SFExportContext is a specific SFEvaluationContext which can contain
   * additional settings to control what is exported. For example for SFFunctor nodes
   * on some occasion you might want to display the memoised dag.
   */
  class ExportedByScalarFields SFExportContext : public SFEvaluationContext {

    friend class PolyBodyToSF;

    typedef std::unique_ptr<SFExportContext> SFExportContextUPtr;
    typedef std::shared_ptr<SFExportContext> SFExportContextPtr;
  public:
    SFExportContext(const int iTag);
    SFExportContext(const SFEvaluationContext& iOther, const bool iExportMemoizedDAG);
    SFExportContext(const SFExportContext& iOther);
    virtual ~SFExportContext();

    const bool GetExportMemoizedDAG() const {
      return _exportMemoizedDAG;
    }

  private:
    const bool _exportMemoizedDAG;
  };
};

#endif // SFExportContext_h
