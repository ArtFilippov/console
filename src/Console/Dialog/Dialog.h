#pragma once

#include <memory>
#include <vector>
#include <functional>

namespace console {
class Dialog;

using data_t = std::shared_ptr<std::vector<uint8_t>>;
} // namespace console

class console::Dialog {
  public:
    virtual ~Dialog() = default;

    virtual void subDialogs(std::function<void(const std::vector<std::shared_ptr<Dialog>> &)> fn) = 0;

    virtual void responses(std::function<void(const std::vector<data_t> &)> fn) = 0;

    virtual data_t request() = 0;

    virtual void newMsgs(data_t req, data_t res) = 0;
};
