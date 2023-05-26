#ifndef CATSYPModelTagVisitor_H
#define CATSYPModelTagVisitor_H

#include <CATStyleProcessor.h>
#include <CATSYPMacros.h>

class CATSYPModelTag;
class CATSYPModelContainer;

/**
 * Interface that allow to parse a hierarchical tree of CATSYPModelTag
 * @see CATSYPModelTagVisitorBuilder
 */
class CATSYPModelTagVisitor
{
public:
  /**
   * Called by a CATSYPModelTag#Accept method.
   * @return 1 if the Accept method must continue, 0 if it has to be interrupted.
   */
  virtual int  VisitEnter(const CATSYPModelTag& i_tag)=0; 
  /**
   * Called by a CATSYPModelTag#Accept method.
   */
  virtual void Visit(const CATSYPModelTag& i_tag)=0; 
  /**
   * Called by a CATSYPModelTag#Accept method.
   * @return 1 if the Accept method must continue, 0 if it has to be interrupted.
   */
  virtual int  VisitChildrenEnter(const CATSYPModelContainer& i_tag)=0; 
  /**
   * Called by a CATSYPModelTag#Accept method.
   * @return 1 if the Accept method must continue, 0 if it has to be interrupted.
   */
	virtual int  VisitChildrenLeave(const CATSYPModelContainer& i_tag)=0; 
  /**
   * Called by a CATSYPModelTag#Accept method.
   * @return 1 if the Accept method must continue, 0 if it has to be interrupted.
   */
	virtual int  VisitLeave(const CATSYPModelTag& i_tag)=0; 
};
#endif
