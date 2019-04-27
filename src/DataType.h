//
// Created by Jens Klimke on 2019-04-26.
//

#ifndef PARSE_XSD_DATATYPE_H
#define PARSE_XSD_DATATYPE_H

#include <string>
#include <map>
#include "functions.h"


struct DataField;

struct DataType {


    DataType() = default;
    virtual ~DataType() = default;

    static std::vector<std::unique_ptr<DataType>> dataTypesVector;
    static std::map<std::string, DataType*> dataTypes;

    static void addDataType(const std::string &name, DataType* dt) {

        dataTypes[name] = dt;
        dataTypesVector.emplace_back(std::unique_ptr<DataType>(dt));

    }



    /*
     *  Class definition
     */

    std::string originalType;
    std::string type;

    std::string superType;

    virtual void init() = 0;
    virtual std::string typeDefString() = 0;
    virtual std::string typeDefStringFull() = 0;

    virtual std::string parseString(const DataField *dv, const std::string &name) = 0;
    virtual std::string parseBody() = 0;


    virtual std::string parseHeader() {

        return string_format("bool __parse__%s(const tinyxml2::XMLElement *elem, const std::string &name, %s &obj)", type.c_str(), type.c_str());

    }


};








struct DataField {

    DataType *dataType;

    std::string fieldName;
    std::string originalName;

    bool vector = false;


    virtual std::string attributeString() {

        if(vector)
            return string_format("std::vector<std::unique_ptr<%s>> %s{};", dataType->type.c_str(), fieldName.c_str());
        else
            return string_format("%s %s;", dataType->type.c_str(), fieldName.c_str());

    }

};







struct DataType_Basic : public DataType {


    DataType_Basic() = default;
    ~DataType_Basic() override = default;


    void init() override {

        // c strings
        auto _orig = originalType.c_str();

        if (strcmp(_orig, "xs:double") == 0) {
            superType = string_format("_Attribute<%s>", "double");
        } else if (strcmp(_orig, "xs:integer") == 0) {
            superType = string_format("_Attribute<%s>", "int");
        } else if (strcmp(_orig, "xs:nonNegativeInteger") == 0) {
            superType = string_format("_Attribute<%s>", "unsigned int");
        } else if (strcmp(_orig, "xs:string") == 0) {
            superType = string_format("_Attribute<%s>", "std::string");
        } else if (strcmp(_orig, "xs:float") == 0) {
            superType = string_format("_Attribute<%s>", "float");
        } else {
            auto err = string_format("unknown type %s", _orig);
            throw std::runtime_error(err.c_str());
        }

        // set type if not set before
        if(type.empty())
            type = superType;

    }


    std::string typeDefString() override {

        return string_format("typedef %s %s;", superType.c_str(), type.c_str());

    }


    std::string typeDefStringFull() override {

        return "";

    }


    std::string parseStr(const std::string &fieldName, const std::string &name) {

        // c strings
        auto _fieldName = fieldName.c_str();
        auto _name = name.c_str();
        auto _orig = originalType.c_str();

        std::string parseString;
        if (strcmp(_orig, "xs:double") == 0)
            parseString = string_format("%s = e->DoubleAttribute(%s, 0.0);", _fieldName, _name);
        else if (strcmp(_orig, "xs:integer") == 0)
            parseString = string_format("%s = e->IntAttribute(%s, 0);", _fieldName, _name);
        else if (strcmp(_orig, "xs:nonNegativeInteger") == 0)
            parseString = string_format("%s = e->UnsignedAttribute(%s, 0);", _fieldName, _name);
        else if (strcmp(_orig, "xs:string") == 0)
            parseString = string_format("%s = std::string(e->Attribute(%s));", _fieldName, _name);
        else if (strcmp(_orig, "xs:float") == 0)
            parseString = string_format("%s = e->FloatAttribute(%s, 0.0f);", _fieldName, _name);
        else {
            auto err = string_format("unknown type %s", _orig);
            throw std::runtime_error(err.c_str());
        }

        return parseString;

    }


