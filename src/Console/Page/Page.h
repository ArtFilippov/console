#pragma once

#include <string>
#include <atomic>

namespace console {
class Page;
class Focus;
} // namespace console

class console::Focus {
    bool focusOnMe;

  public:
    Focus(bool f) : focusOnMe(f) {}

    Focus() : Focus(false) {}

    operator bool() { return focusOnMe; }

    Focus(const Focus &) = delete;

    Focus(Focus &&other) : focusOnMe(other.focusOnMe) { other.focusOnMe = false; }

    const Focus &operator=(const Focus &) = delete;

    const Focus &operator=(Focus &&other) {
        focusOnMe = other.focusOnMe;
        other.focusOnMe = false;
        return *this;
    }
};

class Lines {
    std::atomic<std::size_t> num;

  public:
    Lines(std::size_t lineNum) : num(lineNum) {}

    std::size_t lines() { return num.load(std::memory_order::acquire); }

    void update(std::size_t lineNum) { num.store(lineNum, std::memory_order::relaxed); }

    static Lines &instance() {
        static Lines l{50};
        return l;
    }
};

class console::Page {
  public:
    virtual ~Page() = default;

    virtual void handle(std::string cmd, Focus &f) = 0;

    virtual std::string page() const = 0;

    virtual std::string title() const = 0;
};
