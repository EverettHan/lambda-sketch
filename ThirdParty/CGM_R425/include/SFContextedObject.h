#ifndef SFContextedObject_h
#define SFContextedObject_h

// Mathematics
#include "CATMathPoint.h"

// ScalarFields
#include "ScalarFields.h"
#include "ScalarFieldUtils.h"
#include "SFTypes.h"
#include "SFSWContext.h"

// STD
#include <iostream>
#include <memory>
#include <vector>

namespace SF
{
  /**
   * @brief All objects which are tied to a specific context of execution should derive from this class.
   *
   * @details Some objects behavior need to be customizable at least to some extend. This is done via the SFSWContext.
   * see description of that class for more details.
   */
  class ExportedByScalarFields SFContextedObject 
  {
  public:
    /**
     * @brief If you know exactly which semantic level you need use this constructor to get your working SFContextedObject.
     *
     * @param iNeededSemanticLevel (SFSemanticLevel), the semantic level you know you need to use.
     */
    SFContextedObject(const SFSWContext& iCtx);

    /**
     * @brief copy constructor.
     *
     * @param iOther (SFContextedObject), another context.
     */
    SFContextedObject(const SFContextedObject& iOther);

    /**
     * @brief default dtor.
     *
     */
    virtual ~SFContextedObject();

    /**
     * @brief Gives you the level of semantic associated with this context. See SFContextedObject description.
     *
     * @return the semantic level supported within this context as a SFSemanticLevel.
     */
    const SFSWContext& GetContext() const;

  private:
    const SFSWContext& _ctx;
  };

  typedef std::unique_ptr<SFContextedObject> SFContextedObjectUPtr;
  typedef std::shared_ptr<SFContextedObject> SFContextedObjectPtr;
};

#endif // SFContextedObject_h
