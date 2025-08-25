#pragma once

#include "Dialog.h"
#include <shared_mutex>
#include <unordered_map>

namespace console {
class ReqLayerDlg;
}

class console::ReqLayerDlg : public Dialog {
    std::unordered_map<std::string, std::size_t> dlgIdx;

    mutable std::shared_mutex mut;
    std::vector<std::shared_ptr<Dialog>> dlg;
    std::vector<data_t> resp;

  public:
    void subDialogs(std::function<void(const std::vector<std::shared_ptr<Dialog>> &)> fn) const override;

    void responses(std::function<void(const std::vector<data_t> &)> fn) const override;

    data_t request() const override;

    void newMsgs(data_t req, data_t res) override;
};
