#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <iterator>
#include <cstddef>

#include <CATSysErrorDef.h>
#include <CATSysBoolean.h>
#include <CATDataType.h>

#include "PolyMathContainers.h"

#include "CATPolyAssert.h"

// From
// https://probablydance.com/2018/05/28/a-new-fast-hash-table-in-response-to-googles-new-fast-hash-table/

struct ExportedByPolyMathContainers HashMapUtils {
  static constexpr uint32_t block_size_log = 4;
  static constexpr uint32_t block_size = 1 << block_size_log;
  static constexpr uint32_t block_size_minus_one = block_size - 1;
  static constexpr uint32_t control_empty = 255;
  static constexpr uint32_t control_endlist = 254;
  static constexpr uint32_t control_endlist_without_first = 126;
  static constexpr uint32_t control_first_node_in_bucket = 1 << 7;

  static constexpr float max_load_factor = 0.9375f;

  static constexpr uint32_t nb_jump_distances = 126;
  // jump distances chosen like this:
  // 1. pick the first 16 integers to promote staying in the same block
  // 2. add the next 66 triangular numbers to get even jumps when
  // the hash table is a power of two
  // 3. add 44 more triangular numbers at a much steeper growth rate
  // to get a sequence that allows large jumps so that a table
  // with 10000 sequential numbers doesn't endlessly re-allocate
  static constexpr uint64_t jump_distances[nb_jump_distances] {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17,

    21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231,
    253, 276, 300, 325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630,
    666, 703, 741, 780, 820, 861, 903, 946, 990, 1035, 1081, 1128, 1176,
    1225, 1275, 1326, 1378, 1431, 1485, 1540, 1596, 1653, 1711, 1770, 1830,
    1891, 1953, 2016, 2080, 2145, 2211, 2278, 2346, 2415, 2485, 2556,

    3741, 8385, 18915, 42486, 95703, 215496, 485605, 1091503, 2456436,
    5529475, 12437578, 27986421, 62972253, 141700195, 318819126, 717314626,
    1614000520, 3631437253, 8170829695, 18384318876, 41364501751,
    93070021080, 209407709220, 471167588430, 1060127437995, 2385287281530,
    5366895564381, 12075513791265, 27169907873235, 61132301007778,
    137547673121001, 309482258302503, 696335090510256, 1566753939653640,
    3525196427195653, 7931691866727775, 17846306747368716,
    40154190394120111, 90346928493040500, 203280588949935750,
    457381324898247375, 1029107980662394500, 2315492957028380766,
    5209859150892887590
  };

  static constexpr bool is_power_two(uint32_t const v) {
    return (v & (v - 1)) == 0;
  }

  static constexpr uint32_t add_bucket(uint32_t const i1, uint32_t const i2) {
    uint32_t const i = i1 + i2;
    return i;
  }
};

constexpr uint32_t HashMapUtils::control_empty;
constexpr uint64_t HashMapUtils::jump_distances[];



template <typename T, uint32_t size>
struct  Block {
  static_assert(HashMapUtils::is_power_two(size), "block size should be a power of 2");

  std::array<uint8_t, size> control;
  std::array<T, size> data;

  Block() {
    std::fill(std::begin(control), std::end(control), HashMapUtils::control_empty);
  }
};



template <typename HashMap>
struct ExportedByPolyMathContainers Iterator {
  using key_type = typename HashMap::key_type;
  using Value = typename HashMap::value_type;  // XXX
  using iterator_category = std::forward_iterator_tag;
  using difference_type   = uint32_t;
  using value_type        = std::pair<key_type, typename HashMap::value_type>; // XXX
  using pointer           = value_type*;  // or also value_type*
  using reference         = value_type&;  // or also value_type&

private:
  Block<value_type, HashMapUtils::block_size>* begin_block;
  Block<value_type, HashMapUtils::block_size>* block;
  uint32_t capacity;
  uint32_t i;

#ifdef POLY_DEBUG_BUILD
  uint32_t hashmap_state;
#endif