    std::string parseString(const DataField *dv, const std::string &name) override {

        if(name.empty())
            return parseStr(dv->fieldName, "\"" + dv->originalName + "\"");
        else
            return parseStr(name + dv->fieldName, "\"" + dv->originalName + "\"");

    }


    std::string parseBody() override {

        return "\t" + parseStr("obj", "name.c_str()");

    }



};


struct DataType_Simple : public DataType_Basic {


    DataType_Simple() = default;
    ~DataType_Simple() override = default;

    void init() override {

        DataType_Basic::init();

    }


    std::string parseHeader() override {

        return "";

    }


};



struct DataType_Union : public DataType {

    std::vector<DataType*> subTypes{};

    DataType_Union() = default;
    ~DataType_Union() override = default;


    std::string parseString(const DataField *dv, const std::string &name) override {

        // TODO
        return "// TODO: union";

    }


    std::string typeDefString() override {

        return string_format("struct %s;", type.c_str());

    }


    std::string typeDefStringFull() override {

        std::string st = superType.empty() ? "" : string_format(" : public %s", superType.c_str());

        std::string ret = string_format("struct %s%s {\n", type.c_str(), st.c_str());

        size_t i = 0;
        for(const auto &e : subTypes)
            ret += string_format("\tstd::unique_ptr<%s> _v%d;\n", e->type.c_str(), i++);

        ret += "};";

        return ret;

    }


    std::string parseBody() override {

        std::string ret = "// TODO";
        return ret;

    }


    void init() override {

        // set type
        type = originalType;

        for(auto e : subTypes) {

            // TODO

        }

    }

};



struct DataType_Complex : public DataType {

    std::map<std::string, DataField*> subs{};
    std::map<std::string, DataField*> attr{};

    DataType_Complex() = default;
    ~DataType_Complex() override = default;


    std::string parseString(const DataField *dv, const std::string &name) override {

        // bool __parse__t_road_link(const tinyxml2::XMLElement *elem, const std::string &name, t_road_link &obj);
        return string_format("__parse__%s(e, \"%s\", %s%s);", type.c_str(), dv->originalName.c_str(), name.c_str(), dv->fieldName.c_str());

    }


    std::string typeDefString() override {

        return string_format("struct %s;", type.c_str());

    }


    std::string typeDefStringFull() override {

        std::string st = superType.empty() ? "" : string_format(" : public %s", superType.c_str());

        std::string ret = string_format("struct %s%s {\n", type.c_str(), st.c_str());

        for(const auto &e : subs) {
            auto f = e.second->attributeString();
            ret += f.empty() ? "" : "\t" + f + "\n";
        }

        for(const auto &e : attr) {
            auto f = e.second->attributeString();
            ret += f.empty() ? "" : "\t" + f + "\n";
        }

        ret += "};";

        return ret;

    }


    std::string parseBody() override {

        std::string res{};
        res = "\n\tauto e = elem->FirstChildElement(name.c_str());\n\tsize_t i = 0;\n\twhile(e != nullptr) {\n\t\t";
        res += string_format("\n\t\tauto tmp = std::make_unique<%s>();\n", type.c_str());

        for(const auto &e : attr) {
            res += "\t\tif(e->Attribute(\"" + e.second->originalName + "\") != nullptr)\n";
            res += "\t\t\t" + e.second->dataType->parseString(e.second, "tmp->") + "\n";
        }

        for(const auto &e : subs)
            res += "\t\t" + e.second->dataType->parseString(e.second, "tmp->") + "\n";

        res += "\n\t\tobj.emplace_back(std::move(tmp));\n";
        res += "\n\t\ti++;\n\t\te = e->NextSiblingElement(name.c_str());\n\t}";

        return res;

    }


    std::string parseHeader() override {

        return string_format("bool __parse__%s(const tinyxml2::XMLElement *elem, "
                             "const std::string &name, std::vector<std::unique_ptr<%s>> &obj)", type.c_str(), type.c_str());

    }


    void init() override {

        // set type
        type = originalType;

        for(auto &e : subs) {
            e.second->fieldName = e.first;

        }


        for(auto &e : attr) {
            e.second->fieldName = e.first;

        }

    }

};






#endif //PARSE_XSD_DATATYPE_H
