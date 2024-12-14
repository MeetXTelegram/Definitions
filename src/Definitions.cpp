#include <Definitions.hpp>

#include <csetjmp>

#include <pqxx/pqxx>

std::shared_ptr<pqxx::connection> db::database = nullptr;

sigjmp_buf signalsUtils::programBuf;