  void set_hashmap_state(uint32_t const state) {
#ifdef POLY_DEBUG_BUILD
    hashmap_state = state;
#endif
  }

public:
  Iterator() :
    begin_block(nullptr),
    block(nullptr),
    capacity(0),
    i(0) {
    set_hashmap_state(0);
  }

  Iterator(HashMap const& hashmap, uint32_t const i_) :
        begin_block(hashmap.block),
        block(hashmap.block),
        capacity(hashmap.get_capacity()),
        i(i_)
  {
    poly_assert(HashMapUtils::is_power_two(capacity));
    poly_assert(i < capacity);
    block = begin_block + (i >> HashMapUtils::block_size_log);
    set_hashmap_state(hashmap.get_hashmap_state());
  }

  Iterator(Iterator const& it) :
        begin_block(it.begin_block),
        block(it.block),
        capacity(it.capacity),
        i(it.i) {
    poly_assert(HashMapUtils::is_power_two(capacity));
    poly_assert(i <= capacity);
    set_hashmap_state(it.get_hashmap_state());
  }

  bool is_end() const {
    return i >= capacity;
  }

  bool is_first_element_in_bucket() const {
    poly_assert(!is_end());

    auto const control = get_control();
    if (control == HashMapUtils::control_empty) {
      return false;
    }

    return control & HashMapUtils::control_first_node_in_bucket;
  }

  reference operator*() const {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    return block->data[ii];
  }

  pointer operator->() {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    return &block->data[ii];
  }

  uint32_t get_i() const {return i;}

  uint8_t get_control() const {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    return block->control[ii];
  }

  key_type const& get_key() const {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    return block->data[ii].first;
  }

  Value const& get_value() const {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    return block->data[ii].second;
  }

  Value& get_value() {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    return block->data[ii].second;
  }

  void set_control(uint8_t const new_control) {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    block->control[ii] = new_control;
  }

  void set_key(key_type const& k) {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    block->data[ii].first = k;
  }

  void set_value(Value const& v) {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    block->data[ii].second = v;
  }

  void set(uint8_t const new_control, key_type const& k, Value const& v) {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    block->control[ii] = new_control;
    block->data[ii].first = k;
    block->data[ii].second = v;
  }

  Iterator& bucket_next()  {
    poly_assert(block != nullptr);
    poly_assert(begin_block != nullptr);

    uint32_t const ii = i & HashMapUtils::block_size_minus_one;
    uint8_t const control = block->control[ii];
    uint8_t const control_without_first = control & (HashMapUtils::control_first_node_in_bucket - 1);
    if (control_without_first >= HashMapUtils::control_endlist_without_first) {
      block = nullptr;
      i = capacity;
    } else {
      add(HashMapUtils::jump_distances[control_without_first]);

      poly_assert(block != nullptr);
      poly_assert(begin_block != nullptr);
    }

    return *this;
  }

  Iterator& value_next() {
    static_assert(HashMapUtils::block_size >= 16, "HashMapUtils::block_size must be a multiple of 16");
    poly_assert(!is_end());

    i++;
    while(1) {
      uint32_t const ii = i & HashMapUtils::block_size_minus_one;
      switch (ii) {
      case 0:
        block++;
        if (i >= capacity) {
          block = nullptr;
          return *this;
        }

        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 1:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 2:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 3:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 4:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 5:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 6:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 7:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 8:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 9:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 10:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 11:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 12:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 13:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 14:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      case 15:
        if (get_control() != HashMapUtils::control_empty) {
          return *this;
        }
        i++;
      }
    }
  }

  Iterator value_next(int const) {
    Iterator<HashMap> tmp = *this;
    value_next();
    return tmp;
  }

  Iterator& add(uint32_t const offset) {
    poly_assert(begin_block != nullptr);
    poly_assert(i < capacity);

    i = HashMapUtils::add_bucket(i, offset);
    i = i & (capacity - 1);
    block = begin_block + (i >> HashMapUtils::block_size_log);

    return *this;
  }

  Iterator& operator++() {
    return value_next();
  }

