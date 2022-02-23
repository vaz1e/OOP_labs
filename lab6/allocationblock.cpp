#include "allocationblock.h"
#include <memory>
TAllocationBlock::TAllocationBlock(size_t size, size_t count) {
    _used_blocks = (char *)malloc(size * count);
    for (int32_t i = 0; i < count; ++i) {
        void *ptr = (void *)malloc(sizeof(void *));
        ptr = _used_blocks + i * size;
        _free_blocks.Push(std::make_shared<void*>(ptr));
    }
}

void *TAllocationBlock::allocate() {
    if (!_free_blocks.Empty()) {
        void *res = *(_free_blocks.Top());
        int32_t first = 1;
        _free_blocks.Pop();
        std::cout << "Trapezoid created" << std::endl;
        return res;
    } else {
        throw std::bad_alloc();
    }
}

void TAllocationBlock::deallocate(void *ptr) {
    _free_blocks.Push(std::make_shared<void*>(ptr));
}

bool TAllocationBlock::has_free_blocks() {
    return _free_blocks.Empty();
}


TAllocationBlock::~TAllocationBlock() {
    while (!_free_blocks.Empty()) {
        int32_t first = 1;
        _free_blocks.Pop();
    }
    free(_used_blocks);
    std::cout << "Rectangle deleted" << std::endl;
}