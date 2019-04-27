#include <iostream>
#include <exception>
#include <tinyxml2.h>
#include <cmath>
#include <fstream>
#include <string>

#include "functions.h"
#include "XSDParser.h"
#include "DataType.h"

std::vector<std::unique_ptr<DataType>> DataType::dataTypesVector{};
std::map<std::string, DataType*> DataType::dataTypes{};


int main(int argc, char* argv[]) {

    if(argc < 3)
        throw std::invalid_argument("please provide file name");

    // create file name
    std::string filename(argv[1]);
    std::string outpath(argv[2]);

    // create outputs
    std::string headerFile = outpath + "/generated.h";
    std::string sourceFile = outpath + "/generated.cc";


    // xml document
    tinyxml2::XMLDocument xml_doc;

    // load and check file
    tinyxml2::XMLError eResult = xml_doc.LoadFile(filename.c_str());
    if (eResult != tinyxml2::XML_SUCCESS)
        throw std::runtime_error("File could not be loaded!");

    // get root element
    auto schema = xml_doc.FirstChildElement("xs:schema");
    if (schema == nullptr)
        throw std::runtime_error("Schema element could not be found!");

    // parse scheme
    XSDParser::parseScheme(schema);


    // create files
    std::fstream fsh(headerFile, std::ios::out);
    std::fstream fss(sourceFile, std::ios::out);


    fsh << "#include <vector>" << std::endl;
    fsh << "#include <string>" << std::endl;
    fsh << "#include <Attribute.h>" << std::endl;
    fsh << "#include <tinyxml2/tinyxml2.h>" << std::endl;


    fsh << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto d = t->typeDefString();
        if (!d.empty())
            fsh << d << std::endl;

    }


    fsh << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto d = t->typeDefStringFull();
        if (!d.empty())
            fsh << d << std::endl << std::endl;

    }


    fsh << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto tp = t->parseHeader();
        if(!tp.empty())
            fsh << tp << ";" << std::endl;

    }



    /*fsh << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto tp = t->type.c_str();
        fsh << string_format("bool __dump__%s(tinyxml2::XMLElement *elem, const std::string &name, const %s &obj);", tp, tp) << std::endl;

    }*/





    fss << "#include \"generated.h\"" << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {


        auto tp = t->parseHeader();
        auto tb = t->parseBody();

        if(!tp.empty())
            fss << string_format("%s {\n\n%s\n\n\treturn true;\n\n}", tp.c_str(), tb.c_str()) << std::endl << std::endl;

    }


    /*fsh << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto tp = t->type.c_str();
        fsh << string_format("bool __dump__%s(tinyxml2::XMLElement *elem, const std::string &name, const %s &obj) {\n\n\treturn true;\n\n}", tp, tp) << std::endl << std::endl;

    }*/

    return 0;

}