  Iterator operator++(int const unused) {
    return value_next(unused);
  }

//  Iterator& operator+=(uint32_t const offset);
  Iterator& operator=(Iterator const& it) {
    begin_block = it.begin_block;
    block = it.block;
    capacity = it.capacity;
    i = it.i;
    set_hashmap_state(it.get_hashmap_state());

    return *this;
  }

  bool operator==(Iterator const& it) const {
    poly_assert(begin_block == it.begin_block || is_end() || it.is_end());
    poly_assert(capacity == it.capacity || is_end() || it.is_end());
    poly_assert(get_hashmap_state() == it.get_hashmap_state() || is_end() || it.is_end());

    return (i == it.i && begin_block == it.begin_block) || (is_end() && it.is_end());
  }

  bool operator!=(Iterator<HashMap> const& it2) {
    return !this->operator==(it2);
  }

  void begin() {
    block = begin_block;
    i = 0;

    if (is_end()) {  // empty hashmap
      return;
    }

    if (get_control() != HashMapUtils::control_empty) {
      return;
    }

    value_next();
  }

  static Iterator end() {
    return Iterator();
  }

  uint32_t get_hashmap_state() const {
#ifdef POLY_DEBUG_BUILD
    return hashmap_state;
#else
    return 0;
#endif
  }
};

template <typename Key, typename Value, typename Hash>
class ExportedByPolyMathContainers HashMap final {

public:
  using block_type = Block<std::pair<Key, Value>, HashMapUtils::block_size>;
  static block_type empty_block;

  block_type* block;
  uint32_t capacity; //  max number of element = blocksize * nb_block * max_load_factor
  uint32_t element_count;

#ifdef POLY_DEBUG_BUILD
  uint32_t hashmap_state = 0;
#endif

  void update_hashmap_state() {
#ifdef POLY_DEBUG_BUILD
    hashmap_state++;
#endif
  }

  uint32_t get_hashmap_state() const {
#ifdef POLY_DEBUG_BUILD
    return hashmap_state;
#else
    return 0;
#endif
  }

  uint32_t map_hash_to_bucket(typename std ::size_t const hash) const {
    return static_cast<uint32_t>(hash & (capacity - 1));
  }

  uint32_t get_first_bucket(Key const& k) const {
    auto const hash = Hash{}(k);
    uint32_t const bucket = map_hash_to_bucket(hash);
    return bucket;
  }


public:
  using key_type = Key;
  using value_type = Value;
  using size_type = uint32_t;
  using iterator = Iterator<HashMap<Key, Value, Hash>>;

  HashMap() :
    block(&empty_block),
    capacity(1),
    element_count(0) {
  }

  template<class InputIt>
  HashMap(InputIt first, InputIt last) :
    HashMap() {
    for (auto it = first; it != last; ++it) {
      insert(*it);
    }
  }

  HashMap(std::initializer_list<std::pair<Key, Value>> init) :
    HashMap(std::begin(init), std::end(init)) {}

  ~HashMap() {
    clear();
  }

//  HashMap(HashMap const& h) = delete;

  /*
   * FIND
   */
  iterator find(Key const& k) const  {
    iterator it(*this, get_first_bucket(k));
    if (!it.is_first_element_in_bucket()) {
      return iterator::end();
    }

    while (!it.is_end()) {
      if (it.get_key() == k) {
        return it;
      }

      it.bucket_next();
    }

    return iterator::end();
  }

  /*
   * INSERT
   */
  std::pair<iterator, bool> insert(std::pair<Key const, Value const> const& p) {
    return insert<InsertOnlyFunctor>(p.first, p.second);
  }

  // TODO &&
  std::pair<iterator, bool> insert_or_assign(Key const& k, Value const& v) {
    return insert<InsertOrAssignFunctor>(k, v);
  }

