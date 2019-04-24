#include <iostream>
#include <exception>
#include <tinyxml2.h>
#include <cmath>
#include <fstream>

#include "functions.h"




void parseElement(const tinyxml2::XMLElement* elem, std::ostream &os) {

    // iterate over simple types
    auto st = elem->FirstChildElement("xs:simpleType");
    while(st != nullptr) {

        // get name and create struct
        auto ctName = st->Attribute("name");
        os << string_format("struct %s;\n", ctName);

        st = st->NextSiblingElement("xs:simpleType");

    }

    st = elem->FirstChildElement("xs:simpleType");
    while(st != nullptr) {

        // get name and create struct
        auto ctName = st->Attribute("name");
        os << string_format("struct %s {\n", ctName);

        // <xs:attribute name="revMajor" type="xs:integer" fixed="1" use="required"/>
        auto res = st->FirstChildElement("xs:restriction");
        auto un = st->FirstChildElement("xs:union");
        if(res != nullptr) {

            // get attributes
            auto type  = res->Attribute("base");

            // get type
            std::string type_str;
            if(strcmp(type, "xs:double") == 0)
                type_str = "double";
            else if(strcmp(type, "xs:integer") == 0)
                type_str = "int";
            else if(strcmp(type, "xs:nonNegativeInteger") == 0)
                type_str = "unsigned int";
            else if(strcmp(type, "xs:string") == 0)
                type_str = "std::string";
            else if(strcmp(type, "xs:float") == 0)
                type_str = "float";
            else
                throw std::invalid_argument(string_format("Unknown type %s", type).c_str());

            os << string_format("\tAttribute<%s> value;\n", type_str.c_str());

        } else if(un != nullptr) {

            // get attributes
            auto type  = un->Attribute("memberTypes");

            unsigned int i = 0;
            for(auto e : split(type)) {

                // get type
                std::string type_str;
                if (strcmp(e.c_str(), "xs:double") == 0)
                    type_str = "double";
                else if (strcmp(e.c_str(), "xs:integer") == 0)
                    type_str = "int";
                else if (strcmp(e.c_str(), "xs:nonNegativeInteger") == 0)
                    type_str = "unsigned int";
                else if (strcmp(e.c_str(), "xs:string") == 0)
                    type_str = "std::string";
                else if (strcmp(e.c_str(), "xs:float") == 0)
                    type_str = "float";
                else
                    type_str = e;

                os << string_format("\tAttribute<%s> v%i;\n", type_str.c_str(), ++i);

            }

        }

        os << "};\n\n";

        // get next one
        st = st->NextSiblingElement("xs:simpleType");

    }


    // iterate over elements
    st = elem->FirstChildElement("xs:element");
    while(st != nullptr) {

        auto ename = st->Attribute("name");

        // get next one
        st = st->NextSiblingElement("xs:element");

    }


    // iterate over complex types
    st = elem->FirstChildElement("xs:complexType");
    while(st != nullptr) {

        // get name and create struct
        auto ctName = st->Attribute("name");
        os << string_format("struct %s {\n", ctName);

        // <xs:attribute name="revMajor" type="xs:integer" fixed="1" use="required"/>
        auto at = st->FirstChildElement("xs:attribute");
        while(at != nullptr) {

            // get attributes
            auto aName  = at->Attribute("name");
            auto type  = at->Attribute("type");
            auto fixed = at->Attribute("fixed");
            auto use   = at->Attribute("use");

            // get type
            std::string type_str;
            if(strcmp(type, "xs:double") == 0)
                type_str = "double";
            else if(strcmp(type, "xs:integer") == 0)
                type_str = "int";
            else if(strcmp(type, "xs:nonNegativeInteger") == 0)
                type_str = "unsigned int";
            else if(strcmp(type, "xs:string") == 0)
                type_str = "std::string";
            else if(strcmp(type, "xs:float") == 0)
                type_str = "float";
            else
                type_str = type;

            os << string_format("\tAttribute<%s> %s;\n", type_str.c_str(), aName);

            // next attribute
            at = at->NextSiblingElement("xs:Attribute");

        }

        os << "};\n\n";

        // get next one
        st = st->NextSiblingElement("xs:complexType");

    }

}


void parseScheme(const tinyxml2::XMLElement* elem, std::ostream &os) {

    os << "#include <Attribute.h>\n\n";

    parseElement(elem, os);

}


int main(int argc, char* argv[]) {

    if(argc != 3)
        throw std::invalid_argument("please provide file name");

    // xml document
    tinyxml2::XMLDocument xml_doc;

    // load and check file
    tinyxml2::XMLError eResult = xml_doc.LoadFile(argv[1]);
    if (eResult != tinyxml2::XML_SUCCESS)
        throw std::runtime_error("File could not be loaded!");

    // get root element
    auto schema = xml_doc.FirstChildElement("xs:schema");
    if (schema == nullptr)
        throw std::runtime_error("Schema element could not be found!");

    // parse schema
    parseScheme(schema, std::cout);


    // write the shit to a file
    std::ofstream myfile;
    myfile.open(argv[2]);

    parseScheme(schema, myfile);

    myfile.close();

    return 0;

}