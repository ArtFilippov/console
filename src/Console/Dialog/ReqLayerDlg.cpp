#include "ReqLayerDlg.h"
#include "SingleReqDlg.h"
#include "common/common.h"

using namespace console;

void ReqLayerDlg::subDialogs(std::function<void(const std::vector<std::shared_ptr<Dialog>> &)> fn) {
    std::shared_lock lg{mut};
    fn(dlg);
}

void ReqLayerDlg::responses(std::function<void(const std::vector<data_t> &)> fn) {
    std::shared_lock lg{mut};
    fn(resp);
}

data_t ReqLayerDlg::request() { return dlg[0]->request(); }

void ReqLayerDlg::newMsgs(data_t req, data_t res) {
    std::unique_lock lg{mut};

    auto hash = common::print(req->data(), req->size()).str();
    if (!dlgIdx.contains(hash)) {
        dlgIdx[hash] = dlg.size();
        dlg.push_back(snew<SingleReqDlg>(req));
    }

    resp.push_back(res);
    dlg[dlgIdx[hash]]->newMsgs(req, res);
}
