//
//  json22.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/6.
//

#include "json22.hpp"
//#include <memory>


namespace json22 {

template<typename T>
class JsonValue: public Value {
public:
    explicit JsonValue(const T& t): t_value(t){}
    const T t_value;
    
    void dump(string & out) override {}
};

class IntValue: public JsonValue<int> {
    
public:
    explicit IntValue(int v): JsonValue(v) { }
    void dump(string &out) override {
        char buf[32];
        snprintf(buf, sizeof buf, "%d", t_value);
        out = out + buf;
    }
};


class BoolValue: public JsonValue<bool> {

public:
    BoolValue(bool v): JsonValue(v) { }

    void dump(string &out) override {
        out += t_value ? "true" : "false";
    }
};

class StringValue: public JsonValue<std::string> {
    
public:
    explicit StringValue(std::string v): JsonValue(v) { }
    
    void dump(string &out) override {
        out += '"';
        for (size_t i = 0; i < t_value.length(); i++) {
            const char ch = t_value[i];
            if (ch == '\\') {
                out += "\\\\";
            } else if (ch == '"') {
                out += "\\\"";
            } else if (ch == '\b') {
                out += "\\b";
            } else if (ch == '\f') {
                out += "\\f";
            } else if (ch == '\n') {
                out += "\\n";
            } else if (ch == '\r') {
                out += "\\r";
            } else if (ch == '\t') {
                out += "\\t";
            } else if (static_cast<uint8_t>(ch) <= 0x1f) {
                char buf[8];
                snprintf(buf, sizeof buf, "\\u%04x", ch);
                out += buf;
            } else if (static_cast<uint8_t>(ch) == 0xe2 && static_cast<uint8_t>(t_value[i+1]) == 0x80
                       && static_cast<uint8_t>(t_value[i+2]) == 0xa8) {
                out += "\\u2028";
                i += 2;
            } else if (static_cast<uint8_t>(ch) == 0xe2 && static_cast<uint8_t>(t_value[i+1]) == 0x80
                       && static_cast<uint8_t>(t_value[i+2]) == 0xa9) {
                out += "\\u2029";
                i += 2;
            } else {
                out += ch;
            }
        }
        out += '"';
    }
};

class ArrayValue: public JsonValue<Json::Array> {
    
public:
    explicit ArrayValue(Json::Array v): JsonValue(v) { }
    
    void dump(string &out) override {
        bool first = true;
        out += "[";
        for (const auto &value : t_value) {
            if (!first)
                out += ", ";
            value.dump(out);
            first = false;
        }
        out += "]";
    }
};

class ObjectValue: public JsonValue<Json::Object> {
    
public:
    explicit ObjectValue(Json::Object v): JsonValue(v) { }
    
    void dump(string &out) override {
        bool first = true;
        out += "{";
        for (const auto &kv : t_value) {
            if (!first)
                out += ", ";
            Json(kv.first).dump(out);
            out += ": ";
            Json(kv.second).dump(out);
//            kv.second.dump(out);
            first = false;
        }
        out += "}";
    }
};


Json::Json(int v): ptr(make_shared<IntValue>(v)) { }
Json::Json(bool v): ptr(make_shared<BoolValue>(v)) { }
Json::Json(const std::string& v): ptr(make_shared<StringValue>(v)) { }
Json::Json(std::string&& v): ptr(make_shared<StringValue>(move(v))) { }
Json::Json(const Array& v): ptr(make_shared<ArrayValue>(v)) { }
Json::Json(Array&& v): ptr(make_shared<ArrayValue>(std::move(v))) { }
Json::Json(const Object& v): ptr(make_shared<ObjectValue>(v)) { }
Json::Json(Object&& v): ptr(make_shared<ObjectValue>(std::move(v))) { }
Json::Json(const Json& j) : ptr(j.ptr){}
Json::Json(Json&& j) : ptr(j.ptr){};

void Json::dump(std::string &out) const {
    ptr->dump(out);
}
}


