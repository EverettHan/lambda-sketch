#ifndef CATCDSNamedTuple_H
#define CATCDSNamedTuple_H

#include <tuple>

/*#define RES_STRUCT_1(FIELD1) struct {FIELD1;}
#define RES_STRUCT_2(FIELD1, FIELD2) struct {FIELD1; FIELD2;}
#define RES_STRUCT_3(FIELD1, FIELD2, FIELD3) struct {FIELD1; FIELD2; FIELD3;}

#define NUM_ARGS_AUX(X64,X63,X62,X61,X60,X59,X58,X57,X56,X55,X54,X53,X52,X51,X50,X49,X48,X47,X46,X45,X44,X43,X42,X41,X40,X39,X38,X37,X36,X35,X34,X33,X32,X31,X30,X29,X28,X27,X26,X25,X24,X23,X22,X21,X20,X19,X18,X17,X16,X15,X14,X13,X12,X11,X10,X9,X8,X7,X6,X5,X4,X3,X2,X1,N,...) N
#define NUM_ARGS(...) NUM_ARGS_AUX(__VA_ARGS__ ,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1)

#define RES_STRUCT_N(N, ...) RES_STRUCT_##N(__VA_ARGS__)
#define RES_STRUCT(...) RES_STRUCT_N(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)*/

namespace cds
{
  namespace details
  {
    template<class F>
    struct function_to_tuple;

    template<class R, class... T>
    struct function_to_tuple<R(T...)>
    {
      using type = std::tuple<T...>;
    };

    template<class F>
    using function_to_tuple_t = typename function_to_tuple<F>::type;
  }
}

// NAMED_TUPLE(int a, CATCDSPoint3 b) est équivalent std::tuple<int, CATCDSPoint3>
// La macro permet d'annoter le n-uplet avec des noms de champs pour le lecteur
#define NAMED_TUPLE(...) cds::details::function_to_tuple_t<void(__VA_ARGS__)>

#endif
