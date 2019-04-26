#include <iostream>
#include <exception>
#include <tinyxml2.h>
#include <cmath>
#include <fstream>
#include <string>
#include <tuple>

#include "functions.h"


struct attribute_type {

    std::string type;
    std::string parser;
    std::string name;

};


struct parsed_type : public attribute_type{

    std::string super{};
    std::vector<attribute_type> attributes{};
    bool is_typedef = false;

};


static std::vector<parsed_type> types{};




attribute_type parseType(const std::string &e, const std::string &_name, const std::string &_varname) {

    // get type
    std::string type_str;
    std::string parse_str;

    tinyxml2::XMLElement *elem;


    auto name = _name.c_str();
    auto varname = _varname.c_str();

    parse_str = "\t//TODO: implement parse code for " + e + "\n";

    if (strcmp(e.c_str(), "xs:double") == 0) {
        type_str  = "_Attribute<double>";
        parse_str = string_format("\tt.%s = elem->DoubleAttribute(\"%s\", 0.0);\n", varname, name);
    } else if (strcmp(e.c_str(), "xs:integer") == 0) {
        type_str = "_Attribute<int>";
        parse_str = string_format("\tt.%s = elem->IntAttribute(\"%s\", 0);\n", varname, name);
    } else if (strcmp(e.c_str(), "xs:nonNegativeInteger") == 0) {
        type_str = "_Attribute<unsigned int>";
        parse_str = string_format("\tt.%s = elem->UnsignedAttribute(\"%s\", 0);\n", varname, name);
    } else if (strcmp(e.c_str(), "xs:string") == 0) {
        type_str = "_Attribute<std::string>";
        parse_str = string_format("\tt.%s = std::string(elem->Attribute(\"%s\"));\n", varname, name);
    } else if (strcmp(e.c_str(), "xs:float") == 0) {
        type_str = "_Attribute<float>";
        parse_str = string_format("\tt.%s = elem->FloatAttribute(\"%s\", 0.0f);\n", varname, name);
    } else {
        type_str = e;
    }


    // TODO: other types

    return {type_str, parse_str, _varname};

}




void parseElement(const tinyxml2::XMLElement* elem) {


    auto st = elem->FirstChildElement("xs:simpleType");
    while(st != nullptr) {

        // get name and create struct
        auto ctName = st->Attribute("name");

        // create type
        parsed_type tp;

        // set attributes
        tp.name = ctName;

        // <xs:attribute name="revMajor" type="xs:integer" fixed="1" use="required"/>
        auto res = st->FirstChildElement("xs:restriction");
        auto un = st->FirstChildElement("xs:union");
        if(res != nullptr) {

            auto type = parseType(res->Attribute("base"), "", "");
            tp.super = type.type;

            type.type = "";
            tp.attributes.emplace_back(type);
            tp.is_typedef = true;

        } else if(un != nullptr) {

            // get attributes
            auto type  = un->Attribute("memberTypes");

            unsigned int i = 0;
            for(const auto &e : split(type)) {

                auto attr = parseType(e, "", string_format("_v%i", i++));

                // update data
                attr.type = string_format("_Attribute<%s>", attr.type.c_str());
                attr.parser = "";

                // add attribute
                tp.attributes.emplace_back(attr);

            }

            // set super type
            tp.super = string_format("_Union<%i>", i);

        }

        // add type to list
        types.emplace_back(tp);

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

        // create type
        parsed_type tp;

        // set attributes
        tp.name = ctName;
        tp.parser = "";



        /*
         *  <xs:sequence>
         *      <xs:element name="geoReference"     type="t_header_GeoReference"    minOccurs="0"   maxOccurs="1"/>
         *      <xs:element name="offset"           type="t_header_Offset"          minOccurs="0"   maxOccurs="1"/>
         *      <xs:group ref="g_additionalData"/>
         *  </xs:sequence>
         */
        // get sequences
        auto seq = st->FirstChildElement("xs:sequence");
        if(seq != nullptr) {

            auto se = seq->FirstChildElement("xs:element");
            while(se != nullptr) {


                // get attributes
                auto aName  = se->Attribute("name");
                auto type   = se->Attribute("type");

                // get attributes
                auto attr = parseType(type, aName, string_format("__vec_%s", aName));

                // update data
                attr.type = string_format("_Vector<%s>", attr.type.c_str());
                //attr.parser = string_format("\ta = elem->FirstChildElement(\"%s\");\n\twhile(a != nullptr) {\n\t\ta = a->NextSiblingElement(\"%s\");\n\t}\n\n", name, name);

                // add attribute
                tp.attributes.emplace_back(attr);

                // next element
                se = se->NextSiblingElement("xs:element");

            }

        }


        // <xs:attribute name="revMajor" type="xs:integer" fixed="1" use="required"/>
        auto at = st->FirstChildElement("xs:attribute");
        while(at != nullptr) {

            // get attributes
            auto aName  = at->Attribute("name");
            auto type  = at->Attribute("type");
            auto fixed = at->Attribute("fixed");
            auto use   = at->Attribute("use");


            // get attributes
            auto attr = parseType(type, aName, string_format("_%s", aName));

            // add attribute
            tp.attributes.emplace_back(attr);


            // next attribute
            at = at->NextSiblingElement("xs:attribute");

        }

        // add to types
        types.emplace_back(tp);

        // get next one
        st = st->NextSiblingElement("xs:complexType");

    }

}


