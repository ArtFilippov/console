#pragma once

#include <string>

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
    }
};

class console::Page {
  public:
    virtual ~Page() = default;

    virtual void handle(std::string cmd, Focus &f) = 0;

    virtual std::string page() const = 0;

    virtual std::string title() const = 0;
};