  /**
   * Inserts or updates a pair (key, value) in the map.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A new key is inserted or updated in the map.
   *   <li> <tt>S_FALSE</tt> The key is already in the map and does not need to be updated.
   *   <li> <tt>E_FAIL</tt> The pair cannot be inserted in the map because some error occured.
   * </ul>
   */
  HRESULT InsertOrUpdate(Key const& k, Value const& v) {
    if ((element_count + 1) > HashMapUtils::max_load_factor * capacity) {
      grow();
    }

    InsertWithoutGrow p = insert_without_grow<InsertOrAssignFunctor>(k, v);
    while (!(p.it_insert.second || p.is_updated)) {
      grow();
      p = insert_without_grow<InsertOrAssignFunctor>(k, v);
    }

    if (!p.is_updated) {
      element_count++;
    }

    if (p.it_insert.second) {
      return S_OK;
    }

    if (p.is_updated) {
      if (p.already_exist) {
        return S_FALSE;
      } else {
        return S_OK;
      }
    }

    return E_FAIL;
  }

private :
  struct InsertWithoutGrow {
    std::pair<iterator, bool> it_insert;
    bool is_updated;
    bool already_exist;

    InsertWithoutGrow(iterator const& it, bool const is_inserted, bool const is_updated_, bool const already_exist_) :
      it_insert{it, is_inserted},
      is_updated(is_updated_),
      already_exist(already_exist_) {}

    InsertWithoutGrow(std::pair<iterator, bool> const& it_insert_, bool const is_updated_, bool const already_exist_) :
      it_insert(it_insert_),
      is_updated(is_updated_),
      already_exist(already_exist_) {}

    InsertWithoutGrow& operator=(InsertWithoutGrow const& i) {
      it_insert = i.it_insert;
      is_updated = i.is_updated;
      already_exist = i.already_exist;

      return *this;
    }
  };

  struct InsertOrAssignFunctor {
    static bool assign(iterator& it, Value const& v /* TODO && ? */) {
      if (it.get_value() == v) {
        return true;
      }

      it.set_value(v);
      return false;
    }
  };

  struct InsertOnlyFunctor {
    static bool assign(iterator&, Value const& /* TODO && ? */) {
      return false;
    }
  };

  template <typename InsertOrAssignFunctor>
  std::pair<iterator, bool> insert(Key const& k, Value const& v) {
    if ((element_count + 1) > HashMapUtils::max_load_factor * capacity) {
      grow();
    }

    InsertWithoutGrow p = insert_without_grow<InsertOrAssignFunctor>(k, v);
    while (!(p.it_insert.second || p.is_updated)) {
      grow();
      p = insert_without_grow<InsertOrAssignFunctor>(k, v);
    }

    if (!p.is_updated) {
      element_count++;
    }

    return p.it_insert;
  }

  /*
   * Start a new bucket
   * Suppose that the slot is available (empty or the old value is no longer relevant)
   */
  InsertWithoutGrow insert_new_bucket(iterator& it, Key const& k, Value const& v) {
    it.set(HashMapUtils::control_endlist, k, v);
    return {it, true, false, false};
  }

  InsertWithoutGrow insert_last_element(iterator& it, Key const& k, Value const& v, uint8_t const is_after_first_prefix) {
    poly_assert(is_after_first_prefix == 0 || is_after_first_prefix == HashMapUtils::control_first_node_in_bucket);

    for (uint32_t i = 0; i < HashMapUtils::nb_jump_distances; i++) {
      iterator next_it(it);
      next_it.add(HashMapUtils::jump_distances[i]);

      if (next_it.get_control() == HashMapUtils::control_empty) { // new bucket & new
        it.set_control(is_after_first_prefix + i);
        next_it.set(HashMapUtils::control_endlist_without_first, k, v);
        return {next_it, true, false, false};
      }
    }

    return {iterator::end(), false, false, false};
  }

