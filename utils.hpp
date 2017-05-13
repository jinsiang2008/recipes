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
