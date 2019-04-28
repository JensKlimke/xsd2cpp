//
// Created by Jens Klimke on 2019-04-26.
//

#ifndef PARSE_XSD_XSDPARSER_H
#define PARSE_XSD_XSDPARSER_H

#include "DataType.h"


class XSDParser {

public:


    static void parseRestrictedType(const tinyxml2::XMLElement* elem, const std::string &name) {

        // create data type
        auto tp = (DataType_Simple*) DataType::dataTypes.at(name);
        tp->type = name;
        tp->originalType = elem->Attribute("base");

        // initialize
        tp->init();

    }



    static void parseUnionType(const tinyxml2::XMLElement* elem, const std::string &name) {

        // create data type
        auto tp = (DataType_Simple*) DataType::dataTypes.at(name);
        tp->type = name;
        tp->originalType = "xs:string";

        // initialize
        tp->init();

    }


    static void parseAttribute(const tinyxml2::XMLElement* attr, DataType_Complex* tp) {

        auto an = std::string(attr->Attribute("name"));
        auto at = std::string(attr->Attribute("type"));

        // create data field
        auto df = new DataField;

        // create types
        auto pre = at.substr(0, 3);
        if(pre == "xs:") {
            df->dataType = new DataType_Basic;
            df->dataType->originalType = at;
            df->dataType->init();
        } else
            df->dataType = DataType::dataTypes.at(at);

        // set name
        df->fieldName = "_" + an; //"_f__" + an;
        df->originalName = an;

        // add to list
        tp->attr[df->fieldName] = df;

    }


    static void parseSubElement(const tinyxml2::XMLElement* sub, DataType_Complex* tp) {

        // get name and type
        auto an = std::string(sub->Attribute("name"));
        auto at = std::string(sub->Attribute("type"));

        // get bounds
        std::string min = "0";
        if(sub->Attribute("minOccurs") != nullptr)
            min = std::string(sub->Attribute("minOccurs"));

        std::string max = "unbounded";
        if(sub->Attribute("maxOccurs") != nullptr)
            max = std::string(sub->Attribute("maxOccurs"));

        // create data field
        auto df = new DataField;
        df->fieldName = "sub_" + an; //"_s__" + an;
        df->originalName = an;
        df->dataType = DataType::dataTypes.at(at);

        // save vector flag
        df->vector = max == "unbounded";

        // add to list
        tp->subs[df->fieldName] = df;

    }


    static void parseComplexType(const tinyxml2::XMLElement* elem, const std::string &name) {

        // create data type
        auto tp = (DataType_Complex*) DataType::dataTypes.at(name);
        tp->originalType = name;


        // complex content
        auto cc = elem->FirstChildElement("xs:complexContent");
        if(cc != nullptr) {

            // get super class
            auto ext = cc->FirstChildElement("xs:extension");
            auto clazz = DataType::dataTypes.at(ext->Attribute("base"));

            // save super class
            tp->superType = clazz->type;

            // get members
            auto attr = ext->FirstChildElement("xs:attribute");
            while(attr != nullptr) {

                // parse attribute
                parseAttribute(attr, tp);

                // next element
                attr = attr->NextSiblingElement("xs:attribute");

            }


        }


        // get members
        auto attr = elem->FirstChildElement("xs:attribute");
        while(attr != nullptr) {

            // parse attribute
            parseAttribute(attr, tp);

            // next element
            attr = attr->NextSiblingElement("xs:attribute");

        }


        // get members
        auto seq = elem->FirstChildElement("xs:sequence");
        if(seq != nullptr) {

            auto sub = seq->FirstChildElement("xs:element");
            while (sub != nullptr) {

                // parse element
                parseSubElement(sub, tp);
                sub = sub->NextSiblingElement("xs:element");

            }

            auto ch = seq->FirstChildElement("xs:choice");
            while (ch != nullptr) {

                sub = ch->FirstChildElement("xs:element");
                while (sub != nullptr) {

                    // parse element
                    parseSubElement(sub, tp);
                    sub = sub->NextSiblingElement("xs:element");

                }

                // next element
                ch = ch->NextSiblingElement("xs:element");

            }

        }

        // initialize
        tp->init();

    }



    static void parseTypes(const tinyxml2::XMLElement *elem, const std::string &superName) {

        auto st = elem->FirstChildElement("xs:simpleType");
        while(st != nullptr) {

            // get name and create struct
            auto ctName = st->Attribute("name");

            // check if restriction
            auto res = st->FirstChildElement("xs:restriction");
            if(res != nullptr)
                parseRestrictedType(res, ctName);

            // get next one
            st = st->NextSiblingElement("xs:simpleType");

        }


        st = elem->FirstChildElement("xs:simpleType");
        while(st != nullptr) {

            // get name and create struct
            auto ctName = st->Attribute("name");

            // check if union
            auto un = st->FirstChildElement("xs:union");
            if(un != nullptr)
                parseUnionType(un, ctName);

            // get next one
            st = st->NextSiblingElement("xs:simpleType");

        }


        // iterate over complex types to process
        st = elem->FirstChildElement("xs:element");
        while(st != nullptr) {

            // get name and create struct
            auto name = st->Attribute("name");
            parseTypes(st, name);

            // get next one
            st = st->NextSiblingElement("xs:element");

        }


        // iterate over complex types to process
        st = elem->FirstChildElement("xs:complexType");
        while(st != nullptr) {

            // get name and create struct
            auto ctName = st->Attribute("name");

            // get super name
            if(ctName == nullptr)
                ctName = superName.c_str();

            // parse super type
            parseComplexType(st, ctName);

            // get next one
            st = st->NextSiblingElement("xs:complexType");

        }


    }



    static void createTypes(const tinyxml2::XMLElement *elem, const std::string &superName) {

        auto st = elem->FirstChildElement("xs:simpleType");
        while(st != nullptr) {

            // get name and create struct
            auto ctName = st->Attribute("name");

            // check if restriction
            auto res = st->FirstChildElement("xs:restriction");
            if(res != nullptr) {

                // create data type
                DataType::addDataType(ctName, new DataType_Simple);

            }

            // get next one
            st = st->NextSiblingElement("xs:simpleType");

        }


        st = elem->FirstChildElement("xs:simpleType");
        while(st != nullptr) {

            // get name and create struct
            auto ctName = st->Attribute("name");

            // check if union
            auto un = st->FirstChildElement("xs:union");
            if(un != nullptr) {

                // create data type
                DataType::addDataType(ctName, new DataType_Simple);

            }

            // get next one
            st = st->NextSiblingElement("xs:simpleType");

        }


        // iterate over complex types to create
        st = elem->FirstChildElement("xs:complexType");
        while(st != nullptr) {

            // get name and create struct
            auto ctName = st->Attribute("name");

            if(ctName == nullptr)
                ctName = superName.c_str();

            DataType::addDataType(ctName, new DataType_Complex);

            st = st->NextSiblingElement("xs:complexType");

        }


        // iterate over complex types to process
        st = elem->FirstChildElement("xs:element");
        while(st != nullptr) {

            // get name and create struct
            createTypes(st, st->Attribute("name"));

            // get next one
            st = st->NextSiblingElement("xs:element");

        }


    }



    static void parseScheme(const tinyxml2::XMLElement* elem) {

        createTypes(elem, "");
        parseTypes(elem, "");

    }

};


#endif //PARSE_XSD_XSDPARSER_H
