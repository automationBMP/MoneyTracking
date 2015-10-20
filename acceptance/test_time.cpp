#include <iostream>
#include <ctime>
#include <string>

int main (int argc, char* argv[]) {
    
    using namespace std;

    time_t epoch = time(0);

    if ( argc == 2 && 
         string(argv[1]) == string("--gmt") ) {
        // print gmt time
        tm* gmt = gmtime(&epoch);
        char buffer[50];
        // Thu, 08 Oct 2015 10:52:35 GMT
        strftime(buffer, 50, "%a, %d %b %Y %H:%M:%S ", gmt);
        cout << "Transaction time: " << buffer << "GMT" << endl;
    }
    else {
        // print unix time stamp
        cout << epoch << argv[1] << endl;
    }
    return 0;
}