  template <typename InsertOrAssignFunctor>
  InsertWithoutGrow insert_without_grow(Key const& k, Value const& v) {
    uint32_t const bucket = get_first_bucket(k);
    iterator it(*this, bucket);

    auto const control = it.get_control();

    if (control & HashMapUtils::control_first_node_in_bucket) { // correct bucket
      if (control == HashMapUtils::control_empty) { // new bucket & new element
        return insert_new_bucket(it, k, v);
      } else if (control == HashMapUtils::control_endlist) {  // existing bucket with only 1 element

        // update
        if (it.get_key() == k) {
          bool const already_exist = InsertOrAssignFunctor::assign(it, v);
          return {it, false, true, already_exist};
        }

        // insert
        return insert_last_element(it, k, v, HashMapUtils::control_first_node_in_bucket);
      } else {  // existing bucket with more than 1 element

        // update
        do {
          if (it.get_key() == k) {
            bool const already_exist = InsertOrAssignFunctor::assign(it, v);
            return {it, false, true, already_exist};
          }
          it.bucket_next();
        } while (it.get_control() != HashMapUtils::control_endlist_without_first);
        if (it.get_key() == k) {
          bool const already_exist = InsertOrAssignFunctor::assign(it, v);
          return {it, false, true, already_exist};
        }

        return insert_last_element(it, k, v, 0);
      }

    } else {	// an element (from another bucket) is already there -> we must move it first and create an new bucket with the new element
      update_hashmap_state();

      Key const& old_key = it.get_key();
      uint32_t const old_first_bucket = get_first_bucket(old_key);

      iterator prev_it;//(*this, old_first_bucket);
      iterator next_it(*this, old_first_bucket);

      poly_assert(old_key != next_it->first);
      poly_assert(next_it.get_control() & HashMapUtils::control_first_node_in_bucket);
      poly_assert(old_first_bucket != bucket);
      do {
        prev_it = next_it;
        next_it.bucket_next();
      } while (next_it.get_key() != old_key);

      poly_assert(old_key != prev_it->first);
      poly_assert(old_key == next_it->first);
      poly_assert(next_it.get_i() == bucket);
      if (next_it.get_control() == HashMapUtils::control_endlist_without_first) {
        InsertWithoutGrow const p = insert_last_element(prev_it, next_it->first, next_it->second, prev_it.get_control() & HashMapUtils::control_first_node_in_bucket);
        if (!p.it_insert.second) {
          return p;
        }

        return insert_new_bucket(it, k, v);

      } else {
        poly_assert(next_it.get_control() != HashMapUtils::control_endlist_without_first && next_it.get_control() != HashMapUtils::control_endlist);

        auto const prev_control_without_first = prev_it.get_control() & (HashMapUtils::control_first_node_in_bucket - 1);
        auto const next_control_without_first = next_it.get_control() & (HashMapUtils::control_first_node_in_bucket - 1);
        uint64_t expected_jump = HashMapUtils::add_bucket(HashMapUtils::jump_distances[prev_control_without_first], HashMapUtils::jump_distances[next_control_without_first]) & (capacity - 1);

        uint32_t const min_nb_jump_distances = capacity < HashMapUtils::nb_jump_distances ? capacity : HashMapUtils::nb_jump_distances; //std::min(capacity, HashMapUtils::nb_jump_distances);
        for (uint32_t i = 0; i < min_nb_jump_distances; i++) {
          if (expected_jump == (HashMapUtils::jump_distances[i] & (capacity -1))) {
            Value const& old_value = next_it->second;
            do {
              next_it.bucket_next();
              poly_assert(!next_it.is_end());
              poly_assert((next_it.get_control() & HashMapUtils::control_first_node_in_bucket) == false);
            } while (next_it.get_control() != HashMapUtils::control_endlist_without_first);

            InsertWithoutGrow const p = insert_last_element(next_it, old_key, old_value, 0);
            if (!p.it_insert.second) {
              return p;
            }

            prev_it.set_control((prev_it.get_control() & HashMapUtils::control_first_node_in_bucket) + i);
            return insert_new_bucket(it, k, v);
          }
        }

        while(1) {
          InsertWithoutGrow const p = insert_last_element(prev_it, next_it.get_key(), next_it.get_value(), prev_it.get_control() & HashMapUtils::control_first_node_in_bucket);
          if (!p.it_insert.second) {
            return p;
          }

          prev_it = p.it_insert.first;
          iterator old_it = next_it;

          next_it.bucket_next();

          if (old_it.get_i() != bucket) {
            old_it.set_control(HashMapUtils::control_empty);
          }
          if (next_it.is_end()) {
            return insert_new_bucket(it, k, v);
          }

          poly_assert(prev_it.get_control() == HashMapUtils::control_endlist_without_first);
          expected_jump = (next_it.get_i() - prev_it.get_i()) & (capacity - 1);
          for (uint32_t i = 0; i < min_nb_jump_distances; i++) {
            uint32_t const prev_jump_i = HashMapUtils::add_bucket(prev_it.get_i(), HashMapUtils::jump_distances[i]) & (capacity - 1);
            if (prev_jump_i == next_it.get_i()) {
              prev_it.set_control((prev_it.get_control() & HashMapUtils::control_first_node_in_bucket) + i);
              return insert_new_bucket(it, k, v);
            }
          }
        }

        poly_assert(false);
      }
    }

    return {iterator::end(), false, false, false};
  }



