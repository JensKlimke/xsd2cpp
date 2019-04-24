//
// Created by Jens Klimke on 2019-04-14.
//

#ifndef PARSE_XSD_ATTRIBUTE_H
#define PARSE_XSD_ATTRIBUTE_H

#include <memory>



template<typename T>
struct Attribute : std::unique_ptr<T> {

};



#endif //PARSE_XSD_ATTRIBUTE_H
