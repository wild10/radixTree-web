#include "server_http.hpp"
#include <iostream>
#include <typeinfo>
#include <string>
#include <utility>
//Models for rtree
// #include "models/Polygon.cpp"

#include "../core/tree.h"
#include "../radixset.hpp"
// Added for the json-example
#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>


#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#ifdef HAVE_OPENSSL
#include "crypto.hpp"
#endif

using namespace std;
using namespace boost::property_tree;

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;





int main() {
    
clasTest radix = clasTest();

    
    
    Tree* t = new Tree();
    // crear tree
    int a, b;


/*
    t->add("ROMARIO",a,b);
      t->add("RAMIRO",a,b);
      t->add("CARCO",a,b);
     cout << t->printjson() <<endl;

*/

    HttpServer server;
    server.config.port = 8091;    

    //Get | radix
    server.resource["^/radix$"]["GET"] = [&radix](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        stringstream stream;
        SimpleWeb::CaseInsensitiveMultimap header;
        stream << radix.str;
        response->write_get(stream,header);

    };


 /*   //Post | add polygons
    server.resource["^/radix$"]["POST"] = [&radix](
            shared_ptr<HttpServer::Response> response,
            shared_ptr<HttpServer::Request> request
        ) {

        stringstream stream;
        string json_string = "";
        SimpleWeb::CaseInsensitiveMultimap header;
        try {
            ptree pt;
            read_json(request->content, pt);
            string newcadena = pt.get<string>("cadena");
            radix.text = newcadena;
            
            for (boost::property_tree::ptree::value_type& rowPair:pt.get_child("polygon")) {
                for (boost::property_tree::ptree::value_type& itemPair : rowPair.second) {
                    int value = itemPair.second.get_value<int>();
                    v.push_back(value);
                }
            }
            for (size_t i = 0; i < v.size(); i += 2) {
                P point(v[i], v[i+1]);
                pv.push_back(point);
            }
            int identifier_polygon = count++;
            tree->insert(new Polygon<dtype>(pv, identifier_polygon));
            json_string = "{\"status\": true}";
            json_string = "{\"status\": true}";
            // json_string += "{ cadena: " + radix.respuestaHola(word) + "}";
            stream << json_string;
            response->write_get(stream,header);
        } catch (const exception &e) {
            response->write(
                SimpleWeb::StatusCode::client_error_bad_request,
                e.what()
            );
        }
    };*/
/*
    vector<int> v;
    vector<Point> pv;

    //Post | add polygons
    server.resource["^/radix/arrays$"]["POST"] = [&radix,&v,&pv](
            shared_ptr<HttpServer::Response> response,
            shared_ptr<HttpServer::Request> request
        ) {

        stringstream stream;
        string json_string = "";
        SimpleWeb::CaseInsensitiveMultimap header;
        try {
            ptree pt;
            read_json(request->content, pt);

            for (boost::property_tree::ptree::value_type& rowPair:pt.get_child("points")) {
                for (boost::property_tree::ptree::value_type& itemPair : rowPair.second) {
                    int value = itemPair.second.get_value<int>();
                    v.push_back(value);
                }
            }
            for (size_t i = 0; i < v.size(); i += 2) {
                Point point;
                point.x = v[i];
                point.y = v[i+1];
                pv.push_back(point);
            }

            //tree->insert(new Polygon<dtype>(pv, identifier_polygon));
            json_string = "{\"status\": verdad}";

            stream << json_string;
            response->write_get(stream,header);
        } catch (const exception &e) {
            response->write(
                SimpleWeb::StatusCode::client_error_bad_request,
                e.what()
            );
        }
    };
*/

    /* http://localhost:8090/radix/getOptions?word=test */
    server.resource["^/radix/getOptions$"]["GET"] = [t,&a,&b](
        shared_ptr<HttpServer::Response> response,
        shared_ptr<HttpServer::Request> request
        ) {

        stringstream stream;
        SimpleWeb::CaseInsensitiveMultimap header;

        try {
            string word;
            auto query_fields = request->parse_query_string();
            for(auto &field : query_fields)
                word = field.second;

            // radix.prueba(word);


             cout<<"word: ->"<< word <<endl;
             // int c, d;   
             
              t->add(word, a, b);
               
             cout<< t->printjson() <<endl;

            // stream << radix.test(word);
            stream << t->printjson();

            // cout<<"jason ->" << strjason(word) <<endl;
            response->write_get(stream, header);


        } catch (const exception &e) {
            response->write(
                SimpleWeb::StatusCode::client_error_bad_request,
                e.what()
            );
        }
    };


    server.on_error = [](shared_ptr<HttpServer::Request> /*request*/, const SimpleWeb::error_code & /*ec*/) {
        // Handle errors here
        // Note that connection timeouts will also call this handle with ec set to SimpleWeb::errc::operation_canceled
    };

    cout << "WEB SERVER IS RUNNNING" << endl;
    thread server_thread([&server]() {
        // Start server
        server.start();
    });

    // Wait for server to start so that the client can connect
    this_thread::sleep_for(chrono::seconds(1));
    server_thread.join();
}