  /*
   * ERASE
   */
  std::pair<iterator, size_type> erase_from_key(Key const& k) {
    iterator it = iterator(*this, get_first_bucket(k));
    if (!it.is_first_element_in_bucket()) {
      return {end(), 0};
    }

    iterator prev_it(it);
    iterator next_it(it);
    while (next_it.get_control() != HashMapUtils::control_endlist_without_first && next_it.get_control() != HashMapUtils::control_endlist) {
      if (next_it.get_key() == k) {
        it = next_it;
      }

      prev_it = next_it;
      next_it.bucket_next();
    }
    if (next_it.get_key() == k) {
      it = next_it;
    }

    if (it.get_key() != k) {
      return {end(), 0};
    }

    poly_assert(element_count != 0);
    auto const control = it.get_control();

    // only 1 element in the bucket
    if (control == HashMapUtils::control_endlist) {
      it.set_control(HashMapUtils::control_empty);
      --element_count;

      return {it.value_next(), 1};
    }

    // element is at the end of the bucket
    if (control == HashMapUtils::control_endlist_without_first) {
      poly_assert(it.get_i() != prev_it.get_i());
      poly_assert(it.get_i() == next_it.get_i());
      poly_assert(!(control & HashMapUtils::control_first_node_in_bucket));
      prev_it.set_control((prev_it.get_control() & HashMapUtils::control_first_node_in_bucket) + HashMapUtils::control_endlist_without_first);
      it.set_control(HashMapUtils::control_empty);
      --element_count;

      return {it.value_next(), 1};
    }

    // element is somewhere in the bucket -> swap with the last element
    update_hashmap_state();

    poly_assert(it.get_i() != next_it.get_i());
    poly_assert(next_it.get_control() == HashMapUtils::control_endlist_without_first);
    poly_assert(prev_it.get_i() != next_it.get_i());
    it.set_key(next_it.get_key());
    it.set_value(next_it.get_value());
    prev_it.set_control((prev_it.get_control() & HashMapUtils::control_first_node_in_bucket) + HashMapUtils::control_endlist_without_first);
    next_it.set_control(HashMapUtils::control_empty);
    --element_count;

    return {it, 1};
  }

public :
  size_type erase(Key const& k) {
    auto const p = erase_from_key(k);
    return p.second;
  }

  iterator erase(iterator const pos) {
    poly_assert(get_hashmap_state() == pos.get_hashmap_state());
    auto const p = erase_from_key(pos.get_key());
    return p.first;
  }

  void reserve(size_type const count) {
    size_type s = HashMapUtils::block_size;
    while (s * HashMapUtils::max_load_factor < count) {
      s *=2;
    }

    grow(s);
  }

  // TODO
  void grow() {
    if (capacity == 1) {
      poly_assert(block == &empty_block);
      size_type const new_capacity = HashMapUtils::block_size;
      grow(new_capacity);
    } else {
      poly_assert((capacity & (1 << 31)) == 0);
      size_type const new_capacity = 2 * capacity;
      grow(new_capacity);
    }
  }

