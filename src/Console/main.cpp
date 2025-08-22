#include "comport/Comport.h"
#include "logger/ELogger.h"
#include "common/common.h"
#include "connected_execution/ExecutionStream/UniqueTasksExecutionStream.h"
#include "connected_execution/ExecutionStream/BoostFibersExecutionStream.h"

#include <iostream>

constexpr uint64_t COMPORT_RECEIVE_TIMEOUT = 50;
constexpr uint64_t COMPORT_BUF_SIZE = 255;

int main() {
    using namespace connection;
    using namespace execution;

    auto logger = LoggerConfigurator::getLogger({
        {"name", "logLiftDebug"},
        {"file", "logLiftDebug.log"},
        {"level", "debug"},
    });

    auto comport = ComportConfigurator::getComport({
        {"class", "Comport"},
        {"device", "/dev/ttyRS485-2"},
        {"baudrate", "B9600"},
        {"oneStopBit", true},
    });

    auto readAndWrite = [=](con::tx_ptr<int>) {
        std::size_t BUF_SIZE = 255;
        std::vector<uint8_t> buf(BUF_SIZE, 0);
        while (true) {
            buf = {0x2,  0x46, 0x46, 0x41, 0x31, 0x30, 0x31, 0xff, 0x35, 0x45, 0x3,  0x2,  0x46, 0x46, 0x41, 0x31,
                   0x30, 0x31, 0x30, 0x41, 0x30, 0x33, 0x31, 0x30, 0x30, 0x31, 0x31, 0x39, 0x32, 0x32, 0x30, 0x30};
            auto sent = comport->send(buf.data(), static_cast<uint16_t>(buf.size()));
            if (sent) {
                logger->logInfo(std::to_string(sent) + " were sent");
            }
            buf.resize(BUF_SIZE);
            auto bytes = comport->receive(buf.data(), static_cast<uint16_t>(buf.size()));
            if (bytes) {
                buf.resize(static_cast<std::size_t>(bytes));
                logger->logDebug(common::print(buf.data(), buf.size()).str());
            } else {
                logger->logError("");
            }
            boost::this_fiber::sleep_for(std::chrono::milliseconds(100));
        }
    };

    auto stream = std::make_shared<exec::BoostFibersExecutionStream>(1);
    stream->submit(exec::make_exec<int>("Reader", readAndWrite));

    char c;
    std::cin >> c;
}
