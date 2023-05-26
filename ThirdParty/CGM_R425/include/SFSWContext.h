#ifndef SFSWContext_h
#define SFSWContext_h

// Mathematics
#include "CATMathPoint.h"

// ScalarFields
#include "ScalarFields.h"
#include "ScalarFieldUtils.h"
#include "SFTypes.h"

// STD
#include <iostream>
#include <memory>
#include <vector>

namespace SF
{
  enum class ExportedByScalarFields SFSemanticLevel { ECustom = 0, EV1 = 1, EV2 = 2 };
  enum class ExportedByScalarFields SFSemanticSupportStatus { EUndefined, ENotSupported, ESupported };
  enum class ExportedByScalarFields SFGeometryCreationMode { EUndefined, EVolumic, EShell };

  /**
   * @brief It is sometime convenient to attach to the SFSWContext some options impacting geometry creation, for example
   * this might allow to inform contexted objects involved in geometry creation that we want to generate the shell
   * and not the volumic representation.
   */
  class ExportedByScalarFields SFGeometryOptions {
  public:
    SFGeometryOptions();
    SFGeometryOptions(const SFGeometryOptions& iOther);
    SFGeometryOptions(const SFGeometryCreationMode iSFGeometryCreationMode);
    virtual ~SFGeometryOptions();

    SFINLINE const SFGeometryCreationMode GetCreationMode() const
    {
      return _creationMode;
    }

  private:
    SFGeometryCreationMode _creationMode;
  };

  /**
   * @brief Some ScalarFields key component features can be configured to some extend by the caller
   * through the settings maintained by the SFSWContext
   *
   * @details As an example you might want to synchronize some behavior with stream version levels.
   * This can be achieved by using the right SFSWContext when creating some ScalarFields components.
   * These are instances of classes deriving from SFSWContextedObject. An important example of this
   * is SFDagToExpression. You might want to indicate the level of semantic that you want to support.
   * For example a context created with GetContext(1) (see below) will allow semantics supported
   * by 23xGA stream but no further. GetContext(2) semantics supported by 24xGA ...
   * See also CATImplicitExpression::_Version. The UShort given to GetContext should match the value
   * used in CATImplicitExpression::_Version.
   */
  class ExportedByScalarFields SFSWContext {

  public:
    /**
     * @brief ctor that create a SFSWContext within which only default semantics are supported (SFSemanticLevel::EV1). Some semantics won't be enabled, for
     * example affine transforms...
     */
    SFSWContext();

    /**
     * @brief If you know exactly which semantic level you need use this constructor to get your working SFSWContext.
     *
     * @param iNeededSemanticLevel (SFSemanticLevel), the semantic level you know you need to use.
     */
    SFSWContext(const SFSemanticLevel iNeededSemanticLevel);

    /**
     * @brief copy constructor.
     *
     * @param iOther (SFSWContext), another context.
     */
    SFSWContext(const SFSWContext& iOther);

    /**
     * @brief default dtor.
     *
     */
    virtual ~SFSWContext();

    /**
     * @brief Gives you the level of semantic associated with this context. See SFSWContext description.
     *
     * @return the semantic level supported within this context as a SFSemanticLevel.
     */
    const SFSemanticLevel GetSupportedSemanticLevel() const;

    /**
     * @brief Provided information on whether the specified type is supported or not within this SFSWContext.
     * See also SFSemanticSupportStatus.
     *
     * @return the semantic level supported within this context as a SFSemanticLevel.
     *
     * @param iType (SFNodeType), the node type for which you want to know if it is supported of not withing this context.
     */
    const SFSemanticSupportStatus IsSemanticSupported(const SFNodeType iType) const;

    /**
     * @brief It is sometime convenient to attach to the SFSWContext some options impacting geometry creation, for example
     * this might allow to inform contexted objects involved in geometry creation that we want to generate the shell
     * and not the volumic representation.
     *
     * @param iGeometryOptions (:SFGeometryOptions), the options that we want to be used by contexted objects involved in geometry creation.
     */
    void SetGeometryOptions(const SFGeometryOptions& iGeometryOptions) {
      _geometryOptions = iGeometryOptions;
    }

    /**
     * @brief Get the GeometryOptions associated with the context.
     *
     * @return the geometry options.
     *
     */
    const SFGeometryOptions& GetGeometryOptions() const {
      return _geometryOptions;
    }

  protected:
    SFSemanticLevel     _supportedSemanticLevel;
    SFGeometryOptions   _geometryOptions;
  };

  typedef std::unique_ptr<SFSWContext> SFSWContextUPtr;
  typedef std::shared_ptr<SFSWContext> SFSWContextPtr;
};

#endif // SFSWContext_h
