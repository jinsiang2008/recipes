/** A collection of useful functions
 */
#include <memory>

// Backport of C++14
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}

// From rocksplicator
using std::chrono::seconds;
uint64_t GetCurrentTime() {
  return std::chrono::duration_cast<seconds>(
    std::chrono::system_clock::now().time_since_epoch()).count();
}

bool asciiString(const std::string& str) {
  uint8_t b;
  for (const auto c : str) {
    b = c;
    if (b < 0x20 || b > 0x7f) {
      return false;
    }
  }
  return true;
}

// Get number of CPU
// from <unistd.h>
sysconf(_SC_NPROCESSORS_ONLN);


// Is T one of T1, T2, ..., Tn?
// From folly/Traits.h
template <class T, class... Ts>
struct IsOneOf {
  enum { value = false };
};

template <class T, class T1, class... Ts>
struct IsOneOf<T, T1, Ts...> {
  enum { value = std::is_same<T, T1>::value || IsOneOf<T, Ts...>::value };
};

// Random generator (non-crypto)
// https://www.guyrutenberg.com/2014/05/03/c-mt19937-example/#comment-1897375
// https://github.com/facebook/rocksdb/blob/master/util/random.h#L83
#include <random>
uint64_t random64(uint64_t bound) {
  std::mt19937_64 gen(time(nullptr)); // or std::default_random_engine
  // std::uniform_real_distribution for float point
  return std::uniform_int_distribution<uint64_t>(0, bound)(gen);
}
