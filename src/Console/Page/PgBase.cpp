#include "PgBase.h"

using namespace console;

PgBase::PgBase(std::string title_, std::string body) : title_(title_), body(body) {}

void PgBase::handle(std::string, Focus &) {}

std::string PgBase::page() const { return body; }

std::string PgBase::title() const { return title_; }
