#include "json_token.hpp"
#include "json_value.hpp"

#include <tuple>
#include <vector>
#include <string>

namespace json {
    std::tuple<std::vector<JsonToken>, std::wstring> lex(std::wstring);
    std::tuple<std::vector<JsonToken>, int, std::wstring> parse(std::vector<JsonToken>, int index = 0);
    std::wstring deparse(JsonValue, std::wstring whitespace = L"");
}