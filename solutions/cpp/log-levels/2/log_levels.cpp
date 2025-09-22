#include <string>
using namespace std;

namespace log_line {
string message(string line) {
    int msg_start = line.find(": ");
    string msg = line.substr((msg_start + 2));
    return msg;
}

string log_level(string line) {
    int log_end = line.find("]");
    string log = line.substr(1,(log_end - 1));
    return log;
}

string reformat(string line) {
    int msg_start = line.find(": ");
    string msg = line.substr((msg_start + 2));
    int log_end = line.find("]");
    string log = line.substr(1,(log_end - 1));
    return msg + " (" + log + ")";
}
}  // namespace log_line
