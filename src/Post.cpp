#include <iostream>

#include "HTTPRequest.hpp"

int main()
{
  try
  {
    http::Request request { "http://dweet.io/dweet/for/frazzertest" };
    // send a post request
    const auto response = request.send( "POST", R"({"foo":"bar"})", { "Content-Type: application/json" } );
    std::cout << "Description: " << response.description << '\n';    // print the description
    std::cout << "Headers: ";
    for( const std::string & s : response.headers ) std::cout << '\t' << s << '\n';                 // print the headers
    std::cout << "Body: " << std::string { response.body.begin(), response.body.end() } << '\n';    // print the body
  }
  catch( const std::exception & e )
  {
    std::cerr << "Request failed, error: " << e.what() << '\n';
  }
}