  void grow(size_type const new_capacity) {
    update_hashmap_state();

    uint32_t const old_capacity = capacity;
    capacity = new_capacity;

    block_type* const old_block = block;
    uint32_t const nb_block = capacity / HashMapUtils::block_size;

    block = new block_type[nb_block];
    uint32_t const nb_old_block = old_capacity / HashMapUtils::block_size;

    for (uint32_t index_block = 0; index_block < nb_old_block; index_block++) {
      block_type* const b = old_block + index_block;
      for (uint32_t i = 0; i < HashMapUtils::block_size; i++) {
        if (b->control[i] != HashMapUtils::control_empty) {
          insert_without_grow<InsertOnlyFunctor>(b->data[i].first, b->data[i].second);
        }
      }
    }

    if (old_capacity != 1) {
      poly_assert(block != &empty_block);
      delete[] old_block;
    }
  }

  void clear() {
    update_hashmap_state();

    if (capacity != 1) {
      poly_assert(block != &empty_block);
      delete[] block;
    }

    block = &empty_block;
    capacity = 1;
    element_count = 0;
  }

  uint32_t get_capacity() const {
    return capacity;
  }

  uint32_t size() const noexcept {
    return element_count;
  }

  bool empty() const noexcept {
    return element_count == 0;
  }

  iterator end() const {
    return iterator::end();
  }

  iterator begin() const {
    if (empty()) {
      return end();
    }

    iterator it = iterator(*this, 0);
    if (it.get_control() != HashMapUtils::control_empty) {
      return it;
    }

    return it.value_next();
  }
};

template <typename Key, typename Value, typename Hash>
typename HashMap<Key, Value, Hash>::block_type HashMap<Key, Value, Hash>::empty_block;




template <typename Key, typename Value, typename Hash>
class ExportedByPolyMathContainers PolyHashMap {
private :
  using HashMapType = HashMap<Key, Value, Hash>;
  using HashMapIterator = typename HashMapType::iterator;
  HashMapType map;

public :
  class PolyHashMapIterator {
  private:
    HashMapIterator it;

  public:
    PolyHashMapIterator() {};
    PolyHashMapIterator(void*) {};

    PolyHashMapIterator(PolyHashMap const& polyHashMap) :
      it(polyHashMap.map.begin()) {};

    PolyHashMapIterator(HashMapIterator it_) :
      it(it_) {};

    PolyHashMapIterator& operator++() {
      it.operator++();
      return *this;
    }

    PolyHashMapIterator& operator++(int const unused) {
      it.operator++(unused);
      return *this;
    }

    PolyHashMapIterator& Begin () {
      it.begin();
      return *this;
    }

    CATBoolean End () const {
      bool const is_end = it.is_end();
      if (is_end) {
        return TRUE;
      }

      return FALSE;
    }

    Key const& GetKey () const {
      return it.get_key();
    }

    Value const& GetData () const {
      return it.get_value();
    }

    Value& GetData () {
      return it.get_value();
    }

    PolyHashMapIterator GetHandle () const {
      return *this;
    }

    bool operator== (PolyHashMapIterator const& phmIt) const {
      return it == phmIt.it;
    }

    friend bool operator!= (PolyHashMapIterator const& phmIt1, PolyHashMapIterator const& phmIt2) {
      return !(phmIt1 == phmIt2);
    }

    explicit operator bool() const{
        return !it.is_end();
    }
  };

  PolyHashMap() = default;
  PolyHashMap(uint32_t const expected_capacity) {
    map.reserve(expected_capacity);
  };

  /**
   * A handle to an element in the hash table.
   * A handle provides direct access to the element.
   * A NULL handle is an invalid handle.  Handles are NOT stable after insertion or removal of elements.
   */
  typedef PolyHashMapIterator Handle;

  /**
   * Returns TRUE and the value associated to a key.  Returns FALSE if the key is not found in the map.
   */
  CATBoolean Locate (Key const& key, Value& data) const {
    HashMapIterator const it = map.find(key);

    if (it.is_end()) {
      return FALSE;
    }

    data = it.get_value();
    return TRUE;
  }

  /**
   * Finds the handle to the element in the hash table given its key.
   */
  Handle Find(Key const& key) const {
    HashMapIterator const it = map.find(key);

    return Iterator(it);
  }

