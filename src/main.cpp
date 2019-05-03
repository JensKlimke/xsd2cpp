#include <iostream>
#include <exception>
#include <tinyxml2.h>
#include <cmath>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>

#include "comment.h"
#include "functions.h"
#include "XSDParser.h"
#include "DataType.h"

std::vector<std::unique_ptr<DataType>> DataType::dataTypesVector{};
std::map<std::string, DataType*> DataType::dataTypes{};


int main(int argc, char* argv[]) {

    if(argc < 5)
        throw std::invalid_argument("please provide file name");


    // create file name
    std::string filename(argv[1]);
    std::string outPathPublic(argv[2]);
    std::string outPathPrivate(argv[3]);
    std::string libName(argv[4]);
    std::string libVersion(argv[5]);

    // create outputs
    std::string structHeaderFile = outPathPublic  + "/" + libVersion + "_structure.h";
    std::string headerFile       = outPathPrivate + "/" + libVersion + ".hpp";
    std::string sourceFile       = outPathPrivate + "/" + libVersion + ".cc";


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
    std::fstream fsp(structHeaderFile, std::ios::out);
    std::fstream fsh(headerFile, std::ios::out);
    std::fstream fss(sourceFile, std::ios::out);



    // PUBLIC HEADER FILE

    std::string inclGuard = "XML_PARSER_" + libVersion + "_STRUCTURE_H";
    std::transform(inclGuard.begin(), inclGuard.end(),inclGuard.begin(), ::toupper);


    fsp << string_format(license, (libVersion + "_structure.h").c_str()) << std::endl << std::endl;
    fsp << "#ifndef " << inclGuard << "\n";
    fsp << "#define " << inclGuard << std::endl << std::endl;
    fsp << "#include \"Attribute.h\"" << std::endl;
    fsp << "#include <string>" << std::endl << std::endl;
    fsp << "namespace " << libVersion << " {" << std::endl << std::endl;


    // iterate over data types to generate typedefs and pre-defs
    for(const auto &t : DataType::dataTypesVector) {

        auto d = t->typeDefString();
        if (!d.empty())
            fsp << "\t" << d << std::endl;

    }


    fsp << std::endl << std::endl;

    // iterate over data types to generate full structure
    for(const auto &t : DataType::dataTypesVector) {

        auto d = t->typeDefStringFull();
        if (!d.empty())
            fsp << d << std::endl << std::endl;

    }


    fsp << std::endl;
    fsp << "} // namespace " << libVersion << std::endl << std::endl;
    fsp << "#endif // " << inclGuard << std::endl;



    // HEADER FILE

    inclGuard = "XML_PARSER_" + libVersion + "_hpp";
    std::transform(inclGuard.begin(), inclGuard.end(),inclGuard.begin(), ::toupper);

    fsh << string_format(license, (libVersion + ".hpp").c_str()) << std::endl << std::endl;
    fsh << "#ifndef " << inclGuard << "\n";
    fsh << "#define " << inclGuard << std::endl << std::endl;
    fsh << "#include <vector>" << std::endl;
    fsh << "#include <string>" << std::endl;
    fsh << "#include <tinyxml2.h>" << std::endl << std::endl;
    fsh << "#include <" << libName << "/" << libVersion << "_structure.h>" << std::endl << std::endl;
    fsh << "namespace " << libVersion << " {" << std::endl << std::endl;


    // iterate over data types to generate parser function definitions
    for(const auto &t : DataType::dataTypesVector) {

        auto tp = t->parseHeader();
        if(!tp.empty())
            fsh << "\t" << tp << ";" << std::endl;

    }


    fsh << std::endl;
    fsh << "} // namespace " << libVersion << std::endl << std::endl;
    fsh << "#endif // " << inclGuard << std::endl;




    // SOURCE FILE

    fss << string_format(license, (libVersion + ".cc").c_str()) << std::endl << std::endl;
    fss << "#include \"" << libVersion << ".hpp\"" << std::endl << std::endl;
    fss << "namespace " << libVersion << " {" << std::endl << std::endl;


    // iterate over data types to generate parser function implementations
    for(const auto &t : DataType::dataTypesVector) {

        auto tp = t->parseHeader();
        auto tb = t->parseBody();

        if(!tp.empty())
            fss << string_format("%s {\n\n%s\n\n\treturn true;\n\n}", tp.c_str(), tb.c_str()) << std::endl << std::endl;

    }


    fss << std::endl;
    fss << "} // namespace " << libVersion << std::endl;




    /*fsp << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto d = t->typeDefStringFull();
        if (!d.empty())
            fsp << d << std::endl << std::endl;

    }


    fsh << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto tp = t->parseHeader();
        if(!tp.empty())
            fsh << tp << ";" << std::endl;

    }*/



    /*fsh << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto tp = t->type.c_str();
        fsh << string_format("bool __dump__%s(tinyxml2::XMLElement *elem, const std::string &name, const %s &obj);", tp, tp) << std::endl;

    }*/





    /*fss << "#include \"generated.h\"" << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {


        auto tp = t->parseHeader();
        auto tb = t->parseBody();

        if(!tp.empty())
            fss << string_format("%s {\n\n%s\n\n\treturn true;\n\n}", tp.c_str(), tb.c_str()) << std::endl << std::endl;

    }*/


    /*fsh << std::endl << std::endl;

    for(const auto &t : DataType::dataTypesVector) {

        auto tp = t->type.c_str();
        fsh << string_format("bool __dump__%s(tinyxml2::XMLElement *elem, const std::string &name, const %s &obj) {\n\n\treturn true;\n\n}", tp, tp) << std::endl << std::endl;

    }*/


    fsp.close();

    return 0;

}