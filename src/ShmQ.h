#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>

#include <boost/lockfree/queue.hpp>

#include "Request.h"
namespace bip = boost::interprocess;
namespace bl = boost::lockfree;

namespace shm {

typedef bip::allocator<Request, managed_shared_memory_t::segment_manager> allocator_t;
typedef bip::managed_shared_memory managed_shared_memory_t;
typedef bl::queue<Request, bl::fixed_sized<true>, bl::capacity<500>> ring_buffer;

class ShmQ {
private:
    managed_shared_memory_t segment_;
    const allocator_t allocator_;

    shm::ring_buffer *queue;
public:
    ShmQ() : segment_(bip::open_or_create,
                      "RequestQueue",
                      1024 * 1024 * 64
             ), 
             allocator_(segment_.get_segment_manager())
             ){
        
        queue = segment.find_or_construct<shm::ring_buffer>("queue")();
    }
    shm::ring_buffer* GetQueue() {
        return queue;
    }
}

}