  /**
   * Inserts a pair (key, value) in the map.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A new key is inserted in the map.
   *   <li> <tt>S_FALSE</tt> The key is already in the map and the values match.
   *   <li> <tt>E_FAIL</tt> The pair cannot be inserted in the map because the values do not match or some other error.
   * </ul>
   */
  HRESULT Insert (Key const& key, Value const& data) {
    std::pair<HashMapIterator, bool> it = map.insert({key, data});
    if (it.first.is_end()) {
      return E_FAIL;
    }

    if (it.second) {
      return S_OK;
    }

    if (it.first.get_value() == data) {
      return S_FALSE;
    }

    return E_FAIL;
  }

  /**
   * Inserts an element and return its handle.
   */
  HRESULT Insert (Key const& key, Value const& data, Handle& oHandle) {
    std::pair<HashMapIterator, bool> it = map.insert({key, data});
    if (it.first.is_end()) {
      return E_FAIL;
    }

    if (it.second) {
      oHandle = Iterator(it.first);
      return S_OK;
    }

    return S_FALSE;
  }


  /**
   * Updates the value associated to a key in the map.
   * The method returns S_OK if the key is successfully updated, S_FALSE if the key is not found in the map,
   * and an error otherwise.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A value is successfully updated.
   *   <li> <tt>S_FALSE</tt> The key is not in the map.
   *   <li> <tt>E_FAIL</tt> Some error occured.
   * </ul>
   */
  HRESULT Update(Key const& key, Value const& value) {
    std::pair<HashMapIterator, bool> it = map.insert_or_assign(key, value);
    if (it.first.is_end()) {
      return S_FALSE;
    }

    return S_OK;
  }

  /**
   * Updates the value given a handle.
   */
  HRESULT Update(Handle iHandle, Value const& data) {
    return Update (iHandle.GetKey(), data);
  }


  /**
   * Inserts or updates a pair (key, value) in the map.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A new key is inserted or updated in the map.
   *   <li> <tt>S_FALSE</tt> The key is already in the map and does not need to be updated.
   *   <li> <tt>E_FAIL</tt> The pair cannot be inserted in the map because some error occured.
   * </ul>
   */
  HRESULT InsertOrUpdate(Key const& key, Value const& v) {
    return map.InsertOrUpdate(key, v);
  }

  /**
   * Removes a key from the map.  If the key is not found in the map, the method returns S_FALSE.
   */
  HRESULT Remove (Key const& key) {
    auto const i = map.erase(key);
    if (i == 0) {
      return S_FALSE;
    }

    return S_OK;
  }

  /**
   * Removes a key from the map.  If the key is not found in the map, the method returns S_FALSE.
   * The method also returns the value that is associated to the key being removed.
   */
  HRESULT Remove(Key const& key, Value& data) {
    HashMapIterator const it = map.find(key);
    if (it.is_end()) {
      return S_FALSE;
    }

    data = it.get_value();
    return Remove(key);
  }

  HRESULT RemoveAll() {
    map.clear();
    return S_OK;
  }

  /**
   * Returns the number of elements in the map.
   */
  int Size() const {
    return map.size();
  }

  /**
   * Returns the size of the allocated memory used by the map in bytes.
   * TODO: not implemented
   */
  unsigned int SizeOf() const {
    poly_assert(false);
    return 0;
  }


  /**
   * Returns the key given a handle.
   */
  static Key const& GetKey(Handle const& h) {
    return h.GetKey();
  }

  /**
   * Returns the value given a handle.
   */
  static Value const& GetData(Handle const& h) {
    return h.GetData();
  }

  static Value& GetData(Handle& h) {
    return h.GetData();
  }

  typedef PolyHashMapIterator Iterator;
};




extern template class Iterator<HashMap<int, int, std::hash<uint32_t>>>;
extern template class HashMap<int, int, std::hash<uint32_t>>;
extern template class PolyHashMap<int, int, std::hash<uint32_t>>;

using CATPolyMapOfIntToInt = PolyHashMap<int, int, std::hash<uint32_t>>;
