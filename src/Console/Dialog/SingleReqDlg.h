#pragma once

#include "Dialog.h"
#include <shared_mutex>

namespace console {
class SingleReqDlg;
}

class console::SingleReqDlg : public Dialog {
    data_t req;

    std::shared_mutex mut;
    std::vector<data_t> resp;

  public:
    SingleReqDlg(data_t req);

    void subDialogs(std::function<void(const std::vector<std::shared_ptr<Dialog>> &)> fn) override;

    void responses(std::function<void(const std::vector<data_t> &)> fn) override;

    data_t request() override;

    void newMsgs(data_t req, data_t res) override;
};