void parseScheme(const tinyxml2::XMLElement* elem) {

    parseElement(elem);

}


int main(int argc, char* argv[]) {

    if(argc < 3)
        throw std::invalid_argument("please provide file name");

    // create file name
    std::string filename(argv[1]);
    std::string outpath(argv[2]);
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
    parseScheme(schema);

    // write the shit to a file
    std::ofstream fs;
    fs.open(headerFile.c_str());


    fs << "#include <string>\n";
    fs << "#include <Attribute.h>\n";
    fs << "#include <tinyxml2.h>\n\n";


    // print class pre-definitions
    for(const auto &tp : types)
        if(!tp.is_typedef)
            fs << string_format("struct %s;\n", tp.name.c_str());



    fs << "\n\n";

    // print class pre-definitions
    for(const auto &tp : types)
        if(tp.is_typedef)
            fs << string_format("typedef %s %s;\n", tp.super.c_str(), tp.name.c_str());



    fs << "\n\n";


    // print class definitions
    for(const auto &tp : types) {

        if(!tp.is_typedef) {

            // super class
            auto sp = tp.super.empty() ? "" : string_format(" : public %s", tp.super.c_str());
            fs << string_format("\nstruct %s%s {\n\n", tp.name.c_str(), sp.c_str());

            for (const auto &p : tp.attributes)
                fs << string_format("\t%s %s;\n", p.type.c_str(), p.name.c_str());

            fs << "\n};\n\n";

        }


    }


    fs << "\n\n";

    // print parse function
    for(const auto &tp : types)
        fs << string_format("void parse_%s(tinyxml2::XMLElement *elem, %s& t);\n", tp.name.c_str(), tp.name.c_str());




    // write the shit to a file
    std::ofstream fscpp;
    fscpp.open(sourceFile.c_str());

    fscpp << "#include \"generated.h\"\n\n";

    // print parse function
    for(const auto &tp : types) {

        fscpp << string_format("void parse_%s(tinyxml2::XMLElement *elem, %s& t) {\n\n", tp.name.c_str(), tp.name.c_str());
        fscpp << "\ttinyxml2::XMLElement *a = nullptr;\n\n";

        // iterate over attributes
        for(const auto &p : tp.attributes)
            fscpp << p.parser;

        fscpp << "\n}\n\n";

    }


    fs.close();
    fscpp.close();

    return 0;

}