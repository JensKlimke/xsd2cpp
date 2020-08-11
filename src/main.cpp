#include <iostream>
#include <tinyxml2.h>
#include <fstream>
#include <string>

#include "library/XSDParser.h"
#include "library/code_generator.h"


int main(int argc, char *argv[]) {

    using namespace xsd2cpp;

    if (argc < 5)
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

    // generate code
    code_generator(fsp, fsh, fss, libVersion, libName);

    // close streams
    fsp.close();
    fsh.close();
    fss.close();

    return 0;

}