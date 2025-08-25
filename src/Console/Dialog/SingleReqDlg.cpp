#include "SingleReqDlg.h"

using namespace console;

SingleReqDlg::SingleReqDlg(data_t req) : req(req) {}

void SingleReqDlg::subDialogs(std::function<void(const std::vector<std::shared_ptr<Dialog>> &)> fn) const { fn({}); }

void SingleReqDlg::responses(std::function<void(const std::vector<data_t> &)> fn) const {
    std::shared_lock lg{mut};
    fn(resp);
}

data_t SingleReqDlg::request() const { return req; }

void SingleReqDlg::newMsgs(data_t req, data_t res) {
    std::unique_lock lg{mut};
    resp.push_back(res);
}
