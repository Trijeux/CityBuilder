#ifndef CORE_MATHS_DYNAMICQUEUE_H_
#define CORE_MATHS_DYNAMICQUEUE_H_

#include <vector>
#include <stdexcept>

namespace core {

template<typename T>
class DynamicQueue {
private:
    std::vector<T> data_;
    std::size_t front_;
    std::size_t back_;
    std::size_t size_;

public:
    DynamicQueue() : front_(0), back_(0), size_(0) {}

    void enqueue(const T& value) {
        if (size_ == data_.capacity()) {
            data_.push_back(value);
        } else {
            data_[back_] = value;
        }
        back_ = (back_ + 1) % data_.capacity();
        size_++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        front_ = (front_ + 1) % data_.capacity();
        size_--;
    }

    T& front() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data_[front_];
    }

    [[nodiscard]] const T& front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data_[front_];
    }

    [[nodiscard]] bool isEmpty() const {
        return size_ == 0;
    }

    [[nodiscard]] std::size_t capacity() const {
        return size_;
    }

}; // class DynamicQueue

} // namespace core

#endif  // CORE_MATHS_DYNAMICQUEUE_H_
