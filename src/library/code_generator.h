// Copyright (c) 2020 Jens Klimke (jens.klimke@rwth-aachen.de). All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Created by Jens Klimke on $YEAR-$MONTH-11.
//

#include <ostream>
#include <exception>
#include <cmath>
#include <algorithm>
#include <memory>
#include <string>

#include "DataType.h"
#include "comment.h"
#include "functions.h"

#ifndef PARSE_XSD_CODEGENERATOR_H
#define PARSE_XSD_CODEGENERATOR_H

namespace xsd2cpp {

    void code_generator(std::ostream &fsp,
                        std::ostream &fsh,
                        std::ostream &fss,
                        const std::string &libVersion,
                        const std::string &libName) {


        // PUBLIC HEADER FILE

        std::string inclGuard = "XML_PARSER_" + libVersion + "_STRUCTURE_H";
        std::transform(inclGuard.begin(), inclGuard.end(), inclGuard.begin(), ::toupper);


        fsp << string_format(license, (libVersion + "_structure.h").c_str()) << std::endl << std::endl;
        fsp << "#ifndef " << inclGuard << "\n";
        fsp << "#define " << inclGuard << std::endl << std::endl;
        fsp << "#include \"Attribute.h\"" << std::endl;
        fsp << "#include <string>" << std::endl << std::endl;
        fsp << "namespace " << libVersion << " {" << std::endl << std::endl;


        // iterate over data types to generate typedefs and pre-defs
        for (const auto &t : DataType::dataTypesVector) {

            auto d = t->typeDefString();
            if (!d.empty())
                fsp << "\t" << d << std::endl;

        }


        fsp << std::endl << std::endl;

        // iterate over data types to generate full structure
        for (const auto &t : DataType::dataTypesVector) {

            auto d = t->typeDefStringFull();
            if (!d.empty())
                fsp << d << std::endl << std::endl;

        }


        fsp << std::endl;
        fsp << "} // namespace " << libVersion << std::endl << std::endl;
        fsp << "#endif // " << inclGuard << std::endl;



        // HEADER FILE

        inclGuard = "XML_PARSER_" + libVersion + "_hpp";
        std::transform(inclGuard.begin(), inclGuard.end(), inclGuard.begin(), ::toupper);

        fsh << string_format(license, (libVersion + ".hpp").c_str()) << std::endl << std::endl;
        fsh << "#ifndef " << inclGuard << "\n";
        fsh << "#define " << inclGuard << std::endl << std::endl;
        fsh << "#include <vector>" << std::endl;
        fsh << "#include <string>" << std::endl;
        fsh << "#include <tinyxml2.h>" << std::endl << std::endl;
        fsh << "#include <" << libName << "/" << libVersion << "_structure.h>" << std::endl << std::endl;
        fsh << "namespace " << libVersion << " {" << std::endl << std::endl;


        // iterate over data types to generate parser function definitions
        for (const auto &t : DataType::dataTypesVector) {

            auto tp = t->parseHeader();
            if (!tp.empty())
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
        for (const auto &t : DataType::dataTypesVector) {

            auto tp = t->parseHeader();
            auto tb = t->parseBody();

            if (!tp.empty())
                fss << string_format("%s {\n\n%s\n\n\treturn true;\n\n}", tp.c_str(), tb.c_str()) << std::endl
                    << std::endl;

        }


        fss << std::endl;
        fss << "} // namespace " << libVersion << std::endl;

    }

}

#endif //PARSE_XSD_CODEGENERATOR_H
