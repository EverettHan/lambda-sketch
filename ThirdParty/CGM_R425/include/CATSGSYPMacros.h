#ifndef CATSGSYPMacros_H
#define CATSGSYPMacros_H

/**
 * Use FORCE_STACK_ALLOCATION to block usage of 
 * new and delete operators on a class
 *
 * :NOTE: If we define operator new, then name lookup for the placement new
 * version fails (hidden)
 *
 * However, even if we want to prevent components from being instantiated
 * directly on the heap, we still want dynamic containers, which usually rely
 * on call to placement new to remain usable (eg STL containers)
 */
#define SG_FORCE_STACK_ALLOCATION() \
public: \
  void *operator new(size_t, void *loc) { return loc; } \
  void operator delete(void *){}; \
private:   \
  void *operator new(size_t){return NULL;};

#endif
