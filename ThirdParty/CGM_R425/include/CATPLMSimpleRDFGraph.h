#ifndef SimpleRDF_Graph_H
#define SimpleRDF_Graph_H 

#include "CATOmxCxxPortability.h"
#include "DSYString.h"
#include "CATPLMIntegrationBase.h"

#define SRDF_ERROR_BASE 0xce74
#define SRDF_E_NOMATCH  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, SRDF_ERROR_BASE + 1)
#define SRDF_E_SEVERALMATCHES MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, SRDF_ERROR_BASE + 2)
#define SRDF_E_CORRUPTCACHE MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, SRDF_ERROR_BASE + 3)

namespace SimpleRDF
{
  class Node;
  class Triple;
  class TripleCollection;
  class GraphImpl;
  /**
  * Simple RDF Graph.
  */
  class ExportedByCATPLMIntegrationBase Graph
  {
  public:
    /**
    * when creating a SimpleRDF Graph with base constructor
    * You must always call GetPersistantLayer
    * Example :
    *   SimpleRDF::Graph _rGraph;
    *   CATUnicodeString Path = *path to offlinecache file*
    *   SimpleRDF::Graph::GetPersistentLayer(Path,_rGraph);
    *
    * otherwise you get only E_UNEXPECTED HRESULT or false when performing add ,delete ,find etc ...
    */
    Graph();
    ~Graph();
    /*
    * Get and set Cachefolder path
    */
    static CATUnicodeString & CachePath();

    /**
     * Gets size of the TripleCollection
     * @return
     *   Size in unsigned int
     */
    int TripleCount() const;

    /**
    * Insert the triple in the Graph, return false if already existing
    * @param
    *  Triple object to be added
    * @return
    *   true if successful false if Triple already exists in Graph
    */

    bool Add(const Triple &);

    /**
    * Insert the triple as three nodes, return false if already existing
    * @param
    *  Subject predicate and object nodes
    * @return
    *   true if successful false if Triple already exists in Graph
    */
    bool Emplace(const Node & subject, const Node & predicate, const Node & object);

    /**
    * Delete the first triple matching a pattern from graph
    * @param
    *  Triple object to be deleted
    * @return
    *   S_OK: exactly one match found
    *   S_FALSE: no match found.
    *   SRDF_E_SEVERALMATCHES: more than one match found only first deleted.
    */
    HRESULT DeleteUnique(const Triple &);

    /**
    * Remove all triples matching pattern
    * @param
    *  Triple pattern to be deleted (should contain wildcard)
    * @return
    *   true if successful false if Triple does not exist in Graph
    */
    bool Delete(const Triple &);

    /**
   * Remove all triples in graph
   * this funtions clears triples and writes to log all delete operations
   * @return
   *   S_OK : Triple(s) succesfully deleted
   */
    HRESULT Clear();

    /**
    * Check if Triple exists at least once
    * WARNING Contains is not very good with multi wild card .. use the Find functions instead
    * @param
    *  Triple pattern to be found (can contain wildcard)
    * @return
    *   true : at least one triple matches pattern
    *   S_FALSE : not a single Triple matches pattern
    */
    bool Contains(const Triple &) const;

    /**
   * Find all Triples that matche a pattern
   * @param
   *  Triple pattern to be found (can contain wildcard)
   *  TripleCollection to store found tripes
   * @return
   *   true : at least one triple matches pattern
   *   false : not a single Triple matches pattern
   */
    bool Find(const Triple &, TripleCollection &) const;

    /**
     * Similar to Find but returns SRDF_E_SEVERALMATCHES if more than one match is found
     * @return
     *   S_OK: exactly one match found
     *   S_FALSE: no match found.
     *   SRDF_E_SEVERALMATCHES: more than one match found.
     */
    HRESULT FindUnique(const Triple& pattern, Triple& match) const;


    /**
    * Compares the TripleCollections of two graphs (Does not take into account Wildcards)
    * @return
    *   True: if TripleCollection are identical
    *   false: otherwise.
    */
    bool Equals(const Graph &) const;
    inline bool operator == (const Graph & g) const { return Equals(g); }
    inline bool operator != (const Graph & g) const { return !Equals(g); }
    inline bool operator !() const { return m_Impl == nullptr; }
    /**
    * Commit all changes to persistency layer
    * @return
    *   S_OK: Success
    *   E_FAIL: failed to write in cache.
    */
    HRESULT Commit();

    /**
    * abort all changes since the last commit
    * @return
    *   S_OK: Succes
    *   E_FAIL: failed to write in cache or recover abort log.
    */
    HRESULT Abort();
    /**
    * Creates Graph object from OfflineCache
    * If called on a non-empty graph
    * the Graph will be deleted and replaced with new one created from persistant layer
    * persistant layer AKA offline cache file
    * @return
    *   S_OK: Succes
    *   E_FAIL: failed to recover Graph.
    */
    static HRESULT GetPersistentLayer(const CATUnicodeString & s, Graph & g);

    /**
    * static function to Garbage collect OfflineCache
    */
    static HRESULT GarbageCollect();

    /**
    * function to get size of cache in bytes
    */
    static int GetCacheSize();
  private:
    Graph(const Graph&) OMX_Cxx11_DELETE;
    Graph& operator=(const Graph&) OMX_Cxx11_DELETE;
    GraphImpl * m_Impl;
  };
}

#endif

