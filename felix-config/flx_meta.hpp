#ifndef __FLX_META_H__
#define __FLX_META_H__
// GENERATED during config
// taken from BOOST
#define FLX_HAVE_INCLASS_MEMBER_INITIALIZATION 1
#if FLX_HAVE_INCLASS_MEMBER_INITIALIZATION
#  define FLX_STATIC_CONSTANT(type, assignment) static const type assignment
#else
#  define FLX_STATIC_CONSTANT(type, assignment) enum { assignment }
#endif

#include <cstddef>

template <std::size_t> struct type_with_alignment;
template <> struct type_with_alignment<8>{ typedef long long type; };
template <> struct type_with_alignment<1>{ typedef char type; };
template <> struct type_with_alignment<2>{ typedef short type; };
template <> struct type_with_alignment<4>{ typedef int type; };
template <typename T> struct alignment_of;

template <typename T>
struct alignment_of_hack
{
  char c;
  T t;
  alignment_of_hack();
};

template <unsigned A, unsigned S>
struct alignment_logic
{
  FLX_STATIC_CONSTANT(std::size_t, value = A < S ? A : S);
};

template< typename T >
struct alignment_of
{
  FLX_STATIC_CONSTANT(std::size_t, value =
    (alignment_logic<
      sizeof(alignment_of_hack<T>) - sizeof(T),
      sizeof(T)
    >::value));
};

template<std::size_t L, std::size_t A>
struct aligned_storage
{
  union type
  {
    unsigned char data_[ L ];
    typename type_with_alignment<A>::type align_;
  };
};

template<typename T>
struct store_of
{
  typedef typename aligned_storage<sizeof(T), alignment_of<T>::value>::type type;
};

// convert an rvalue to an lvalue
template<typename T>
T const &lvalue(T const &x)
{
  return x;
}

// this reinterpret cast works with rvalues too
template<typename T, typename U>
T &reinterpret(U const &x) {
  return reinterpret_cast<T&>(const_cast<U&>(x));
}

template<typename T> void destroy(T *p){ p->T::~T(); }

#endif
