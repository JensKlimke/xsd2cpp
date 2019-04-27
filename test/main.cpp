//
// Created by Jens Klimke on 2019-04-27.
//

#include <tinyxml2.h>
#include "generated.h"
#include <vector>

int main(int argc, char* argv[]) {

    if (argc < 2)
        throw std::invalid_argument("please provide file name");

    // create file name
    std::string filename(argv[1]);

    // xml document
    tinyxml2::XMLDocument xml_doc;

    // load and check file
    tinyxml2::XMLError eResult = xml_doc.LoadFile(filename.c_str());
    if (eResult != tinyxml2::XML_SUCCESS)
        throw std::runtime_error("File could not be loaded!");

    std::vector<std::unique_ptr<OpenDRIVE>> odrvec{};
    __parse__OpenDRIVE((tinyxml2::XMLElement*) &xml_doc, "OpenDRIVE", odrvec);

}