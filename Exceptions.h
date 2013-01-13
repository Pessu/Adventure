/*
 * Exceptions.h
 *
 *  Created on: 13.1.2013
 *      Author: Pessu
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>

class FileNotFoundException: public std::runtime_error
{
  public:

   FileNotFoundException():runtime_error("File not found")
   {}
   FileNotFoundException(std::string msg):runtime_error(msg.c_str())
   {}

};

#endif /* EXCEPTIONS_H_ */
