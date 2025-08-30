#include <string>
#include <vector>

using namespace std;

class OrderedStream {
private:
    vector<string> stream;
    unsigned int current_index = 0;

public:
    OrderedStream(int n) { stream = vector<string>(n, ""); }

    vector<string> insert(int idKey, string value) {
        vector<string> output;
        stream[idKey - 1] = value;
        while (current_index < stream.capacity() &&
               stream[current_index] != "") {
            output.push_back(stream[current_index]);
            current_index += 1;
        }
        return output;
    }
};

int main(int argc, char *argv[]) {
    OrderedStream sol(10);
    vector<string> param1 = sol.insert(3, "ccccc");
    return 0;
}