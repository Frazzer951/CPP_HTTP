#include <iostream>

#include "HTTPRequest.hpp"

int main()
{
  try
  {
    // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
    http::Request request { "http://dweet.io/get/latest/dweet/for/frazzertest" };

    // send a get request
    const auto response = request.send( "GET" );
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