#pragma once
#include <optional>
#include <string>
#include <vector>

namespace json {
    enum JsonValueType {
        String,
        Number,
        Boolean,
        Array,
        Object,
        Null
    };

    struct JsonValue {
        std::optional<std::wstring> string;
        std::optional<double> number;
        std::optional<bool> boolean;
        std::optional<std::vector<JsonValue>> array;
        std::optional<std::wstring> object;
        JsonValueType type;
    };
}
